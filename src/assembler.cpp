#include <assembler.h>
#include <tokeniser.h>
#include <iostream>
#include <vector>
#include <bitset>

std::vector<uint16_t> assembler(std::vector<Token> tokens) {
    std::vector<uint16_t> code;
    // loop through all tokens
    for (int i = 0; i<tokens.size(); i++) {
        if (tokens[i].type == TT_LABEL) {
            std::cerr << "Labels are not supported yet" << '\n';
        } else if (tokens[i].type == TT_INSTRUCTION ) {
            std::string instruction = tokens[i].value;
            
            if (instruction == "ADD") {
                for (int n=1; n<4; n++) {
                    if (tokens[i+n].type == TT_INSTRUCTION || tokens[i+n].type == TT_LABEL || tokens[i+n].type == TT_IMMEDIATE || tokens[i+n].type == TT_MEMADDR) {
                        std::cerr << "Invalid instruction Opperands" << '\n';
                        break;
                    }
                }
                std::string op1 = tokens[i+1].value;
                std::string op2 = tokens[i+2].value;
                std::string op3 = tokens[i+3].value;

                uint16_t op1_hex = std::stoi(op1, nullptr, 16);
                uint16_t op2_hex = std::stoi(op2, nullptr, 16);
                uint16_t op3_hex = std::stoi(op3, nullptr, 16);
                uint16_t instruction_hex = 0x0001;

                // add the opcodes to the instruction_hex, by adding 8 more bits
                instruction_hex = instruction_hex << 4;
                instruction_hex = instruction_hex + op1_hex;
                instruction_hex = instruction_hex << 4;
                instruction_hex = instruction_hex + op2_hex;
                instruction_hex = instruction_hex << 4;
                instruction_hex = instruction_hex + op3_hex;

                code.push_back(instruction_hex);
                i += 3;
            } else if (instruction == "RSH") {
                for (int n=1; n<3; n++) {
                    if (tokens[i+n].type == TT_INSTRUCTION || tokens[i+n].type == TT_LABEL || tokens[i+n].type == TT_IMMEDIATE || tokens[i+n].type == TT_MEMADDR) {
                        std::cerr << "Invalid instruction Opperands" << '\n';
                        break;
                    }
                }
                std::string op1 = tokens[i+1].value;
                std::string op2 = tokens[i+2].value;

                uint16_t op1_hex = std::stoi(op1, nullptr, 16);
                uint16_t op2_hex = std::stoi(op2, nullptr, 16);
                uint16_t instruction_hex = 0x0006;

                instruction_hex = instruction_hex << 8;
                instruction_hex = instruction_hex + op1_hex;
                instruction_hex = instruction_hex << 4;
                instruction_hex = instruction_hex + op2_hex;

                code.push_back(instruction_hex);
                i += 2;
            } else if (instruction == "LOD") {
                for (int n=1; n<3; n++) {
                    if (tokens[i+n].type == TT_INSTRUCTION || tokens[i+n].type == TT_LABEL || tokens[i+n].type == TT_IMMEDIATE || tokens[i+n].type == TT_MEMADDR) {
                        std::cerr << "Invalid instruction Opperands" << '\n';
                        break;
                    }
                }
                std::string op1 = tokens[i+1].value;
                std::string op2 = tokens[i+2].value;

                uint16_t op1_hex = std::stoi(op1, nullptr, 16);
                uint16_t op2_hex = std::stoi(op2, nullptr, 16);
                uint16_t instruction_hex = 0x0062;
                // print instruction_hex converted to binary
                

                op1_hex = op1_hex << 4;
                instruction_hex = instruction_hex << 8;
                instruction_hex = instruction_hex + op1_hex;
                instruction_hex = instruction_hex + op2_hex;
                code.push_back(instruction_hex);
                i += 2;
            } else if (instruction=="STR") {
                for (int n=1; n<3; n++) {
                    if (tokens[i+n].type == TT_INSTRUCTION || tokens[i+n].type == TT_LABEL || tokens[i+n].type == TT_IMMEDIATE || tokens[i+n].type == TT_MEMADDR) {
                        std::cerr << "Invalid instruction Opperands" << '\n';
                        break;
                    }
                }
                std::string op1 = tokens[i+1].value;
                std::string op2 = tokens[i+2].value;

                uint16_t op1_hex = std::stoi(op1, nullptr, 16);
                uint16_t op2_hex = std::stoi(op2, nullptr, 16);
                uint16_t instruction_hex = 0x0062;

                op1_hex = op1_hex << 4;
                instruction_hex = instruction_hex << 8;
                instruction_hex = instruction_hex + op1_hex;
                instruction_hex = instruction_hex + op2_hex;

                code.push_back(instruction_hex);
                i += 2;
            } else if (instruction=="BGE") {
                std::cout << "THIS INSTRUCTION DOSENT WORK BUT IT IS ENCODED ANYWAY!" << '\n';
                for (int n=1; n<4; n++) {
                    if (tokens[i+n].type == TT_INSTRUCTION || tokens[i+n].type == TT_IMMEDIATE || tokens[i+n].type == TT_MEMADDR) {
                        std::cerr << "Invalid instruction Opperands" << '\n';
                        break;
                    }
                }
                std::string op1 = tokens[i+1].value;
                std::string op2 = tokens[i+2].value;
                std::string op3 = tokens[i+3].value;

                uint16_t op1_hex = std::stoi(op1, nullptr, 16);
                uint16_t op2_hex = std::stoi(op2, nullptr, 16);
                uint16_t op3_hex = std::stoi(op3, nullptr, 16);
                uint16_t instruction_hex = 0x0004;

                instruction_hex = instruction_hex << 4;
                instruction_hex = instruction_hex + op1_hex;
                instruction_hex = instruction_hex << 4;
                instruction_hex = instruction_hex + op2_hex;
                instruction_hex = instruction_hex << 4;
                instruction_hex = instruction_hex + op3_hex;

                code.push_back(instruction_hex);
                i += 3;
            } else if (instruction == "NOR") {
                for(int i=1; i<3; i++) {
                    if (tokens[i+i].type == TT_INSTRUCTION || tokens[i+i].type == TT_LABEL || tokens[i+i].type == TT_IMMEDIATE || tokens[i+i].type == TT_MEMADDR) {
                        std::cerr << "Invalid instruction Opperands" << '\n';
                        break;
                    }
                }
                std::string op1 = tokens[i+1].value;
                std::string op2 = tokens[i+2].value;
                std::string op3 = tokens[i+3].value;

                uint16_t op1_hex = std::stoi(op1, nullptr, 16);
                uint16_t op2_hex = std::stoi(op2, nullptr, 16);
                uint16_t op3_hex = std::stoi(op3, nullptr, 16);
                uint16_t instruction_hex = 0x0003;

                instruction_hex = instruction_hex << 4;
                instruction_hex = instruction_hex + op1_hex;
                instruction_hex = instruction_hex << 4;
                instruction_hex = instruction_hex + op2_hex;
                instruction_hex = instruction_hex << 4;
                instruction_hex = instruction_hex + op3_hex;

                code.push_back(instruction_hex);
                i += 3;
            } else if (instruction == "IMM") {
                std::cout << "IMM has not been implimented yet" << '\n';
                code.push_back(0x0000);
                i+=2;
            } else if (instruction == "JMP") {
                for (int n=1; n<2; n++) {
                    if (tokens[i+n].type == TT_INSTRUCTION || tokens[i+n].type == TT_LABEL || tokens[i+n].type == TT_MEMADDR) {
                        std::cerr << "Invalid instruction Opperands" << '\n';
                        break;
                    }
                }
                std::string op1 = tokens[i+1].value;

                uint16_t op1_hex = std::stoi(op1, nullptr, 16);
                uint16_t instruction_hex = 0x0001;

                instruction_hex = instruction_hex << 4;
                instruction_hex = instruction_hex + op1_hex;

                code.push_back(instruction_hex);
                i += 1;
            }
        }
    }



    return code;
}

