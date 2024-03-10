#include "bricks_logic.h"

int allocate_memory_fields(GameInfo_t *game_info) {
  int allocate_error = 0;

  game_info->field = (int **)malloc(ROWS * sizeof(int *));
  if (game_info->field != NULL) {
    for (int i = 0; i < ROWS; i++) {
      game_info->field[i] = (int *)malloc(COLS * sizeof(int));
      if (game_info->field[i] == NULL) {
        for (int j = 0; j < i; j++) {
          free(game_info->field[j]);
        }
        free(game_info->field);
        game_info->field = NULL;

        allocate_error = 1;
        break;
      }
    }
  } else {
    allocate_error = 1;
  }

  if (!allocate_error) {
    game_info->next = (int **)malloc(ROWS * sizeof(int *));
    if (game_info->next != NULL) {
      for (int i = 0; i < ROWS; i++) {
        game_info->next[i] = (int *)malloc(COLS * sizeof(int));
        if (game_info->next[i] == NULL) {
          for (int j = 0; j < i; j++) {
            free(game_info->next[j]);
          }
          free(game_info->next);
          game_info->next = NULL;

          allocate_error = 1;
          break;
        }
      }
    } else {
      allocate_error = 1;
    }
  }

  return allocate_error;
}

void free_fields(GameInfo_t *game_info) {
  if (game_info != NULL) {
    for (int i = 0; i < ROWS; i++) {
      free(game_info->field[i]);
      free(game_info->next[i]);
    }
    free(game_info->field);
    free(game_info->next);
  }
}
