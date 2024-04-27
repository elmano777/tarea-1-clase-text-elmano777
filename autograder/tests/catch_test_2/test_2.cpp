//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "Tarea_1.h"
using namespace std;

static void question_2() {
    Text text_1;
    std::cin >> text_1;
    std::cout << text_1 << std::endl;
}

TEST_CASE("Question #2") {
    execute_test("test_2.in", question_2);
}