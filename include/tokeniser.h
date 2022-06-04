#ifndef TOKENISER_H
#define TOKENISER_H

#include <iostream>
#include <vector>

enum TT_TYPES {
    TT_INSTRUCTION,
    TT_LABEL,
    TT_IMMEDIATE,
    TT_REGADDR,
    TT_MEMADDR,
    TT_UNKNOWN
};

struct Token {
    TT_TYPES type;
    std::string value;
};


std::vector<Token> tokeniser(std::string code);


#endif