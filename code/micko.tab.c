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
#line 1 "micko.y" /* yacc.c:339  */

  #include <stdio.h>
  #include <stdlib.h>
  #include "defs.h"
  #include "symtab.h"
  #include "codegen.h"
 
  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  void warning(char *s);

  extern int yylineno;
  int out_lin = 0;
  char char_buffer[CHAR_BUFFER_LENGTH];
  int error_count = 0;
  int warning_count = 0;
  int var_num = 0;
  int fun_idx = -1;
  int fcall_idx = -1;
  int lab_num = -1;
  int para_num =0;
  FILE *output;


 int br_par = 0;
  int tip;
  int vrsta;
  bool ret=0;
  int jiro_idx;
  int br_arg = 0;
  int rel1;
  int rel2;
 int reg;
 int dvostruka=-1;
 int jiro_num=-1;
 int idx_switch=0;
 int tranga_num=-1;


#line 107 "micko.tab.c" /* yacc.c:339  */

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
   by #include "micko.tab.h".  */
#ifndef YY_YY_MICKO_TAB_H_INCLUDED
# define YY_YY_MICKO_TAB_H_INCLUDED
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
    _TYPE = 258,
    _IF = 259,
    _ELSE = 260,
    _RETURN = 261,
    _ID = 262,
    _INT_NUMBER = 263,
    _UINT_NUMBER = 264,
    _LPAREN = 265,
    _RPAREN = 266,
    _LBRACKET = 267,
    _RBRACKET = 268,
    _ASSIGN = 269,
    _SEMICOLON = 270,
    _AROP = 271,
    _RELOP = 272,
    _COMMA = 273,
    _POSTINC = 274,
    _PARA = 275,
    _PASO = 276,
    _JIRO = 277,
    _TRANGA = 278,
    _TOERANA = 279,
    _COLON = 280,
    _BREAK = 281,
    _QMARK = 282,
    ONLY_IF = 283
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 42 "micko.y" /* yacc.c:355  */

  int i;
  char *s;

#line 181 "micko.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MICKO_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 198 "micko.tab.c" /* yacc.c:358  */

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   137

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

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
      25,    26,    27,    28
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    83,    83,    88,    96,    97,   100,   101,   105,   116,
     115,   148,   150,   167,   187,   186,   206,   208,   212,   223,
     241,   240,   249,   258,   269,   271,   275,   276,   277,   278,
     279,   280,   281,   286,   291,   285,   305,   307,   315,   314,
     328,   328,   340,   348,   356,   358,   363,   384,   362,   407,
     428,   432,   447,   448,   490,   491,   497,   502,   518,   522,
     526,   525,   543,   550,   555,   558,   564,   563,   587,   589,
     599,   612,   641,   647,   653,   646,   667,   689,   699
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_TYPE", "_IF", "_ELSE", "_RETURN",
  "_ID", "_INT_NUMBER", "_UINT_NUMBER", "_LPAREN", "_RPAREN", "_LBRACKET",
  "_RBRACKET", "_ASSIGN", "_SEMICOLON", "_AROP", "_RELOP", "_COMMA",
  "_POSTINC", "_PARA", "_PASO", "_JIRO", "_TRANGA", "_TOERANA", "_COLON",
  "_BREAK", "_QMARK", "ONLY_IF", "$accept", "program", "function_list",
  "steva", "g_prom", "function", "$@1", "parameter", "body", "$@2",
  "variable_list", "variable", "pocetak_var", "$@3", "vars",
  "statement_list", "statement", "jiro_statement", "$@4", "$@5",
  "break_exp", "tranga_exp", "$@6", "$@7", "jiro_literal", "toerana_exp",
  "para_statement", "$@8", "$@9", "postinc_statement",
  "compound_statement", "assignment_statement", "num_exp", "exp", "$@10",
  "nesto", "literal", "function_call", "$@11", "argument", "if_statement",
  "if_part", "@12", "$@13", "rel_exp", "return_statement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283
};
# endif

#define YYPACT_NINF -104

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-104)))

#define YYTABLE_NINF -67

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      12,    23,    45,    67,    12,  -104,  -104,    40,  -104,    77,
    -104,    67,  -104,  -104,    75,  -104,    83,    80,    28,  -104,
      76,    86,  -104,  -104,    84,    87,  -104,  -104,  -104,  -104,
      37,    85,     0,    50,  -104,  -104,    78,    88,    27,    34,
    -104,  -104,    89,  -104,  -104,  -104,  -104,  -104,  -104,  -104,
    -104,    90,  -104,    -1,  -104,  -104,    50,    46,  -104,  -104,
      81,    94,  -104,  -104,    49,    50,    79,     4,    99,    93,
      21,  -104,    95,    33,  -104,  -104,    50,  -104,  -104,    50,
    -104,    52,  -104,  -104,    97,   100,  -104,    50,  -104,    50,
      82,  -104,    60,  -104,  -104,  -104,  -104,    92,    29,    92,
      91,    98,    96,   101,  -104,    50,    66,    21,    50,   102,
      92,  -104,    72,  -104,  -104,   104,   103,    66,   106,    70,
      57,  -104,    74,  -104,  -104,  -104,    70,   105,   107,  -104,
     108,   109,    21,  -104,   110,    21,  -104,  -104,    21,   111,
      21,  -104,   113,  -104,   111,  -104,  -104
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     0,     6,     4,     9,     1,     0,
       5,     2,     7,     8,     0,     9,    11,     0,     0,    12,
       0,     0,    16,    10,     0,    14,    13,    20,    24,    17,
       0,     0,     0,     0,    18,    22,    21,     0,     0,     0,
      24,    15,     0,    33,    25,    32,    31,    29,    26,    27,
      28,    71,    30,    55,    64,    65,     0,     0,    52,    54,
      56,     0,    73,    78,     0,     0,     0,     0,     0,     0,
       0,    57,     0,     0,    60,    19,     0,    58,    23,     0,
      77,     0,    49,    50,     0,     0,    72,    68,    59,     0,
       0,    53,     0,    74,    51,    46,    34,    69,     0,    76,
       0,     0,     0,     0,    67,     0,     0,     0,     0,     0,
      70,    62,     0,    63,    75,     0,     0,     0,     0,     0,
      44,    61,     0,    42,    43,    38,     0,     0,     0,    47,
       0,     0,     0,    35,     0,     0,    40,    45,     0,    36,
       0,    48,     0,    39,    36,    37,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -104,  -104,   112,  -104,   118,    18,  -104,  -104,  -104,  -104,
    -104,  -104,  -104,  -104,  -104,    73,   -69,  -104,  -104,  -104,
     -38,  -104,  -104,  -104,   -16,  -104,  -104,  -104,  -104,  -104,
    -104,  -104,   -33,    39,  -104,     6,  -103,  -104,  -104,  -104,
    -104,  -104,  -104,  -104,   -77,  -104
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     5,     6,    14,    18,    23,    28,
      25,    29,    30,    31,    36,    32,    44,    45,    69,   103,
     143,   120,   130,   140,   125,   128,    46,   102,   134,    47,
      48,    49,    92,    58,    90,   112,    59,    60,    72,    98,
      50,    51,    79,   101,    74,    52
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,    86,    93,   113,    37,    64,    38,    39,    37,   -66,
      38,    39,    40,    41,   113,     1,    40,    83,    71,   129,
      42,    10,    43,    73,    42,    37,    43,    38,    39,    10,
       7,   115,    81,    40,    53,    54,    55,    56,   114,    20,
     104,    42,    63,    43,    88,     8,    21,   105,    65,    76,
      89,    33,    34,    66,    97,    13,    99,    53,    54,    55,
      56,    75,    76,   137,    80,    76,   139,    94,    76,   141,
       9,   144,   110,   111,    54,    55,    76,    89,   123,   124,
     126,   127,    54,    55,    15,    16,    17,    19,    22,    24,
      27,    26,    35,   100,    82,    70,    61,   117,    62,    68,
      77,    78,    84,    85,    95,    87,   146,    96,    76,   107,
     131,   108,   109,    67,   116,    91,    11,     0,   106,   118,
     133,   138,    12,   121,     0,     0,   119,   122,   145,     0,
     132,     0,     0,   135,   136,     0,     0,   142
};

static const yytype_int16 yycheck[] =
{
      33,    70,    79,   106,     4,    38,     6,     7,     4,    10,
       6,     7,    12,    13,   117,     3,    12,    13,    19,   122,
      20,     3,    22,    56,    20,     4,    22,     6,     7,    11,
       7,   108,    65,    12,     7,     8,     9,    10,   107,    11,
      11,    20,    15,    22,    11,     0,    18,    18,    14,    16,
      17,    14,    15,    19,    87,    15,    89,     7,     8,     9,
      10,    15,    16,   132,    15,    16,   135,    15,    16,   138,
       3,   140,   105,     7,     8,     9,    16,    17,     8,     9,
      23,    24,     8,     9,     7,    10,     3,     7,    12,     3,
       3,     7,     7,    11,    15,     5,    18,    25,    10,    10,
      19,     7,     3,    10,     7,    10,   144,     7,    16,    11,
     126,    15,    11,    40,    12,    76,     4,    -1,    27,    15,
      13,    11,     4,   117,    -1,    -1,    23,    21,    15,    -1,
      25,    -1,    -1,    25,    25,    -1,    -1,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    30,    31,    32,    33,    34,     7,     0,     3,
      34,    31,    33,    15,    35,     7,    10,     3,    36,     7,
      11,    18,    12,    37,     3,    39,     7,     3,    38,    40,
      41,    42,    44,    14,    15,     7,    43,     4,     6,     7,
      12,    13,    20,    22,    45,    46,    55,    58,    59,    60,
      69,    70,    74,     7,     8,     9,    10,    61,    62,    65,
      66,    18,    10,    15,    61,    14,    19,    44,    10,    47,
       5,    19,    67,    61,    73,    15,    16,    19,     7,    71,
      15,    61,    15,    13,     3,    10,    45,    10,    11,    17,
      63,    62,    61,    73,    15,     7,     7,    61,    68,    61,
      11,    72,    56,    48,    11,    18,    27,    11,    15,    11,
      61,     7,    64,    65,    45,    73,    12,    25,    15,    23,
      50,    64,    21,     8,     9,    53,    23,    24,    54,    65,
      51,    53,    25,    13,    57,    25,    25,    45,    11,    45,
      52,    45,    26,    49,    45,    15,    49
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    29,    30,    30,    31,    31,    32,    32,    33,    35,
      34,    36,    36,    36,    38,    37,    39,    39,    40,    40,
      42,    41,    43,    43,    44,    44,    45,    45,    45,    45,
      45,    45,    45,    47,    48,    46,    49,    49,    51,    50,
      52,    50,    53,    53,    54,    54,    56,    57,    55,    58,
      59,    60,    61,    61,    62,    62,    62,    62,    62,    62,
      63,    62,    64,    64,    65,    65,    67,    66,    68,    68,
      68,    69,    69,    71,    72,    70,    73,    74,    74
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     2,     1,     2,     3,     0,
       7,     0,     2,     4,     0,     5,     0,     2,     2,     4,
       0,     3,     1,     3,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     0,     0,    10,     0,     2,     0,     6,
       0,     7,     1,     1,     0,     3,     0,     0,    13,     3,
       3,     4,     1,     3,     1,     1,     1,     2,     2,     3,
       0,     8,     1,     1,     1,     1,     0,     5,     0,     1,
       3,     1,     3,     0,     0,     7,     3,     3,     2
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
#line 84 "micko.y" /* yacc.c:1646  */
    {  
        if(lookup_symbol("main", FUN) == NO_INDEX)
          err("undefined reference to 'main'");
      }
#line 1379 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 89 "micko.y" /* yacc.c:1646  */
    {  
        if(lookup_symbol("main", FUN) == NO_INDEX)
          err("undefined reference to 'main'");
      }
#line 1388 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 106 "micko.y" /* yacc.c:1646  */
    {
  if(lookup_symbol((yyvsp[-1].s), GVAR) == NO_INDEX)
           insert_symbol((yyvsp[-1].s), GVAR, (yyvsp[-2].i), NO_ATR, NO_ATR);
        else 
           err("redefinition of '%s'", (yyvsp[-1].s));
           code("\n%s: WORD\n 1",(yyvsp[-1].s));
}
#line 1400 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 116 "micko.y" /* yacc.c:1646  */
    {
        fun_idx = lookup_symbol((yyvsp[0].s), FUN);

        if(fun_idx == NO_INDEX)
          fun_idx = insert_symbol((yyvsp[0].s), FUN, (yyvsp[-1].i), NO_ATR, NO_ATR);

        else 
          err("Funkcija: '%s' je vec definisana!", (yyvsp[0].s));

        code("\n%s:", (yyvsp[0].s));
        code("\n\t\tPUSH\t%%14");
        code("\n\t\tMOV \t%%15,%%14");
      }
#line 1418 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 130 "micko.y" /* yacc.c:1646  */
    {
        if(!ret && (yyvsp[-6].i)!=VOID)
         warning("Funkcija tipa INT/UNSIGNED treba da vrati vrednost odgovarajuceg tipa!");
        
        clear_symbols(fun_idx + br_par + 1);
        var_num = 0;
        br_par = 0;
        ret=0;

        code("\n@%s_exit:", (yyvsp[-5].s));
        code("\n\t\tMOV \t%%14,%%15");
        code("\n\t\tPOP \t%%14");
        code("\n\t\tRET");
      }
#line 1437 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 148 "micko.y" /* yacc.c:1646  */
    { set_atr1(fun_idx, 0); }
#line 1443 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 151 "micko.y" /* yacc.c:1646  */
    {
        if((yyvsp[-1].i) == VOID)
          err("Promenjive ne mogu da budu VOID tipa");

        else{
            if(lookup_symbol((yyvsp[0].s),PAR) == NO_INDEX)
            {
              insert_symbol((yyvsp[0].s), PAR, (yyvsp[-1].i), ++br_par, NO_ATR);
              set_atr1(fun_idx, br_par);
              set_atr2(fun_idx, (yyvsp[-1].i));
            }

            else
              err("Promenjiva '%s' je vec definisana", (yyvsp[0].s));
            }
      }
#line 1464 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 168 "micko.y" /* yacc.c:1646  */
    {
        if(get_type((yyvsp[-1].i)) == VOID)
            err("Promenjive ne mogu da budu VOID tipa");

        else{
          if(lookup_symbol((yyvsp[0].s), PAR) == NO_INDEX)
          {
            insert_symbol((yyvsp[0].s), PAR, (yyvsp[-1].i), ++br_par, NO_ATR);
            set_atr1(fun_idx, br_par);
            set_atr2(fun_idx, (yyvsp[-1].i));
          }
          else
            err("Promenjiva '%s' je vec definisana",(yyvsp[0].s));
            }
      }
#line 1484 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 187 "micko.y" /* yacc.c:1646  */
    {
    if(var_num)
          code("\n\t\tSUBS\t%%15,$%d,%%15", 4*var_num);
        code("\n@%s_body:", get_name(fun_idx));

        for(int idx = 14; idx <= get_last_element(); idx++)
    	  {
    	    if(get_atr2(idx) != 0 && get_kind(idx) == VAR)
    	      {
    	          gen_mov(get_atr2(idx), idx);
    	      }
    	      
    	    set_atr2(idx, 0);
    	  }


  }
#line 1506 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 212 "micko.y" /* yacc.c:1646  */
    {

    for(int idx = 14; idx <= get_last_element(); idx++)
    	  {
    	    if(get_atr2(idx) == MAGIC_NUM && get_kind(idx) == VAR)
    	      {
    	          set_atr2(idx, 0);
    	      }
    	  }

  }
#line 1522 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 224 "micko.y" /* yacc.c:1646  */
    { 
      if(tip != get_type((yyvsp[-1].i)))
        err("Tip deklarisanih varijabli i tip podatka koji im se dodeljuje se ne poklapaju");

        for(int idx = 14; idx <= get_last_element(); idx++)
    	  {
    	    if(get_atr2(idx) == MAGIC_NUM && get_kind(idx) == VAR)
    	      {
    	          set_atr2(idx, (yyvsp[-1].i));
    	      }
    	  }

  }
#line 1540 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 241 "micko.y" /* yacc.c:1646  */
    {if((yyvsp[0].i)==VOID)
    err("Promenjiva ne moze biti tipa VOID!");
    tip=(yyvsp[0].i);
    }
#line 1549 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 250 "micko.y" /* yacc.c:1646  */
    {
        if(lookup_symbol((yyvsp[0].s), VAR|PAR|GVAR) == NO_INDEX)  {        
           insert_symbol((yyvsp[0].s), VAR, tip, ++var_num, NO_ATR);
           set_atr2(lookup_symbol((yyvsp[0].s), VAR|PAR|GVAR) , MAGIC_NUM);
           }
        else 
           err("Promenjiva '%s' je vec definisana!", (yyvsp[0].s));
       }
#line 1562 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 259 "micko.y" /* yacc.c:1646  */
    {
        if(lookup_symbol((yyvsp[0].s), VAR|PAR|GVAR) == NO_INDEX)   {  
           insert_symbol((yyvsp[0].s), VAR, tip, ++var_num, NO_ATR);
           set_atr2(lookup_symbol((yyvsp[0].s), VAR|PAR|GVAR), MAGIC_NUM);
           }
        else 
           err("Promenjiva '%s' je vec definisana!", (yyvsp[0].s));
      }
#line 1575 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 286 "micko.y" /* yacc.c:1646  */
    {
      jiro_idx=get_last_element();
      jiro_num++;
    }
#line 1584 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 291 "micko.y" /* yacc.c:1646  */
    {  
    idx_switch=lookup_symbol((yyvsp[0].s),VAR|PAR|GVAR);
    if(idx_switch==NO_INDEX){
    err(" Promenjiva '%s' mora biti prethodno deklarisana!",(yyvsp[0].s));}
    
    tip=get_type(idx_switch);
  }
#line 1596 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 299 "micko.y" /* yacc.c:1646  */
    {
    code("\njiro_exit%d:",jiro_num);
    clear_symbols(jiro_idx+1);
  }
#line 1605 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 307 "micko.y" /* yacc.c:1646  */
    {

    code("\n\t\tJMP\tjiro_exit%d",jiro_num);
  }
#line 1614 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 315 "micko.y" /* yacc.c:1646  */
    {
    if(tip!=get_type((yyvsp[0].i))){
      err("Tip tranga iskaza mora biti istog tipa kao Jiro promenjiva!");
      }
      else{
    gen_cmp(idx_switch,(yyvsp[0].i));
    code("\n\t\t%s\t@tranga_false%d",opp_jumps[4 + ((tip - 1) * RELOP_NUMBER)],++tranga_num);}
  }
#line 1627 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 323 "micko.y" /* yacc.c:1646  */
    {

    code("\n@tranga_false%d:",tranga_num);
  }
#line 1636 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 328 "micko.y" /* yacc.c:1646  */
    {
      if(tip!=get_type((yyvsp[-1].i))){
      err("Tip tranga iskaza mora biti istog tipa kao Jiro promenjiva!");
      }
      else{
    gen_cmp(idx_switch,(yyvsp[-1].i));
    code("\n\t\t%s\t@tranga_false%d",opp_jumps[4 + ((tip - 1) * RELOP_NUMBER)],++tranga_num);}
  }
#line 1649 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 335 "micko.y" /* yacc.c:1646  */
    {
    code("\n@tranga_false%d:",tranga_num);
  }
#line 1657 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 341 "micko.y" /* yacc.c:1646  */
    { 
      if(lookup_symbol((yyvsp[0].s),JLIT)==NO_INDEX)
        (yyval.i) = insert_symbol((yyvsp[0].s), JLIT, INT ,NO_ATR, NO_ATR);
      else 
        err("Svi literali u tranga iskazu se moraju razlikovati! ('%s')",(yyvsp[0].s));
    }
#line 1668 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 349 "micko.y" /* yacc.c:1646  */
    { 
        if(lookup_symbol((yyvsp[0].s),JLIT)==NO_INDEX)
          (yyval.i) = insert_symbol((yyvsp[0].s), JLIT, UINT ,NO_ATR, NO_ATR);
        else 
          err("Svi literali u tranga iskazu se moraju razlikovati! ('%s')",(yyvsp[0].s));
    }
#line 1679 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 363 "micko.y" /* yacc.c:1646  */
    {
      dvostruka++;
     int idx=lookup_symbol((yyvsp[0].s),ITR);
     if(idx==NO_INDEX){
       if((yyvsp[-1].i)==VOID){err("Ne moze inkeremnt biti tipa void!");
       }
      else{
        idx=insert_symbol((yyvsp[0].s),ITR,(yyvsp[-1].i),(var_num+1+dvostruka),NO_ATR);
        code("\n@para%d:",++para_num);
        code("\n\t\tSUBS\t%%15,$4,%%15");
        code("\n\t\tMOV\t$0,-%d(%%14)",4*(var_num+1+dvostruka));
   
      code("\n@para_body%d:",para_num);
      }}
      
     else 
      err("Iterator '%s' vec postoji! ",(yyvsp[0].s));

     
    }
#line 1704 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 384 "micko.y" /* yacc.c:1646  */
    { 
     if(get_type(lookup_symbol((yyvsp[-6].s),ITR))!=get_type((yyvsp[0].i)))
        err("Iterator petlje '%s' i inkrement '%s' moraju biti istog tipa!",(yyvsp[-6].s),get_name((yyvsp[0].i)));

      code("\n\t\t%s\t@para_exit%d", opp_jumps[(yyvsp[-3].i)], para_num);
      code("\n@petlja%d:",para_num);
      
    }
#line 1717 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 392 "micko.y" /* yacc.c:1646  */
    {  
     code("\n\t\tADDS\t-%d(%%14),$%s,-%d(%%14)",4*(var_num+1+dvostruka),get_name((yyvsp[-3].i)),4*(var_num+1+dvostruka));
     code("\n\t\tJMP\t@para_body%d",para_num);
     code("\n@para_exit%d:",para_num);
     if(dvostruka>=1){
       dvostruka--;
       para_num--;
     }else{
       dvostruka=-1;
       para_num++;
     }
     clear_symbols(lookup_symbol((yyvsp[-9].s),ITR));
   }
#line 1735 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 408 "micko.y" /* yacc.c:1646  */
    {
   int idx=lookup_symbol((yyvsp[-2].s), VAR|PAR|ITR|GVAR);
    if(idx == NO_INDEX)      {    
      err("Promenjiva '%s' nema deklaraciju!", (yyvsp[-2].s));}
      else{
        int a=get_type(idx);
        code("\n\t\t%s\t",ar_instructions[ADD + (a-1) * AROP_NUMBER]);

        gen_sym_name(idx);
        code(",");
        code("$1");
        code(",");
        gen_sym_name(idx);
     
      }
        
  }
#line 1757 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 433 "micko.y" /* yacc.c:1646  */
    {
        int idx = lookup_symbol((yyvsp[-3].s), VAR|PAR|GVAR);
        if(idx == NO_INDEX){
          err("Promenjiva '%s' nema deklaraciju!", (yyvsp[-3].s));}
        else{
          if(get_type(idx) != get_type((yyvsp[-1].i))){
            err("Promenjiva i vrednost koja joj se dodeljuje moraju biti istog tipa!");}
           gen_mov((yyvsp[-1].i), idx);
            }
        
      }
#line 1773 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 449 "micko.y" /* yacc.c:1646  */
    {
        if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i))){
          err("Promenjive u aritmetickim operacijama moraju biti istog tipa!");}
          else{
        int a = get_type((yyvsp[-2].i));    
        code("\n\t\t%s\t", ar_instructions[(yyvsp[-1].i) + (a - 1) * AROP_NUMBER]);
        gen_sym_name((yyvsp[-2].i));
        code(",");
        gen_sym_name((yyvsp[0].i));
        code(",");
        free_if_reg((yyvsp[0].i));
        free_if_reg((yyvsp[-2].i));
        (yyval.i) = take_reg();
        gen_sym_name((yyval.i));
        set_type((yyval.i), a);

         if(get_atr2((yyvsp[-2].i))==1){
        code("\n\t\t%s\t", ar_instructions[(a - 1) * AROP_NUMBER]);
        gen_sym_name((yyvsp[-2].i));
        code(",");
        code("$1");
        code(",");
        gen_sym_name((yyvsp[-2].i));
        set_atr2((yyvsp[-2].i),0);
            }
        if(get_atr2((yyvsp[0].i))==1){
          a=get_type((yyvsp[0].i)); 
         code("\n\t\t%s\t", ar_instructions[ (a - 1) * AROP_NUMBER]);
         gen_sym_name((yyvsp[0].i));
         code(",");
        code("$1");
        code(",");
        gen_sym_name((yyvsp[0].i));
        set_atr2((yyvsp[0].i),0);
        }
        }
      }
#line 1815 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 492 "micko.y" /* yacc.c:1646  */
    {
        (yyval.i) = lookup_symbol((yyvsp[0].s), VAR|PAR|ITR|GVAR);
        if((yyval.i) == NO_INDEX)
          err("Promenjiva '%s' nema deklaraciju!", (yyvsp[0].s));
      }
#line 1825 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 498 "micko.y" /* yacc.c:1646  */
    {
    (yyval.i) = take_reg();
    gen_mov(FUN_REG, (yyval.i));
  }
#line 1834 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 503 "micko.y" /* yacc.c:1646  */
    { 
      (yyval.i)=lookup_symbol((yyvsp[-1].s), VAR|PAR|GVAR);
       if((yyval.i) == NO_INDEX)   {       
        err("Promenjiva '%s' nema deklaraciju!", (yyvsp[-1].s));}
      else 
      {
        vrsta = get_kind((yyval.i));
      if(vrsta !=VAR && vrsta !=PAR && vrsta !=GVAR){
        err("Samo varijable i parametri mogu da se inkrementuju!");}
      else{
        set_atr2((yyval.i),1);
      }
        
      }
    }
#line 1854 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 519 "micko.y" /* yacc.c:1646  */
    {
      err("Jezik ne podrzava postinkrement poziva funkcije! ('%s')",get_name(fcall_idx));
    }
#line 1862 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 523 "micko.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[-1].i); }
#line 1868 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 526 "micko.y" /* yacc.c:1646  */
    {
    code("\n\t\t%s\t@false%d", opp_jumps[(yyvsp[0].i)], ++lab_num);
    code("\n@true%d:", lab_num);
   }
#line 1877 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 531 "micko.y" /* yacc.c:1646  */
    {
      (yyval.i) =take_reg();
      gen_mov((yyvsp[-2].i),(yyval.i));
      code("\n\t\tJMP\t@exit%d",lab_num);
      code("\n@false%d:", lab_num);
      gen_mov((yyvsp[0].i),(yyval.i));

     code("\n@exit%d:", lab_num);
   }
#line 1891 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 544 "micko.y" /* yacc.c:1646  */
    {
  if(lookup_symbol((yyvsp[0].s),VAR|PAR)==NO_INDEX)
    err("Promenljiva '%s' nema deklaraciju!",(yyvsp[0].s));

    (yyval.i)=lookup_symbol((yyvsp[0].s),VAR|PAR);
}
#line 1902 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 556 "micko.y" /* yacc.c:1646  */
    { (yyval.i) = insert_literal((yyvsp[0].s), INT); }
#line 1908 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 559 "micko.y" /* yacc.c:1646  */
    { (yyval.i) = insert_literal((yyvsp[0].s), UINT); }
#line 1914 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 564 "micko.y" /* yacc.c:1646  */
    {
        fcall_idx = lookup_symbol((yyvsp[0].s), FUN);
        if(fcall_idx == NO_INDEX)
          err("'%s' nije funkcija!", (yyvsp[0].s));
      }
#line 1924 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 570 "micko.y" /* yacc.c:1646  */
    {
        if(get_atr1(fcall_idx) != (yyvsp[-1].i))
          err("Broj argumenata poziva funkcije '%s' nije ispravan!",get_name(fcall_idx));
        else
        {
          code("\n\t\t\tCALL\t%s", get_name(fcall_idx));
          code("\n\t\t\tADDS\t%%15,$%d,%%15", (yyvsp[-1].i) * 4);
          set_type(FUN_REG, get_type(fcall_idx));
          (yyval.i) = FUN_REG;
          br_arg=0;
        }
      
      }
#line 1942 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 587 "micko.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 1948 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 590 "micko.y" /* yacc.c:1646  */
    { 
      br_arg++;
      if(get_type(fcall_idx+br_arg) != get_type((yyvsp[0].i)))
        err("Tip promenjive argumenta '%s' se ne poklapa sa tipom parametra '%s' iz pozvane funkcije '%s' !",get_name((yyvsp[0].i)),get_name(fcall_idx+br_arg),get_name(fcall_idx));
        free_if_reg((yyvsp[0].i));
      code("\n\t\t\tPUSH\t");
      gen_sym_name((yyvsp[0].i));
      (yyval.i) = br_arg;
    }
#line 1962 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 600 "micko.y" /* yacc.c:1646  */
    { 
      br_arg++;
      if(get_type(fcall_idx+br_arg) != get_type((yyvsp[0].i)))
        err("Tip promenjive argumenta '%s' se ne poklapa sa tipom parametra '%s' iz pozvane funkcije '%s' !",get_name((yyvsp[0].i)),get_name(fcall_idx+br_arg),get_name(fcall_idx));
        free_if_reg((yyvsp[0].i));
      code("\n\t\t\tPUSH\t");
      gen_sym_name((yyvsp[0].i));
      (yyval.i) = br_arg;
    }
#line 1976 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 613 "micko.y" /* yacc.c:1646  */
    { code("\n@exit%d:", (yyvsp[0].i)); 
  if(get_atr2(rel1) == 1){
        
               int a = get_type(rel1);  
           	code("\n\t\t%s\t", ar_instructions[ADD + (a - 1) * AROP_NUMBER]);

           	gen_sym_name(rel1);
           	code(",");
           	code("$1");
           	code(",");
           	gen_sym_name(rel1);
    	   	set_atr2(rel1, 0);
        }
        
        if(get_atr2(rel2) == 1){
        
               int a = get_type(rel2);  
           	code("\n\t\t%s\t", ar_instructions[ADD + (a - 1) * AROP_NUMBER]);

           	gen_sym_name(rel2);
           	code(",");
           	code("$1");
           	code(",");
            gen_sym_name(rel2);
    	   	set_atr2(rel2, 0);
        }
      }
#line 2008 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 642 "micko.y" /* yacc.c:1646  */
    { code("\n@exit%d:", (yyvsp[-2].i)); }
#line 2014 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 647 "micko.y" /* yacc.c:1646  */
    {
        (yyval.i) = ++lab_num;
        code("\n@if%d:", lab_num);
        
  }
#line 2024 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 653 "micko.y" /* yacc.c:1646  */
    {
     code("\n\t\t%s\t@false%d", opp_jumps[(yyvsp[0].i)], (yyvsp[-1].i));
     code("\n@true%d:", (yyvsp[-1].i));
     
   }
#line 2034 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 658 "micko.y" /* yacc.c:1646  */
    {

     code("\n\t\tJMP \t@exit%d", (yyvsp[-4].i));
        code("\n@false%d:", (yyvsp[-4].i));
        (yyval.i) = (yyvsp[-4].i);
   }
#line 2045 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 668 "micko.y" /* yacc.c:1646  */
    {
        if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
          err("Tipovi promenjivih pri aritmetickim operacijama moraju biti isti!");
          (yyval.i) = (yyvsp[-1].i) + ((get_type((yyvsp[-2].i)) - 1) * RELOP_NUMBER);
         
        gen_cmp((yyvsp[-2].i), (yyvsp[0].i));

       if(get_atr2((yyvsp[-2].i)) == 1){
        	rel1 = (yyvsp[-2].i);
        }
        
        if(get_atr2((yyvsp[0].i)) == 1){
		rel2 = (yyvsp[0].i);
        }
        

       
      }
#line 2068 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 690 "micko.y" /* yacc.c:1646  */
    { ret=1;
        if(get_type(fun_idx)==VOID)
          err("Void funkcija ne sme da vraca vrednost!");

        else if(get_type(fun_idx) != get_type((yyvsp[-1].i)))
          err("Funkcija ne vraca vrednost odgovarajuceg tipa!");
          gen_mov((yyvsp[-1].i), FUN_REG);
        code("\n\t\tJMP \t@%s_exit", get_name(fun_idx)); 
      }
#line 2082 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 699 "micko.y" /* yacc.c:1646  */
    {
    ret=1;
    if(get_type(fun_idx)!=VOID)
      warning("Funkcija tipa INT/UNSIGNED treba da vrati vrednost odgovarajuceg tipa! ");
      
        code("\n\t\tJMP \t@%s_exit", get_name(fun_idx)); 
  }
#line 2094 "micko.tab.c" /* yacc.c:1646  */
    break;


#line 2098 "micko.tab.c" /* yacc.c:1646  */
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
#line 709 "micko.y" /* yacc.c:1906  */


int yyerror(char *s) {
  fprintf(stderr, "\nline %d: ERROR: %s", yylineno, s);
  error_count++;
  return 0;
}

void warning(char *s) {
  fprintf(stderr, "\nline %d: WARNING: %s", yylineno, s);
  warning_count++;
}

int main() {
  int synerr;
  init_symtab();
  output = fopen("output.asm", "w+");

  synerr = yyparse();

  clear_symtab();  
  fclose(output);

  if(warning_count)
    printf("\n%d warning(s).\n", warning_count);

  if(error_count)
    printf("\n%d error(s).\n", error_count);

  if(synerr) 
  return -1;
  else return error_count;
  }
