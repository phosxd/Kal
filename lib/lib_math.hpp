#pragma once

namespace lib {
    std::string trim_num(std::string num) {
        size_t radix = num.find(".");
        if(radix == std::string::npos) {
            return num;
        }

        int pos = num.size();
        while(num[pos - 1] == '0') {
            pos--;
        }

        if(num[pos - 1] == '.') {
            pos--;
        }

        return num.substr(0, pos);
    }
}
