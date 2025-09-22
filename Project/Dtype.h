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

    bool isResolved; // to check if the variable is resolved or not

    virtual ~Dtype();
    // This is a factory method which will return the Dtype object based on the did passed
    static Dtype * factory(mexprcpp_dtypes_t did, std :: string val);
    virtual void setValue(void *value) = 0;
    virtual void setValue (Dtype *) = 0;
    // This is a clone method which will return a copy of the current object
    virtual MexpNode *clone() = 0;
    // This method will return the resultant dtype id after applying an operator on two dtypes
    virtual mexprcpp_dtypes_t result(mexprcpp_dtypes_t d_id1 , mexprcpp_dtypes_t d_id2) = 0;
    // This method will compute the value after applying an operator on two dtypes
    virtual Dtype *compute(Dtype * dtype1, Dtype * dtype2) = 0;
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
    virtual void setValue(void *value) override;
    virtual void setValue (Dtype *) override;
    virtual MexpNode *clone() override;
    virtual mexprcpp_dtypes_t result(mexprcpp_dtypes_t d_id1 , mexprcpp_dtypes_t d_id2) override;
    virtual Dtype *compute(Dtype * dtype1, Dtype * dtype2) override;
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
    virtual void setValue(void *value) override;
    virtual void setValue (Dtype *) override;
    virtual MexpNode *clone() override;
    virtual mexprcpp_dtypes_t result(mexprcpp_dtypes_t d_id1 , mexprcpp_dtypes_t d_id2) override;
    virtual Dtype *compute(Dtype * dtype1, Dtype * dtype2) override;
    
};


// String Dtype
class Dtype_STRING : public Dtype{
    
    private:
    protected:
    public:
    std :: string string_val;
    Dtype_STRING();
    ~Dtype_STRING();
    virtual void setValue(void *value) override;
    virtual void setValue (Dtype *) override;
    virtual MexpNode *clone() override;
    virtual mexprcpp_dtypes_t result(mexprcpp_dtypes_t d_id1 , mexprcpp_dtypes_t d_id2) override;
    virtual Dtype *compute(Dtype * dtype1, Dtype * dtype2) override;
};

// bool Dtype
class Dtype_BOOL : public Dtype{
    
    private:
    protected:
    public:
    bool bool_val;
    Dtype_BOOL();
    ~Dtype_BOOL();
    virtual void setValue(void *value) override;
    virtual void setValue (Dtype *) override;
    virtual MexpNode *clone() override;
    virtual mexprcpp_dtypes_t result(mexprcpp_dtypes_t d_id1 , mexprcpp_dtypes_t d_id2) override;
    virtual Dtype *compute(Dtype * dtype1, Dtype * dtype2) override;
};

// variable Dtype
class Dtype_VARIABLE : public Dtype{
    
    private:
    protected:
    public:
    std :: string var_name;
    // resolution Information
    void * data_src;
    Dtype *(*compute_fn_ptr)(char *, void *);
    mexprcpp_dtypes_t resolved_did;

    Dtype_VARIABLE();
    Dtype_VARIABLE(std :: string var);  // parametrized constructor
    ~Dtype_VARIABLE();
    virtual void setValue(void *value) override;
    virtual void setValue (Dtype *) override;
    virtual MexpNode *clone() override;
    virtual mexprcpp_dtypes_t result(mexprcpp_dtypes_t d_id1 , mexprcpp_dtypes_t d_id2) override;
    virtual Dtype *compute(Dtype * dtype1, Dtype * dtype2) override;
    void ResolveOperand(mexprcpp_dtypes_t resolved_did, 
        void * data_src, Dtype *(*compute_fn_ptr)(char *, void *));
};
#endif