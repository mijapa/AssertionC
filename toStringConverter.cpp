//
// Created by micha on 06.05.19.
//

#include "toStringConverter.h"
#include <iostream>
#include <sstream>
#include <string>

template<class T>
std::string valueToString(T value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}
