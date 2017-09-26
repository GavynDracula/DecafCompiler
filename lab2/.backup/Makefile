parser: SemanticAnalysis.l SemanticAnalysis.y GrammarTree.h
	bison -d SemanticAnalysis.y 
	flex SemanticAnalysis.l 
	gcc SemanticAnalysis.c SemanticAnalysis.tab.c SymbolTable.c GrammarTree.c -lfl -ly -o parser

wc:
	wc -l GrammarTree.h GrammarTree.c  SemanticAnalysis.h SemanticAnalysis.c SemanticAnalysis.l SemanticAnalysis.y SymbolTable.h SymbolTable.c Makefile

backup:
	cp GrammarTree.h GrammarTree.c  SemanticAnalysis.h SemanticAnalysis.c SemanticAnalysis.l SemanticAnalysis.y SymbolTable.h SymbolTable.c Makefile test.decaf .backup

.PHONY: clean
clean:
	rm parser SemanticAnalysis.tab.c SemanticAnalysis.tab.h lex.yy.c
