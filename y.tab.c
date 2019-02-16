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
#line 1 "ast.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdlib.h>
	#include<string.h>
	FILE *fp;
	int reg = 0;
	int label = 0;
	int flabel = 1;
	int currFType = -1;
	int whilelabel = -1;
	int bindingAddress = 4096;
	int Lbinding = 1;
	struct Gsymbol *symTable = NULL;
	struct Lsymbol *Lsym = NULL;
	extern FILE *yyin;
	
	#include "ast.h"
	#include "ast.c"

	int yylex(void);


#line 89 "y.tab.c" /* yacc.c:339  */

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
    PLUS = 259,
    MINUS = 260,
    MUL = 261,
    DIV = 262,
    START = 263,
    END = 264,
    WRITE = 265,
    READ = 266,
    ID = 267,
    ASSIGN = 268,
    IF = 269,
    THEN = 270,
    ELSE = 271,
    ENDIF = 272,
    WHILE = 273,
    DO = 274,
    ENDWHILE = 275,
    BREAK = 276,
    CONT = 277,
    LT = 278,
    LE = 279,
    GT = 280,
    GE = 281,
    EQ = 282,
    NE = 283,
    REPEAT = 284,
    UNTIL = 285,
    MOD = 286,
    DECL = 287,
    ENDDECL = 288,
    INT = 289,
    STR = 290,
    STRING = 291,
    MAIN = 292,
    RETURN = 293,
    AND = 294,
    OR = 295
  };
#endif
/* Tokens.  */
#define NUM 258
#define PLUS 259
#define MINUS 260
#define MUL 261
#define DIV 262
#define START 263
#define END 264
#define WRITE 265
#define READ 266
#define ID 267
#define ASSIGN 268
#define IF 269
#define THEN 270
#define ELSE 271
#define ENDIF 272
#define WHILE 273
#define DO 274
#define ENDWHILE 275
#define BREAK 276
#define CONT 277
#define LT 278
#define LE 279
#define GT 280
#define GE 281
#define EQ 282
#define NE 283
#define REPEAT 284
#define UNTIL 285
#define MOD 286
#define DECL 287
#define ENDDECL 288
#define INT 289
#define STR 290
#define STRING 291
#define MAIN 292
#define RETURN 293
#define AND 294
#define OR 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 25 "ast.y" /* yacc.c:355  */

	struct tnode *yys;	
	int integer;
	struct varList *varNameList;
	char *string;
	struct argumentList *argList;

#line 217 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 234 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   546

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  193

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      45,    46,     2,     2,    42,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    48,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    49,    49,    56,    61,    68,    69,    72,    73,    76,
      86,    87,    90,    91,    92,    93,    97,    98,   101,   110,
     112,   113,   116,   119,   120,   124,   125,   128,   129,   132,
     143,   144,   147,   155,   157,   158,   161,   162,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   178,
     180,   182,   184,   185,   186,   189,   191,   192,   193,   196,
     198,   200,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   226,   227
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "PLUS", "MINUS", "MUL", "DIV",
  "START", "END", "WRITE", "READ", "ID", "ASSIGN", "IF", "THEN", "ELSE",
  "ENDIF", "WHILE", "DO", "ENDWHILE", "BREAK", "CONT", "LT", "LE", "GT",
  "GE", "EQ", "NE", "REPEAT", "UNTIL", "MOD", "DECL", "ENDDECL", "INT",
  "STR", "STRING", "MAIN", "RETURN", "AND", "OR", "';'", "','", "'['",
  "']'", "'('", "')'", "'{'", "'}'", "$accept", "Program", "GDeclBlock",
  "GdeclList", "GDecl", "GidList", "Gid", "FDefBlock", "Fdef", "fname",
  "ParamList", "Param", "Type", "LdeclBlock", "LDecList", "LDecl",
  "IdList", "MainBlock", "mains", "Body", "slist", "stmt", "wedo", "iets",
  "ietse", "instmt", "outstmt", "asgstmt", "reun", "dowe", "ret", "expr",
  "Arglist", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,    59,    44,    91,    93,    40,    41,   123,   125
};
# endif

#define YYPACT_NINF -87

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-87)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -31,   100,   -26,    27,   102,   -87,    20,   -87,   -87,   -87,
     139,   -87,    43,    26,   -87,   -26,   102,   -87,   110,    48,
     -87,    31,   -87,   -87,   -25,   121,   -87,   -87,   -87,   -87,
      19,   -87,    61,    41,    59,    96,    80,   -87,    43,   110,
      63,   -87,   -87,   177,   108,    64,   -87,    47,   -87,   -87,
      59,   -87,   111,   209,   -87,    58,    79,   -87,   -87,   108,
     -87,   141,   -87,   -87,   -87,   130,   140,     3,   155,   156,
     475,   -87,   -87,   475,    14,   392,   106,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   118,   -87,   192,
      14,   208,    14,    14,    14,    14,   496,   427,   -87,     6,
     -87,    14,   369,   -87,   172,   -87,   -87,   -87,    78,   -14,
     369,   201,   115,   125,   176,   178,    14,    11,   153,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,   -87,   -87,    14,   -87,    15,   223,   220,    14,
      14,   229,   -87,   369,    65,   -87,    57,    57,   -87,   -87,
     243,   243,   243,   243,   243,   243,   -87,   515,   515,   257,
      14,    14,   475,   475,   163,   191,   203,    14,   -87,    82,
     369,   285,   406,   440,   220,   -87,    14,   369,    14,   -87,
     238,   475,   -87,   -87,   313,   341,    14,   462,   -87,   212,
     369,   -87,   -87
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,     0,     6,    23,    24,
       0,     8,     0,     0,     1,    23,     0,    17,     0,     0,
       3,     0,     5,     7,    12,     0,    11,    33,    16,     2,
       0,    21,     0,     0,     0,     0,     0,     9,     0,     0,
       0,    22,    19,     0,     0,     0,    15,     0,    10,    20,
       0,    26,     0,     0,    28,     0,     0,    13,    14,     0,
      31,     0,    25,    27,    35,     0,     0,     0,     0,     0,
       0,    44,    45,     0,     0,     0,     0,    41,    42,    43,
      38,    39,    40,    46,    47,    48,    32,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    69,    68,
      76,     0,    61,    34,     0,    37,    18,    30,     0,     0,
      56,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    36,    55,     0,    52,     0,     0,     0,     0,
       0,     0,    79,    84,     0,    67,    62,    64,    63,    65,
      72,    74,    73,    75,    70,    71,    66,    82,    81,     0,
       0,     0,     0,     0,     0,     0,    77,     0,    80,     0,
      57,     0,     0,     0,    60,    59,     0,    83,     0,    53,
       0,     0,    50,    49,     0,     0,     0,     0,    78,     0,
      58,    51,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -87,   -87,   -87,   -87,   249,   -87,   227,   -87,   250,   -87,
     231,   232,     9,   222,   -87,   217,   -87,     8,   -87,   216,
     -68,   -75,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -86,   -87
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    10,    11,    25,    26,    16,    17,    18,
      30,    31,    32,    44,    53,    54,    61,     5,     6,    56,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,   102,   144
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     104,     1,    96,     2,   108,    97,   110,   111,   112,   113,
      12,    13,    20,    19,    98,   118,    92,    98,    35,    12,
      36,   104,   104,    99,    29,    19,    99,    14,   160,   134,
     141,   143,   135,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,    93,   100,   159,   116,
     100,   117,    52,   164,   165,    24,   101,   142,   161,   101,
      33,    39,    52,   121,   122,    40,    21,    64,    65,    66,
      67,    27,    68,    41,   170,   171,    69,    70,    34,    71,
      72,   177,   119,   120,   121,   122,    42,    73,   129,    39,
     184,    43,   185,    58,   172,   173,    74,   104,   104,    45,
     190,   123,   124,   125,   126,   127,   128,   167,    57,   129,
      50,   168,   104,   187,     8,     9,    55,   130,   131,   119,
     120,   121,   122,    60,   133,   178,    46,    86,   179,   119,
     120,   121,   122,     7,     8,     9,    15,     9,   123,   124,
     125,   126,   127,   128,     8,     9,   129,   105,   123,   124,
     125,   126,   127,   128,   130,   131,   129,   119,   120,   121,
     122,   137,    37,    38,   130,   131,   106,   119,   120,   121,
     122,   138,    22,     8,     9,    90,   123,   124,   125,   126,
     127,   128,    88,    89,   129,    91,   123,   124,   125,   126,
     127,   128,   130,   131,   129,   119,   120,   121,   122,   145,
      94,    95,   130,   131,   107,   119,   120,   121,   122,   174,
      51,     8,     9,   132,   123,   124,   125,   126,   127,   128,
     109,   139,   129,   140,   123,   124,   125,   126,   127,   128,
     130,   131,   129,   119,   120,   121,   122,   175,   162,   163,
     130,   131,    62,     8,     9,   136,   176,   119,   120,   121,
     122,   186,   123,   124,   125,   126,   127,   128,   192,    23,
     129,   119,   120,   121,   122,    48,    28,    47,   130,   131,
      63,    49,    59,   166,   129,    87,     0,     0,     0,     0,
     123,   124,   125,   126,   127,   128,     0,     0,   129,   119,
     120,   121,   122,     0,     0,     0,   130,   131,     0,     0,
       0,   169,     0,     0,     0,     0,     0,     0,   123,   124,
     125,   126,   127,   128,     0,     0,   129,   119,   120,   121,
     122,     0,     0,     0,   130,   131,     0,     0,     0,   180,
       0,     0,     0,     0,     0,     0,   123,   124,   125,   126,
     127,   128,     0,     0,   129,   119,   120,   121,   122,     0,
       0,     0,   130,   131,     0,     0,     0,   188,     0,     0,
       0,     0,     0,     0,   123,   124,   125,   126,   127,   128,
       0,     0,   129,   119,   120,   121,   122,     0,     0,     0,
     130,   131,     0,     0,     0,   189,     0,     0,     0,     0,
       0,     0,   123,   124,   125,   126,   127,   128,     0,     0,
     129,   103,    65,    66,    67,     0,    68,     0,   130,   131,
      69,    70,     0,    71,    72,     0,    65,    66,    67,     0,
      68,    73,   181,   182,    69,    70,     0,    71,    72,     0,
      74,     0,     0,     0,     0,    73,     0,    65,    66,    67,
       0,    68,     0,     0,    74,    69,    70,     0,    71,    72,
      65,    66,    67,     0,    68,     0,    73,   115,    69,    70,
     183,    71,    72,     0,     0,    74,     0,     0,     0,    73,
       0,     0,    65,    66,    67,     0,    68,     0,    74,   191,
      69,    70,     0,    71,    72,    65,    66,    67,     0,    68,
       0,    73,     0,    69,    70,     0,    71,    72,     0,     0,
      74,     0,     0,     0,    73,     0,    65,    66,    67,     0,
      68,     0,     0,    74,   114,    70,     0,    71,    72,   119,
     120,   121,   122,     0,     0,    73,     0,     0,     0,     0,
       0,     0,     0,     0,    74,     0,     0,     0,   123,   124,
     125,   126,   127,   128,     0,     0,   129
};

static const yytype_int16 yycheck[] =
{
      75,    32,    70,    34,    90,    73,    92,    93,    94,    95,
       1,    37,     4,     4,     3,   101,    13,     3,    43,    10,
      45,    96,    97,    12,    16,    16,    12,     0,    13,    43,
     116,   117,    46,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    43,    36,   134,    43,
      36,    45,    43,   139,   140,    12,    45,    46,    43,    45,
      12,    42,    53,     6,     7,    46,    46,     9,    10,    11,
      12,    45,    14,    12,   160,   161,    18,    19,    47,    21,
      22,   167,     4,     5,     6,     7,    45,    29,    31,    42,
     176,    32,   178,    46,   162,   163,    38,   172,   173,     3,
     186,    23,    24,    25,    26,    27,    28,    42,    44,    31,
      47,    46,   187,   181,    34,    35,     8,    39,    40,     4,
       5,     6,     7,    12,    46,    43,    46,    48,    46,     4,
       5,     6,     7,    33,    34,    35,    34,    35,    23,    24,
      25,    26,    27,    28,    34,    35,    31,    41,    23,    24,
      25,    26,    27,    28,    39,    40,    31,     4,     5,     6,
       7,    46,    41,    42,    39,    40,    48,     4,     5,     6,
       7,    46,    33,    34,    35,    45,    23,    24,    25,    26,
      27,    28,    41,    42,    31,    45,    23,    24,    25,    26,
      27,    28,    39,    40,    31,     4,     5,     6,     7,    46,
      45,    45,    39,    40,    12,     4,     5,     6,     7,    46,
      33,    34,    35,    41,    23,    24,    25,    26,    27,    28,
      12,    45,    31,    45,    23,    24,    25,    26,    27,    28,
      39,    40,    31,     4,     5,     6,     7,    46,    15,    19,
      39,    40,    33,    34,    35,    44,    43,     4,     5,     6,
       7,    13,    23,    24,    25,    26,    27,    28,    46,    10,
      31,     4,     5,     6,     7,    38,    16,    36,    39,    40,
      53,    39,    50,    44,    31,    59,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    27,    28,    -1,    -1,    31,     4,
       5,     6,     7,    -1,    -1,    -1,    39,    40,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    -1,    -1,    31,     4,     5,     6,
       7,    -1,    -1,    -1,    39,    40,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,
      27,    28,    -1,    -1,    31,     4,     5,     6,     7,    -1,
      -1,    -1,    39,    40,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,    28,
      -1,    -1,    31,     4,     5,     6,     7,    -1,    -1,    -1,
      39,    40,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    24,    25,    26,    27,    28,    -1,    -1,
      31,     9,    10,    11,    12,    -1,    14,    -1,    39,    40,
      18,    19,    -1,    21,    22,    -1,    10,    11,    12,    -1,
      14,    29,    16,    17,    18,    19,    -1,    21,    22,    -1,
      38,    -1,    -1,    -1,    -1,    29,    -1,    10,    11,    12,
      -1,    14,    -1,    -1,    38,    18,    19,    -1,    21,    22,
      10,    11,    12,    -1,    14,    -1,    29,    30,    18,    19,
      20,    21,    22,    -1,    -1,    38,    -1,    -1,    -1,    29,
      -1,    -1,    10,    11,    12,    -1,    14,    -1,    38,    17,
      18,    19,    -1,    21,    22,    10,    11,    12,    -1,    14,
      -1,    29,    -1,    18,    19,    -1,    21,    22,    -1,    -1,
      38,    -1,    -1,    -1,    29,    -1,    10,    11,    12,    -1,
      14,    -1,    -1,    38,    18,    19,    -1,    21,    22,     4,
       5,     6,     7,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    -1,    -1,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    34,    50,    51,    66,    67,    33,    34,    35,
      52,    53,    61,    37,     0,    34,    56,    57,    58,    61,
      66,    46,    33,    53,    12,    54,    55,    45,    57,    66,
      59,    60,    61,    12,    47,    43,    45,    41,    42,    42,
      46,    12,    45,    32,    62,     3,    46,    59,    55,    60,
      47,    33,    61,    63,    64,     8,    68,    44,    46,    62,
      12,    65,    33,    64,     9,    10,    11,    12,    14,    18,
      19,    21,    22,    29,    38,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    48,    68,    41,    42,
      45,    45,    13,    43,    45,    45,    69,    69,     3,    12,
      36,    45,    80,     9,    70,    41,    48,    12,    80,    12,
      80,    80,    80,    80,    18,    30,    43,    45,    80,     4,
       5,     6,     7,    23,    24,    25,    26,    27,    28,    31,
      39,    40,    41,    46,    43,    46,    44,    46,    46,    45,
      45,    80,    46,    80,    81,    46,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      13,    43,    15,    19,    80,    80,    44,    42,    46,    44,
      80,    80,    69,    69,    46,    46,    43,    80,    43,    46,
      44,    16,    17,    20,    80,    80,    13,    69,    44,    44,
      80,    17,    46
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    50,    51,    51,    52,    52,    53,
      54,    54,    55,    55,    55,    55,    56,    56,    57,    58,
      59,    59,    60,    61,    61,    62,    62,    63,    63,    64,
      65,    65,    66,    67,    68,    68,    69,    69,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    71,
      72,    73,    74,    74,    74,    75,    76,    76,    76,    77,
      78,    79,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    81,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       3,     1,     1,     4,     4,     3,     2,     1,     7,     3,
       3,     1,     2,     1,     1,     3,     2,     2,     1,     3,
       3,     1,     6,     3,     3,     2,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     7,
       7,     9,     4,     7,    10,     4,     3,     6,     9,     6,
       6,     2,     3,     3,     3,     3,     3,     3,     1,     1,
       3,     3,     3,     3,     3,     3,     1,     4,     7,     3,
       4,     3,     3,     3,     1
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
#line 49 "ast.y" /* yacc.c:1646  */
    {	(yyval.yys) = makeConnectorNode((yyvsp[-1].yys), (yyvsp[0].yys));
											fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, %d\n", getBinding(0));printf("codeGen starts\n");
											fprintf(fp, "CALL F0\n");
											fprintf(fp, "MOV R2, 10\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nINT 10\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1\n");
											codeGen((yyval.yys));
											return 0;
										 }
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 56 "ast.y" /* yacc.c:1646  */
    {fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, %d\n", getBinding(0));printf("codeGen starts\n");
							fprintf(fp, "CALL F0\n");
							fprintf(fp, "MOV R2, 10\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nINT 10\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1\n");
							codeGen((yyvsp[0].yys));
							return 0;}
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 61 "ast.y" /* yacc.c:1646  */
    {fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, %d\n", getBinding(0));printf("codeGen starts\n");
							fprintf(fp, "CALL F0\n");
							fprintf(fp, "MOV R2, 10\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nINT 10\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1\n");
							codeGen((yyvsp[0].yys));
							return 0;}
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 68 "ast.y" /* yacc.c:1646  */
    {printSymTable();}
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 69 "ast.y" /* yacc.c:1646  */
    {}
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 72 "ast.y" /* yacc.c:1646  */
    {}
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 73 "ast.y" /* yacc.c:1646  */
    {}
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 76 "ast.y" /* yacc.c:1646  */
    {
								while((yyvsp[-1].varNameList) != NULL)
								{
									install((yyvsp[-1].varNameList)->name, (yyvsp[-2].integer), (yyvsp[-1].varNameList)->size, (yyvsp[-1].varNameList)->rowsize, (yyvsp[-1].varNameList)->argList);
									(yyvsp[-1].varNameList) = (yyvsp[-1].varNameList)->next;
									Lsym = NULL;
								}
							}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 86 "ast.y" /* yacc.c:1646  */
    {(yyval.varNameList) = addVarList((yyvsp[-2].varNameList), (yyvsp[0].varNameList));}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 87 "ast.y" /* yacc.c:1646  */
    {(yyval.varNameList) = (yyvsp[0].varNameList);}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 90 "ast.y" /* yacc.c:1646  */
    {(yyval.varNameList) = makeVarList((yyvsp[0].string), 1, 1);}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 91 "ast.y" /* yacc.c:1646  */
    {(yyval.varNameList) = makeVarList((yyvsp[-3].string), (yyvsp[-1].integer), 1);}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 92 "ast.y" /* yacc.c:1646  */
    {(yyval.varNameList) = addFunc((yyvsp[-3].string), (yyvsp[-1].argList));}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 93 "ast.y" /* yacc.c:1646  */
    {(yyval.varNameList) = addFunc((yyvsp[-2].string), NULL);}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 97 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeConnectorNode((yyvsp[-1].yys), (yyvsp[0].yys));}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 98 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 101 "ast.y" /* yacc.c:1646  */
    {
															funcLookUp((yyvsp[-6].argList)->type, (yyvsp[-6].argList)->name, (yyvsp[-5].argList));
															(yyval.yys) = makeFuncDefNode((yyvsp[-6].argList)->type, (yyvsp[-6].argList)->name, (yyvsp[-1].yys));
															currFType = -1;
															Lsym = NULL;
															Lbinding = 1;
														}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 110 "ast.y" /* yacc.c:1646  */
    {(yyval.argList) = makeArgList((yyvsp[-2].integer), (yyvsp[-1].string)); currFType = (yyvsp[-2].integer); Lsym = (lookUp((yyvsp[-1].string)))->Lsym;}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 112 "ast.y" /* yacc.c:1646  */
    {(yyval.argList) = addArgList((yyvsp[-2].argList), (yyvsp[0].argList));}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 113 "ast.y" /* yacc.c:1646  */
    {(yyval.argList) = (yyvsp[0].argList);}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 116 "ast.y" /* yacc.c:1646  */
    {(yyval.argList) = makeArgList((yyvsp[-1].integer), (yyvsp[0].string));}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 119 "ast.y" /* yacc.c:1646  */
    {(yyval.integer) = inttype;}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 120 "ast.y" /* yacc.c:1646  */
    {(yyval.integer) = strtype;}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 124 "ast.y" /* yacc.c:1646  */
    {}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 125 "ast.y" /* yacc.c:1646  */
    {}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 128 "ast.y" /* yacc.c:1646  */
    {}
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 129 "ast.y" /* yacc.c:1646  */
    {}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 132 "ast.y" /* yacc.c:1646  */
    {
							while((yyvsp[-1].varNameList) != NULL)
								{
									Linstall((yyvsp[-1].varNameList)->name, (yyvsp[-2].integer), Lbinding);
									Lbinding++;
									(yyvsp[-1].varNameList) = (yyvsp[-1].varNameList)->next;
								}
							printLocalSym();
						}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 143 "ast.y" /* yacc.c:1646  */
    {(yyval.varNameList) = addLVarList((yyvsp[-2].varNameList), (yyvsp[0].string));}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 144 "ast.y" /* yacc.c:1646  */
    {(yyval.varNameList) = makeLVarList((yyvsp[0].string));}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 147 "ast.y" /* yacc.c:1646  */
    {
												(yyval.yys) = makeFuncDefNode((yyvsp[-5].argList)->type, (yyvsp[-5].argList)->name, (yyvsp[-1].yys));
												currFType = -1;
												Lsym = NULL;
												Lbinding = 1;
											  }
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 155 "ast.y" /* yacc.c:1646  */
    {install("main", inttype, 0, 0, NULL); (yyval.argList) = makeArgList(inttype, "main"); currFType = inttype; Lsym = NULL;}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 157 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[-1].yys);}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 158 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = NULL;}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 161 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeConnectorNode((yyvsp[-2].yys), (yyvsp[-1].yys));}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 162 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[-1].yys);}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 165 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 166 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 167 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 168 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 169 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 170 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 171 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeJmpNode(BRKST);}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 172 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeJmpNode(CONTST);}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 173 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 174 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 175 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 178 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeWhileNode((yyvsp[-4].yys), (yyvsp[-1].yys));}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 180 "ast.y" /* yacc.c:1646  */
    { (yyval.yys) = makeIfNode((yyvsp[-4].yys), (yyvsp[-1].yys));}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 182 "ast.y" /* yacc.c:1646  */
    { (yyval.yys) = makeIfElseNode((yyvsp[-6].yys), (yyvsp[-3].yys), (yyvsp[-1].yys));}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 184 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeReadNode(makeVarNode((yyvsp[-1].string)));}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 185 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeReadNode(makeArrayNode((yyvsp[-4].string), (yyvsp[-2].yys)));}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 186 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeReadNode(make2DArrayNode((yyvsp[-7].string), (yyvsp[-5].yys), (yyvsp[-2].yys)));}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 189 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeWriteNode((yyvsp[-1].yys));}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 191 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeOperatorNode('=', makeVarNode((yyvsp[-2].string)), (yyvsp[0].yys));}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 192 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeOperatorNode('=',makeArrayNode((yyvsp[-5].string),(yyvsp[-3].yys)),(yyvsp[0].yys));}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 193 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeOperatorNode('=',make2DArrayNode((yyvsp[-8].string),(yyvsp[-6].yys), (yyvsp[-3].yys)),(yyvsp[0].yys));}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 196 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeRepeatNode((yyvsp[-4].yys), (yyvsp[-1].yys));}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 198 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeDoWhileNode((yyvsp[-4].yys), (yyvsp[-1].yys));}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 200 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeReturnNode((yyvsp[0].yys));}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 203 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeOperatorNode('+',(yyvsp[-2].yys), (yyvsp[0].yys));}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 204 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeOperatorNode('*',(yyvsp[-2].yys), (yyvsp[0].yys));}
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 205 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeOperatorNode('-',(yyvsp[-2].yys), (yyvsp[0].yys));}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 206 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeOperatorNode('/',(yyvsp[-2].yys), (yyvsp[0].yys));}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 207 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeOperatorNode('%', (yyvsp[-2].yys), (yyvsp[0].yys));}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 208 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[-1].yys);}
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 209 "ast.y" /* yacc.c:1646  */
    { (yyval.yys) = makeVarNode((yyvsp[0].string));}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 210 "ast.y" /* yacc.c:1646  */
    { (yyval.yys) = makeConstantNode((yyvsp[0].integer));}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 211 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeCondNode("==", (yyvsp[-2].yys), (yyvsp[0].yys));}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 212 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeCondNode("!=", (yyvsp[-2].yys), (yyvsp[0].yys));}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 213 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeCondNode("<", (yyvsp[-2].yys), (yyvsp[0].yys));}
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 214 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeCondNode(">", (yyvsp[-2].yys), (yyvsp[0].yys));}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 215 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeCondNode("<=", (yyvsp[-2].yys), (yyvsp[0].yys));}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 216 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeCondNode(">=", (yyvsp[-2].yys), (yyvsp[0].yys));}
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 217 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeStringNode((yyvsp[0].string));}
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 218 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeArrayNode((yyvsp[-3].string), (yyvsp[-1].yys));}
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 219 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = make2DArrayNode((yyvsp[-6].string), (yyvsp[-4].yys), (yyvsp[-1].yys));}
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 220 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeFuncCallNode((yyvsp[-2].string), NULL);}
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 221 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeFuncCallNode((yyvsp[-3].string), (yyvsp[-1].yys));}
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 222 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeOrNode((yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 223 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeAndNode((yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 226 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeConnectorNode((yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 227 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeConnectorNode(NULL, (yyvsp[0].yys));}
#line 2043 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2047 "y.tab.c" /* yacc.c:1646  */
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
#line 230 "ast.y" /* yacc.c:1906  */


int yyerror(char const *s)
{
    printf("%s\n",s);
}


int main(int argc , char *argv[]) {
	if(argc > 1)
	{
		FILE *in = fopen(argv[1],"r");
		yyin = in;
	}
	fp = fopen("a.xsm","w");
	yyparse();
	return 0;
}
