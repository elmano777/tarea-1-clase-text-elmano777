//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "Tarea_1.h"
using namespace std;

static void question_1() {
    Text text_1 = "Hola Mundo";
    std::cout << text_1 << std::endl;
}

TEST_CASE("Question #1") {
    execute_test("test_1.in", question_1);
}