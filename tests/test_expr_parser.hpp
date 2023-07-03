#pragma once

#include "../expr_parser.hpp"

void test_expr_parser() {
    std::string expr, found, actual;

    component("Expression Parser");

    title("eval()");
    expr = "1 + 2 * 3";
    actual = "7.000000";
    found = eval(expr);
    check(found, actual);

    expr = "(1 + 2) * 3";
    actual = "9.000000";
    found = eval(expr);
    check(found, actual);

    expr = "1 == (0 + 1)";
    actual = "1";
    found = eval(expr);
    check(found, actual);

    expr = "\"hello\" == \"hello\"";
    actual = "1";
    found = eval(expr);
    check(found, actual);

    expr = "\"hello\" != \"hello\"";
    actual = "0";
    found = eval(expr);
    check(found, actual);

    expr = "\"hello\" == \"hey\"";
    actual = "0";
    found = eval(expr);
    check(found, actual);

    expr = "\"hello\" != \"hey\"";
    actual = "1";
    found = eval(expr);
    check(found, actual);

    expr = "\"a\" + \"b\"";
    actual = "\"ab\"";
    found = eval(expr);
    check(found, actual);

    expr = "\"a\" * 3";
    actual = "\"aaa\"";
    found = eval(expr);
    check(found, actual);

    expr = "\"a\" + \"b\" * 3";
    actual = "\"abbb\"";
    found = eval(expr);
    check(found, actual);

    expr = "\"a\" + \"b\" * 3 == \"abbb\"";
    actual = "1";
    found = eval(expr);
    check(found, actual);

    expr = "(\"a\" + \"b\") * 3";
    actual = "\"ababab\"";
    found = eval(expr);
    check(found, actual);

    expr = "(\"a\" + \"b\") * 3 == \"ababab\"";
    actual = "1";
    found = eval(expr);
    check(found, actual);

    expr = "(\"a\" + \"b\") * (1 + 2) == \"ababab\"";
    actual = "1";
    found = eval(expr);
    check(found, actual);

    expr = "\"hell\" + \"o\" == \"hel\" + \"lo\"";
    actual = "1";
    found = eval(expr);
    check(found, actual);

    expr = "\"a\" * 1 + \"b\" * 2 + \"c\" * 3";
    actual = "\"abbccc\"";
    found = eval(expr);
    check(found, actual);

    expr = "\"a\" * 1 + \"b\" * 2 + \"c\" * 3 == \"abbccc\"";
    actual = "1";
    found = eval(expr);
    check(found, actual);

    progress();
}