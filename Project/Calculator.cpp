#include<bits/stdc++.h>
using namespace std;
#include "Dtype.h"
#include "MexpTree.h"
#include "MexprEnums.h"

extern "C" void Calculator(MexpTree * Tree){
    Dtype *Output = Tree -> evaluate(Tree -> root);
    if(Output){
        switch(Output -> d_id){
            case MATH_CPP_INT : {
                Dtype_INT *int_output = dynamic_cast<Dtype_INT *>(Output);
                cout << int_output -> int_val << endl;
                break;
            }
            case MATH_CPP_DOUBLE : {
                Dtype_DOUBLE *double_output = dynamic_cast<Dtype_DOUBLE *>(Output);
                cout << double_output -> double_val << endl;
                break;
            }
            case MATH_CPP_STRING : {
                Dtype_STRING *string_output = dynamic_cast<Dtype_STRING *>(Output);
                cout << string_output -> string_val << endl;
                break;
            }
            case MATH_CPP_BOOL : {
                Dtype_BOOL *bool_output = dynamic_cast<Dtype_BOOL *>(Output);
                if(bool_output -> bool_val){
                    cout << "TRUE" << endl;
                }else{
                    cout << "FALSE" << endl;
                }
                break;
            }
            default : {
                cout << "Error in evaluation" << endl;
            }
        }
    }else{
        cout << "Error in evaluation" << endl;
    }
}