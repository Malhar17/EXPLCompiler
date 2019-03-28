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
	struct TypeTable *currFType = NULL;
	int whilelabel = -1;
	int bindingAddress = 4096;
	int Lbinding = 1;
	struct Gsymbol *symTable = NULL;
	struct Lsymbol *Lsym = NULL;
	struct TypeTable *Ttable = NULL;
	int Tsize = 0;
	extern FILE *yyin;
	
	struct TypeTable *inttype;
	struct TypeTable *strtype;
	struct TypeTable *booltype;
	struct TypeTable *nulltype;
	struct TypeTable *voidtype;


	#include "ast.h"
	#include "SymbolTable.c"
	#include "ast.c"
	#include "CodeGeneration.c"

	int yylex(void);


#line 100 "y.tab.c" /* yacc.c:339  */

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
    OR = 295,
    TYPE = 296,
    ENDTYPE = 297,
    ALLOC = 298,
    INITIALIZE = 299,
    FREE = 300,
    NIL = 301
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
#define TYPE 296
#define ENDTYPE 297
#define ALLOC 298
#define INITIALIZE 299
#define FREE 300
#define NIL 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 36 "ast.y" /* yacc.c:355  */

	struct tnode *yys;	
	int integer;
	struct varList *varNameList;
	char *string;
	struct argumentList *argList;
	struct TypeTable *typeTable;
	struct FieldList *fieldsList;

#line 242 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 259 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   677

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  232

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

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
      53,    54,     2,     2,    50,     2,    55,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    49,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    47,     2,     2,     2,     2,
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
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    64,    64,    72,    79,    86,    94,   101,   110,   113,
     114,   117,   120,   123,   124,   127,   130,   131,   132,   135,
     138,   139,   142,   152,   153,   156,   157,   158,   159,   163,
     164,   167,   176,   178,   179,   182,   186,   187,   190,   191,
     194,   204,   205,   208,   216,   218,   219,   222,   223,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     239,   241,   243,   245,   246,   247,   250,   252,   253,   254,
     255,   258,   260,   262,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     293,   294,   297,   298
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
  "STR", "STRING", "MAIN", "RETURN", "AND", "OR", "TYPE", "ENDTYPE",
  "ALLOC", "INITIALIZE", "FREE", "NIL", "'}'", "'{'", "';'", "','", "'['",
  "']'", "'('", "')'", "'.'", "$accept", "Program", "TypeDefBlock",
  "TypeDefList", "TypeDef", "tname", "FieldDeclList", "FieldDecl",
  "TypeName", "GDeclBlock", "GdeclList", "GDecl", "GidList", "Gid",
  "FDefBlock", "Fdef", "fname", "ParamList", "Param", "LdeclBlock",
  "LDecList", "LDecl", "IdList", "MainBlock", "mains", "Body", "slist",
  "stmt", "wedo", "iets", "ietse", "instmt", "outstmt", "asgstmt", "reun",
  "dowe", "ret", "expr", "Arglist", "field", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   125,   123,    59,
      44,    91,    93,    40,    41,    46
};
# endif

#define YYPACT_NINF -88

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-88)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     167,    -1,   -28,     5,    22,    46,    97,   -88,    -7,   -88,
     -88,   -88,    30,   115,   -88,    11,    47,   -10,   -88,    -1,
     -88,    97,   -88,   -28,    38,    97,   -88,    -1,   -88,    59,
      28,    36,   -88,   -88,   -88,   -88,   -88,   -88,   -88,    71,
     -88,   101,    97,   -88,    57,   -88,   -88,   105,    66,    79,
      89,   130,     2,   -88,    30,   -88,   -88,    90,   -88,   -88,
     -88,    96,    -1,    -1,   135,    94,   -88,   106,   -88,   -88,
      89,   -88,   147,   157,   -88,   502,   114,   -88,   -88,   135,
     -88,    40,   -88,   -88,   -88,   113,   117,     6,   124,   125,
     607,   -88,   -88,   607,     9,   516,   118,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,   -88,     3,   -88,   133,   -88,
     181,     9,   182,     9,     9,   183,     9,     9,   620,   552,
     -88,   156,   -88,   143,   164,   165,   -88,     9,   479,   145,
     -88,   161,   -88,     9,   207,   -88,   -88,   148,   -41,   479,
     311,   -88,   158,   199,   168,   175,     9,    48,   166,   177,
       9,   209,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,     9,   -88,   479,   -88,   -88,     9,
     -88,   -12,   214,   222,     9,     9,   341,   -88,   451,   188,
     -88,   -88,   250,   -88,    -3,    -3,   -88,   -88,    93,    93,
      93,    93,    93,    93,   -88,   646,   646,   371,     9,     9,
     607,   607,   260,   301,   192,     9,   -88,   -88,   -16,   479,
     381,   539,   573,   222,   -88,     9,   -88,     9,   -88,   231,
     607,   -88,   -88,   411,   421,     9,   586,   -88,   191,   479,
     -88,   -88
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     7,     0,    18,
      16,    17,     0,     0,    21,     0,     0,     0,    10,     0,
       1,     0,     4,    16,     0,     0,    30,     0,     6,     0,
      25,     0,    24,    19,    20,    44,    12,     8,     9,     0,
      14,     0,     0,     3,     0,    29,     5,     0,     0,    34,
      37,     0,     0,    22,     0,    11,    13,     0,     2,    32,
      35,     0,     0,     0,     0,     0,    28,     0,    23,    15,
      37,    33,     0,     0,    39,     0,     0,    26,    27,     0,
      42,     0,    36,    38,    46,     0,     0,     0,     0,     0,
       0,    55,    56,     0,     0,     0,     0,    52,    53,    54,
      49,    50,    51,    57,    58,    59,     0,    43,     0,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      81,    80,    88,     0,     0,     0,    99,     0,    73,    95,
      45,     0,    48,     0,     0,    31,    41,     0,     0,    67,
       0,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    47,    70,   102,    66,     0,
      63,     0,     0,     0,     0,     0,     0,    91,   101,     0,
      96,    98,     0,    79,    74,    76,    75,    77,    84,    86,
      85,    87,    82,    83,    78,    94,    93,     0,     0,     0,
       0,     0,     0,     0,    89,     0,    92,    97,     0,    68,
       0,     0,     0,    72,    71,     0,   100,     0,    64,     0,
       0,    61,    60,     0,     0,     0,     0,    90,     0,    69,
      62,    65
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -88,   -88,   -88,   -88,   229,   -88,   -88,   208,    95,   245,
     -88,   238,   -88,   198,   237,   -19,   -88,   -21,   -88,   189,
     -88,   187,   -88,    98,   -88,   190,   -85,   -70,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,   -88,   -88,   -87,    56,   -75
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,    17,    18,    19,    39,    40,    24,     6,
      13,    14,    31,    32,    25,    26,    27,    48,    49,    64,
      73,    74,    81,     7,     8,    76,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   178,   179,   129
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     106,   198,    16,   154,   155,   118,    45,   128,   119,    15,
     169,     9,   120,   170,     9,   106,   133,    16,   106,   113,
     106,   121,    20,    45,   137,   131,   139,   140,   162,   142,
     143,    67,    37,    10,    11,   217,    10,    11,   218,   199,
     151,    71,    30,   106,   106,   122,   166,    29,   131,   131,
      44,   120,   123,   124,   125,   126,    66,   114,   134,   176,
     121,   115,   127,   182,    35,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     1,    51,
       2,    52,   197,     9,   122,    53,    54,   202,   203,   109,
     110,   123,   124,   125,   126,    36,    12,   152,   153,   154,
     155,   127,   177,    22,    28,    10,    11,    50,    12,     9,
      59,   209,   210,    57,    41,   211,   212,    60,    55,    43,
      61,    63,    47,    46,   162,   106,   106,     9,   223,    62,
     224,    23,    11,    65,    41,   226,   106,   106,   229,    69,
      58,   131,   131,    75,    70,   106,    77,    47,    33,    10,
      11,   106,   152,   153,   154,   155,   131,    47,    72,    80,
      78,   107,   152,   153,   154,   155,   111,   132,    72,     9,
     112,   156,   157,   158,   159,   160,   161,   116,   117,   162,
     135,   156,   157,   158,   159,   160,   161,   163,   164,   162,
      82,    10,    11,   136,   138,   141,   148,   163,   164,     1,
     134,     2,   168,   152,   153,   154,   155,   146,     3,   147,
     165,   115,   172,   152,   153,   154,   155,   149,   150,   167,
     180,   174,   156,   157,   158,   159,   160,   161,   175,   200,
     162,   181,   156,   157,   158,   159,   160,   161,   163,   164,
     162,   201,   206,   215,   225,   231,    38,    56,   163,   164,
      21,    34,    68,   173,   152,   153,   154,   155,    42,    79,
      83,   216,     0,   183,   152,   153,   154,   155,     0,   108,
       0,     0,     0,   156,   157,   158,   159,   160,   161,     0,
       0,   162,     0,   156,   157,   158,   159,   160,   161,   163,
     164,   162,     0,     0,     0,     0,     0,     0,     0,   163,
     164,     0,     0,     0,   207,   152,   153,   154,   155,     0,
       0,     0,     0,     0,   213,   152,   153,   154,   155,     0,
       0,     0,     0,     0,   156,   157,   158,   159,   160,   161,
       0,     0,   162,     0,   156,   157,   158,   159,   160,   161,
     163,   164,   162,     0,     0,   152,   153,   154,   155,     0,
     163,   164,     0,     0,     0,   214,     0,     0,     0,     0,
       0,     0,     0,   171,   156,   157,   158,   159,   160,   161,
       0,     0,   162,     0,     0,   152,   153,   154,   155,     0,
     163,   164,     0,     0,     0,   152,   153,   154,   155,     0,
       0,     0,     0,   204,   156,   157,   158,   159,   160,   161,
       0,     0,   162,     0,   156,   157,   158,   159,   160,   161,
     163,   164,   162,     0,     0,   152,   153,   154,   155,     0,
     163,   164,     0,   208,     0,   152,   153,   154,   155,     0,
       0,     0,     0,   219,   156,   157,   158,   159,   160,   161,
       0,     0,   162,     0,   156,   157,   158,   159,   160,   161,
     163,   164,   162,     0,     0,   152,   153,   154,   155,     0,
     163,   164,     0,   227,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   228,   156,   157,   158,   159,   160,   161,
       0,     0,   162,   152,   153,   154,   155,     0,     0,     0,
     163,   164,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   205,   156,   157,   158,   159,   160,   161,     0,     0,
     162,    84,    85,    86,    87,     0,    88,     0,   163,   164,
      89,    90,     0,    91,    92,   130,    85,    86,    87,     0,
      88,    93,     0,     0,    89,    90,     0,    91,    92,     0,
      94,     0,     0,     0,     0,    93,     0,     0,     0,    85,
      86,    87,     0,    88,    94,   220,   221,    89,    90,     0,
      91,    92,    85,    86,    87,     0,    88,     0,    93,     0,
      89,    90,     0,    91,    92,     0,     0,    94,     0,     0,
       0,    93,   145,    85,    86,    87,     0,    88,     0,     0,
      94,    89,    90,   222,    91,    92,    85,    86,    87,     0,
      88,     0,    93,   230,    89,    90,     0,    91,    92,     0,
       0,    94,     0,     0,     0,    93,     0,    85,    86,    87,
       0,    88,     0,     0,    94,    89,    90,     0,    91,    92,
      85,    86,    87,     0,    88,     0,    93,     0,   144,    90,
       0,    91,    92,     0,     0,    94,     0,     0,     0,    93,
     152,   153,   154,   155,     0,     0,     0,     0,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   156,
     157,   158,   159,   160,   161,     0,     0,   162
};

static const yytype_int16 yycheck[] =
{
      75,    13,    12,     6,     7,    90,    25,    94,    93,    37,
      51,    12,     3,    54,    12,    90,    13,    12,    93,    13,
      95,    12,     0,    42,   111,    95,   113,   114,    31,   116,
     117,    52,    42,    34,    35,    51,    34,    35,    54,    51,
     127,    62,    12,   118,   119,    36,   133,    54,   118,   119,
      12,     3,    43,    44,    45,    46,    54,    51,    55,   146,
      12,    55,    53,   150,    53,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,    32,    51,
      34,    53,   169,    12,    36,    49,    50,   174,   175,    49,
      50,    43,    44,    45,    46,    48,     1,     4,     5,     6,
       7,    53,    54,     5,     6,    34,    35,    48,    13,    12,
      53,   198,   199,    12,    19,   200,   201,    12,    47,    21,
      54,    32,    27,    25,    31,   200,   201,    12,   215,    50,
     217,    34,    35,     3,    39,   220,   211,   212,   225,    49,
      42,   211,   212,     8,    48,   220,    52,    52,    33,    34,
      35,   226,     4,     5,     6,     7,   226,    62,    63,    12,
      54,    47,     4,     5,     6,     7,    53,    49,    73,    12,
      53,    23,    24,    25,    26,    27,    28,    53,    53,    31,
      47,    23,    24,    25,    26,    27,    28,    39,    40,    31,
      33,    34,    35,    12,    12,    12,    53,    39,    40,    32,
      55,    34,    54,     4,     5,     6,     7,    51,    41,    53,
      49,    55,    54,     4,     5,     6,     7,    53,    53,    12,
      54,    53,    23,    24,    25,    26,    27,    28,    53,    15,
      31,    54,    23,    24,    25,    26,    27,    28,    39,    40,
      31,    19,    54,    51,    13,    54,    17,    39,    39,    40,
       5,    13,    54,    54,     4,     5,     6,     7,    21,    70,
      73,   205,    -1,    54,     4,     5,     6,     7,    -1,    79,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    -1,
      -1,    31,    -1,    23,    24,    25,    26,    27,    28,    39,
      40,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,    -1,    -1,    -1,    54,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    54,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,    28,
      -1,    -1,    31,    -1,    23,    24,    25,    26,    27,    28,
      39,    40,    31,    -1,    -1,     4,     5,     6,     7,    -1,
      39,    40,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    23,    24,    25,    26,    27,    28,
      -1,    -1,    31,    -1,    -1,     4,     5,     6,     7,    -1,
      39,    40,    -1,    -1,    -1,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    52,    23,    24,    25,    26,    27,    28,
      -1,    -1,    31,    -1,    23,    24,    25,    26,    27,    28,
      39,    40,    31,    -1,    -1,     4,     5,     6,     7,    -1,
      39,    40,    -1,    52,    -1,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    52,    23,    24,    25,    26,    27,    28,
      -1,    -1,    31,    -1,    23,    24,    25,    26,    27,    28,
      39,    40,    31,    -1,    -1,     4,     5,     6,     7,    -1,
      39,    40,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    23,    24,    25,    26,    27,    28,
      -1,    -1,    31,     4,     5,     6,     7,    -1,    -1,    -1,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    23,    24,    25,    26,    27,    28,    -1,    -1,
      31,     9,    10,    11,    12,    -1,    14,    -1,    39,    40,
      18,    19,    -1,    21,    22,     9,    10,    11,    12,    -1,
      14,    29,    -1,    -1,    18,    19,    -1,    21,    22,    -1,
      38,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    10,
      11,    12,    -1,    14,    38,    16,    17,    18,    19,    -1,
      21,    22,    10,    11,    12,    -1,    14,    -1,    29,    -1,
      18,    19,    -1,    21,    22,    -1,    -1,    38,    -1,    -1,
      -1,    29,    30,    10,    11,    12,    -1,    14,    -1,    -1,
      38,    18,    19,    20,    21,    22,    10,    11,    12,    -1,
      14,    -1,    29,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    38,    -1,    -1,    -1,    29,    -1,    10,    11,    12,
      -1,    14,    -1,    -1,    38,    18,    19,    -1,    21,    22,
      10,    11,    12,    -1,    14,    -1,    29,    -1,    18,    19,
      -1,    21,    22,    -1,    -1,    38,    -1,    -1,    -1,    29,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      24,    25,    26,    27,    28,    -1,    -1,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    34,    41,    57,    58,    65,    79,    80,    12,
      34,    35,    64,    66,    67,    37,    12,    59,    60,    61,
       0,    65,    79,    34,    64,    70,    71,    72,    79,    54,
      12,    68,    69,    33,    67,    53,    48,    42,    60,    62,
      63,    64,    70,    79,    12,    71,    79,    64,    73,    74,
      48,    51,    53,    49,    50,    47,    63,    12,    79,    53,
      12,    54,    50,    32,    75,     3,    54,    73,    69,    49,
      48,    73,    64,    76,    77,     8,    81,    52,    54,    75,
      12,    78,    33,    77,     9,    10,    11,    12,    14,    18,
      19,    21,    22,    29,    38,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    95,    47,    81,    49,
      50,    53,    53,    13,    51,    55,    53,    53,    82,    82,
       3,    12,    36,    43,    44,    45,    46,    53,    93,    95,
       9,    83,    49,    13,    55,    47,    12,    93,    12,    93,
      93,    12,    93,    93,    18,    30,    51,    53,    53,    53,
      53,    93,     4,     5,     6,     7,    23,    24,    25,    26,
      27,    28,    31,    39,    40,    49,    93,    12,    54,    51,
      54,    52,    54,    54,    53,    53,    93,    54,    93,    94,
      54,    54,    93,    54,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    13,    51,
      15,    19,    93,    93,    52,    50,    54,    54,    52,    93,
      93,    82,    82,    54,    54,    51,    94,    51,    54,    52,
      16,    17,    20,    93,    93,    13,    82,    52,    52,    93,
      17,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    57,    57,    57,    57,    57,    58,    59,
      59,    60,    61,    62,    62,    63,    64,    64,    64,    65,
      66,    66,    67,    68,    68,    69,    69,    69,    69,    70,
      70,    71,    72,    73,    73,    74,    75,    75,    76,    76,
      77,    78,    78,    79,    80,    81,    81,    82,    82,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      84,    85,    86,    87,    87,    87,    88,    89,    89,    89,
      89,    90,    91,    92,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      94,    94,    95,    95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     2,     3,     2,     1,     3,     2,
       1,     3,     2,     2,     1,     3,     1,     1,     1,     3,
       2,     1,     3,     3,     1,     1,     4,     4,     3,     2,
       1,     7,     3,     3,     1,     2,     3,     0,     2,     1,
       3,     3,     1,     6,     3,     3,     2,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       7,     7,     9,     4,     7,    10,     4,     3,     6,     9,
       3,     6,     6,     2,     3,     3,     3,     3,     3,     3,
       1,     1,     3,     3,     3,     3,     3,     3,     1,     4,
       7,     3,     4,     3,     3,     1,     3,     4,     3,     1,
       3,     1,     3,     3
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
#line 64 "ast.y" /* yacc.c:1646  */
    {	
											(yyval.yys) = makeConnectorNode((yyvsp[-1].yys), (yyvsp[0].yys));
											fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, %d\n", getBinding(0));printf("codeGen starts\n");
											fprintf(fp, "CALL F0\n");
											fprintf(fp, "MOV R2, 10\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nINT 10\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1\n");
											codeGen((yyval.yys));
											return 0;
										 }
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 72 "ast.y" /* yacc.c:1646  */
    {
											fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, %d\n", getBinding(0));printf("codeGen starts\n");
											fprintf(fp, "CALL F0\n");
											fprintf(fp, "MOV R2, 10\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nINT 10\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1\n");
											codeGen((yyvsp[0].yys));
											return 0;
										 }
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 79 "ast.y" /* yacc.c:1646  */
    {	
									fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, %d\n", getBinding(0));printf("codeGen starts\n");
									fprintf(fp, "CALL F0\n");
									fprintf(fp, "MOV R2, 10\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nINT 10\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1\n");
									codeGen((yyvsp[0].yys));
									return 0;
								 }
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 86 "ast.y" /* yacc.c:1646  */
    {	
											(yyval.yys) = makeConnectorNode((yyvsp[-1].yys), (yyvsp[0].yys));
											fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, %d\n", getBinding(0));printf("codeGen starts\n");
											fprintf(fp, "CALL F0\n");
											fprintf(fp, "MOV R2, 10\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nINT 10\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1\n");
											codeGen((yyval.yys));
											return 0;
										 }
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 94 "ast.y" /* yacc.c:1646  */
    {	
									fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, %d\n", getBinding(0));printf("codeGen starts\n");
									fprintf(fp, "CALL F0\n");
									fprintf(fp, "MOV R2, 10\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nINT 10\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1\n");
									codeGen((yyvsp[0].yys));
									return 0;
								 }
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 101 "ast.y" /* yacc.c:1646  */
    {	
						fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, %d\n", getBinding(0));printf("codeGen starts\n");
						fprintf(fp, "CALL F0\n");
						fprintf(fp, "MOV R2, 10\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nINT 10\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1\n");
						codeGen((yyvsp[0].yys));
						return 0;
					}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 110 "ast.y" /* yacc.c:1646  */
    {printTypeTable();}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 113 "ast.y" /* yacc.c:1646  */
    {}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 114 "ast.y" /* yacc.c:1646  */
    {}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 117 "ast.y" /* yacc.c:1646  */
    {fieldDef((yyvsp[-2].typeTable), (yyvsp[-1].fieldsList)); Tsize = 0;}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 120 "ast.y" /* yacc.c:1646  */
    {Tinstall((yyvsp[-1].string));(yyval.typeTable) = TlookUp((yyvsp[-1].string));}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 123 "ast.y" /* yacc.c:1646  */
    {(yyval.fieldsList) = addField((yyvsp[-1].fieldsList), (yyvsp[0].fieldsList));}
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 124 "ast.y" /* yacc.c:1646  */
    {(yyval.fieldsList) = (yyvsp[0].fieldsList);}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 127 "ast.y" /* yacc.c:1646  */
    {(yyval.fieldsList) = makeField((yyvsp[-2].typeTable), (yyvsp[-1].string)); Tsize++;}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 130 "ast.y" /* yacc.c:1646  */
    {(yyval.typeTable) = inttype;}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 131 "ast.y" /* yacc.c:1646  */
    {(yyval.typeTable) = strtype;}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 132 "ast.y" /* yacc.c:1646  */
    {(yyval.typeTable) = TlookUp((yyvsp[0].string));}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 135 "ast.y" /* yacc.c:1646  */
    {printSymTable();}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 138 "ast.y" /* yacc.c:1646  */
    {}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 139 "ast.y" /* yacc.c:1646  */
    {}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 142 "ast.y" /* yacc.c:1646  */
    {
								while((yyvsp[-1].varNameList) != NULL)
								{
									install((yyvsp[-1].varNameList)->name, (yyvsp[-2].typeTable), (yyvsp[-1].varNameList)->size, (yyvsp[-1].varNameList)->rowsize, (yyvsp[-1].varNameList)->argList);
									(yyvsp[-1].varNameList) = (yyvsp[-1].varNameList)->next;
									Lsym = NULL;
								}
							}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 152 "ast.y" /* yacc.c:1646  */
    {(yyval.varNameList) = addVarList((yyvsp[-2].varNameList), (yyvsp[0].varNameList));}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 153 "ast.y" /* yacc.c:1646  */
    {(yyval.varNameList) = (yyvsp[0].varNameList);}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 156 "ast.y" /* yacc.c:1646  */
    {(yyval.varNameList) = makeVarList((yyvsp[0].string), 1, 1);}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 157 "ast.y" /* yacc.c:1646  */
    {(yyval.varNameList) = makeVarList((yyvsp[-3].string), (yyvsp[-1].integer), 1);}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 158 "ast.y" /* yacc.c:1646  */
    {(yyval.varNameList) = addFunc((yyvsp[-3].string), (yyvsp[-1].argList));}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 159 "ast.y" /* yacc.c:1646  */
    {(yyval.varNameList) = addFunc((yyvsp[-2].string), NULL);}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 163 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeConnectorNode((yyvsp[-1].yys), (yyvsp[0].yys));}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 164 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 167 "ast.y" /* yacc.c:1646  */
    {
															funcLookUp((yyvsp[-6].argList)->type, (yyvsp[-6].argList)->name, (yyvsp[-5].argList));
															(yyval.yys) = makeFuncDefNode((yyvsp[-6].argList)->type, (yyvsp[-6].argList)->name, (yyvsp[-1].yys));
															currFType = NULL;
															Lsym = NULL;
															Lbinding = 1;
														}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 176 "ast.y" /* yacc.c:1646  */
    {(yyval.argList) = makeArgList((yyvsp[-2].typeTable), (yyvsp[-1].string)); currFType = (yyvsp[-2].typeTable); Lsym = (lookUp((yyvsp[-1].string)))->Lsym;printf("%s function starts\n\n", (yyvsp[-1].string));}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 178 "ast.y" /* yacc.c:1646  */
    {(yyval.argList) = addArgList((yyvsp[-2].argList), (yyvsp[0].argList));}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 179 "ast.y" /* yacc.c:1646  */
    {(yyval.argList) = (yyvsp[0].argList);}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 182 "ast.y" /* yacc.c:1646  */
    {(yyval.argList) = makeArgList((yyvsp[-1].typeTable), (yyvsp[0].string));}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 186 "ast.y" /* yacc.c:1646  */
    {printLocalSym();}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 187 "ast.y" /* yacc.c:1646  */
    {}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 190 "ast.y" /* yacc.c:1646  */
    {}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 191 "ast.y" /* yacc.c:1646  */
    {}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 194 "ast.y" /* yacc.c:1646  */
    {
							while((yyvsp[-1].varNameList) != NULL)
								{
									Linstall((yyvsp[-1].varNameList)->name, (yyvsp[-2].typeTable), Lbinding);
									Lbinding++;
									(yyvsp[-1].varNameList) = (yyvsp[-1].varNameList)->next;
								}
						}
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 204 "ast.y" /* yacc.c:1646  */
    {(yyval.varNameList) = addLVarList((yyvsp[-2].varNameList), (yyvsp[0].string));}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 205 "ast.y" /* yacc.c:1646  */
    {(yyval.varNameList) = makeLVarList((yyvsp[0].string));}
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 208 "ast.y" /* yacc.c:1646  */
    {
												(yyval.yys) = makeFuncDefNode((yyvsp[-5].argList)->type, (yyvsp[-5].argList)->name, (yyvsp[-1].yys));
												currFType = NULL;
												Lsym = NULL;
												Lbinding = 1;
											  }
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 216 "ast.y" /* yacc.c:1646  */
    {install("main", inttype, 0, 0, NULL); (yyval.argList) = makeArgList(inttype, "main"); currFType = inttype; Lsym = NULL;}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 218 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[-1].yys);}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 219 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = NULL;}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 222 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeConnectorNode((yyvsp[-2].yys), (yyvsp[-1].yys));}
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 223 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[-1].yys);}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 226 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 227 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 228 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 229 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 230 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 231 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 232 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeJmpNode(BRKST);}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 233 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeJmpNode(CONTST);}
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 234 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 235 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 236 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 239 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeWhileNode((yyvsp[-4].yys), (yyvsp[-1].yys));}
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 241 "ast.y" /* yacc.c:1646  */
    { (yyval.yys) = makeIfNode((yyvsp[-4].yys), (yyvsp[-1].yys));}
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 243 "ast.y" /* yacc.c:1646  */
    { (yyval.yys) = makeIfElseNode((yyvsp[-6].yys), (yyvsp[-3].yys), (yyvsp[-1].yys));}
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 245 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeReadNode(makeVarNode((yyvsp[-1].string)));}
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 246 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeReadNode(makeArrayNode((yyvsp[-4].string), (yyvsp[-2].yys)));}
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 247 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeReadNode(make2DArrayNode((yyvsp[-7].string), (yyvsp[-5].yys), (yyvsp[-2].yys)));}
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 250 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeWriteNode((yyvsp[-1].yys));}
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 252 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeOperatorNode('=', makeVarNode((yyvsp[-2].string)), (yyvsp[0].yys));}
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 253 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeOperatorNode('=',makeArrayNode((yyvsp[-5].string),(yyvsp[-3].yys)),(yyvsp[0].yys));}
#line 2043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 254 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeOperatorNode('=',make2DArrayNode((yyvsp[-8].string),(yyvsp[-6].yys), (yyvsp[-3].yys)),(yyvsp[0].yys));}
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 255 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeOperatorNode('=',(yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 258 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeRepeatNode((yyvsp[-4].yys), (yyvsp[-1].yys));}
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 260 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeDoWhileNode((yyvsp[-4].yys), (yyvsp[-1].yys));}
#line 2067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 262 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeReturnNode((yyvsp[0].yys));}
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 265 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeOperatorNode('+',(yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 266 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeOperatorNode('*',(yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 267 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeOperatorNode('-',(yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 268 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeOperatorNode('/',(yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 269 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeOperatorNode('%', (yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 270 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[-1].yys);}
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 271 "ast.y" /* yacc.c:1646  */
    { (yyval.yys) = makeVarNode((yyvsp[0].string));}
#line 2115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 272 "ast.y" /* yacc.c:1646  */
    { (yyval.yys) = makeConstantNode((yyvsp[0].integer));}
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 273 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeCondNode("==", (yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 274 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeCondNode("!=", (yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 275 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeCondNode("<", (yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 276 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeCondNode(">", (yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 277 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeCondNode("<=", (yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 278 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeCondNode(">=", (yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 279 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeStringNode((yyvsp[0].string));}
#line 2163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 280 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeArrayNode((yyvsp[-3].string), (yyvsp[-1].yys));}
#line 2169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 281 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = make2DArrayNode((yyvsp[-6].string), (yyvsp[-4].yys), (yyvsp[-1].yys));}
#line 2175 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 282 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeFuncCallNode((yyvsp[-2].string), NULL);}
#line 2181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 283 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeFuncCallNode((yyvsp[-3].string), (yyvsp[-1].yys));}
#line 2187 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 284 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeOrNode((yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 285 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeAndNode((yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 286 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 2205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 287 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeAllocNode();}
#line 2211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 288 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeFreeNode((yyvsp[-1].yys));}
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 289 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeInitializeNode();}
#line 2223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 290 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeNullNode();}
#line 2229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 293 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeConnectorNode((yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 294 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeConnectorNode((yyvsp[0].yys), NULL);}
#line 2241 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 297 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeFieldNode((yyvsp[-2].yys), (yyvsp[0].string));}
#line 2247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 298 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeFieldNode(makeVarNode((yyvsp[-2].string)), (yyvsp[0].string));}
#line 2253 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2257 "y.tab.c" /* yacc.c:1646  */
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
#line 301 "ast.y" /* yacc.c:1906  */


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
	createTypeTable();
	yyparse();
	return 0;
}
