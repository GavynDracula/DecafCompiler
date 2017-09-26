/*************************************************************************
	> File Name: main.c
	> Author: GuanyuLi
	> Mail: guanyuli@hustunique.com
	> Created Time: Thu 22 Dec 2016 06:51:28 PM CST
 ************************************************************************/

#include"main.h"

int main(int argc, char** argv)
{
    int i;
    int source = 0;
    int help = 0;
    for (i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help"))
        {
            help = 1;
            printf("Usage: gcc [options] file\n");
            printf("Compile Decaf source file to asm format. Notice: gdcf only support a subset of Decaf\n\n");
            printf("Options:\n");
            printf("%-20sDisplay the grammar tree of the target.\n", "  -g, --gmtree");
            printf("%-20sDisplay this information.\n", "  -h, --help");
            printf("%-20sDisplay the intermediate code of the target.\n", "  -i, --intercode");
            printf("%-20sDisplay the symbol table of the target.\n", "  -s, --symtable");
            printf("%-20sGenerate the code which can run on Mars MIPS Simulator. Otherwise the code can only run on special cpu.\n", "  -m, mars");
            printf("%-20sPlace the output into <file>.\n", "  -o, <file>");
            break;
        }
        else if (!strcmp(argv[i], "-g") || !strcmp(argv[i], "--gmtree"))
            garg = 1;
        else if (!strcmp(argv[i], "-i") || !strcmp(argv[i], "--intercode"))
            iarg = 1;
        else if (!strcmp(argv[i], "-s") || !strcmp(argv[i], "--symtable"))
            sarg = 1;
        else if (!strcmp(argv[i], "-m") || !strcmp(argv[i], "--mars"))
            marg = 1;
        else if (!strcmp(argv[i], "-o"))
        {
            oarg = 1;
            fp = fopen(argv[i + 1], "w");
            i += 1;
        }
        else
        {
            if (source != 0)
            {
                printf("gdcf: sorry, gdcf only support compling one source file.\n");
                printf("compilation terminated.\n");
                return 1;
            }
            else
                source = i;
        }
    }
    if (source == 0 && help == 0)
    {
        printf("gcc: fatal error: no input file\n");
        printf("compilation terminated.\n");
        return 1;
    }
    else if (help == 1)
        return 0;
    else if (!(yyin = fopen(argv[source], "r")))
    {
        perror(argv[source]);
        return 1;
    }
    else 
    {
        yyparse();
        return 0;
    }
}
