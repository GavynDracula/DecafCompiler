/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 18 "SemanticAnalysis.y" /* yacc.c:1909  */

    GrammarTree grammar_tree;

#line 113 "SemanticAnalysis.tab.h" /* yacc.c:1909  */
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
