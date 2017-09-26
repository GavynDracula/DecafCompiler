%{
    #include<stdio.h>
    #include<stdlib.h>
    #include"GrammarTree.h"
    #include"GrammarTree.tab.h"

    int two_tuples_trigger = 0;  // the trigger controling wether display two-tuples of lexical analyzing

    int yycolumn = 1;
    #define YY_USER_ACTION \
      yylloc.first_line = yylloc.last_line = yylineno; \
      yylloc.first_column = yycolumn; \
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
CONSTANTSTRING  \"[^\"\n]*\"
IDENTIFIER      [a-zA-Z][a-zA-Z0-9_]* 
COMMENT         (\/\/.*)|(\/\*((\*[^\/]?)|[^\*]*)*\*\/)
SPACE           " "|\t
EOL             \n
WRONGSTRING     \"[^\"\n]*$
WRONGIDENTIFIER [0-9_][a-zA-Z0-9_]* 
AERROR          .

%%
{SPSEMICOLON} { 
    if (two_tuples_trigger)
        printf("(%s, SPSEMICOLON)\n", yytext); 
    yylval.grammar_tree = CreateGrammarTree("SPSEMICOLON", 0, yylineno);
    return SPSEMICOLON;
}
{SPCOMMA} { 
    if (two_tuples_trigger)
        printf("(%s, SPCOMMA)\n", yytext); 
    yylval.grammar_tree = CreateGrammarTree("SPCOMMA", 0, yylineno);
    return SPCOMMA;
}
{SPDOT} { 
    if (two_tuples_trigger)
        printf("(%s, SPDOT)\n", yytext); 
    yylval.grammar_tree = CreateGrammarTree("SPDOT", 0, yylineno);
    return SPDOT;
}
{SPLEFTBRACE} { 
    if (two_tuples_trigger)
        printf("(%s, SPLEFTBRACE)\n", yytext); 
    yylval.grammar_tree = CreateGrammarTree("SPLEFTBRACE", 0, yylineno);
    return SPLEFTBRACE;
}
{SPRIGHTBRACE} { 
    if (two_tuples_trigger)
        printf("(%s, SPRIGHTBRACE)\n", yytext); 
    yylval.grammar_tree = CreateGrammarTree("SPRIGHTBRACE", 0, yylineno);
    return SPRIGHTBRACE;
}
{OPLEFTPRNT} { 
    if (two_tuples_trigger)
        printf("(%s, OPLEFTPRNT)\n", yytext); 
    yylval.grammar_tree = CreateGrammarTree("OPLEFTPRNT", 0, yylineno);
    return OPLEFTPRNT;
}
{OPRIGHTPRNT} { 
    if (two_tuples_trigger)
        printf("(%s, OPRIGHTPRNT)\n", yytext); 
    yylval.grammar_tree = CreateGrammarTree("OPRIGHTPRNT", 0, yylineno);
    return OPRIGHTPRNT;
}
{OPLEFTBRACKET} { 
    if (two_tuples_trigger)
        printf("(%s, OPLEFTBRACKET)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("OPLEFTBRACKET", 0, yylineno);
    return OPLEFTBRACKET;
}
{OPRIGHTBRACKET} { 
    if (two_tuples_trigger)
        printf("(%s, OPRIGHTBRACKET)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("OPRIGHTBRACKET", 0, yylineno);
    return OPRIGHTBRACKET;
}
{OPPLUS} { 
    if (two_tuples_trigger)
        printf("(%s, OPPLUS)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("OPPLUS", 0, yylineno);
    return OPPLUS;
}
{OPMINUS} { 
    if (two_tuples_trigger)
        printf("(%s, OPMINUS)\n", yytext); 
    yylval.grammar_tree = CreateGrammarTree("OPMINUS", 0, yylineno);
    return OPMINUS;
}
{OPMULTIPLY} { 
    if (two_tuples_trigger)
        printf("(%s, OPMULTIPLY)\n", yytext); 
    yylval.grammar_tree = CreateGrammarTree("OPMULTIPLY", 0, yylineno);
    return OPMULTIPLY;
}
{OPDIVIDE} { 
    if (two_tuples_trigger)
        printf("(%s, OPDIVIDE)\n", yytext); 
    yylval.grammar_tree = CreateGrammarTree("OPDIVIDE", 0, yylineno);
    return OPDIVIDE;
}
{OPASSIGN} { 
    if (two_tuples_trigger)
        printf("(%s, OPASSIGN)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("OPASSIGN", 0, yylineno);
    return OPASSIGN;
}
{OPAND} { 
    if (two_tuples_trigger)
        printf("(%s, OPAND)\n", yytext); 
    yylval.grammar_tree = CreateGrammarTree("OPAND", 0, yylineno);
    return OPAND;
}
{OPOR} { 
    if (two_tuples_trigger)
        printf("(%s, OPOR)\n", yytext); 
    yylval.grammar_tree = CreateGrammarTree("OPOR", 0, yylineno);
    return OPOR;
}
{OPNOT} { 
    if (two_tuples_trigger)
        printf("(%s, OPNOT)\n", yytext); 
    yylval.grammar_tree = CreateGrammarTree("OPNOT", 0, yylineno);
    return OPNOT;
}
{OPEQUAL} { 
    if (two_tuples_trigger)
        printf("(%s, OPEQUAL)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("OPEQUAL", 0, yylineno);
    return OPEQUAL;
}
{OPNOTEQUAL} { 
    if (two_tuples_trigger)
        printf("(%s, OPNOTEQUAL)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("OPNOTEQUAL", 0, yylineno);
    return OPNOTEQUAL;
}
{OPGREAT} { 
    if (two_tuples_trigger)
        printf("(%s, OPGREAT)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("OPGREAT", 0, yylineno);
    return OPGREAT;
}
{OPLIGHT} { 
    if (two_tuples_trigger)
        printf("(%s, OPLIGHT)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("OPLIGHT", 0, yylineno);
    return OPLIGHT;
}
{OPGREATEQ} { 
    if (two_tuples_trigger)
        printf("(%s, OPGREATEQ)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("OPGREATEQ", 0, yylineno);
    return OPGREATEQ;
}
{OPLIGHTEQ} { 
    if (two_tuples_trigger)
        printf("(%s, OPLIGHTEQ)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("OPLIGHTEQ", 0, yylineno);
    return OPLIGHTEQ;
}
{TYPEVOID} { 
    if (two_tuples_trigger)
        printf("(%s, TYPEVOID)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("TYPEVOID", 0, yylineno);
    return TYPEVOID;
}
{TYPEINTEGER} { 
    if (two_tuples_trigger)
        printf("(%s, TYPEINTEGER)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("TYPEINTEGER", 0, yylineno);
    return TYPEINTEGER;
}
{TYPEFLOAT} { 
    if (two_tuples_trigger)
        printf("(%s, TYPEFLOAT)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("TYPEFLOAT", 0, yylineno);
    return TYPEFLOAT;
}
{TYPEBOOL} { 
    if (two_tuples_trigger)
        printf("(%s, TYPEBOOL)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("TYPEBOOL", 0, yylineno);
    return TYPEBOOL;
}
{TYPESTRING} { 
    if (two_tuples_trigger)
        printf("(%s, TYPESTRING)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("TYPESTRING", 0, yylineno);
    return TYPESTRING;
}
{KEYCLASS} { 
    if (two_tuples_trigger)
        printf("(%s, KEYCLASS)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("KEYCLASS", 0, yylineno);
    return KEYCLASS;
}
{KEYNEW} { 
    if (two_tuples_trigger)
        printf("(%s, KEYNEW)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("KEYNEW", 0, yylineno);
    return KEYNEW;
}
{KEYEXTENDS} { 
    if (two_tuples_trigger)
        printf("(%s, KEYEXTENDS)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("KEYEXTENDS", 0, yylineno);
    return KEYEXTENDS;
}
{KEYTHIS} { 
    if (two_tuples_trigger)
        printf("(%s, KEYTHIS)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("KEYTHIS", 0, yylineno);
    return KEYTHIS;
}
{KEYINSTANCEOF} { 
    if (two_tuples_trigger)
        printf("(%s, KEYINSTANCEOF)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("KEYINSTANCEOF", 0, yylineno);
    return KEYINSTANCEOF;
}
{KEYIF} { 
    if (two_tuples_trigger)
        printf("(%s, KEYIF)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("KEYIF", 0, yylineno);
    return KEYIF;
}
{KEYELSE} { 
    if (two_tuples_trigger)
        printf("(%s, KEYELSE)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("KEYELSE", 0, yylineno);
    return KEYELSE;
}
{KEYFOR} { 
    if (two_tuples_trigger)
        printf("(%s, KEYFOR)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("KEYFOR", 0, yylineno);
    return KEYFOR;
}
{KEYWHILE} { 
    if (two_tuples_trigger)
        printf("(%s, KEYWHILE)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("KEYWHILE", 0, yylineno);
    return KEYWHILE;
}
{KEYBREAK} { 
    if (two_tuples_trigger)
        printf("(%s, KEYBREAK)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("KEYBREAK", 0, yylineno);
    return KEYBREAK;
}
{KEYRETURN} { 
    if (two_tuples_trigger)
        printf("(%s, KEYRETURN)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("KEYRETURN", 0, yylineno);
    return KEYRETURN;
}
{KEYSTATIC} { 
    if (two_tuples_trigger)
        printf("(%s, KEYSTATIC)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("KEYSTATIC", 0, yylineno);
    return KEYSTATIC;
}
{KEYPRINT} { 
    if (two_tuples_trigger)
        printf("(%s, KEYPRINT)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("KEYPRINT", 0, yylineno);
    return KEYPRINT;
}
{KEYREADINTEGER} { 
    if (two_tuples_trigger)
        printf("(%s, KEYREADINTEGER)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("KEYREADINTEGER", 0, yylineno);
    return KEYREADINTEGER;
}
{KEYREADLINE} { 
    if (two_tuples_trigger)
        printf("(%s, KEYREADLINE)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("KEYREADLINE", 0, yylineno);
    return KEYREADLINE;
}
{CONSTANTNULL} { 
    if (two_tuples_trigger)
        printf("(%s, CONSTANTNULL)\n", yytext); 
    yylval.grammar_tree = CreateGrammarTree("CONSTANTNULL", 0, yylineno);
    return CONSTANTNULL;
}
{CONSTANTBOOL} { 
    if (two_tuples_trigger)
        printf("(%s, CONSTANTBOOL)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("CONSTANTBOOL", 0, yylineno);
    return CONSTANTBOOL;
}
{CONSTANTINTD} { 
    if (two_tuples_trigger)
        printf("(%s, CONSTANTINTD)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("CONSTANTINTD", 0, yylineno);
    return CONSTANTINTD;
}
{CONSTANTINTH} { 
    if (two_tuples_trigger)
        printf("(%s, CONSTANTINTH)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("CONSTANTINTH", 0, yylineno);
    return CONSTANTINTH;
}
{CONSTANTFLOAT} { 
    if (two_tuples_trigger)
        printf("(%s, CONSTANTFLOAT)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("CONSTANTFLOAT", 0, yylineno);
    return CONSTANTFLOAT;
}
{CONSTANTFLOATSC} { 
    if (two_tuples_trigger)
        printf("(%s, CONSTANTFLOATSC)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("CONSTANTFLOATSC", 0, yylineno);
    return CONSTANTFLOATSC;
}
{CONSTANTSTRING} { 
    if (two_tuples_trigger)
        printf("(%s, CONSTANTSTRING)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("CONSTANTSTRING", 0, yylineno);
    return CONSTANTSTRING;
}
{IDENTIFIER} { 
    if (two_tuples_trigger)
        printf("(%s, IDENTIFIER)\n", yytext);
    yylval.grammar_tree = CreateGrammarTree("IDENTIFIER", 0, yylineno);
    return IDENTIFIER;
}
{COMMENT} { if (two_tuples_trigger) printf("(%s, COMMENT)\n", yytext); }
{SPACE} { if (two_tuples_trigger) printf("(%s, SPACE)\n", yytext); }
{EOL} { if (two_tuples_trigger) printf("(\\n, EOL)\n"); yycolumn = 1; }
{WRONGSTRING} {
    printf("Error type A at Line %d column %d: Missing \"\"\".\n", yylineno, yylloc.last_column); 
    exit(-1);
}
{WRONGIDENTIFIER} {
    printf("Error type A at Line %d column %d: Wrong format of identifier.\n", yylineno, yylloc.first_column); 
    exit(-1);
}
{AERROR} { 
    printf("Error type A at Line %d column %d: Mysterious characters \"%s\".\n", yylineno, yylloc.first_column, yytext); 
    exit(-1); 
}
%%
