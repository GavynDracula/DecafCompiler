parser: GrammarTree.l GrammarTree.y GrammarTree.h
	bison -d -v GrammarTree.y
	flex GrammarTree.l
	gcc GrammarTree.c GrammarTree.tab.c -lfl -ly -o parser

.PHONY: clean
clean:
	rm parser GrammarTree.tab.c GrammarTree.tab.h lex.yy.c
