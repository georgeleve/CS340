#include <string>
#include <iostream>

unsigned consts_newstring(string s);
unsigned consts_newnumber(double n);
unsigned libfuncs_newused(string s);
struct vmarg { vmarg_t type; unsigned val; }


void make_operand (expr* e, vmarg* arg) {
    /*
	if(e == NULL){
		arg->val = -1;
		arg->type = -1;
		return;
	}*/
    //All those below use a variable for storage
	switch(e->type){
		case var_e:
		case tableitem_e:
		case arithexpr_e:
		case boolexpr_e:
		//case assignexpr_e:
		case newtable_e:    {
                               // assert(e->sym);
                                arg->val = e->sym->offset;
                                switch(e->sym->space){            
                                    case programVar:	arg->type = global_a;   break;
                                    case functionLocal:	arg->type = local_a;    break;
                                    case formalArg:		arg->type = formal_a;   break;
                                    default: assert(0);
                                }
                                break;
		                    }
        // Constants
		case constbool_e: 	{
								//if(e->boolConst == '0') arg->val = 0;
								//else arg->val = 1;
                                arg->val = e->constBool;
								arg->type = bool_a;    break;
		                    }
		case conststring_e:	{
								arg->val = consts_newstring(e->strConst); //  INSERTER_STRING(e->strConst);
								arg->type = string_a;	break;
						 	}
		case constnum_e:	{
									
								arg->val = consts_newnumber(e->numConst); //INSERTER_NUM(e->numConst);
								arg->type = number_a;   break;
							}

		case nil_e:			{
								arg->type = nil_a; break;
							}
        //functions
		case programfunc_e: {
								arg->type = userfunc_a;
								arg->val = e->sym->taddress; //INSERTER_USERFUNC(e->sym->value.funcVal->taddress, e->sym->value.funcVal->totallocals,e->sym->value.funcVal->totalargs, (char*) e->sym->value.funcVal->name);
								break;
							}
		case libraryfunc_e:	{
								arg->type = libfunc_a;
								arg->val = libfuncs_newused(e->sym->name); //INSERTER_LIBFUNC((char*) e->sym->value.funcVal->name);
								break;
							}
		default :   assert(0);
	}
}



struct instruction {
    vmopcode opcode;
    vmarg result;
    vmarg arg1;
    vmarg arg2;
    unsigned srcLine; // we may use unsigned int
};



struct incomplete_jump {
    unsigned instrNo;       // The jump instruction number
    unsigned iaddress;      // The i-code jump-target address
    incomplete_jump* next;  // a trivial linked list
};

incomplete_jump* ij_head = (incomplete_jump*) 0;
unsigned ij_total = 0;

void add_incomplete_jump (unsigned instrNo, unsigned iaddress);


void patch_incomplete_jumps() {
    /*
    for each incomplete jump x do {
    if x.iaddress = intermediate code size then
    instructions[x.instrNo].result = target code size;
    else
    instructions[x.instrNo].result = quads[x.iaddress].taddress;
    }*/
}


extern void generate_ADD 					(quad *quad);
extern void generate_SUB 					(quad *quad);
extern void generate_MUL 					(quad *quad);
extern void generate_DIV 					(quad *quad);
extern void generate_MOD 					(quad *quad);
extern void generate_NEWTABLE 				(quad *quad);
extern void generate_TABLEGETELM 			(quad *quad);
extern void generate_TABLESETELEM			(quad *quad);
extern void generate_ASSIGN 				(quad *quad);
extern void generate_NOP 					(quad *quad);
extern void generate_JUMP 					(quad *quad);
extern void generate_IF_EQ 				    (quad *quad);
extern void generate_IF_NOTEQ 				(quad *quad);
extern void generate_IF_GREATER 			(quad *quad);
extern void generate_IF_GREATEREQ 			(quad *quad);
extern void generate_IF_LESS 				(quad *quad);
extern void generate_IF_LESSEQ 			    (quad *quad);
extern void generate_NOT					(quad *quad);
extern void generate_OR 					(quad *quad);
extern void generate_PARAM 					(quad *quad);
extern void generate_CALL 					(quad *quad);
extern void generate_GETRETVAL 				(quad *quad);
extern void generate_FUNCSTART				(quad *quad);
extern void generate_RETURN					(quad *quad);
extern void generate_FUNCEND				(quad *quad);

typedef void (*generator_func_t) (quad*);

generator_func_t generators [] = {
    generate_ADD,
    generate_SUB,
    generate_MUL,
    generate_DIV,
    generate_MOD,
    generate_NEWTABLE,
    generate_TABLEGETELM,
    generate_TABLESETELEM,
    generate_ASSIGN,
    generate_NOP,
    generate_JUMP,
    generate_IF_EQ,
    generate_IF_NOTEQ,
    generate_IF_GREATER,
    generate_IF_GREATEREQ,
    generate_IF_LESS,
    generate_IF_LESSEQ,
    generate_NOT,
    generate_OR,
    generate_PARAM,
    generate_CALL,
    generate_GETRETVAL,
    generate_FUNCSTART,
    generate_RETURN,
    generate_FUNCEND
}; 

void generate (void) {
    for(unsigned i = 0; i < total; ++i)
        (*generators[quads[i].op]) (quads + i)
}


struct avm_table;

struct avm_memcell {
   avm_memcell_t type;
   union {
      double numVal;
      //int intVal;
      string strVal; //may use string
      unsigned char boolVal;
      struct avm_table *tableVal;
      unsigned int funcVal;
      string libfuncVal;   
   }data;
};

enum avm_memcell_t {
	number_m	= 0,
	string_m	= 1,
	bool_m		= 2,
	table_m		= 3,
	userfunc_m	= 4,
	libfunc_m	= 5,
	nil_m		= 6,
	undef_m		= 7
};


avm_memcell* avm_translate_operand (vmarg* arg, avm_memcell* reg) {
    switch (arg->type){
        //variables
        case global_a: return (&stack[AVM_STACKSIZE-1-arg->val]);
        case local_a: return (&stack[topsp-arg->val]);
        case formal_a: return (&stack[topsp+AVM_STACKENV_SIZE+1+arg->val]);
        case retval_a: return (&retval);
        //case integer_a:
        case number_a: {
            reg->type = number_m;
            reg->data.numVal = consts_getnumber(arg->val);//constArray[arg->val].value->doubletype;
	 	    return reg;
        }	 
        case string_a: {
	 	    reg->type = string_m;
	 	    reg->data.strVal = consts_getstring(arg->val); //= strdup(constArray[arg->val].value->strtype);
	 	    return reg;
        }
        case bool_a: {
	 	    reg->type = bool_m;
	 	    reg->data.boolVal = arg->val;
	 	    return reg;
        }
        
        case nil_a: reg->type = nil_m; return reg;

        case userfunc_a: {
            reg->type = userfunc_m;
            reg->data.funcVal = arg->val; //= userFunctions[FindFunctionUserByAddr(arg->val)]->taddress;
            //assert(reg->data.funcVal);
            return reg;
        }
        case libfunc_a: {
            reg->type = libfunc_m;
            reg->data.libfuncVal = libfuncs_getused(arg->val); //=strdup(libFunctions[arg->val]->name);
            return reg;
        }
        default: assert(0);
		    //printf("DEBUG:argtype:%d\n",arg->type);
    }
}

execute_func_t executeFuncs[] = {
    execute_assign,
    execute_add, 
    execute_sub,
    execute_mul,	
    execute_div,	
    execute_mod,
    execute_unimus,
    execute_and,
    execute_or,
    execute_not,
    execute_jeq,
    execute_jne,
    execute_jle,
    execute_jge,
    execute_jlt,
    execute_jgt,
    execute_call,
    execute_pusharg,
    execute_funcenter,
    execute_funcexit,
    execute_newtable,
    execute_tablegetelem,
    execute_tablesetelem,
    execute_nop,
};


unsigned char executionFinished = 0;
unsigned pc = 0;
unsigned currLine = 0;
unsigned codeSize = 0;
instruction* code = (instruction*) 0;
#define AVM_ENDING_PC codeSize

void execute_cycle(void){
    if(executionFinished) return;

    if(pc == AVM_ENDING_PC){
	    //printf("DEBUG:%d\n",pc);
        executionFinished = 1;
        return;
    }
    else {
        assert(pc < AVM_ENDING_PC);
        instruction* instr = code + pc;
        //printf("DEBUG:%d\n",instr -> opcode);
        assert(instr->opcode >= 0 && instr->opcode <= AVM_MAX_INSTRUCTIONS);
        if(instr->srcLine)
            currLine = instr -> srcLine;
        unsigned int oldPC = pc; 
        (*executeFuncs[instr->opcode])(instr);
        if(pc == oldPC) ++pc;
   }
}


void avm_callsaveenviroment(void){
	avm_push_envvalue(totalActuals);
	avm_push_envvalue(pc+1);
	avm_push_envvalue(top + totalActuals + 2);    //call (sosimo perivalontos kai klhsh)
	avm_push_envvalue(topsp);
}

totalActuals = 0;
userfunc* funcInfo = avm_getfuncinfo(pc);   //funcenter
topsp = top;
top = top - funcInfo->localSize;


void execute_funcexit(instruction *unused){
	unsigned int oldTop = top;
	top = avm_get_envvalue(topsp + AVM_SAVEDTOP_OFFSET);
	pc = avm_get_envvalue(topsp + AVM_SAVEDPC_OFFSET);
	topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);     //funcexit
	//const_s tmpconst_s = constArray[topsp];
	int tmp_s = stack[topsp].data.numVal;
	while(oldTop++ <= top){
		avm_memcellclear(&stack[oldTop]);
	}
}

avm_assign(&stack[top], arg);
++totalActuals;                   // pusharg
avm_dec_top();





typedef void(*library_func_t) (void);
library_func_t avm_getlibraryfunc(string id); // typical hashing

void avm_calllibfunc(char* id){
	library_func_t f = avm_getlibraryfunc(id);
	//printf("DEBUG:FNAME %s\n",f->name);
	if(!f){
		avm_error("unsupported lib func called!");
		executionFinished = 1;
	}
	else{
		topsp = top;
		totalActuals = 0;
        (*f) ();

		if(!executionFinished)
			execute_funcexit((instruction*) 0);
	}
}


unsigned avm_totalactuals(void){
	return avm_get_envvalue(topsp + AVM_NUMACTUALS_OFFSET);
}

avm_memcell *avm_getactual(unsigned i){
	assert(i < avm_totalactuals());
	return &stack[topsp + AVM_STACKENV_SIZE + 1 + i];
}

void libfunc_print(){
	unsigned i = 0;
	unsigned n = 0;	
	n = avm_totalactuals();
	//printf("DEBUG: TOTALACTUALS:%d\n",n);
	for(i = 0; i < n; ++i){  
		string s = avm_tostring(avm_getactual(i));
		//printf("%s", s);
		puts(s);  //strdup(s)
		if(*s)	free(s);
	}
}

void avm_registerlibfunc(string id, library_func_t addr);


void libfunc_typeof(){
	unsigned n = avm_totalactuals();
	if(n != 1){
		avm_error("One argument (not many) expected in 'typeof'.");
	}
	else{
		avm_memcellclear(&retval);
		retval.type = string_m;
		retval.data.strVal = strdup(typeStrings[avm_getactual(0)->type]);//(constArray[avm_getactual(0)->type].value->strtype);
	}
}

void libfunc_totalarguments(){
	unsigned int p_topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET );
	avm_memcellclear(&retval);

	if(!p_topsp){
		avm_warning("Totalarguments() (library function) called outside of function!");
		retval.type = nil_m;
	}
	else{
		retval.type = number_m;
		retval.data.numVal = avm_get_envvalue(p_topsp + AVM_NUMACTUALS_OFFSET);
	}
}



#define execute_add execute_arithmetic
#define execute_sub execute_arithmetic
#define execute_mul execute_arithmetic
#define execute_div execute_arithmetic
#define execute_mod execute_arithmetic

typedef double (*arithmetic_func_t) (double x, double y);

double add_impl( double x, double y ){
	return x+y;
}

double sub_impl( double x, double y ){
	return x-y;
}

double mul_impl( double x, double y ){
	return x*y;
}

double div_impl( double x, double y ){
	if( y == 0){avm_error("Error:Division with zero attempted.\n");}
	return x/y;
}

double mod_impl( double x, double y ){
	if( y == 0){avm_error("Error:Division with zero attempted.\n");}
	return (( unsigned ) x ) % (( unsigned ) y );
}

arithmetic_func_t arithmeticFuncs[] ={
	add_impl,
	sub_impl,
	mul_impl,
	div_impl,
	mod_impl
};


void execute_arithmetic (instruction* instr){
	avm_memcell* lv = avm_translate_operand(&instr->result, (avm_memcell*)0);  // maybe some without &
	avm_memcell* rv1= avm_translate_operand(&instr->arg1,&ax);
	avm_memcell* rv2= avm_translate_operand(&instr->arg2,&bx);

	assert(lv && (&stack[0] <= lv && &stack[top] > lv || lv == &retval ));
	assert(rv1 && rv2);

	if (rv1->type != number_m || rv2->type != number_m){
		avm_error("not a number arithmetic!\n");
		executionFinished=1;
	}
	else{
		arithmetic_func_t op = arithmeticFuncs[instr->opcode - add_v];
		avm_memcellclear(lv);
		lv->type = number_m;
		lv->data.numVal = (*op)(rv1->data.numVal,rv2->data.numVal);
	}
	//printf("DEBUG VALUE:%d\n",(int)lv->data.numVal);
}



unsigned char number_tobool (avm_memcell* m) {
	return m->data.numVal !=0; 
}

unsigned char string_tobool (avm_memcell* m) {	
	return m->data.strVal[0] !=0; 
}

unsigned char bool_tobool (avm_memcell* m) {
	return m->data.boolVal !=0; 
}

unsigned char table_tobool (avm_memcell* m) {	
	return 1; 
}

unsigned char userfunc_tobool (avm_memcell* m) {
	return 1; 
}

unsigned char libfunc_tobool (avm_memcell* m) {
	return 1; 
}

unsigned char nil_tobool (avm_memcell* m) {	
	return 0; 
}
	
unsigned char undef_tobool (avm_memcell* m) {
	return 0; 
}

tobool_func_t toboolFuncs[] = {
	number_tobool,
	string_tobool,
	bool_tobool,
	table_tobool,
	userfunc_tobool,
	libfunc_tobool,
	nil_tobool,
	undef_tobool
};

unsigned char avm_tobool(avm_memcell* m){
	assert(m->type >=0 && m->type <undef_m);
	return (*toboolFuncs[m->type])(m);
}



void execute_jeq(instruction* instr){

	assert(instr->result->type == label_a);

	avm_memcell* rv1 = avm_translate_operand(&instr->arg1, &ax);  //maybe without &
	avm_memcell* rv2 = avm_translate_operand(&instr->arg2, &bx);

    unsigned char result = 0;


	if (rv1->type == undef_m || rv2->type == undef_m) {
		avm_error("'Undef' involved in equality!");
	} else if(rv1->type==nil_m || rv2->type ==nil_m) {
		result = (rv1->type == nil_m) && (rv2->type == nil_m);
	} else if(rv1->type == bool_m || rv2->type == bool_m) {
		result=rv1->data.boolVal == rv2->data.boolVal;
	} else if(rv1->type != rv2->type) {
		avm_error("String is illegal!"); //,typeStrings[rv1->type]);
    } else {
		switch (rv1->type) {
			case number_m: {
				result = rv1->data.numVal == rv2->data.numVal;	
				break;
			}
			case string_m: {
				result = !(strcmp(rv1->data.strVal,rv2->data.strVal));		
				break;
			}
			case table_m: {
				result = rv1->data.tableVal == rv2->data.tableVal ; 	
				break;	
			}
			case userfunc_m: {
				result = rv1->data.funcVal == rv2->data.funcVal;			
				break;
			}
			case libfunc_m: {
				result = !(strcmp(rv1->data.libfuncVal,rv2->data.libfuncVal));		
				break;
			}

			default: assert(0);
		}
	}
	
	if(!executionFinished && (result == 1))	pc=instr->result->val;
}

string typeStrings[]={
    "number",
    "string",
    "bool",
    "table",
    "userfunc",
    "libfunc",
    "nil",
    "undef"
};




void execute_newtable(instruction* instr){

	avm_memcall* lv = avm_translate_operand(&instr->result, (avm_memcall*) 0);

	avm_memcellclear(lv);

	lv->type = table_m;
	lv->data.tableVal = avm_tablenew();
	avm_tableincrefcounter(lv->data.tableVal);
}

avm_memcell* avm_tablegetelem(avm_table* table, avm_memcell* index);

void avm_tablesetelem(avm_table* table, avm_memcell* index, avm_memcell* content);


void execute_tablegetelem(instruction* instr){
	avm_memcell* lv = avm_translate_operand(&instr->result, (avm_memcell*) 0);	
	avm_memcell* t = avm_translate_operand(&instr->arg1, (avm_memcell*) 0);
	avm_memcell* i = avm_translate_operand(&instr->arg2, &ax);

	assert(lv && (&stack[0] <= lv && &stack[top] > lv || lv == &retval));
	assert(t && &stack[0] <= t && &stack[top] > t);
	assert(i);

	avm_memcellclear(lv);
	lv->type = nil_m;

	if(t->type != table_m){
		avm_error("Illegal use of type %s as table!", typeStrings[t->type]);
	}else{
		string ts = avm_tostring(t);
		string is = avm_tostring(i);
		avm_warning("%s[%s] not found!", ts, is);
		free(ts);
		free(is);
	}
}

void execute_tablesetelem(instruction* instr){
	avm_memcell* lv = avm_translate_operand(&instr->result, (avm_memcell*) 0);
	avm_memcell* i = avm_translate_operand(&instr->arg1, &ax);
	avm_memcell* c = avm_translate_operand(&instr->arg2, &bx);

	assert(t && &stack[0] <= t && &stack[top] > t);
	assert(i && c);

	if(t->type != table_m)
		avm_error("Illegal use of type %s as table!", typeString[t->type]);
	else
		avm_tablesetelem(t->data.tableVal, i, c);
}