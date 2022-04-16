#include <unordered_map>

std::unordered_map<std::string, std::string> get_args(char** args, const int& size) {
    std::unordered_map<std::string, std::string> args_map;
    for(int item_itr = 0; item_itr < size; item_itr++) {
       if(args[item_itr][0] == '-') {
            args_map[args[item_itr]] = args[item_itr + 1];
       }
    }

    return args_map;
}
