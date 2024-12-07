#pragma once

#include "../exec.hpp"
#include "../lexer.hpp"

void test_control_flow() {
    std::string actual_string, found_string;
    std::vector<std::string> lines;
    std::vector<Token> tokens;

    component("Control Flow");

    title("line_exec() - if");

    lines = {
        "var value = 0",
        "if $value == 0 {",
            "$value = 1",
        "}"
    };
    tokens = lexer::tokenize(lines);
    line_exec(tokens);
    actual_string = "1";
    found_string = VarTable::print("$value");
    check(found_string, actual_string);

    lines = {
        "if $value == 1 && 1 + 1 == 2 {",
            "$value = 2",
        "}"
    };
    tokens = lexer::tokenize(lines);
    line_exec(tokens);
    actual_string = "2";
    found_string = VarTable::print("$value");
    check(found_string, actual_string);

    lines = {
        "if $value == 2 || 2 + 2 == 5 {",
            "$value = 3",
        "}"
    };
    tokens = lexer::tokenize(lines);
    line_exec(tokens);
    actual_string = "3";
    found_string = VarTable::print("$value");
    check(found_string, actual_string);

    lines = {
        "$value = 0",
        "if $value == 1 {",
            "$value = 1",
        "}"
    };
    tokens = lexer::tokenize(lines);
    line_exec(tokens);
    actual_string = "0";
    found_string = VarTable::print("$value");
    check(found_string, actual_string);

    progress();
}