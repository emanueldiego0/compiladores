all: 			interpretador

interpretador:		lex.yy.c y.tab.o arvore.o tabela.o tabelaNumero.o
			gcc lex.yy.c y.tab.o arvore.o tabela.o tabelaNumero.o -o interpretador -g

lex.yy.c:		interpretador.lex
			lex interpretador.lex

arvore.o:		arvore.h arvore.c
			gcc arvore.c -c -o arvore.o

tabela.o:		tabela.h tabela.c
			gcc tabela.c -c -o tabela.o

tabelaNumero.o:		tabelaNumero.c tabelaNumero.h
			gcc tabelaNumero.c -c -o tabelaNumero.o

y.tab.o:		y.tab.c y.tab.h
			gcc y.tab.c -c

y.tab.c:		interpretador.yacc
			yacc interpretador.yacc -d --debug --verbose

y.tab.h:		interpretador.yacc
			yacc interpretador.yacc -d

clean:
			rm y.tab.*
			rm lex.yy.c
			rm *.o
			rm interpretador


teste: source.ccc interpretador
	./interpretador < source.ccc
