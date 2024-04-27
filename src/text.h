//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT1_TEXT_V2023_1_TEXT_H
#define PROG3_UNIT1_TEXT_V2023_1_TEXT_H

#include <iostream>
#include <cstring>
#include <string>

class Text {
private:
    char* data;
    size_t length;


public:
    Text();
    Text(const char* str);
    Text(const Text& other);
    Text(Text&& other) noexcept;
    ~Text();

    Text& operator=(const Text& other);
    Text& operator=(Text&& other) noexcept;
    Text operator^(const Text& other) const;
    Text operator^(const char* str) const;
    Text& operator^=(const Text& other);
    Text& operator^=(const char* str);

    friend std::ostream& operator<<(std::ostream& os, const Text& text);
    friend std::istream& operator>>(std::istream& is, Text& text);

    Text(const std::string& str);
    operator std::string() const;
    Text& operator=(const std::string& str);

    friend std::istream& getline(std::istream& is, Text& text);
};

#endif //PROG3_UNIT1_TEXT_V2023_1_TEXT_H
