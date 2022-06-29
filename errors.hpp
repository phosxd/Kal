#pragma once

#include "style.hpp"

namespace errors {
    void kal_error(std::string kal_err) {
        std::cout << style::red << style::bold << "Kal:" << style::reset << style::red << " " << kal_err << style::reset << std::endl;
    }

    void stdout_error(std::string second_parameter) {
        std::cout << style::red << style::bold << "stdout:" << style::reset << style::red << " stdout takes only one parameter but multiple parameters were passed: " << second_parameter << "..." << style::reset << std::endl;
    }
}
