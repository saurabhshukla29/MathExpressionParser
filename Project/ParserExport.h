#ifndef _PARSER_EXPORT_
#define _PARSER_EXPORT_



#include <stdio.h>
#include <string.h>
#include "MexprEnums.h"

extern int yylex();

//Define Data Structures Here...

typedef struct lex_data{
    int token_code;
    int token_len;
    char *token_val;
}lex_data_t;                // It is basically aliasing the struct- we don't have to use struct when we are declaring.


#define MAX_LEN 512
#define MAX_STRING_SIZE 512
#define PARSER_EOL 10000
#define PARSER_WHITE_SPACE 10002

typedef struct stack{
    int top;
    lex_data_t data[MAX_LEN];
}stack_t;


//Define Global Variables
extern char lex_buffer[MAX_STRING_SIZE];
extern stack_t undo_stack;
extern char *curr_ptr;
extern int cyylex();
extern void yyrewind(int n);
extern void Parser_stack_reset();
extern char *lex_curr_token;
extern int lex_curr_length;


#define CHECKPOINT(a) \
    a = undo_stack.top;

#define RESTORE_CHKP(a) \
    yyrewind(undo_stack.top-a);


#endif