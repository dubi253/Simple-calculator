//
// Created by 都比253 on 2020/10/24.
//
#include <string>
#include <tuple>
#include <iostream>
enum class Token_type{
    Number, End, Plus = '+',  Minus = '-', Multiply = '*', Divide = '/', Left_bracket = '(', Right_bracket = ')', Power = '^'
};

struct Token{
    Token_type type;
    double value = 0.0;
};

static std::tuple<double, std::string> parse_number(std::string input);
std::tuple<Token, std::string>Input_analysis(std::string input);
#ifndef CALCULATOR_TOKEN_H
#define CALCULATOR_TOKEN_H

#endif //CALCULATOR_TOKEN_H
