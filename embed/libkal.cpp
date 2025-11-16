#include <iostream>
#include <vector>
#include <unordered_map>

#include "../config.hpp"
#include "../var.hpp"
#include "../exec.hpp"
#include "../preprocessor.hpp"
#include "../expr_parser.hpp"

#include "kal.hpp"

Value* Kal::exec(std::string code) {
    std::vector<std::string> lines = preproc::preprocess(code);
    std::vector<Token> tokens = lexer::tokenize(lines);
    Value* ret_val = line_exec(tokens, false, false, true, k_memory);
    return ret_val;
}

Kal::~Kal() {
    VarTable::gc(0, k_memory);
}