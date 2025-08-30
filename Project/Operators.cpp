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

// - operator
OperatorMinus :: OperatorMinus(){
    this -> op_id = MATH_CPP_MINUS;
    this -> name = "-";
    this -> isUnary = false;
}   

OperatorMinus :: ~OperatorMinus(){
    // cout << "OperatorMinus Destructor called" << endl;
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

// / operator
OperatorDiv :: OperatorDiv(){
    this -> op_id = MATH_CPP_DIV;
    this -> name = "/";
    this -> isUnary = false;
}

OperatorDiv :: ~OperatorDiv(){
    // cout << "OperatorDiv Destructor called" << endl;
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

// != operator
OperatorNeq :: OperatorNeq(){
    this -> op_id = MATH_CPP_NEQ;
    this -> name = "!=";
    this -> isUnary = false;
}

OperatorNeq :: ~OperatorNeq(){
    // cout << "OperatorNeq Destructor called" << endl;
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

// > operator
OperatorGreaterthan :: OperatorGreaterthan(){
    this -> op_id = MATH_CPP_GREATER_THAN;
    this -> name = ">";
    this -> isUnary = false;
}

OperatorGreaterthan :: ~OperatorGreaterthan(){
    // cout << "OperatorGreaterthan Destructor called" << endl;
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

// sqrt operator
OperatorSqrt :: OperatorSqrt(){
    this -> op_id = MATH_CPP_SQRT;
    this -> name = "sqrt";
    this -> isUnary = true;
}

OperatorSqrt :: ~OperatorSqrt(){
    // cout << "OperatorSqrt Destructor called" << endl;
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

// min operator
OperatorMin :: OperatorMin(){
    this -> op_id = MATH_CPP_MIN;
    this -> name = "min";
    this -> isUnary = false;
}

OperatorMin :: ~OperatorMin(){
    // cout << "OperatorMin Destructor called" << endl;
}