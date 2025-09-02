#include<bits/stdc++.h>
#include "MexpTree.h"
#include "ParserExport.h"
#include "Dtype.h"
#include "Operators.h"
using namespace std;

MexpNode :: MexpNode(){
    this -> parent = NULL;
    this -> left = NULL;
    this -> right = NULL;
    this -> First_left = NULL;
    this -> First_right = NULL;
}

MexpNode :: ~MexpNode(){
    // cout << "MexpNode Destructor called" << endl;
}

MexpTree :: MexpTree(){
    this -> root = NULL;
    this -> First_head = NULL;
}

MexpTree :: MexpTree(lex_data_t **postfix_array, int size){
    
    stack <MexpNode*> st;
    for(int i = 0 ; i < size ; ++i){
        if(!Math_cpp_is_operand(postfix_array[i] -> token_code) 
            and !Math_cpp_is_operator(postfix_array[i] -> token_code)){
                continue;
        }
        if(Math_cpp_is_operand(postfix_array[i] -> token_code)){
            MexpNode *node = Dtype :: factory((mexprcpp_dtypes_t)postfix_array[i] -> token_code);
        }else if(Math_cpp_is_unary_operator(postfix_array[i] -> token_code)){
            MexpNode *node = Operator :: factory((mexprcpp_operators_t)postfix_array[i] -> token_code);
            MexpNode *leftChild = st.top();
            st.pop();
            node -> left = leftChild;
            node -> right = NULL;
            leftChild -> parent = node;
            st.push(node);
        }else{
            assert(Math_cpp_is_operator(postfix_array[i] -> token_code));
            MexpNode *node = Operator :: factory((mexprcpp_operators_t)postfix_array[i] -> token_code);
            MexpNode *rightChild = st.top();
            st.pop();
            MexpNode *leftChild = st.top();
            st.pop();
            node -> left = leftChild;
            node -> right = rightChild;
            leftChild -> parent = node;
            rightChild -> parent = node;
            st.push(node);
        }
        this -> root = st.top();
        st.pop();
        assert(st.empty());
    }
}