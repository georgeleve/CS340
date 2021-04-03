%{
	#include <stdio.h>
	#include <cstdio>
  	#include <iostream>
	#include <stdlib.h>
	#include <unistd.h>
	#include <string.h>
  	using namespace std;

	/* Declare things from Lex that Yacc needs to know: */
	extern FILE* yyin;
	int yylex(void);
	//extern int yylex();
  	//extern int yyparse();

	int yyerror (char* yaccProvidedMessage);
	extern int yylineno;
	extern char* yytext;
	
%}

%start program

/* Token Types Union */
%union {
	char* stringValue;
	int intValue;
	float floatValue;
}

/* Rest of the tokens */
// Define the "terminal symbol" token types I'm going to use (in CAPS
// by convention), and associate each with a field of the %union:
%token <stringval> ID
%token <stringval> STRING;
%token <intval> INTEGER;
%token <floatval> FLOAT;
 
%token <strval> IF ELSE WHILE FOR FUNCTION RETURN BREAK CONTINUE AND NOT OR LOCAL TRUE FALSE NIL
%token <strval> EQUAL PLUS MINUS MULTIPLICATION DIVISION PERCENTAGE EQUAL_EQUAL NOTEQUAL PLUS_PLUS MINUS_MINUS GREATER LESS_THAN GREATER_EQUAL LESS_EQUAL 
%token <strval> LEFT_BRACE RIGHT_BRACE LEFT_BRACKET RIGHT_BRACKET LEFT_PARENTH RIGHT_PARENTH SEMICOLON COMMA COLON DOUBLE_COLON DOT DOUBLE_DOT

%right '='
%left '+' '-'
%left '*' '/'
%right UMINUS
%left '(' ')'

%type <intValue> expression

%destructor { free($$); } ID

/* APO EDO */
%token ID INTEGER
%right '='
%left ','
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS
%left '(' ')'
/* MEXRI EDO  ISOS NA TA SBHSOUME argotera */


/* grammar rules (h allios legontai productions)  pou to kathe ena exei actions */n  

/* This is the actual grammar that bison will parse */
%%

program	: assignments expressions {;}
	 	| /* empty */  {;}
	 	;

expression		: INTEGER  						{ $$ = $1; }
				| ID	 						{ $$ = lookup($1); free($1); }
				| expression '+' expression		{ $$ = $1 + $3; }
				| expression '-' expression		{ $$ = $1 - $3; }
				| expression '*' expression		{ $$ = $1 * $3; }
				| expression '/' expression		{ $$ = $1 / $3; }
				| '(' expression ')'			{ $$ = $2; 		}
				| '-' expression %prec UMINUS   { $$ = -$2; 	}
				;

expr:	expression ';' { fprintf(stdout, "Result is: %d\n", $1); }

expr:	expression ';' { fprintf(stdout, "Result is: %d\n", $1); }
		| error ';' { yyerrok; }
		;

expressions: expression expr {;}
	     	| expr {;}
	     	;

assignment	: ID '=' expression ';' { assign($1, $3); }
	     	;

assignments:  assignments assignment {;}
	     	| /* empty */ {;}
	     	;


%%

/* this will be called if we have syntax errors */
int yyerror (char* yaccProvidedMessage) {
	fprintf(stderr, "%s: at line %d, before token: %s\n", yaccProvidedMessage, yylineno, yytext);
	fprintf(stderr, "INPUT NOT VALID\n");
	cout << "EEK, parse error on line " << yylineno << "!  Message: " << s << endl;
	return 1;
}

// h main opos thn exei to front
int main(int argc, char** argv){
	if (argc > 1){
		if(!yyin = fopen(argv[1], "r"))){
			fprintf(stderr, "Cannot read file: %s\n", argv[1]);
			return 1;
		}
	}else{
		yyin = stdin;
	}

	// Parse through the input:
	yyparse(); // the function generated by yacc
	return 0;
}

/* h main tou lex
int main(int argc, char** argv) {
    if(argc<2 || argc>3){
        fprintf(stderr, "Invalid arguments! Usage: ./scanner input.txt (output.txt)\n");
        return 1;
    }
    if(!(yyin = fopen(argv[1], "r"))) {
        fprintf(stderr, "Cannot open input file: %s\n", argv[1]);
        return 1;
    }
    yyout = stdout;
    if(argc==3){
        if(!(yyout = fopen(argv[2], "w"))) {
            fprintf(stderr, "Cannot create output file: %s\n", argv[2]);
            return 1;
        }
    }
    fprintf(yyout, "--------------------   Lexical Analysis   --------------------\n\n");
    vector<alpha_token*> token;
    alpha_yylex(token); 
    return 0;
}
*/
