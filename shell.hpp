#pragma once

#include <iostream>

#include "parser.hpp"
#include "preprocessor.hpp"
#include "lib/lib_style.hpp"

namespace shell {
    void init_shell() {
        int count = 1;
        VarTable var = VarTable();
        std::string init_file_path = "";

        while(true) {
            std::string command;
            std::cout << style::bold << "\nKal" << style::reset << " " << style::bold << style::green << "[" << count << "]:" << style::reset << " ";
            std::getline(std::cin, command);
            command = preproc::remove_comments(command);
            command = lib::trim_leading(command);
            command = lib::trim_trailing(command);

            if(command[0] == '@') {
                std::string file_name = command.substr(1);
                std::vector<std::string> source_lines = preproc::initial_preprocessing(file_name);
                preproc::preprocess(source_lines, init_file_path);
                std::vector<std::vector<std::string>> tokens = lexer::tokenize(source_lines);
                line_exec(tokens, var);
            }

            if(command == "") {
                continue;
            }

            std::vector<std::string> line_tokens = lib::split(command, ' ');
            if(line_tokens[0] == "var" || line_tokens[0] == "const") {
                line_tokens = lib::split(command, ' ', '"', true);
            }
            std::vector<std::vector<std::string>> tokens = { line_tokens };
            line_exec(tokens, var);

            count++;
        }
    }
}
