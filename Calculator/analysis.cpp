//
// Created by 都比253 on 2020/10/25.
//
#include "analysis.h"
#include "token.h"
bool first_minus;
static std::tuple<double, std::string>analysis_factor(std::string input){
    double result;
    Token state;
    std::tie(state, input) = Input_analysis(input);
    switch (state.type) {
        case Token_type::Number: result = state.value; break;
        case Token_type::Left_bracket:
            std::tie(result, input) = analysis_expression(input);
            std::tie(state,input) = Input_analysis(input);
            if (state.type != Token_type::Right_bracket){
                std:: cout << "Expression missing closing bracket." << std::endl << std::endl;
                throw std::runtime_error("");
            }
            break;
        case Token_type::Minus:
            if (first_minus){
                std::tie(state, input) = Input_analysis(input);
                result = -state.value;
                first_minus = false;
            }
            else{
                std:: cout << "Mathematical errors." << std::endl << std::endl;
                throw std::runtime_error("");
            }
            break;
        default: std:: cout << "Mathematical errors." << std::endl << std::endl;
            throw std::runtime_error("");
    }
    return {result, input};
}


static std::tuple<double, std::string>analysis_term(std::string input){
    double result;
    std::tie(result, input) = analysis_factor(input);
    bool whether_loop = true;
    while (whether_loop){
        Token op;
        std::string rest;
        double term = 0;
        std::tie(op, rest) = Input_analysis(input);
        switch (op.type) {
            case Token_type:: Multiply : std::tie(term, input) = analysis_factor(rest); result *= term; break;
            case Token_type:: Divide:
                std::tie(term, input) = analysis_factor(rest);
                if (term == 0.0){
                    std:: cout << "Numbers cannot be divided by zero." << std::endl << std::endl;
                    throw std::runtime_error("");
                }
                result /= term;
                break;
            case Token_type:: Power:
                std::tie(term, input) = analysis_factor(rest); result = pow(result, term); break;
            default: whether_loop = false; break;
        }
    }

    return {result, input};
}


std::tuple<double, std::string>analysis_expression(std::string input){
    double result;
    std::tie(result, input) = analysis_term(input);
    bool whether_loop = true;
    while (whether_loop){
        Token op;
        std::string rest;
        double term;
        std::tie(op, rest) = Input_analysis(input);
        switch (op.type) {
            case Token_type:: Plus : std::tie(term, input) = analysis_term(rest); result += term; break;
            case Token_type:: Minus: std::tie(term, input) = analysis_term(rest); result -= term; break;
            default: whether_loop = false; break;
        }
    }
    return {result, input};
}