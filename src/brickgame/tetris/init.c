#include "bricks_logic.h"

void init_game_field(GameInfo_t *game_info) {

  for(int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      game_info->field[i][j] = ' ';
    }
  }

  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      if(i == 0 || i == ROWS - 1) {
        game_info->field[i][j] = 'X';
      }
      if(j == 0 || j == COLS - 1) {
        game_info->field[i][j] = 'X';
      }
    }
  }

  game_info->score = 0;
  game_info->high_score = 0;
  game_info->level = 0;
  game_info->speed = 0;
}
