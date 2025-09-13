#ifndef _OPERATORS_H_
#define _OPERATORS_H_

#include<string>
#include<stdbool.h>
#include "MexprEnums.h"
#include "MexpTree.h"
#include "Dtype.h"

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
    virtual MexpNode *clone() = 0;
    virtual mexprcpp_dtypes_t result(mexprcpp_dtypes_t d_id1 , mexprcpp_dtypes_t d_id2) = 0;
    virtual Dtype *compute(Dtype * dtype1, Dtype * dtype2) = 0;
};

// + operator
class OperatorPlus : public Operator{
    private:
    protected:
    public:
    OperatorPlus();
    ~OperatorPlus();
    virtual MexpNode *clone() override;
    virtual mexprcpp_dtypes_t result(mexprcpp_dtypes_t d_id1 , mexprcpp_dtypes_t d_id2) override;
    virtual Dtype *compute(Dtype * dtype1, Dtype * dtype2) override;
};

// - operator
class OperatorMinus : public Operator{
    private:
    protected:
    public:
    OperatorMinus();
    ~OperatorMinus();
    virtual MexpNode *clone() override;
    virtual mexprcpp_dtypes_t result(mexprcpp_dtypes_t d_id1 , mexprcpp_dtypes_t d_id2) override;
    virtual Dtype *compute(Dtype * dtype1, Dtype * dtype2) override;
};

// * operator
class OperatorMul : public Operator{
    private:
    protected:
    public:
    OperatorMul();
    ~OperatorMul();
    virtual MexpNode *clone() override;
    virtual mexprcpp_dtypes_t result(mexprcpp_dtypes_t d_id1 , mexprcpp_dtypes_t d_id2) override;
    virtual Dtype *compute(Dtype * dtype1, Dtype * dtype2) override;
};

// / operator
class OperatorDiv : public Operator{
    private:
    protected:
    public:
    OperatorDiv();
    ~OperatorDiv();
    virtual MexpNode *clone() override;
    virtual mexprcpp_dtypes_t result(mexprcpp_dtypes_t d_id1 , mexprcpp_dtypes_t d_id2) override;
    virtual Dtype *compute(Dtype * dtype1, Dtype * dtype2) override;
};

// == operator
class OperatorEq : public Operator{
    private:
    protected:
    public:
    OperatorEq();
    ~OperatorEq();
    virtual MexpNode *clone() override;
    virtual mexprcpp_dtypes_t result(mexprcpp_dtypes_t d_id1 , mexprcpp_dtypes_t d_id2) override;
    virtual Dtype *compute(Dtype * dtype1, Dtype * dtype2) override;
};

// != operator
class OperatorNeq : public Operator{
    private:
    protected:
    public:
    OperatorNeq();
    ~OperatorNeq();
    virtual MexpNode *clone() override;
    virtual mexprcpp_dtypes_t result(mexprcpp_dtypes_t d_id1 , mexprcpp_dtypes_t d_id2) override;
    virtual Dtype *compute(Dtype * dtype1, Dtype * dtype2) override;
};

// < operator
class OperatorLessthan : public Operator{
    private:
    protected:
    public:
    OperatorLessthan();
    ~OperatorLessthan();
    virtual MexpNode *clone() override;
    virtual mexprcpp_dtypes_t result(mexprcpp_dtypes_t d_id1 , mexprcpp_dtypes_t d_id2) override;
    virtual Dtype *compute(Dtype * dtype1, Dtype * dtype2) override;
};

// > operator
class OperatorGreaterthan : public Operator{
    private:
    protected:
    public:
    OperatorGreaterthan();
    ~OperatorGreaterthan();
    virtual MexpNode *clone() override;
    virtual mexprcpp_dtypes_t result(mexprcpp_dtypes_t d_id1 , mexprcpp_dtypes_t d_id2) override;
    virtual Dtype *compute(Dtype * dtype1, Dtype * dtype2) override;
};

// sqr operator
class OperatorSqr : public Operator{
    private:
    protected:
    public:
    OperatorSqr();
    ~OperatorSqr();
    virtual MexpNode *clone() override;
    virtual mexprcpp_dtypes_t result(mexprcpp_dtypes_t d_id1 , mexprcpp_dtypes_t d_id2) override;
    virtual Dtype *compute(Dtype * dtype1, Dtype * dtype2) override;
};

// sqrt operator
class OperatorSqrt : public Operator{
    private:
    protected:
    public:
    OperatorSqrt();
    ~OperatorSqrt();
    virtual MexpNode *clone() override;
    virtual mexprcpp_dtypes_t result(mexprcpp_dtypes_t d_id1 , mexprcpp_dtypes_t d_id2) override;
    virtual Dtype *compute(Dtype * dtype1, Dtype * dtype2) override;
};

// max operator
class OperatorMax : public Operator{
    private:
    protected:
    public:
    OperatorMax();
    ~OperatorMax();
    virtual MexpNode *clone() override;
    virtual mexprcpp_dtypes_t result(mexprcpp_dtypes_t d_id1 , mexprcpp_dtypes_t d_id2) override;
    virtual Dtype *compute(Dtype * dtype1, Dtype * dtype2) override;
};

// min operator
class OperatorMin : public Operator{
    private:
    protected:
    public:
    OperatorMin();
    ~OperatorMin();
    virtual MexpNode *clone() override;
    virtual mexprcpp_dtypes_t result(mexprcpp_dtypes_t d_id1 , mexprcpp_dtypes_t d_id2) override;
    virtual Dtype *compute(Dtype * dtype1, Dtype * dtype2) override;
};

class OperatorPow : public Operator{
    private:
    protected:
    public:
    OperatorPow();
    ~OperatorPow();
    virtual MexpNode *clone() override;
    virtual mexprcpp_dtypes_t result(mexprcpp_dtypes_t d_id1 , mexprcpp_dtypes_t d_id2) override;
    virtual Dtype *compute(Dtype * dtype1, Dtype * dtype2) override;
};

#endif