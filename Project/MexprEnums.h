#ifndef _MEXPR_ENUMS_
#define _MEXPR_ENUMS_

typedef enum{

    MATH_CPP_INT,
    MATH_CPP_DOUBLE, // decimal values
    MATH_CPP_VARIABLE, // Alphanumeric words
    MATH_CPP_IPV4,


    MATH_CPP_DTYPE_MAX

}mexprcpp_dtype_t;

typedef enum{

    PARSER_EOL = MATH_CPP_DTYPE_MAX + 1
}extra_enums;

#endif