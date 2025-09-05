#ifndef _OPERATORS_H_
#define _OPERATORS_H_

#include<string>
#include<stdbool.h>
#include "MexprEnums.h"
#include "MexpTree.h"

class Operator : public MexpNode{
    private:
    protected:
    Operator();
    public:
    virtual ~Operator();
    int op_id;  // operator id
    std :: string name;
    bool isUnary;
    static Operator * factory(mexprcpp_operators_t op_id);
    virtual MexpNode *clone();
};

// + operator
class OperatorPlus : public Operator{
    private:
    protected:
    public:
    OperatorPlus();
    ~OperatorPlus();
    virtual MexpNode *clone();
};

// - operator
class OperatorMinus : public Operator{
    private:
    protected:
    public:
    OperatorMinus();
    ~OperatorMinus();
    virtual MexpNode *clone();
};

// * operator
class OperatorMul : public Operator{
    private:
    protected:
    public:
    OperatorMul();
    ~OperatorMul();
    virtual MexpNode *clone();
};

// / operator
class OperatorDiv : public Operator{
    private:
    protected:
    public:
    OperatorDiv();
    ~OperatorDiv();
    virtual MexpNode *clone();
};

// == operator
class OperatorEq : public Operator{
    private:
    protected:
    public:
    OperatorEq();
    ~OperatorEq();
    virtual MexpNode *clone();
};

// != operator
class OperatorNeq : public Operator{
    private:
    protected:
    public:
    OperatorNeq();
    ~OperatorNeq();
    virtual MexpNode *clone();
};

// < operator
class OperatorLessthan : public Operator{
    private:
    protected:
    public:
    OperatorLessthan();
    ~OperatorLessthan();
    virtual MexpNode *clone();
};

// > operator
class OperatorGreaterthan : public Operator{
    private:
    protected:
    public:
    OperatorGreaterthan();
    ~OperatorGreaterthan();
    virtual MexpNode *clone();
};

// sqr operator
class OperatorSqr : public Operator{
    private:
    protected:
    public:
    OperatorSqr();
    ~OperatorSqr();
    virtual MexpNode *clone();
};

// sqrt operator
class OperatorSqrt : public Operator{
    private:
    protected:
    public:
    OperatorSqrt();
    ~OperatorSqrt();
    virtual MexpNode *clone();
};

// max operator
class OperatorMax : public Operator{
    private:
    protected:
    public:
    OperatorMax();
    ~OperatorMax();
    virtual MexpNode *clone();
};

// min operator
class OperatorMin : public Operator{
    private:
    protected:
    public:
    OperatorMin();
    ~OperatorMin();
    virtual MexpNode *clone();
};

#endif