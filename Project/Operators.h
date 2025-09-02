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
};

// + operator
class OperatorPlus : public Operator{
    private:
    protected:
    public:
    OperatorPlus();
    ~OperatorPlus();
};

// - operator
class OperatorMinus : public Operator{
    private:
    protected:
    public:
    OperatorMinus();
    ~OperatorMinus();
};

// * operator
class OperatorMul : public Operator{
    private:
    protected:
    public:
    OperatorMul();
    ~OperatorMul();
};

// / operator
class OperatorDiv : public Operator{
    private:
    protected:
    public:
    OperatorDiv();
    ~OperatorDiv();
};

// == operator
class OperatorEq : public Operator{
    private:
    protected:
    public:
    OperatorEq();
    ~OperatorEq();
};

// != operator
class OperatorNeq : public Operator{
    private:
    protected:
    public:
    OperatorNeq();
    ~OperatorNeq();
};

// < operator
class OperatorLessthan : public Operator{
    private:
    protected:
    public:
    OperatorLessthan();
    ~OperatorLessthan();
};

// > operator
class OperatorGreaterthan : public Operator{
    private:
    protected:
    public:
    OperatorGreaterthan();
    ~OperatorGreaterthan();
};

// sqr operator
class OperatorSqr : public Operator{
    private:
    protected:
    public:
    OperatorSqr();
    ~OperatorSqr();
};

// sqrt operator
class OperatorSqrt : public Operator{
    private:
    protected:
    public:
    OperatorSqrt();
    ~OperatorSqrt();
};

// max operator
class OperatorMax : public Operator{
    private:
    protected:
    public:
    OperatorMax();
    ~OperatorMax();
};

// min operator
class OperatorMin : public Operator{
    private:
    protected:
    public:
    OperatorMin();
    ~OperatorMin();
};

#endif