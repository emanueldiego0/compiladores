#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"
#include "y.tab.h"

//Expressao INICIO
no_arvore * criar_no_expressao(int op, void *dir, void *esq) {
	no_arvore *novo = (no_arvore *)  malloc(sizeof(no_arvore));
	novo->tipo = EXPR;
	novo->dado.expr =  criar_expressao(op, dir, esq);
	return novo;
}

t_expr * criar_expressao(int op, void *dir, void *esq) {
	t_expr * novo = (t_expr *) malloc(sizeof(t_expr));
	novo->op = op;
	novo->dir = dir;
	novo->esq = esq;
	return novo;
}
//Expressao FIM

//Atribuicao INICIO
no_arvore * criar_no_atribuicao(simbolo *resultado, void *expressao) {
	no_arvore *novo = (no_arvore *)  malloc(sizeof(no_arvore));
	novo->tipo = ATTR;
	novo->dado.attr =  criar_atribuicao(resultado, expressao);
	return novo;
}

t_attr * criar_atribuicao(simbolo *resultado, void *expressao){ 
	t_attr * novo = (t_attr *) malloc(sizeof(t_attr));
	novo->resultado = resultado;
	novo->expressao = expressao;
	return novo;
}
//Atribuicao FIM

//Expressao logica INICIO
no_arvore * criar_no_expr_log(int op, void *dir, void *esq) {
	no_arvore *novo = (no_arvore *)  malloc(sizeof(no_arvore));
	novo->tipo = EXPR_LOG;
	novo->dado.expr_log =  criar_expr_log(op, dir, esq);
	return novo;
}

t_expr_log * criar_expr_log(int op, void *dir, void *esq){ 
	t_expr_log * novo = (t_expr_log *) malloc(sizeof(t_expr_log));
	novo->op = op;
	novo->dir = dir;
	novo->esq = esq;
	return novo;
}
//Expressao logica FIM

//Stmt INICIO
no_arvore * criar_no_stmt(void *stmt) {
	no_arvore *novo = (no_arvore *)  malloc(sizeof(no_arvore));
	novo->tipo = STMT;
	novo->dado.stmt =  criar_stmt(stmt);
	return novo;
}
t_stmt * criar_stmt(void *stmt){ 
	t_stmt * novo = (t_stmt *) malloc(sizeof(t_stmt));
	novo->stmt = stmt;
	return novo;
}
//Stmt FIM

//Stmts INICIO
no_arvore * criar_no_stmts(void *stmts, void *stmt) {
	no_arvore *novo = (no_arvore *)  malloc(sizeof(no_arvore));
	novo->tipo = STMTS;
	novo->dado.stmts =  criar_stmts(stmts, stmt);
	return novo;
}
t_stmts * criar_stmts(void *stmts, void *stmt){ 
	t_stmts * novo = (t_stmts *) malloc(sizeof(t_stmts));
	novo->stmt_d = stmt;
	novo->stmt_e = stmts;
	return novo;
}
//Stmts FIM

//Bloco INICIO
no_arvore * criar_no_bloco(void* stmts) {
	no_arvore *novo = (no_arvore *)  malloc(sizeof(no_arvore));
	novo->tipo = BLOCO;
	novo->dado.bloco =  criar_bloco(stmts);
	return novo;
}
t_bloco * criar_bloco(void* stmts){ 
	t_bloco * novo = (t_bloco *) malloc(sizeof(t_bloco));
	novo->corpo = stmts;
	return novo;
}
//Bloco FIM

//Program INICIO
no_arvore * criar_no_program(void *program_e, void *program_d) {
	no_arvore *novo = (no_arvore *)  malloc(sizeof(no_arvore));
	novo->tipo = PROGRAM;
	novo->dado.program =  criar_program(program_e, program_d);
	return novo;
}
t_program * criar_program(void *program_e, void *program_d){ 
	t_program * novo = (t_program *) malloc(sizeof(t_program));
	novo->program_d = program_d;
	novo->program_e = program_e;
	return novo;
}
//Program FIM

//Condicional INICIO
no_arvore * criar_no_condicional(void *logica, void *_if, void *_else) {
	no_arvore *novo = (no_arvore *)  malloc(sizeof(no_arvore));
	novo->tipo = COND;
	novo->dado.cond =  criar_condicional(logica, _if, _else);
	return novo;
}
t_cond * criar_condicional(void *logica, void *_if, void *_else){ 
	t_cond * novo = (t_cond *) malloc(sizeof(t_cond));
	novo->logica = logica;
	novo->_if = _if;
	novo->_else = _else;
	return novo;
}
//Condicional FIM

//Repeticao INICIO
no_arvore * criar_no_rept(void *cond, void *corpo){
	no_arvore *novo = (no_arvore *)  malloc(sizeof(no_arvore));
	novo->tipo = REPT;
	novo->dado.rept =  criar_rept(cond, corpo);
	return novo;
}
t_rept * criar_rept(void *cond, void *corpo){ 
	t_rept * novo = (t_rept *) malloc(sizeof(t_rept));
	novo->cond = cond;
	novo->corpo = corpo;
	return novo;
}
//Repeticao FIM

//WriteLn INICIO
no_arvore * criar_no_writeln(void *expr){
	no_arvore *novo = (no_arvore *)  malloc(sizeof(no_arvore));
	novo->tipo = WRITELN;
	novo->dado.writeln =  criar_writeln(expr);
	return novo;
}

t_writeln * criar_writeln(void *expr){ 
	t_writeln * novo = (t_writeln *) malloc(sizeof(t_writeln));
	novo->expr = expr;
	return novo;
}
//WriteLn FIM

//Read INICIO
no_arvore * criar_no_read(void *id){
	no_arvore *novo = (no_arvore *)  malloc(sizeof(no_arvore));
	novo->tipo = READ;
	novo->dado.read =  criar_read(id);
	return novo;
}
t_read * criar_read(void *id){ 
	t_read * novo = (t_read *) malloc(sizeof(t_read));
	novo->id = id;
	return novo;
}
//Read FIM
