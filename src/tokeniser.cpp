#include <tokeniser.h>
#include <iostream>
#include <vector>


std::vector<std::string> to_words(std::string code) {
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
    lines.push_back(line);
    // split lines by space
    std::vector<std::string> words;
    for (const std::string& line: lines) {
        std::string word;
        std::string e;
        for (char c : line) {
            if (c == ' ') {
                words.push_back(e);
                e = "";
            } else {
                e += c;
            }
        }
        words.push_back(e);
    }
    return words;
}


std::vector<Token> tokeniser(std::string code) {
    std::vector<Token> tokens;

    std::vector<std::string> words = to_words(code);


    // INSTRUCTIONS
    std::vector<std::string> instructions;
    instructions.push_back("ADD");
    instructions.push_back("RSH");
    instructions.push_back("LOD");
    instructions.push_back("STR");
    instructions.push_back("BGE");
    instructions.push_back("NOR");
    instructions.push_back("IMM");
    instructions.push_back("JMP");
    // print each line
    for (long long unsigned int i = 0; i < words.size(); i++) {
        if (words[i][0]=='.') {
            Token token;
            token.type = TT_LABEL;
            token.value = words[i];
            tokens.push_back(token);
        } else if (std::find(instructions.begin(), instructions.end(), words[i]) != instructions.end()) {
            Token token;
            token.type = TT_INSTRUCTION;
            token.value = words[i];
            tokens.push_back(token);
        } else if (words[i][0] == 'R') {
            Token token;
            token.type = TT_REGADDR;
            token.value = words[i].substr(1,words[i].length());
            tokens.push_back(token);
        } else if (words[i][0] == '#') {
            Token token;
            token.type = TT_MEMADDR;
            token.value = words[i].substr(1,words[i].length());
            tokens.push_back(token);
        } else if (words[i][0] >= '0' && words[i][0] <= '9') {
            Token token;
            token.type = TT_IMMEDIATE;
            token.value = words[i];
            tokens.push_back(token);
        } else {
            std::cerr  << "Unknown instruction or Invalid Syntax: " << words[i] << "\n";
        }
    }
    


    return tokens;
}


