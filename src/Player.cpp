#include "Player.h"
#include <iostream>
#include <cstdlib>

Code Player::guessCode() const
{
    Code::CodeType code;
    for (auto i = 0u; i < Code::CODE_SIZE; ++i)
    {
        while (true)
        {
            std::string code_elem;
            std::cout << "Please give the " << i << " element [0-9]: ";
            std::cin >> code_elem;

            if (code_elem.size() != 1 || !std::isdigit(code_elem[0]))
            {
                std::cout << "You passed: " << code_elem << " which it does not meet one of the following conditions:\n"
                "\t- the char is a digit\n"
                "\t- there is only one char\n\n"
                "Try it again!" << std::endl;

                continue;
            }

            code[i] = code_elem[0];
            break;
        }
    }

    return Code(code);
}