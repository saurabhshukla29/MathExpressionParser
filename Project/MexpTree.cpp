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


/*
MexpNode* MexpNode :: clone(){
    MexpNode *new_node = new MexpNode();
    *new_node = *this;
    new_node -> parent = NULL;
    new_node -> left = NULL;
    new_node -> right = NULL;
    new_node -> First_left = NULL;
    new_node -> First_right = NULL;
    return new_node;
}
*/

MexpTree :: MexpTree(){
    this -> root = NULL;
    this -> First_head = NULL;
}

MexpTree :: ~MexpTree(){
    // cout << "MexpTree Destructor called" << endl;
}


MexpTree :: MexpTree(lex_data_t **postfix_array, int size){
    
    stack <MexpNode*> st;
    for(int i = 0 ; i < size ; ++i){
        if(!Math_cpp_is_operand(postfix_array[i] -> token_code) 
            and !Math_cpp_is_operator(postfix_array[i] -> token_code)){
                continue;
        }
        if(Math_cpp_is_operand(postfix_array[i] -> token_code)){
            string str = postfix_array[i] -> token_val;
            MexpNode *node = Dtype :: factory((mexprcpp_dtypes_t)postfix_array[i] -> token_code, str);
            st.push(node);
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
    }
    this -> root = st.top();
    st.pop();
    assert(st.empty());
}

void InorderTraversal(MexpNode *node){
    if(node == NULL) return;
    if(node -> left){
        InorderTraversal(node -> left);
    }
    // dynamic cast will check at runtime if node is of type Operator or not
    Operator *op_node = dynamic_cast<Operator*>(node);
    if(op_node){
        cout << op_node -> name << " ";
    }else{
        Dtype *dt_node = dynamic_cast<Dtype*>(node);
        if(dt_node){
            switch (dt_node -> d_id)
            {
                case (int)MATH_CPP_INT:{
                    Dtype_INT *int_node = dynamic_cast<Dtype_INT*>(dt_node);
                    cout << int_node -> int_val << " ";
                    break;
                }
                case (int)MATH_CPP_DOUBLE:{
                    Dtype_DOUBLE *double_node = dynamic_cast<Dtype_DOUBLE*>(dt_node);
                    cout << double_node -> double_val << " ";
                    break;
                }
                case (int)MATH_CPP_STRING:{
                    Dtype_STRING *string_node = dynamic_cast<Dtype_STRING*>(dt_node);
                    cout << string_node -> string_val << " ";
                    break;
                }
                default:{
                    assert(false);
                }
            }
        }else assert(false);
    }
    if(node -> right){
        InorderTraversal(node -> right);
    }
}

void MexpTree :: Inorder(MexpTree *tree){
    MexpNode *node = tree -> root;
    InorderTraversal(node);
}

mexprcpp_dtypes_t MexpTree :: internalValidate(MexpNode * root){
    if(!root){
        return MATH_CPP_DTYPE_INVALID;
    }

    mexprcpp_dtypes_t leftChild = internalValidate(root -> left);
    mexprcpp_dtypes_t rightChild = internalValidate(root -> right);
    // Leaf Nodes
    if(!root -> left and !root -> right){
        return root -> result(MATH_CPP_DTYPE_INVALID, MATH_CPP_DTYPE_INVALID);
    }

    // unary operators
    if(root -> left and !root -> right){
        return root -> result(leftChild, MATH_CPP_DTYPE_INVALID);
    }

    // binary operators
    return root -> result(leftChild, rightChild);
}

bool MexpTree :: validate(MexpNode * root){
    mexprcpp_dtypes_t res = internalValidate(root);
    if(res != MATH_CPP_DTYPE_INVALID){
        return true;
    }
    return false;
}

Dtype * MexpTree :: internalEvaluate(MexpNode * root){
    if(!root) return NULL;
    Dtype * leftChild = internalEvaluate(root -> left);
    Dtype * rightChild = internalEvaluate(root -> right);

    // Leaf Nodes
    if(!root -> left and !root -> right){
        Dtype * res = root -> compute(NULL, NULL);
        return res;
    }

    // unary operators
    if(root -> left and !root -> right){
        Dtype * res = root -> compute(leftChild, NULL);
        delete leftChild;
        return res;
    }

    // binary operators
    Dtype * res = root -> compute(leftChild, rightChild);
    delete leftChild;
    delete rightChild;
    return res;
}


Dtype * MexpTree :: evaluate(MexpNode * root){
    return internalEvaluate(root);
}

