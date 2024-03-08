#include "bricks_logic.h"

void input_keyboard(UserAction_t *input_key) {
  int ch;

  while (*input_key != Terminate) {
    ch = getchar();
    switch (ch) {
      case 'q':
        *input_key = Terminate;
        break;
      case KEY_LEFT:
        *input_key = Left;
        break;
      case KEY_RIGHT:
        *input_key = Right;
        break;
      case KEY_UP:
        *input_key = Up;
        break;
      case KEY_DOWN:
        *input_key = Down;
        break;
      case 's':
        *input_key = Start;
        break;
      case 'p':
        *input_key = Pause;
        break;
      default:
        break;
    }
  }

}