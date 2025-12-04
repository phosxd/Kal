#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>

class Value;
struct Token;

using Memory = std::unordered_map<std::string, Value*>;
using Table = std::unordered_map<std::string, std::string>;

class Result {
    private:
    public:
        double* number = nullptr;
        std::string* string = nullptr;
        std::vector<std::string>* list = nullptr;
        std::unordered_map<std::string, std::string>* dict = nullptr;

        Result();
        Result(std::string);
        Result(const Result&);
        ~Result();

        Result operator[](int);
        Result operator[](std::string);
        Result operator=(const Result&);

        double to_number();
        std::string to_string();
        std::vector<Result> to_list();
        std::unordered_map<std::string, Result> to_dict();

};

std::ostream& operator<<(std::ostream&, Result);

class Kal {
    private:
        Memory k_memory;

    public:
        std::string exec(std::string, Table = {});
        ~Kal();
};