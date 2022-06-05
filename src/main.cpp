#include <iostream>
#include <tokeniser.h>
#include <assembler.h>
#include <bitset>
#include <fstream>

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

int main(int argc, char **argv)
{
    // open urclcode.txt
    std::cout << "Opening file: " << argv[1] << '\n';
    std::ifstream file(argv[1]);
    // read the file into a string
    std::string code;
    code = std::string(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());

    std::transform(code.begin(), code.end(), code.begin(), ::toupper);
    std::vector<Token> tokens = tokeniser(code);
    std::vector<uint16_t> codebytes = assembler(tokens);
    //dump the raw bytes to the file in order
    std::ofstream outfile(argv[2], std::ios::binary);
    for (uint16_t byte: codebytes) {
        outfile.write((char*)&byte, sizeof(byte));
    }
    return 0;
}