/*************************************************************************
	> File Name: GrammarTree.c
	> Author: GuanyuLi
	> Mail: guanyuli@hustunique.com
	> Created Time: Tue 22 Nov 2016 02:40:28 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>
#include"GrammarTree.h"

void yyerror(char *info, ...)
{
    va_list ap;
    va_start(ap, info);
    fprintf(stderr, "%d: error:", yylineno);
    vfprintf(stderr, info, ap);
    fprintf(stderr, "\n");
}

GrammarTree CreateGrammarTree(char* name, int num, ...)
{
    int i;
    char* cache;
    va_list varibles;
    GrammarTree current = (GrammarTree)malloc(sizeof(GrammarTreeNode));
    GrammarTree tmp;
    current->name = name;
    va_start(varibles, num);
    if (num > 0)
    {
        tmp = va_arg(varibles, GrammarTree);
        current->lchild = tmp;
        current->line = tmp->line;
        for (i = 0; i < num - 1; i++)
        {
            tmp->rchild = va_arg(varibles, GrammarTree);
            tmp = tmp->rchild;
        }
    }
    else
    {
        current->line = va_arg(varibles, int);
        if (!strcmp(current->name, "IDENTIFIER"))
        {
            cache = (char *)malloc(sizeof(char) * MAXSTRING);
            strcpy(cache, yytext);
            current->string_value = cache;
        }
        else  if (!strcmp(current->name, "CONSTANTINTD"))
        {
            current->int_value = atoi(yytext);
        }
    }
    return current;
}

void TraverseGrammerTree(GrammarTree gmtree, int level)
{
    int i;
    if (gmtree != NULL)
    {
        for (i = 0; i < level; i++)
            printf("  ");
        if (gmtree->line != -1)
        {
            printf("%s", gmtree->name);
            if (!strcmp(gmtree->name, "IDENTIFIER"))
                printf(": %s\n", gmtree->string_value);
            else if (!strcmp(gmtree->name, "CONSTANTINTD"))
                printf(": %d\n", gmtree->int_value);
            else
                printf(" (%d)\n", gmtree->line);
        }
    }
    TraverseGrammerTree(gmtree->lchild, level + 1);
    TraverseGrammerTree(gmtree->rchild, level);
}

int main(int argc, char** argv)
{
    if (argc > 1)
    {
        if (!(yyin = fopen(argv[1], "r")))
        {
            perror(argv[1]);
            return 1;
        }
    }
    yyparse();
    return 0;
}
