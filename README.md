# Task #0: Text
**course:** Programación III  
**unit:** 1  
**cmake project:** prog3_unit1_text_v2023_1
## Instructions
Subir a gradescope los siguientes archivos:

## Question #1 - (20 points)
Desarrolla la clase `Text` que implemente características similares a la clase std::string.

- Esta clase debera contar con un constructor que tomo como argumento un parámetro del tipo `const char*` que represente el contenido inicial y que  almacene en la memoria dinámica una copia de este texto.
- Debera tener implementado el `copy constructor` que permita realizar de forma segura la copia de un objeto `Text` a otro objeto `Text`.
- La clase debera contar también con el `move constructor` que permita intercambiar el contenido entre dos objetos del tipo `Text`.
- Debera implementarse correctamente el `destructor` de modo que memoria dinámica que almacena el texto sea liberada.
- La clase debera contar con la sobre escritura de los operadores `copy asignment` y `move assignment`. complementos de los constructores `copy/move`.
- La clase debera también sobrecargar el operador `^` que se utilizara para realizar la concatenación entre dos objetos del tipo `Text` o entre un objeto `Text` y un texto almacenado en en un `rvalue` o `lvalue` del tipo `const char*`. También considerar la sobrecarga del operador `^=`.
- Debera de sobrecargarse el operador ostream (`<<`) y el operador istream (`>>`)
- Elaborar el constructor por parámetros del tipo `std::string`, la sobrecarga del operador conversion `string` y el operador `=` de modo que se pueda asignar el contenido de un objeto del tipo `Text` a un objeto del tipo `std:string` y viceversa.

**Use Case #1:** Crear un objeto `Text` e imprimirlo
```cpp
Text text_1 = "Hola Mundo";
std::cout << text_1 << std::endl;
```

**Use Case #2:** Crear un objeto `Text` leer del teclado e imprimirlo
```cpp
Text text_1;
std::cin >> text_1;
std::cout << text_1 << std::endl;
```

**Use Case #3:** Crear cuatro objetos `Text`, leer el contenido de dos del teclado, concatenarlos y asignarlos al tercer objeto, al cuarto asignarle el valor del primero y agregarle al final el texto: "/CUARTO"
```cpp
Text text_1;
Text text_2;
Text text_3;
Text text_4;

getline(cin, text_1);
getline(cin, text_2);

text_3 = text_1 ^ text_2;
text_4 = text_1;
text_4 ^= "/CUARTO";

std::cout << "Texto 1: " << text_1 << std::endl;
std::cout << "Texto 2: " << text_2 << std::endl;
std::cout << "Texto 3: " << text_3 << std::endl;
std::cout << "Texto 4: " << text_4 << std::endl;
```

**Use Case #4:** Crear dos objetos `Text`, leer el contenido desde el teclado y realizar un intercambio de valores utilizando el algoritmo `std::swap()`.
```cpp
Text text_1;
Text text_2;

getline(std::cin, text_1);
getline(std::cin, text_2);

std::swap(text_1, text_2);

std::cout << text_1 << endl;
std::cout << text_2 << endl;
```

**Use Case #5:** Crear cuatro objetos: dos del tipo `Text` y dos del tipo `std::string`, leer el contenido desde el teclado de uno del tipo `Text` y otro del tipo `std::string`, copiar el contenido del primer objeto `Text` dentro del segundo objeto `std::string` y realizar de forma similar copiar el contenido del primer objeto `std::string` dentro del segundo objeto del tipo `Text`
```cpp
    Text text_1;
std::string text_2;
Text text_3;
std::string text_4;
Text text_5 = string("Hola std::string");   // Constructor x parámetro std::string

getline(std::cin, text_1);
getline(std::cin, text_2);
text_4 = text_1;                            // Sobrecarga al operador conversión
text_3 = text_2;                            // Sobrecarga al operador =

std::cout << text_1 << endl;
std::cout << text_2 << endl;
std::cout << text_3 << endl;
std::cout << text_4 << endl;
std::cout << text_5 << endl;
```