#ifndef STRING_S21_BRICKS_GAME_H
#define STRING_S21_BRICKS_GAME_H

#include "ncurses.h"
#include "stdio.h"
#include "stdlib.h"

typedef enum {
  Start,
  Pause,
  Terminate,
  Left,
  Right,
  Up,
  Down,
  Action
} UserAction_t;

typedef struct {
  int **field;
  int **next;
  int score;
  int high_score;
  int level;
  int speed;
  int pause;
} GameInfo_t;

void userInput(UserAction_t action, bool hold);

GameInfo_t updateCurrentState();

#endif // STRING_S21_BRICKS_GAME_H

void input_keyboard(UserAction_t *input_key);