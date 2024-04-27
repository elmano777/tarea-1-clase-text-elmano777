//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "Tarea_1.h"
#include <iostream>
#include <string>
using namespace std;

static void question_4() {
    Text text_1;
    Text text_2;

    getline(std::cin, text_1);
    getline(std::cin, text_2);

    std::swap(text_1, text_2);

    std::cout << text_1 << endl;
    std::cout << text_2 << endl;
}

TEST_CASE("Question #4") {
    execute_test("test_4.in", question_4);
}