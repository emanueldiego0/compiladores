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
    TYPE = 258,
    REAL = 259,
    INTEGER = 260,
    ID = 261,
    BEGIN_ = 262,
    END = 263,
    WHILE = 264,
    DO = 265,
    IF = 266,
    ELSE = 267,
    THEN = 268,
    EXPR = 269,
    ATTR = 270,
    VAR = 271,
    STMT = 272,
    STMTS = 273,
    BLOCO = 274,
    PROGRAM = 275,
    EXPR_LOG = 276,
    COND = 277,
    REPT = 278,
    ATT = 279,
    ADD = 280,
    SUB = 281,
    OR = 282,
    MULT = 283,
    DIVR = 284,
    DIVI = 285,
    MOD = 286,
    AND = 287,
    EQ = 288,
    NE = 289,
    GE = 290,
    LE = 291,
    GT = 292,
    LT = 293,
    NOT = 294,
    NUMBER = 295,
    UMINUS = 296
  };
#endif
/* Tokens.  */
#define TYPE 258
#define REAL 259
#define INTEGER 260
#define ID 261
#define BEGIN_ 262
#define END 263
#define WHILE 264
#define DO 265
#define IF 266
#define ELSE 267
#define THEN 268
#define EXPR 269
#define ATTR 270
#define VAR 271
#define STMT 272
#define STMTS 273
#define BLOCO 274
#define PROGRAM 275
#define EXPR_LOG 276
#define COND 277
#define REPT 278
#define ATT 279
#define ADD 280
#define SUB 281
#define OR 282
#define MULT 283
#define DIVR 284
#define DIVI 285
#define MOD 286
#define AND 287
#define EQ 288
#define NE 289
#define GE 290
#define LE 291
#define GT 292
#define LT 293
#define NOT 294
#define NUMBER 295
#define UMINUS 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
