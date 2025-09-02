#ifndef _PARSER_EXPORT_
#define _PARSER_EXPORT_



#include <stdio.h>
#include <string.h>
#include "MexprEnums.h"

extern int yylex();

//Define Data Structures Here...

typedef enum parse_rc_{

    PARSE_SUCCESS,
    PARSE_ERR
}parse_rc_t;

typedef struct lex_data{
    int token_code;
    int token_len;
    char *token_val;
}lex_data_t;                // It is basically aliasing the struct- we don't have to use struct when we are declaring.


#define MAX_LEN 512
#define MAX_STRING_SIZE 512
#define PARSER_EOL 10000
#define PARSER_WHITE_SPACE 10002

typedef struct _stack{
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
extern void RESTORE_CHKP(int a);


#define CHECKPOINT(a) \
    a = undo_stack.top;



#define RETURN_PARSE_SUCCESS    \
    return PARSE_SUCCESS

#define PARSER_LOG_ERR(token_obtained, expected_token)  \
    printf ("%s(%d) : Token Obtained = %d (%s) , expected token = %d\n",    \
    __FUNCTION__, __LINE__, token_obtained, lex_curr_token, expected_token);


#define parse_init()   \
        int token_code=0;    \
        int _lchkp=undo_stack.top;    \
        parse_rc_t err = PARSE_SUCCESS


#define RETURN_PARSE_ERROR  \
    {RESTORE_CHKP(_lchkp);       \
    return PARSE_ERR;}           \

    

#endif