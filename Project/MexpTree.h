#ifndef _MEXP_TREE_H_
#define _MEXP_TREE_H_

#include<stdbool.h>
#include<stdlib.h>
#include<stdint.h>
#include "MexprEnums.h"
#include "ParserExport.h"

class Dtype; // forward declaration
class MexpNode{
    private:
    protected:
    MexpNode();
    public:
    // virtual methods define here because if direcly use destructor of base class
    // then derived class destructor will not be called and hence memory leak will occur and vice versa
    virtual ~MexpNode();
    MexpNode *parent;
    MexpNode *left;
    MexpNode *right;
    MexpNode *First_left;
    MexpNode *First_right;
    virtual MexpNode *clone() = 0; // pure virtual function makes this class abstract. Derived class must override this method
    virtual mexprcpp_dtypes_t result(mexprcpp_dtypes_t d_id1 , mexprcpp_dtypes_t d_id2) = 0;
    virtual Dtype *compute(Dtype * dtype1, Dtype * dtype2) = 0;
};

class MexpTree{

    private:
    mexprcpp_dtypes_t internalValidate(MexpNode * root);
    Dtype * internalEvaluate(MexpNode * root);
    protected:
    public:
    MexpNode *root;
    MexpNode *First_head;
    MexpTree();
    MexpTree(lex_data_t **postfix_array, int size); // constructor
    static void Inorder( MexpTree *tree );
    virtual ~MexpTree();
    bool validate(MexpNode * root);
    Dtype * evaluate(MexpNode * root);
};

#endif