#pragma once

#include <iostream>
#include <unordered_map>

template <typename TYPE>
class Variable {
    private:
        std::string var_name;
        TYPE var_val;

    public:
        Variable(std::string name, TYPE value) {
            var_name = name;
            var_val = value;
        }

        std::string get_name() {
            return var_name;
        }

        TYPE get_val() {
            return var_val;
        }

        void reassign(TYPE new_val) {
            var_val = new_val;
        }
};
