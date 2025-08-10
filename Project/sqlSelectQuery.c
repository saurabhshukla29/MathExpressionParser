#include<string.h>
#include "ParserExport.h"
#include "MexprEnums.h"

// This file implements a simple parser for the select sql queries.

// Q -> select cols from tables
// cols -> col, cols | col
// col -> col_name 
// tables -> table, tables| table
// table -> table_name

static parse_rc_t TABLE();
static parse_rc_t COL();
static parse_rc_t COLS();
parse_rc_t Q();


// table -> table_name
parse_rc_t TABLE() {      
    parse_init();

    token_code = cyylex();
    if(token_code != MATH_CPP_VARIABLE){
        RETURN_PARSE_ERROR;
    }
    
    RETURN_PARSE_SUCCESS;
}


// tables -> table, tables| table
parse_rc_t TABLES() {
    parse_init();
    int initial_lchkp;
    CHECKPOINT(initial_lchkp);
    // tables -> table, tables
    do{
        err = TABLE();
        if(err == PARSE_ERR) break;
        token_code = cyylex(); 
        if(token_code != MATH_CPP_COMMA) break;
        err = TABLES(); 
        if(err == PARSE_ERR) break;
        RETURN_PARSE_SUCCESS;
    }while(0);

    RESTORE_CHKP(initial_lchkp);

    // tables -> table
    do{
        err = TABLE();
        if(err == PARSE_ERR) break;
        RETURN_PARSE_SUCCESS;   
    }while(0);
    
    RETURN_PARSE_ERROR;
}


// col -> col_name
parse_rc_t COL(){
    parse_init();

    token_code = cyylex();
    if(token_code != MATH_CPP_VARIABLE){
        RETURN_PARSE_ERROR;
    }
    
    RETURN_PARSE_SUCCESS;
}


// cols -> col, cols | col
parse_rc_t COLS() {

    parse_init();
    int initial_lchkp;
    CHECKPOINT(initial_lchkp);
    //cols -> col, cols
    do{

        err = COL();
        if(err == PARSE_ERR) break;
        token_code = cyylex();
        if(token_code != MATH_CPP_COMMA) break;
        err = COLS();
        if(err == PARSE_ERR) break;
        RETURN_PARSE_SUCCESS;

    }while(0);
    
    RESTORE_CHKP(initial_lchkp);

    //cols -> col
    do{

        err = COL();
        if(err == PARSE_ERR) break;
        RETURN_PARSE_SUCCESS;

    }while(0);

    RESTORE_CHKP(initial_lchkp);
    RETURN_PARSE_ERROR;
}


// Q -> select cols from table
parse_rc_t Q() {

    parse_init();

    token_code = cyylex();
    if(token_code != MATH_CPP_VARIABLE){
        RETURN_PARSE_ERROR;
    }
    if(strcasecmp(lex_curr_token, "SELECT")) RETURN_PARSE_ERROR;

    err = COLS();
    if(err == PARSE_ERR){
        RETURN_PARSE_ERROR;
    }

    token_code = cyylex();
    if(token_code != MATH_CPP_VARIABLE){
        RETURN_PARSE_ERROR;
    }
    if(strcasecmp(lex_curr_token, "FROM")) RETURN_PARSE_ERROR;

    err = TABLES();
    if(err == PARSE_ERR){
        RETURN_PARSE_ERROR;
    }

    token_code = cyylex();
    if(token_code != PARSER_EOL){
        RETURN_PARSE_ERROR;
    }
    yyrewind(1); // rewind the last token -> "\n"
    RETURN_PARSE_SUCCESS;

}