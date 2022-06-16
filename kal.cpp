#include <iostream>
#include "errors.hpp"
#include "arg_parser.hpp"
#include "preprocessor.hpp"
#include "lib/lib_string.hpp"

int main(int argc, char** argv) {
    if(argc == 1) {
        errors::kal_error("No arguments passed.");
        return 1;
    }
    std::vector<std::string> args = get_args(argv, argc);
    if(args.size() == 0) {
        errors::kal_error("Invalid argument passed.");
        return 1;
    }
    std::unordered_map<std::string, std::string> flags = get_flags(argv, argc);
    
    std::string& file_name = args[0];

    std::vector<std::string> source_lines = preproc::initial_preprocessing(file_name);
    preproc::preprocess(source_lines);

    for(std::string line : source_lines) {
        std::cout << "[" << line << "]" << std::endl;
    }

    return 0;
}
