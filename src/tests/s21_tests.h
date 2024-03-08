#ifndef SRC_TESTS_INCLUDES_S21_TESTS_H_
#define SRC_TESTS_INCLUDES_S21_TESTS_H_

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFF_SIZE 1000

#include "../brickgame/tetris/bricks_logic.h"

void run_tests(void);
void run_testcase(Suite *testcase, int counter_testcase);

#endif  // SRC_TESTS_INCLUDES_S21_TESTS_H_