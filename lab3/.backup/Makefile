parser: IntermediateCode.l IntermediateCode.y GrammarTree.h
	bison -d IntermediateCode.y 
	flex IntermediateCode.l 
	gcc SemanticAnalysis.c IntermediateCode.tab.c SymbolTable.c GrammarTree.c IntermediateCode.c -lfl -ly -o parser

wc:
	wc -l GrammarTree.h GrammarTree.c  SemanticAnalysis.h SemanticAnalysis.c SymbolTable.h SymbolTable.c IntermediateCode.h IntermediateCode.c IntermediateCode.l IntermediateCode.y Makefile

backup:
	cp GrammarTree.h GrammarTree.c  SemanticAnalysis.h SemanticAnalysis.c SymbolTable.h SymbolTable.c IntermediateCode.h IntermediateCode.c IntermediateCode.l IntermediateCode.y Makefile .backup

.PHONY: clean
clean:
	rm parser IntermediateCode.tab.c IntermediateCode.tab.h lex.yy.c
