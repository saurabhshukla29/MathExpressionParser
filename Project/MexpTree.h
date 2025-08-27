#ifndef _MEXP_TREE_H_
#define _MEXP_TREE_H_

#include<stdbool.h>
#include<stdlib.h>
#include<stdint.h>
#include "MexprEnums.h"

class MexpNode{
    private:
    protected:
    MexpNode();
    public:
    // virtual methods define here because if direcly use destructor of base class
    // then derived class destructor will not be called and hence memory leak will occur and vice versa
    virtual ~MexpNode();
};

typedef struct lex_data_t;
class MexpTree{

    private:
    protected:
    public:
    MexpNode *root;
    MexpNode *First_head;
    MexpTree(lex_data_t **postfix_array, int size); // constructor
};

#endif