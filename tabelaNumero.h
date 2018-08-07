#ifndef TABELA_NUMERO_H
#define TABELA_NUMERO_H
#include "tabela.h"

typedef struct numero {
	int tipo;
	valor val;
} numero;

numero *  criar_numero (valor val, int tipo);

#endif
