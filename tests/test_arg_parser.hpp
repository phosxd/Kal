#pragma once

#include "../arg_parser.hpp"

void test_arg_parser() {
    int size, found_size, actual_size;
    std::string found, actual;
    bool found_bool, actual_bool;
    std::vector<std::string> found_args, actual_args;

    size = 5;
    char* args[] = { (char*)"kal", (char*)"-p", (char*)"core.kal", (char*)"-o", (char*)"core_pre.kal" };

    component("Argument Parser");

    title("ArgParser::ArgParser()");
    ArgParser arg = ArgParser(size, args);
    progress();

    title("ArgParser::get_value()");
    actual = "core.kal";
    found = arg.get_value("-p");
    check(found, actual);
    progress();

    title("ArgParser::flag_exists()");
    actual_bool = true;
    found_bool = arg.flag_exists("-p");
    check(found_bool, actual_bool);
    progress();

    title("ArgParser::get_args()");
    size = 4;
    char* args1[] = { (char*)"kal", (char*)"core.kal", (char*)"arg1", (char*)"arg2" };
    arg = ArgParser(size, args1);
    actual_args = { "kal", "core.kal", "arg1", "arg2" };
    found_args = arg.get_args();
    for(uint64_t i = 0; i < actual_args.size(); i++) {
        check(found_args[i], actual_args[i]);
    }
    progress();

    title("ArgParser::args_size()");
    actual_size = 4;
    found_size = arg.args_size();
    check(found_size, actual_size);
    progress();
}