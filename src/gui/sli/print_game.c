#include "gui.h"

void print_game(GameInfo_t *game_info) {

  printw("\n");
  printw("Best Score: %d\n", game_info->score);
  printw("Score: %d\n", game_info->high_score);
  printw("Level: %d\n", game_info->level);
  printw("Speed: %d\n", game_info->speed);
  printw("\n");

  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      printw("%c", game_info->field[i][j]);
    }
    printw("\n");
  }
}

