#include <vector>
#include <unordered_map>
#include "../lib/lib_string.cpp"

std::unordered_map<std::string, std::string> get_flags(char** args, const int& size) {
    std::unordered_map<std::string, std::string> flags_map;
    for(int item_itr = 0; item_itr < size; item_itr++) {
       if(args[item_itr][0] == '-') {
            flags_map[args[item_itr]] = args[item_itr + 1];
       }
    }

    return flags_map;
}

std::vector<std::string> get_args(char** args, const int& size) {
    bool get_next = false;
    std::vector<std::string> prog_args;

    for(int arg_itr = 0; arg_itr < size; arg_itr++) {
        std::string file_extension = ".kal";
        std::string arg_str = std::string(args[arg_itr]);

        if(lib::ends_with(arg_str, file_extension)) {
            get_next = true;
        }

        if(get_next) {
            prog_args.push_back(arg_str);
        }
    }

    return prog_args;
}
