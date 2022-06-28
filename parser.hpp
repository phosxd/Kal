#pragma once

#include "lexer.hpp"
#include "lib/lib_string.hpp"

namespace parser {
    void std_out(std::string arg) {
        std::cout << lib::render_escape_chars(arg);
    }
}

void line_exec(const std::vector<std::vector<std::string>>& tokens) {
    int tokens_list = tokens.size();

    for(int line = 0; line < tokens_list; line++) {
        std::vector<std::string> cmd = tokens[line];
        int cmd_size = cmd.size();

        if((cmd[0] == "stdout") && cmd_size == 2) {
            parser::std_out(cmd[1]);
        }
    }
}
