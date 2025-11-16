#pragma once

#include <string>
#include <stack>
#include <utility>
#include <unordered_map>

#include "types.hpp"

using Memory = std::unordered_map<std::string, Value*>;

int depth = 0;
Memory memory;

enum Type {
    VAR,
    INERT
};

namespace VarTable {
    std::string print(std::string, Memory& memory = memory);
    Value* get(std::string, std::vector<std::string> = {}, bool = false, bool = false, bool = true, Memory& = memory);
    void set(std::string var, std::string data, Value* data_ptr = nullptr, Type type = VAR, bool disallow_copy = false, int depth = 0, bool allow_shadowing = false, Memory& memory = memory);
}