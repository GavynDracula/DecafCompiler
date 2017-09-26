%{
    #include<stdio.h>
    #include<unistd.h>
    #include"GrammarTree.h"
    #include"lex.yy.c"
    void yyerror(const char* fmt, ...);
%}

%error-verbose
%locations

%union {
    GrammarTree grammar_tree;
}

%token <grammar_tree> SPSEMICOLON SPCOMMA SPDOT SPLEFTBRACE SPRIGHTBRACE
%token <grammar_tree> OPLEFTPRNT OPRIGHTPRNT OPLEFTBRACKET OPRIGHTBRACKET
%token <grammar_tree> OPPLUS OPMINUS OPMULTIPLY OPDIVIDE OPASSIGN
%token <grammar_tree> OPAND OPOR OPNOT
%token <grammar_tree> OPEQUAL OPNOTEQUAL OPGREAT OPLIGHT OPGREATEQ OPLIGHTEQ
%token <grammar_tree> TYPEVOID TYPEINTEGER TYPEFLOAT TYPEBOOL TYPESTRING
%token <grammar_tree> KEYCLASS KEYNEW KEYEXTENDS KEYTHIS KEYINSTANCEOF
%token <grammar_tree> KEYIF KEYELSE KEYFOR KEYWHILE KEYBREAK
%token <grammar_tree> KEYRETURN 
%token <grammar_tree> KEYSTATIC
%token <grammar_tree> KEYPRINT KEYREADINTEGER KEYREADLINE
%token <grammar_tree> CONSTANTNULL CONSTANTBOOL CONSTANTINTD CONSTANTINTH CONSTANTFLOAT CONSTANTFLOATSC CONSTANTSTRING
%token <grammar_tree> IDENTIFIER

%type <grammar_tree> Program ClassDefs VariableDef CommaIdentifiers Variable Type Variables Formals FunctionDef ClassDef Fields Field StmtBlock Stmts Stmt SimpleStmt LValue Call Actuals Exprs ForStmt WhileStmt IfStmt ReturnStmt BreakStmt PrintStmt BoolExpr Expr Constant

%right OPASSIGN
%left OPOR
%left OPAND
%left OPLIGHT OPLIGHTEQ OPGREAT OPGREATEQ OPEQUAL OPNOTEQUAL
%left OPPLUS OPMINUS
%left OPMULTIPLY OPDIVIDE
%right OPNOT
%left SPDOT
%left OPRIGHTBRACKET
%right OPLEFTBRACKET
%left OPRIGHTPRNT
%right OPLEFTPRNT

%nonassoc LOWER_THAN_ELSE
%nonassoc KEYELSE 

%%
Program: ClassDefs { 
       $$ = CreateGrammarTree("Program", 1, $1); 
       if (two_tuples_trigger)
       {
           printf("__________________________________________________\n\n");
           printf("The two-tuples of \"Lexical Analyzing\" are printed!\n");
           printf("__________________________________________________\n");
       }
       if (!gmerror) {
           printf("\nNow print the grammar-tree of \"Grammar Analyzing\":\n");
           printf("__________________________________________________\n\n"); 
           TraverseGrammerTree($$, 0);
           printf("__________________________________________________\n\n"); 
           printf("The grammar-tree of \"Grammar Analyzing\" is printed!\n\n"); 
       }
       }
       ;

ClassDefs: ClassDef { $$ = CreateGrammarTree("ClassDefs", 1, $1); }
         | ClassDefs ClassDef { $$ = CreateGrammarTree("ClassDefs", 2, $1, $2); }
         ;

VariableDef: Variable SPSEMICOLON { $$ = CreateGrammarTree("VariableDef", 2, $1, $2); }
           | Variable CommaIdentifiers SPSEMICOLON { $$ = CreateGrammarTree("VariableDef", 3, $1, $2, $3); } 
           | error SPSEMICOLON { $$ = CreateGrammarTree("VariableDef", 1, $2); gmerror += 1; }
           ;

CommaIdentifiers: SPCOMMA IDENTIFIER { $$ = CreateGrammarTree("CommaIdentifiers", 2, $1, $2); } 
                | CommaIdentifiers SPCOMMA IDENTIFIER { $$ = CreateGrammarTree("CommaIdentifiers", 3, $1, $2, $3); } 
                ;

Variable: Type IDENTIFIER { $$ = CreateGrammarTree("Variable", 2, $1, $2); }
        ;

Type: TYPEINTEGER { $$ = CreateGrammarTree("Type", 1, $1); }
    | TYPEFLOAT { $$ = CreateGrammarTree("Type", 1, $1); }
    | TYPEBOOL { $$ = CreateGrammarTree("Type", 1, $1); }
    | TYPESTRING { $$ = CreateGrammarTree("Type", 1, $1); }
    | TYPEVOID { $$ = CreateGrammarTree("Type", 1, $1); }
    | KEYCLASS IDENTIFIER { $$ = CreateGrammarTree("Type", 2, $1, $2); }
    | Type OPLEFTBRACKET OPRIGHTBRACKET { $$ = CreateGrammarTree("Type", 3, $1, $2, $3); }
    ;

Variables: Variable { $$ = CreateGrammarTree("Variables", 1, $1); }
         | Variables SPCOMMA Variable { $$ = CreateGrammarTree("Variables", 3, $1, $2, $3); }
         ;

Formals: { $$ = CreateGrammarTree("Formals", 0, -1); }
       | Variables { $$ = CreateGrammarTree("Formals", 1, $1); }
       ;

FunctionDef: Type IDENTIFIER OPLEFTPRNT Formals OPRIGHTPRNT StmtBlock { $$ = CreateGrammarTree("FunctionDef", 6, $1, $2, $3, $4, $5, $6); }
           | KEYSTATIC Type IDENTIFIER OPLEFTPRNT Formals OPRIGHTPRNT StmtBlock { $$ = CreateGrammarTree("FunctionDef", 7, $1, $2, $3, $4, $5, $6, $7); }
           ;

ClassDef: KEYCLASS IDENTIFIER SPLEFTBRACE Fields SPRIGHTBRACE { $$ = CreateGrammarTree("ClassDef", 5, $1, $2, $3, $4, $5); }
        | KEYCLASS IDENTIFIER KEYEXTENDS IDENTIFIER SPLEFTBRACE Fields SPRIGHTBRACE { $$ = CreateGrammarTree("ClassDef", 7, $1, $2, $3, $4, $5, $6, $7); }
        | error SPRIGHTBRACE { $$ = CreateGrammarTree("ClassDef", 1, $2); gmerror += 1; }
        ;

Fields: { $$ = CreateGrammarTree("Fields", 0, -1); }
      | Field Fields { $$ = CreateGrammarTree("Fields", 2, $1, $2); }
      ;

Field: VariableDef { $$ = CreateGrammarTree("Field", 1, $1); }
     | FunctionDef { $$ = CreateGrammarTree("Field", 1, $1); }
     ;

StmtBlock: SPLEFTBRACE Stmts SPRIGHTBRACE { $$ = CreateGrammarTree("StmtBlock", 3, $1, $2, $3); }
         | error SPRIGHTBRACE { $$ = CreateGrammarTree("StmtBlock", 1, $2); gmerror += 1; }
         ;

Stmts: { $$ = CreateGrammarTree("Stmts", 0, -1); }
     | Stmt Stmts { $$ = CreateGrammarTree("Stmts", 2, $1, $2); }
     ;

Stmt: VariableDef { $$ = CreateGrammarTree("Stmt", 1, $1); }
    | SimpleStmt SPSEMICOLON { $$ = CreateGrammarTree("Stmt", 2, $1, $2); }
    | IfStmt { $$ = CreateGrammarTree("Stmt", 1, $1); }
    | WhileStmt { $$ = CreateGrammarTree("Stmt", 1, $1); }
    | ForStmt { $$ = CreateGrammarTree("Stmt", 1, $1); }
    | BreakStmt SPSEMICOLON { $$ = CreateGrammarTree("Stmt", 2, $1, $2); }
    | ReturnStmt SPSEMICOLON { $$ = CreateGrammarTree("Stmt", 2, $1, $2); }
    | PrintStmt SPSEMICOLON { $$ = CreateGrammarTree("Stmt", 2, $1, $2); }
    | StmtBlock { $$ = CreateGrammarTree("Stmt", 1, $1); }
    ;

SimpleStmt: { $$ = CreateGrammarTree("SimpleStmt", 0, -1); } 
          | LValue OPASSIGN Expr { $$ = CreateGrammarTree("SimpleStmt", 3, $1, $2, $3); } 
          | Call { $$ = CreateGrammarTree("SimpleStmt", 1, $1); } 
          ;

LValue: IDENTIFIER { $$ = CreateGrammarTree("LValue", 1, $1); }  
      | Expr SPDOT IDENTIFIER { $$ = CreateGrammarTree("LValue", 3, $1, $2, $3); }  
      | Expr OPLEFTBRACKET Expr OPRIGHTBRACKET { $$ = CreateGrammarTree("LValue", 4, $1, $2, $3, $4); }  
      ;

Call: IDENTIFIER OPLEFTPRNT Actuals OPRIGHTPRNT { $$ = CreateGrammarTree("Call", 4, $1, $2, $3, $4); }  
    | Expr SPDOT IDENTIFIER OPLEFTPRNT Actuals OPRIGHTPRNT { $$ = CreateGrammarTree("Call", 6, $1, $2, $3, $4, $5, $6); }  
    ;

Actuals: { $$ = CreateGrammarTree("Actuals", 0, -1); }
       | Exprs { $$ = CreateGrammarTree("Actuals", 1, $1); }

Exprs: Expr { $$ = CreateGrammarTree("Exprs", 1, $1); }
     | Exprs SPCOMMA Expr { $$ = CreateGrammarTree("Exprs", 3, $1, $2, $3); }
     ;

ForStmt: KEYFOR OPLEFTPRNT SimpleStmt SPSEMICOLON BoolExpr SPSEMICOLON SimpleStmt OPRIGHTPRNT Stmt { $$ = CreateGrammarTree("ForStmt", 9, $1, $2, $3, $4, $5, $6, $7, $8, $9); }  
       ;

WhileStmt: KEYWHILE OPLEFTPRNT BoolExpr OPRIGHTPRNT Stmt { $$ = CreateGrammarTree("WhileStmt", 5, $1, $2, $3, $4, $5); }  
         ;

IfStmt: KEYIF OPLEFTPRNT BoolExpr OPRIGHTPRNT Stmt %prec LOWER_THAN_ELSE { $$ = CreateGrammarTree("IfStmt", 5, $1, $2, $3, $4, $5); }  
      | KEYIF OPLEFTPRNT BoolExpr OPRIGHTPRNT Stmt KEYELSE Stmt { $$ = CreateGrammarTree("IfStmt", 7, $1, $2, $3, $4, $5, $6, $7); }  
      ;

ReturnStmt: KEYRETURN { $$ = CreateGrammarTree("ReturnStmt", 1, $1); }
          | KEYRETURN Expr { $$ = CreateGrammarTree("ReturnStmt", 2, $1, $2); } 
          ;

BreakStmt: KEYBREAK { $$ = CreateGrammarTree("BreakStmt", 1, $1); }
         ;

PrintStmt: KEYPRINT OPLEFTPRNT Exprs OPRIGHTPRNT { $$ = CreateGrammarTree("PrintStmt", 4, $1, $2, $3, $4); }  
         ;

BoolExpr: Expr { $$ = CreateGrammarTree("BoolExpr", 1, $1); }
        ;

Expr: Constant { $$ = CreateGrammarTree("Expr", 1, $1); }
    | LValue { $$ = CreateGrammarTree("Expr", 1, $1); }
    | KEYTHIS { $$ = CreateGrammarTree("Expr", 1, $1); }
    | Call { $$ = CreateGrammarTree("Expr", 1, $1); }
    | OPLEFTPRNT Expr OPRIGHTPRNT { $$ = CreateGrammarTree("Expr", 3, $1, $2, $3); }
    | Expr OPPLUS Expr { $$ = CreateGrammarTree("Expr", 3, $1, $2, $3); }
    | Expr OPMINUS Expr { $$ = CreateGrammarTree("Expr", 3, $1, $2, $3); }
    | Expr OPMULTIPLY Expr { $$ = CreateGrammarTree("Expr", 3, $1, $2, $3); }
    | Expr OPDIVIDE Expr { $$ = CreateGrammarTree("Expr", 3, $1, $2, $3); }
    | OPMINUS Expr { $$ = CreateGrammarTree("Expr", 2, $1, $2); }
    | Expr OPLIGHT Expr { $$ = CreateGrammarTree("Expr", 3, $1, $2, $3); }
    | Expr OPLIGHTEQ Expr { $$ = CreateGrammarTree("Expr", 3, $1, $2, $3); }
    | Expr OPGREAT Expr { $$ = CreateGrammarTree("Expr", 3, $1, $2, $3); }
    | Expr OPGREATEQ Expr { $$ = CreateGrammarTree("Expr", 3, $1, $2, $3); }
    | Expr OPEQUAL Expr { $$ = CreateGrammarTree("Expr", 3, $1, $2, $3); }
    | Expr OPNOTEQUAL Expr { $$ = CreateGrammarTree("Expr", 3, $1, $2, $3); }
    | Expr OPAND Expr { $$ = CreateGrammarTree("Expr", 3, $1, $2, $3); }
    | Expr OPOR Expr { $$ = CreateGrammarTree("Expr", 3, $1, $2, $3); }
    | OPNOT Expr { $$ = CreateGrammarTree("Expr", 2, $1, $2); }
    | KEYREADINTEGER OPLEFTPRNT OPRIGHTPRNT { $$ = CreateGrammarTree("Expr", 3, $1, $2, $3); }
    | KEYREADLINE OPLEFTPRNT OPRIGHTPRNT { $$ = CreateGrammarTree("Expr", 3, $1, $2, $3); }
    | KEYNEW IDENTIFIER OPLEFTPRNT OPRIGHTPRNT { $$ = CreateGrammarTree("Expr", 4, $1, $2, $3, $4); }
    | KEYNEW Type OPLEFTBRACKET Expr OPRIGHTBRACKET { $$ = CreateGrammarTree("Expr", 5, $1, $2, $3, $4, $5); }
    | KEYINSTANCEOF OPLEFTPRNT Expr SPCOMMA IDENTIFIER OPRIGHTPRNT { $$ = CreateGrammarTree("Expr", 6, $1, $2, $3, $4, $5, $6); }
    | OPLEFTPRNT KEYCLASS IDENTIFIER OPRIGHTPRNT Expr { $$ = CreateGrammarTree("Expr", 5, $1, $2, $3, $4, $5); }
    ;

Constant: CONSTANTINTD { $$ = CreateGrammarTree("Constant", 1, $1); }
        | CONSTANTINTH { $$ = CreateGrammarTree("Constant", 1, $1); }
        | CONSTANTFLOAT { $$ = CreateGrammarTree("Constant", 1, $1); }
        | CONSTANTFLOATSC { $$ = CreateGrammarTree("Constant", 1, $1); }
        | CONSTANTBOOL { $$ = CreateGrammarTree("Constant", 1, $1); }
        | CONSTANTSTRING { $$ = CreateGrammarTree("Constant", 1, $1); }
        | CONSTANTNULL { $$ = CreateGrammarTree("Constant", 1, $1); }
        ;

%%

#include<stdarg.h>

void yyerror(const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "Error type B at Line %d Column %d: ", yylineno, yylloc.first_column);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, ".\n");
}

