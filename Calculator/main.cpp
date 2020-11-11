#include <iostream>//1
#include "token.h"
#include "analysis.h"

int main()
{
    std::string res,input;
    unsigned char w = 0;
    /*std::cout << "Simple calculator [version 12.1.38]" << std::endl;
    std::cout << "Designed by Dubi253" << std::endl;
    std::cout << "(c) 2020 All rights reserved" << std::endl << std::endl;*/
    std::cout << "Please enter the formula." << std::endl;
    while (getline(std::cin, input)){
        first_minus = true;
        double result = 0.0;
                if (input.empty()){
            for (int i = 0; i <= w; ++i) {
                std::cout << "?" ;
            }
            std::cout << std::endl;
            ++w;
        } else{
            try {
                std::tie(result, res) = analysis_expression(input);
                std::cout << result << std::endl << std::endl;
                w = 0;
            }
            catch (...) {}
        }

    }
}