#include <iostream>
#include "variable.hpp"

int main() {
    VarTable var = VarTable();
    var.add("str", "name", "Shreyas");
    var.add("num", "age", "18");
    var.add("bool", "is_good", "true");
    return 0;
}
