/*************************************************************************
	> File Name: SemanticAnalysis.c
	> Author: GuanyuLi
	> Mail: guanyuli@hustunique.com
	> Created Time: Fri 25 Nov 2016 10:51:13 AM CST
 ************************************************************************/

#include"SemanticAnalysis.h"

void InitScopeStack(ScopeStack* stack)
{
    stack->base = (Scope*)malloc(STACK_INIT_SIZE * sizeof(Scope));
    stack->top = stack->base;
    stack->stacksize = STACK_INIT_SIZE;
    return;
}

void DestroyScopeStack(ScopeStack* stack)
{
    if (stack->base)
        free(stack->base);
    stack->base = NULL;
    stack->top = NULL;
    return;
}

int ScopeStackLength(ScopeStack stack)
{
    return (stack.top - stack.base) / sizeof(Scope);
}

void PushScopeStack(ScopeStack* stack, Scope scope)
{
    if ((stack->top-stack->base)/sizeof(Scope) >= stack->stacksize)
    {
        stack->base = (Scope*)realloc(stack->base, (stack->stacksize + STACKINCREMENT) * sizeof(Scope));
        stack->top = stack->base + stack->stacksize;
        stack->stacksize += STACKINCREMENT;
    }
    *stack->top++ = scope;
    /*
     *printf("Push ");
     *switch (scope.type)
     *{
     *    case ScopeLocal:
     *        printf("local scope");
     *        break;
     *    case ScopeFormal:
     *        printf("formal scope");
     *        break;
     *    case ScopeClass:
     *        printf("class scope");
     *        break;
     *    case ScopeGlobal:
     *        printf("global scope");
     *        break;
     *}
     *printf(" into stack\n");
     */
    return;
}

void PopScopeStack(ScopeStack* stack, Scope* scope)
{
    *scope = *--stack->top;
    /*
     *printf("Pop ");
     *switch (scope->type)
     *{
     *    case ScopeLocal:
     *        printf("local scope");
     *        break;
     *    case ScopeFormal:
     *        printf("formal scope");
     *        break;
     *    case ScopeClass:
     *        printf("class scope");
     *        break;
     *    case ScopeGlobal:
     *        printf("global scope");
     *        break;
     *}
     *printf(" from stack\n");
     */
    return;
}

Scope* GetStackTop(ScopeStack* stack)
{
    return stack->top - 1;
}

Scope TraverseScopeStack(ScopeStack stack, char* name)
{
    Scope* tmp = stack.top;
    Scope result;
    LocalScope local_symtable;
    FormalScope formal_symtable;
    ClassScope class_symtable;
    GlobalScope global_symtalbe;
    if (tmp == stack.base)
    {
        result.type = ScopeNone;
        result.localscope = NULL;
        return result;
    }
    while (--tmp >= stack.base)
    {
        switch (tmp->type)
        {
            case ScopeLocal:
                local_symtable = tmp->localscope;
                while (local_symtable)
                {
                    if (!strcmp(local_symtable->name, name))
                    {
                        result.type = ScopeLocal;
                        result.localscope = local_symtable;
                        return result;
                    }
                    local_symtable = local_symtable->next;
                }
                break;
            case ScopeFormal:
                formal_symtable = tmp->formalscope;
                while (formal_symtable)
                {
                    if (!strcmp(formal_symtable->name, name))
                    {
                        result.type = ScopeFormal;
                        result.formalscope = formal_symtable;
                        return result;
                    }
                    formal_symtable = formal_symtable->next;
                }
                break;
            case ScopeClass:
                class_symtable = tmp->classscope;
                while (class_symtable)
                {
                    if (!strcmp(class_symtable->name, name))
                    {
                        result.type = ScopeClass;
                        result.classscope = class_symtable;
                        return result;
                    }
                    class_symtable = class_symtable->next;
                }
                break;
            case ScopeGlobal:
                global_symtalbe = tmp->globalscope;
                while (global_symtalbe)
                {
                    if (!strcmp(global_symtalbe->name, name))
                    {
                        result.type = ScopeGlobal;
                        result.globalscope = global_symtalbe;
                        return result;
                    }
                    global_symtalbe = global_symtalbe->next;
                }
                break;
        }
    }
    result.type = ScopeNone;
    result.localscope = NULL;
    return result;
}

ClassScope FindInClass(ScopeStack* stack, char* class_name, char* member, DecafCategory category)
{
    GlobalScope globalscope = stack->base->globalscope;
    ClassScope classscope = NULL;
    while (globalscope)
    {
        if (!strcmp(globalscope->name, class_name))
        {
            classscope = globalscope->depictor.classdsp->classscope;
            break;
        }
        globalscope = globalscope->next;
    }
    while (classscope)
    {
        if (!strcmp(classscope->name, member) && classscope->category == category)
        // Find the member
            return classscope;
        classscope = classscope->next;
    }
    // Can't find the member whose name is "member" and category is "category" in class "class_name"
    if (globalscope && globalscope->depictor.classdsp->parent)
    {
        classscope = globalscope->depictor.classdsp->parent->classscope;
        while (classscope)
        {
            if (!strcmp(classscope->name, member) && classscope->category == category)
            // Find the member
                return classscope;
            classscope = classscope->next;
        }
    }
    // Can't find the member whose name is "member" and category is "category" in class "class_name" and its parent class
    return NULL;
}

ExprType* GetExprType(GrammarTree tree, ScopeStack* stack)
{
    if (!tree)
        return NULL;
    ExprType* result = NULL;
    if ((!strcmp(tree->name, "Call") || !strcmp(tree->name, "LValue")) 
            && !strcmp(tree->lchild->name, "Expr") 
            && !strcmp(tree->lchild->rchild->name, "SPDOT"))
    {
        // If the object use the attribute or the method of class, return the type of attribute or method
        // Next is similar with the process for the same purpose in ScopeTrial
        ExprType* type = GetExprType(tree->lchild, stack);
        if (type)
        {
            if (!strncmp(type->type, "class:", 6))
            {
                ClassScope classscope;
                if (!strcmp(tree->name, "Call"))
                    classscope = FindInClass(stack, type->type + 6, tree->lchild->rchild->rchild->string_value, Function);
                else
                    classscope = FindInClass(stack, type->type + 6, tree->lchild->rchild->rchild->string_value, Variable);
                if (classscope)
                {
                    result = (ExprType*)malloc(sizeof(ExprType));
                    result->category = classscope->category;
                    result->type = classscope->type;
                    return result;
                }
            }
        }
        return NULL;
    }
    else if (!strcmp(tree->name, "KEYTHIS"))
    {
        // If the Expr is "this"
        Scope scope = TraverseScopeStack(*stack, "this");
        if (scope.type == ScopeFormal)
        {
            result = (ExprType*)malloc(sizeof(ExprType));
            result->category = Variable;
            result->type = scope.formalscope->type;
            return result;
        }
        else
            return NULL;
    }
    else if (!strcmp(tree->name, "KEYNEW") && !strcmp(tree->rchild->name, "Type"))
    {
        // If Expr is used to apply for an array
        result = (ExprType*)malloc(sizeof(ExprType));
        char* cache = (char*)malloc(sizeof(char) * (strlen(tree->rchild->string_value) + 2));
        strcpy(cache, tree->rchild->string_value);
        strcat(cache, "[]");
        result->category = Variable;
        result->type = cache;
        return result;
    }
    else if (!strcmp(tree->name, "KEYNEW") && !strcmp(tree->rchild->name, "IDENTIFIER"))
    {
        // If Expr is used to apply for an object
        GlobalScope globalscope = stack->base->globalscope;
        // First judege if the class is declared
        while (globalscope)
        {
            if (!strcmp(globalscope->name, tree->rchild->string_value))
                break;
            globalscope = globalscope->next;
        }
        if (!globalscope)
        {
            // The class is not declared
            smerror += 1;
            printf("Semantic Error 1 at Line %d Column %d: The Class \"%s\" is not Declared!\n", 
                   tree->line, tree->rchild->column, tree->rchild->string_value);
            return NULL;
        }
        else
        {
            // The class is declared
            result = (ExprType*)malloc(sizeof(ExprType));
            char* cache = (char*)malloc(sizeof(char) * (strlen(tree->rchild->string_value) + 6));
            strcpy(cache, "class:");
            strcat(cache, tree->rchild->string_value);
            result->category = Variable;
            result->type = cache;
            return result;
        }
    }
    else if (!strcmp(tree->name, "Constant"))
    {
        // If Expr is a constant
        result = (ExprType*)malloc(sizeof(ExprType));
        result->category = Const;
        if (!strcmp(tree->lchild->name, "CONSTANTINTD") || !strcmp(tree->lchild->name, "CONSTANTINTH"))
            result->type = "int";
        else if (!strcmp(tree->lchild->name, "CONSTANTFLOAT") || !strcmp(tree->lchild->name, "CONSTANTFLOATSC"))
            result->type = "float";
        else if (!strcmp(tree->lchild->name, "CONSTANTBOOL"))
            result->type = "bool";
        else if (!strcmp(tree->lchild->name, "CONSTANTSTRING"))
            result->type = "string";
        else if (!strcmp(tree->lchild->name, "CONSTANTNULL"))
            result->type = "null";
        return result;
    }
    else if (!strcmp(tree->name, "IDENTIFIER"))
    {
        // If expr is identifier
        Scope scope = TraverseScopeStack(*stack, tree->string_value);
        if (scope.type == ScopeNone)
            return NULL;
        result = (ExprType*)malloc(sizeof(ExprType));
        if (scope.type == ScopeLocal)
        {
            result->category = scope.localscope->category;
            result->type = scope.localscope->type;
        }
        else if (scope.type == ScopeFormal)
        {
            result->category = Variable;
            result->type = scope.formalscope->type;
        }
        else if (scope.type == ScopeClass)
        {
            result->category = scope.classscope->category;
            result->type = scope.classscope->type;
        }
        else if (scope.type == ScopeGlobal)
        {
            result->category = Class;
            result->type = "class";
        }
        return result;
    }
    else
    {
        // Deeper search key element to judge the type of Expr
        result = GetExprType(tree->lchild, stack);
        if (result)
            return result;
        else
            return GetExprType(tree->rchild, stack);
    }
}

void SameNameTrial(ClassScope classscope, GrammarTree tree)
{
    ClassScope first = classscope, tmp;
    while (classscope)
    {
        tmp = first;
        while (tmp != classscope)
        {
            if (!strcmp(tmp->name, classscope->name))
            {
                smerror += 1;
                printf("Semantic Error 2 at Line %d Column %d: There are Members whose Name are all \"%s\" in Class \"%s\"!\n", 
                       tree->line, tree->column, classscope->name, tree->string_value);
                return;
            }
            tmp = tmp->next;
        }
        classscope = classscope->next;
    }
}

void ScopeTrial(GrammarTree tree, Scope scope, ScopeStack* stack)
{
    if (tree == NULL)
        return;
    if (!strcmp(tree->name, "Program"))
    {
        PushScopeStack(stack, scope);
    }
    else if (!strcmp(tree->name, "ClassDef"))
    {
        Scope result;
        ClassDepictor classdsp = tree->depictor.classdsp;
        scope.type = ScopeClass;
        result = TraverseScopeStack(*stack, tree->lchild->rchild->string_value);
        // Judge whether the class has been declared
        if (result.type != ScopeNone && result.globalscope->depictor.classdsp != tree->depictor.classdsp)
        {
            smerror += 1;
            printf("Semantic Error 3 at Line %d Column %d: The Class \"%s\" has been Declared!\n", 
                   tree->line, tree->lchild->rchild->column, tree->lchild->rchild->string_value);
        }
        else
            SameNameTrial(classdsp->classscope, tree->lchild->rchild);
        // Judge if the class has parent class
        if (classdsp->parentname)
        {
            if (classdsp->parent)
            {
                scope.classscope = classdsp->parent->classscope;
                // Push parent class into scope stack
                PushScopeStack(stack, scope);
            }
            else
            {
                smerror += 1;
                printf("Semantic Error 4 at Line %d Column %d: The Parent Class \"%s\" is Not Declared!\n", 
                       tree->line, tree->lchild->rchild->rchild->rchild->column, classdsp->parentname);
            }
        }
        scope.classscope = classdsp->classscope;
        PushScopeStack(stack, scope); 
    }
    else if (!strcmp(tree->name, "FunctionDef"))
    {
        FunctionDepictor funcdsp;
        funcdsp = tree->depictor.funcdsp;
        // Push function formals into scope stack
        scope.type = ScopeFormal;
        scope.formalscope = funcdsp->formalscope;
        PushScopeStack(stack, scope);
        // Push function body into scope stack
        scope.type = ScopeLocal;
        scope.localscope = funcdsp->formalscope->functionscope;
        PushScopeStack(stack, scope);
    }
    else if (!strcmp(tree->name, "StmtBlock"))
    {
        // Judge if this block is function body
        if (tree->localscope != GetStackTop(stack)->localscope)
        {
            scope.type = ScopeLocal;
            scope.localscope = tree->localscope;
            PushScopeStack(stack, scope);
        }
    }
    else if (!strcmp(tree->name, "SPRIGHTBRACE"))
    {
        Scope top;
        PopScopeStack(stack, &top);
        // Judge if it has parent class, if it has, pop parent class as well
        if (top.type == ScopeClass && GetStackTop(stack)->type == ScopeClass)
            PopScopeStack(stack, &top);
        // Judge if it is function
        else if (top.type == ScopeLocal && GetStackTop(stack)->type == ScopeFormal)
            PopScopeStack(stack, &top);
        scope = *GetStackTop(stack);
    }
    else if (!strcmp(tree->name, "LValue") && !strcmp(tree->lchild->name, "IDENTIFIER"))
    {
        // Examine the left value 
        Scope result = TraverseScopeStack(*stack, tree->lchild->string_value);
        if (result.type == ScopeNone)
        {
            smerror += 1;
            printf("Semantic Error 5 at Line %d Column %d: The Variable \"%s\" is Not Declared Before Used!\n", tree->line, tree->column, tree->lchild->string_value);
        }
        else if (result.type == ScopeGlobal)
        {
            smerror += 1;
            printf("Semantic Error 6 at Line %d Column %d: The Class \"%s\" can Not be Used as Left Value!\n", tree->line, tree->column, tree->lchild->string_value);
        }
        else if (tree->rchild && !strcmp(tree->rchild->name, "OPASSIGN"))
        {
            // If this is a assign statement, judege two sides of '=' whether are valid and compatible
            ExprType* exprtype = GetExprType(tree->rchild->rchild, stack);
            if (exprtype)
            {
                if (result.type == ScopeClass && strcmp(result.classscope->type, exprtype->type))
                {
                    smerror += 1;
                    printf("Semantic Error 7 at Line %d Column %d: The Two Sides of \"=\" have Conflicted Types! One is \"%s\", but the Other is \"%s\"!\n", 
                           tree->line, tree->rchild->column, result.classscope->type, exprtype->type);
                }
                else if (result.type == ScopeFormal && strcmp(result.formalscope->type, exprtype->type))
                {
                    smerror += 1;
                    printf("Semantic Error 7 at Line %d Column %d: The Two Sides of \"=\" have Conflicted Types! One is \"%s\", but the Other is \"%s\"!\n", 
                           tree->line, tree->rchild->column, result.formalscope->type, exprtype->type);
                }
                else if (result.type == ScopeLocal && strcmp(result.localscope->type, exprtype->type))
                {
                    smerror += 1;
                    printf("Semantic Error 7 at Line %d Column %d: The Two Sides of \"=\" have Conflicted Types! One is \"%s\", but the Other is \"%s\"!\n", 
                           tree->line, tree->rchild->column, result.localscope->type, exprtype->type);
                }
            }
        }
    }
    else if (!strcmp(tree->name, "LValue") && !strcmp(tree->lchild->name, "Expr") && !strcmp(tree->lchild->rchild->name, "SPDOT"))
    {
        ExprType* type = GetExprType(tree->lchild, stack);
        if (type)
        {
            // First, judge if the variable is an object of a class
            if (!strncmp(type->type, "class:", 6))
            {
                ClassScope classscope = FindInClass(stack, type->type + 6, tree->lchild->rchild->rchild->string_value, Variable);
                // Then judege if the class has the attribute
                if (classscope)
                {
                    // Next judge if it it an assign statement
                    if (tree->rchild && !strcmp(tree->rchild->name, "OPASSIGN"))
                    {
                        ExprType* exprtype = GetExprType(tree->rchild->rchild, stack);
                        if (exprtype)
                        {
                            // Judge two sides of '='
                            if (strcmp(classscope->type, exprtype->type))
                            {
                                smerror += 1;
                                printf("Semantic Error 7 at Line %d Column %d: The Two Sides of \"=\" have Conflicted Types! One is \"%s\", but the Other is \"%s\"!\n", 
                                       tree->line, tree->rchild->column, classscope->type, exprtype->type);
                            }
                        }
                    }
                }
                else
                {
                    smerror += 1;
                    printf("Semantic Error 8 at Line %d Column %d: Class \"%s\" has No Attribute Called \"%s\"!\n", 
                           tree->lchild->line, tree->lchild->column, type->type + 6, tree->lchild->rchild->rchild->string_value);
                }
            }
            else
            {
                smerror += 1;
                printf("Semantic Error 9 at Line %d Column %d: It is Not an Instance of Any Class!\n", tree->lchild->line, tree->lchild->column);
            }
        }
    }
    else if (!strcmp(tree->name, "Call") && !strcmp(tree->lchild->name, "IDENTIFIER"))
    {
        Scope result = TraverseScopeStack(*stack, tree->lchild->string_value);
        if (result.type == ScopeNone)
        {
            smerror += 1;
            printf("Semantic Error 10 at Line %d Column %d: The Function \"%s\" is Not Declared Before Used!\n", tree->line, tree->column, tree->lchild->string_value);
        }
        else if (result.type == ScopeFormal)
        {
            smerror += 1;
            printf("Semantic Error 11 at Line %d Column %d: The Function \"%s\" is Not Declared Before Used!\n", tree->line, tree->column, tree->lchild->string_value);
            printf("Hint: You have Declared \"%s\" as Function Formal Before!\n", tree->lchild->string_value);
        }
        // It is declared but it is not a function(localscope, classscope, globalscope all have category item)
        else if (result.localscope->category != Function)
        {
            smerror += 1;
            printf("Semantic Error 12 at Line %d Column %d: The Function \"%s\" is Not Declared Before Used!\n", tree->line, tree->column, tree->lchild->string_value);
            printf("Hint: You have Declared \"%s\" ", tree->lchild->string_value);
            switch (result.localscope->category)
            {
                case Class:
                    printf("as Class Before!\n");
                    break;
                case Variable:
                    printf("as Variable Before!\n");
                    break;
            }
        }
    }
    else if (!strcmp(tree->name, "Call") && !strcmp(tree->lchild->name, "Expr") && !strcmp(tree->lchild->rchild->name, "SPDOT"))
    {
        ExprType* type = GetExprType(tree->lchild, stack);
        if (type)
        {
            if (!strncmp(type->type, "class:", 6))
            {
                ClassScope classscope = FindInClass(stack, type->type + 6, tree->lchild->rchild->rchild->string_value, Function);
                if (!classscope)
                {
                    smerror += 1;
                    printf("Semantic Error 13 at Line %d Column %d: Class \"%s\" has No Method Called \"%s\"!\n", 
                           tree->lchild->line, tree->lchild->column, type->type + 6, tree->lchild->rchild->rchild->string_value);
                }
            }
            else
            {
                smerror += 1;
                printf("Semantic Error 9 at Line %d Column %d: It is Not an Instance of Any Class!\n", tree->lchild->line, tree->lchild->column);
            }
        }
    }
    else if (!strcmp(tree->name, "Expr") && !strcmp(tree->lchild->name, "Expr"))
    {
        // Such as rule "Expr->Expr OP Expr"
        ExprType* type1 = GetExprType(tree->lchild, stack);
        ExprType* type2 = GetExprType(tree->lchild->rchild->rchild, stack);
        // Expr1 and Expr2 has been valid
        if (type1 != NULL && type2 != NULL)
        {
            if (strcmp(type1->type, type2->type))
            {
                smerror += 1;
                printf("Semantic Error at Line %d Column %d: The Operators have Conflicted Types! One is \"%s\", but the Other is \"%s\"!\n", 
                       tree->line, tree->lchild->rchild->rchild->column, type1->type, type2->type);
            }
        }
    }
    ScopeTrial(tree->lchild, scope, stack);
    ScopeTrial(tree->rchild, scope, stack);
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
