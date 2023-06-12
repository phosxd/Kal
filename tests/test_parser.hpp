#pragma once

#include "../parser.hpp"

void test_parser() {
    int index;
    std::string text, actual, found;

    component("Parser");

    title("parser::parse_number()");
    index = 3;
    text = "abc3.14xyz";
    actual = "3.14";
    found = parser::parse_number(text, index);
    check(found, actual);
    progress();
}