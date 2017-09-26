/*************************************************************************
	> File Name: main.h
	> Author: GuanyuLi
	> Mail: guanyuli@hustunique.com
	> Created Time: Thu 22 Dec 2016 06:52:14 PM CST
 ************************************************************************/

#ifndef _MAIN_H
#define _MAIN_H

#include<stdio.h>
#include<string.h>

extern FILE* yyin;
extern int yyparse();
extern int darg, garg, iarg, sarg, marg, oarg;
extern FILE* fp;

#endif
