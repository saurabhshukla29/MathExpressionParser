%{


#include <stdio.h>
#include <string.h>
#include "MexprEnums.h"


//Define Data Structures Here...

typedef struct lex_data{
    int token;
    int token_len;
    char *token_val;
}lex_data_t;                // It is basically aliasing the struct- we don't have to use struct when we are declaring.


int MAX_LEN=512;
int MAX_STRING_SIZE=512;

typedef struct stack{
    int top;
    lex_data_t data[MAX_LEN];
}stack_t;


//Define Global Variables
extern char lex_buffer[MAX_STRING_SIZE];
extern stack_t undo_stack;

char lex_buffer[MAX_STRING_SIZE];


static void
push(stack_t st, lex_data_t a){
    if(st.top<MAX_LEN){
        st.data[++st.top]=a;
    }
}

static lex_data_t
pop(stack_t st){
    if(st.top()>-1){
        int ans=st.data[st.top];
        st.top()--;
        return ans;
    }else return {-1,{0,0,0}};
}

stack_t undo_stack={-1,{0,0,0}};

%}

%%

"(" {
    return MATH_CPP_BRACKET_START;
}

")" {
    return MATH_CPP_BRACKET_END;
}

"<=" {
    return MATH_CPP_LESS_THAN_EQ;
}

"<" {
    return MATH_CPP_LESS_THAN;
}

">" {
    return MATH_CPP_GREATER_THAN;
}

"=" {
    return MATH_CPP_EQ;
}

"!=" {
    return MATH_CPP_NEQ;
}

"and" {
    return MATH_CPP_AND;
}

"or" {
    return MATH_CPP_OR;
}

"*" {
    return MATH_CPP_MUL;
}

"+" {
    return MATH_CPP_PLUS;
}

"-" {
    return  MATH_CPP_MINUS;
}

"/" {
    return MATH_CPP_DIV;
}

"," {
    return MATH_CPP_COMMA;
}

"sqrt" {
    return MATH_CPP_SQRT;
}

"sqr" {
    return MATH_CPP_SQR;
}

"mmax" {
    return MATH_CPP_MAX;
}

"mmin" {
    return MATH_CPP_MIN;
}

"sin" {
    return MATH_CPP_SIN;
}

"cos" {
    return MATH_CPP_COS;
}

"pow" {
    return MATH_CPP_POW;
}

\n {
    return PARSER_EOL;
}

"\\\n" {

}

[ ] {
    /* Ignore */
    //process_white_space(1);
}

[\t] {
    /*ignore*/
    //process_white_space(4);
}

"\\q" {
    return PARSER_QUIT;
}

0|-?[1-9][0-9]* {
    return MATH_CPP_INT;
}

-?[0-9]*\.[0-9]+ {
    return MATH_CPP_DOUBLE;
}

[a-zA-Z0-9_]+ {
    return MATH_CPP_VARIABLE;
}

[a-zA-Z0-9_]+\.[a-zA-Z0-9_]+ {
    return MATH_IDENTIFIER_IDENTIFIER;
}

'[^']*' {
    // string enclosed within single quotes
    return MATH_CPP_STRING;
}

\"[^"]*\" {
    // string enclosed within double quotes
    return MATH_CPP_STRING;
}


. {
    // ignore any other character
}



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