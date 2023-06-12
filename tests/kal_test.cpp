#include <iostream>
#include <vector>

#include "lib_kal_test.hpp"
#include "test_parser.hpp"
#include "test_lexer.hpp"

int main() {
    test_lexer();
    test_parser();

    exit_successfully();
    return 0;
}