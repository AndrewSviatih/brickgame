#include "brickgame/tetris/bricks_logic.h"

int main() {

  UserAction_t user_action = Start;

  input_keyboard(&user_action);

  printf("%c\n", user_action);
}