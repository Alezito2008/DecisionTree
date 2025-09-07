//
// Created by alezito on 9/5/25.
//

#pragma once

#include <vector>
#include <iostream>

using Serial = std::vector<float>;

inline std::ostream& operator<<(std::ostream& os, const Serial& serial) {
    os << '[';
    for (size_t i = 0; i < serial.size(); ++i) {
        os << serial[i];
        if ((i + 1) != serial.size()) os << ", ";
    }
    os << ']';
    return os;
}

using Table = std::vector<Serial>;
