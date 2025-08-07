%{

#include "ParserExport.h"


stack_t undo_stack = {-1,{0,0,0}};

char lex_buffer[MAX_STRING_SIZE];
char *curr_ptr = lex_buffer;
char *lex_curr_token = NULL;
int lex_curr_length = 0;



static void
lex_push(stack_t st, lex_data_t a){
    if(st.top<MAX_LEN){
        st.data[++st.top]=a;
        lex_curr_token = (char * )a.token_val;
        lex_curr_length = a.token_len;
    }
}

static lex_data_t
lex_pop(stack_t st){
    if(st.top > -1){
        lex_data_t ans=st.data[st.top];
        st.top--;
        if(st.top > -1){
            lex_data_t lex_data = st.data[st.top];
            lex_curr_token = lex_data.token_val;
            lex_curr_length = lex_data.token_len;
        }else{
            lex_curr_token = NULL;
            lex_curr_length = 0;
        }
        return ans;
    }
    return (lex_data_t){-1,0,NULL};
}



int cyylex(){
    int token_code = yylex();
    lex_data_t lex_data;
    lex_data.token_code = token_code;
    lex_data.token_len = yyleng;
    curr_ptr += yyleng;
    lex_data.token_val = (char *)calloc(1, yyleng + 1);
    strcpy(lex_data.token_val, yytext);
    lex_push(undo_stack,lex_data);
    return token_code;
}

static void process_white_space(int n){
    lex_data_t lex_data;
    lex_data.token_code = PARSER_WHITE_SPACE;
    lex_data.token_len = n;
    curr_ptr += n;
    lex_data.token_val = NULL;
    lex_push(undo_stack, lex_data);
}


/*
Why free() is Only Used for token_val
Because free() is only needed for memory that was dynamically allocated using malloc(), calloc(), etc.

token_code and token_len are just int values. They're stored inside the struct and are not pointers.

Their memory is part of the struct itself and is freed automatically when the struct goes out of scope 
(if it's on the stack) or when you free(&undo_stack) (if it's on the heap).
No malloc() → No free() needed.
*/

void Parser_stack_reset(){
    int i;
    lex_data_t *lex_data;

    for (i = 0; i < undo_stack.top; i++) {
        lex_data = &undo_stack.data[i];
        lex_data->token_code = 0;
        lex_data->token_len = 0;
        if (lex_data->token_val) {
            free(lex_data->token_val);
            lex_data->token_val = NULL;
        }
    }
    undo_stack.top = -1;
    curr_ptr = lex_buffer;
    lex_curr_token = NULL;
    lex_curr_length = 0;
}

void lex_set_scan_buffer (const char *buffer) {
    yy_scan_string(buffer);
}

// n->No. of words wants to remove from stack
void yyrewind(int n){
    if(n<=0) return;
    if(curr_ptr==lex_buffer) return;
    int data_len=0;
    lex_data_t lex_data;
    while(n){
        lex_data = lex_pop(undo_stack);
        data_len += lex_data.token_len;
        if(lex_data.token_code == PARSER_WHITE_SPACE){
            continue;
        }else{
            n--;
        }
    }
    curr_ptr -= data_len;
    yy_scan_string(curr_ptr);
}

void RESTORE_CHKP(int a){
    while(undo_stack.top > a){
        lex_data_t data = lex_pop(undo_stack);
        curr_ptr -= data.token_len;
        data.token_code = 0;
        data.token_len = 0;
        free(data.token_val);
        data.token_val = NULL;
    }
    yy_scan_string(curr_ptr);
    if(undo_stack.top >= 0){
        lex_curr_length -= undo_stack.data[undo_stack.top].token_len;
        lex_curr_token = undo_stack.data[undo_stack.top].token_val;
    }
}

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
        int token_code = yylex();

        while (token_code!= PARSER_EOL) {
            printf("token_code = %d, text = %s, len = %lu\n", token_code, yytext, strlen(yytext));
            token_code = yylex();
        }
    }
    return 0;
}


int yywrap() {
    return 1;
}