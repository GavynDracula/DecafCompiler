/*************************************************************************
	> File Name: SemanticAnalysis.h
	> Author: GuanyuLi
	> Mail: guanyuli@hustunique.com
	> Created Time: Fri 25 Nov 2016 10:51:27 AM CST
 ************************************************************************/

#ifndef _SEMANTICANALYSIS_H
#define _SEMANTICANALYSIS_H

#include<stdio.h>
#include"GrammarTree.h"
#include"SymbolTable.h"

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 20

extern int smerror;

typedef enum ScopeType
{
    ScopeLocal,
    ScopeFormal,
    ScopeClass,
    ScopeGlobal,
    ScopeNone
} ScopeType;

typedef struct Scope
{
    ScopeType type;
    union
    {
        LocalScope localscope;
        FormalScope formalscope;
        ClassScope classscope;
        GlobalScope globalscope;
    };
} Scope;

typedef struct ScopeStack
{
    Scope* base;
    Scope* top;
    int stacksize;
} ScopeStack;

typedef struct ExprType
{
    DecafCategory category;
    char* type;
} ExprType;

void InitScopeStack(ScopeStack* stack);
void DestroyScopeStack(ScopeStack* stack);
int ScopeStackLength(ScopeStack stack);
void PushScopeStack(ScopeStack* stack, Scope scope);
void PopScopeStack(ScopeStack* stack, Scope* scope);
Scope* GetStackTop(ScopeStack* stack);
Scope TraverseScopeStack(ScopeStack stack, char* name);

ClassScope FindInClass(ScopeStack* stack, char* class_name, char* member, DecafCategory category);
ExprType* GetExprType(GrammarTree tree, ScopeStack* stack);
void SameNameTrial(ClassScope classscope, GrammarTree tree);
/*Traverse the grammar tree and operate the scope stack at the same time to do trial*/
void ScopeTrial(GrammarTree tree, Scope scope, ScopeStack* stack);

#endif
