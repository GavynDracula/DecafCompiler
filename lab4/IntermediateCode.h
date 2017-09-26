/*************************************************************************
	> File Name: Intermediate.h
	> Author: GuanyuLi
	> Mail: guanyuli@hustunique.com
	> Created Time: Fri 02 Dec 2016 08:25:56 AM CST
 ************************************************************************/

#ifndef _INTERMEDIATE_H
#define _INTERMEDIATE_H

#include<stdio.h>
#include<malloc.h>
#include<stdarg.h>
#include"SemanticAnalysis.h"

//extern FILE* yyin;
//extern int yyparse();

typedef enum TACOperandKind
{
    VARIABLE,
    ADDRESSS,
    INTEGERCONST,
    FLOATCONST,
    FUNCTION,
    LABEL
} TACOperandKind;

typedef struct TACOperand
{
    TACOperandKind kind;
    union
    {
        int intvalue;
        int labelvalue;
        float floatvalue;
        Scope variable;
        Scope function;
    };
} TACOperand;

typedef enum TACOpKind
{
    ASSIGN,
    ADD,
    SUB,
    MUL,
    DIV,
    FUNCTIONDF,
    PARAM,
    LABELDF,
    IFLTGOTO,
    IFLEGOTO,
    IFGTGOTO,
    IFGEGOTO,
    IFEQGOTO,
    IFNEQGOTO,
    GOTO,
    RETURN,
    ARG,
    CALLASSIGN,
    CALL,
    PRINTID,
    PRINTCHAR,
    READINT
} TACOpKind;

typedef struct TAC
{
    TACOpKind opkind;
    TACOperand dest;
    TACOperand firstsrc;
    TACOperand secondsrc;
} TAC;

/*
 *double orientation link list
 *Notice: the first element's "prev" points to the last element
 */
typedef struct TACCode
{
    int line;
    TAC code;
    struct TACCode* prev;
    struct TACCode* next;
} TACCode;

extern int marg;

typedef unsigned int Label;

TACCode* MergeTACCode(int num, ...);
TACCode* TranslateExpr(GrammarTree tree, Scope scope, ScopeStack* stack, Scope place);
TACCode* TranslateCondition(GrammarTree tree, Scope scope, ScopeStack* stack, unsigned int label_true, unsigned int label_false);
TACCode* TranslateArgs(GrammarTree tree, Scope scope, ScopeStack* stack);
TACCode* TranslateExprs(GrammarTree tree, Scope scope, ScopeStack* stack);
TACCode* TranslateStmt(GrammarTree tree, Scope scope, ScopeStack* stack);
TACCode* GenerateInterCode(GrammarTree tree, Scope scope, ScopeStack* stack); 
void DisplayTACCode(TACCode* entrance);
Scope AddTempIntoSymtable(LocalScope local_symtable, char* name, DecafCategory category, char* type, LocalScope embededscop, ScopeStack* stack, Scope scope);

#endif
