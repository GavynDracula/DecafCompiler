/*************************************************************************
	> File Name: SymbolTable.h
	> Author: GuanyuLi
	> Mail: guanyuli@hustunique.com
	> Created Time: Fri 25 Nov 2016 11:21:24 AM CST
 ************************************************************************/

#ifndef _SYMBOLTABLE_H
#define _SYMBOLTABLE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum DecafCategory
{
    Class,
    Variable,
    Function,
    Block,
    Const
} DecafCategory;

// Define depictor structure
typedef struct ClassDepictorEntry
{
    char* parentname;
    struct ClassDepictorEntry* parent;
    struct ClassScopeEntry* classscope;
} ClassDepictorEntry;

typedef ClassDepictorEntry* ClassDepictor;

typedef struct FunctionDepictorEntry
{
    int isstatic;
    int ismain;
    struct FormalScopeEntry* formalscope;
} FunctionDepictorEntry;

typedef FunctionDepictorEntry* FunctionDepictor;

//typedef struct DataDepictorEntry
//{
    //int isarray;
    //int size;
    //struct DataDepictorEntry* basetype; 
//} DataDepictorEntry;

//typedef struct DataDepictorEntry* DataDepictor;

typedef union Depictor
{
    ClassDepictor classdsp;
    FunctionDepictor funcdsp;
    //DataDepictor datadsp;
} Depictor;

// Define scope symbol table

typedef struct LocalScopeEntry
{
    char* name;
    DecafCategory category;
    char* type;
    struct LocalScopeEntry* embededscope;
    struct LocalScopeEntry* next;
} LocalScopeEntry;

typedef struct LocalScopeEntry* LocalScope;

typedef struct FormalScopeEntry
{
    char* name;
    char* type;
    LocalScope functionscope;
    struct FormalScopeEntry* next;
} FormalScopeEntry;

typedef FormalScopeEntry* FormalScope;

typedef struct ClassScopeEntry
{
    char* name;
    DecafCategory category;
    char* type;
    Depictor depictor;
    struct ClassScopeEntry* next;
} ClassScopeEntry;

typedef ClassScopeEntry* ClassScope;

typedef struct GlobalScopeEntry
{
    char* name;
    DecafCategory category;
    Depictor depictor;
    struct GlobalScopeEntry* next;
} GlobalScopeEntry;

typedef GlobalScopeEntry* GlobalScope;

// Define scope create function
LocalScope AddIntoLocal(LocalScope local_symtable, char* name, DecafCategory category, char* type, LocalScope embededscope);
FormalScope AddIntoFormal(FormalScope forma_symtable, char* name, char* type, LocalScope functionscope);
ClassScope AddIntoClass(ClassScope class_symtable, char *name, DecafCategory category, char* type, Depictor depictor);
GlobalScope AddIntoGlobal(GlobalScope global_symtable, char* name, Depictor depictor);
LocalScope MergeLocalScope(LocalScope l1, LocalScope l2);
ClassScope MergeClassScope(ClassScope s1, ClassScope s2);
Depictor CreateClassDepictor(char* parentname, ClassScope classscope);
Depictor CreateFunctionDepictor(int isstatic, char* name, FormalScope formalscope);
void AddThisType(ClassScope class_symtable, char* class_name);
void AddLocalIntoFormal(FormalScope formal_symtable, LocalScope local_symtable);
void AddClassParent(GlobalScope global_symtable);

// Display symbol table
void DisplayLocalScope(LocalScope local_symtable, char* table);
void DisplayFormalScope(FormalScope formal_symtable, char* table);
void DisplayFunctionDepictor(FunctionDepictor funcdsp, char* table);
void DisplayClassScope(ClassScope class_symtable, char* table);
void DisplayClassDepictor(ClassDepictor classdsp, char* table);
void DisplayGlobalScope(GlobalScope global_symtable, char* table);

#endif
