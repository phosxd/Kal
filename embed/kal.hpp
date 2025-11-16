#pragma once

#include <iostream>
#include <unordered_map>

class Value;
struct Token;

using Memory = std::unordered_map<std::string, Value*>;

namespace VarTable {
    std::string print(std::string);
}

class Kal {
    private:
        Memory k_memory;

    public:
        Value* exec(std::string);
        ~Kal();
};