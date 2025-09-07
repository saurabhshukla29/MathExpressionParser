#include<bits/stdc++.h>
#include "Operators.h"
using namespace std;

Operator :: Operator(){
    this -> op_id = MATH_CPP_OPR_INVALID;
    this -> name = "";
    this -> isUnary = false;
}

Operator :: ~Operator(){
    // cout << "Operator Destructor called" << endl;
}

/*
MexpNode* Operator :: clone(){
    Operator *new_node = new Operator();
    *new_node = *this;
    this -> parent = NULL;
    this -> left = NULL;
    this -> right = NULL;
    this -> First_left = NULL;
    this -> First_right = NULL;
    return new_node;
}
*/


// Concrete class now :

// + operator
OperatorPlus :: OperatorPlus(){
    this -> op_id = MATH_CPP_PLUS;
    this -> name = "+";
    this -> isUnary = false;
}

OperatorPlus :: ~OperatorPlus(){
    // cout << "OperatorPlus Destructor called" << endl;
}

MexpNode* OperatorPlus :: clone(){
    OperatorPlus *new_node = new OperatorPlus();
    *new_node = *this;
    this -> parent = NULL;
    this -> left = NULL;
    this -> right = NULL;
    this -> First_left = NULL;
    this -> First_right = NULL;
    return new_node;
}

mexprcpp_dtypes_t OperatorPlus :: result(mexprcpp_dtypes_t d_id1 , mexprcpp_dtypes_t d_id2){
    switch(d_id1){
        case MATH_CPP_INT : 
            switch(d_id2){
                case MATH_CPP_INT :
                return MATH_CPP_INT;
                case MATH_CPP_DOUBLE :
                return MATH_CPP_DOUBLE;
                case MATH_CPP_DTYPE_WILDCRAD :
                return MATH_CPP_INT;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        case MATH_CPP_DOUBLE :
            switch(d_id2){
                case MATH_CPP_INT :
                return MATH_CPP_DOUBLE;
                case MATH_CPP_DOUBLE :
                return MATH_CPP_DOUBLE;
                case MATH_CPP_DTYPE_WILDCRAD :
                return MATH_CPP_DOUBLE;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        case MATH_CPP_STRING :
            switch(d_id2){
                case MATH_CPP_STRING :
                return MATH_CPP_STRING;
                case MATH_CPP_DTYPE_WILDCRAD :
                return MATH_CPP_STRING;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        case MATH_CPP_DTYPE_WILDCRAD :
            switch(d_id2){
                case MATH_CPP_INT :
                return MATH_CPP_INT;
                case MATH_CPP_DOUBLE :
                return MATH_CPP_DOUBLE;
                case MATH_CPP_STRING :
                return MATH_CPP_STRING;
                case MATH_CPP_DTYPE_WILDCRAD :
                return MATH_CPP_DTYPE_WILDCRAD;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        default : 
        return MATH_CPP_DTYPE_INVALID;
    }
}

// - operator
OperatorMinus :: OperatorMinus(){
    this -> op_id = MATH_CPP_MINUS;
    this -> name = "-";
    this -> isUnary = false;
}   

OperatorMinus :: ~OperatorMinus(){
    // cout << "OperatorMinus Destructor called" << endl;
}

MexpNode* OperatorMinus :: clone(){
    OperatorMinus *new_node = new OperatorMinus();
    *new_node = *this;
    this -> parent = NULL;
    this -> left = NULL;
    this -> right = NULL;
    this -> First_left = NULL;
    this -> First_right = NULL;
    return new_node;
}

mexprcpp_dtypes_t OperatorMinus :: result(mexprcpp_dtypes_t d_id1 , mexprcpp_dtypes_t d_id2){
    switch(d_id1){
        case MATH_CPP_INT : 
            switch(d_id2){
                case MATH_CPP_INT :
                return MATH_CPP_INT;
                case MATH_CPP_DOUBLE :
                return MATH_CPP_DOUBLE;
                case MATH_CPP_DTYPE_WILDCRAD :
                return MATH_CPP_INT;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        case MATH_CPP_DOUBLE :
            switch(d_id2){
                case MATH_CPP_INT :
                return MATH_CPP_DOUBLE;
                case MATH_CPP_DOUBLE :
                return MATH_CPP_DOUBLE;
                case MATH_CPP_DTYPE_WILDCRAD :
                return MATH_CPP_DOUBLE;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        case MATH_CPP_STRING :
            switch(d_id2){
                case MATH_CPP_STRING :
                return MATH_CPP_STRING;
                case MATH_CPP_DTYPE_WILDCRAD :
                return MATH_CPP_STRING;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        case MATH_CPP_DTYPE_WILDCRAD :
            switch(d_id2){
                case MATH_CPP_INT :
                return MATH_CPP_INT;
                case MATH_CPP_DOUBLE :
                return MATH_CPP_DOUBLE;
                case MATH_CPP_STRING :
                return MATH_CPP_STRING;
                case MATH_CPP_DTYPE_WILDCRAD :
                return MATH_CPP_DTYPE_WILDCRAD;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        default : 
        return MATH_CPP_DTYPE_INVALID;
    }
}

// * operator
OperatorMul :: OperatorMul(){
    this -> op_id = MATH_CPP_MUL;
    this -> name = "*";
    this -> isUnary = false;
}   

OperatorMul :: ~OperatorMul(){
    // cout << "OperatorMul Destructor called" << endl;
}

MexpNode* OperatorMul :: clone(){
    OperatorMul *new_node = new OperatorMul();
    *new_node = *this;
    this -> parent = NULL;
    this -> left = NULL;
    this -> right = NULL;
    this -> First_left = NULL;
    this -> First_right = NULL;
    return new_node;
}

mexprcpp_dtypes_t OperatorMul :: result(mexprcpp_dtypes_t d_id1 , mexprcpp_dtypes_t d_id2){
    switch(d_id1){
        case MATH_CPP_INT : 
            switch(d_id2){
                case MATH_CPP_INT :
                return MATH_CPP_INT;
                case MATH_CPP_DOUBLE :
                return MATH_CPP_DOUBLE;
                case MATH_CPP_DTYPE_WILDCRAD :
                return MATH_CPP_INT;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        case MATH_CPP_DOUBLE :
            switch(d_id2){
                case MATH_CPP_INT :
                return MATH_CPP_DOUBLE;
                case MATH_CPP_DOUBLE :
                return MATH_CPP_DOUBLE;
                case MATH_CPP_DTYPE_WILDCRAD :
                return MATH_CPP_DOUBLE;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        case MATH_CPP_DTYPE_WILDCRAD :
            switch(d_id2){
                case MATH_CPP_INT :
                return MATH_CPP_INT;
                case MATH_CPP_DOUBLE :
                return MATH_CPP_DOUBLE;
                case MATH_CPP_DTYPE_WILDCRAD :
                return MATH_CPP_DTYPE_WILDCRAD;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        default : 
        return MATH_CPP_DTYPE_INVALID;
    }
}

// / operator
OperatorDiv :: OperatorDiv(){
    this -> op_id = MATH_CPP_DIV;
    this -> name = "/";
    this -> isUnary = false;
}

OperatorDiv :: ~OperatorDiv(){
    // cout << "OperatorDiv Destructor called" << endl;
}

MexpNode* OperatorDiv :: clone(){
    OperatorDiv *new_node = new OperatorDiv();
    *new_node = *this;
    this -> parent = NULL;
    this -> left = NULL;
    this -> right = NULL;
    this -> First_left = NULL;
    this -> First_right = NULL;
    return new_node;
}

mexprcpp_dtypes_t OperatorDiv :: result(mexprcpp_dtypes_t d_id1 , mexprcpp_dtypes_t d_id2){
    switch(d_id1){
        case MATH_CPP_INT : 
            switch(d_id2){
                case MATH_CPP_INT :
                return MATH_CPP_DOUBLE;
                case MATH_CPP_DOUBLE :
                return MATH_CPP_DOUBLE;
                case MATH_CPP_DTYPE_WILDCRAD :
                return MATH_CPP_DOUBLE;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        case MATH_CPP_DOUBLE :
            switch(d_id2){
                case MATH_CPP_INT :
                return MATH_CPP_DOUBLE;
                case MATH_CPP_DOUBLE :
                return MATH_CPP_DOUBLE;
                case MATH_CPP_DTYPE_WILDCRAD :
                return MATH_CPP_DOUBLE;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        case MATH_CPP_DTYPE_WILDCRAD :
            switch(d_id2){
                case MATH_CPP_INT or MATH_CPP_DOUBLE :
                return MATH_CPP_DOUBLE;
                case MATH_CPP_DTYPE_WILDCRAD :
                return MATH_CPP_DTYPE_WILDCRAD;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        default : 
        return MATH_CPP_DTYPE_INVALID;
    }
}

// == operator
OperatorEq :: OperatorEq(){
    this -> op_id = MATH_CPP_EQ;
    this -> name = "==";
    this -> isUnary = false;
}

OperatorEq :: ~OperatorEq(){
    // cout << "OperatorEq Destructor called" << endl;
}

MexpNode* OperatorEq :: clone(){
    OperatorEq *new_node = new OperatorEq();
    *new_node = *this;
    this -> parent = NULL;
    this -> left = NULL;
    this -> right = NULL;
    this -> First_left = NULL;
    this -> First_right = NULL;
    return new_node;
}

mexprcpp_dtypes_t OperatorEq :: result (mexprcpp_dtypes_t d_id1, mexprcpp_dtypes_t d_id2){
    switch(d_id1){
        case MATH_CPP_INT :
            switch(d_id2){
                case MATH_CPP_INT or MATH_CPP_DOUBLE or MATH_CPP_DTYPE_WILDCRAD :
                return MATH_CPP_BOOL;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        case MATH_CPP_DOUBLE :
            switch(d_id2){
                case MATH_CPP_INT or MATH_CPP_DOUBLE or MATH_CPP_DTYPE_WILDCRAD :
                return MATH_CPP_BOOL;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        case MATH_CPP_STRING :
            switch(d_id2){
                case MATH_CPP_STRING :
                return MATH_CPP_BOOL;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        case MATH_CPP_DTYPE_WILDCRAD :
            switch(d_id2){
                case MATH_CPP_INT or MATH_CPP_DOUBLE or MATH_CPP_STRING :
                return MATH_CPP_BOOL;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        default :
        return MATH_CPP_DTYPE_INVALID;
    }
}

// != operator
OperatorNeq :: OperatorNeq(){
    this -> op_id = MATH_CPP_NEQ;
    this -> name = "!=";
    this -> isUnary = false;
}

OperatorNeq :: ~OperatorNeq(){
    // cout << "OperatorNeq Destructor called" << endl;
}

MexpNode* OperatorNeq :: clone(){
    OperatorNeq *new_node = new OperatorNeq();
    *new_node = *this;
    this -> parent = NULL;
    this -> left = NULL;
    this -> right = NULL;
    this -> First_left = NULL;
    this -> First_right = NULL;
    return new_node;
}

mexprcpp_dtypes_t OperatorNeq :: result (mexprcpp_dtypes_t d_id1, mexprcpp_dtypes_t d_id2){
    switch(d_id1){
        case MATH_CPP_INT :
            switch(d_id2){
                case MATH_CPP_INT or MATH_CPP_DOUBLE or MATH_CPP_DTYPE_WILDCRAD :
                return MATH_CPP_BOOL;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        case MATH_CPP_DOUBLE :
            switch(d_id2){
                case MATH_CPP_INT or MATH_CPP_DOUBLE or MATH_CPP_DTYPE_WILDCRAD :
                return MATH_CPP_BOOL;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        case MATH_CPP_STRING :
            switch(d_id2){
                case MATH_CPP_STRING :
                return MATH_CPP_BOOL;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        case MATH_CPP_DTYPE_WILDCRAD :
            switch(d_id2){
                case MATH_CPP_INT or MATH_CPP_DOUBLE or MATH_CPP_STRING :
                return MATH_CPP_BOOL;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        default :
        return MATH_CPP_DTYPE_INVALID;
    }
}

// < operator
OperatorLessthan :: OperatorLessthan(){
    this -> op_id = MATH_CPP_LESS_THAN;
    this -> name = "<";
    this -> isUnary = false;
}

OperatorLessthan :: ~OperatorLessthan(){
    // cout << "OperatorLessthan Destructor called" << endl;
}

MexpNode* OperatorLessthan :: clone(){
    OperatorLessthan *new_node = new OperatorLessthan();
    *new_node = *this;
    this -> parent = NULL;
    this -> left = NULL;
    this -> right = NULL;
    this -> First_left = NULL;
    this -> First_right = NULL;
    return new_node;
}

mexprcpp_dtypes_t OperatorLessthan :: result (mexprcpp_dtypes_t d_id1, mexprcpp_dtypes_t d_id2){
    switch(d_id1){
        case MATH_CPP_INT :
            switch(d_id2){
                case MATH_CPP_INT or MATH_CPP_DOUBLE or MATH_CPP_DTYPE_WILDCRAD :
                return MATH_CPP_BOOL;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        case MATH_CPP_DOUBLE :
            switch(d_id2){
                case MATH_CPP_INT or MATH_CPP_DOUBLE or MATH_CPP_DTYPE_WILDCRAD :
                return MATH_CPP_BOOL;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        case MATH_CPP_STRING :
            switch(d_id2){
                case MATH_CPP_STRING :
                return MATH_CPP_BOOL;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        case MATH_CPP_DTYPE_WILDCRAD :
            switch(d_id2){
                case MATH_CPP_INT or MATH_CPP_DOUBLE or MATH_CPP_STRING :
                return MATH_CPP_BOOL;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        default :
        return MATH_CPP_DTYPE_INVALID;
    }
}

// > operator
OperatorGreaterthan :: OperatorGreaterthan(){
    this -> op_id = MATH_CPP_GREATER_THAN;
    this -> name = ">";
    this -> isUnary = false;
}

OperatorGreaterthan :: ~OperatorGreaterthan(){
    // cout << "OperatorGreaterthan Destructor called" << endl;
}

MexpNode* OperatorGreaterthan :: clone(){
    OperatorGreaterthan *new_node = new OperatorGreaterthan();
    *new_node = *this;
    this -> parent = NULL;
    this -> left = NULL;
    this -> right = NULL;
    this -> First_left = NULL;
    this -> First_right = NULL;
    return new_node;
}

mexprcpp_dtypes_t OperatorGreaterthan :: result (mexprcpp_dtypes_t d_id1, mexprcpp_dtypes_t d_id2){
    switch(d_id1){
        case MATH_CPP_INT :
            switch(d_id2){
                case MATH_CPP_INT or MATH_CPP_DOUBLE or MATH_CPP_DTYPE_WILDCRAD :
                return MATH_CPP_BOOL;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        case MATH_CPP_DOUBLE :
            switch(d_id2){
                case MATH_CPP_INT or MATH_CPP_DOUBLE or MATH_CPP_DTYPE_WILDCRAD :
                return MATH_CPP_BOOL;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        case MATH_CPP_STRING :
            switch(d_id2){
                case MATH_CPP_STRING :
                return MATH_CPP_BOOL;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        case MATH_CPP_DTYPE_WILDCRAD :
            switch(d_id2){
                case MATH_CPP_INT or MATH_CPP_DOUBLE or MATH_CPP_STRING :
                return MATH_CPP_BOOL;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        default :
        return MATH_CPP_DTYPE_INVALID;
    }
}

// sqr operator
OperatorSqr :: OperatorSqr(){
    this -> op_id = MATH_CPP_SQR;
    this -> name = "sqr";
    this -> isUnary = true;
}

OperatorSqr :: ~OperatorSqr(){
    // cout << "OperatorSqr Destructor called" << endl;
}

MexpNode* OperatorSqr :: clone(){
    OperatorSqr *new_node = new OperatorSqr();
    *new_node = *this;
    this -> parent = NULL;
    this -> left = NULL;
    this -> right = NULL;
    this -> First_left = NULL;
    this -> First_right = NULL;
    return new_node;
}

mexprcpp_dtypes_t OperatorSqr :: result (mexprcpp_dtypes_t d_id1, mexprcpp_dtypes_t d_id2){
    switch(d_id1){
        case MATH_CPP_INT :
        return MATH_CPP_INT;
        break;
        case MATH_CPP_DOUBLE :
        return MATH_CPP_DOUBLE;
        break;
        case MATH_CPP_DTYPE_WILDCRAD :
        return MATH_CPP_DTYPE_WILDCRAD;
        break;
        default :
        return MATH_CPP_DTYPE_INVALID;
    }
}

// sqrt operator
OperatorSqrt :: OperatorSqrt(){
    this -> op_id = MATH_CPP_SQRT;
    this -> name = "sqrt";
    this -> isUnary = true;
}

OperatorSqrt :: ~OperatorSqrt(){
    // cout << "OperatorSqrt Destructor called" << endl;
}

MexpNode* OperatorSqrt :: clone(){
    OperatorSqrt *new_node = new OperatorSqrt();
    *new_node = *this;
    this -> parent = NULL;
    this -> left = NULL;
    this -> right = NULL;
    this -> First_left = NULL;
    this -> First_right = NULL;
    return new_node;
}

mexprcpp_dtypes_t OperatorSqrt :: result (mexprcpp_dtypes_t d_id1, mexprcpp_dtypes_t d_id2){
    switch(d_id1){
        case MATH_CPP_INT :
        return MATH_CPP_DOUBLE;
        break;
        case MATH_CPP_DOUBLE :
        return MATH_CPP_DOUBLE;
        break;
        case MATH_CPP_DTYPE_WILDCRAD :
        return MATH_CPP_DOUBLE;
        break;
        default :
        return MATH_CPP_DTYPE_INVALID;
    }
}

// max operator
OperatorMax :: OperatorMax(){
    this -> op_id = MATH_CPP_MAX;
    this -> name = "max";
    this -> isUnary = false;
}

OperatorMax :: ~OperatorMax(){
    // cout << "OperatorMax Destructor called" << endl;
}

MexpNode* OperatorMax :: clone(){
    OperatorMax *new_node = new OperatorMax();
    *new_node = *this;
    this -> parent = NULL;
    this -> left = NULL;
    this -> right = NULL;
    this -> First_left = NULL;
    this -> First_right = NULL;
    return new_node;
}

mexprcpp_dtypes_t OperatorMax :: result(mexprcpp_dtypes_t d_id1 , mexprcpp_dtypes_t d_id2){
    switch(d_id1){
        case MATH_CPP_INT : 
            switch(d_id2){
                case MATH_CPP_INT :
                return MATH_CPP_INT;
                case MATH_CPP_DOUBLE :
                return MATH_CPP_DOUBLE;
                case MATH_CPP_DTYPE_WILDCRAD :
                return MATH_CPP_INT;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        case MATH_CPP_DOUBLE :
            switch(d_id2){
                case MATH_CPP_INT :
                return MATH_CPP_DOUBLE;
                case MATH_CPP_DOUBLE :
                return MATH_CPP_DOUBLE;
                case MATH_CPP_DTYPE_WILDCRAD :
                return MATH_CPP_DOUBLE;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        case MATH_CPP_STRING :
            switch(d_id2){
                case MATH_CPP_STRING :
                return MATH_CPP_STRING;
                case MATH_CPP_DTYPE_WILDCRAD :
                return MATH_CPP_STRING;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        case MATH_CPP_DTYPE_WILDCRAD :
            switch(d_id2){
                case MATH_CPP_INT :
                return MATH_CPP_INT;
                case MATH_CPP_DOUBLE :
                return MATH_CPP_DOUBLE;
                case MATH_CPP_STRING :
                return MATH_CPP_STRING;
                case MATH_CPP_DTYPE_WILDCRAD :
                return MATH_CPP_DTYPE_WILDCRAD;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        default : 
        return MATH_CPP_DTYPE_INVALID;
    }
}

// min operator
OperatorMin :: OperatorMin(){
    this -> op_id = MATH_CPP_MIN;
    this -> name = "min";
    this -> isUnary = false;
}

OperatorMin :: ~OperatorMin(){
    // cout << "OperatorMin Destructor called" << endl;
}

MexpNode* OperatorMin :: clone(){
    OperatorMin *new_node = new OperatorMin();
    *new_node = *this;
    this -> parent = NULL;
    this -> left = NULL;
    this -> right = NULL;
    this -> First_left = NULL;
    this -> First_right = NULL;
    return new_node;
}

mexprcpp_dtypes_t OperatorMin :: result(mexprcpp_dtypes_t d_id1 , mexprcpp_dtypes_t d_id2){
    switch(d_id1){
        case MATH_CPP_INT : 
            switch(d_id2){
                case MATH_CPP_INT :
                return MATH_CPP_INT;
                case MATH_CPP_DOUBLE :
                return MATH_CPP_DOUBLE;
                case MATH_CPP_DTYPE_WILDCRAD :
                return MATH_CPP_INT;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        case MATH_CPP_DOUBLE :
            switch(d_id2){
                case MATH_CPP_INT :
                return MATH_CPP_DOUBLE;
                case MATH_CPP_DOUBLE :
                return MATH_CPP_DOUBLE;
                case MATH_CPP_DTYPE_WILDCRAD :
                return MATH_CPP_DOUBLE;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        case MATH_CPP_STRING :
            switch(d_id2){
                case MATH_CPP_STRING :
                return MATH_CPP_STRING;
                case MATH_CPP_DTYPE_WILDCRAD :
                return MATH_CPP_STRING;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        break;
        case MATH_CPP_DTYPE_WILDCRAD :
            switch(d_id2){
                case MATH_CPP_INT :
                return MATH_CPP_INT;
                case MATH_CPP_DOUBLE :
                return MATH_CPP_DOUBLE;
                case MATH_CPP_STRING :
                return MATH_CPP_STRING;
                case MATH_CPP_DTYPE_WILDCRAD :
                return MATH_CPP_DTYPE_WILDCRAD;
                default :
                return MATH_CPP_DTYPE_INVALID;
            }
        default : 
        return MATH_CPP_DTYPE_INVALID;
    }
}

Operator * Operator :: factory(mexprcpp_operators_t op_id){
    switch (op_id)
    {
    case (int)MATH_CPP_PLUS:
        return new OperatorPlus();
    case (int)MATH_CPP_MINUS:
        return new OperatorMinus();
    case (int)MATH_CPP_MUL:
        return new OperatorMul();
    case (int)MATH_CPP_DIV:
        return new OperatorDiv();
    case (int)MATH_CPP_EQ:
        return new OperatorEq();
    case (int)MATH_CPP_NEQ:
        return new OperatorNeq();
    case (int)MATH_CPP_LESS_THAN:
        return new OperatorLessthan();
    case (int)MATH_CPP_GREATER_THAN:
        return new OperatorGreaterthan();
    case (int)MATH_CPP_SQR:
        return new OperatorSqr();
    case (int)MATH_CPP_SQRT:
        return new OperatorSqrt();
    case (int)MATH_CPP_MAX:
        return new OperatorMax();
    case (int)MATH_CPP_MIN:
        return new OperatorMin();
    default:
        assert(false); // should never reach here
        return nullptr;
    }
}