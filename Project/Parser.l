%{


#include <stdio.h>
#include <string.h>
#include "MexprEnums.h"


//Define Global Variables
extern char lex_buffer[512];


char lex_buffer[512];
%}

%%

\n                      { return PARSER_EOL; }

0|-?[1-9][0-9]*         { return MATH_CPP_INT; }

-?[0-9]*\.[0-9]+        { return MATH_CPP_DOUBLE; }

[a-zA-Z_][a-zA-Z0-9_]*  { return MATH_CPP_VARIABLE; }

[ \t]+                  { /* ignore whitespace */ }

.                       { printf("Unrecognized token: %s\n", yytext); }

%%


int main(int argc, char **argv) {
    while (1) {
        printf("Enter the input >> ");
        fgets(lex_buffer, sizeof(lex_buffer), stdin);

        if (lex_buffer[0] == '\n'){
            lex_buffer[0]=0;
            continue;
        }

        yy_scan_string(lex_buffer);
        int token = yylex();

        while (token != PARSER_EOL) {
            printf("token = %d, text = %s, len = %lu\n", token, yytext, strlen(yytext));
            token = yylex();
        }
    }
    return 0;
}


int yywrap() {
    return 1;
}