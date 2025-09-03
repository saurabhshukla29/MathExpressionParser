#include "Dtype.h"
#include <bits/stdc++.h>
using namespace std;

// :: scope resolution operator
// This operator is used to define a constructor outside the class
Dtype :: Dtype(){
    this -> d_id = MATH_CPP_DTYPE_INVALID;
}

Dtype :: ~Dtype(){
    // cout << "Dtype destructor called" << endl;
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

Dtype_INT :: ~Dtype_INT(){
    // cout << "Dtype destructor called" << endl;
}

void Dtype_INT :: setValue(void *value){
    this -> int_val = atoi((char *)value);
}

void Dtype_INT :: setValue(Dtype *dtype){
    Dtype_INT *int_dtype = dynamic_cast<Dtype_INT *>(dtype);
    this -> int_val = int_dtype -> int_val;
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

void Dtype_DOUBLE :: setValue(void *value){
    this -> double_val = (double)atof((char *)value);
}

void Dtype_DOUBLE :: setValue(Dtype *dtype){
    Dtype_DOUBLE *double_dtype = dynamic_cast<Dtype_DOUBLE *>(dtype);
    this -> double_val = double_dtype -> double_val;
}


// String Dtype
Dtype_STRING :: Dtype_STRING(){
    this -> d_id = MATH_CPP_STRING;
}   

Dtype_STRING :: ~Dtype_STRING(){
    // cout << "Dtype_STRING destructor called" << endl;
}

void Dtype_STRING :: setValue(void *value){
    this -> string_val.assign(std :: string((char *)value));

    // remove the double quotes from the string if present
    this -> string_val.erase(remove(this -> string_val.begin(), this -> string_val.end(), '\"'), 
                            this -> string_val.end());

    // remove the single quotes from the string if present
    this -> string_val.erase(remove(this -> string_val.begin(), this -> string_val.end(), '\''), 
                            this -> string_val.end());
}

void Dtype_STRING :: setValue(Dtype *dtype){
    Dtype_STRING *string_dtype = dynamic_cast<Dtype_STRING *>(dtype);
    this -> string_val = string_dtype -> string_val;
}


// General Rule of defining function outside class
// <return-type> <ClassName>::<FunctionName>(parameters) { ... }
Dtype* Dtype :: factory(mexprcpp_dtypes_t d_id, string val){
    switch (d_id)
    {
    case (int)MATH_CPP_INT:{
        Dtype_INT *int_node = new Dtype_INT();
        int_node -> int_val = stoi(val);
        return int_node;
    }
    case (int)MATH_CPP_DOUBLE:{
        Dtype_DOUBLE *double_node = new Dtype_DOUBLE();
        double_node -> double_val = stod(val);
        return double_node;
    }
    case (int)MATH_CPP_STRING:{
        Dtype_STRING *string_node = new Dtype_STRING();
        string_node -> string_val = val;
        return string_node;
    }
    default:
        assert(false); // should never reach here
        return nullptr;
    }
}