#include <iostream>
#include <vector>

#include "lib_kal_test.hpp"
#include "test_arg_parser.hpp"
#include "test_lexer.hpp"
#include "test_preprocessor.hpp"
#include "test_parser.hpp"

int main() {
    test_arg_parser();
    test_preprocessor();
    test_lexer();
    test_parser();

    exit_successfully();
    return 0;
}