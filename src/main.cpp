#include <iostream>
#include <tokeniser.h>


int main()
{
    std::string code = ".label\n.label2";
    std::vector<Token> tokens = tokeniser(code);
    std::cout << "test";
    std::cout << tokens.size();
    return 0;
}