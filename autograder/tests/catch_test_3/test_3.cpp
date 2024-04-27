//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "Tarea_1.h"
#include <iostream>
#include <string>
using namespace std;

static void question_3() {
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
}

TEST_CASE("Question #3") {
    execute_test("test_3.in", question_3);
}