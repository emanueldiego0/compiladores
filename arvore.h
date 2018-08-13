#ifndef ARVORE_H
#define ARVORE_H

#include <string.h>
#include "tabela.h"
#include "y.tab.h"

typedef struct t_expr {
	int op;
	int tipo; //float ou int
	void *dir, *esq;
	//valor valor;
} t_expr;

typedef struct t_cond {
	void *logica; 
	void *_if;
	void *_else;
} t_cond;

typedef struct t_rept {
	void *cond;
	void *corpo;
} t_rept;

typedef struct t_expr_log {
	int op;
	void *dir, *esq;
} t_expr_log;

typedef struct t_attr {
	simbolo *resultado;
	void *expressao;
} t_attr;

typedef struct t_stmt {
	void *stmt;
} t_stmt;

typedef struct t_stmts {
	//O tipo da declaração a direita é o stmt
	void *stmt_e, *stmt_d;
} t_stmts;

typedef struct t_bloco {
	void *corpo;
} t_bloco;

typedef struct t_writeln {
	void *expr;
} t_writeln;

typedef struct t_read {
	void *id;
} t_read;

typedef struct t_program {
	void *program_e, *program_d;
} t_program;

typedef union valor_sintatico {
	t_expr *expr;
	t_attr *attr;
	t_cond *cond;
	t_rept *rept;
	t_program *program;
	t_bloco *bloco;
	t_stmts *stmts;
	t_stmt *stmt;
	t_expr_log *expr_log;
	t_writeln *writeln;
	t_read *read;
} valor_sintatico;

typedef struct no_arvore {
	int tipo; //expr, attr, stmt, ...
	valor_sintatico dado;
	//ponteiro para tabela de símbolos
} no_arvore;

no_arvore * criar_no_expressao(int op, void *dir, void *esq);
t_expr * criar_expressao(int op, void *dir, void *esq);

no_arvore * criar_no_atribuicao(simbolo *resultado, void *expressao);
t_attr * criar_atribuicao(simbolo *resultado, void *expressao);

no_arvore * criar_no_expr_log(int op, void *dir, void *esq);
t_expr_log * criar_expr_log(int op, void *dir, void *esq);

no_arvore * criar_no_stmt(void *stmt);
t_stmt * criar_stmt(void *stmt);

no_arvore * criar_no_stmts(void *stmts, void *stmt);
t_stmts * criar_stmts(void *stmts, void *stmt);

no_arvore * criar_no_condicional(void *logica, void *_if, void *_else);
t_cond * criar_condicional(void *logica, void *_if, void *_else);

no_arvore * criar_no_rept(void *cond, void *corpo);
t_rept * criar_rept(void *cond, void *corpo);

no_arvore * criar_no_writeln(void *expr);
t_writeln * criar_writeln(void *expr);

no_arvore * criar_no_read(void *id);
t_read * criar_read(void *id);

no_arvore * criar_no_bloco(void *stmts);
t_bloco * criar_bloco(void *stmts);

no_arvore * criar_no_program(void *program_e, void *program_d);
t_program * criar_program(void *program_e, void *program_d);


#endif
