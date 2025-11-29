#pragma once

#include <iostream>
#include <unordered_map>

class Value;
struct Token;

using Memory = std::unordered_map<std::string, Value*>;
using Table = std::unordered_map<std::string, std::string>;

class Kal {
    private:
        Memory k_memory;

    public:
        std::string exec(std::string, Table = {});
        double number(std::string);
        std::string string(std::string);
        std::string list(std::string, int);
        std::string dict(std::string, std::string);
        ~Kal();
};