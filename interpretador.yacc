%{

#ifndef YYSTYPE
#define YYSTYPE long int
#endif

#include <stdio.h>
#include "tabela.h"
#include "arvore.h"

int yylex(void);
void yyerror(char *);

pilha_contexto *pilha;

%}

%token TYPE INT REAL PRINT NUMBER ID EXPR ATTR ADD SUB BEGIN_ END VAR PROGRAM ATT WRITE IF THEN ELSE FOR TO DO
%left ADD SUB OR
%left EQ NE GE LE GT LT
%left MULT DIVR DIVI MOD AND
%left NOT
%%


code:
			
	init var_area bloco
	;

init:
	PROGRAM ID ';'		{ 
					tabela *contexto = criar_contexto(topo_pilha(pilha));
					pilha = empilhar_contexto(pilha, contexto);
				}

var_area:
	VAR decls		{ }
	|
	;



bloco: 
	BEGIN_ 			{ 
				imprimir_contexto(topo_pilha(pilha));
				tabela *contexto = criar_contexto(topo_pilha(pilha));
				pilha = empilhar_contexto(pilha, contexto);

				 }

	stmts END		{ 
				imprimir_contexto(topo_pilha(pilha));
				desempilhar_contexto(&pilha); }
	;

decls: 
	decls decl		{ }
	|
	;

decl:
	ID ':' TYPE ';'			{	simbolo * s = criar_simbolo((char *) $1, $3);
	;					inserir_simbolo(topo_pilha(pilha), s); }

stmts: 
	stmts stmt		{	}
	| 	
	;

stmt:
	expr ';'		{	}
	| bloco
	| attr			{	}
	| print			{	}
	| cond			{	}
	| rept			{	}
	;

cond:	IF '(' expr ')' THEN stmt 	{	}
	;

rept:	FOR ID ATT NUMBER TO NUMBER DO stmt	{	}
	;

print:	WRITE '(' expr ')' ';'	{	
					no_arvore *n = (no_arvore*)$3;
					printf("%d\n",n->dado.expr->valor.dval);
				}
	;

attr: 
	ID ATT expr ';'		{ simbolo * s = localizar_simbolo(topo_pilha(pilha), (char *) $1);
				  if(s == NULL)
					yyerror("Identificador não declarado");
				  else  {
					no_arvore *n = criar_no_atribuicao(s, (void *) $3);
					$$ = (long int) n;
				  }
				}
expr:

	 NUMBER			{ no_arvore *n = criar_no_expressao(NUMBER, (void *) $1, NULL); 
				  $$ = (long int) n;
				}

	| ID			{ simbolo * s = localizar_simbolo(topo_pilha(pilha), (char *) $1);
				  if(s == NULL)
					yyerror("Identificador não declarado");
				  else  {
					no_arvore *n = criar_no_expressao(ID, s, NULL);
					$$ = (long int) n;
				  }
				}
	| expr ADD expr		{ 
					no_arvore *n = criar_no_expressao(ADD, (void *) $1, (void *) $3); 
				 	$$ = (long int) n; 
				}
	| expr SUB expr		{ no_arvore *n = criar_no_expressao(SUB, (void *) $1, (void *) $3);}

	| expr MULT expr	{ no_arvore *n = criar_no_expressao(MULT, (void *) $1, (void *) $3); 
				  $$ = (long int) n; }
	| expr DIVR expr	{ no_arvore *n = criar_no_expressao(DIVR, (void *) $1, (void *) $3);
//passa a referencia para a tabela de símbolos contextual com 
//topo_pilha(pilha) 
				  $$ = (long int) n; }
	| '(' expr ')'		{ $$ = $2; }
	; 

%%

void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}

int main(void) {
	pilha = NULL;
	yyparse();
	return 0;
}
