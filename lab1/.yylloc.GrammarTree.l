%{
    #include<stdio.h>
    #include<stdlib.h>
    #include"GrammarTree.h"
    #include"GrammarTree.tab.h"

    int yycolumn = 1;
    #define YY_USER_ACTION \
      yylloc.first_line = yylloc.last_line = yylineno; \
      yylloc.firt_column = yycolumn; \
      yylloc.last_column = yycolumn + yyleng - 1; \
      yycolumn += yyleng;

%}

%option yylineno

SPSEMICOLON     ";"
SPCOMMA         ","
SPDOT           "."
SPLEFTBRACE     "{"
SPRIGHTBRACE    "}"
OPLEFTPRNT      "("
OPRIGHTPRNT     ")"
OPLEFTBRACKET   "["
OPRIGHTBRACKET  "]"
OPPLUS          "+"
OPMINUS         "-"
OPMULTIPLY      "*"
OPDIVIDE        "/"
OPASSIGN        "="
OPAND           "&&"
OPOR            "||"
OPNOT           "!"
OPEQUAL         "=="
OPNOTEQUAL      "!="
OPGREAT         ">"
OPLIGHT         "<"
OPGREATEQ       ">="
OPLIGHTEQ       "<="
TYPEVOID        "void"
TYPEINTEGER     "int"
TYPEFLOAT       "float"
TYPEBOOL        "bool"
TYPESTRING      "string"
KEYCLASS        "class"
KEYNEW          "new"
KEYEXTENDS      "extends"
KEYTHIS         "this"
KEYINSTANCEOF   "instanceof"
KEYIF           "if"
KEYELSE         "else"
KEYFOR          "for"
KEYWHILE        "while"
KEYBREAK        "break"
KEYRETURN       "return"
KEYSTATIC       "static"
KEYPRINT        "Print"
KEYREADINTEGER  "ReadInteger"
KEYREADLINE     "ReadLine"
CONSTANTNULL    "null"
CONSTANTBOOL    "true"|"false"
CONSTANTFLOAT   [+-]?([0-9]*\.?[0-9]+|[0-9]+\.)
CONSTANTFLOATSC [+-]?[0-9]+\.?[0-9]*([eE]{CONSTANTINTD})?
CONSTANTINTD    [+-]?[0-9]+
CONSTANTINTH    [+-]?0[xX][0-9a-fA-F]+
CONSTANTSTRING  \".*\"
IDENTIFIER      [a-zA-Z][a-zA-Z0-9_]* 
COMMENT         \/\/.*
SPACE           " "|\t
EOL             \n
AERROR          .

%%
{SPSEMICOLON} { 
    printf("(%s, SPSEMICOLON)\n", yytext); 
    yylval.grammar_tree = CreateGrammarTree("SPSEMICOLON", 0, yylineno);
    return SPSEMICOLON;
}
{SPCOMMA} { 
    printf("(%s, SPCOMMA)\n", yytext); 
    yylval.grammar_tree = CreateGrammarTree("SPCOMMA", 0, yylineno);
    return SPCOMMA;
}
{SPDOT} { 
    printf("(%s, SPDOT)\n", yytext); 
    yylval.grammar_tree = CreateGrammarTree("SPDOT", 0, yylineno);
    return SPDOT;
}
{SPLEFTBRACE} { 
    printf("(%s, SPLEFTBRACE)\n", yytext); 
    yylval.grammar_tree = CreateGrammarTree("SPLEFTBRACE", 0, yylineno);
    return SPLEFTBRACE;
}
{SPRIGHTBRACE} { 
    printf("(%s, SPRIGHTBRACE)\n", yytext); 
    yylval.grammar_tree = CreateGrammarTree("SPRIGHTBRACE", 0, yylineno);
    return SPRIGHTBRACE;
}
{OPLEFTPRNT} { 
    printf("(%s, OPLEFTPRNT)\n", yytext); 
    yylval.grammar_tree = CreateGrammarTree("OPLEFTPRNT", 0, yylineno);
    return OPLEFTPRNT;
}
{OPRIGHTPRNT} { 
    printf("(%s, OPRIGHTPRNT)\n", yytext); 
    yylval.grammar_tree = CreateGrammarTree("OPRIGHTPRNT", 0, yylineno);
    return OPRIGHTPRNT;
}
{OPLEFTBRACKET} { 
    printf("(%s, OPLEFTBRACKET)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("OPLEFTBRACKET", 0, yylineno);
    return OPLEFTBRACKET;
}
{OPRIGHTBRACKET} { 
    printf("(%s, OPRIGHTBRACKET)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("OPRIGHTBRACKET", 0, yylineno);
    return OPRIGHTBRACKET;
}
{OPPLUS} { 
    printf("(%s, OPPLUS)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("OPPLUS", 0, yylineno);
    return OPPLUS;
}
{OPMINUS} { 
    printf("(%s, OPMINUS)\n", yytext); 
    yylval.grammar_tree = CreateGrammarTree("OPMINUS", 0, yylineno);
    return OPMINUS;
}
{OPMULTIPLY} { 
    printf("(%s, OPMULTIPLY)\n", yytext); 
    yylval.grammar_tree = CreateGrammarTree("OPMULTIPLY", 0, yylineno);
    return OPMULTIPLY;
}
{OPDIVIDE} { 
    printf("(%s, OPDIVIDE)\n", yytext); 
    yylval.grammar_tree = CreateGrammarTree("OPDIVIDE", 0, yylineno);
    return OPDIVIDE;
}
{OPASSIGN} { 
    printf("(%s, OPASSIGN)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("OPASSIGN", 0, yylineno);
    return OPASSIGN;
}
{OPAND} { 
    printf("(%s, OPAND)\n", yytext); 
    yylval.grammar_tree = CreateGrammarTree("OPAND", 0, yylineno);
    return OPAND;
}
{OPOR} { 
    printf("(%s, OPOR)\n", yytext); 
    yylval.grammar_tree = CreateGrammarTree("OPOR", 0, yylineno);
    return OPOR;
}
{OPNOT} { 
    printf("(%s, OPNOT)\n", yytext); 
    yylval.grammar_tree = CreateGrammarTree("OPNOT", 0, yylineno);
    return OPNOT;
}
{OPEQUAL} { 
    printf("(%s, OPEQUAL)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("OPEQUAL", 0, yylineno);
    return OPEQUAL;
}
{OPNOTEQUAL} { 
    printf("(%s, OPNOTEQUAL)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("OPNOTEQUAL", 0, yylineno);
    return OPNOTEQUAL;
}
{OPGREAT} { 
    printf("(%s, OPGREAT)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("OPGREAT", 0, yylineno);
    return OPGREAT;
}
{OPLIGHT} { 
    printf("(%s, OPLIGHT)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("OPLIGHT", 0, yylineno);
    return OPLIGHT;
}
{OPGREATEQ} { 
    printf("(%s, OPGREATEQ)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("OPGREATEQ", 0, yylineno);
    return OPGREATEQ;
}
{OPLIGHTEQ} { 
    printf("(%s, OPLIGHTEQ)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("OPLIGHTEQ", 0, yylineno);
    return OPLIGHTEQ;
}
{TYPEVOID} { 
    printf("(%s, TYPEVOID)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("TYPEVOID", 0, yylineno);
    return TYPEVOID;
}
{TYPEINTEGER} { 
    printf("(%s, TYPEINTEGER)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("TYPEINTEGER", 0, yylineno);
    return TYPEINTEGER;
}
{TYPEFLOAT} { 
    printf("(%s, TYPEFLOAT)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("TYPEFLOAT", 0, yylineno);
    return TYPEFLOAT;
}
{TYPEBOOL} { 
    printf("(%s, TYPEBOOL)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("TYPEBOOL", 0, yylineno);
    return TYPEBOOL;
}
{TYPESTRING} { 
    printf("(%s, TYPESTRING)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("TYPESTRING", 0, yylineno);
    return TYPESTRING;
}
{KEYCLASS} { 
    printf("(%s, KEYCLASS)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("KEYCLASS", 0, yylineno);
    return KEYCLASS;
}
{KEYNEW} { 
    printf("(%s, KEYNEW)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("KEYNEW", 0, yylineno);
    return KEYNEW;
}
{KEYEXTENDS} { 
    printf("(%s, KEYEXTENDS)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("KEYEXTENDS", 0, yylineno);
    return KEYEXTENDS;
}
{KEYTHIS} { 
    printf("(%s, KEYTHIS)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("KEYTHIS", 0, yylineno);
    return KEYTHIS;
}
{KEYINSTANCEOF} { 
    printf("(%s, KEYINSTANCEOF)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("KEYINSTANCEOF", 0, yylineno);
    return KEYINSTANCEOF;
}
{KEYIF} { 
    printf("(%s, KEYIF)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("KEYIF", 0, yylineno);
    return KEYIF;
}
{KEYELSE} { 
    printf("(%s, KEYELSE)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("KEYELSE", 0, yylineno);
    return KEYELSE;
}
{KEYFOR} { 
    printf("(%s, KEYFOR)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("KEYFOR", 0, yylineno);
    return KEYFOR;
}
{KEYWHILE} { 
    printf("(%s, KEYWHILE)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("KEYWHILE", 0, yylineno);
    return KEYWHILE;
}
{KEYBREAK} { 
    printf("(%s, KEYBREAK)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("KEYBREAK", 0, yylineno);
    return KEYBREAK;
}
{KEYRETURN} { 
    printf("(%s, KEYRETURN)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("KEYRETURN", 0, yylineno);
    return KEYRETURN;
}
{KEYSTATIC} { 
    printf("(%s, KEYSTATIC)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("KEYSTATIC", 0, yylineno);
    return KEYSTATIC;
}
{KEYPRINT} { 
    printf("(%s, KEYPRINT)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("KEYPRINT", 0, yylineno);
    return KEYPRINT;
}
{KEYREADINTEGER} { 
    printf("(%s, KEYREADINTEGER)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("KEYREADINTEGER", 0, yylineno);
    return KEYREADINTEGER;
}
{KEYREADLINE} { 
    printf("(%s, KEYREADLINE)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("KEYREADLINE", 0, yylineno);
    return KEYREADLINE;
}
{CONSTANTNULL} { 
    printf("(%s, CONSTANTNULL)\n", yytext); 
    yylval.grammar_tree = CreateGrammarTree("CONSTANTNULL", 0, yylineno);
    return CONSTANTNULL;
}
{CONSTANTBOOL} { 
    printf("(%s, CONSTANTBOOL)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("CONSTANTBOOL", 0, yylineno);
    return CONSTANTBOOL;
}
{CONSTANTINTD} { 
    printf("(%s, CONSTANTINTD)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("CONSTANTINTD", 0, yylineno);
    return CONSTANTINTD;
}
{CONSTANTINTH} { 
    printf("(%s, CONSTANTINTH)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("CONSTANTINTH", 0, yylineno);
    return CONSTANTINTH;
}
{CONSTANTFLOAT} { 
    printf("(%s, CONSTANTFLOAT)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("CONSTANTFLOAT", 0, yylineno);
    return CONSTANTFLOAT;
}
{CONSTANTFLOATSC} { 
    printf("(%s, CONSTANTFLOATSC)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("CONSTANTFLOATSC", 0, yylineno);
    return CONSTANTFLOATSC;
}
{CONSTANTSTRING} { 
    printf("(%s, CONSTANTSTRING)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("CONSTANTSTRING", 0, yylineno);
    return CONSTANTSTRING;
}
{IDENTIFIER} { 
    printf("(%s, IDENTIFIER)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("IDENTIFIER", 0, yylineno);
    return IDENTIFIER;
}
{COMMENT} { printf("(%s, COMMENT)\n", yytext); }
{SPACE} { printf("(%s, SPACE)\n", yytext); }
{EOL} { printf("(\\n, EOL)\n"); yycolumn = 1; }
{AERROR} { printf("Error type A at line %d: Mysterious characters \'%s\'\n", yylineno, yytext); exit(-1); }
%%
