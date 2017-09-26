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
#line 1 "SemanticAnalysis.y" /* yacc.c:339  */

    #include<stdio.h>
    #include<stdlib.h>
    #include<unistd.h>
    #include"GrammarTree.h"
    #include"SemanticAnalysis.h"
    #include"lex.yy.c"
    void yyerror(const char* fmt, ...);
    int gmerror = 1;
    int smerror = 0;
    int block = 0;
    ScopeStack scopestk;

#line 80 "SemanticAnalysis.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "SemanticAnalysis.tab.h".  */
#ifndef YY_YY_SEMANTICANALYSIS_TAB_H_INCLUDED
# define YY_YY_SEMANTICANALYSIS_TAB_H_INCLUDED
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
    SPSEMICOLON = 258,
    SPCOMMA = 259,
    SPDOT = 260,
    SPLEFTBRACE = 261,
    SPRIGHTBRACE = 262,
    OPLEFTPRNT = 263,
    OPRIGHTPRNT = 264,
    OPLEFTBRACKET = 265,
    OPRIGHTBRACKET = 266,
    OPPLUS = 267,
    OPMINUS = 268,
    OPMULTIPLY = 269,
    OPDIVIDE = 270,
    OPASSIGN = 271,
    OPAND = 272,
    OPOR = 273,
    OPNOT = 274,
    OPEQUAL = 275,
    OPNOTEQUAL = 276,
    OPGREAT = 277,
    OPLIGHT = 278,
    OPGREATEQ = 279,
    OPLIGHTEQ = 280,
    TYPEVOID = 281,
    TYPEINTEGER = 282,
    TYPEFLOAT = 283,
    TYPEBOOL = 284,
    TYPESTRING = 285,
    KEYCLASS = 286,
    KEYNEW = 287,
    KEYEXTENDS = 288,
    KEYTHIS = 289,
    KEYINSTANCEOF = 290,
    KEYIF = 291,
    KEYELSE = 292,
    KEYFOR = 293,
    KEYWHILE = 294,
    KEYBREAK = 295,
    KEYRETURN = 296,
    KEYSTATIC = 297,
    KEYPRINT = 298,
    KEYREADINTEGER = 299,
    KEYREADLINE = 300,
    CONSTANTNULL = 301,
    CONSTANTBOOL = 302,
    CONSTANTINTD = 303,
    CONSTANTINTH = 304,
    CONSTANTFLOAT = 305,
    CONSTANTFLOATSC = 306,
    CONSTANTSTRING = 307,
    IDENTIFIER = 308,
    LOWER_THAN_ELSE = 309
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 18 "SemanticAnalysis.y" /* yacc.c:355  */

    GrammarTree grammar_tree;

#line 179 "SemanticAnalysis.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_SEMANTICANALYSIS_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 210 "SemanticAnalysis.tab.c" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   460

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  191

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    83,    87,    93,    97,   101,   104,   105,
     106,   107,   108,   109,   116,   126,   130,   136,   137,   143,
     150,   159,   164,   169,   172,   173,   179,   184,   190,   191,
     194,   195,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   217,   218,   219,   222,   223,   224,   227,   228,   231,
     232,   234,   235,   238,   241,   244,   245,   248,   249,   252,
     255,   258,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   288,   289,   290,
     291,   292,   293,   294
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SPSEMICOLON", "SPCOMMA", "SPDOT",
  "SPLEFTBRACE", "SPRIGHTBRACE", "OPLEFTPRNT", "OPRIGHTPRNT",
  "OPLEFTBRACKET", "OPRIGHTBRACKET", "OPPLUS", "OPMINUS", "OPMULTIPLY",
  "OPDIVIDE", "OPASSIGN", "OPAND", "OPOR", "OPNOT", "OPEQUAL",
  "OPNOTEQUAL", "OPGREAT", "OPLIGHT", "OPGREATEQ", "OPLIGHTEQ", "TYPEVOID",
  "TYPEINTEGER", "TYPEFLOAT", "TYPEBOOL", "TYPESTRING", "KEYCLASS",
  "KEYNEW", "KEYEXTENDS", "KEYTHIS", "KEYINSTANCEOF", "KEYIF", "KEYELSE",
  "KEYFOR", "KEYWHILE", "KEYBREAK", "KEYRETURN", "KEYSTATIC", "KEYPRINT",
  "KEYREADINTEGER", "KEYREADLINE", "CONSTANTNULL", "CONSTANTBOOL",
  "CONSTANTINTD", "CONSTANTINTH", "CONSTANTFLOAT", "CONSTANTFLOATSC",
  "CONSTANTSTRING", "IDENTIFIER", "LOWER_THAN_ELSE", "$accept", "Program",
  "ClassDefs", "VariableDef", "Variable", "Type", "Variables", "Formals",
  "FunctionDef", "ClassDef", "Fields", "Field", "StmtBlock", "Stmts",
  "Stmt", "SimpleStmt", "LValue", "Call", "Actuals", "Exprs", "ForStmt",
  "WhileStmt", "IfStmt", "ReturnStmt", "BreakStmt", "PrintStmt",
  "BoolExpr", "Expr", "Constant", YY_NULLPTR
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
     305,   306,   307,   308,   309
};
# endif

#define YYPACT_NINF -105

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-105)))

#define YYTABLE_NINF -44

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      20,    -6,   -49,    53,     6,  -105,  -105,    65,  -105,  -105,
      66,     3,    54,  -105,  -105,  -105,  -105,  -105,    15,   184,
    -105,    69,     1,  -105,    82,    66,   106,  -105,  -105,     9,
    -105,   110,   105,  -105,  -105,    66,   114,  -105,   184,   120,
     184,  -105,    12,   126,   124,  -105,   139,  -105,   184,    11,
      11,  -105,   134,   137,  -105,  -105,  -105,    33,    -3,   259,
     259,    73,  -105,   141,   143,   145,   146,  -105,   259,   150,
     162,   166,  -105,  -105,  -105,  -105,  -105,  -105,  -105,   171,
    -105,  -105,   148,   137,   189,   178,    17,  -105,  -105,  -105,
     192,   194,   196,   393,  -105,   149,  -105,  -105,   330,   132,
      64,   193,   195,   259,   259,   259,   259,   393,   259,   191,
     197,   259,  -105,  -105,  -105,   259,  -105,  -105,  -105,   151,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   198,  -105,   199,   236,   309,   214,   393,
     224,   223,   102,   393,  -105,  -105,   237,   241,   393,   240,
     351,   132,   132,    64,    64,   435,   414,   147,   147,   147,
     147,   147,   147,   259,  -105,   372,   200,   190,   259,   190,
     259,  -105,  -105,   259,  -105,  -105,  -105,   242,   213,   249,
    -105,   393,   245,  -105,   190,   259,  -105,  -105,   247,   190,
    -105
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     3,    23,     0,     1,     4,
       0,     0,     0,    12,     8,     9,    10,    11,     0,     0,
      26,     0,     0,    27,     0,     0,     0,     6,    13,     0,
       5,     0,     7,    21,    25,     0,     0,    14,    17,     0,
      17,    15,     0,    18,     0,    22,     0,     7,     0,     0,
       0,    16,     0,     0,    19,    20,    29,     0,     0,     0,
       0,     0,    64,     0,     0,     0,     0,    59,    57,     0,
       0,     0,    93,    91,    87,    88,    89,    90,    92,    44,
      32,    40,     0,     0,     0,    63,    65,    36,    35,    34,
       0,     0,     0,     0,    62,     0,    63,    65,     0,    71,
      80,     0,     0,     0,     0,    41,     0,    58,     0,     0,
       0,    49,    28,    31,    33,     0,    38,    37,    39,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    66,     0,     0,     0,     0,    61,
       0,     0,     0,    51,    81,    82,     0,    50,    42,    45,
       0,    67,    68,    69,    70,    78,    79,    76,    77,    74,
      72,    75,    73,     0,    83,     0,     0,     0,     0,     0,
       0,    60,    47,    49,    46,    86,    84,     0,    55,     0,
      54,    52,     0,    85,     0,    41,    48,    56,     0,     0,
      53
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -105,  -105,  -105,    80,   -13,    -1,  -105,   217,  -105,   254,
      85,  -105,   -11,   176,   -60,   -97,   -53,   -50,    87,   153,
    -105,  -105,  -105,  -105,  -105,  -105,  -104,   -45,  -105
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    80,    21,    42,    43,    44,    23,     5,
      24,    25,    81,    82,    83,    84,    96,    97,   146,   147,
      87,    88,    89,    90,    91,    92,   138,    93,    94
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      85,     6,   141,    86,     7,    58,    -2,     1,   140,    22,
      59,    31,    52,    98,    99,   100,    60,    53,    29,    31,
     -43,     1,    31,   107,    22,    41,   -43,    41,    95,    61,
      85,    62,    63,    86,    22,    51,    27,     2,    54,    55,
      56,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,     2,    85,     8,    32,    86,    26,    27,   137,   139,
     102,   139,    36,   143,   179,    47,   143,    12,    28,   119,
     148,    10,    30,   -24,   120,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   188,    33,
      20,   165,    13,    14,    15,    16,    17,    18,    11,    13,
      14,    15,    16,    17,    18,    20,   170,   178,    19,   180,
      34,   171,    35,    38,    85,    20,    85,    86,   175,    86,
      39,    37,    40,   139,   187,   181,   101,    45,   143,   190,
      48,    85,    85,    49,    86,    86,    85,   119,    57,    86,
     -41,    56,   120,    53,   -30,    58,   123,   124,    50,   103,
      59,   104,   119,   105,   106,   112,    60,   120,   108,   121,
     122,   123,   124,    13,    14,    15,    16,    17,    18,    61,
     109,    62,    63,    64,   110,    65,    66,    67,    68,   111,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    57,   114,   -41,   115,   116,    53,   117,    58,   118,
     144,   135,   133,    59,   149,   136,   145,   163,   164,    60,
      13,    14,    15,    16,    17,    18,    13,    14,    15,    16,
      17,    18,    61,   167,    62,    63,    64,   168,    65,    66,
      67,    68,   169,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    58,   170,   172,    37,   173,    59,
     184,   183,   185,   177,   186,    60,   189,    46,     9,   113,
     182,   142,     0,     0,     0,     0,     0,    58,    61,     0,
      62,    63,    59,     0,     0,     0,     0,     0,    60,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
       0,    61,     0,    62,    63,     0,     0,     0,     0,     0,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,   166,   119,     0,     0,     0,     0,   120,
       0,   121,   122,   123,   124,     0,   125,   126,     0,   127,
     128,   129,   130,   131,   132,   119,     0,     0,     0,   134,
     120,     0,   121,   122,   123,   124,     0,   125,   126,     0,
     127,   128,   129,   130,   131,   132,   119,     0,     0,     0,
       0,   120,   174,   121,   122,   123,   124,     0,   125,   126,
       0,   127,   128,   129,   130,   131,   132,   119,     0,     0,
       0,     0,   120,   176,   121,   122,   123,   124,     0,   125,
     126,     0,   127,   128,   129,   130,   131,   132,   119,     0,
       0,     0,     0,   120,     0,   121,   122,   123,   124,     0,
     125,   126,     0,   127,   128,   129,   130,   131,   132,   119,
       0,     0,     0,     0,   120,     0,   121,   122,   123,   124,
       0,   125,     0,     0,   127,   128,   129,   130,   131,   132,
     119,     0,     0,     0,     0,   120,     0,   121,   122,   123,
     124,     0,     0,     0,     0,   127,   128,   129,   130,   131,
     132
};

static const yytype_int16 yycheck[] =
{
      53,     7,   106,    53,    53,     8,     0,     1,   105,    10,
      13,    10,     1,    58,    59,    60,    19,     6,    19,    10,
       3,     1,    10,    68,    25,    38,     9,    40,    31,    32,
      83,    34,    35,    83,    35,    48,     3,    31,    49,    50,
       7,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    31,   105,     0,    53,   105,    53,     3,   103,   104,
      61,   106,    53,   108,   168,    53,   111,     1,    53,     5,
     115,     6,     3,     7,    10,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   185,     7,
      10,   136,    26,    27,    28,    29,    30,    31,    33,    26,
      27,    28,    29,    30,    31,    25,     4,   167,    42,   169,
      25,     9,     6,     8,   167,    35,   169,   167,   163,   169,
      35,    11,     8,   168,   184,   170,    53,     7,   173,   189,
       4,   184,   185,     9,   184,   185,   189,     5,     1,   189,
       3,     7,    10,     6,     7,     8,    14,    15,     9,     8,
      13,     8,     5,     8,     8,     7,    19,    10,     8,    12,
      13,    14,    15,    26,    27,    28,    29,    30,    31,    32,
       8,    34,    35,    36,     8,    38,    39,    40,    41,     8,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,     1,     3,     3,    16,     3,     6,     3,     8,     3,
       9,     8,    53,    13,    53,    10,     9,     9,     9,    19,
      26,    27,    28,    29,    30,    31,    26,    27,    28,    29,
      30,    31,    32,     9,    34,    35,    36,     3,    38,    39,
      40,    41,     9,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,     8,     4,     9,    11,     8,    13,
      37,     9,     3,    53,     9,    19,     9,    40,     4,    83,
     173,   108,    -1,    -1,    -1,    -1,    -1,     8,    32,    -1,
      34,    35,    13,    -1,    -1,    -1,    -1,    -1,    19,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    32,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,     4,     5,    -1,    -1,    -1,    -1,    10,
      -1,    12,    13,    14,    15,    -1,    17,    18,    -1,    20,
      21,    22,    23,    24,    25,     5,    -1,    -1,    -1,     9,
      10,    -1,    12,    13,    14,    15,    -1,    17,    18,    -1,
      20,    21,    22,    23,    24,    25,     5,    -1,    -1,    -1,
      -1,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
      -1,    20,    21,    22,    23,    24,    25,     5,    -1,    -1,
      -1,    -1,    10,    11,    12,    13,    14,    15,    -1,    17,
      18,    -1,    20,    21,    22,    23,    24,    25,     5,    -1,
      -1,    -1,    -1,    10,    -1,    12,    13,    14,    15,    -1,
      17,    18,    -1,    20,    21,    22,    23,    24,    25,     5,
      -1,    -1,    -1,    -1,    10,    -1,    12,    13,    14,    15,
      -1,    17,    -1,    -1,    20,    21,    22,    23,    24,    25,
       5,    -1,    -1,    -1,    -1,    10,    -1,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    31,    56,    57,    64,     7,    53,     0,    64,
       6,    33,     1,    26,    27,    28,    29,    30,    31,    42,
      58,    59,    60,    63,    65,    66,    53,     3,    53,    60,
       3,    10,    53,     7,    65,     6,    53,    11,     8,    65,
       8,    59,    60,    61,    62,     7,    62,    53,     4,     9,
       9,    59,     1,     6,    67,    67,     7,     1,     8,    13,
      19,    32,    34,    35,    36,    38,    39,    40,    41,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      58,    67,    68,    69,    70,    71,    72,    75,    76,    77,
      78,    79,    80,    82,    83,    31,    71,    72,    82,    82,
      82,    53,    60,     8,     8,     8,     8,    82,     8,     8,
       8,     8,     7,    68,     3,    16,     3,     3,     3,     5,
      10,    12,    13,    14,    15,    17,    18,    20,    21,    22,
      23,    24,    25,    53,     9,     8,    10,    82,    81,    82,
      70,    81,    74,    82,     9,     9,    73,    74,    82,    53,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,     9,     9,    82,     4,     9,     3,     9,
       4,     9,     9,     8,    11,    82,    11,    53,    69,    81,
      69,    82,    73,     9,    37,     3,     9,    69,    70,     9,
      69
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    59,    60,    60,
      60,    60,    60,    60,    60,    61,    61,    62,    62,    63,
      63,    64,    64,    64,    65,    65,    66,    66,    67,    67,
      68,    68,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    70,    70,    70,    71,    71,    71,    72,    72,    73,
      73,    74,    74,    75,    76,    77,    77,    78,    78,    79,
      80,    81,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    83,    83,    83,
      83,    83,    83,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     2,     3,     1,     3,     0,     1,     6,
       7,     5,     7,     2,     0,     2,     1,     1,     3,     2,
       0,     2,     1,     2,     1,     1,     1,     2,     2,     2,
       1,     0,     3,     1,     1,     3,     4,     4,     6,     0,
       1,     1,     3,     9,     5,     5,     7,     1,     2,     1,
       4,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     4,     5,     6,     5,     1,     1,     1,
       1,     1,     1,     1
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 55 "SemanticAnalysis.y" /* yacc.c:1646  */
    { 
       (yyval.grammar_tree) = CreateGrammarTree("Program", 1, (yyvsp[0].grammar_tree)); 
       AddClassParent((yyvsp[0].grammar_tree)->globalscope);
       (yyval.grammar_tree)->globalscope = (yyvsp[0].grammar_tree)->globalscope;
       if (!gmerror) {
           printf("\nNow print the grammar-tree of \"Grammar Analyzing\":\n");
           printf("__________________________________________________\n\n"); 
           TraverseGrammerTree((yyval.grammar_tree), 0);
           printf("__________________________________________________\n\n"); 
           printf("The grammar-tree of \"Grammar Analyzing\" is printed!\n\n"); 
       }
       if (!smerror)
       {
           printf("\nNow print the symbol tables of \"Semantic Analyzing\":\n");
           printf("__________________________________________________\n\n"); 
           DisplayGlobalScope((yyvsp[0].grammar_tree)->globalscope, "Program");
           printf("__________________________________________________\n\n"); 
           printf("The symbol tables of \"Semantic Analyzing\" is printed!\n\n"); 
       }
       InitScopeStack(&scopestk);
       Scope scope;
       scope.type = ScopeGlobal;
       scope.globalscope = (yyval.grammar_tree)->globalscope;
       ScopeTrial((yyval.grammar_tree), scope, &scopestk);
       TraverseScopeStack(scopestk, "test");
       }
#line 1599 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 83 "SemanticAnalysis.y" /* yacc.c:1646  */
    { 
         (yyval.grammar_tree) = CreateGrammarTree("ClassDefs", 1, (yyvsp[0].grammar_tree)); 
         (yyval.grammar_tree)->globalscope = AddIntoGlobal((yyval.grammar_tree)->globalscope, (yyvsp[0].grammar_tree)->lchild->rchild->string_value, (yyvsp[0].grammar_tree)->depictor); 
         }
#line 1608 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 87 "SemanticAnalysis.y" /* yacc.c:1646  */
    { 
         (yyval.grammar_tree) = CreateGrammarTree("ClassDefs", 2, (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree));
         (yyval.grammar_tree)->globalscope = AddIntoGlobal((yyvsp[-1].grammar_tree)->globalscope, (yyvsp[0].grammar_tree)->lchild->rchild->string_value, (yyvsp[0].grammar_tree)->depictor);
         }
#line 1617 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 93 "SemanticAnalysis.y" /* yacc.c:1646  */
    { 
           (yyval.grammar_tree) = CreateGrammarTree("VariableDef", 2, (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); 
           (yyval.grammar_tree)->localscope = AddIntoLocal((yyval.grammar_tree)->localscope, (yyvsp[-1].grammar_tree)->lchild->rchild->string_value, Variable, (yyvsp[-1].grammar_tree)->lchild->string_value, NULL);
           }
#line 1626 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 97 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("VariableDef", 1, (yyvsp[0].grammar_tree)); gmerror += 1; }
#line 1632 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 101 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Variable", 2, (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 1638 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 104 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Type", 1, (yyvsp[0].grammar_tree)); (yyval.grammar_tree)->string_value = (yyvsp[0].grammar_tree)->string_value; }
#line 1644 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 105 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Type", 1, (yyvsp[0].grammar_tree)); (yyval.grammar_tree)->string_value = (yyvsp[0].grammar_tree)->string_value; }
#line 1650 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 106 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Type", 1, (yyvsp[0].grammar_tree)); (yyval.grammar_tree)->string_value = (yyvsp[0].grammar_tree)->string_value; }
#line 1656 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 107 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Type", 1, (yyvsp[0].grammar_tree)); (yyval.grammar_tree)->string_value = (yyvsp[0].grammar_tree)->string_value; }
#line 1662 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 108 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Type", 1, (yyvsp[0].grammar_tree)); (yyval.grammar_tree)->string_value = (yyvsp[0].grammar_tree)->string_value; }
#line 1668 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 109 "SemanticAnalysis.y" /* yacc.c:1646  */
    { 
    (yyval.grammar_tree) = CreateGrammarTree("Type", 2, (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); 
    char* cache = (char*)malloc(sizeof(char) * (6 + strlen((yyvsp[0].grammar_tree)->string_value)));
    strcpy(cache, "class:");
    strcat(cache, (yyvsp[0].grammar_tree)->string_value);
    (yyval.grammar_tree)->string_value = cache;
    }
#line 1680 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 116 "SemanticAnalysis.y" /* yacc.c:1646  */
    { 
    (yyval.grammar_tree) = CreateGrammarTree("Type", 3, (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); 
    char* cache = (char*)malloc(sizeof(char) * (strlen((yyvsp[-2].grammar_tree)->string_value) + 2));
    strcpy(cache, (yyvsp[-2].grammar_tree)->string_value);
    strcat(cache, "[]");
    (yyval.grammar_tree)->string_value = cache;
    }
#line 1692 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 126 "SemanticAnalysis.y" /* yacc.c:1646  */
    { 
         (yyval.grammar_tree) = CreateGrammarTree("Variables", 1, (yyvsp[0].grammar_tree)); 
         (yyval.grammar_tree)->formalscope = AddIntoFormal((yyval.grammar_tree)->formalscope, (yyvsp[0].grammar_tree)->lchild->rchild->string_value, (yyvsp[0].grammar_tree)->lchild->string_value, NULL);
         }
#line 1701 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 130 "SemanticAnalysis.y" /* yacc.c:1646  */
    { 
         (yyval.grammar_tree) = CreateGrammarTree("Variables", 3, (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); 
         (yyval.grammar_tree)->formalscope = AddIntoFormal((yyvsp[-2].grammar_tree)->formalscope, (yyvsp[0].grammar_tree)->lchild->rchild->string_value, (yyvsp[0].grammar_tree)->lchild->string_value, NULL);
         }
#line 1710 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 136 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Formals", 0, -1); (yyval.grammar_tree)->formalscope = NULL; }
#line 1716 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 137 "SemanticAnalysis.y" /* yacc.c:1646  */
    { 
       (yyval.grammar_tree) = CreateGrammarTree("Formals", 1, (yyvsp[0].grammar_tree)); 
       (yyval.grammar_tree)->formalscope = (yyvsp[0].grammar_tree)->formalscope;
       }
#line 1725 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 143 "SemanticAnalysis.y" /* yacc.c:1646  */
    { 
           (yyval.grammar_tree) = CreateGrammarTree("FunctionDef", 6, (yyvsp[-5].grammar_tree), (yyvsp[-4].grammar_tree), (yyvsp[-3].grammar_tree), (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); 
           (yyvsp[-2].grammar_tree)->formalscope = AddIntoFormal((yyvsp[-2].grammar_tree)->formalscope, "this", "class:", NULL);
           AddLocalIntoFormal((yyvsp[-2].grammar_tree)->formalscope, (yyvsp[0].grammar_tree)->localscope);
           (yyval.grammar_tree)->depictor = CreateFunctionDepictor(0, (yyvsp[-4].grammar_tree)->string_value, (yyvsp[-2].grammar_tree)->formalscope);
           (yyval.grammar_tree)->classscope = AddIntoClass((yyval.grammar_tree)->classscope, (yyvsp[-4].grammar_tree)->string_value, Function, (yyvsp[-5].grammar_tree)->string_value, (yyval.grammar_tree)->depictor); 
           }
#line 1737 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 150 "SemanticAnalysis.y" /* yacc.c:1646  */
    { 
           (yyval.grammar_tree) = CreateGrammarTree("FunctionDef", 7, (yyvsp[-6].grammar_tree), (yyvsp[-5].grammar_tree), (yyvsp[-4].grammar_tree), (yyvsp[-3].grammar_tree), (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); 
           (yyvsp[-2].grammar_tree)->formalscope = AddIntoFormal((yyvsp[-2].grammar_tree)->formalscope, "this", "class:", NULL);
           AddLocalIntoFormal((yyvsp[-2].grammar_tree)->formalscope, (yyvsp[0].grammar_tree)->localscope);
           (yyval.grammar_tree)->depictor = CreateFunctionDepictor(1, (yyvsp[-4].grammar_tree)->string_value, (yyvsp[-2].grammar_tree)->formalscope);
           (yyval.grammar_tree)->classscope = AddIntoClass((yyval.grammar_tree)->classscope, (yyvsp[-4].grammar_tree)->string_value, Function, (yyvsp[-5].grammar_tree)->string_value, (yyval.grammar_tree)->depictor);
           }
#line 1749 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 159 "SemanticAnalysis.y" /* yacc.c:1646  */
    { 
        (yyval.grammar_tree) = CreateGrammarTree("ClassDef", 5, (yyvsp[-4].grammar_tree), (yyvsp[-3].grammar_tree), (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree));
        AddThisType((yyvsp[-1].grammar_tree)->classscope, (yyvsp[-3].grammar_tree)->string_value);
        (yyval.grammar_tree)->depictor = CreateClassDepictor(NULL, (yyvsp[-1].grammar_tree)->classscope);
        }
#line 1759 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 164 "SemanticAnalysis.y" /* yacc.c:1646  */
    { 
        (yyval.grammar_tree) = CreateGrammarTree("ClassDef", 7, (yyvsp[-6].grammar_tree), (yyvsp[-5].grammar_tree), (yyvsp[-4].grammar_tree), (yyvsp[-3].grammar_tree), (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); 
        AddThisType((yyvsp[-1].grammar_tree)->classscope, (yyvsp[-5].grammar_tree)->string_value);
        (yyval.grammar_tree)->depictor = CreateClassDepictor((yyvsp[-3].grammar_tree)->string_value, (yyvsp[-1].grammar_tree)->classscope);
        }
#line 1769 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 169 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("ClassDef", 1, (yyvsp[0].grammar_tree)); gmerror += 1; }
#line 1775 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 172 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Fields", 0, -1); (yyval.grammar_tree)->classscope = NULL; }
#line 1781 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 173 "SemanticAnalysis.y" /* yacc.c:1646  */
    { 
      (yyval.grammar_tree) = CreateGrammarTree("Fields", 2, (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree));
      (yyval.grammar_tree)->classscope = MergeClassScope((yyvsp[-1].grammar_tree)->classscope, (yyvsp[0].grammar_tree)->classscope);
      }
#line 1790 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 179 "SemanticAnalysis.y" /* yacc.c:1646  */
    { 
     (yyval.grammar_tree) = CreateGrammarTree("Field", 1, (yyvsp[0].grammar_tree)); 
     Depictor depictor;
     (yyval.grammar_tree)->classscope = AddIntoClass((yyval.grammar_tree)->classscope, (yyvsp[0].grammar_tree)->lchild->lchild->rchild->string_value, Variable, (yyvsp[0].grammar_tree)->lchild->lchild->string_value, depictor);
     }
#line 1800 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 184 "SemanticAnalysis.y" /* yacc.c:1646  */
    { 
     (yyval.grammar_tree) = CreateGrammarTree("Field", 1, (yyvsp[0].grammar_tree)); 
     (yyval.grammar_tree)->classscope = (yyvsp[0].grammar_tree)->classscope;
     }
#line 1809 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 190 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("StmtBlock", 3, (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); (yyval.grammar_tree)->localscope = (yyvsp[-1].grammar_tree)->localscope; }
#line 1815 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 191 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("StmtBlock", 1, (yyvsp[0].grammar_tree)); gmerror += 1; }
#line 1821 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 194 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Stmts", 0, -1); (yyval.grammar_tree)->localscope = NULL; }
#line 1827 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 195 "SemanticAnalysis.y" /* yacc.c:1646  */
    { 
     (yyval.grammar_tree) = CreateGrammarTree("Stmts", 2, (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); 
     (yyval.grammar_tree)->localscope = MergeLocalScope((yyvsp[0].grammar_tree)->localscope, (yyvsp[-1].grammar_tree)->localscope);
     }
#line 1836 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 201 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Stmt", 1, (yyvsp[0].grammar_tree)); (yyval.grammar_tree)->localscope = (yyvsp[0].grammar_tree)->localscope; }
#line 1842 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 202 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Stmt", 2, (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 1848 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 203 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Stmt", 1, (yyvsp[0].grammar_tree)); }
#line 1854 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 204 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Stmt", 1, (yyvsp[0].grammar_tree)); }
#line 1860 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 205 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Stmt", 1, (yyvsp[0].grammar_tree)); }
#line 1866 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 206 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Stmt", 2, (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 1872 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 207 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Stmt", 2, (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 1878 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 208 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Stmt", 2, (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 1884 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 209 "SemanticAnalysis.y" /* yacc.c:1646  */
    { 
    (yyval.grammar_tree) = CreateGrammarTree("Stmt", 1, (yyvsp[0].grammar_tree)); 
    char cache[5];
    sprintf(cache, "%d", block++);
    (yyval.grammar_tree)->localscope = AddIntoLocal((yyval.grammar_tree)->localscope, cache, Block, "Block", (yyvsp[0].grammar_tree)->localscope); 
    }
#line 1895 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 217 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("SimpleStmt", 0, -1); }
#line 1901 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 218 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("SimpleStmt", 3, (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 1907 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 219 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("SimpleStmt", 1, (yyvsp[0].grammar_tree)); }
#line 1913 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 222 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("LValue", 1, (yyvsp[0].grammar_tree)); }
#line 1919 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 223 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("LValue", 3, (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 1925 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 224 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("LValue", 4, (yyvsp[-3].grammar_tree), (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 1931 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 227 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Call", 4, (yyvsp[-3].grammar_tree), (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 1937 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 228 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Call", 6, (yyvsp[-5].grammar_tree), (yyvsp[-4].grammar_tree), (yyvsp[-3].grammar_tree), (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 1943 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 231 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Actuals", 0, -1); }
#line 1949 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 232 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Actuals", 1, (yyvsp[0].grammar_tree)); }
#line 1955 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 234 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Exprs", 1, (yyvsp[0].grammar_tree)); }
#line 1961 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 235 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Exprs", 3, (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 1967 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 238 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("ForStmt", 9, (yyvsp[-8].grammar_tree), (yyvsp[-7].grammar_tree), (yyvsp[-6].grammar_tree), (yyvsp[-5].grammar_tree), (yyvsp[-4].grammar_tree), (yyvsp[-3].grammar_tree), (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 1973 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 241 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("WhileStmt", 5, (yyvsp[-4].grammar_tree), (yyvsp[-3].grammar_tree), (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 1979 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 244 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("IfStmt", 5, (yyvsp[-4].grammar_tree), (yyvsp[-3].grammar_tree), (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 1985 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 245 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("IfStmt", 7, (yyvsp[-6].grammar_tree), (yyvsp[-5].grammar_tree), (yyvsp[-4].grammar_tree), (yyvsp[-3].grammar_tree), (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 1991 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 248 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("ReturnStmt", 1, (yyvsp[0].grammar_tree)); }
#line 1997 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 249 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("ReturnStmt", 2, (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 2003 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 252 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("BreakStmt", 1, (yyvsp[0].grammar_tree)); }
#line 2009 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 255 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("PrintStmt", 4, (yyvsp[-3].grammar_tree), (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 2015 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 258 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("BoolExpr", 1, (yyvsp[0].grammar_tree)); }
#line 2021 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 261 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Expr", 1, (yyvsp[0].grammar_tree)); }
#line 2027 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 262 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Expr", 1, (yyvsp[0].grammar_tree)); }
#line 2033 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 263 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Expr", 1, (yyvsp[0].grammar_tree)); }
#line 2039 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 264 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Expr", 1, (yyvsp[0].grammar_tree)); }
#line 2045 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 265 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Expr", 3, (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 2051 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 266 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Expr", 3, (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 2057 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 267 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Expr", 3, (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 2063 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 268 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Expr", 3, (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 2069 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 269 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Expr", 3, (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 2075 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 270 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Expr", 2, (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 2081 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 271 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Expr", 3, (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 2087 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 272 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Expr", 3, (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 2093 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 273 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Expr", 3, (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 2099 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 274 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Expr", 3, (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 2105 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 275 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Expr", 3, (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 2111 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 276 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Expr", 3, (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 2117 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 277 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Expr", 3, (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 2123 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 278 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Expr", 3, (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 2129 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 279 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Expr", 2, (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 2135 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 280 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Expr", 3, (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 2141 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 281 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Expr", 3, (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 2147 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 282 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Expr", 4, (yyvsp[-3].grammar_tree), (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 2153 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 283 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Expr", 5, (yyvsp[-4].grammar_tree), (yyvsp[-3].grammar_tree), (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 2159 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 284 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Expr", 6, (yyvsp[-5].grammar_tree), (yyvsp[-4].grammar_tree), (yyvsp[-3].grammar_tree), (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 2165 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 285 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Expr", 5, (yyvsp[-4].grammar_tree), (yyvsp[-3].grammar_tree), (yyvsp[-2].grammar_tree), (yyvsp[-1].grammar_tree), (yyvsp[0].grammar_tree)); }
#line 2171 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 288 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Constant", 1, (yyvsp[0].grammar_tree)); }
#line 2177 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 289 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Constant", 1, (yyvsp[0].grammar_tree)); }
#line 2183 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 290 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Constant", 1, (yyvsp[0].grammar_tree)); }
#line 2189 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 291 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Constant", 1, (yyvsp[0].grammar_tree)); }
#line 2195 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 292 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Constant", 1, (yyvsp[0].grammar_tree)); }
#line 2201 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 293 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Constant", 1, (yyvsp[0].grammar_tree)); }
#line 2207 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 294 "SemanticAnalysis.y" /* yacc.c:1646  */
    { (yyval.grammar_tree) = CreateGrammarTree("Constant", 1, (yyvsp[0].grammar_tree)); }
#line 2213 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
    break;


#line 2217 "SemanticAnalysis.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 297 "SemanticAnalysis.y" /* yacc.c:1906  */


#include<stdarg.h>

void yyerror(const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "Grammar Error at Line %d Column %d: ", yylineno, yylloc.first_column);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, ".\n");
}

