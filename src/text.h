#ifndef PROG3_UNIT1_TEXT_V2023_1_TEXT_H
#define PROG3_UNIT1_TEXT_V2023_1_TEXT_H

#include <iostream>
#include <string>

class Text {
private:
    char* datos;
    size_t longitud;

public:
    Text();
    Text(const char* cad);
    Text(const Text& otro);
    Text(Text&& otro) noexcept;
    ~Text();

    Text& operator=(const Text& otro);
    Text& operator=(Text&& otro) noexcept;
    Text operator^(const Text& otro) const;
    Text operator^(const char* cad) const;
    Text& operator^=(const Text& otro);
    Text& operator^=(const char* cad);

    friend std::ostream& operator<<(std::ostream& os, const Text& texto);
    friend std::istream& operator>>(std::istream& is, Text& texto);

    Text(const std::string& cad);
    operator std::string() const;
    Text& operator=(const std::string& cad);

    friend std::istream& getline(std::istream& is, Text& texto);
};

#endif //PROG3_UNIT1_TEXT_V2023_1_TEXT_H
