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
    INT = 259,
    REAL = 260,
    PRINT = 261,
    NUMBER = 262,
    ID = 263,
    EXPR = 264,
    ATTR = 265,
    ADD = 266,
    SUB = 267,
    BEGIN_ = 268,
    END = 269,
    VAR = 270,
    PROGRAM = 271,
    ATT = 272,
    WRITE = 273,
    IF = 274,
    THEN = 275,
    ELSE = 276,
    FOR = 277,
    TO = 278,
    DO = 279,
    OR = 280,
    EQ = 281,
    NE = 282,
    GE = 283,
    LE = 284,
    GT = 285,
    LT = 286,
    MULT = 287,
    DIVR = 288,
    DIVI = 289,
    MOD = 290,
    AND = 291,
    NOT = 292
  };
#endif
/* Tokens.  */
#define TYPE 258
#define INT 259
#define REAL 260
#define PRINT 261
#define NUMBER 262
#define ID 263
#define EXPR 264
#define ATTR 265
#define ADD 266
#define SUB 267
#define BEGIN_ 268
#define END 269
#define VAR 270
#define PROGRAM 271
#define ATT 272
#define WRITE 273
#define IF 274
#define THEN 275
#define ELSE 276
#define FOR 277
#define TO 278
#define DO 279
#define OR 280
#define EQ 281
#define NE 282
#define GE 283
#define LE 284
#define GT 285
#define LT 286
#define MULT 287
#define DIVR 288
#define DIVI 289
#define MOD 290
#define AND 291
#define NOT 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
