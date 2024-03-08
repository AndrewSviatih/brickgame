#include "brickgame/tetris/s21_bricks_logic.h"

typedef struct {
    int a;
    int b;
} test;

int main() {
    test testing;

    testing.a = 1;
    testing.b = 2;

    int res = testing.a + testing.b;

    printf("%d\n", res);
}