#pragma once

#include "style.hpp"

namespace errors {
    void kal_error(std::string kal_err) {
        std::cout << style::red << style::bold << "Kal:" << style::reset << style::red << " " << kal_err << style::reset << std::endl;
    }
}
