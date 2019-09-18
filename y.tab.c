/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "lab9.y" /* yacc.c:339  */

/*
Programmer: Fidel Garcia
Date: March 26. 2019
Details: This YACC program will interpet the tokens that are given from our LEX
		program and will create and interpet the tokens into our regular Expression
		language. This program will also create nodes that are predefined in 
		our C program and header file. Additionally, this program will also have
		semantic action after every declaration, weather it be with variables
		variable types, and or compositional statements such as functions, if 
		statements, read, writes and call methods, with the additional a symbol table and type checking. 
Input: This file will take tokens from LEX.
Output: This file will handle the tokens from LEX and if the tokens are in the
		correct sequence then the file will create nodes and have function calls 
		to print, what tokens are seen. If the sequence is not correct then this
		file will display a generic syntax error.   
*/	
	
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "symtable.h"
#include "emit.h"

extern int lineNum;
extern int mydebug;

int level = 0;
int offset = 2;
int tempOffest = 0;
int maxOffset = 0;
int yylex(); 

struct ASTnodetype *myprogram = NULL;				

/* Called by yyparse on error */
void yyerror (s)  
	char *s;{
  fprintf (stderr,"%s on line %d\n", s, lineNum);
				}

#line 110 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    NUM = 258,
    ID = 259,
    INT = 260,
    VOID = 261,
    WHILE = 262,
    DO = 263,
    IF = 264,
    THEN = 265,
    ELSE = 266,
    READ = 267,
    WRITE = 268,
    FOR = 269,
    RETURN = 270,
    LE = 271,
    GE = 272,
    EQ = 273,
    NE = 274,
    L = 275,
    G = 276,
    STRING = 277,
    THEBEGIN = 278,
    END = 279,
    OF = 280,
    BOOLEAN = 281,
    TRUE = 282,
    FALSE = 283,
    AND = 284,
    OR = 285,
    NOT = 286
  };
#endif
/* Tokens.  */
#define NUM 258
#define ID 259
#define INT 260
#define VOID 261
#define WHILE 262
#define DO 263
#define IF 264
#define THEN 265
#define ELSE 266
#define READ 267
#define WRITE 268
#define FOR 269
#define RETURN 270
#define LE 271
#define GE 272
#define EQ 273
#define NE 274
#define L 275
#define G 276
#define STRING 277
#define THEBEGIN 278
#define END 279
#define OF 280
#define BOOLEAN 281
#define TRUE 282
#define FALSE 283
#define AND 284
#define OR 285
#define NOT 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 48 "lab9.y" /* yacc.c:355  */

  int number;
  char *string;
  struct ASTnodetype *ASTnode;
	enum Operator myOperator;
	enum SystemType myType;

#line 220 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 237 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   127

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  129

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    37,     2,     2,
      41,    42,    36,    33,    40,    34,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    32,
      44,    43,    45,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    70,    71,    75,    76,    79,    90,   104,
     119,   134,   150,   151,   152,   155,   167,   155,   182,   183,
     186,   187,   190,   203,   218,   218,   230,   231,   235,   236,
     240,   241,   242,   243,   244,   245,   246,   247,   250,   253,
     256,   262,   270,   276,   277,   282,   287,   291,   298,   304,
     307,   308,   325,   343,   363,   364,   365,   366,   367,   368,
     371,   372,   388,   389,   392,   393,   409,   410,   411,   412,
     415,   416,   420,   421,   422,   426,   430,   440,   469,   470,
     472,   477
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "ID", "INT", "VOID", "WHILE",
  "DO", "IF", "THEN", "ELSE", "READ", "WRITE", "FOR", "RETURN", "LE", "GE",
  "EQ", "NE", "L", "G", "STRING", "THEBEGIN", "END", "OF", "BOOLEAN",
  "TRUE", "FALSE", "AND", "OR", "NOT", "';'", "'+'", "'-'", "'/'", "'*'",
  "'%'", "'['", "']'", "','", "'('", "')'", "'='", "'<'", "'>'", "$accept",
  "program", "declList", "decl", "varDecl", "varList", "type", "funcDecl",
  "$@1", "$@2", "params", "paramList", "param", "compState", "$@3",
  "locDecl", "stateList", "state", "exprState", "selcState", "iterState",
  "retState", "readState", "wrtState", "assState", "expr", "simpExpr",
  "var", "relop", "addExpr", "addop", "term", "multop", "factor", "call",
  "args", "argsList", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,    59,    43,    45,    47,    42,    37,    91,    93,
      44,    40,    41,    61,    60,    62
};
# endif

#define YYPACT_NINF -102

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-102)))

#define YYTABLE_NINF -19

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      19,  -102,  -102,  -102,     7,  -102,    19,  -102,    18,  -102,
    -102,  -102,    34,    12,    45,    51,     9,  -102,    21,    54,
    -102,    47,    26,    42,    82,    57,  -102,    49,    51,    63,
    -102,    19,  -102,    61,    70,  -102,  -102,  -102,  -102,    19,
      19,    51,     8,  -102,  -102,   -11,    30,    30,    98,    10,
      15,  -102,  -102,    30,  -102,    30,  -102,    79,     8,  -102,
    -102,  -102,  -102,  -102,  -102,  -102,    72,  -102,    64,    46,
      52,  -102,  -102,    30,    30,    97,  -102,    96,    71,    76,
      78,    80,  -102,    81,  -102,    69,  -102,  -102,  -102,    30,
    -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,    30,    30,
    -102,  -102,  -102,  -102,    30,    75,    77,    73,  -102,     8,
       8,  -102,  -102,  -102,  -102,  -102,    84,    62,    52,  -102,
    -102,    30,  -102,  -102,   107,  -102,  -102,     8,  -102
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    12,    13,    14,     0,     2,     3,     5,     0,     6,
       1,     4,     8,     0,     0,     0,     0,     7,     0,     8,
      10,     0,     9,    13,     0,     0,    19,    20,     0,    22,
      16,     0,    11,     0,     0,    21,    23,    24,    17,    26,
      26,     0,    28,    27,    71,    52,     0,     0,     0,     0,
       0,    74,    75,     0,    39,     0,    31,     0,    28,    30,
      32,    33,    35,    36,    37,    34,     0,    49,    72,    50,
      60,    64,    73,     0,    78,     0,    72,     0,    52,     0,
       0,     0,    43,     0,    76,     0,    25,    29,    38,     0,
      54,    57,    58,    59,    62,    63,    55,    56,     0,     0,
      68,    69,    67,    66,     0,     0,    80,     0,    79,     0,
       0,    45,    47,    46,    44,    70,     0,    51,    61,    65,
      53,     0,    77,    42,    40,    48,    81,     0,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -102,  -102,   113,  -102,    58,    55,    38,  -102,  -102,  -102,
    -102,    89,  -102,    87,  -102,    83,    66,  -101,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,   -45,    33,   -42,  -102,    27,
    -102,    28,  -102,   -50,  -102,  -102,     5
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    13,     8,     9,    16,    34,
      25,    26,    27,    56,    39,    42,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    76,    98,    69,
      99,    70,   104,    71,    72,   107,   108
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      68,    75,    77,    84,    81,    83,    79,    10,   123,   124,
      85,    44,    45,    44,    45,    46,    68,    47,    44,    45,
      48,    49,    12,    50,     1,     2,   128,    73,   105,   106,
      74,    37,    80,    44,    45,    51,    52,    51,    52,    53,
      54,    53,    51,    52,    17,     3,    53,    82,    18,    55,
      21,    55,     1,    23,   119,    19,    55,    51,    52,    24,
      22,    53,    90,    91,    92,    93,    28,    68,    68,    24,
      20,    55,    14,     3,    15,   -15,   106,    41,    41,    94,
      95,   100,   101,    32,   -18,    68,    29,   102,   103,    31,
      96,    97,    14,    37,    15,    94,    95,    40,    40,    30,
      36,    33,    78,    86,    88,   109,   110,    89,   111,    73,
     112,   115,   113,   114,   120,   122,   125,   121,   127,    11,
      35,    38,   116,    43,    87,   117,   126,   118
};

static const yytype_uint8 yycheck[] =
{
      42,    46,    47,    53,    49,    50,    48,     0,   109,   110,
      55,     3,     4,     3,     4,     7,    58,     9,     3,     4,
      12,    13,     4,    15,     5,     6,   127,    38,    73,    74,
      41,    23,    22,     3,     4,    27,    28,    27,    28,    31,
      32,    31,    27,    28,    32,    26,    31,    32,     3,    41,
      41,    41,     5,     6,   104,     4,    41,    27,    28,    21,
      39,    31,    16,    17,    18,    19,    40,   109,   110,    31,
      15,    41,    38,    26,    40,    41,   121,    39,    40,    33,
      34,    29,    30,    28,    42,   127,     4,    35,    36,    40,
      44,    45,    38,    23,    40,    33,    34,    39,    40,    42,
      39,    38,     4,    24,    32,     8,    10,    43,    32,    38,
      32,    42,    32,    32,    39,    42,    32,    40,    11,     6,
      31,    34,    89,    40,    58,    98,   121,    99
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,    26,    47,    48,    49,    50,    52,    53,
       0,    48,     4,    51,    38,    40,    54,    32,     3,     4,
      51,    41,    39,     6,    52,    56,    57,    58,    40,     4,
      42,    40,    51,    38,    55,    57,    39,    23,    59,    60,
      50,    52,    61,    61,     3,     4,     7,     9,    12,    13,
      15,    27,    28,    31,    32,    41,    59,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    75,
      77,    79,    80,    38,    41,    71,    73,    71,     4,    73,
      22,    71,    32,    71,    79,    71,    24,    62,    32,    43,
      16,    17,    18,    19,    33,    34,    44,    45,    74,    76,
      29,    30,    35,    36,    78,    71,    71,    81,    82,     8,
      10,    32,    32,    32,    32,    42,    72,    75,    77,    79,
      39,    40,    42,    63,    63,    32,    82,    11,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    51,    51,
      51,    51,    52,    52,    52,    54,    55,    53,    56,    56,
      57,    57,    58,    58,    60,    59,    61,    61,    62,    62,
      63,    63,    63,    63,    63,    63,    63,    63,    64,    64,
      65,    65,    66,    67,    67,    68,    69,    69,    70,    71,
      72,    72,    73,    73,    74,    74,    74,    74,    74,    74,
      75,    75,    76,    76,    77,    77,    78,    78,    78,    78,
      79,    79,    79,    79,    79,    79,    79,    80,    81,    81,
      82,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     1,     4,
       3,     6,     1,     1,     1,     0,     0,     8,     1,     1,
       1,     3,     2,     4,     0,     5,     0,     2,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       4,     6,     4,     2,     3,     3,     3,     3,     4,     1,
       1,     3,     1,     4,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     2,     4,     0,     1,
       1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 67 "lab9.y" /* yacc.c:1646  */
    {myprogram = (yyvsp[0].ASTnode);}
#line 1408 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 70 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode);}
#line 1414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 71 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = (yyvsp[-1].ASTnode);
                           (yyvsp[-1].ASTnode) ->next = (yyvsp[0].ASTnode);}
#line 1421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 75 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode);}
#line 1427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 76 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode);}
#line 1433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 79 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = (yyvsp[-1].ASTnode);
							ASTnode *p;
							p = (yyval.ASTnode);
								while (p != NULL){
									p ->mytype = (yyvsp[-2].myType);
									p ->symbol ->Type = (yyvsp[-2].myType);
									p = p ->s1;
								}
                            }
#line 1447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 90 "lab9.y" /* yacc.c:1646  */
    {struct SymbTab *p;
					if (Search((yyvsp[0].string), level, 0) == NULL){
						(yyval.ASTnode) = ASTCreateNode(VarDec);
                        (yyval.ASTnode) ->name = (yyvsp[0].string);
						(yyval.ASTnode) ->symbol = Insert((yyvsp[0].string), 0, 0, level, 1, offset, NULL);
							offset++;
							Display();
							} else{
								yyerror((yyvsp[0].string));
								yyerror("Error: Value(s) already been prev. declared.");
								exit(1);
							}
              }
#line 1465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 104 "lab9.y" /* yacc.c:1646  */
    {struct SymbTab *p;
									if (Search((yyvsp[-3].string), level, 0) == NULL){
				 					   (yyval.ASTnode) = ASTCreateNode(VarDec);
                     (yyval.ASTnode) ->name = (yyvsp[-3].string);
									   (yyval.ASTnode) ->value = (yyvsp[-1].number);
                     (yyval.ASTnode) ->symbol = Insert((yyvsp[-3].string), 0, 2, level, (yyvsp[-1].number), offset, 0);
										offset = offset + (yyvsp[-1].number);
										Display();
                          	} else{
									  yyerror((yyvsp[-3].string));
									  yyerror("Error: Value(s) already been prev. declared.");
									  exit(1);
                          		}
							  		}
#line 1484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 119 "lab9.y" /* yacc.c:1646  */
    {struct SymbTab *p;
				 					if (Search((yyvsp[-2].string), level, 0) == NULL){
				 					   (yyval.ASTnode) = ASTCreateNode(VarDec);
                     (yyval.ASTnode) ->name = (yyvsp[-2].string);
                     (yyval.ASTnode) ->s1 = (yyvsp[0].ASTnode);
									   (yyval.ASTnode) ->symbol = Insert((yyvsp[-2].string), 0, 0, level, 1, offset, 0);
										offset++;
										Display();
                          } else{
									  yyerror((yyvsp[-2].string));
									  yyerror("Error: Value(s) already been prev. declared.");
									  exit(1);
                          		}
							  }
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 134 "lab9.y" /* yacc.c:1646  */
    {struct SymbTab *p;
                                        if (Search((yyvsp[-5].string), level, 0) == NULL){
                                           (yyval.ASTnode) = ASTCreateNode(VarDec);
                                           (yyval.ASTnode) ->name = (yyvsp[-5].string);
                                           (yyval.ASTnode) ->symbol = Insert((yyvsp[-5].string), 0, 2, level, (yyvsp[-3].number), offset, 0);
                                            offset = offset + (yyvsp[-3].number);
                                           (yyval.ASTnode) ->value = (yyvsp[-3].number);
                                           (yyval.ASTnode) ->s1 = (yyvsp[0].ASTnode);
                                       } else {
                                            yyerror((yyvsp[-5].string));
                                            yyerror("Error: Value(s) already been prev. declared");
                                            exit(1);
                                       }
                                    }
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 150 "lab9.y" /* yacc.c:1646  */
    {(yyval.myType) = INTType;}
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 151 "lab9.y" /* yacc.c:1646  */
    {(yyval.myType) = VOIDType;}
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 152 "lab9.y" /* yacc.c:1646  */
    {(yyval.myType) = BOOLType;}
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 155 "lab9.y" /* yacc.c:1646  */
    {if(Search((yyvsp[0].string), level, 0)== NULL){
                    tempOffest = offset;
                    offset = 2;
                    maxOffset = offset;
                    Insert((yyvsp[0].string), (yyvsp[-1].myType), 1, level, 1, offset, 0);
                        }else{
                        	yyerror((yyvsp[0].string));
									yyerror("Error: Function has already been prev defined");
									exit(1);
                        }
                    }
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 167 "lab9.y" /* yacc.c:1646  */
    {Search((yyvsp[-4].string), 0, 0) -> fparms = (yyvsp[-1].ASTnode);}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 169 "lab9.y" /* yacc.c:1646  */
    {struct SymbTab *p;
                        (yyval.ASTnode) = ASTCreateNode(FuncDec);
                        (yyval.ASTnode) ->name = (yyvsp[-6].string);
                        (yyval.ASTnode) ->mytype = (yyvsp[-7].myType);
                        (yyval.ASTnode) ->size = maxOffset; /* size of the node */
                        (yyval.ASTnode) ->symbol = Search((yyvsp[-6].string), level, 0);
                        (yyval.ASTnode) ->symbol ->offset = maxOffset; /* size of the Symb struct */
                        (yyval.ASTnode) ->s1 = (yyvsp[-3].ASTnode);
                        (yyval.ASTnode) ->s2 = (yyvsp[0].ASTnode);
                        offset = tempOffest;
                        }
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 182 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = NULL;}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 183 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode);}
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 186 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode);}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 187 "lab9.y" /* yacc.c:1646  */
    {(yyvsp[-2].ASTnode) -> next = (yyvsp[0].ASTnode);}
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 190 "lab9.y" /* yacc.c:1646  */
    {if (Search((yyvsp[0].string), level+1, 0) == NULL){
  							(yyval.ASTnode) = ASTCreateNode(Param);
  						 	(yyval.ASTnode) ->name =(yyvsp[0].string);
  						 	(yyval.ASTnode) ->mytype = (yyvsp[-1].myType);
							(yyval.ASTnode) ->symbol = Insert((yyvsp[0].string), (yyvsp[-1].myType), 0, level+1, 1, offset, 0);
								offset++;
								}else{
									yyerror((yyvsp[0].string));
									yyerror("Error: Parameter has already been prev. defined");
									exit(1);
								}
						  
                   }
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 203 "lab9.y" /* yacc.c:1646  */
    {if (Search((yyvsp[-2].string), level+1, 0) == NULL){
									(yyval.ASTnode) = ASTCreateNode(Param);
             				  	(yyval.ASTnode) ->name = (yyvsp[-2].string);
									(yyval.ASTnode) ->value = -1;
            					(yyval.ASTnode) ->mytype = (yyvsp[-3].myType);
									(yyval.ASTnode) ->symbol = Insert((yyvsp[-2].string), (yyvsp[-3].myType), 2, level+1, 1, offset, 0);
										offset++;
          						}else{
										yyerror((yyvsp[-2].string));
										yyerror("Error: Parameter [] has already been prev. defined");
										exit(1);
          							}
                          }
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 218 "lab9.y" /* yacc.c:1646  */
    {level++;}
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 219 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = ASTCreateNode(Block);
                                           (yyval.ASTnode) -> s1 = (yyvsp[-2].ASTnode);
                                           (yyval.ASTnode) -> s2 = (yyvsp[-1].ASTnode);
														 Display();
														 if (maxOffset < offset)
														 	maxOffset = offset;
														 	offset = offset - Delete(level);
															level--;
                                           }
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 230 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = NULL;}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 231 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = (yyvsp[-1].ASTnode);
                            (yyvsp[-1].ASTnode) -> next = (yyvsp[0].ASTnode);}
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 235 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = NULL;}
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 236 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = (yyvsp[-1].ASTnode);
                            (yyvsp[-1].ASTnode) -> next = (yyvsp[0].ASTnode);}
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 240 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode);}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 241 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode);}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 242 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode);}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 243 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode);}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 244 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode);}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 245 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode);}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 246 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode);}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 247 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode);}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 250 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = ASTCreateNode(Expression);
                    (yyval.ASTnode) -> s1 = (yyvsp[-1].ASTnode);}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 253 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = ASTCreateNode(Expression);}
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 256 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = ASTCreateNode(ifState);
                               (yyval.ASTnode) -> s1 = (yyvsp[-2].ASTnode);
                               (yyval.ASTnode) ->s2 = ASTCreateNode(ifElse);
                               (yyval.ASTnode) -> s2 ->s1 = (yyvsp[0].ASTnode);
                               }
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 262 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = ASTCreateNode(ifState);
                                         (yyval.ASTnode) ->s1 = (yyvsp[-4].ASTnode);
                                         (yyval.ASTnode) ->s2 = ASTCreateNode(ifElse);
                                         (yyval.ASTnode) ->s2 ->s1 = (yyvsp[-2].ASTnode);
                                         (yyval.ASTnode) ->s2 ->s2 = (yyvsp[0].ASTnode);
                                         }
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 270 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = ASTCreateNode(Iterative);
                               (yyval.ASTnode) ->s1 = (yyvsp[-2].ASTnode);
                               (yyval.ASTnode) ->s2 = (yyvsp[0].ASTnode);
                               }
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 276 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = ASTCreateNode(ReturnState);}
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 277 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = ASTCreateNode(ReturnState);
                            (yyval.ASTnode) ->s1 = (yyvsp[-1].ASTnode);
                           }
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 282 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = ASTCreateNode(Read);
                         (yyval.ASTnode) ->s1 = (yyvsp[-1].ASTnode); 
                        }
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 287 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = ASTCreateNode(Write);
                           (yyval.ASTnode) ->s1 = (yyvsp[-1].ASTnode);
                          }
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 291 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = ASTCreateNode(Write);
                             (yyval.ASTnode) ->name = (yyvsp[-1].string);
                             (yyval.ASTnode) ->mytype = STRINGType;
                             (yyval.ASTnode) ->label = label();
                            }
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 298 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = ASTCreateNode(Assign);
                                (yyval.ASTnode) ->s1 = (yyvsp[-3].ASTnode);
                                (yyval.ASTnode) ->s2 = (yyvsp[-1].ASTnode);
                                }
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 304 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode);}
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 307 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode);}
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 308 "lab9.y" /* yacc.c:1646  */
    {if ((yyvsp[-2].ASTnode) ->mytype == (yyvsp[0].ASTnode) ->mytype){
				 							(yyval.ASTnode) = ASTCreateNode(Expression);
                            	  	(yyval.ASTnode) ->s1 = (yyvsp[-2].ASTnode);
                     				(yyval.ASTnode) ->s2 = (yyvsp[0].ASTnode);
      									(yyval.ASTnode) ->mytype = (yyvsp[0].ASTnode) ->mytype;
											(yyval.ASTnode) ->myOperator = (yyvsp[-1].myOperator);
											(yyval.ASTnode) ->name = createTemp();
											(yyval.ASTnode) ->symbol = Insert((yyval.ASTnode) ->name, INTType, 0, level, 1, offset, 0);
                                                offset++;
											}else{
												yyerror("Error: Add expression mismatch");
												exit(1);
											}
										         
										}
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 325 "lab9.y" /* yacc.c:1646  */
    {struct SymbTab *p;
					if((p = Search((yyvsp[0].string), level, 1)) != NULL){
						(yyval.ASTnode) = ASTCreateNode(Var);
	               (yyval.ASTnode) ->name = (yyvsp[0].string);
						(yyval.ASTnode) ->symbol = p;
						(yyval.ASTnode) ->mytype = p ->Type;
						if(p ->IsAFunc == 2){
							yyerror((yyvsp[0].string));
							yyerror("Error: Variable is not a function");
							exit(1);
						}
						}else{
							yyerror((yyvsp[0].string));
							yyerror("Error: Variable has already been prev. defined");
							exit(1);
						}
              }
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 343 "lab9.y" /* yacc.c:1646  */
    {struct SymbTab *p;
				 				if((p = Search((yyvsp[-3].string), level, 1)) != NULL){
					 				(yyval.ASTnode) = ASTCreateNode(Var);
	          				  	(yyval.ASTnode) ->name = (yyvsp[-3].string);
	           				 	(yyval.ASTnode) ->s1 = (yyvsp[-1].ASTnode);
									(yyval.ASTnode) ->mytype = p ->Type;
									if(p ->IsAFunc == 2){
										(yyval.ASTnode) ->symbol = p;
										}else{
											yyerror((yyvsp[-3].string));
											yyerror("Variable [], is not a function");
										}
				 				} else{
				 					yyerror((yyvsp[-3].string));
									yyerror("Error: Variable [], has already prev. been defined");
				 					exit(1);
									}	
                        }
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 363 "lab9.y" /* yacc.c:1646  */
    {(yyval.myOperator) = LessThenEQ;}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 364 "lab9.y" /* yacc.c:1646  */
    {(yyval.myOperator) = LessThen;}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 365 "lab9.y" /* yacc.c:1646  */
    {(yyval.myOperator) = GreatThen;}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 366 "lab9.y" /* yacc.c:1646  */
    {(yyval.myOperator) = GreatThenEQ;}
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 367 "lab9.y" /* yacc.c:1646  */
    {(yyval.myOperator) = EqualTo;}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 368 "lab9.y" /* yacc.c:1646  */
    {(yyval.myOperator) = NotEqualTo;}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 371 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode);}
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 372 "lab9.y" /* yacc.c:1646  */
    {if((yyvsp[-2].ASTnode) ->mytype == (yyvsp[0].ASTnode) ->mytype){
				 							(yyval.ASTnode) = ASTCreateNode(Expression);
				                		(yyval.ASTnode) ->s1 = (yyvsp[-2].ASTnode);
				                  	(yyval.ASTnode) ->s2 = (yyvsp[0].ASTnode);
				                     (yyval.ASTnode) ->mytype = (yyvsp[0].ASTnode) ->mytype;
											(yyval.ASTnode) ->myOperator = (yyvsp[-1].myOperator);
											(yyval.ASTnode) ->name = createTemp();
											(yyval.ASTnode) ->symbol = Insert((yyval.ASTnode) ->name, INTType, 0, level, 1, offset, 0);
												offset++;
          							}else{
          								yyerror("Error: Add expression type mismatch");
											exit(1);
          								}
                              }
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 388 "lab9.y" /* yacc.c:1646  */
    {(yyval.myOperator) = MyPlus;}
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 389 "lab9.y" /* yacc.c:1646  */
    {(yyval.myOperator) = MyMinus;}
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 392 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode);}
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 393 "lab9.y" /* yacc.c:1646  */
    {if((yyvsp[-2].ASTnode) ->mytype == (yyvsp[0].ASTnode) ->mytype){
				 							(yyval.ASTnode) = ASTCreateNode(Expression);
				                		(yyval.ASTnode) ->s1 = (yyvsp[-2].ASTnode);
				                  	(yyval.ASTnode) ->s2 = (yyvsp[0].ASTnode);
				                     (yyval.ASTnode) ->mytype = (yyvsp[0].ASTnode) ->mytype;
											(yyval.ASTnode) ->myOperator = (yyvsp[-1].myOperator);
											(yyval.ASTnode) ->name = createTemp();
											(yyval.ASTnode) ->symbol = Insert((yyval.ASTnode) ->name, INTType, 0, level, 1, offset, 0);
												offset++;
          							}else{
          								yyerror("Error: Add expression type mismatch");
											exit(1);
          								}
                              }
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 409 "lab9.y" /* yacc.c:1646  */
    {(yyval.myOperator) = MyTimes;}
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 410 "lab9.y" /* yacc.c:1646  */
    {(yyval.myOperator) = MyDiv;}
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 411 "lab9.y" /* yacc.c:1646  */
    {(yyval.myOperator) = MyAND;}
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 412 "lab9.y" /* yacc.c:1646  */
    {(yyval.myOperator) = MyOR;}
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 415 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = (yyvsp[-1].ASTnode);}
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 416 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = ASTCreateNode(Number);
                (yyval.ASTnode) ->value = (yyvsp[0].number);
					 (yyval.ASTnode) ->mytype = INTType;
                }
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 420 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode);}
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 421 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode);}
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 422 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = ASTCreateNode(Number);
                 (yyval.ASTnode) ->value = 1;
					  (yyval.ASTnode) ->mytype = BOOLType;
                 }
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 426 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = ASTCreateNode(Number);
                  (yyval.ASTnode) ->value = 0;
						(yyval.ASTnode) ->mytype = BOOLType;
                 }
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 430 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = ASTCreateNode(Expression);
                      (yyval.ASTnode) ->myOperator = MyNot;
                      (yyval.ASTnode) ->s1 = (yyvsp[0].ASTnode);
                      (yyval.ASTnode) ->mytype = (yyvsp[0].ASTnode) ->mytype;
                      (yyval.ASTnode) ->name = createTemp();
                      (yyval.ASTnode) ->symbol = Insert((yyval.ASTnode) ->name, BOOLType, 0, level, 1, offset, 0);
                      offset++;
                     }
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 440 "lab9.y" /* yacc.c:1646  */
    {struct SymbTab *p;
								if((p = Search((yyvsp[-3].string), level, 1)) != NULL){
									if(p ->IsAFunc != 1){
										yyerror((yyvsp[-3].string));
										yyerror("Error: Call is not a function");
										exit(1);
									}
									if(compareFormula(p ->fparms, (yyvsp[-1].ASTnode)) != 1){
										yyerror((yyvsp[-3].string));
										yyerror("Error: Param lenght/type mismatch");
										exit(1);
									}
									(yyval.ASTnode) = ASTCreateNode(Call);
                                    (yyval.ASTnode) ->name = (yyvsp[-3].string);
                                    (yyval.ASTnode) ->s1 = (yyvsp[-1].ASTnode);
									(yyval.ASTnode) ->symbol = p;
									(yyval.ASTnode) ->mytype = p ->Type;
									}else{
										yyerror((yyvsp[-3].string));
										yyerror("Error: Reference has not yet been defined");
										exit(1);
									}
									
									
									
									
                         }
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 469 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = NULL;}
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 470 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode);}
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 472 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = ASTCreateNode(Expression);
						(yyval.ASTnode) = (yyvsp[0].ASTnode);
                 	(yyval.ASTnode) ->mytype = (yyvsp[0].ASTnode) ->mytype;
						
					}
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 477 "lab9.y" /* yacc.c:1646  */
    {(yyval.ASTnode) = ASTCreateNode(Expression);
                         		(yyval.ASTnode) ->s1 = (yyvsp[-2].ASTnode);
                        		(yyval.ASTnode) ->next = (yyvsp[0].ASTnode);
                    			 	(yyval.ASTnode) ->mytype = (yyvsp[-2].ASTnode) ->mytype; 
									}
#line 2145 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2149 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 483 "lab9.y" /* yacc.c:1906  */
  /* end of rules, start of program */

//arguments are being parsed and passed by the compiler
int main(int argc, char*argv[]){
   //set the initial file pointer to null
	fp = NULL;
	char myfile[100];
	yyparse();
	
	//loop to find the argument
	for(int i = 0; i < argc; i++){
      if(strcmp(argv[i], "-d") == 0){
        mydebug = 1;
        printf("Debugging is now turned ON");
      }
	   printf("arg at %d is %s \n", i, argv[i]);
	   if(strcmp(argv[i], "-o") == 0){
	      printf("Got it, file name is %s \n", argv[i+1]);

	      //create a file with the name given
	      strcpy(myfile, argv[i+1]);

	      //attach the asm extention to the created file
	      strcat(myfile, ".asm");
	      printf("The name of the file is %s:\n", myfile);

	      //open the file in order to write to it
	      fp = fopen(myfile, "w");

	      //error check the new file
	      if(fp == NULL){
	         printf("The file is NOT writeable.");
	      }else {
            //writing into the file
	         fprintf(fp, "%%include \"io64.inc\" \n");
	         emitGlobal(myprogram);
	         fprintf(fp, "section .data\n\n");
	         emitString(myprogram);
            fprintf(fp, "section .text\n\n");
            fprintf(fp, "\t global main\n"); 
             emitAST(myprogram);
         //close the file when done writing to it   
         fclose(fp);
	         }//end of else
	}//end of if
   }//end of for loop
}//end of main method
