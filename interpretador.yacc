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

%token TYPE REAL INTEGER ID BEGIN_ END
%token WHILE DO
%token IF ELSE THEN
%token EXPR ATTR VAR STMT STMTS BLOCO PROGRAM EXPR_LOG COND REPT ATT WRITELN READ
%left ADD SUB OR
%left MULT DIVR DIVI MOD AND
%left EQ NE GE LE GT LT
%left NOT
%token NUMBER
%right UMINUS


%%


code:
			
	init var_area bloco
	|
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
	//decls			{ }
	BEGIN_ 			{ 
					imprimir_contexto(topo_pilha(pilha));
					tabela *contexto = criar_contexto(topo_pilha(pilha));
					pilha = empilhar_contexto(pilha, contexto);
				}
	
			
	var_area stmts END	{ 
					imprimir_contexto(topo_pilha(pilha));
					desempilhar_contexto(&pilha); 
				
					no_arvore *n = criar_no_bloco((void *) $2);
					$$ = (long int) n;
				}
	;

decls: 
	decls decl		{ }
	|
	;

decl:
	ID ':' TYPE ';'			{	
			simbolo * s = localizar_simbolo_contexto_topo(topo_pilha(pilha), (char *) $1);
			if(s == NULL) {
				simbolo * s = criar_simbolo((char *) $1, $3);
				inserir_simbolo(topo_pilha(pilha), s); 
			} else 	{
				yyerror("Identificador já declarado");
				}
	}
	;

stmts: 
	stmts stmt		{
				no_arvore *n = criar_no_stmts((void *) $1, (void *) $2);
				$$ = (long int)n;				
				}
	| 	
	;

stmt:
	expr ';'	{
			no_arvore *n = criar_no_stmt((void *) $1);
			$$ = (long int) n;
			}
	| bloco		{
			no_arvore *n = criar_no_stmt((void *) $1);
			$$ = (long int) n;
			}
	| attr		{
			no_arvore *n = criar_no_stmt((void *) $1);
			$$ = (long int) n;
			}
	| cond		{
			no_arvore *n = criar_no_stmt((void *) $1);
			$$ = (long int) n;
			}
	| rept		{
			no_arvore *n = criar_no_stmt((void *) $1);
			$$ = (long int) n;
			}
	| write		{
			no_arvore *n = criar_no_writeln((void *) $1);
			$$ = (long int) n;
			}
	| read		{
			no_arvore *n = criar_no_read((void *) $1);
			$$ = (long int) n;
			}
			
	;

write:	WRITELN '(' expr ')'';'	{ no_arvore *n = criar_no_writeln((void *) $3); 
					$$ = (long int) n;}	
	;

read:	READ '(' ID ')'';'		{
					simbolo* s = localizar_simbolo(topo_pilha(pilha), (char*) $3);
        				if(s != NULL){
				            no_arvore* n = criar_no_read(s);
			        	    $$ = (long int) n;
				        }else{
            					yyerror("Identificador não declarado");
        				}
        
				}
	;

cond:	IF '(' expr_log ')' THEN stmt 	
			{
			no_arvore *n = criar_no_condicional((void *) $3, (void *) $6, NULL);
			$$ = (long int) n;
			}
	| IF '(' expr_log ')' THEN stmt ELSE stmt
			{
			no_arvore *n = criar_no_condicional((void *) $3, (void *) $6, (void *) $8);
			$$ = (long int) n;
			}
	;

rept:	WHILE '(' expr_log ')' DO stmt
			{
			no_arvore *n = criar_no_rept((void *) $2, (void *) $4);
			$$ = (long int) n;
			}
	;

expr_log:	expr LT expr
			{
			no_arvore *n = criar_no_expr_log(LT, (void *) $1, (void *) $3);
			$$ = (long int) n;
			}
		| expr LE expr
			{
			no_arvore *n = criar_no_expr_log(LE, (void *) $1, (void *) $3);
			$$ = (long int) n;
			}
		| expr EQ expr
			{
			no_arvore *n = criar_no_expr_log(EQ, (void *) $1, (void *) $3);
			$$ = (long int) n;
			}
		| expr NE expr
			{
			no_arvore *n = criar_no_expr_log(NE, (void *) $1, (void *) $3);
			$$ = (long int) n;
			}
		| expr GT expr
			{
			no_arvore *n = criar_no_expr_log(GT, (void *) $1, (void *) $3);
			$$ = (long int) n;
			}

		| expr GE expr
			{
			no_arvore *n = criar_no_expr_log(GE, (void *) $1, (void *) $3);
			$$ = (long int) n;
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
				;
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

				no_arvore * no_direita = (no_arvore *) $1;
				t_expr *dir = no_direita->dado.expr;

				no_arvore * no_esquerda = (no_arvore *) $3;
				t_expr *esq = no_esquerda->dado.expr;
			

				if(esq->tipo == REAL || dir->tipo == REAL)
					n->tipo = REAL;
				else
					n->tipo = INTEGER;
				$$ = (long int) n; 
				}
	| expr SUB expr		{
				no_arvore *n = criar_no_expressao(SUB, (void *) $1, (void *) $3);

				no_arvore * no_direita = (no_arvore *) $1;
				t_expr *dir = no_direita->dado.expr;

				no_arvore * no_esquerda = (no_arvore *) $3;
				t_expr *esq = no_esquerda->dado.expr;
			

				if(esq->tipo == REAL || dir->tipo == REAL)
					n->tipo = REAL;
				else
					n->tipo = INTEGER;
				$$ = (long int) n;
				}

	| expr MULT expr	{
				no_arvore *n = criar_no_expressao(MULT, (void *) $1, (void *) $3);

				no_arvore * no_direita = (no_arvore *) $1;
				t_expr *dir = no_direita->dado.expr;

				no_arvore * no_esquerda = (no_arvore *) $3;
				t_expr *esq = no_esquerda->dado.expr;
			

				if(esq->tipo == REAL || dir->tipo == REAL)
					n->tipo = REAL;
				else
					n->tipo = INTEGER;
				$$ = (long int) n;
				}
	| expr DIVR expr	{ no_arvore *n = criar_no_expressao(DIVI, (void *) $1, (void *) $3);

				no_arvore * no_direita = (no_arvore *) $1;
				t_expr *dir = no_direita->dado.expr;

				no_arvore * no_esquerda = (no_arvore *) $3;
				t_expr *esq = no_esquerda->dado.expr;
			

				if(esq->tipo == REAL || dir->tipo == REAL)
					n->tipo = REAL;
				else
					n->tipo = INTEGER;
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
