#include <bits/stdc++.h>
#include "MexprEnums.h"
#include "ParserExport.h"
using namespace std;

extern "C" lex_data_t** convertInfixToPostfix(lex_data_t *infix, int size_in, int *size_out) {
    vector<lex_data_t*> postfixArray;   // output
    vector<lex_data_t*> opStack;        // operator stack
    *size_out = 0;

    for (int i = 0; i < size_in; i++) {
        if (infix[i].token_code == PARSER_WHITE_SPACE || infix[i].token_code == PARSER_EOL) {
            continue;
        }

        if (!Math_cpp_is_operand(infix[i].token_code) && 
            !Math_cpp_is_operator(infix[i].token_code)) {
            assert(false);
        }

        if (infix[i].token_code == (int)MATH_CPP_BRACKET_START) {
            opStack.push_back(&infix[i]);
        } else if (infix[i].token_code == (int)MATH_CPP_BRACKET_END) {
            while (!opStack.empty() && opStack.back()->token_code != (int)MATH_CPP_BRACKET_START) {
                postfixArray.push_back(opStack.back());
                opStack.pop_back();
                (*size_out)++;
            }
            if (!opStack.empty()) opStack.pop_back(); // remove '('
        } else if (Math_cpp_is_operand(infix[i].token_code)) {
            postfixArray.push_back(&infix[i]);
            (*size_out)++;
        }else {
            while (!opStack.empty() && 
                   Math_cpp_operator_precedence(infix[i].token_code) <=
                   Math_cpp_operator_precedence(opStack.back()->token_code)) {
                postfixArray.push_back(opStack.back());
                opStack.pop_back();
                (*size_out)++;
            }
            opStack.push_back(&infix[i]);
        }
    }

    while (!opStack.empty()) {
        postfixArray.push_back(opStack.back());
        opStack.pop_back();
        (*size_out)++;
    }

    // Allocate array to return
    lex_data_t **result = (lex_data_t**)malloc(postfixArray.size() * sizeof(lex_data_t*));
    for (int i = 0; i < postfixArray.size(); i++) {
        result[i] = postfixArray[i];
    }
    return result;
}


/*
int main(){
    lex_data_t infix[] = {
        {MATH_CPP_VARIABLE, 1, "a"},
        {PARSER_WHITE_SPACE, 1, " "},
        {MATH_CPP_PLUS, 1, "+"},
        {PARSER_WHITE_SPACE, 1, " "},
        {MATH_CPP_VARIABLE, 1, "b"},
        {MATH_CPP_MUL, 1, "*"},
        {MATH_CPP_VARIABLE, 1, "c"}
    };
    int size_out = 0;
    lex_data_t **postfixArray = convertInfixToPostfix(infix, sizeof(infix)/sizeof(infix[0]),&size_out);
    cout<< "PostfixArray :";
    for(int i =0 ; i < size_out ; i++){
        lex_data_t *lex_data = postfixArray[i];
        cout<< lex_data -> token_val;
    }
    cout<<endl;
    return 0;
}
*/
