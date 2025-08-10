#include<string.h>
#include "ParserExport.h"
#include "MexprEnums.h"


// This file implements a simple parser for the grammar: Context free grammar

// Context free grammar is nothing but a set of rules that describe how to form a
//strings from a language's alphabet that are valid according to the language's syntax.

// The inorder traversal of the all the leaves of parse tree for this grammar will 
// yield the desired string.


// Here A, B is non-terminal and a, b are terminals.

// A -> aB
// B -> bA | b | ba
parse_rc_t A();
static parse_rc_t B();


parse_rc_t B(){

    parse_init();
    // B-> bA
    do{

        token_code = cyylex();
        if(token_code != MATH_CPP_VARIABLE){
            yyrewind(1);
            break;
        }
        if(strcmp(lex_curr_token, "b")){
            yyrewind(1);
            break;
        }
        err = A();
        if(err == PARSE_ERR){
            yyrewind(1);
            break;
        }
        RETURN_PARSE_SUCCESS;

    }while(0);

    // B -> b
    do{
 
        token_code = cyylex();
        if(token_code != MATH_CPP_VARIABLE){
            yyrewind(1);
            break;
        }
        if(strcmp(lex_curr_token, "b")){
            yyrewind(1);
            break;
        }
        RETURN_PARSE_SUCCESS;

    }while(0);

    // B -> ba
    do{
        
        token_code = cyylex();
        if(token_code != MATH_CPP_VARIABLE){
            yyrewind(1);
            break;
        }
        if(strcmp(lex_curr_token, "b")){
            yyrewind(1);
            break;
        }

        token_code = cyylex();
        if(token_code != MATH_CPP_VARIABLE){
            yyrewind(2);
            break;
        }
        if(strcmp(lex_curr_token, "a")){
            yyrewind(2);
            break;
        }
        RETURN_PARSE_SUCCESS;

    }while(0);

    RETURN_PARSE_ERROR;

}


parse_rc_t A(){
    
    parse_init();
    // A -> aB
    do{
        
        token_code = cyylex();
        if(token_code != MATH_CPP_VARIABLE){
            RETURN_PARSE_ERROR
        }
        if(strcmp(lex_curr_token, "a")){
            RETURN_PARSE_ERROR;
        }
        err = B();
        if(err == PARSE_ERR){
            RETURN_PARSE_ERROR;
        }
        RETURN_PARSE_SUCCESS;

    }while(0);
}