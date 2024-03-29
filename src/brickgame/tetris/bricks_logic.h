#ifndef STRING_S21_BRICKS_GAME_H
#define STRING_S21_BRICKS_GAME_H

#include "ncurses.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

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


#define ROWS 21
#define COLS 11

#define GAME_COLS 10

#endif // STRING_S21_BRICKS_GAME_H

// inits
void init_game_field(GameInfo_t *game_info);

// memory funcs
int allocate_memory_fields(GameInfo_t *game_info);
void free_fields(GameInfo_t *game_info);

// print funcs
void print_game(GameInfo_t *game_info);