/*************************************************************************
	> File Name: ObjectCode.c
	> Author: GuanyuLi
	> Mail: guanyuli@hustunique.com
	> Created Time: Fri 16 Dec 2016 04:46:29 PM CST
 ************************************************************************/

#include"ObjectCode.h"

int mulop = 0;
RegDepictorEntry RegDepictor[32];

char RegName[32][6] = {
    "$zero",
    "$at",
    "$v0", "$v1",
    "$a0", "$a1", "$a2", "$a3", 
    "$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", 
    "$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7", 
    "$t8", "$t9",
    "$k0", "$k1",
    "$gp", "$sp", "$fp", "$ra"
};

int GetReg(FILE* fp, Scope variable)
{
    int i;
    if (variable.type == ScopeFormal)
    {
        if (variable.formalscope->reg != 0)
        {
            RegDepictor[variable.formalscope->reg].used += 1;
            return variable.formalscope->reg;
        }
        else
        {
            for (i = 8; i <= 25; i++)
            {
                if (RegDepictor[i].filled == 0)
                {
                    RegDepictor[i].filled = 1;
                    RegDepictor[i].used = 0;
                    RegDepictor[i].variable = variable;
                    variable.formalscope->reg = i;
                    fprintf(fp, "lw %s, %d($fp)\n", RegName[i], variable.formalscope->offset);
                    return i;
                }
            }
            for (i = 8; i <= 25; i++)
            {
                if (RegDepictor[i].used == 0)
                {
                    fprintf(fp, "sw %s, %d($fp)\n", RegName[i], RegDepictor[i].variable.formalscope->offset);
                    RegDepictor[i].variable = variable;
                    variable.formalscope->reg = i;
                    fprintf(fp, "lw %s, %d($fp)\n", RegName[i], variable.formalscope->offset);
                    RegDepictor[i].used = 0;
                    return i;
                }
            }
            fprintf(fp, "sw %s, %d($fp)\n", RegName[8], RegDepictor[8].variable.formalscope->offset);
            fprintf(fp, "lw %s, %d($fp)\n", RegName[8], variable.formalscope->offset);
            RegDepictor[8].used = 0;
            return 8;
        }
    }
    else if (variable.type == ScopeLocal)
    {
        if (variable.localscope->reg != 0)
        {
            RegDepictor[variable.localscope->reg].used += 1;
            return variable.localscope->reg;
        }
        else
        {
            for (i = 8; i <= 25; i++)
            {
                if (RegDepictor[i].filled == 0)
                {
                    RegDepictor[i].filled = 1;
                    RegDepictor[i].used = 0;
                    RegDepictor[i].variable = variable;
                    variable.localscope->reg = i;
                    fprintf(fp, "lw %s, %d($fp)\n", RegName[i], variable.localscope->offset);
                    return i;
                }
            }
            for (i = 8; i <= 25; i++)
            {
                if (RegDepictor[i].used == 0)
                {
                    fprintf(fp, "sw %s, %d($fp)\n", RegName[i], RegDepictor[i].variable.localscope->offset);
                    RegDepictor[i].variable.localscope->reg = 0;
                    RegDepictor[i].variable = variable;
                    variable.localscope->reg = i;
                    fprintf(fp, "lw %s, %d($fp)\n", RegName[i], variable.localscope->offset);
                    RegDepictor[i].used = 0;
                    return i;
                }
            }
            fprintf(fp, "sw %s, %d($fp)\n", RegName[8], RegDepictor[8].variable.localscope->offset);
            RegDepictor[8].variable.localscope->reg = 0;
            RegDepictor[8].variable = variable;
            variable.localscope->reg = 8;
            fprintf(fp, "lw %s, %d($fp)\n", RegName[8], variable.localscope->offset);
            RegDepictor[8].used = 0;
            return 8;
        }
    }
    else
        return 0;
}

int AllocateLocal(LocalScope localvariable, int offset)
{
    while (localvariable)
    {
        if (localvariable->category == Variable)
        {
            localvariable->offset = -offset;
            offset = offset + 4;
        }
        else if (localvariable->category == Block)
            offset = AllocateLocal(localvariable->embededscope, offset);
        localvariable = localvariable->next;
    }
    return offset;
}

void GenerateObjectCode(FILE* fp, TACCode* entrance)
{
    int line = 1;
    TACCode* tmp = entrance;
    char cache[10];
    if (marg == 0)
    {
        fprintf(fp, "ori $sp, $0, 1023\n");
        fprintf(fp, "ori $fp, $0, 1023\n");
    }
    fprintf(fp, "jal main\n");
    fprintf(fp, "ori $v0, $0, 10\n");
    fprintf(fp, "syscall\n");
    while (tmp)
    {
        if (tmp->code.opkind == ASSIGN && tmp->code.dest.kind == VARIABLE)
        {
            if (tmp->code.firstsrc.kind == VARIABLE)
                fprintf(fp, "addu %s, %s, $0\n", RegName[GetReg(fp, tmp->code.dest.variable)], RegName[GetReg(fp, tmp->code.firstsrc.variable)]);
            else if (tmp->code.firstsrc.kind == ADDRESSS)
                fprintf(fp, "lw %s, 0(%s)\n", RegName[GetReg(fp, tmp->code.dest.variable)], RegName[GetReg(fp, tmp->code.firstsrc.variable)]);
            else if (tmp->code.firstsrc.kind == INTEGERCONST)
                fprintf(fp, "ori %s, $0, %d\n", RegName[GetReg(fp, tmp->code.dest.variable)], tmp->code.firstsrc.intvalue);
            else if (tmp->code.firstsrc.kind == FLOATCONST)
                ;
            fprintf(fp, "sw %s, %d($fp)\n", RegName[GetReg(fp, tmp->code.dest.variable)], tmp->code.dest.variable.localscope->offset);
        }
        else if (tmp->code.opkind == ASSIGN && tmp->code.dest.kind == ADDRESSS)
            fprintf(fp, "sw %s, 0(%s)\n", RegName[GetReg(fp, tmp->code.firstsrc.variable)], RegName[GetReg(fp, tmp->code.dest.variable)]);
        else if (tmp->code.opkind == ADD) 
        {
            if (tmp->code.firstsrc.kind == VARIABLE && tmp->code.secondsrc.kind == VARIABLE)
                fprintf(fp, "add %s, %s, %s\n", RegName[GetReg(fp, tmp->code.dest.variable)], 
                        RegName[GetReg(fp, tmp->code.firstsrc.variable)], RegName[GetReg(fp, tmp->code.secondsrc.variable)]);
            else if (tmp->code.firstsrc.kind == VARIABLE && tmp->code.secondsrc.kind == INTEGERCONST)
                fprintf(fp, "addi %s, %s, #%d\n", RegName[GetReg(fp, tmp->code.dest.variable)], 
                        RegName[GetReg(fp, tmp->code.firstsrc.variable)], tmp->code.secondsrc.intvalue);
            else if (tmp->code.firstsrc.kind == INTEGERCONST && tmp->code.secondsrc.kind == VARIABLE)
                fprintf(fp, "addi %s, %s, #%d\n", RegName[GetReg(fp, tmp->code.dest.variable)], 
                        RegName[GetReg(fp, tmp->code.secondsrc.variable)], tmp->code.firstsrc.intvalue);
            else if (tmp->code.firstsrc.kind == INTEGERCONST && tmp->code.secondsrc.kind == INTEGERCONST)
                fprintf(fp, "ori %s, $0, %d\n", RegName[GetReg(fp, tmp->code.dest.variable)], tmp->code.firstsrc.intvalue + tmp->code.secondsrc.intvalue);
            fprintf(fp, "sw %s, %d($fp)\n", RegName[GetReg(fp, tmp->code.dest.variable)], tmp->code.dest.variable.localscope->offset);
        }
        else if (tmp->code.opkind == SUB)
        {
            if (tmp->code.firstsrc.kind == VARIABLE && tmp->code.secondsrc.kind == VARIABLE)
                fprintf(fp, "sub %s, %s, %s\n", RegName[GetReg(fp, tmp->code.dest.variable)], 
                        RegName[GetReg(fp, tmp->code.firstsrc.variable)], RegName[GetReg(fp, tmp->code.secondsrc.variable)]);
            else if (tmp->code.firstsrc.kind == VARIABLE && tmp->code.secondsrc.kind == INTEGERCONST)
                fprintf(fp, "addi %s, %s, #-%d\n", RegName[GetReg(fp, tmp->code.dest.variable)], 
                        RegName[GetReg(fp, tmp->code.firstsrc.variable)], tmp->code.secondsrc.intvalue);
            else if (tmp->code.firstsrc.kind == INTEGERCONST && tmp->code.secondsrc.kind == VARIABLE)
                fprintf(fp, "addi %s, %s, #-%d\n", RegName[GetReg(fp, tmp->code.dest.variable)], 
                        RegName[GetReg(fp, tmp->code.secondsrc.variable)], tmp->code.firstsrc.intvalue);
            else if (tmp->code.firstsrc.kind == INTEGERCONST && tmp->code.secondsrc.kind == INTEGERCONST)
                fprintf(fp, "ori %s, $0, %d\n", RegName[GetReg(fp, tmp->code.dest.variable)], tmp->code.firstsrc.intvalue - tmp->code.secondsrc.intvalue);
            fprintf(fp, "sw %s, %d($fp)\n", RegName[GetReg(fp, tmp->code.dest.variable)], tmp->code.dest.variable.localscope->offset);
        }
        else if (tmp->code.opkind == MUL)
        {
            mulop += 1;
            fprintf(fp, "addi $sp, $sp, -8\n");
            fprintf(fp, "sw $a0, 4($sp)\n");
            fprintf(fp, "sw $a1, 8($sp)\n");
            fprintf(fp, "addu $a0, %s, $0\n", RegName[GetReg(fp, tmp->code.firstsrc.variable)]);
            fprintf(fp, "addu $a1, %s, $0\n", RegName[GetReg(fp, tmp->code.secondsrc.variable)]);
            fprintf(fp, "sll $a0, $a0, 16\n");
            fprintf(fp, "sll $a1, $a1, 16\n");
            fprintf(fp, "jal booth_mul\n");
            fprintf(fp, "addu %s, $v0, $0\n", RegName[GetReg(fp, tmp->code.dest.variable)]);
            fprintf(fp, "lw $a0, 4($sp)\n");
            fprintf(fp, "lw $a1, 8($sp)\n");
            fprintf(fp, "addi $sp, $sp, 8\n");
            fprintf(fp, "sw %s, %d($fp)\n", RegName[GetReg(fp, tmp->code.dest.variable)], tmp->code.dest.variable.localscope->offset);
        }
        else if (tmp->code.opkind == DIV)
        {
            fprintf(fp, "div %s, %s\n", RegName[GetReg(fp, tmp->code.firstsrc.variable)], RegName[GetReg(fp, tmp->code.secondsrc.variable)]);
            fprintf(fp, "mflo %s\n", RegName[GetReg(fp, tmp->code.dest.variable)]);
            fprintf(fp, "sw %s, %d($fp)\n", RegName[GetReg(fp, tmp->code.dest.variable)], tmp->code.dest.variable.localscope->offset);
        }
        else if (tmp->code.opkind == FUNCTIONDF)
        {
            int i = 0;
            int offset;
            TACCode* param = tmp;
            LocalScope localvariable = tmp->code.dest.function.classscope->depictor.funcdsp->formalscope->functionscope;
            fprintf(fp, "\n%s:\n", tmp->code.dest.function.classscope->name);
            fprintf(fp, "sw $ra, 0($sp)\n");
            fprintf(fp, "sw $fp, -4($sp)\n");
            fprintf(fp, "addu $fp, $sp, $0\n");
            for (i = 8; i <= 25; i++)
                RegDepictor[i].filled = 0;
            i = 0;
            while (param->next->code.opkind == PARAM)
            {
                param = param->next;
                if (i < 4)
                {
                    param->code.dest.variable.formalscope->reg = i + 4;
                    RegDepictor[i + 4].variable = param->code.dest.variable;
                }
                else
                    param->code.dest.variable.formalscope->offset = (i - 3) * 4;
                i += 1;
            }
            // Modify
            i = (i - 3) * 4;
            while (param->code.opkind == PARAM)
            {
                if (param->code.dest.variable.formalscope->offset > 0)
                    param->code.dest.variable.formalscope->offset = i - param->code.dest.variable.formalscope->offset;
                else
                    break;
                param = param->prev;
            }
            offset = AllocateLocal(localvariable, 8);
            fprintf(fp, "ori $1, $0, %d\n", offset + 4);
            fprintf(fp, "sw $1, -%d($sp)\n", offset);
            fprintf(fp, "sub $sp, $sp, $1\n");
        }
        else if (tmp->code.opkind == LABELDF)
        {
            sprintf(cache, "label%d", tmp->code.dest.labelvalue);
            fprintf(fp, "%s:\n", cache);
        }
        else if (tmp->code.opkind == IFLTGOTO)
        {
            sprintf(cache, "label%d", tmp->code.dest.labelvalue);
            fprintf(fp, "slt $1, %s, %s\n", RegName[GetReg(fp, tmp->code.firstsrc.variable)], RegName[GetReg(fp, tmp->code.secondsrc.variable)]);
            fprintf(fp, "addi, $1, $1, -1\n");
            fprintf(fp, "beq $1, $0, %s\n", cache);
        }
        else if (tmp->code.opkind == IFLEGOTO)
        {
            sprintf(cache, "label%d", tmp->code.dest.labelvalue);
            fprintf(fp, "beq %s, %s, %s\n", RegName[GetReg(fp, tmp->code.firstsrc.variable)], RegName[GetReg(fp, tmp->code.secondsrc.variable)], cache);
            fprintf(fp, "slt $1, %s, %s\n", RegName[GetReg(fp, tmp->code.firstsrc.variable)], RegName[GetReg(fp, tmp->code.secondsrc.variable)]);
            fprintf(fp, "addi, $1, $1, -1\n");
            fprintf(fp, "beq $1, $0, %s\n", cache);
        }
        else if (tmp->code.opkind == IFGTGOTO)
        {
            sprintf(cache, "label%d", tmp->code.dest.labelvalue);
            fprintf(fp, "slt $1, %s, %s\n", RegName[GetReg(fp, tmp->code.secondsrc.variable)], RegName[GetReg(fp, tmp->code.firstsrc.variable)]);
            fprintf(fp, "addi, $1, $1, -1\n");
            fprintf(fp, "beq $1, $0, %s\n", cache);
        }
        else if (tmp->code.opkind == IFGEGOTO)
        {
            sprintf(cache, "label%d", tmp->code.dest.labelvalue);
            fprintf(fp, "beq %s, %s, %s\n", RegName[GetReg(fp, tmp->code.secondsrc.variable)], RegName[GetReg(fp, tmp->code.firstsrc.variable)], cache);
            fprintf(fp, "slt $1, %s, %s\n", RegName[GetReg(fp, tmp->code.secondsrc.variable)], RegName[GetReg(fp, tmp->code.firstsrc.variable)]);
            fprintf(fp, "addi, $1, $1, -1\n");
            fprintf(fp, "beq $1, $0, %s\n", cache);
        }
        else if (tmp->code.opkind == IFEQGOTO)
        {
            sprintf(cache, "label%d", tmp->code.dest.labelvalue);
            fprintf(fp, "beq %s, %s, %s\n", RegName[GetReg(fp, tmp->code.firstsrc.variable)], RegName[GetReg(fp, tmp->code.secondsrc.variable)], cache);
        }
        else if (tmp->code.opkind == IFNEQGOTO)
        {
            sprintf(cache, "label%d", tmp->code.dest.labelvalue);
            if (tmp->code.secondsrc.kind == VARIABLE)
                fprintf(fp, "bne %s, %s, %s\n", RegName[GetReg(fp, tmp->code.firstsrc.variable)], RegName[GetReg(fp, tmp->code.secondsrc.variable)], cache);
            else if (tmp->code.secondsrc.kind == INTEGERCONST)
            {
                fprintf(fp, "ori $1, $0, %d\n", tmp->code.secondsrc.intvalue);
                fprintf(fp, "bne %s, $1, %s\n", RegName[GetReg(fp, tmp->code.firstsrc.variable)], cache);
            }
        }
        else if (tmp->code.opkind == GOTO)
        {
            sprintf(cache, "label%d", tmp->code.dest.labelvalue);
            fprintf(fp, "j %s\n", cache);
        }
        else if (tmp->code.opkind == RETURN)
        {
            int i;
            fprintf(fp, "lw $1, 4($sp)\n");
            fprintf(fp, "add $sp, $sp, $1\n");
            fprintf(fp, "lw $ra, 0($sp)\n");
            fprintf(fp, "lw $fp, -4($sp)\n");
            fprintf(fp, "addu $v0, %s, $0\n", RegName[GetReg(fp, tmp->code.dest.variable)]);
            fprintf(fp, "jr $ra\n");
        }
        else if (tmp->code.opkind == CALLASSIGN)
        {
            TACCode* arg = tmp;
            int i = 0;
            int j;
            while (arg->prev->code.opkind == ARG)
            {
                arg = arg->prev;
                if (i < 4)
                    fprintf(fp, "addu %s, %s, $0\n", RegName[i + 4], RegName[GetReg(fp, arg->code.dest.variable)]);
                else
                    fprintf(fp, "sw %s, -%d($sp)\n", RegName[GetReg(fp, arg->code.dest.variable)], (i - 4) * 4);
                i += 1;
            }
            if (i > 4)
            {
                fprintf(fp, "ori $1, $0, %d\n", (i - 4) * 4);
                fprintf(fp, "sub $sp, $sp, $1\n");
            }
            for (j = 8; j <= 25; j++)
            {
                if (RegDepictor[j].filled)
                {
                    fprintf(fp, "sw %s, %d($fp)\n", RegName[j], RegDepictor[j].variable.localscope->offset);
                    RegDepictor[j].filled = 0;
                    RegDepictor[j].used = 0;
                    RegDepictor[j].variable.localscope->reg = 0;
                }
            }
            fprintf(fp, "jal %s\n", tmp->code.firstsrc.function.classscope->name);
            if (i > 4)
            {
                fprintf(fp, "ori $1, $0, %d\n", (i - 4) * 4);
                fprintf(fp, "add $sp, $sp, $1\n");
            }
            fprintf(fp, "addu %s, $v0, $0\n", RegName[GetReg(fp, tmp->code.dest.variable)]);
        }
        else if (tmp->code.opkind == CALL)
        {
            TACCode* arg = tmp;
            int i = 0;
            int j;
            while (arg->prev->code.opkind == ARG)
            {
                arg = arg->prev;
                if (i < 4)
                    fprintf(fp, "addu %s, %s, $0\n", RegName[i + 4], RegName[GetReg(fp, arg->code.dest.variable)]);
                else
                    fprintf(fp, "sw %s, -%d($sp)\n", RegName[GetReg(fp, arg->code.dest.variable)], (i - 4) * 4);
                i += 1;
            }
            if (i > 4)
            {
                fprintf(fp, "ori $1, $0, %d\n", (i - 4) * 4);
                fprintf(fp, "sub $sp, $sp, $1\n");
            }
            for (j = 8; j <= 25; j++)
            {
                if (RegDepictor[j].filled)
                {
                    fprintf(fp, "sw %s, %d($fp)\n", RegName[j], RegDepictor[j].variable.localscope->offset);
                    RegDepictor[j].filled = 0;
                    RegDepictor[j].used = 0;
                    RegDepictor[j].variable.localscope->reg = 0;
                }
            }
            fprintf(fp, "jal %s\n", tmp->code.firstsrc.function.classscope->name);
            if (i > 4)
            {
                fprintf(fp, "ori $1, $0, %d\n", (i - 4) * 4);
                fprintf(fp, "add $sp, $sp, $1\n");
            }
        }
        else if (tmp->code.opkind == PRINTID)
        {
            fprintf(fp, "addu $a0, %s, $0\n", RegName[GetReg(fp, tmp->code.dest.variable)]);
            fprintf(fp, "ori $v0, $0, 1\n");
            fprintf(fp, "syscall\n");
        }
        else if (tmp->code.opkind == PRINTCHAR)
        {
            fprintf(fp, "ori $a0, $0, %d\n", tmp->code.dest.intvalue);
            fprintf(fp, "ori $v0, $0, 11\n");
            fprintf(fp, "syscall\n");
        }
        else if (tmp->code.opkind == READINT)
        {
            fprintf(fp, "ori $v0, $0, 5\n");
            fprintf(fp, "syscall\n");
            fprintf(fp, "addu %s, $v0, $0\n", RegName[GetReg(fp, tmp->code.dest.variable)]);
        }
        tmp = tmp->next;
        line += 1;
    }
    if (mulop != 0)
    {
        fprintf(fp, "\nbooth_mul:\n");
        fprintf(fp, "srl  $a0, $a0, 16\n");
        fprintf(fp, "addi $a2, $0, 16\n");
        fprintf(fp, "add  $v0, $0, $a0\n");
        fprintf(fp, "addi $a3, $0, 0\n");
        fprintf(fp, "booth_loop:\n");
        fprintf(fp, "andi $t2, $a0, 1\n");
        fprintf(fp, "beq  $a3, $t2, booth_l1\n");
        fprintf(fp, "slt  $t3, $t2, $a3\n");
        fprintf(fp, "beq  $t3, $0, booth_l2\n");
        fprintf(fp, "add  $v0, $v0, $a1\n");
        fprintf(fp, "j    booth_l1\n");
        fprintf(fp, "booth_l2:\n");
        fprintf(fp, "sub  $v0, $v0, $a1\n");
        fprintf(fp, "booth_l1:\n");
        fprintf(fp, "sra  $v0, $v0, 1\n");
        fprintf(fp, "add  $a3, $t2, $0\n");
        fprintf(fp, "sra  $a0, $a0, 1\n");
        fprintf(fp, "addi $a2, $a2, -1\n");
        fprintf(fp, "bne  $a2, $0, booth_loop\n");
        fprintf(fp, "add  $s0, $v0, $0\n");
        fprintf(fp, "jr   $ra\n");
    }
}
