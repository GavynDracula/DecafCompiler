gdcf: Decaf.l Decaf.y GrammarTree.h
	bison -d Decaf.y 
	flex Decaf.l 
	gcc SemanticAnalysis.c Decaf.tab.c SymbolTable.c GrammarTree.c IntermediateCode.c ObjectCode.c main.c -lfl -ly -o gdcf 

wc:
	wc -l GrammarTree.h GrammarTree.c  SemanticAnalysis.h SemanticAnalysis.c SymbolTable.h SymbolTable.c IntermediateCode.h IntermediateCode.c ObjectCode.h ObjectCode.c Decaf.l Decaf.y main.h main.c Makefile

backup:
	cp GrammarTree.h GrammarTree.c  SemanticAnalysis.h SemanticAnalysis.c SymbolTable.h SymbolTable.c IntermediateCode.h IntermediateCode.c ObjectCode.h ObjectCode.c Decaf.l Decaf.y main.h main.c Makefile .backup

.PHONY: clean
clean:
	rm gdcf Decaf.tab.c Decaf.tab.h lex.yy.c *.asm *.text
