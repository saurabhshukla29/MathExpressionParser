#include "Dtype.h"
using namespace std;

// :: scope resolution operator
// This operator is used to define a function outside the class
Dtype :: Dtype(){
    this -> d_id = MATH_CPP_DTYPE_INVALID;
}


// Concrete class now :

// Integer Dtype
Dtype_INT :: Dtype_INT(){
    this -> d_id = MATH_CPP_INT;
}

Dtype_INT :: Dtype_INT(int val){
    this -> d_id = MATH_CPP_INT;
    this -> int_val = val;
}

Dtype :: ~Dtype(){
    // cout << "Dtype destructor called" << endl;
}



// Double Dtype
Dtype_DOUBLE :: Dtype_DOUBLE(){
    this -> d_id = MATH_CPP_DOUBLE;
}

Dtype_DOUBLE :: Dtype_DOUBLE(double val){
    this -> d_id = MATH_CPP_DOUBLE;
    this -> double_val = val;
}

Dtype_DOUBLE :: ~Dtype_DOUBLE(){
    // cout << "Dtype_DOUBLE destructor called" << endl;
}