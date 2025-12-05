#pragma once

#include <string>
#include <stack>
#include <utility>
#include <unordered_map>

class Value;
using Memory = std::unordered_map<std::string, Value*>;
Memory memory;

#include "types.hpp"

int depth = 0;

enum Type {
    VAR,
    INERT
};

namespace VarTable {
    std::string print(std::string, Memory& memory);
    // {}, false, false, true
    Value* get(std::string, std::vector<std::string>, bool, bool, bool, Memory&);
    // nullptr, VAR, false, 0, false
    void set(std::string var, std::string data, Value* data_ptr, Type type , bool disallow_copy, int depth, bool allow_shadowing, Memory& memory);
}