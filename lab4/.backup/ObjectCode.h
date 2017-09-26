/*************************************************************************
	> File Name: ObjectCode.h
	> Author: GuanyuLi
	> Mail: guanyuli@hustunique.com
	> Created Time: Fri 16 Dec 2016 04:46:34 PM CST
 ************************************************************************/

#ifndef _OBJECTCODE_H
#define _OBJECTCODE_H

#include<stdio.h>
#include<stdlib.h>
#include"IntermediateCode.h"

typedef enum Register
{
    Reg_zero, 
    Reg_at, 
    Reg_v0, Reg_v1, 
    Reg_a0, Reg_a1, Reg_a2, Reg_a3,
    Reg_t0, Reg_t1, Reg_t2, Reg_t3, Reg_t4, Reg_t5, Reg_t6, Reg_t7,
    Reg_s0, Reg_s1, Reg_s2, Reg_s3, Reg_s4, Reg_s5, Reg_s6, Reg_s7, 
    Reg_t8, Reg_t9,
    Reg_k0, Reg_k1,
    Reg_gp, Reg_sp, Reg_fp, Reg_ra
} Register;

typedef struct RegDepictorEntry
{
    int filled;
    int used;
    Scope variable;
} RegDepictorEntry;

extern int marg;

int GetReg(FILE* fp, Scope variable);
int AllocateLocal(LocalScope localvariable, int offset);
void GenerateObjectCode(FILE* fp, TACCode* entrance);

#endif
