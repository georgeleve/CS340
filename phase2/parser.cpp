/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

	#include "helper.h"
	int yyerror (char* yaccProvidedMessage);
	extern int yylineno;
	extern FILE* yyin;
	extern int yylex(void);
	extern char* yytext;
	extern FILE* yyout;
	
	int fID = 1;
	bool shouldInsert = true;
	bool insideCall = false;

#line 84 "parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    STRING = 259,
    INTEGER = 260,
    FLOAT = 261,
    IF = 262,
    ELSE = 263,
    WHILE = 264,
    FOR = 265,
    FUNCTION = 266,
    RETURN = 267,
    BREAK = 268,
    CONTINUE = 269,
    AND = 270,
    NOT = 271,
    OR = 272,
    LOCAL = 273,
    TRUE = 274,
    FALSE = 275,
    NIL = 276,
    ASSIGN = 277,
    PLUS = 278,
    MINUS = 279,
    MUL = 280,
    DIV = 281,
    MODULO = 282,
    EQUAL = 283,
    NOT_EQUAL = 284,
    PLUS_PLUS = 285,
    MINUS_MINUS = 286,
    GREATER = 287,
    LESS = 288,
    GREATER_EQUAL = 289,
    LESS_EQUAL = 290,
    LEFT_BRACE = 291,
    RIGHT_BRACE = 292,
    LEFT_BRACKET = 293,
    RIGHT_BRACKET = 294,
    LEFT_PARENTH = 295,
    RIGHT_PARENTH = 296,
    SEMICOLON = 297,
    COMMA = 298,
    COLON = 299,
    DOUBLE_COLON = 300,
    DOT = 301,
    DOT_DOT = 302,
    UMINUS = 303
  };
#endif
/* Tokens.  */
#define ID 258
#define STRING 259
#define INTEGER 260
#define FLOAT 261
#define IF 262
#define ELSE 263
#define WHILE 264
#define FOR 265
#define FUNCTION 266
#define RETURN 267
#define BREAK 268
#define CONTINUE 269
#define AND 270
#define NOT 271
#define OR 272
#define LOCAL 273
#define TRUE 274
#define FALSE 275
#define NIL 276
#define ASSIGN 277
#define PLUS 278
#define MINUS 279
#define MUL 280
#define DIV 281
#define MODULO 282
#define EQUAL 283
#define NOT_EQUAL 284
#define PLUS_PLUS 285
#define MINUS_MINUS 286
#define GREATER 287
#define LESS 288
#define GREATER_EQUAL 289
#define LESS_EQUAL 290
#define LEFT_BRACE 291
#define RIGHT_BRACE 292
#define LEFT_BRACKET 293
#define RIGHT_BRACKET 294
#define LEFT_PARENTH 295
#define RIGHT_PARENTH 296
#define SEMICOLON 297
#define COMMA 298
#define COLON 299
#define DOUBLE_COLON 300
#define DOT 301
#define DOT_DOT 302
#define UMINUS 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "parser.y"

	char* stringval;
	int intval;
	float floatval;

#line 238 "parser.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  72
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   582

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  203

#define YYUNDEFTOK  2
#define YYMAXUTOK   303


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    49,    49,    50,    53,    54,    55,    56,    57,    58,
      61,    64,    65,    66,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    86,
      87,    88,    89,   102,   115,   128,   141,   144,   159,   173,
     184,   185,   186,   187,   190,   191,   192,   193,   194,   197,
     256,   266,   274,   277,   278,   279,   280,   283,   284,   285,
     288,   289,   292,   295,   298,   299,   300,   303,   304,   307,
     308,   311,   311,   311,   314,   315,   318,   319,   318,   323,
     334,   323,   340,   346,   340,   354,   355,   356,   357,   358,
     359,   362,   373,   384,   388,   387,   396,   395,   406,   410,
     405,   420,   424,   419,   432,   433,   433
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "STRING", "INTEGER", "FLOAT", "IF",
  "ELSE", "WHILE", "FOR", "FUNCTION", "RETURN", "BREAK", "CONTINUE", "AND",
  "NOT", "OR", "LOCAL", "TRUE", "FALSE", "NIL", "ASSIGN", "PLUS", "MINUS",
  "MUL", "DIV", "MODULO", "EQUAL", "NOT_EQUAL", "PLUS_PLUS", "MINUS_MINUS",
  "GREATER", "LESS", "GREATER_EQUAL", "LESS_EQUAL", "LEFT_BRACE",
  "RIGHT_BRACE", "LEFT_BRACKET", "RIGHT_BRACKET", "LEFT_PARENTH",
  "RIGHT_PARENTH", "SEMICOLON", "COMMA", "COLON", "DOUBLE_COLON", "DOT",
  "DOT_DOT", "UMINUS", "$accept", "program", "stmt", "expr", "term",
  "assignexpr", "primary", "lvalue", "member", "call", "callsuffix",
  "normcall", "methodcall", "elist", "objectdef", "indexed", "indexedelem",
  "$@1", "$@2", "temp_stmt", "block", "$@3", "$@4", "funcdef", "$@5",
  "$@6", "$@7", "$@8", "const", "idlist", "ifstmt", "$@9", "$@10",
  "whilestmt", "$@11", "$@12", "forstmt", "$@13", "$@14", "returnstmt",
  "$@15", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

#define YYPACT_NINF (-174)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     220,     2,  -174,  -174,  -174,    -4,  -174,  -174,    40,     6,
      10,    47,   286,    94,  -174,  -174,  -174,   286,     1,     1,
    -174,     9,   263,  -174,    97,   117,   220,   332,  -174,  -174,
    -174,     4,   112,    45,  -174,  -174,  -174,  -174,   127,  -174,
    -174,  -174,   263,   286,    96,    98,  -174,   101,  -174,   286,
    -174,  -174,  -174,   115,    31,  -174,   139,   132,   147,    15,
    -174,    45,    15,  -174,  -174,   521,   -36,   -34,  -174,   395,
     114,   134,  -174,  -174,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,  -174,  -174,  -174,
     286,   286,   154,   155,  -174,  -174,  -174,   286,   286,   286,
     164,  -174,   521,  -174,   416,   286,   286,   135,  -174,   353,
     263,  -174,   133,  -174,   220,   286,  -174,   286,  -174,   140,
    -174,   138,   263,   534,   137,    31,    31,  -174,  -174,  -174,
     547,   547,   288,   288,   288,   288,   458,   -23,  -174,   145,
     521,   479,    41,  -174,   220,  -174,   437,    17,  -174,   189,
    -174,   521,  -174,   138,  -174,   157,   310,   521,  -174,   286,
     521,  -174,  -174,  -174,   286,  -174,  -174,  -174,   220,  -174,
     286,   189,  -174,    55,  -174,  -174,    60,    66,  -174,   220,
     374,    67,   163,   199,   286,  -174,  -174,  -174,   286,   167,
    -174,  -174,   500,    83,  -174,   109,  -174,  -174,   177,  -174,
     220,  -174,  -174
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    49,    87,    85,    86,     0,    98,   101,    82,   105,
       0,     0,     0,     0,    89,    90,    88,     0,     0,     0,
      76,    66,     0,    13,     0,     0,     3,     0,    28,    14,
      36,    44,    52,    45,    46,    11,    12,    48,     5,     6,
       7,     8,     0,     0,     0,     0,    79,     0,   104,     0,
       9,    10,    31,    50,    30,    49,     0,     0,     0,    32,
      52,     0,    34,    75,    71,    64,     0,     0,    69,     0,
       0,    51,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     4,    33,    35,
       0,    66,     0,     0,    58,    60,    61,     0,     0,    66,
       0,    96,    37,    40,     0,     0,    66,     0,    83,     0,
       0,    50,     0,    51,    77,     0,    67,     0,    68,     0,
      29,    47,     0,    26,    27,    15,    16,    17,    18,    19,
      24,    25,    20,    22,    21,    23,     0,     0,    53,     0,
      43,     0,     0,    55,     0,    94,     0,     0,    80,    93,
     106,    38,    41,     0,    74,     0,     0,    65,    70,    66,
      39,    42,    54,    62,    66,    56,    57,    97,     0,    99,
       0,    93,    91,     0,    78,    72,     0,     0,    95,     0,
       0,     0,     0,     0,     0,    59,    63,   100,    66,     0,
      75,    92,     0,     0,    75,     0,    73,   102,     0,    84,
       0,    81,   103
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -174,   178,     0,   -11,  -174,  -174,  -174,    59,    74,   113,
    -174,  -174,  -174,   -83,  -174,  -174,    86,  -174,  -174,  -173,
    -174,  -174,  -174,   -20,  -174,  -174,  -174,  -174,  -174,    35,
    -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,
    -174
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,   154,    27,    28,    29,    30,    31,    32,    33,
      94,    95,    96,    66,    34,    67,    68,   115,   184,   114,
      35,    63,   155,    36,   107,   171,    47,   149,    37,   173,
      38,   168,   144,    39,    44,   179,    40,    45,   200,    41,
      49
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      26,    52,    70,   116,    55,   118,    54,   117,   137,   119,
      65,    69,     1,     2,     3,     4,   142,   195,   163,    56,
     117,   198,   103,   147,    42,    12,    26,    13,    14,    15,
      16,   102,   104,    17,    88,    89,    43,   112,   109,    18,
      19,    57,    90,    46,    91,    64,    58,    21,    48,    22,
      92,    93,    50,    90,    24,    91,    78,    79,    80,   170,
     117,    92,    93,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   176,    59,    62,   136,
      65,   177,   166,    98,   117,    99,   140,   141,    65,    51,
     152,   100,    60,    60,   146,    65,   182,    53,   183,   151,
      71,   185,   161,   117,   156,   193,   157,   186,   189,   117,
     183,   160,     1,     2,     3,     4,     5,    72,     6,     7,
       8,     9,    10,    11,   197,    12,   117,    13,    14,    15,
      16,    61,    61,    17,    97,   101,   105,   110,   106,    18,
      19,   108,   111,     8,   167,    20,   199,    21,    65,    22,
     113,    23,    74,    65,    24,   121,   122,   138,   139,   180,
      76,    77,    78,    79,    80,    81,    82,   143,   178,    83,
      84,    85,    86,   192,   153,   148,    64,    65,   159,   187,
       1,     2,     3,     4,     5,   164,     6,     7,     8,     9,
      10,    11,   172,    12,   174,    13,    14,    15,    16,   190,
     202,    17,   191,   194,    73,   158,   181,    18,    19,     0,
       0,     0,     0,    20,   201,    21,     0,    22,     0,    23,
       0,     0,    24,     1,     2,     3,     4,     5,     0,     6,
       7,     8,     9,    10,    11,     0,    12,     0,    13,    14,
      15,    16,     0,     0,    17,     0,     0,     0,     0,     0,
      18,    19,     0,     0,     0,     0,    20,     0,    21,     0,
      22,     0,    23,     0,     0,    24,     1,     2,     3,     4,
       0,     0,     0,     0,     8,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,     0,     0,    17,     0,     1,
       2,     3,     4,    18,    19,     0,     0,     0,     0,     0,
       0,    21,    12,    22,    13,    14,    15,    16,    24,     0,
      17,    76,    77,    78,    79,    80,    18,    19,     0,     0,
      -1,    -1,    -1,    -1,    21,    74,    22,    75,     0,     0,
       0,    24,     0,    76,    77,    78,    79,    80,    81,    82,
       0,     0,    83,    84,    85,    86,     0,    74,     0,    75,
       0,     0,     0,     0,   175,    76,    77,    78,    79,    80,
      81,    82,     0,     0,    83,    84,    85,    86,    74,     0,
      75,     0,     0,     0,    87,     0,    76,    77,    78,    79,
      80,    81,    82,     0,     0,    83,    84,    85,    86,    74,
       0,    75,     0,     0,     0,   150,     0,    76,    77,    78,
      79,    80,    81,    82,     0,     0,    83,    84,    85,    86,
      74,     0,    75,     0,     0,     0,   188,     0,    76,    77,
      78,    79,    80,    81,    82,     0,     0,    83,    84,    85,
      86,    74,     0,    75,     0,     0,   120,     0,     0,    76,
      77,    78,    79,    80,    81,    82,     0,     0,    83,    84,
      85,    86,    74,     0,    75,     0,     0,   145,     0,     0,
      76,    77,    78,    79,    80,    81,    82,     0,     0,    83,
      84,    85,    86,    74,     0,    75,     0,     0,   169,     0,
       0,    76,    77,    78,    79,    80,    81,    82,     0,     0,
      83,    84,    85,    86,    74,     0,    75,   162,     0,     0,
       0,     0,    76,    77,    78,    79,    80,    81,    82,     0,
       0,    83,    84,    85,    86,    74,     0,    75,   165,     0,
       0,     0,     0,    76,    77,    78,    79,    80,    81,    82,
       0,     0,    83,    84,    85,    86,    74,   196,    75,     0,
       0,     0,     0,     0,    76,    77,    78,    79,    80,    81,
      82,     0,     0,    83,    84,    85,    86,    76,    77,    78,
      79,    80,    81,    82,     0,     0,    83,    84,    85,    86,
      76,    77,    78,    79,    80,    -1,    -1,     0,     0,    83,
      84,    85,    86
};

static const yytype_int16 yycheck[] =
{
       0,    12,    22,    39,     3,    39,    17,    43,    91,    43,
      21,    22,     3,     4,     5,     6,    99,   190,    41,    18,
      43,   194,    42,   106,    22,    16,    26,    18,    19,    20,
      21,    42,    43,    24,    30,    31,    40,    57,    49,    30,
      31,    40,    38,     3,    40,    36,    45,    38,    42,    40,
      46,    47,    42,    38,    45,    40,    25,    26,    27,    42,
      43,    46,    47,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,   159,    18,    19,    90,
      91,   164,    41,    38,    43,    40,    97,    98,    99,    42,
     110,    46,    18,    19,   105,   106,    41,     3,    43,   110,
       3,    41,   122,    43,   115,   188,   117,    41,    41,    43,
      43,   122,     3,     4,     5,     6,     7,     0,     9,    10,
      11,    12,    13,    14,    41,    16,    43,    18,    19,    20,
      21,    18,    19,    24,    22,     8,    40,    22,    40,    30,
      31,    40,     3,    11,   144,    36,    37,    38,   159,    40,
       3,    42,    15,   164,    45,    41,    22,     3,     3,   170,
      23,    24,    25,    26,    27,    28,    29,     3,   168,    32,
      33,    34,    35,   184,    41,    40,    36,   188,    40,   179,
       3,     4,     5,     6,     7,    40,     9,    10,    11,    12,
      13,    14,     3,    16,    37,    18,    19,    20,    21,    36,
     200,    24,     3,    36,    26,   119,   171,    30,    31,    -1,
      -1,    -1,    -1,    36,    37,    38,    -1,    40,    -1,    42,
      -1,    -1,    45,     3,     4,     5,     6,     7,    -1,     9,
      10,    11,    12,    13,    14,    -1,    16,    -1,    18,    19,
      20,    21,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    36,    -1,    38,    -1,
      40,    -1,    42,    -1,    -1,    45,     3,     4,     5,     6,
      -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    16,
      -1,    18,    19,    20,    21,    -1,    -1,    24,    -1,     3,
       4,     5,     6,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    16,    40,    18,    19,    20,    21,    45,    -1,
      24,    23,    24,    25,    26,    27,    30,    31,    -1,    -1,
      32,    33,    34,    35,    38,    15,    40,    17,    -1,    -1,
      -1,    45,    -1,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    32,    33,    34,    35,    -1,    15,    -1,    17,
      -1,    -1,    -1,    -1,    44,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    32,    33,    34,    35,    15,    -1,
      17,    -1,    -1,    -1,    42,    -1,    23,    24,    25,    26,
      27,    28,    29,    -1,    -1,    32,    33,    34,    35,    15,
      -1,    17,    -1,    -1,    -1,    42,    -1,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    32,    33,    34,    35,
      15,    -1,    17,    -1,    -1,    -1,    42,    -1,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    32,    33,    34,
      35,    15,    -1,    17,    -1,    -1,    41,    -1,    -1,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    32,    33,
      34,    35,    15,    -1,    17,    -1,    -1,    41,    -1,    -1,
      23,    24,    25,    26,    27,    28,    29,    -1,    -1,    32,
      33,    34,    35,    15,    -1,    17,    -1,    -1,    41,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      32,    33,    34,    35,    15,    -1,    17,    39,    -1,    -1,
      -1,    -1,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    32,    33,    34,    35,    15,    -1,    17,    39,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    32,    33,    34,    35,    15,    37,    17,    -1,
      -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    32,    33,    34,    35,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    32,    33,    34,    35,
      23,    24,    25,    26,    27,    28,    29,    -1,    -1,    32,
      33,    34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     9,    10,    11,    12,
      13,    14,    16,    18,    19,    20,    21,    24,    30,    31,
      36,    38,    40,    42,    45,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    63,    69,    72,    77,    79,    82,
      85,    88,    22,    40,    83,    86,     3,    75,    42,    89,
      42,    42,    52,     3,    52,     3,    18,    40,    45,    56,
      57,    58,    56,    70,    36,    52,    62,    64,    65,    52,
      72,     3,     0,    50,    15,    17,    23,    24,    25,    26,
      27,    28,    29,    32,    33,    34,    35,    42,    30,    31,
      38,    40,    46,    47,    59,    60,    61,    22,    38,    40,
      46,     8,    52,    72,    52,    40,    40,    73,    40,    52,
      22,     3,    72,     3,    68,    66,    39,    43,    39,    43,
      41,    41,    22,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    62,     3,     3,
      52,    52,    62,     3,    81,    41,    52,    62,    40,    76,
      42,    52,    72,    41,    51,    71,    52,    52,    65,    40,
      52,    72,    39,    41,    40,    39,    41,    51,    80,    41,
      42,    74,     3,    78,    37,    44,    62,    62,    51,    84,
      52,    78,    41,    43,    67,    41,    41,    51,    42,    41,
      36,     3,    52,    62,    36,    68,    37,    41,    68,    37,
      87,    37,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    53,
      53,    53,    53,    53,    53,    53,    53,    54,    54,    54,
      54,    54,    54,    54,    55,    55,    55,    55,    55,    56,
      56,    56,    56,    57,    57,    57,    57,    58,    58,    58,
      59,    59,    60,    61,    62,    62,    62,    63,    63,    64,
      64,    66,    67,    65,    68,    68,    70,    71,    69,    73,
      74,    72,    75,    76,    72,    77,    77,    77,    77,    77,
      77,    78,    78,    78,    80,    79,    81,    79,    83,    84,
      82,    86,    87,    85,    88,    89,    88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       2,     2,     2,     2,     2,     2,     1,     3,     4,     4,
       3,     4,     4,     3,     1,     1,     1,     3,     1,     1,
       2,     2,     1,     3,     4,     3,     4,     4,     2,     6,
       1,     1,     3,     5,     1,     3,     0,     3,     3,     1,
       3,     0,     0,     7,     2,     0,     0,     0,     5,     0,
       0,    10,     0,     0,     9,     1,     1,     1,     1,     1,
       1,     1,     3,     0,     0,     6,     0,     4,     0,     0,
       7,     0,     0,    11,     2,     0,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3:
#line 50 "parser.y"
                {}
#line 1635 "parser.cpp"
    break;

  case 9:
#line 58 "parser.y"
                         {
		if(!isLastTypeLoop()) printf("ERROR: No loop found in this scope. (line %d)\n",yylineno);
	}
#line 1643 "parser.cpp"
    break;

  case 10:
#line 61 "parser.y"
                            {
		if(!isLastTypeLoop()) printf("ERROR: No loop found in this scope. (line %d)\n",yylineno);
	}
#line 1651 "parser.cpp"
    break;

  case 15:
#line 70 "parser.y"
                                 {(yyval.intval) = (yyvsp[-2].intval) + (yyvsp[0].intval);}
#line 1657 "parser.cpp"
    break;

  case 16:
#line 71 "parser.y"
                                 {(yyval.intval) = (yyvsp[-2].intval) - (yyvsp[0].intval);}
#line 1663 "parser.cpp"
    break;

  case 17:
#line 72 "parser.y"
                                 {(yyval.intval) = (yyvsp[-2].intval) * (yyvsp[0].intval);}
#line 1669 "parser.cpp"
    break;

  case 18:
#line 73 "parser.y"
                                 {(yyval.intval) = (yyvsp[-2].intval) / (yyvsp[0].intval);}
#line 1675 "parser.cpp"
    break;

  case 19:
#line 74 "parser.y"
                                 {(yyval.intval) = (yyvsp[-2].intval) % (yyvsp[0].intval);}
#line 1681 "parser.cpp"
    break;

  case 20:
#line 75 "parser.y"
                                 {(yyval.intval) = ((yyvsp[-2].intval) > (yyvsp[0].intval))?1:0;}
#line 1687 "parser.cpp"
    break;

  case 21:
#line 76 "parser.y"
                                  {(yyval.intval) = ((yyvsp[-2].intval)>=(yyvsp[0].intval))?1:0;}
#line 1693 "parser.cpp"
    break;

  case 22:
#line 77 "parser.y"
                                 {(yyval.intval) = ((yyvsp[-2].intval)<(yyvsp[0].intval))?1:0;}
#line 1699 "parser.cpp"
    break;

  case 23:
#line 78 "parser.y"
                               {(yyval.intval) = ((yyvsp[-2].intval)<=(yyvsp[0].intval))?1:0;}
#line 1705 "parser.cpp"
    break;

  case 24:
#line 79 "parser.y"
                                         {(yyval.intval) = ((yyvsp[-2].intval)==(yyvsp[0].intval))?1:0;}
#line 1711 "parser.cpp"
    break;

  case 25:
#line 80 "parser.y"
                                 {(yyval.intval) = ((yyvsp[-2].intval)!=(yyvsp[0].intval))?1:0;}
#line 1717 "parser.cpp"
    break;

  case 26:
#line 81 "parser.y"
                                 {(yyval.intval) = ((yyvsp[-2].intval)&&(yyvsp[0].intval))?1:0;}
#line 1723 "parser.cpp"
    break;

  case 27:
#line 82 "parser.y"
                                 {(yyval.intval) = ((yyvsp[-2].intval)||(yyvsp[0].intval))?1:0;}
#line 1729 "parser.cpp"
    break;

  case 29:
#line 86 "parser.y"
                                      { printf( "(" ); }
#line 1735 "parser.cpp"
    break;

  case 30:
#line 87 "parser.y"
                     { printf(" - ");}
#line 1741 "parser.cpp"
    break;

  case 31:
#line 88 "parser.y"
                   { printf(" != "); }
#line 1747 "parser.cpp"
    break;

  case 32:
#line 89 "parser.y"
                           { 
				string var = (yyvsp[0].stringval);
				pair<int,Information> scopeFound = lookupTillGlobalScope(var,true);
				if(scopeFound.first==-1){
					printf("Error: %s was not found! (line %d)\n",var.c_str(),yylineno); 
				}else if(scopeFound.first==-2){
					printf("Error: %s is not accessible! (line %d)\n",var.c_str(),yylineno); 
				}else {
					if(scopeFound.second.type == USERFUNC || scopeFound.second.type == LIBFUNC){
						printf("Error: Can't use increment operator on function! (line %d)\n", yylineno);
					} //else printf("Prefix increment operator at %s (line %d) at scope %d\n",var.c_str(), yylineno, scopeFound);
				}
			}
#line 1765 "parser.cpp"
    break;

  case 33:
#line 102 "parser.y"
                           { 
				string var = (yyvsp[-1].stringval);
				pair<int,Information> scopeFound = lookupTillGlobalScope(var,true);
				if(scopeFound.first==-1){
					printf("Error: %s was not found! (line %d)\n",var.c_str(),yylineno); 
				}else if(scopeFound.first==-2){
					printf("Error: %s is not accessible! (line %d)\n",var.c_str(),yylineno); 
				}else {
					if(scopeFound.second.type == USERFUNC || scopeFound.second.type == LIBFUNC){
						printf("Error: Can't use increment operator on function! (line %d)\n", yylineno);
					} //else printf("Suffix increment operator at %s (line %d) at scope %d\n",var.c_str(), yylineno, scopeFound);
				}
			}
#line 1783 "parser.cpp"
    break;

  case 34:
#line 115 "parser.y"
                             { 
				string var = (yyvsp[0].stringval);
				pair<int,Information> scopeFound = lookupTillGlobalScope(var,true);
				if(scopeFound.first==-1){
					printf("Error: %s was not found! (line %d)\n",var.c_str(),yylineno); 
				}else if(scopeFound.first==-2){
					printf("Error: %s is not accessible! (line %d)\n",var.c_str(),yylineno); 
				}else {
					if(scopeFound.second.type == USERFUNC || scopeFound.second.type == LIBFUNC){
						printf("Error: Can't use decrement operator on function! (line %d)\n", yylineno);
					} //else printf("Prefix decrement operator at %s (line %d) at scope %d\n",var.c_str(), yylineno, scopeFound);
				}
			}
#line 1801 "parser.cpp"
    break;

  case 35:
#line 128 "parser.y"
                             {
				string var = (yyvsp[0].stringval);
				pair<int,Information> scopeFound = lookupTillGlobalScope(var,true);
				if(scopeFound.first==-1){
					printf("Error: %s was not found! (line %d)\n",var.c_str(),yylineno); 
				}else if(scopeFound.first==-2){
					printf("Error: %s is not accessible! (line %d)\n",var.c_str(),yylineno); 
				}else {
					if(scopeFound.second.type == USERFUNC || scopeFound.second.type == LIBFUNC){
						printf("Error: Can't use decrement operator on function! (line %d)\n", yylineno);
					} //else printf("Suffix decrement operator at %s (line %d) at scope %d\n",var.c_str(), yylineno, scopeFound);
				}
			}
#line 1819 "parser.cpp"
    break;

  case 37:
#line 144 "parser.y"
                           { //This should be correct - This part is done
			string var = (yyvsp[-2].stringval);
			pair<int,Information> scopeFound = lookupTillGlobalScope(var,true);
			//printf("playing with %s (line %d) (scopeFound: %d)\n",var.c_str(),yylineno,scopeFound.first); 
			if(scopeFound.first==-1){
				insertVariable(var, yylineno);
				//printf("%s inserted! (line %d)\n",var.c_str(),yylineno); 
			}else if(scopeFound.first==-2){
				printf("Error: %s is not accessible! (line %d)\n",var.c_str(),yylineno); 
			}else {
				if(scopeFound.second.type == USERFUNC || scopeFound.second.type == LIBFUNC){
					printf("Error: Can not assign value to function! (line %d)\n", yylineno);
				} //else printf("We refer to the already existant %s (line %d) at scope %d\n",var.c_str(), yylineno, scope);
			}
		}
#line 1839 "parser.cpp"
    break;

  case 38:
#line 159 "parser.y"
                                        {
			string var = (yyvsp[-2].stringval);
			pair<int,Information> lk = lookup(var);
			if(lk.first==-1){
				if(!isSystemFunction(var)){
					insertVariable(var,yylineno);
					//printf("%s inserted! (line %d)\n",var.c_str(),yylineno); 
				}else printf("Error: %s is a system function. (line %d)\n",var.c_str(),yylineno); 
			}else {
				if(lk.second.type == USERFUNC || lk.second.type == LIBFUNC){
					printf("Error: Can not assign value to function! (line %d)\n",yylineno);
				} //else printf("We refer to the already existant %s (line %d)\n",var.c_str(),yylineno);
			}
	   	 }
#line 1858 "parser.cpp"
    break;

  case 39:
#line 173 "parser.y"
                                               { 
				string var = (yyvsp[-2].stringval);
				pair<int,Information> lk = globalLookup(var);
				if(lk.first!=-1){
					if(lk.second.type == USERFUNC || lk.second.type == LIBFUNC){
						printf("Error: Can not assign value to function! (line %d)\n",yylineno);
					} //else printf("We refer to the global %s (line %d)\n",var.c_str(),yylineno);
				}else{
					printf("Error: Could not find a global variable/function %s (line %d)\n",var.c_str(),yylineno);
				}
	   	 }
#line 1874 "parser.cpp"
    break;

  case 49:
#line 197 "parser.y"
           {
			string var = (yyvsp[0].stringval);
			
			//lookup without taking into account if there is function in between
			pair<int,Information> search = lookupTillGlobalScope(var,false);
			
			if(search.first==-1){
				//Not found at all!
				if(shouldInsert) {
					insertVariable(var, yylineno);
					//printf("%s inserted! (line %d)\n",var.c_str(),yylineno); 
				}else {
					printf("Error: %s was not found! (line %d)\n",var.c_str(),yylineno);
				}	
			}else{
				if(search.second.type == USERFUNC || search.second.type == LIBFUNC){
					printf("1WWWWWe refer to the already existant function %s (line %d) at scope %d\n",var.c_str(), yylineno, scope);
				}else{
					//In this case the variable should be a variable
					search = lookupTillGlobalScope(var,true);
					if(search.first==-1){
						if(shouldInsert) {
							insertVariable(var, yylineno);
							//printf("%s inserted! (line %d)\n",var.c_str(),yylineno); 
						}else {
							printf("Error: %s was not found! (line %d)\n",var.c_str(),yylineno);
						}					
					}else if(search.first==-2){
						printf("Error: %s is not accessible! (line %d)\n",var.c_str(),yylineno); 
					}else {
						printf("2WWWWWe refer to the already existant %s (line %d) at scope %d\n",var.c_str(), yylineno, scope);
					}
				}
			}
			/* REMOVE THIS IF EVERYTHING WORKS
			if(insideCall){
				pair<int,Information> scopeFound = lookupTillGlobalScope(var,false);
				if(scopeFound.first==-1){
					printf("Error: %s was not found! (line %d)\n",var.c_str(),yylineno);	
				}else {
					//printf("We refer to the already existant %s (line %d) at scope %d\n",var.c_str(), yylineno, scope);
				}
			}else{
				pair<int,Information> scopeFound = lookupTillGlobalScope(var,true);
				if(scopeFound.first==-1){
					if(shouldInsert) { 
						insertVariable(var, yylineno);
						//printf("%s inserted! (line %d)\n",var.c_str(),yylineno); 
					}else {
						printf("Error: %s was not found! (line %d)\n",var.c_str(),yylineno);
					}					
				}else if(scopeFound.first==-2){
					printf("Error: %s is not accessible! (line %d)\n",var.c_str(),yylineno); 
				}else {
					//printf("We refer to the already existant %s (line %d) at scope %d\n",var.c_str(), yylineno, scope);
				}
			}
			*/
		}
#line 1938 "parser.cpp"
    break;

  case 50:
#line 256 "parser.y"
                     { //This part is correct 100%
			string var = (yyvsp[0].stringval);
			if(lookup(var).first==-1){
				if(!isSystemFunction(var)){
					if(shouldInsert) insertVariable(var,yylineno);
					//printf("%s inserted! (line %d)\n",var.c_str(),yylineno); 
				}else printf("Error: %s is a system function. (line %d)\n",var.c_str(),yylineno); 
			}//else printf("We refer to the already existant %s (line %d)\n",var.c_str(),yylineno); 
		
		}
#line 1953 "parser.cpp"
    break;

  case 51:
#line 266 "parser.y"
                            { //This part is correct 100%
			string var = (yyvsp[0].stringval);
			pair<int,Information> lk = globalLookup(var);
			if(lk.first==-1)
				printf("Error: Could not find global variable %s (line %d)\n", var.c_str(), yylineno);
			//else printf("We refer to the already existant global %s (line %d)\n", var.c_str(), yylineno); 
		}
#line 1965 "parser.cpp"
    break;

  case 66:
#line 300 "parser.y"
           {}
#line 1971 "parser.cpp"
    break;

  case 71:
#line 311 "parser.y"
                       {shouldInsert = false;}
#line 1977 "parser.cpp"
    break;

  case 72:
#line 311 "parser.y"
                                                         {shouldInsert = true;}
#line 1983 "parser.cpp"
    break;

  case 74:
#line 314 "parser.y"
                                {;}
#line 1989 "parser.cpp"
    break;

  case 75:
#line 315 "parser.y"
          {;}
#line 1995 "parser.cpp"
    break;

  case 76:
#line 318 "parser.y"
                  {increaseScope();}
#line 2001 "parser.cpp"
    break;

  case 77:
#line 319 "parser.y"
                    {}
#line 2007 "parser.cpp"
    break;

  case 78:
#line 320 "parser.y"
                       {decreaseScope();}
#line 2013 "parser.cpp"
    break;

  case 79:
#line 323 "parser.y"
                     { 
			string fName = (yyvsp[0].stringval); 
			pair<int,Information> lk = lookup(fName);
			if(lk.first!=-1){
				printf("Error: %s already declared in this scope (line %d).\n",fName.c_str(),yylineno);
			}else{
				if(isSystemFunction(fName)){
					printf("Error: %s it is already defined as a lib function. (line %d)\n",fName.c_str(),yylineno);
				} else insertUserFunction(fName, yylineno);
			}
		}
#line 2029 "parser.cpp"
    break;

  case 80:
#line 334 "parser.y"
                              { increaseScope(); pushType(1);}
#line 2035 "parser.cpp"
    break;

  case 81:
#line 339 "parser.y"
                            {decreaseScope();popType();}
#line 2041 "parser.cpp"
    break;

  case 82:
#line 340 "parser.y"
                           { 
			string fName = ("_f"+to_string(fID++));
			while(lookup(fName).first!=-1 || isSystemFunction(fName)) fName = ("_f"+to_string(fID++));
			insertUserFunction(fName, yylineno);
			//printf("Inserted function with name %s\n", fName.c_str());
		}
#line 2052 "parser.cpp"
    break;

  case 83:
#line 346 "parser.y"
                              { increaseScope(); pushType(1);}
#line 2058 "parser.cpp"
    break;

  case 84:
#line 351 "parser.y"
                            {decreaseScope();popType();}
#line 2064 "parser.cpp"
    break;

  case 91:
#line 362 "parser.y"
                                                {	
			string varName = yytext; 
			pair<int,Information> lk = lookup(varName);
			if(lk.first!=-1){
				printf("Error: %s already declared in this scope (line %d).\n",varName.c_str(),yylineno);
			}else{
				if(isSystemFunction(varName)){
					printf("Error: %s can not be a function argument, it is a lib function. (line %d)\n",varName.c_str(),yylineno);
				} else insertArgument(varName, yylineno);
			}
		}
#line 2080 "parser.cpp"
    break;

  case 92:
#line 373 "parser.y"
                                        {	
			string varName = yytext; 
			pair<int,Information> lk = lookup(varName);
			if(lk.first!=-1){
				printf("Error: %s already declared in this scope (line %d).\n",varName.c_str(),yylineno);
			}else{
				if(isSystemFunction(varName)){
					printf("Error: %s can not be a function argument, it is a lib function. (line %d)\n",varName.c_str(),yylineno);
				} else insertArgument(varName, yylineno);
			}
		}
#line 2096 "parser.cpp"
    break;

  case 93:
#line 384 "parser.y"
                  {}
#line 2102 "parser.cpp"
    break;

  case 94:
#line 388 "parser.y"
                {
			//printf("if(expr)");
		}
#line 2110 "parser.cpp"
    break;

  case 95:
#line 392 "parser.y"
                {
			//printf("if stmt"); 
		}
#line 2118 "parser.cpp"
    break;

  case 96:
#line 396 "parser.y"
                {
			//printf("else"); 
		}
#line 2126 "parser.cpp"
    break;

  case 97:
#line 400 "parser.y"
                {
			//printf("else stmt"); 
		}
#line 2134 "parser.cpp"
    break;

  case 98:
#line 406 "parser.y"
                 {
			 pushType(0);
		 }
#line 2142 "parser.cpp"
    break;

  case 99:
#line 410 "parser.y"
                 {
		 }
#line 2149 "parser.cpp"
    break;

  case 100:
#line 413 "parser.y"
                 {
			popType();
		 }
#line 2157 "parser.cpp"
    break;

  case 101:
#line 420 "parser.y"
                {
			pushType(0);
		}
#line 2165 "parser.cpp"
    break;

  case 102:
#line 424 "parser.y"
                {
		}
#line 2172 "parser.cpp"
    break;

  case 103:
#line 427 "parser.y"
                {
			popType();
		}
#line 2180 "parser.cpp"
    break;

  case 104:
#line 432 "parser.y"
                                 {if(!isInFunction()) printf("Error: This return is not part of a function. (line %d)\n",yylineno); }
#line 2186 "parser.cpp"
    break;

  case 105:
#line 433 "parser.y"
                          {shouldInsert = false;}
#line 2192 "parser.cpp"
    break;

  case 106:
#line 433 "parser.y"
                                                                { if(!isInFunction()) printf("Error: This return is not part of a function. (line %d)\n",yylineno); shouldInsert = true;}
#line 2198 "parser.cpp"
    break;


#line 2202 "parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 435 "parser.y"


/* this will be called if we have syntax errors */
int yyerror (char* yaccProvidedMessage) {
	fprintf(stderr, "%s: at line %d, before token: %s\n", yaccProvidedMessage, yylineno, yytext);
	fprintf(stderr, "INPUT NOT VALID\n");
	cout << "EEK, parse error on line " << yylineno << "!  Message: " << yaccProvidedMessage << endl;
	return 0;
}

int main(int argc, char** argv) {
    if(argc<2 || argc>3){
        fprintf(stderr, "Invalid arguments! Usage: ./calc input.txt (output.txt)\n");
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
	initializeSymTable();
	yyparse(); /* Parse through the input - the function generated by yacc */
	
	printFullSymTable();
	
	fclose(yyin);
    return 0;
}
