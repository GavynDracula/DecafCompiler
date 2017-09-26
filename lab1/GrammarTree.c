/*************************************************************************
	> File Name: GrammarTree.c
	> Author: GuanyuLi
	> Mail: guanyuli@hustunique.com
	> Created Time: Tue 22 Nov 2016 02:40:28 PM CST
 ************************************************************************/

#include"GrammarTree.h"

extern int two_tuples_trigger;

GrammarTree CreateGrammarTree(char* name, int num, ...)
{
    int i;
    char* cache;
    va_list variables;       
    GrammarTree current = (GrammarTree)malloc(sizeof(GrammarTreeNode));     //Create node for current grammar unit
    GrammarTree tmp;
    current->name = name;
    va_start(variables, num);           // Init the variable parameter list
    if (num > 0)
    {
        tmp = va_arg(variables, GrammarTree);
        current->lchild = tmp;
        current->line = tmp->line;      // Current grammar unit's line number is equal to its left child's
        for (i = 0; i < num - 1; i++)
        {                               // Brothers
            tmp->rchild = va_arg(variables, GrammarTree);
            tmp = tmp->rchild;
        }
        // Modify the line number when reduce using rule "Stmt->SimpleStmt" and SimpleStmt is Epsilon
        if (!strcmp(current->lchild->name, "SimpleStmt") && current->lchild->line == -1)
            current->line = current->lchild->rchild->line;
    }
    else
    {   // This grammar unit is terminal or void rule
        current->line = va_arg(variables, int);
        if (!strcmp(current->name, "IDENTIFIER"))
        {
            cache = (char *)malloc(sizeof(char) * strlen(yytext));
            strcpy(cache, yytext);
            current->string_value = cache;
        }
        else  if (!strcmp(current->name, "CONSTANTINTD"))
        {
            current->int_value = atoi(yytext);
        }
        else  if (!strcmp(current->name, "CONSTANTINTH"))
        {
            current->int_value = strtol(yytext, NULL, 16);
        }
        else  if (!strcmp(current->name, "CONSTANTFLOAT"))
        {
            current->float_value = atof(yytext);
        }
        else  if (!strcmp(current->name, "CONSTANTFLOATSC"))
        {
            current->float_value = atof(yytext);
        }
        else  if (!strcmp(current->name, "CONSTANTBOOL"))
        {
            cache = (char *)malloc(sizeof(char) * strlen(yytext));
            strcpy(cache, yytext);
            current->string_value = cache;
        }
        else  if (!strcmp(current->name, "CONSTANTSTRING"))
        {
            cache = (char *)malloc(sizeof(char) * strlen(yytext));
            strcpy(cache, yytext);
            current->string_value = cache;
        }
        else  if (!strcmp(current->name, "CONSTANTNULL"))
        {
            cache = (char *)malloc(sizeof(char) * strlen(yytext));
            strcpy(cache, yytext);
            current->string_value = cache;
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
            // Not void rule
            printf("%s", gmtree->name);
            if (!strcmp(gmtree->name, "IDENTIFIER"))
                printf(": %s\n", gmtree->string_value);
            else if (!strcmp(gmtree->name, "CONSTANTINTD"))
                printf(": %d\n", gmtree->int_value);
            else if (!strcmp(gmtree->name, "CONSTANTINTH"))
                printf(": %d\n", gmtree->int_value);
            else if (!strcmp(gmtree->name, "CONSTANTFLOAT"))
                printf(": %f\n", gmtree->float_value);
            else if (!strcmp(gmtree->name, "CONSTANTFLOATSC"))
                printf(": %f\n", gmtree->float_value);
            else if (!strcmp(gmtree->name, "CONSTANTBOOL"))
                printf(": %s\n", gmtree->string_value);
            else if (!strcmp(gmtree->name, "CONSTANTSTRING"))
                printf(": %s\n", gmtree->string_value);
            else if (!strcmp(gmtree->name, "CONSTANTNULL"))
                printf(": %s\n", gmtree->string_value);
            else
                printf(" (%d)\n", gmtree->line);
        }
        else
            printf("%s (Epsilon)\n", gmtree->name);
        TraverseGrammerTree(gmtree->lchild, level + 1);
        TraverseGrammerTree(gmtree->rchild, level);
    }
}

int main(int argc, char** argv)
{
    gmerror = 0;
    if (argc > 1)
    {
        if (!(yyin = fopen(argv[1], "r")))
        {
            perror(argv[1]);
            return 1;
        }
    }
    if (two_tuples_trigger)
    {
        printf("\nNow print the two-tuples of \"Lexical Analyzing\":\n");
        printf("__________________________________________________\n\n");
    }
    yyparse();
    return 0;
}
