#include<bits/stdc++.h>
#include "MexpTree.h"
using namespace std;

MexpNode :: MexpNode(){
    // cout << "MexpNode Constructor called" << endl;
}

MexpNode :: ~MexpNode(){
    // cout << "MexpNode Destructor called" << endl;
}

MexpTree :: MexpTree(lex_data_t **postfix_array, int size){
    this -> root = NULL;
    this -> First_head = NULL;
};