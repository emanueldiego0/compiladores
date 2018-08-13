%{

/*
#ifdef __STDC_ALLOC_LIB__
#define __STDC_WANT_LIB_EXT2__ 1
#else
#define _POSIX_C_SOURCE 200809L
#endif*/

#ifndef YYSTYPE
#define YYSTYPE long int
#endif

#include <stdlib.h>
#include "tabela.h"
#include "tabelaNumero.h"
void yyerror(char *);
#include "y.tab.h"
%}

letra	[a-z|A-Z|_] 
numero	[0-9]
identificador	{letra}({letra}|{numero})*

%%


{numero}+	   { 
	valor v;
	v.dval = atoi(yytext);
	yylval = (long int) criar_numero(v, INTEGER);
	return NUMBER;
}

{numero}+"."{numero}+	  { 
	valor v;
	v.fval = atof(yytext);
	yylval = (long int) criar_numero(v, REAL);
	return NUMBER;
}


integer		{	yylval = INTEGER;
			return TYPE;
		}
real		{
			yylval = REAL;
			return TYPE;
		}

"if"		{	return IF;
		}

"else"		{	return ELSE;
		}

"then"		{	return THEN;
		}

"while"		{	return WHILE;
		}

"do"		{	return DO;
		}

":="		{	return ATT;
		}

"program"	{
			return PROGRAM;
		}

"var"		{
			return VAR;
		}

"begin"		{
			return BEGIN_;
		}

"end"		{
			return END;
		}		

"+"			{return ADD;}
"-"			{return SUB;}
"*"			{return MULT;}
"/"			{return DIVR;}
"div"			{return DIVI;}
"mod"			{return MOD;}

"="			{return EQ;}
"<>"			{return NE;}
">"			{return GT;}
"<"			{return LT;}
">="			{return GE;}
"<="			{return LE;}

"and"			{return AND;}
"or"			{return OR;}
"not"			{return NOT;}


{identificador}	{
			yylval = (long int) strdup(yytext);
			return ID;
		}	

":"		{	return *yytext; }

[-+=();]	{	return *yytext; }




[ \t\n] 	; /* skip whitespace */
. 	yyerror("invalid character");
%%
int yywrap(void) {
return 1;
}
