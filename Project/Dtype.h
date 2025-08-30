#ifndef _DTYPE_H_
#define _DTYPE_H_

#include<string>
#include "MexprEnums.h"
#include "MexpTree.h"

class Dtype : public MexpNode {
    private:
    protected:
    Dtype();
    public:
    mexprcpp_dtypes_t d_id;   // Dtype ID
    virtual ~Dtype();
};


// Integer Dtype
class Dtype_INT : public Dtype{

    private:
    protected:
    public:
    int int_val;
    Dtype_INT();
    Dtype_INT(int val);  // parametrized constructor
    ~Dtype_INT();

};


// Double Dtype
class Dtype_DOUBLE : public Dtype{
    
    private:
    protected:
    public:
    double double_val;
    Dtype_DOUBLE();
    Dtype_DOUBLE(double val);  // parametrized constructor
    ~Dtype_DOUBLE();
};


// String Dtype
class Dtype_STRING : public Dtype{
    
    private:
    protected:
    public:
    std :: string string_val;
    Dtype_STRING();
    ~Dtype_STRING();
};

#endif