//
// Created by 都比253 on 2020/10/24.
//
#include "token.h"
static std::tuple<double, std::string> parse_number(std::string input){
    std::string numstr;
    bool firstdot = true;
    while (true){
        if (input.empty()){
            break;
        }
        char ch = input.front();
        if ((ch >= '0' && ch <= '9')||(ch == '.' && firstdot)){
            numstr.push_back(ch);
            input.erase(input.begin());
            if (ch == '.'){
                firstdot = false;
            }
        } else break;
    }
    return {std::stod(numstr),input};
}

std::tuple<Token, std::string>Input_analysis(std::string input){
    Token state;
    char character;
    do{
        if (input.empty()){
            state.type = Token_type:: End;
            return {state, ""};
        } else{
            character = input.front();//得到当前输入字符串的第一个字符
            input.erase(input.begin());//删除刚刚读取到的字符
        }
    }while (character == ' ');
    switch (character) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
        case '^':
            state.type = Token_type(character);
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            state.type = Token_type::Number;
            input.insert(input.begin(),character);
            std::tie(state.value,input) = parse_number(input);
            break;
        default:
            std:: cout << "Unavailable symbols were entered." << std::endl << std::endl;
            throw std::runtime_error("");
    }
    return {state, input};
}