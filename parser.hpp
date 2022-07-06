#pragma once

#include "lexer.hpp"
#include "errors.hpp"
#include "variable.hpp"
#include "lib/lib_string.hpp"

namespace parser {
    void std_out(std::string out_text) {
        std::cout << lib::render_escape_chars(out_text);
    }

    void std_err(std::string err_text) {
        std::cerr << lib::render_escape_chars(err_text);
    }
}

int line_exec(const std::vector<std::vector<std::string>>& tokens, VarTable& var) {
    int tokens_list = tokens.size();

    for(int line = 0; line < tokens_list; line++) {
        std::vector<std::string> cmd = tokens[line];
        int cmd_size = cmd.size();

        if(cmd[0][0] == '#' && cmd[0][1] == '!') {
            continue;
        }

        else if(cmd[0] == "stdout") {
            if(cmd_size == 1) {
                std::cout << "";
            }
            else if(cmd_size == 2) {
                parser::std_out(cmd[1]);
            }
            else {
                errors::stdout_error(cmd[2]);
                return 1;
            }
        }

        else if(cmd[0] == "stderr" && cmd_size == 2) {
            parser::std_err(cmd[1]);
        }

        else if(cmd[0] == "var") {
            std::vector<std::string> var_data = lexer::lex_variable_declaration(cmd);
            var.var_add(var_data[0], var_data[1], var_data[2]);
        }
    }

    return 0;
}
