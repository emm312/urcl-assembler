#include <iostream>
#include <tokeniser.h>


std::string enumtostring(TT_TYPES type) {
    switch (type) {
        case TT_INSTRUCTION:
            return "TT_INSTRUCTION";
        case TT_LABEL:
            return "TT_LABEL";
        case TT_IMMEDIATE:
            return "TT_IMMEDIATE";
        case TT_REGADDR:
            return "TT_REGADDR";
        case TT_MEMADDR:
            return "TT_MEMADDR";
        default:
            return "TT_UNKNOWN";
    }
    return "";
}

int main()
{
    std::string code = ".label\n.label2\nJMP .label2\nADD R0 R1 R2\n";
    std::vector<Token> tokens = tokeniser(code);
    // print the tokens var
    std::cout << "Tokens:" << "\n";
    for (Token token : tokens) {
        std::cout << token.value << " " << enumtostring(token.type) << "\n";
    }
    return 0;
}