/*  

A Grammar to parse mathematical expression !

1. E -> E + T | E - T | T
2. T -> T * F | T / F | F
3. F -> ( E ) | INTEGER | DECIMAL | VAR 


Now remove left recursion from it :

1. E -> E + T | E - T | T

E ->  T E'
E' -> + T E' | - T E' |  $   ( $ represents epsilon)

4. T -> T * F | T / F | F

T -> F T'
T' -> * F T' |   / F T'  |  $

Combining Everything , final grammar is :
1. E -> T E'
2. E' -> + T E' | - T E' | $
3. T -> F T'
4. T' -> * F T' | / F T' | $
5. F -> ( E ) | INTEGER | DECIMAL | VAR 

*/


/*

Adding Inequlity to the grammar :

Inequality nothing but -> mathematical expression Inequality mathematical expression

6. Q -> E Ineq E
7. Ineq -> < | > | <= | >= | = | !=
*/

/*
Adding binary and unary operators to the grammar :
5. F -> (E) | INTEGER | DECIMAL | VAR | G(E,E) | P(E)
8. G -> max | min | pow
9. P -> sqrt | sqr | sin
*/

#include <stdio.h>
#include<string.h>
#include "MexprEnums.h"
#include "ParserExport.h"

static parse_rc_t E();
static parse_rc_t E_dash();
static parse_rc_t T();
static parse_rc_t T_dash();
static parse_rc_t F();
static parse_rc_t Ineq();
static parse_rc_t G();
static parse_rc_t P();
parse_rc_t Q();


// P -> sqrt | sqr | sin
parse_rc_t P(){
    parse_init();
    token_code = cyylex();
    if(token_code == MATH_CPP_SQRT ||
        token_code == MATH_CPP_SQR ||
        token_code == MATH_CPP_SIN ){
        RETURN_PARSE_SUCCESS;
    }
    RETURN_PARSE_ERROR;
}


// G -> max | min | pow
parse_rc_t G(){
    parse_init();
    token_code = cyylex();
    if(token_code == MATH_CPP_MAX ||
        token_code == MATH_CPP_MIN ||
        token_code == MATH_CPP_POW){
        RETURN_PARSE_SUCCESS;
    }
    RETURN_PARSE_ERROR;
}


// F -> ( E ) | INTEGER | DECIMAL | VAR | STRING | G(E,E) | P(E)
parse_rc_t F(){
    parse_init();
    int initial_lchkp;
    CHECKPOINT(initial_lchkp);
    // F -> ( E )
    do{
        token_code = cyylex();
        if(token_code != MATH_CPP_BRACKET_START){
            break;
        }
        err = E();
        if(err == PARSE_ERR) {
            break;
        }
        token_code = cyylex();
        if(token_code != MATH_CPP_BRACKET_END){ 
            break;
        }
        RETURN_PARSE_SUCCESS;
    }while(0);
    RESTORE_CHKP(initial_lchkp);


    // F -> G(E, E)
    do{
        err = G();
        if(err == PARSE_ERR){
            break;
        }
        token_code = cyylex();
        if(token_code != MATH_CPP_BRACKET_START){
            break;
        }
        err = E();
        if(err == PARSE_ERR){
            break;
        }
        token_code = cyylex();
        if(token_code != MATH_CPP_COMMA){
            break;
        }
        err = E();
        if(err == PARSE_ERR){
            break;
        }
        token_code = cyylex();
        if(token_code != MATH_CPP_BRACKET_END){
            break;
        }
        RETURN_PARSE_SUCCESS;
        
    }while(0);
    RESTORE_CHKP(initial_lchkp);

    // F -> P(E)
    do{
        err = P();
        if(err == PARSE_ERR){
            break;
        }
        token_code = cyylex();
        if(token_code != MATH_CPP_BRACKET_START){
            break;
        }
        err = E();
        if(err == PARSE_ERR){
            break;
        }
        token_code = cyylex();
        if(token_code != MATH_CPP_BRACKET_END){
            break;
        }
        RETURN_PARSE_SUCCESS;
    }while(0);
    RESTORE_CHKP(initial_lchkp);

    // F -> INTEGER | DECIMAL | VAR | STRING
    do{
        token_code = cyylex();
        if(token_code == MATH_CPP_INT || token_code == MATH_CPP_DOUBLE || 
            token_code == MATH_CPP_VARIABLE || token_code == MATH_CPP_STRING){
            RETURN_PARSE_SUCCESS;
        } 
        RETURN_PARSE_ERROR;
    }while(0);
}





// T' -> * F T' | / F T' | $
parse_rc_t T_dash() {
    parse_init();

    int initial_lchkp;
    CHECKPOINT(initial_lchkp);
    // T' -> * F T'
    do{
        token_code = cyylex();
        if(token_code != MATH_CPP_MUL){
            break;
        }
        err = F();
        if(err == PARSE_ERR) {
            break;
        }
        err = T_dash();
        if(err == PARSE_ERR) {  
            break;
        }
        RETURN_PARSE_SUCCESS;
    }while(0);
    RESTORE_CHKP(initial_lchkp);

    // T' -> / F T'
    do{
        token_code = cyylex();
        if(token_code != MATH_CPP_DIV){
            break;
        }
        err = F();
        if(err == PARSE_ERR) {
            break;
        }
        err = T_dash();
        if(err == PARSE_ERR) {  
            break;
        }
        RETURN_PARSE_SUCCESS;   
    }while(0);
    RESTORE_CHKP(initial_lchkp);
    // T' -> $
    RETURN_PARSE_SUCCESS;
}



// E' -> + T E' | - T E' | $
parse_rc_t E_dash(){
    parse_init();

    int initial_lchkp;
    CHECKPOINT(initial_lchkp);
    // E' -> + T E'
    do{
        token_code = cyylex();
        if(token_code != MATH_CPP_PLUS){
            break;
        }
        err = T();
        if(err == PARSE_ERR) {
            break;
        }
        err = E_dash();
        if(err == PARSE_ERR) {  
            break;
        }
        RETURN_PARSE_SUCCESS;
    }while(0);
    RESTORE_CHKP(initial_lchkp);

    // E' -> - T E'
    do{
        token_code = cyylex();
        if(token_code != MATH_CPP_MINUS){
            break;
        }
        err = T();
        if(err == PARSE_ERR) {
            break;
        }
        err = E_dash();
        if(err == PARSE_ERR) {  
            break;
        }
        RETURN_PARSE_SUCCESS;   
    }while(0);
    RESTORE_CHKP(initial_lchkp);
    // E' -> $
    RETURN_PARSE_SUCCESS;
}



//T -> F T'
parse_rc_t T(){
    parse_init();

    err = F();
    if(err == PARSE_ERR) {  
        RETURN_PARSE_ERROR;
    }
    err = T_dash();
    if(err == PARSE_ERR) {
        RETURN_PARSE_ERROR;
    }
    RETURN_PARSE_SUCCESS;
}


// E -> T E'
parse_rc_t E() {
    parse_init();

    err = T();
    if(err == PARSE_ERR) {
        RETURN_PARSE_ERROR;
    }
    err = E_dash();
    if(err == PARSE_ERR) {
        RETURN_PARSE_ERROR;
    }
    RETURN_PARSE_SUCCESS;
}


// Ineq -> < | > | <= | >= | = | !=
parse_rc_t Ineq() {
    parse_init();
    token_code = cyylex();
    if(token_code == MATH_CPP_LESS_THAN ||
       token_code == MATH_CPP_GREATER_THAN ||
       token_code == MATH_CPP_LESS_THAN_EQ ||
       token_code == MATH_CPP_GREATER_THAN_EQ ||
       token_code == MATH_CPP_EQ ||
       token_code == MATH_CPP_NEQ) {
        RETURN_PARSE_SUCCESS;
    }
    RETURN_PARSE_ERROR;
}


// Q -> E Ineq E
parse_rc_t Q(){
    parse_init();

    err = E();
    if(err == PARSE_ERR) {
        RETURN_PARSE_ERROR;
    }
    err = Ineq();
    if(err == PARSE_ERR) {
        RETURN_PARSE_ERROR;
    }
    err = E();
    if(err == PARSE_ERR) {
        RETURN_PARSE_ERROR;
    }

    RETURN_PARSE_SUCCESS;
}