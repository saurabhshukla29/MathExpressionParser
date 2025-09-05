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
    static Dtype * factory(mexprcpp_dtypes_t did, std :: string val);
    virtual void setValue(void *value) ;
    virtual void setValue (Dtype *) ;
    virtual MexpNode *clone();
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
    virtual MexpNode *clone();
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
    virtual MexpNode *clone();
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
    virtual MexpNode *clone();
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
    virtual MexpNode *clone();
};


#endif