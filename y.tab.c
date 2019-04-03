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
	int clabel = 0;
	int classField = 0;
	int funcPosition = 0;
	struct TypeTable *currFType = NULL;
	int whilelabel = -1;
	int bindingAddress = 4096;
	int Lbinding = 1;
	struct Gsymbol *symTable = NULL;
	struct Lsymbol *Lsym = NULL;
	struct TypeTable *Ttable = NULL;
	struct ClassTable *Ctable = NULL;
	struct ClassTable *currClass = NULL;
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


#line 105 "y.tab.c" /* yacc.c:339  */

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
    NIL = 301,
    CLASS = 302,
    ENDCLASS = 303,
    DELETE = 304,
    NEW = 305,
    SELF = 306
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
#define CLASS 302
#define ENDCLASS 303
#define DELETE 304
#define NEW 305
#define SELF 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 41 "ast.y" /* yacc.c:355  */

	struct tnode *yys;	
	int integer;
	struct varList *varNameList;
	char *string;
	struct argumentList *argList;
	struct TypeTable *typeTable;
	struct FieldList *fieldsList;
	struct ClassType *classTable;

#line 258 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 275 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   777

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  130
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  302

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

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
      55,    56,     2,     2,    57,     2,    60,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    54,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    59,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    52,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    71,    71,    80,    88,    95,   104,   112,   121,   124,
     125,   128,   131,   134,   135,   138,   141,   142,   143,   146,
     147,   150,   151,   154,   164,   166,   169,   170,   173,   176,
     177,   180,   181,   184,   185,   188,   191,   192,   195,   205,
     206,   209,   210,   211,   212,   216,   217,   220,   228,   238,
     248,   249,   252,   256,   257,   260,   261,   264,   274,   275,
     278,   286,   288,   289,   292,   293,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   309,   311,   313,
     315,   316,   317,   320,   322,   323,   324,   325,   328,   330,
     332,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     366,   367,   368,   369,   370,   371,   375,   376,   379,   380,
     381
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
  "ALLOC", "INITIALIZE", "FREE", "NIL", "CLASS", "ENDCLASS", "DELETE",
  "NEW", "SELF", "'}'", "'{'", "';'", "'('", "')'", "','", "'['", "']'",
  "'.'", "$accept", "Program", "TypeDefBlock", "TypeDefList", "TypeDef",
  "tname", "FieldDeclList", "FieldDecl", "TypeName", "ClassDefBlock",
  "ClassDefList", "ClassDef", "classDel", "Cname", "Fieldlists", "Fld",
  "MethodDecl", "Mdecl", "MethodDefs", "GDeclBlock", "GdeclList", "GDecl",
  "GidList", "Gid", "FDefBlock", "Fdef", "fname", "ParamList", "Param",
  "LdeclBlock", "LDecList", "LDecl", "IdList", "MainBlock", "mains",
  "Body", "slist", "stmt", "wedo", "iets", "ietse", "instmt", "outstmt",
  "asgstmt", "reun", "dowe", "ret", "expr", "fieldFucntion", "Arglist",
  "field", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   125,   123,    59,    40,    41,    44,    91,    93,
      46
};
# endif

#define YYPACT_NINF -111

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-111)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      33,   -19,    15,    46,    21,   -21,    71,  -111,    53,    60,
      70,    29,  -111,    66,  -111,    -1,  -111,    75,  -111,    71,
    -111,   105,   101,    76,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,    98,  -111,   134,  -111,  -111,   115,   101,   140,    64,
    -111,   -19,   147,   101,  -111,     8,  -111,   131,  -111,  -111,
     112,  -111,    66,   101,  -111,   -43,    51,  -111,  -111,  -111,
     113,  -111,  -111,   136,   179,   128,   135,    66,   185,  -111,
      66,   122,  -111,  -111,    17,   191,  -111,   140,  -111,   131,
    -111,   151,    66,   197,   148,  -111,   592,   161,   202,  -111,
     260,  -111,  -111,  -111,  -111,   163,   162,  -111,   185,   131,
    -111,  -111,   104,  -111,  -111,  -111,   165,   167,   -12,   168,
     175,   696,  -111,  -111,   696,   542,   173,   606,   189,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,   -10,  -111,
      28,  -111,   236,  -111,  -111,  -111,   200,   185,  -111,   237,
     542,   241,   542,   542,   246,   542,   542,   717,   651,  -111,
     -36,  -111,   204,   206,   207,  -111,   214,   227,   228,   542,
     736,  -111,   231,   280,  -111,   243,  -111,   542,   286,  -111,
      25,   245,  -111,   249,  -111,   403,    10,   736,   114,  -111,
     413,   450,   256,   257,   284,   542,   301,   258,   259,   542,
       4,   304,   309,   460,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   310,  -111,  -111,
     736,  -111,   269,   268,  -111,  -111,  -111,   542,    -5,   311,
     306,   542,   542,  -111,   279,   275,   172,   277,  -111,  -111,
     497,   278,     9,   287,   289,  -111,   124,   124,  -111,  -111,
     120,   120,   120,   120,   120,   120,  -111,   746,   746,   290,
    -111,   288,   201,   542,   542,   696,   696,   507,   544,   542,
    -111,   294,   305,  -111,  -111,  -111,   334,   350,  -111,    14,
     736,   211,   637,   353,   306,  -111,  -111,   542,  -111,   291,
    -111,   302,  -111,   303,  -111,   542,   344,   696,  -111,  -111,
     240,  -111,  -111,  -111,   250,   542,   682,  -111,   312,   736,
    -111,  -111
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      20,     0,     0,     0,     0,    20,     0,     7,     0,     0,
       0,     0,    10,     0,    25,     0,    22,     0,     1,     0,
       4,     0,     0,     0,    61,    12,     8,     9,    18,    16,
      17,     0,    14,     0,    19,    21,     0,     0,     0,     0,
      37,    16,     0,     0,    46,     0,     6,    54,    11,    13,
       0,    27,     0,     0,     3,    41,     0,    40,    35,    36,
       0,    45,     5,     0,     0,     0,    51,     0,     0,    15,
       0,     0,    34,     2,     0,     0,    38,     0,    49,    54,
      52,     0,     0,     0,     0,    56,     0,     0,     0,    26,
       0,    30,    23,    33,    44,     0,     0,    39,     0,    54,
      50,    59,     0,    53,    55,    63,     0,     0,     0,     0,
       0,     0,    72,    73,     0,     0,     0,     0,     0,    69,
      70,    71,    66,    67,    68,    74,    75,    76,     0,    60,
       0,    24,     0,    29,    43,    42,     0,     0,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    98,
      97,   105,     0,     0,     0,   117,     0,     0,     0,     0,
      90,   113,   112,     0,    62,     0,    65,     0,     0,    28,
       0,     0,    48,     0,    58,     0,     0,    84,     0,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   130,    64,
      87,   128,     0,     0,    47,    83,    80,     0,     0,     0,
       0,     0,     0,   108,   127,     0,     0,   129,   114,   116,
       0,     0,     0,     0,   130,    96,    91,    93,    92,    94,
     101,   103,   102,   104,    99,   100,    95,   111,   110,   128,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,   106,     0,   115,   119,   118,     0,     0,    31,     0,
      85,     0,     0,     0,    89,    88,   126,     0,   123,     0,
     121,     0,   125,     0,    81,     0,     0,     0,    78,    77,
       0,   122,   120,   124,     0,     0,     0,   107,     0,    86,
      79,    82
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,  -111,  -111,   355,  -111,  -111,   338,    32,   371,
    -111,   366,  -111,  -111,  -111,  -111,  -111,   297,  -111,   369,
    -111,   358,  -111,   315,   361,   119,  -111,   -72,  -111,   -65,
    -111,   318,  -111,     1,  -111,   -81,  -107,  -108,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -110,  -111,   293,
     -86
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,    11,    12,    13,    31,    32,    42,     6,
      15,    16,    52,    17,    70,    89,    90,    91,    71,    22,
      39,    40,    56,    57,    43,    44,    45,    65,    66,    68,
      84,    85,   102,     7,     8,    87,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   224,   161,   225,
     162
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     128,   142,    95,   167,   147,   160,    20,   148,   253,   165,
     100,    14,    74,     1,    98,    75,   231,   136,     9,   184,
      28,    18,   185,    46,   186,   128,     3,    10,   128,    28,
     175,   128,   177,   178,   137,   180,   181,    28,    54,   165,
     165,    10,    29,    30,    62,    33,   143,    34,   144,   193,
     168,    29,    30,   254,    73,   116,   173,   210,    14,    29,
      30,   128,   128,    33,    63,   264,   216,     1,   217,   168,
     284,    26,   285,    94,     2,   226,    38,    64,    28,   230,
       3,   212,   169,   170,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,    58,   213,    83,
      29,    30,    88,    21,   232,    76,    64,   252,    77,    23,
      28,   257,   258,    28,    64,    24,    83,    38,   194,   195,
     196,   197,   132,    25,   194,   195,   196,   197,    36,    47,
     196,   197,    29,    30,    28,    41,    30,   198,   199,   200,
     201,   202,   203,   270,   271,   204,    50,    51,   272,   273,
      48,   204,    55,   205,   206,   204,    29,    30,   138,    60,
      28,   139,    61,    67,   165,   165,    69,   290,    78,   128,
     128,    72,    61,   218,    92,   294,   194,   195,   196,   197,
     296,   103,    29,    30,    81,   299,   128,   128,   165,    79,
      93,    80,    82,    86,    96,   198,   199,   200,   201,   202,
     203,   128,    64,   204,    99,   194,   195,   196,   197,   101,
     128,   205,   206,   129,   130,   194,   195,   196,   197,   134,
     140,   135,   141,   145,   198,   199,   200,   201,   202,   203,
     146,   261,   204,   163,   198,   199,   200,   201,   202,   203,
     205,   206,   204,   166,   194,   195,   196,   197,   171,   174,
     205,   206,   172,   176,   194,   195,   196,   197,   179,   187,
     269,   188,   189,   198,   199,   200,   201,   202,   203,   190,
     286,   204,    28,   198,   199,   200,   201,   202,   203,   205,
     206,   204,   191,   194,   195,   196,   197,   149,   192,   205,
     206,   207,   208,   131,    29,    30,   150,   209,   211,   297,
     170,   214,   198,   199,   200,   201,   202,   203,   149,   298,
     204,   221,   222,   227,   228,   229,   233,   150,   205,   206,
     151,   234,   249,   250,   251,   256,   255,   152,   153,   154,
     155,   260,   262,   156,   157,   158,   259,   149,   144,   159,
     223,   151,   268,   265,   266,   267,   150,   291,   152,   153,
     154,   155,   277,   149,   156,   157,   158,   295,   292,   293,
     159,   278,   150,   106,   107,   108,    27,   109,   301,    49,
     151,   110,   111,   289,   112,   113,    19,   152,   153,   154,
     155,    35,   114,   156,   157,   158,   151,   133,    37,   159,
     280,   115,    97,   152,   153,   154,   155,    59,    53,   156,
     157,   158,   104,     0,   116,   159,   282,   194,   195,   196,
     197,     0,     0,     0,     0,     0,     0,   194,   195,   196,
     197,     0,     0,     0,     0,     0,   198,   199,   200,   201,
     202,   203,     0,     0,   204,     0,   198,   199,   200,   201,
     202,   203,   205,   206,   204,     0,     0,     0,     0,     0,
       0,     0,   205,   206,   194,   195,   196,   197,     0,   215,
       0,     0,     0,     0,   194,   195,   196,   197,     0,   219,
       0,     0,     0,   198,   199,   200,   201,   202,   203,     0,
       0,   204,     0,   198,   199,   200,   201,   202,   203,   205,
     206,   204,     0,     0,     0,     0,     0,     0,     0,   205,
     206,   194,   195,   196,   197,     0,   220,     0,     0,     0,
       0,   194,   195,   196,   197,     0,   235,     0,     0,     0,
     198,   199,   200,   201,   202,   203,     0,     0,   204,     0,
     198,   199,   200,   201,   202,   203,   205,   206,   204,     0,
       0,     0,     0,     0,     0,   149,   205,   206,   194,   195,
     196,   197,   276,   263,   150,   279,     0,     0,     0,   281,
     283,     0,     0,   274,     0,     0,     0,   198,   199,   200,
     201,   202,   203,     0,     0,   204,     0,     0,   151,     0,
       0,     0,     0,   205,   206,   152,   153,   154,   155,     0,
       0,   156,   157,   158,     0,     0,     0,   159,     0,     0,
     275,   105,   106,   107,   108,     0,   109,     0,     0,     0,
     110,   111,     0,   112,   113,   164,   106,   107,   108,     0,
     109,   114,     0,     0,   110,   111,     0,   112,   113,     0,
     115,     0,     0,     0,     0,   114,     0,     0,     0,     0,
       0,     0,     0,   116,   115,     0,     0,   106,   107,   108,
       0,   109,     0,   287,   288,   110,   111,   116,   112,   113,
       0,   106,   107,   108,     0,   109,   114,     0,     0,   110,
     111,     0,   112,   113,     0,   115,     0,     0,     0,     0,
     114,   183,     0,     0,     0,     0,     0,     0,   116,   115,
       0,     0,   106,   107,   108,     0,   109,     0,     0,   300,
     110,   111,   116,   112,   113,     0,   106,   107,   108,     0,
     109,   114,     0,     0,   110,   111,     0,   112,   113,     0,
     115,     0,     0,     0,     0,   114,     0,   106,   107,   108,
       0,   109,     0,   116,   115,   182,   111,     0,   112,   113,
     194,   195,   196,   197,     0,     0,   114,   116,     0,     0,
     194,   195,   196,   197,     0,   115,     0,     0,     0,   198,
     199,   200,   201,   202,   203,     0,     0,   204,   116,   198,
     199,   200,   201,   202,   203,   205,   206,   204
};

static const yytype_int16 yycheck[] =
{
      86,    13,    74,    13,   111,   115,     5,   114,    13,   117,
      82,    12,    55,    34,    79,    58,    12,    98,    37,    55,
      12,     0,    58,    22,    60,   111,    47,    12,   114,    12,
     140,   117,   142,   143,    99,   145,   146,    12,    37,   147,
     148,    12,    34,    35,    43,    13,    58,    48,    60,   159,
      60,    34,    35,    58,    53,    51,   137,   167,    12,    34,
      35,   147,   148,    31,    56,    56,    56,    34,    58,    60,
      56,    42,    58,    56,    41,   185,    12,    45,    12,   189,
      47,    56,    54,    55,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    33,   170,    67,
      34,    35,    70,    32,   190,    54,    74,   217,    57,    56,
      12,   221,   222,    12,    82,    55,    84,    12,     4,     5,
       6,     7,    90,    53,     4,     5,     6,     7,    53,    53,
       6,     7,    34,    35,    12,    34,    35,    23,    24,    25,
      26,    27,    28,   253,   254,    31,    12,    32,   255,   256,
      52,    31,    12,    39,    40,    31,    34,    35,    54,    12,
      12,    57,    43,    32,   272,   273,    54,   277,    55,   255,
     256,    52,    53,    59,    52,   285,     4,     5,     6,     7,
     287,    33,    34,    35,    56,   295,   272,   273,   296,    53,
      71,    12,    57,     8,     3,    23,    24,    25,    26,    27,
      28,   287,   170,    31,    53,     4,     5,     6,     7,    12,
     296,    39,    40,    52,    12,     4,     5,     6,     7,    56,
      55,    59,    55,    55,    23,    24,    25,    26,    27,    28,
      55,    59,    31,    60,    23,    24,    25,    26,    27,    28,
      39,    40,    31,    54,     4,     5,     6,     7,    12,    12,
      39,    40,    52,    12,     4,     5,     6,     7,    12,    55,
      59,    55,    55,    23,    24,    25,    26,    27,    28,    55,
      59,    31,    12,    23,    24,    25,    26,    27,    28,    39,
      40,    31,    55,     4,     5,     6,     7,     3,    60,    39,
      40,    60,    12,    33,    34,    35,    12,    54,    12,    59,
      55,    52,    23,    24,    25,    26,    27,    28,     3,    59,
      31,    55,    55,    12,    56,    56,    12,    12,    39,    40,
      36,    12,    12,    54,    56,    19,    15,    43,    44,    45,
      46,    56,    55,    49,    50,    51,    57,     3,    60,    55,
      56,    36,    54,    56,    55,    55,    12,    56,    43,    44,
      45,    46,    58,     3,    49,    50,    51,    13,    56,    56,
      55,    56,    12,    10,    11,    12,    11,    14,    56,    31,
      36,    18,    19,    20,    21,    22,     5,    43,    44,    45,
      46,    15,    29,    49,    50,    51,    36,    90,    19,    55,
      56,    38,    77,    43,    44,    45,    46,    39,    37,    49,
      50,    51,    84,    -1,    51,    55,    56,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,
      27,    28,    -1,    -1,    31,    -1,    23,    24,    25,    26,
      27,    28,    39,    40,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,     4,     5,     6,     7,    -1,    56,
      -1,    -1,    -1,    -1,     4,     5,     6,     7,    -1,    56,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    -1,
      -1,    31,    -1,    23,    24,    25,    26,    27,    28,    39,
      40,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,     4,     5,     6,     7,    -1,    56,    -1,    -1,    -1,
      -1,     4,     5,     6,     7,    -1,    56,    -1,    -1,    -1,
      23,    24,    25,    26,    27,    28,    -1,    -1,    31,    -1,
      23,    24,    25,    26,    27,    28,    39,    40,    31,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    39,    40,     4,     5,
       6,     7,   259,    56,    12,   262,    -1,    -1,    -1,   266,
     267,    -1,    -1,    56,    -1,    -1,    -1,    23,    24,    25,
      26,    27,    28,    -1,    -1,    31,    -1,    -1,    36,    -1,
      -1,    -1,    -1,    39,    40,    43,    44,    45,    46,    -1,
      -1,    49,    50,    51,    -1,    -1,    -1,    55,    -1,    -1,
      56,     9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,
      18,    19,    -1,    21,    22,     9,    10,    11,    12,    -1,
      14,    29,    -1,    -1,    18,    19,    -1,    21,    22,    -1,
      38,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    38,    -1,    -1,    10,    11,    12,
      -1,    14,    -1,    16,    17,    18,    19,    51,    21,    22,
      -1,    10,    11,    12,    -1,    14,    29,    -1,    -1,    18,
      19,    -1,    21,    22,    -1,    38,    -1,    -1,    -1,    -1,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    51,    38,
      -1,    -1,    10,    11,    12,    -1,    14,    -1,    -1,    17,
      18,    19,    51,    21,    22,    -1,    10,    11,    12,    -1,
      14,    29,    -1,    -1,    18,    19,    -1,    21,    22,    -1,
      38,    -1,    -1,    -1,    -1,    29,    -1,    10,    11,    12,
      -1,    14,    -1,    51,    38,    18,    19,    -1,    21,    22,
       4,     5,     6,     7,    -1,    -1,    29,    51,    -1,    -1,
       4,     5,     6,     7,    -1,    38,    -1,    -1,    -1,    23,
      24,    25,    26,    27,    28,    -1,    -1,    31,    51,    23,
      24,    25,    26,    27,    28,    39,    40,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    34,    41,    47,    62,    63,    70,    94,    95,    37,
      12,    64,    65,    66,    12,    71,    72,    74,     0,    70,
      94,    32,    80,    56,    55,    53,    42,    65,    12,    34,
      35,    67,    68,    69,    48,    72,    53,    80,    12,    81,
      82,    34,    69,    85,    86,    87,    94,    53,    52,    68,
      12,    32,    73,    85,    94,    12,    83,    84,    33,    82,
      12,    86,    94,    56,    69,    88,    89,    32,    90,    54,
      75,    79,    86,    94,    55,    58,    54,    57,    55,    53,
      12,    56,    57,    69,    91,    92,     8,    96,    69,    76,
      77,    78,    52,    86,    56,    88,     3,    84,    90,    53,
      88,    12,    93,    33,    92,     9,    10,    11,    12,    14,
      18,    19,    21,    22,    29,    38,    51,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   111,    52,
      12,    33,    69,    78,    56,    59,    96,    90,    54,    57,
      55,    55,    13,    58,    60,    55,    55,    97,    97,     3,
      12,    36,    43,    44,    45,    46,    49,    50,    51,    55,
     108,   109,   111,    60,     9,    98,    54,    13,    60,    54,
      55,    12,    52,    96,    12,   108,    12,   108,   108,    12,
     108,   108,    18,    30,    55,    58,    60,    55,    55,    55,
      55,    55,    60,   108,     4,     5,     6,     7,    23,    24,
      25,    26,    27,    28,    31,    39,    40,    60,    12,    54,
     108,    12,    56,    88,    52,    56,    56,    58,    59,    56,
      56,    55,    55,    56,   108,   110,   108,    12,    56,    56,
     108,    12,   111,    12,    12,    56,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,    12,
      54,    56,   108,    13,    58,    15,    19,   108,   108,    57,
      56,    59,    55,    56,    56,    56,    55,    55,    54,    59,
     108,   108,    97,    97,    56,    56,   110,    58,    56,   110,
      56,   110,    56,   110,    56,    58,    59,    16,    17,    20,
     108,    56,    56,    56,   108,    13,    97,    59,    59,   108,
      17,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    62,    62,    62,    62,    62,    63,    64,
      64,    65,    66,    67,    67,    68,    69,    69,    69,    70,
      70,    71,    71,    72,    73,    74,    75,    75,    76,    77,
      77,    78,    78,    79,    79,    80,    81,    81,    82,    83,
      83,    84,    84,    84,    84,    85,    85,    86,    86,    87,
      88,    88,    89,    90,    90,    91,    91,    92,    93,    93,
      94,    95,    96,    96,    97,    97,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    99,   100,   101,
     102,   102,   102,   103,   104,   104,   104,   104,   105,   106,
     107,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     109,   109,   109,   109,   109,   109,   110,   110,   111,   111,
     111
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     2,     4,     3,     1,     3,     2,
       1,     3,     2,     2,     1,     3,     1,     1,     1,     3,
       0,     2,     1,     5,     4,     1,     2,     0,     3,     2,
       1,     6,     5,     2,     1,     3,     2,     1,     3,     3,
       1,     1,     4,     4,     3,     2,     1,     7,     6,     3,
       3,     1,     2,     3,     0,     2,     1,     3,     3,     1,
       6,     3,     3,     2,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     7,     7,     9,
       4,     7,    10,     4,     3,     6,     9,     3,     6,     6,
       2,     3,     3,     3,     3,     3,     3,     1,     1,     3,
       3,     3,     3,     3,     3,     1,     4,     7,     3,     4,
       3,     3,     1,     1,     3,     4,     3,     1,     4,     4,
       6,     5,     6,     5,     6,     5,     3,     1,     3,     3,
       3
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
#line 71 "ast.y" /* yacc.c:1646  */
    {
											(yyval.yys) = makeConnectorNode((yyvsp[-1].yys), (yyvsp[0].yys));
											fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, %d\n", getBinding(0));printf("codeGen starts\n");
											fprintf(fp, "CALL F0\n");
											fprintf(fp, "MOV R2, 10\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nINT 10\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1\n");
											codeGen((yyvsp[-3].yys));
											codeGen((yyval.yys));
											return 0;
										 }
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 80 "ast.y" /* yacc.c:1646  */
    {
											fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, %d\n", getBinding(0));printf("codeGen starts\n");
											fprintf(fp, "CALL F0\n");
											fprintf(fp, "MOV R2, 10\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nINT 10\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1\n");
											codeGen((yyvsp[-2].yys));
											codeGen((yyvsp[0].yys));
											return 0;
										 }
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 88 "ast.y" /* yacc.c:1646  */
    {	
									fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, %d\n", getBinding(0));printf("codeGen starts\n");
									fprintf(fp, "CALL F0\n");
									fprintf(fp, "MOV R2, 10\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nINT 10\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1\n");
									codeGen((yyvsp[0].yys));
									return 0;
								 }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 95 "ast.y" /* yacc.c:1646  */
    {	
											(yyval.yys) = makeConnectorNode((yyvsp[-1].yys), (yyvsp[0].yys));
											fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, %d\n", getBinding(0));printf("codeGen starts\n");
											fprintf(fp, "CALL F0\n");
											fprintf(fp, "MOV R2, 10\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nINT 10\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1\n");
											codeGen((yyvsp[-3].yys));
											codeGen((yyval.yys));
											return 0;
										 }
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 104 "ast.y" /* yacc.c:1646  */
    {	
									fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, %d\n", getBinding(0));printf("codeGen starts\n");
									fprintf(fp, "CALL F0\n");
									fprintf(fp, "MOV R2, 10\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nINT 10\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1\n");
									codeGen((yyvsp[-2].yys));
									codeGen((yyvsp[0].yys));
									return 0;
								 }
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 112 "ast.y" /* yacc.c:1646  */
    {	
						fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, %d\n", getBinding(0));printf("codeGen starts\n");
						fprintf(fp, "CALL F0\n");
						fprintf(fp, "MOV R2, 10\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nPUSH R2\nINT 10\nPOP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1\n");
						codeGen((yyvsp[0].yys));
						return 0;
					}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 121 "ast.y" /* yacc.c:1646  */
    {printTypeTable();}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 124 "ast.y" /* yacc.c:1646  */
    {}
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 125 "ast.y" /* yacc.c:1646  */
    {}
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 128 "ast.y" /* yacc.c:1646  */
    {fieldDef((yyvsp[-2].typeTable), (yyvsp[-1].fieldsList)); Tsize = 0;}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 131 "ast.y" /* yacc.c:1646  */
    {Tinstall((yyvsp[-1].string));(yyval.typeTable) = TlookUp((yyvsp[-1].string));}
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 134 "ast.y" /* yacc.c:1646  */
    {(yyval.fieldsList) = addField((yyvsp[-1].fieldsList), (yyvsp[0].fieldsList));}
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 135 "ast.y" /* yacc.c:1646  */
    {(yyval.fieldsList) = (yyvsp[0].fieldsList);}
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 138 "ast.y" /* yacc.c:1646  */
    {(yyval.fieldsList) = makeField(TlookUp((yyvsp[-2].string)), (yyvsp[-1].string)); Tsize++;}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 141 "ast.y" /* yacc.c:1646  */
    {(yyval.string) ="int";}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 142 "ast.y" /* yacc.c:1646  */
    {(yyval.string) = "str";}
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 143 "ast.y" /* yacc.c:1646  */
    {(yyval.string) =strdup((yyvsp[0].string));}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 146 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[-1].yys);}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 147 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = NULL;}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 150 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeConnectorNode((yyvsp[-1].yys), (yyvsp[0].yys));}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 151 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 154 "ast.y" /* yacc.c:1646  */
    {
																		cInstall(currClass); 
																		clabel++; 
																		funcPosition = 0; 
																		classField = 0;
																		currClass = NULL;
																		(yyval.yys) = (yyvsp[-1].yys);
																		}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 164 "ast.y" /* yacc.c:1646  */
    {printClassMember(currClass);}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 166 "ast.y" /* yacc.c:1646  */
    {currClass =  makeClass((yyvsp[0].string));}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 169 "ast.y" /* yacc.c:1646  */
    {}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 173 "ast.y" /* yacc.c:1646  */
    {classFinstall(currClass, (yyvsp[-2].string), (yyvsp[-1].string)); classField++; }
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 176 "ast.y" /* yacc.c:1646  */
    {}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 177 "ast.y" /* yacc.c:1646  */
    {}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 180 "ast.y" /* yacc.c:1646  */
    {classMinstall(currClass,TlookUp((yyvsp[-5].string)), (yyvsp[-4].string), (yyvsp[-2].argList)); funcPosition++;}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 181 "ast.y" /* yacc.c:1646  */
    {classMinstall(currClass,TlookUp((yyvsp[-4].string)), (yyvsp[-3].string), NULL); funcPosition++;}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 184 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeConnectorNode((yyvsp[-1].yys), (yyvsp[0].yys));}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 185 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 188 "ast.y" /* yacc.c:1646  */
    {printSymTable();}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 191 "ast.y" /* yacc.c:1646  */
    {}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 192 "ast.y" /* yacc.c:1646  */
    {}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 195 "ast.y" /* yacc.c:1646  */
    {
								while((yyvsp[-1].varNameList) != NULL)
								{
									install((yyvsp[-1].varNameList)->name, (yyvsp[-2].string), (yyvsp[-1].varNameList)->size, (yyvsp[-1].varNameList)->rowsize, (yyvsp[-1].varNameList)->argList);
									(yyvsp[-1].varNameList) = (yyvsp[-1].varNameList)->next;
									Lsym = NULL;
								}
							}
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 205 "ast.y" /* yacc.c:1646  */
    {(yyval.varNameList) = addVarList((yyvsp[-2].varNameList), (yyvsp[0].varNameList));}
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 206 "ast.y" /* yacc.c:1646  */
    {(yyval.varNameList) = (yyvsp[0].varNameList);}
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 209 "ast.y" /* yacc.c:1646  */
    {(yyval.varNameList) = makeVarList((yyvsp[0].string), 1, 1);}
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 210 "ast.y" /* yacc.c:1646  */
    {(yyval.varNameList) = makeVarList((yyvsp[-3].string), (yyvsp[-1].integer), 1);}
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 211 "ast.y" /* yacc.c:1646  */
    {(yyval.varNameList) = addFunc((yyvsp[-3].string), (yyvsp[-1].argList));}
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 212 "ast.y" /* yacc.c:1646  */
    {(yyval.varNameList) = addFunc((yyvsp[-2].string), NULL);}
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 216 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeConnectorNode((yyvsp[-1].yys), (yyvsp[0].yys));}
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 217 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 220 "ast.y" /* yacc.c:1646  */
    {
															if(currClass == NULL)
																funcLookUp((yyvsp[-6].argList)->type, (yyvsp[-6].argList)->name, (yyvsp[-5].argList));
															(yyval.yys) = makeFuncDefNode((yyvsp[-6].argList)->type, (yyvsp[-6].argList)->name, (yyvsp[-1].yys));
															currFType = NULL;
															Lsym = NULL;
															Lbinding = 1;
														}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 228 "ast.y" /* yacc.c:1646  */
    {
											if(currClass == NULL)
												funcLookUp((yyvsp[-5].argList)->type, (yyvsp[-5].argList)->name, NULL);
											(yyval.yys) = makeFuncDefNode((yyvsp[-5].argList)->type, (yyvsp[-5].argList)->name, (yyvsp[-1].yys));
											currFType = NULL;
											Lsym = NULL;
											Lbinding = 1;
										}
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 238 "ast.y" /* yacc.c:1646  */
    {(yyval.argList) = makeArgList(TlookUp((yyvsp[-2].string)), (yyvsp[-1].string)); currFType = TlookUp((yyvsp[-2].string)); 
		if(lookUp((yyvsp[-1].string)) != NULL)
			Lsym = (lookUp((yyvsp[-1].string)))->Lsym;
		if(currClass != NULL)
			Lsym = (classMlookUp(currClass, (yyvsp[-1].string)))->Lsym;
		if(Lsym == NULL)
			printf("NULLLLLLLL\n");
		printf("%s function starts\n\n", (yyvsp[-1].string));
	}
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 248 "ast.y" /* yacc.c:1646  */
    {(yyval.argList) = addArgList((yyvsp[-2].argList), (yyvsp[0].argList));}
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 249 "ast.y" /* yacc.c:1646  */
    {(yyval.argList) = (yyvsp[0].argList);}
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 252 "ast.y" /* yacc.c:1646  */
    {(yyval.argList) = makeArgList(TlookUp((yyvsp[-1].string)), (yyvsp[0].string));}
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 256 "ast.y" /* yacc.c:1646  */
    {printLocalSym();}
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 257 "ast.y" /* yacc.c:1646  */
    {}
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 260 "ast.y" /* yacc.c:1646  */
    {}
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 261 "ast.y" /* yacc.c:1646  */
    {}
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 264 "ast.y" /* yacc.c:1646  */
    {
							while((yyvsp[-1].varNameList) != NULL)
								{
									Linstall((yyvsp[-1].varNameList)->name, TlookUp((yyvsp[-2].string)), Lbinding);
									Lbinding++;
									(yyvsp[-1].varNameList) = (yyvsp[-1].varNameList)->next;
								}
						}
#line 2067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 274 "ast.y" /* yacc.c:1646  */
    {(yyval.varNameList) = addLVarList((yyvsp[-2].varNameList), (yyvsp[0].string));}
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 275 "ast.y" /* yacc.c:1646  */
    {(yyval.varNameList) = makeLVarList((yyvsp[0].string));}
#line 2079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 278 "ast.y" /* yacc.c:1646  */
    {
												(yyval.yys) = makeFuncDefNode((yyvsp[-5].argList)->type, (yyvsp[-5].argList)->name, (yyvsp[-1].yys));
												currFType = NULL;
												Lsym = NULL;
												Lbinding = 1;
											  }
#line 2090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 286 "ast.y" /* yacc.c:1646  */
    {install("main", "int", 0, 0, NULL); (yyval.argList) = makeArgList(inttype, "main"); currFType = inttype; Lsym = NULL;}
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 288 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[-1].yys);}
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 289 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = NULL;}
#line 2108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 292 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeConnectorNode((yyvsp[-2].yys), (yyvsp[-1].yys));}
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 293 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[-1].yys);}
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 296 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 2126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 297 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 2132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 298 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 299 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 300 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 301 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 2156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 302 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeJmpNode(BRKST);}
#line 2162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 303 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeJmpNode(CONTST);}
#line 2168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 304 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 2174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 305 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 2180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 306 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 2186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 309 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeWhileNode((yyvsp[-4].yys), (yyvsp[-1].yys));}
#line 2192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 311 "ast.y" /* yacc.c:1646  */
    { (yyval.yys) = makeIfNode((yyvsp[-4].yys), (yyvsp[-1].yys));}
#line 2198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 313 "ast.y" /* yacc.c:1646  */
    { (yyval.yys) = makeIfElseNode((yyvsp[-6].yys), (yyvsp[-3].yys), (yyvsp[-1].yys));}
#line 2204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 315 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeReadNode(makeVarNode((yyvsp[-1].string)));}
#line 2210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 316 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeReadNode(makeArrayNode((yyvsp[-4].string), (yyvsp[-2].yys)));}
#line 2216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 317 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeReadNode(make2DArrayNode((yyvsp[-7].string), (yyvsp[-5].yys), (yyvsp[-2].yys)));}
#line 2222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 320 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeWriteNode((yyvsp[-1].yys));}
#line 2228 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 322 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeOperatorNode('=', makeVarNode((yyvsp[-2].string)), (yyvsp[0].yys));}
#line 2234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 323 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeOperatorNode('=',makeArrayNode((yyvsp[-5].string),(yyvsp[-3].yys)),(yyvsp[0].yys));}
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 324 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeOperatorNode('=',make2DArrayNode((yyvsp[-8].string),(yyvsp[-6].yys), (yyvsp[-3].yys)),(yyvsp[0].yys));}
#line 2246 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 325 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeOperatorNode('=',(yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 328 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeRepeatNode((yyvsp[-4].yys), (yyvsp[-1].yys));}
#line 2258 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 330 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeDoWhileNode((yyvsp[-4].yys), (yyvsp[-1].yys));}
#line 2264 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 332 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeReturnNode((yyvsp[0].yys));}
#line 2270 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 335 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeOperatorNode('+',(yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 336 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeOperatorNode('*',(yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 337 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeOperatorNode('-',(yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2288 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 338 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeOperatorNode('/',(yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2294 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 339 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeOperatorNode('%', (yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2300 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 340 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[-1].yys);}
#line 2306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 341 "ast.y" /* yacc.c:1646  */
    { (yyval.yys) = makeVarNode((yyvsp[0].string));}
#line 2312 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 342 "ast.y" /* yacc.c:1646  */
    { (yyval.yys) = makeConstantNode((yyvsp[0].integer));}
#line 2318 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 343 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeCondNode("==", (yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2324 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 344 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeCondNode("!=", (yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2330 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 345 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeCondNode("<", (yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 346 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeCondNode(">", (yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2342 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 347 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeCondNode("<=", (yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 348 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeCondNode(">=", (yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2354 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 349 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeStringNode((yyvsp[0].string));}
#line 2360 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 350 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeArrayNode((yyvsp[-3].string), (yyvsp[-1].yys));}
#line 2366 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 351 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = make2DArrayNode((yyvsp[-6].string), (yyvsp[-4].yys), (yyvsp[-1].yys));}
#line 2372 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 352 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeFuncCallNode((yyvsp[-2].string), NULL);}
#line 2378 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 353 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeFuncCallNode((yyvsp[-3].string), (yyvsp[-1].yys));}
#line 2384 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 354 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeOrNode((yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2390 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 355 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeAndNode((yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2396 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 356 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 2402 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 357 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = (yyvsp[0].yys);}
#line 2408 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 358 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeAllocNode();}
#line 2414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 359 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeFreeNode((yyvsp[-1].yys));}
#line 2420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 360 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeInitializeNode();}
#line 2426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 361 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeNullNode();}
#line 2432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 362 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeNewFunctionNode((yyvsp[-1].string));}
#line 2438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 363 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeDeleteNode((yyvsp[-1].yys));}
#line 2444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 366 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeFieldFucntionNode(makeSelfNode(), (yyvsp[-3].string), (yyvsp[-1].yys));}
#line 2450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 367 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeFieldFucntionNode(makeSelfNode(), (yyvsp[-2].string), NULL);}
#line 2456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 368 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeFieldFucntionNode(makeVarNode((yyvsp[-5].string)), (yyvsp[-3].string), (yyvsp[-1].yys));}
#line 2462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 369 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeFieldFucntionNode(makeVarNode((yyvsp[-4].string)), (yyvsp[-2].string), NULL);}
#line 2468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 370 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeFieldFucntionNode((yyvsp[-5].yys), (yyvsp[-3].string), (yyvsp[-1].yys));}
#line 2474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 371 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeFieldFucntionNode((yyvsp[-4].yys), (yyvsp[-2].string), NULL);}
#line 2480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 375 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeConnectorNode((yyvsp[-2].yys), (yyvsp[0].yys));}
#line 2486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 376 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeConnectorNode((yyvsp[0].yys), NULL);}
#line 2492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 379 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeFieldNode((yyvsp[-2].yys), (yyvsp[0].string));}
#line 2498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 380 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeFieldNode(makeVarNode((yyvsp[-2].string)), (yyvsp[0].string));}
#line 2504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 381 "ast.y" /* yacc.c:1646  */
    {(yyval.yys) = makeFieldNode(makeSelfNode(), (yyvsp[0].string));}
#line 2510 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2514 "y.tab.c" /* yacc.c:1646  */
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
#line 384 "ast.y" /* yacc.c:1906  */


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
