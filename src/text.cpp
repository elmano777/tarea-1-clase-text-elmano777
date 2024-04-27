//
// Created by rudri on 10/11/2020.
//

#include <iostream>
#include "text.h"
#include <cstring>
using namespace std;

Text::Text() : datos(nullptr), longitud(0) {}

Text::Text(const char* cad) {
    longitud = std::strlen(cad);
    datos = new char[longitud + 1];
    std::strcpy(datos, cad);
}

Text::Text(const Text& otro) {
    longitud = otro.longitud;
    datos = new char[longitud + 1];
    std::strcpy(datos, otro.datos);
}

Text::Text(Text&& otro) noexcept {
    longitud = otro.longitud;
    datos = otro.datos;
    otro.datos = nullptr;
    otro.longitud = 0;
}

Text::~Text() {
    delete[] datos;
}

Text& Text::operator=(const Text& otro) {
    if (this != &otro) {
        delete[] datos;
        longitud = otro.longitud;
        datos = new char[longitud + 1];
        std::strcpy(datos, otro.datos);
    }
    return *this;
}

Text& Text::operator=(Text&& otro) noexcept {
    if (this != &otro) {
        delete[] datos;
        longitud = otro.longitud;
        datos = otro.datos;
        otro.datos = nullptr;
        otro.longitud = 0;
    }
    return *this;
}

Text Text::operator^(const Text& otro) const {
    size_t nuevaLongitud = longitud + otro.longitud;
    char* nuevaDatos = new char[nuevaLongitud + 1];
    std::strcpy(nuevaDatos, datos);
    std::strcat(nuevaDatos, otro.datos);
    Text resultado(nuevaDatos);
    delete[] nuevaDatos;
    return resultado;
}

Text Text::operator^(const char* cad) const {
    size_t longitudCad = std::strlen(cad);
    size_t nuevaLongitud = longitud + longitudCad;
    char* nuevaDatos = new char[nuevaLongitud + 1];
    std::strcpy(nuevaDatos, datos);
    std::strcat(nuevaDatos, cad);
    Text resultado(nuevaDatos);
    delete[] nuevaDatos;
    return resultado;
}

Text& Text::operator^=(const Text& otro) {
    *this = *this ^ otro;
    return *this;
}

Text& Text::operator^=(const char* cad) {
    *this = *this ^ cad;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Text& texto) {
    os << texto.datos;
    return os;
}

std::istream& operator>>(std::istream& is, Text& texto) {
    char buffer[1024];
    is.getline(buffer, 1024);
    texto = Text(buffer);
    return is;
}

Text::Text(const std::string& cad) {
    longitud = cad.length();
    datos = new char[longitud + 1];
    std::strcpy(datos, cad.c_str());
}

Text::operator std::string() const {
    return std::string(datos);
}

Text& Text::operator=(const std::string& cad) {
    delete[] datos;
    longitud = cad.length();
    datos = new char[longitud + 1];
    std::strcpy(datos, cad.c_str());
    return *this;
}

std::istream& getline(std::istream& is, Text& texto) {
    std::string linea;
    std::getline(is, linea);
    texto = Text(linea.c_str());
    return is;
}