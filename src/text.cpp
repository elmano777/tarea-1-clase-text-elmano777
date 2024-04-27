//
// Created by rudri on 10/11/2020.
//

#include <iostream>
#include "text.h"
#include <cstring>
using namespace std;

Text::Text() : data(nullptr), length(0) {}

Text::Text(const char* str) {
    length = std::strlen(str);
    data = new char[length + 1];
    std::strcpy(data, str);
}

Text::Text(const Text& other) {
    length = other.length;
    data = new char[length + 1];
    std::strcpy(data, other.data);
}

Text::Text(Text&& other) noexcept {
    length = other.length;
    data = other.data;
    other.data = nullptr;
    other.length = 0;
}

Text::~Text() {
    delete[] data;
}

Text& Text::operator=(const Text& other) {
    if (this != &other) {
        delete[] data;
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }
    return *this;
}

Text& Text::operator=(Text&& other) noexcept {
    if (this != &other) {
        delete[] data;
        length = other.length;
        data = other.data;
        other.data = nullptr;
        other.length = 0;
    }
    return *this;
}

Text Text::operator^(const Text& other) const {
    size_t newLength = length + other.length;
    char* newData = new char[newLength + 1];
    std::strcpy(newData, data);
    std::strcat(newData, other.data);
    Text result(newData);
    delete[] newData;
    return result;
}

Text Text::operator^(const char* str) const {
    size_t strLength = std::strlen(str);
    size_t newLength = length + strLength;
    char* newData = new char[newLength + 1];
    std::strcpy(newData, data);
    std::strcat(newData, str);
    Text result(newData);
    delete[] newData;
    return result;
}

Text& Text::operator^=(const Text& other) {
    *this = *this ^ other;
    return *this;
}

Text& Text::operator^=(const char* str) {
    *this = *this ^ str;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Text& text) {
    os << text.data;
    return os;
}

std::istream& operator>>(std::istream& is, Text& text) {
    char buffer[1024];
    is.getline(buffer, 1024);
    text = Text(buffer);
    return is;
}

Text::Text(const std::string& str) {
    length = str.length();
    data = new char[length + 1];
    std::strcpy(data, str.c_str());
}

Text::operator std::string() const {
    return std::string(data);
}

Text& Text::operator=(const std::string& str) {
    delete[] data;
    length = str.length();
    data = new char[length + 1];
    std::strcpy(data, str.c_str());
    return *this;
}

std::istream& getline(std::istream& is, Text& text) {
    std::string line;
    std::getline(is, line);
    text = Text(line.c_str());
    return is;
}
