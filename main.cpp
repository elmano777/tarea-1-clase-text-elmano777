#include <iostream>
#include <string>
#include "Tarea_1.h"
using namespace std;

int main() {
    Text texto_1 = "Hola";
    cout << texto_1 << endl;
    Text texto_2;
    cin >> texto_2;
    cout << texto_2 << endl;
    cin.ignore(); // <--- COLOCAR antes de un getline
    Text texto_3;
    getline(cin, texto_3);
    cout << texto_3 << endl;

    string texto_4 = "Hola UTEC";
    Text texto_5;
    texto_5 = texto_4;
    cout << texto_5 << endl;

    Text texto_6  = "Hola Mundo!!";
    string texto_7;
    texto_7 = texto_6;
    cout << texto_7 << endl;

    Text texto_8 = string("Hola std::string");
    cout << texto_8 << endl;

    return 0;
}
