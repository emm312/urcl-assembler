#include <tokeniser.h>
#include <iostream>
#include <vector>


std::string first_word(std::string line) {
    std::string word;
    for (char c : line) {
        if (c == ' ') {
            return word;
        } else {
            word.append(&c);
        }
    }
}

std::vector<std::string> to_lines(std::string code) {
    std::vector<std::string> lines;
    std::string line;
    for (char c : code) {
        if (c == '\n') {
            lines.push_back(line);
            line = "";
        } else {
            line += c;
        }
    }
    return lines;
}


std::vector<Token> tokeniser(std::string code) {
    std::vector<Token> tokens;

    std::vector<std::string> lines = to_lines(code);

    for (long long unsigned int i = 0; i < lines.size(); i++) {
        if (lines[i][0]=='.') {
            Token token;
            token.type = TT_LABEL;
            token.value = first_word(lines[i]);
            tokens.push_back(token);
        }
    }





    return tokens;
}


