/*************************************************************************
	> File Name: SymbolTable.c
	> Author: GuanyuLi
	> Mail: guanyuli@hustunique.com
	> Created Time: Fri 25 Nov 2016 11:21:05 AM CST
 ************************************************************************/

#include"SymbolTable.h"

LocalScope AddIntoLocal(LocalScope local_symtable, char* name, DecafCategory category, char* type, LocalScope embededscope)
{
    char* cache = (char*)malloc(sizeof(char) * strlen(name));
    strcpy(cache, name);
    LocalScope tmp = (LocalScope)malloc(sizeof(LocalScopeEntry));
    tmp->name = cache;
    tmp->category = category;
    cache = (char*)malloc(sizeof(char) * strlen(type));
    strcpy(cache, type);
    tmp->type = cache;
    tmp->embededscope = embededscope;
    tmp->next = local_symtable;
    return tmp;
}

FormalScope AddIntoFormal(FormalScope formal_symtable, char* name, char* type, LocalScope functionscope)
{
    char* cache = (char*)malloc(sizeof(char) * strlen(name));
    strcpy(cache, name);
    FormalScope tmp = (FormalScope)malloc(sizeof(FormalScopeEntry));
    tmp->name = cache;
    cache = NULL;
    if (type)
    {
        cache = (char*)malloc(sizeof(char) * strlen(type));
        strcpy(cache, type);
    }
    tmp->type = cache;
    tmp->functionscope = functionscope;
    tmp->next = formal_symtable;
    return tmp;
}

ClassScope AddIntoClass(ClassScope class_symtable, char* name, DecafCategory category, char* type, Depictor depictor)
{
    char* cache = (char*)malloc(sizeof(char) * strlen(name));
    strcpy(cache, name);
    ClassScope tmp = (ClassScope)malloc(sizeof(ClassScopeEntry));
    tmp->name = cache;
    tmp->category = category;
    cache = (char*)malloc(sizeof(char) * strlen(type));
    strcpy(cache, type);
    tmp->type = cache;
    tmp->depictor = depictor;
    tmp->next = class_symtable;
    return tmp;
}

GlobalScope AddIntoGlobal(GlobalScope global_symtable, char* name, Depictor depictor)
{
    char* cache = (char*)malloc(sizeof(char) * strlen(name));
    strcpy(cache, name);
    GlobalScope tmp = (GlobalScope)malloc(sizeof(GlobalScopeEntry));
    tmp->name = cache;
    tmp->category = Class;
    tmp->depictor = depictor;
    tmp->next = global_symtable;
    return tmp;
}

LocalScope MergeLocalScope(LocalScope l1, LocalScope l2)
{
    LocalScope tmp = l1;
    if (!tmp)
        return l2;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = l2;
    return l1;
}

ClassScope MergeClassScope(ClassScope s1, ClassScope s2)
{
    ClassScope tmp = s1;
    if (!tmp)
        return s2;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = s2;
    return s1;
}

Depictor CreateClassDepictor(char* parentname, ClassScope classscope)
{
    char* cache = NULL;
    Depictor depictor;
    depictor.classdsp = (ClassDepictor)malloc(sizeof(ClassDepictorEntry));
    if (parentname)
    {
        cache = (char*)malloc(sizeof(char) * strlen(parentname));
        strcpy(cache, parentname);
    }
    depictor.classdsp->parentname  = cache;
    depictor.classdsp->classscope = classscope;
    return depictor;
}

Depictor CreateFunctionDepictor(int isstatic, char* name, FormalScope formalscope)
{
    Depictor depictor;
    depictor.funcdsp = (FunctionDepictor)malloc(sizeof(FunctionDepictorEntry));
    depictor.funcdsp->isstatic = isstatic;
    if (!strcmp(name, "main"))
        depictor.funcdsp->ismain = 1;
    else
        depictor.funcdsp->ismain = 0;
    depictor.funcdsp->formalscope = formalscope;
    return depictor;
}

void AddThisType(ClassScope class_symtable, char* class_name)
{
    char* cache = (char*)malloc(sizeof(char) * (6 + strlen(class_name)));
    strcpy(cache, "class:");
    strcat(cache, class_name);
    while (class_symtable)
    {
        if (class_symtable->category == Function)
        {
            class_symtable->depictor.funcdsp->formalscope->type = cache;
        }
        class_symtable = class_symtable->next;
    }
}

void AddLocalIntoFormal(FormalScope formal_symtable, LocalScope local_symtable)
{
    while (formal_symtable)
    {
        formal_symtable->functionscope = local_symtable;
        formal_symtable = formal_symtable->next;
    }
}

void AddClassParent(GlobalScope global_symtable)
{
    GlobalScope tmp;
    GlobalScope first = global_symtable;
    while (global_symtable)
    {
        if (global_symtable->depictor.classdsp->parentname)
        {
            tmp = first;
            while (tmp)
            {
                if (!strcmp(global_symtable->depictor.classdsp->parentname, tmp->name))
                {
                    global_symtable->depictor.classdsp->parent = tmp->depictor.classdsp;
                    break;
                }
                tmp = tmp->next;
            }
        }
        global_symtable = global_symtable->next;
    }
}

void DisplayLocalScope(LocalScope local_symtable, char* table)
{
    char* cache;
    LocalScope first = local_symtable;
    printf("%s Local Scope Symbol Table\n", table);
    printf("┌────────────┬────────┬────────────┬────────────┐\n");
    printf("│Name        │Category│Type        │EmbededScope│\n");
    while(local_symtable)
    {
        printf("├────────────┼────────┼────────────┼────────────┤\n");
        printf("│%12s", local_symtable->name);
        switch (local_symtable->category)
        {
            case Class:
                printf("│Class   ");
                break;
            case Variable:
                printf("│Variable");
                break;
            case Function:
                printf("│Function");
                break;
            case Block:
                printf("│Block   ");
                break;
        }
        printf("│%12s", local_symtable->type);
        if (local_symtable->embededscope)
            printf("│      ──────┼──────> Block %s Local Scope Symbol Table\n", local_symtable->name);
        else 
            printf("│         Nil│\n");
        local_symtable = local_symtable->next;
    }
    printf("└────────────┴────────┴────────────┴────────────┘\n\n");
    local_symtable = first;
    while(local_symtable)
    {
        if (local_symtable->embededscope)
        {
            cache = (char*)malloc(sizeof(char) * 12);
            sprintf(cache, "Block %s", local_symtable->name);
            DisplayLocalScope(local_symtable->embededscope, cache);
        }
        local_symtable = local_symtable->next;
    }
}

void DisplayFormalScope(FormalScope formal_symtable, char* table)
{
    FormalScope first = formal_symtable;
    char* cache = (char*)malloc(sizeof(char) * (strlen(table) + 14));
    strcpy(cache, table);
    printf("%s Function Formal Scope Symbol Table\n", table);
    printf("┌────────────┬────────────────┬─────────┐\n");
    printf("│Name        │Type            │BodyScope│\n");
    while (formal_symtable)
    {
        printf("├────────────┼────────────────┼─────────┤\n");
        printf("│%12s│%16s│     ────┼────> %s Function Body Local Scope Symbol Table\n", formal_symtable->name, formal_symtable->type, table);
        formal_symtable = formal_symtable->next;
    }
    printf("└────────────┴────────────────┴─────────┘\n\n");
    strcat(cache, " Function Body");
    DisplayLocalScope(first->functionscope, cache);
}

void DisplayFunctionDepictor(FunctionDepictor funcdsp, char* table)
{
    printf("%s Function Depictor\n", table);
    printf("┌────────┬────────┬───────────┐\n");
    printf("│isstatic│ismain  │FormalScope│\n");
    printf("├────────┼────────┼───────────┤\n");
    if (funcdsp->isstatic)
        printf("│     Yes");
    else
        printf("│      No");
    if (funcdsp->ismain)
        printf("│     Yes");
    else
        printf("│      No");
    printf("│      ─────┼────> %s Function Formal Scope Symbol Table\n", table);
    printf("└────────┴────────┴───────────┘\n\n");
    DisplayFormalScope(funcdsp->formalscope, table);
}

void DisplayClassScope(ClassScope class_symtable, char* table)
{
    ClassScope first = class_symtable;
    printf("%s Class Scope Symbol Table\n", table);
    printf("┌────────────┬────────┬────────────┬────────┐\n");
    printf("│Name        │Category│Type        │Depictor│\n");
    while (class_symtable)
    {
        printf("├────────────┼────────┼────────────┼────────┤\n");
        printf("│%12s", class_symtable->name);
        switch (class_symtable->category)
        {
            case Class:
                printf("│Class   ");
                break;
            case Variable:
                printf("│Variable");
                break;
            case Function:
                printf("│Function");
                break;
            case Block:
                printf("│Block   ");
                break;
        }
        printf("│%12s", class_symtable->type);
        if (class_symtable->depictor.funcdsp)
        {
            printf("│    ────┼────> %s ", class_symtable->name);
            switch (class_symtable->category)
            {
                case Class:
                    printf("Class ");
                    break;
                case Variable:
                    printf("Variable ");
                    break;
                case Function:
                    printf("Function ");
                    break;
                case Block:
                    printf("Block ");
                    break;
            }
            printf("Depictor\n");
        }
        else 
            printf("│     Nil│\n");
        class_symtable = class_symtable->next;
    }
    printf("└────────────┴────────┴────────────┴────────┘\n\n");
    class_symtable = first;
    while (class_symtable)
    {
        if (class_symtable->depictor.funcdsp && class_symtable->category == Function)
            DisplayFunctionDepictor(class_symtable->depictor.funcdsp, class_symtable->name);
        class_symtable = class_symtable->next;
    }
}

void DisplayClassDepictor(ClassDepictor classdsp, char* table)
{
    printf("%s Class Depictor\n", table);
    printf("┌───────────┬───────────────────┬──────────┐\n");
    printf("│ParentClass│ParentClassDepictor│ClassScope│\n");
    printf("├───────────┼───────────────────┼──────────┤\n");
    if (classdsp->parentname)
        printf("│%11s", classdsp->parentname);
    else
        printf("│        Nil");
    if (classdsp->parent)
    {
        printf("│                   ");
        printf("│     ─────┼────> %s Class Scope Symbol Table\n", table);
        printf("└───────────┴─────────┼─────────┴──────────┘\n");
        printf("                      │\n");
        printf("                      ∨\n");
        printf("                 %s Class Depictor\n\n", classdsp->parentname);
    }
    else
    {
        printf("│                Nil");
        printf("│     ─────┼────> %s Class Scope Symbol Table\n", table);
        printf("└───────────┴───────────────────┴──────────┘\n\n");
    }
    DisplayClassScope(classdsp->classscope, table);
}

void DisplayGlobalScope(GlobalScope global_symtable, char* table)
{
    GlobalScope first = global_symtable;
    printf("%s Global Scope Symbol Table\n", table);
    printf("┌────────────┬────────┬────────┐\n");
    printf("│Name        │Category│Depictor│\n");
    while (global_symtable)
    {
        printf("├────────────┼────────┼────────┤\n");
        printf("│%12s│   Class│    ────┼───> %s Class Depictor\n", global_symtable->name, global_symtable->name);
        global_symtable = global_symtable->next;
    }
    printf("└────────────┴────────┴────────┘\n\n");
    global_symtable = first;
    while (global_symtable)
    {
        DisplayClassDepictor(global_symtable->depictor.classdsp, global_symtable->name);
        global_symtable = global_symtable->next;
    }
}

/*
 *Depictor FindFunctionInClass(ClassScope class_symtable, char* function_name)
 *{
 *    while (class_symtable)
 *    {
 *        if (class_symtable->category == Function && !strcmp(class_symtable->name, function_name))
 *            return class_symtable->depictor;
 *        class_symtable = class_symtable->next;
 *    }
 *}
 */

/*
 *int main(void)
 *{
 *    LocalScope local_symtable = NULL;
 *    FormalScope formal_symtable = NULL;
 *    ClassScope class_symtable = NULL;
 *    GlobalScope global_symtable = NULL;
 *    Depictor depictor;
 *    char name[100];
 *    char type[100];
 *    strcpy(name, "i");
 *    strcpy(type, "int");
 *    local_symtable = AddIntoLocal(local_symtable, name, Variable, type, NULL);
 *    strcpy(name, "@this");
 *    strcpy(type, "class:Computer");
 *    formal_symtable = AddIntoFormal(formal_symtable, name, type, local_symtable);
 *    depictor.funcdsp = (FunctionDepictor)malloc(sizeof(FunctionDepictorEntry));
 *    depictor.funcdsp->isstatic = 0;
 *    depictor.funcdsp->ismain = 0;
 *    depictor.funcdsp->formalscope = formal_symtable;
 *    strcpy(name, "Crash");
 *    strcpy(type, "class:Computer->int->void");
 *    class_symtable = AddIntoClass(class_symtable, name, Function, type, depictor);
 *    strcpy(name, "Computer");
 *    depictor.classdsp = (ClassDepictor)malloc(sizeof(ClassDepictorEntry));
 *    depictor.classdsp->parent = NULL;
 *    depictor.classdsp->classscope = class_symtable;
 *    global_symtable = AddIntoGlobal(global_symtable, name, depictor);
 *    printf("%s\n", global_symtable->depictor.classdsp->classscope->depictor.funcdsp->formalscope->functionscope->type);
 *    return 0;
 *}
 */
