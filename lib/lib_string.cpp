#include <fstream>
#include <sstream>

namespace lib {
    bool ends_with(const std::string& major_string, const std::string& minor_string) {
        int major_string_size = major_string.size();
        int minor_string_size = minor_string.size();

        if(major_string_size < minor_string_size) {
            return false;
        }

        int diff_size = major_string_size - minor_string_size;
        return major_string.substr(diff_size, major_string_size - 1) == minor_string;
    }

    std::string read_file(std::string file_path) {
        std::ifstream source_file(file_path);
        std::stringstream file_contents;
        file_contents << source_file.rdbuf();
        source_file.close();
        return file_contents.str();
    }
}
