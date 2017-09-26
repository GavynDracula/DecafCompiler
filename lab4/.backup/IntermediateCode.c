/*************************************************************************
	> File Name: IntermediateCode.c
	> Author: GuanyuLi
	> Mail: guanyuli@hustunique.com
	> Created Time: Fri 02 Dec 2016 08:27:00 AM CST
 ************************************************************************/

#include"IntermediateCode.h"
unsigned int temp_num = 0;
unsigned int label_num = 0;

TACCode* MergeTACCode(int num, ...)
{
    int i = 1;
    va_list codelist;
    TACCode* entrance;
    TACCode* tmp;
    va_start(codelist, num); // Init the variable parameter list 
    while ((entrance = va_arg(codelist, TACCode*)) == NULL && i < num) 
        i += 1;
    while (i < num)
    {
        // First, previous linklist's last element's "next" points to new linklist's first element
        if ((entrance->prev->next = va_arg(codelist, TACCode*)) == NULL)
        {
            /*printf("3 test i:%d num:%d\n", i, num);*/
            i += 1; 
        }
        else
        {
            // Then, save the pointer to new linklist's last element 
            tmp = entrance->prev->next->prev;
            // Next, new linklist's first element's "prev" points to previous linklist's last element
            entrance->prev->next->prev = entrance->prev;
            // Finaly, previous linklist's first element's "prev" points to new linklist's last element
            entrance->prev = tmp;
            i += 1;
        }
    }
    return entrance;
}

TACCode* TranslateCondition(GrammarTree tree, Scope scope, ScopeStack* stack, unsigned int label_true, unsigned int label_false)
{
    if (!strcmp(tree->lchild->name, "Expr"))
    {
        if (!strcmp(tree->lchild->rchild->name, "OPAND"))
        {
            Label label = label_num++;
            scope.localscope = GetStackTop(stack)->localscope;
            TACCode* code1 = TranslateCondition(tree->lchild, scope, stack, label, label_false);
            scope.localscope = GetStackTop(stack)->localscope;
            TACCode* code2 = TranslateCondition(tree->lchild->rchild->rchild, scope, stack, label_true, label_false);
            TACCode* code3 = (TACCode*)malloc(sizeof(TACCode));
            code3->code.opkind = LABELDF;
            code3->code.dest.kind = LABEL;
            code3->code.dest.labelvalue = label;
            code3->line = tree->lchild->rchild->line;
            code3->prev = code3;
            return MergeTACCode(3, code1, code3, code2);
        }
        else if (!strcmp(tree->lchild->rchild->name, "OPOR"))
        {
            Label label = label_num++;
            scope.localscope = GetStackTop(stack)->localscope;
            TACCode* code1 = TranslateCondition(tree->lchild, scope, stack, label_true, label);
            scope.localscope = GetStackTop(stack)->localscope;
            TACCode* code2 = TranslateCondition(tree->lchild->rchild->rchild, scope, stack, label_true, label_false);
            TACCode* code3 = (TACCode*)malloc(sizeof(TACCode));
            code3->code.opkind = LABELDF;
            code3->code.dest.kind = LABEL;
            code3->code.dest.labelvalue = label;
            code3->line = tree->lchild->rchild->line;
            code3->prev = code3;
            return MergeTACCode(3, code1, code3, code2);
        }
        else
        {
            char cache1[8], cache2[8];
            Scope new_temp1, new_temp2;
            TACCode *code1, *code2, *code3, *code4;
            sprintf(cache1, "_t%d", temp_num++);
            sprintf(cache2, "_t%d", temp_num++);
            new_temp1 = AddTempIntoSymtable(scope.localscope, cache1, Variable, GetExprType(tree->lchild, stack)->type, NULL, stack, scope);
            new_temp2 = AddTempIntoSymtable(new_temp1.localscope, cache2, Variable, GetExprType(tree->lchild->rchild->rchild, stack)->type, NULL, stack, scope);
            scope.localscope = GetStackTop(stack)->localscope;
            code1 = TranslateExpr(tree->lchild, new_temp2, stack, new_temp1);
            scope.localscope = GetStackTop(stack)->localscope;
            code2 = TranslateExpr(tree->lchild->rchild->rchild, new_temp2, stack, new_temp2);
            code3 = (TACCode*)malloc(sizeof(TACCode));
            code3->code.dest.kind = LABEL;
            code3->code.dest.labelvalue = label_true;
            code3->code.firstsrc.kind = VARIABLE;
            code3->code.firstsrc.variable = new_temp1;
            code3->code.secondsrc.kind = VARIABLE;
            code3->code.secondsrc.variable = new_temp2;
            code3->line = tree->lchild->rchild->line;
            code3->prev = code3;
            if (!strcmp(tree->lchild->rchild->name, "OPLIGHT"))
                code3->code.opkind = IFLTGOTO;
            else if (!strcmp(tree->lchild->rchild->name, "OPLIGHTEQ"))
                code3->code.opkind = IFLEGOTO;
            else if (!strcmp(tree->lchild->rchild->name, "OPGREAT"))
                code3->code.opkind = IFGTGOTO;
            else if (!strcmp(tree->lchild->rchild->name, "OPGREATEQ"))
                code3->code.opkind = IFGEGOTO;
            else if (!strcmp(tree->lchild->rchild->name, "OPEQUAL"))
                code3->code.opkind = IFEQGOTO;
            else if (!strcmp(tree->lchild->rchild->name, "OPNOTEQUAL"))
                code3->code.opkind = IFNEQGOTO;
            code4 = (TACCode*)malloc(sizeof(TACCode));
            code4->code.opkind = GOTO;
            code4->code.dest.kind = LABEL;
            code4->code.dest.labelvalue = label_false;
            code4->line = tree->line;
            code4->prev = code4;
            return MergeTACCode(4, code1, code2, code3, code4);
        }
    }
    else if (!strcmp(tree->lchild->name, "OPNOT"))
    {
        scope.localscope = GetStackTop(stack)->localscope;
        return TranslateCondition(tree->lchild->rchild, scope, stack, label_false, label_true);
    }
    else
    {
        char cache[8];
        Scope new_temp;
        TACCode *code1, *code2, *code3;
        sprintf(cache, "_t%d", temp_num++);
        new_temp = AddTempIntoSymtable(scope.localscope, cache, Variable, GetExprType(tree, stack)->type, NULL, stack, scope);
        scope.localscope = GetStackTop(stack)->localscope;
        code1 = TranslateExpr(tree, new_temp, stack, new_temp);
        code2 = (TACCode*)malloc(sizeof(TACCode));
        code2->code.opkind = IFNEQGOTO;
        code2->code.dest.kind = LABEL;
        code2->code.dest.labelvalue = label_true;
        code2->code.firstsrc.kind = VARIABLE;
        code2->code.firstsrc.variable = new_temp;
        code2->code.secondsrc.kind = INTEGERCONST;
        code2->code.secondsrc.intvalue = 0;
        code2->line = tree->lchild->line;
        code2->prev = code2;
        code3 = (TACCode*)malloc(sizeof(TACCode));
        code3->code.opkind = GOTO;
        code3->code.dest.kind = LABEL;
        code3->code.dest.labelvalue = label_false;
        code3->line = tree->line;
        code3->prev = code3;
        return MergeTACCode(3, code1, code2, code3);
    }
}

TACCode* TranslateArgs(GrammarTree tree, Scope scope, ScopeStack* stack)
{
    if (tree->line == -1)
        return NULL;
    else
    {
        scope.localscope = GetStackTop(stack)->localscope;
        return TranslateExprs(tree->lchild, scope, stack);
    }
}

TACCode* TranslateExprs(GrammarTree tree, Scope scope, ScopeStack* stack)
{
    if (!strcmp(tree->lchild->name, "Expr"))
    {
        char cache[8];
        Scope new_temp;
        sprintf(cache, "_t%d", temp_num++);
        new_temp = AddTempIntoSymtable(scope.localscope, cache, Variable, 
                                       GetExprType(tree->lchild, stack)->type, NULL, stack, scope);
        scope.localscope = GetStackTop(stack)->localscope;
        return TranslateExpr(tree->lchild, new_temp, stack, new_temp);
    }
    else
    {
        char cache[8];
        Scope new_temp;
        TACCode *code1, *code2;
        sprintf(cache, "_t%d", temp_num++);
        new_temp = AddTempIntoSymtable(scope.localscope, cache, Variable, 
                                       GetExprType(tree->lchild->rchild->rchild, stack)->type, NULL, stack, scope);
        scope.localscope = GetStackTop(stack)->localscope;
        code1 = TranslateExprs(tree->lchild, new_temp, stack);
        scope.localscope = GetStackTop(stack)->localscope;
        code2 = TranslateExpr(tree->lchild->rchild->rchild, new_temp, stack, new_temp);
        return MergeTACCode(2, code1, code2);
    }
}

TACCode* TranslateExpr(GrammarTree tree, Scope scope, ScopeStack* stack, Scope place)
{
    if (!strcmp(tree->lchild->name, "Constant") && !strncmp(tree->lchild->lchild->name, "CONSTANTINT", 11))
    {
        TACCode* tmp = (TACCode*)malloc(sizeof(TACCode));
        tmp->code.opkind = ASSIGN;
        tmp->code.dest.kind = VARIABLE;
        tmp->code.dest.variable = place;
        tmp->code.firstsrc.kind = INTEGERCONST;
        tmp->code.firstsrc.intvalue = tree->lchild->lchild->int_value;
        tmp->line = tree->lchild->line;
        tmp->prev = tmp;
        return tmp;
    }
    else if (!strcmp(tree->lchild->name, "Constant") && !strncmp(tree->lchild->lchild->name, "CONSTANTFLOAT", 13))
    {
        TACCode* tmp = (TACCode*)malloc(sizeof(TACCode));
        tmp->code.opkind = ASSIGN;
        tmp->code.dest.kind = VARIABLE;
        tmp->code.dest.variable = place;
        tmp->code.firstsrc.kind = FLOATCONST;
        tmp->code.firstsrc.intvalue = tree->lchild->lchild->float_value;
        tmp->line = tree->lchild->line;
        tmp->prev = tmp;
        return tmp;
    }
    else if (!strcmp(tree->lchild->name, "LValue"))
    {
        if (!strcmp(tree->lchild->lchild->name, "IDENTIFIER"))
        {
            TACCode* tmp = (TACCode*)malloc(sizeof(TACCode));
            tmp->code.opkind = ASSIGN;
            tmp->code.dest.kind = VARIABLE;
            tmp->code.dest.variable = place;
            tmp->code.firstsrc.kind = VARIABLE;
            tmp->code.firstsrc.variable = TraverseScopeStack(*stack, tree->lchild->lchild->string_value);
            tmp->line = tree->lchild->line;
            tmp->prev = tmp;
            return tmp;
        }
        else if (!strcmp(tree->lchild->lchild->rchild->name, "SPDOT"))
        {
            char cache[26];
            GrammarTree object = tree->lchild->lchild;
            TACCode* tmp = (TACCode*)malloc(sizeof(TACCode));
            tmp->code.opkind = ASSIGN;
            tmp->code.dest.kind = VARIABLE;
            tmp->code.dest.variable = place;
            tmp->code.firstsrc.kind = VARIABLE;
            if (!strcmp(object->lchild->lchild->name, "IDENTIFIER"))
            {
                // Expr: LValue
                // LValue: IDENTIFIER
                sprintf(cache, "%s.%s", object->lchild->lchild->string_value, tree->lchild->lchild->rchild->rchild->string_value);
            }
            tmp->code.firstsrc.variable = TraverseScopeStack(*stack, cache);
            tmp->line = tree->lchild->line;
            tmp->prev = tmp;
            return tmp;
        }
    }
    else if (!strcmp(tree->lchild->name, "OPLEFTPRNT"))
    {
        char cache[8];
        Scope new_temp;
        TACCode* tmp;
        sprintf(cache, "_t%d", temp_num++);
        new_temp = AddTempIntoSymtable(scope.localscope, cache, Variable, 
                                       GetExprType(tree->lchild->rchild, stack)->type, NULL, stack, scope);
        tmp = (TACCode*)malloc(sizeof(TACCode));
        tmp->code.opkind = ASSIGN;
        tmp->code.dest.kind = VARIABLE;
        tmp->code.dest.variable = place;
        tmp->code.firstsrc.kind = VARIABLE;
        tmp->code.firstsrc.variable = new_temp;
        tmp->line = tree->line;
        tmp->prev = tmp;
        scope.localscope = GetStackTop(stack)->localscope;
        return MergeTACCode(2, TranslateExpr(tree->lchild->rchild, new_temp, stack, new_temp), tmp);
    }
    else if (!strcmp(tree->lchild->name, "Expr"))
    {
        if (!strcmp(tree->lchild->rchild->name, "OPPLUS") || !strcmp(tree->lchild->rchild->name, "OPMINUS") 
            || !strcmp(tree->lchild->rchild->name, "OPMULTIPLY") || !strcmp(tree->lchild->rchild->name, "OPDIVIDE"))
        {
            char cache1[8], cache2[8];
            Scope new_temp1, new_temp2;
            TACCode *code1, *code2, *code3;
            sprintf(cache1, "_t%d", temp_num++);
            sprintf(cache2, "_t%d", temp_num++);
            new_temp1 = AddTempIntoSymtable(scope.localscope, cache1, Variable, GetExprType(tree->lchild, stack)->type, NULL, stack, scope);
            new_temp2 = AddTempIntoSymtable(new_temp1.localscope, cache2, Variable, GetExprType(tree->lchild->rchild->rchild, stack)->type, NULL, stack, scope);
            scope.localscope = GetStackTop(stack)->localscope;
            code1 = TranslateExpr(tree->lchild, new_temp2, stack, new_temp1);
            scope.localscope = GetStackTop(stack)->localscope;
            code2 = TranslateExpr(tree->lchild->rchild->rchild, new_temp2, stack, new_temp2);
            code3 = (TACCode*)malloc(sizeof(TACCode));
            if (!strcmp(tree->lchild->rchild->name, "OPPLUS"))
                code3->code.opkind = ADD;
            else if (!strcmp(tree->lchild->rchild->name, "OPMINUS"))
                code3->code.opkind = SUB;
            else if (!strcmp(tree->lchild->rchild->name, "OPMULTIPLY"))
                code3->code.opkind = MUL;
            else if (!strcmp(tree->lchild->rchild->name, "OPDIVIDE"))
                code3->code.opkind = DIV;
            code3->code.dest.kind = VARIABLE;
            code3->code.dest.variable = place;
            code3->code.firstsrc.kind = VARIABLE;
            code3->code.firstsrc.variable = new_temp1;
            code3->code.secondsrc.kind = VARIABLE;
            code3->code.secondsrc.variable = new_temp2;
            code3->line = tree->line;
            code3->prev = code3;
            return MergeTACCode(3, code1, code2, code3);
        }
        else
        {
            Label label1 = label_num++;
            Label label2 = label_num++;
            TACCode* code0 = (TACCode*)malloc(sizeof(TACCode));
            TACCode* code1;
            TACCode* code2 = (TACCode*)malloc(sizeof(TACCode));
            TACCode* code3 = (TACCode*)malloc(sizeof(TACCode));
            TACCode* code4 = (TACCode*)malloc(sizeof(TACCode));
            code0->code.opkind = ASSIGN;
            code0->code.dest.kind = VARIABLE;
            code0->code.dest.variable = place;
            code0->code.firstsrc.kind = INTEGERCONST;
            code0->code.firstsrc.intvalue = 0;
            code0->line = tree->line;
            code0->prev = code0;
            scope.localscope = GetStackTop(stack)->localscope;
            code1 = TranslateCondition(tree, scope, stack, label1, label2);
            code2->code.opkind = LABELDF;
            code2->code.dest.kind = LABEL;
            code2->code.dest.labelvalue = label1;
            code2->line = tree->line;
            code2->prev = code2;
            code3->code.opkind = ASSIGN;
            code3->code.dest.kind = VARIABLE;
            code3->code.dest.variable = place;
            code3->code.firstsrc.kind = INTEGERCONST;
            code3->code.firstsrc.intvalue = 1;
            code3->line = tree->line;
            code3->prev = code3;
            code4->code.opkind = LABELDF;
            code4->code.dest.kind = LABEL;
            code4->code.dest.labelvalue = label2;
            code4->line = tree->line;
            code4->prev = code4;
            return MergeTACCode(5, code0, code1, code2, code3, code4);
        }
    }
    else if (!strcmp(tree->lchild->name, "OPMINUS"))
    {
        char cache[8];
        Scope new_temp;
        TACCode* tmp;
        sprintf(cache, "_t%d", temp_num++);
        new_temp = AddTempIntoSymtable(scope.localscope, cache, Variable, 
                                       GetExprType(tree->lchild->rchild, stack)->type, NULL, stack, scope);
        tmp = (TACCode*)malloc(sizeof(TACCode));
        tmp->code.opkind = SUB;
        tmp->code.dest.kind = VARIABLE;
        tmp->code.dest.variable = place;
        tmp->code.firstsrc.kind = INTEGERCONST;
        tmp->code.firstsrc.intvalue = 0;
        tmp->code.secondsrc.kind = VARIABLE;
        tmp->code.secondsrc.variable = new_temp;
        tmp->line = tree->lchild->line;
        tmp->prev = tmp;
        scope.localscope = GetStackTop(stack)->localscope;
        return MergeTACCode(2, TranslateExpr(tree->lchild->rchild, new_temp, stack, new_temp), tmp);
    }
    else if (!strcmp(tree->lchild->name, "OPNOT"))
    {
        Label label1 = label_num++;
        Label label2 = label_num++;
        TACCode* code0 = (TACCode*)malloc(sizeof(TACCode));
        TACCode* code1;
        TACCode* code2 = (TACCode*)malloc(sizeof(TACCode));
        TACCode* code3 = (TACCode*)malloc(sizeof(TACCode));
        TACCode* code4 = (TACCode*)malloc(sizeof(TACCode));
        code0->code.opkind = ASSIGN;
        code0->code.dest.kind = VARIABLE;
        code0->code.dest.variable = place;
        code0->code.firstsrc.kind = INTEGERCONST;
        code0->code.firstsrc.intvalue = 0;
        code0->line = tree->lchild->line;
        code0->prev = code0;
        scope.localscope = GetStackTop(stack)->localscope;
        code1 = TranslateCondition(tree, scope, stack, label1, label2);
        code2->code.opkind = LABELDF;
        code2->code.dest.kind = LABEL;
        code2->code.dest.labelvalue = label1;
        code2->line = tree->lchild->line;
        code2->prev = code2;
        code3->code.opkind = ASSIGN;
        code3->code.dest.kind = VARIABLE;
        code3->code.dest.variable = place;
        code3->code.firstsrc.kind = INTEGERCONST;
        code3->code.firstsrc.intvalue = 1;
        code3->line = tree->lchild->line;
        code3->prev = code3;
        code4->code.opkind = LABELDF;
        code4->code.dest.kind = LABEL;
        code4->code.dest.labelvalue = label2;
        code4->line = tree->lchild->line;
        code4->prev = code4;
        return MergeTACCode(5, code0, code1, code2, code3, code4);
    }
    else if (!strcmp(tree->lchild->name, "Call"))
    {
        /*
         *if (!strcmp(tree->lchild->lchild->name, "IDENTIFIER"))
         *{
         *    Scope variable;
         *    Scope function = TraverseScopeStack(*stack, tree->lchild->lchild->string_value);
         *    LocalScope origin = GetStackTop(stack)->localscope;
         *    GrammarTree actuals = tree->lchild->lchild->rchild->rchild;
         *    scope.localscope = origin;
         *    scope.localscope = GetStackTop(stack)->localscope;
         *    TACCode* code1 = TranslateArgs(actuals, scope, stack);
         *    LocalScope current = GetStackTop(stack)->localscope;
         *    TACCode* code2 = NULL;
         *    TACCode* code3 = NULL;
         *    TACCode* tmp = NULL;
         *    variable.type = ScopeLocal;
         *    while (current != origin && current != NULL)
         *    {
         *        if (code2 == NULL)
         *        {
         *            code2 = (TACCode*)malloc(sizeof(TACCode));
         *            code2->code.opkind = ARG;
         *            code2->code.dest.kind = VARIABLE;
         *            variable.localscope = current;
         *            code2->code.dest.variable = variable;
         *            code2->line = tree->lchild->line;
         *            code2->prev = code2;
         *        }
         *        else
         *        {
         *            tmp = (TACCode*)malloc(sizeof(TACCode));
         *            tmp->code.opkind = ARG;
         *            tmp->code.dest.kind = VARIABLE;
         *            variable.localscope = current;
         *            tmp->code.dest.variable = variable;
         *            tmp->line = tree->lchild->line;
         *            tmp->prev = tmp;
         *            code2 = MergeTACCode(2, code2, tmp);
         *        }
         *        current = current->next;
         *    }
         *    code3 = (TACCode*)malloc(sizeof(TACCode));
         *    code3->code.opkind = CALLASSIGN;
         *    code3->code.dest.kind = VARIABLE;
         *    code3->code.dest.variable = place;
         *    code3->code.firstsrc.kind = FUNCTION;
         *    code3->code.firstsrc.function = function;
         *    code3->line = tree->lchild->line;
         *    code3->prev = code3;
         *    return MergeTACCode(3, code1, code2, code3);
         *}
         */
        Scope variable;
        Scope function;
        GrammarTree actuals;
        if (!strcmp(tree->lchild->lchild->name, "IDENTIFIER"))
        {
            function = TraverseScopeStack(*stack, tree->lchild->lchild->string_value);
            actuals = tree->lchild->lchild->rchild->rchild;
        }
        else
        {
            if (!strcmp(tree->lchild->lchild->lchild->name, "LValue") 
             && !strcmp(tree->lchild->lchild->lchild->lchild->name, "IDENTIFIER"))
                variable = TraverseScopeStack(*stack, tree->lchild->lchild->lchild->lchild->string_value);
            function.type = ScopeClass;
            function.classscope = FindInClass(stack, variable.localscope->type + 6, tree->lchild->lchild->rchild->rchild->string_value, Function);
            actuals = tree->lchild->lchild->rchild->rchild->rchild->rchild;
        }
        LocalScope origin = GetStackTop(stack)->localscope;
        scope.localscope = origin;
        scope.localscope = GetStackTop(stack)->localscope;
        TACCode* code1 = TranslateArgs(actuals, scope, stack);
        LocalScope current = GetStackTop(stack)->localscope;
        TACCode* code2 = NULL;
        TACCode* code3 = NULL;
        TACCode* tmp = NULL;
        variable.type = ScopeLocal;
        while (current != origin && current != NULL)
        {
            if (code2 == NULL)
            {
                code2 = (TACCode*)malloc(sizeof(TACCode));
                code2->code.opkind = ARG;
                code2->code.dest.kind = VARIABLE;
                variable.localscope = current;
                code2->code.dest.variable = variable;
                code2->line = tree->line;
                code2->prev = code2;
            }
            else
            {
                tmp = (TACCode*)malloc(sizeof(TACCode));
                tmp->code.opkind = ARG;
                tmp->code.dest.kind = VARIABLE;
                variable.localscope = current;
                tmp->code.dest.variable = variable;
                tmp->line = tree->line;
                tmp->prev = tmp;
                code2 = MergeTACCode(2, tmp, code2);
            }
            current = current->next;
        }
        code3 = (TACCode*)malloc(sizeof(TACCode));
        code3->code.opkind = CALLASSIGN;
        code3->code.dest.kind = VARIABLE;
        code3->code.dest.function = place;
        code3->code.firstsrc.kind = FUNCTION;
        code3->code.firstsrc.variable = function;
        code3->line = tree->line;
        code3->prev = code3;
        return MergeTACCode(3, code1, code2, code3);
    }
    else if (!strcmp(tree->lchild->name, "KEYREADINTEGER"))
    {
        TACCode* tmp = (TACCode*)malloc(sizeof(TACCode));
        tmp->code.opkind = READINT;
        tmp->code.dest.kind = VARIABLE;
        tmp->code.dest.variable = place;
        tmp->prev = tmp;
        return tmp;
    }
    return NULL;
}

TACCode* TranslateStmt(GrammarTree tree, Scope scope, ScopeStack* stack)
{
    if (!strcmp(tree->lchild->name, "IfStmt"))
    {
        Label label1 = label_num++;
        Label label2 = label_num++;
        GrammarTree expr = tree->lchild->lchild->rchild->rchild->lchild;
        GrammarTree stmt = tree->lchild->lchild->rchild->rchild->rchild->rchild;
        scope.localscope = GetStackTop(stack)->localscope;
        TACCode* code1 = TranslateCondition(expr, scope, stack, label1, label2);
        scope.localscope = GetStackTop(stack)->localscope;
        TACCode* code2 = TranslateStmt(stmt, scope, stack);
        TACCode* code3 = (TACCode*)malloc(sizeof(TACCode));
        TACCode* code4 = (TACCode*)malloc(sizeof(TACCode));
        code3->code.opkind = LABELDF;
        code3->code.dest.kind = LABEL;
        code3->code.dest.labelvalue = label1;
        code3->line = tree->lchild->line;
        code3->prev = code3;
        code4->code.opkind = LABELDF;
        code4->code.dest.kind = LABEL;
        code4->code.dest.labelvalue = label2;
        code4->line = tree->lchild->line;
        code4->prev = code4;
        if (stmt->rchild && !strcmp(stmt->rchild->name, "KEYELSE"))
        {
            Label label3 = label_num++;
            scope.localscope = GetStackTop(stack)->localscope;
            TACCode* code5 = TranslateStmt(stmt->rchild->rchild, scope, stack);
            TACCode* code6 = (TACCode*)malloc(sizeof(TACCode));
            TACCode* code7 = (TACCode*)malloc(sizeof(TACCode));
            code6->code.opkind = GOTO;
            code6->code.dest.kind = LABEL;
            code6->code.dest.labelvalue = label3;
            code6->line = tree->lchild->line;
            code6->prev = code6;
            code7->code.opkind = LABELDF;
            code7->code.dest.kind = LABEL;
            code7->code.dest.labelvalue = label3;
            code7->line = tree->lchild->line;
            code7->prev = code7;
            return MergeTACCode(7, code1, code3, code2, code6, code4, code5, code7);
        }
        else
            return MergeTACCode(4, code1, code3, code2, code4);
    }
    else if (!strcmp(tree->lchild->name, "WhileStmt"))
    {
        Label label1 = label_num++;
        Label label2 = label_num++;
        Label label3 = label_num++;
        GrammarTree expr = tree->lchild->lchild->rchild->rchild->lchild;
        GrammarTree stmt = tree->lchild->lchild->rchild->rchild->rchild->rchild;
        TACCode* code1 = (TACCode*)malloc(sizeof(TACCode));
        scope.localscope = GetStackTop(stack)->localscope;
        TACCode* code2 = TranslateCondition(expr, scope, stack, label2, label3);
        TACCode* code3 = (TACCode*)malloc(sizeof(TACCode));
        scope.localscope = GetStackTop(stack)->localscope;
        TACCode* code4 = TranslateStmt(stmt, scope, stack);
        TACCode* code5 = (TACCode*)malloc(sizeof(TACCode));
        TACCode* code6 = (TACCode*)malloc(sizeof(TACCode));
        code1->code.opkind = LABELDF;
        code1->code.dest.kind = LABEL;
        code1->code.dest.labelvalue = label1;
        code1->line = tree->lchild->line;
        code1->prev = code1;
        code3->code.opkind = LABELDF;
        code3->code.dest.kind = LABEL;
        code3->code.dest.labelvalue = label2;
        code3->line = tree->lchild->line;
        code3->prev = code3;
        code5->code.opkind = GOTO;
        code5->code.dest.kind = LABEL;
        code5->code.dest.labelvalue = label1;
        code5->line = tree->lchild->line;
        code5->prev = code5;
        code6->code.opkind = LABELDF;
        code6->code.dest.kind = LABEL;
        code6->code.dest.labelvalue = label3;
        code6->line = tree->lchild->line;
        code6->prev = code6;
        return MergeTACCode(6, code1, code2, code3, code4, code5, code6);
    }
    else if (!strcmp(tree->lchild->name, "ForStmt"))
    {
        Label label1 = label_num++;
        Label label2 = label_num++;
        Label label3 = label_num++;
        GrammarTree init = tree->lchild->lchild->rchild->rchild;
        GrammarTree expr = init->rchild->rchild->lchild;
        GrammarTree step = init->rchild->rchild->rchild->rchild;
        GrammarTree stmt = step->rchild->rchild;
        TACCode* code1 = GenerateInterCode(init, scope, stack);
        TACCode* code2 = (TACCode*)malloc(sizeof(TACCode));
        scope.localscope = GetStackTop(stack)->localscope;
        TACCode* code3 = TranslateCondition(expr, scope, stack, label2, label3);
        TACCode* code4 = (TACCode*)malloc(sizeof(TACCode));
        scope.localscope = GetStackTop(stack)->localscope;
        TACCode* code5 = TranslateStmt(stmt, scope, stack);
        TACCode* code6 = GenerateInterCode(step, scope, stack);
        TACCode* code7 = (TACCode*)malloc(sizeof(TACCode));
        TACCode* code8 = (TACCode*)malloc(sizeof(TACCode));
        code2->code.opkind = LABELDF;
        code2->code.dest.kind = LABEL;
        code2->code.dest.labelvalue = label1;
        code2->line = tree->lchild->line;
        code2->prev = code2;
        code4->code.opkind = LABELDF;
        code4->code.dest.kind = LABEL;
        code4->code.dest.labelvalue = label2;
        code4->line = tree->lchild->line;
        code4->prev = code4;
        code7->code.opkind = GOTO;
        code7->code.dest.kind = LABEL;
        code7->code.dest.labelvalue = label1;
        code7->line = tree->lchild->line;
        code7->prev = code7;
        code8->code.opkind = LABELDF;
        code8->code.dest.kind = LABEL;
        code8->code.dest.labelvalue = label3;
        code8->line = tree->lchild->line;
        code8->prev = code8;
        return MergeTACCode(8, code1, code2, code3, code4, code5, code6, code7, code8);
    }
    else if (!strcmp(tree->lchild->name, "ReturnStmt"))
    {
        GrammarTree expr = tree->lchild->lchild->rchild;
        if (expr != NULL && !strcmp(expr->name, "Expr"))
        {
            char cache[8];
            Scope new_temp;
            TACCode* code1; 
            TACCode* code2 = (TACCode*)malloc(sizeof(TACCode));
            sprintf(cache, "_t%d", temp_num++);
            new_temp = AddTempIntoSymtable(scope.localscope, cache, Variable, 
                                            GetExprType(expr, stack)->type, NULL, stack, scope);
            scope.localscope = GetStackTop(stack)->localscope;
            code1 = TranslateExpr(expr, new_temp, stack, new_temp);
            code2->code.opkind = RETURN;
            code2->code.dest.kind = VARIABLE;
            code2->code.dest.variable = new_temp;
            code2->line = tree->lchild->line;
            code2->prev = code2;
            return MergeTACCode(2, code1, code2);
        }
    }
    else if (!strcmp(tree->lchild->name, "PrintStmt"))
    {
        GrammarTree expr = tree->lchild->lchild->rchild->rchild->lchild;
        if (!strcmp(expr->lchild->name, "Constant") && !strcmp(expr->lchild->lchild->name, "CONSTANTSTRING"))
        {
            char* str = expr->lchild->lchild->string_value;
            TACCode* tmp = NULL;
            TACCode* result = NULL;
            while (*str)
            {
                if (result == NULL)
                {
                    result = (TACCode*)malloc(sizeof(TACCode));
                    result->code.opkind = PRINTCHAR;
                    result->code.dest.kind = INTEGERCONST;
                    result->code.dest.intvalue = (int)(*str);
                    result->prev = result;
                }
                else
                {
                    tmp = (TACCode*)malloc(sizeof(TACCode));
                    tmp->code.opkind = PRINTCHAR;
                    tmp->code.dest.kind = INTEGERCONST;
                    tmp->code.dest.intvalue = (int)(*str);
                    tmp->prev = tmp;
                    result = MergeTACCode(2, result, tmp);
                }
                str += 1;
            }
            if (marg == 0)
            {
                tmp = (TACCode*)malloc(sizeof(TACCode));
                tmp->code.opkind = PRINTCHAR;
                tmp->code.dest.kind = INTEGERCONST;
                tmp->code.dest.intvalue = 13; // ASCII of "Enter"
                tmp->prev = tmp;
                result = MergeTACCode(2, result, tmp);
            }
            return result;
        }
        else 
        {
            Scope new_temp;
            char cache[8];
            sprintf(cache, "_t%d", temp_num++);
            new_temp = AddTempIntoSymtable(scope.localscope, cache, Variable, GetExprType(expr, stack)->type, NULL, stack, scope);
            scope.localscope = GetStackTop(stack)->localscope;
            TACCode* tmp = (TACCode*)malloc(sizeof(TACCode));
            tmp->code.opkind = PRINTID;
            tmp->code.dest.kind = VARIABLE;
            tmp->code.dest.variable = new_temp;
            tmp->prev = tmp;
            return MergeTACCode(2, TranslateExpr(expr, scope, stack, new_temp), tmp);
        }
    }
    else
        return GenerateInterCode(tree->lchild, scope, stack);
}

TACCode* GenerateInterCode(GrammarTree tree, Scope scope, ScopeStack* stack)  
{
    if (tree == NULL)
        return NULL;
    if (!strcmp(tree->name, "Program"))
    {
        PushScopeStack(stack, scope);
        return GenerateInterCode(tree->lchild, scope, stack);
    }
    else if (!strcmp(tree->name, "ClassDefs"))
    {
        if (!strcmp(tree->lchild->name, "ClassDef"))
            return GenerateInterCode(tree->lchild, scope, stack);
        else
            return MergeTACCode(2, GenerateInterCode(tree->lchild, scope, stack), 
                                GenerateInterCode(tree->lchild->rchild, scope, stack));
    }
    else if (!strcmp(tree->name, "VariableDef"))
    {
        return NULL;
    }
    else if (!strcmp(tree->name, "Variable"))
    {
        TACCode* tmp = (TACCode*)malloc(sizeof(TACCode));
        tmp->code.opkind = PARAM;
        tmp->code.dest.kind = VARIABLE;
        tmp->code.dest.variable = TraverseScopeStack(*stack, tree->lchild->rchild->string_value);
        tmp->line = tree->line;
        tmp->prev = tmp;
        return tmp;
    }
    else if (!strcmp(tree->name, "Type"))
        return NULL;
    else if (!strcmp(tree->name, "Variables"))
    {
        if (!strcmp(tree->lchild->name, "Variable"))
            return GenerateInterCode(tree->lchild, scope, stack);
        else
            return MergeTACCode(2, GenerateInterCode(tree->lchild, scope, stack), GenerateInterCode(tree->lchild->rchild->rchild, scope, stack));
    }
    else if (!strcmp(tree->name, "Formals"))
    {
        if (tree->line != -1)
            return GenerateInterCode(tree->lchild, scope, stack);
        else
            return NULL;
    }
    else if (!strcmp(tree->name, "FunctionDef"))
    {
        TACCode* tmp = (TACCode*)malloc(sizeof(TACCode));
        TACCode* formalcode = NULL;
        TACCode* bodycode = NULL;
        tmp->code.opkind = FUNCTIONDF;
        tmp->code.dest.kind = FUNCTION;
        if (strcmp(tree->lchild->name, "KEYSTATIC"))
            tmp->code.dest.function = TraverseScopeStack(*stack, tree->lchild->rchild->string_value);
        else
            tmp->code.dest.function = TraverseScopeStack(*stack, tree->lchild->rchild->rchild->string_value);
        tmp->line = tree->line;
        tmp->prev = tmp;
        FunctionDepictor funcdsp = tree->depictor.funcdsp;
        // Push function formals into scope stack
        scope.type = ScopeFormal;
        scope.formalscope = funcdsp->formalscope;
        PushScopeStack(stack, scope);
        if (strcmp(tree->lchild->name, "KEYSTATIC"))
            formalcode = GenerateInterCode(tree->lchild->rchild->rchild->rchild, scope, stack);
        else
            formalcode = GenerateInterCode(tree->lchild->rchild->rchild->rchild->rchild, scope, stack);
        // Push function body into scope stack
        scope.type = ScopeLocal;
        scope.localscope = funcdsp->formalscope->functionscope;
        PushScopeStack(stack, scope);
        if (strcmp(tree->lchild->name, "KEYSTATIC"))
            bodycode = GenerateInterCode(tree->lchild->rchild->rchild->rchild->rchild->rchild, scope, stack);
        else
            bodycode = GenerateInterCode(tree->lchild->rchild->rchild->rchild->rchild->rchild->rchild, scope, stack);
        return MergeTACCode(3, tmp, formalcode, bodycode);
    }
    else if (!strcmp(tree->name, "ClassDef"))
    {
        ClassDepictor classdsp = tree->depictor.classdsp;
        scope.type = ScopeClass;
        // Judge if the class has parent class
        if (classdsp->parent)
        {
            scope.classscope = classdsp->parent->classscope;
            // Push parent class into scope stack
            PushScopeStack(stack, scope);
        }
        scope.classscope = classdsp->classscope;
        PushScopeStack(stack, scope); 
        if (strcmp(tree->lchild->rchild->rchild->name, "KEYEXTENDS"))
        {
            //According the translation rule of c, the second parameter "GenerateInterCode" will operate first
            //The first parameter "GenerateInterCode" is used to traverse "SPRIGHTBRACE"
            return MergeTACCode(2, GenerateInterCode(tree->lchild->rchild->rchild->rchild->rchild, scope, stack),  
                                GenerateInterCode(tree->lchild->rchild->rchild->rchild, scope, stack));
        }
        else
        {
            return MergeTACCode(2, GenerateInterCode(tree->lchild->rchild->rchild->rchild->rchild->rchild->rchild, scope, stack), 
                                GenerateInterCode(tree->lchild->rchild->rchild->rchild->rchild->rchild, scope, stack));
        }
    }
    else if (!strcmp(tree->name, "Fields"))
    {
        if (tree->line != -1)
            return MergeTACCode(2, GenerateInterCode(tree->lchild, scope, stack), GenerateInterCode(tree->lchild->rchild, scope, stack));
        else
            return NULL;
    }
    else if (!strcmp(tree->name, "Field"))
    {
        return GenerateInterCode(tree->lchild, scope, stack);
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
        //According the translation rule of c, the second parameter "GenerateInterCode" will operate first
        //The first parameter "GenerateInterCode" is used to traverse "SPRIGHTBRACE"
        return MergeTACCode(2, GenerateInterCode(tree->lchild->rchild->rchild, scope, stack), 
                            GenerateInterCode(tree->lchild->rchild, scope, stack));
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
        return NULL;
    }
    else if (!strcmp(tree->name, "Stmts"))
    {
        if (tree->line != -1)
        {
            TACCode* code1 = GenerateInterCode(tree->lchild, scope, stack); 
            TACCode* code2 = GenerateInterCode(tree->lchild->rchild, scope, stack);
            return MergeTACCode(2, code1, code2);
        }
        else
            return NULL;
    }
    else if (!strcmp(tree->name, "Stmt"))
    {
        scope.localscope = GetStackTop(stack)->localscope;
        return TranslateStmt(tree, scope, stack);
    }
    else if (!strcmp(tree->name, "SimpleStmt") && !strcmp(tree->lchild->name, "LValue"))
    {
        if (!strcmp(tree->lchild->lchild->name, "IDENTIFIER"))
        {
            char cache[26];
            GrammarTree expr = tree->lchild->rchild->rchild;
            scope.localscope = GetStackTop(stack)->localscope;
            if (!strcmp(expr->lchild->name, "KEYNEW"))
            {
                // Apply for an object, then put it's all attribute into symbol table
                if (!strcmp(expr->lchild->rchild->name, "IDENTIFIER"))
                {
                    GlobalScope globalscope = stack->base->globalscope;
                    while (globalscope)
                    {
                        if (!strcmp(globalscope->name, expr->lchild->rchild->string_value))
                            break;
                        globalscope = globalscope->next;
                    }
                    ClassScope classscope = globalscope->depictor.classdsp->classscope;
                    while (classscope)
                    {
                        if (classscope->category == Variable)
                        {
                            sprintf(cache, "%s.%s", tree->lchild->lchild->string_value, classscope->name);
                            AddTempIntoSymtable(GetStackTop(stack)->localscope, cache, Variable, classscope->type, NULL, stack, scope);
                        }
                        classscope = classscope->next;
                    }
                }
                return NULL;
            }
            else
                return TranslateExpr(expr, scope, stack, TraverseScopeStack(*stack, tree->lchild->lchild->string_value));
        }
        else if (!strcmp(tree->lchild->lchild->rchild->name, "SPDOT"))
        {
            //LValue: Expr SPDOT IDENTIFIER
            GrammarTree expr = tree->lchild->rchild->rchild;
            GrammarTree object = tree->lchild->lchild;
            if (!strcmp(object->lchild->lchild->name, "IDENTIFIER"))
            {
                // Expr: LValue
                // LValue: IDENTIFIER
                char cache[26];
                sprintf(cache, "%s.%s", object->lchild->lchild->string_value, tree->lchild->lchild->rchild->rchild->string_value);
                return TranslateExpr(expr, *GetStackTop(stack), stack, TraverseScopeStack(*stack, cache));
            }
        }
    }
    else if (!strcmp(tree->name, "SimpleStmt") && !strcmp(tree->lchild->name, "Call"))
    {
        Scope variable;
        Scope function;
        GrammarTree actuals;
        if (!strcmp(tree->lchild->lchild->name, "IDENTIFIER"))
        {
            function = TraverseScopeStack(*stack, tree->lchild->lchild->string_value);
            actuals = tree->lchild->lchild->rchild->rchild;
        }
        else
        {
            if (!strcmp(tree->lchild->lchild->lchild->name, "LValue") 
             && !strcmp(tree->lchild->lchild->lchild->lchild->name, "IDENTIFIER"))
                variable = TraverseScopeStack(*stack, tree->lchild->lchild->lchild->lchild->string_value);
            function.type = ScopeClass;
            function.classscope = FindInClass(stack, variable.localscope->type + 6, tree->lchild->lchild->rchild->rchild->string_value, Function);
            actuals = tree->lchild->lchild->rchild->rchild->rchild->rchild;
        }
        LocalScope origin = GetStackTop(stack)->localscope;
        scope.localscope = origin;
        scope.localscope = GetStackTop(stack)->localscope;
        TACCode* code1 = TranslateArgs(actuals, scope, stack);
        LocalScope current = GetStackTop(stack)->localscope;
        TACCode* code2 = NULL;
        TACCode* code3 = NULL;
        TACCode* tmp = NULL;
        variable.type = ScopeLocal;
        while (current != origin && current != NULL)
        {
            if (code2 == NULL)
            {
                code2 = (TACCode*)malloc(sizeof(TACCode));
                code2->code.opkind = ARG;
                code2->code.dest.kind = VARIABLE;
                variable.localscope = current;
                code2->code.dest.variable = variable;
                code2->line = tree->line;
                code2->prev = code2;
            }
            else
            {
                tmp = (TACCode*)malloc(sizeof(TACCode));
                tmp->code.opkind = ARG;
                tmp->code.dest.kind = VARIABLE;
                variable.localscope = current;
                tmp->code.dest.variable = variable;
                tmp->line = tree->line;
                tmp->prev = tmp;
                code2 = MergeTACCode(2, code2, tmp);
            }
            current = current->next;
        }
        code3 = (TACCode*)malloc(sizeof(TACCode));
        code3->code.opkind = CALL;
        code3->code.dest.kind = FUNCTION;
        code3->code.dest.function = function;
        code3->line = tree->line;
        code3->prev = code3;
        return MergeTACCode(3, code1, code2, code3);
    }
    return MergeTACCode(2, GenerateInterCode(tree->rchild, scope, stack), GenerateInterCode(tree->lchild, scope, stack));
}

void DisplayTACCode(TACCode* entrance)
{
    int line = 1;
    TACCode* tmp = entrance;
    char cache[10];
    printf(" No  Source Position\tTACCode\n");
    printf("_______________________________________\n"); 
    printf("  0  (at line   0)\tCALL main\n");
    while (tmp)
    {
        if (tmp->code.opkind == ASSIGN)
        {
            // Notice: no matter variable is in which scope, the scope entry always has "name" attribute
            printf("%3d  (at line %3d)\t%s := ", line, tmp->line, tmp->code.dest.variable.localscope->name);
            if (tmp->code.firstsrc.kind == VARIABLE)
                printf("%s\n", tmp->code.firstsrc.variable.localscope->name);
            else if (tmp->code.firstsrc.kind == ADDRESSS)
                printf("*%s\n", tmp->code.firstsrc.variable.localscope->name);
            else if (tmp->code.firstsrc.kind == INTEGERCONST)
                printf("#%d\n", tmp->code.firstsrc.intvalue);
            else if (tmp->code.firstsrc.kind == FLOATCONST)
                printf("#%d\n", tmp->code.firstsrc.floatvalue);
        }
        else if (tmp->code.opkind == ADD | tmp->code.opkind == SUB | tmp->code.opkind == MUL | tmp->code.opkind == DIV)
        {
            // Notice: no matter variable  is in which scope, the scope entry always has "name" attribute
            printf("%3d  (at line %3d)\t%s := ", line, tmp->line, tmp->code.dest.variable.localscope->name);
            if (tmp->code.firstsrc.kind == VARIABLE)
                printf("%s ", tmp->code.firstsrc.variable.localscope->name);
            else if (tmp->code.firstsrc.kind == ADDRESSS)
                printf("*%s ", tmp->code.firstsrc.variable.localscope->name);
            else if (tmp->code.firstsrc.kind == INTEGERCONST)
                printf("#%d ", tmp->code.firstsrc.intvalue);
            else if (tmp->code.firstsrc.kind == FLOATCONST)
                printf("#%d ", tmp->code.firstsrc.floatvalue);
            switch (tmp->code.opkind)
            {
                case ADD:
                    printf("+ ");
                    break;
                case SUB:
                    printf("- ");
                    break;
                case MUL:
                    printf("* ");
                    break;
                case DIV:
                    printf("/ ");
                    break;
            }
            if (tmp->code.secondsrc.kind == VARIABLE)
                printf("%s\n", tmp->code.secondsrc.variable.localscope->name);
            else if (tmp->code.secondsrc.kind == ADDRESSS)
                printf("*%s\n", tmp->code.secondsrc.variable.localscope->name);
            else if (tmp->code.secondsrc.kind == INTEGERCONST)
                printf("#%d\n", tmp->code.secondsrc.intvalue);
            else if (tmp->code.secondsrc.kind == FLOATCONST)
                printf("#%d\n", tmp->code.secondsrc.floatvalue);
        }
        else if (tmp->code.opkind == FUNCTIONDF)
            printf("\n%3d  (at line %3d)\tFUNCTION %s :\n", line, tmp->line, tmp->code.dest.function.classscope->name);
        else if (tmp->code.opkind == PARAM)
            printf("%3d  (at line %3d)\tPARAM %s\n", line, tmp->line, tmp->code.dest.variable.formalscope->name);
        else if (tmp->code.opkind == LABELDF)
        {
            sprintf(cache, "label%d", tmp->code.dest.labelvalue);
            printf("%3d  (at line %3d)\tLABEL %s :\n", line, tmp->line, cache);
        }
        else if (tmp->code.opkind == IFLTGOTO)
        {
            sprintf(cache, "label%d", tmp->code.dest.labelvalue);
            printf("%3d  (at line %3d)\tIF %s < %s GOTO %s\n", 
                   line, tmp->line, tmp->code.firstsrc.variable.localscope->name, tmp->code.secondsrc.variable.localscope->name, cache);
        }
        else if (tmp->code.opkind == IFLEGOTO)
        {
            sprintf(cache, "label%d", tmp->code.dest.labelvalue);
            printf("%3d  (at line %3d)\tIF %s <= %s GOTO %s\n", 
                   line, tmp->line, tmp->code.firstsrc.variable.localscope->name, tmp->code.secondsrc.variable.localscope->name, cache);
        }
        else if (tmp->code.opkind == IFGTGOTO)
        {
            sprintf(cache, "label%d", tmp->code.dest.labelvalue);
            printf("%3d  (at line %3d)\tIF %s > %s GOTO %s\n", 
                   line, tmp->line, tmp->code.firstsrc.variable.localscope->name, tmp->code.secondsrc.variable.localscope->name, cache);
        }
        else if (tmp->code.opkind == IFGEGOTO)
        {
            sprintf(cache, "label%d", tmp->code.dest.labelvalue);
            printf("%3d  (at line %3d)\tIF %s >= %s GOTO %s\n", 
                   line, tmp->line, tmp->code.firstsrc.variable.localscope->name, tmp->code.secondsrc.variable.localscope->name, cache);
        }
        else if (tmp->code.opkind == IFEQGOTO)
        {
            sprintf(cache, "label%d", tmp->code.dest.labelvalue);
            printf("%3d  (at line %3d)\tIF %s = %s GOTO %s\n", 
                   line, tmp->line, tmp->code.firstsrc.variable.localscope->name, tmp->code.secondsrc.variable.localscope->name, cache);
        }
        else if (tmp->code.opkind == IFNEQGOTO)
        {
            sprintf(cache, "label%d", tmp->code.dest.labelvalue);
            printf("%3d  (at line %3d)\tIF %s != ", line, tmp->line, tmp->code.firstsrc.variable.localscope->name);
            if (tmp->code.secondsrc.kind == VARIABLE)
                printf("%s ", tmp->code.secondsrc.variable.localscope->name);
            else if (tmp->code.secondsrc.kind == INTEGERCONST)
                printf("%d ", tmp->code.secondsrc.intvalue);
            printf("GOTO %s\n", cache);
        }
        else if (tmp->code.opkind == GOTO)
        {
            sprintf(cache, "label%d", tmp->code.dest.labelvalue);
            printf("%3d  (at line %3d)\tGOTO %s\n", line, tmp->line, cache);
        }
        else if (tmp->code.opkind == RETURN)
        {
            printf("%3d  (at line %3d)\tRETURN %s\n", line, tmp->line, tmp->code.dest.variable.localscope->name);
        }
        else if (tmp->code.opkind == ARG)
        {
            printf("%3d  (at line %3d)\tARG %s\n", line, tmp->line, tmp->code.dest.variable.localscope->name);
        }
        else if (tmp->code.opkind == CALLASSIGN)
        {
            printf("%3d  (at line %3d)\t%s := CALL %s\n", line, tmp->line, tmp->code.dest.variable.localscope->name, tmp->code.firstsrc.function.localscope->name);
        }
        else if (tmp->code.opkind == CALL)
        {
            printf("%3d  (at line %3d)\tCALL %s\n", line, tmp->line, tmp->code.dest.function.localscope->name);
        }
        tmp = tmp->next;
        line += 1;
    }
}

Scope AddTempIntoSymtable(LocalScope local_symtable, char* name, DecafCategory category, char* type, LocalScope embededscope, ScopeStack* stack, Scope scope)
{
    FormalScope formalscope;
    LocalScope localscope;
    Scope tmp;
    LocalScope new_temp = AddIntoLocal(local_symtable, name, category, type, embededscope);
    PopScopeStack(stack, &tmp);
    if (GetStackTop(stack)->type == ScopeFormal)
    {
        formalscope = GetStackTop(stack)->formalscope;
        while (formalscope)
        {
            formalscope->functionscope = new_temp;
            formalscope = formalscope->next;
        }
    }
    else if (GetStackTop(stack)->type == ScopeLocal)
    {
        localscope = GetStackTop(stack)->localscope;
        while (localscope)
        {
            if (localscope->category == Block && localscope->embededscope == local_symtable)
            {
                localscope->embededscope = new_temp;
                break;
            }
            localscope = localscope->next;
        }
    }
    tmp.type = ScopeLocal;
    tmp.localscope = new_temp;
    PushScopeStack(stack, tmp);
    return tmp;
}
