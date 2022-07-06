#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

class VarTable {
    private:
        std::unordered_map<std::string, bool> booleans;
        std::unordered_map<std::string, double> numbers;
        std::unordered_map<std::string, std::string> strings;

    public:
        void add(std::string var_type, std::string var_name, std::string var_value) {
            if(var_type == "str") {
                strings[var_name] = var_value;
            }

            else if(var_type == "num") {
                double casted_var_value = std::stod(var_value);
                numbers[var_name] = casted_var_value;
            }

            else if(var_type == "bool") {
                bool boolean_value;
                if(var_value == "true") {
                    boolean_value = true;
                }
                if(var_value == "false") {
                    boolean_value = false;
                }
                booleans[var_name] = boolean_value;
            }
        }
};
