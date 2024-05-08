#include "../../../gui/sli/gui.h"
#include "../bricks_logic.h"
/**
 * @brief Allocates memory for the game information including the game field and
 * figures.
 *
 * This function allocates memory for the game field and figures of the game.
 *
 * @param game_info Pointer to the GameInfoExtended_t structure where the memory
 * will be allocated.
 *
 * @return Returns 0 if memory allocation is successful, otherwise returns 1.
 */
int alloc_game_info(GameInfoExtended_t *game_info) {
  int alloc_error = 0;

  alloc_error = allocate_memory_fields(game_info);
  if (!alloc_error) {
    alloc_error = allocate_memory_figure(game_info);
    if (alloc_error) {
      free_fields(game_info);
      alloc_error = 1;
    }
  } else {
    alloc_error = 1;
  }

  return alloc_error;
}

/**
 * @brief Allocates memory for the game field and next field of the game.
 *
 * This function allocates memory for the game field and next field of the game
 * based on the dimensions specified by GAME_FIELD_Y_ALLOC and
 * GAME_FIELD_X_ALLOC.
 *
 * @param game_info Pointer to the GameInfoExtended_t structure where the memory
 * will be allocated.
 *
 * @return Returns 0 if memory allocation is successful, otherwise returns 1.
 */

int allocate_memory_fields(GameInfoExtended_t *game_info) {
  int allocate_error = 0;

  game_info->next = (int **)malloc(GAME_FIELD_Y_ALLOC * sizeof(int *));
  game_info->field = (int **)malloc(GAME_FIELD_Y_ALLOC * sizeof(int *));
  if (game_info->next != NULL && game_info->field != NULL) {
    for (int i = 0; i < GAME_FIELD_Y_ALLOC; i++) {
      game_info->field[i] = (int *)malloc(GAME_FIELD_X_ALLOC * sizeof(int));
      game_info->next[i] = (int *)malloc(GAME_FIELD_X_ALLOC * sizeof(int));
      if (game_info->next[i] == NULL || game_info->field[i] == NULL) {
        allocate_error = 1;
        for (int j = 0; j <= i; j++) {
          if (game_info->field[j] != NULL) {
            free(game_info->field[j]);
          }
          if (game_info->next[j] != NULL) {
            free(game_info->next[j]);
          }
        }
        free(game_info->next);
        free(game_info->field);
        game_info->next = NULL;
        game_info->field = NULL;
        break;
      }
    }
  } else {
    allocate_error = 1;
  }

  return allocate_error;
}
/**
 * @brief Frees the memory allocated for the game information including the game
 * field and figures.
 *
 * This function frees the memory allocated for the game field and figures of
 * the game.
 *
 * @param game_info Pointer to the GameInfoExtended_t structure whose memory
 * will be freed.
 */
void free_game_info(GameInfoExtended_t *game_info) {
  free_fields(game_info);  // Free the memory allocated for the game field and
                           // next field
  free_figure(game_info);  // Free the memory allocated for the game figures
  game_info = NULL;  // Set the pointer to NULL (Note: This assignment has no
                     // effect outside the function scope)
}

/**
 * @brief Frees the memory allocated for the game field and next field of the
 * game.
 *
 * This function frees the memory allocated for the game field and next field of
 * the game.
 *
 * @param game_info Pointer to the GameInfoExtended_t structure containing the
 * game field and next field.
 */

void free_fields(GameInfoExtended_t *game_info) {
  if (game_info != NULL && game_info->field != NULL) {
    for (int i = 0; i < GAME_FIELD_Y_ALLOC; i++) {
      free(game_info->field[i]);  // Free memory for each row of the game field
      free(game_info->next[i]);   // Free memory for each row of the next field
    }
    free(game_info->field);  // Free memory for the game field
    free(game_info->next);   // Free memory for the next field
  }
}

/**
 * @brief Allocates memory for the game field and next field of the game.
 *
 * This function allocates memory for the game field and next field of the game
 * based on the dimensions specified by GAME_FIELD_Y_ALLOC and
 * GAME_FIELD_X_ALLOC.
 *
 * @param game_info Pointer to the GameInfoExtended_t structure where the memory
 * will be allocated.
 *
 * @return Returns 0 if memory allocation is successful, otherwise returns 1.
 */

int allocate_memory_figure(GameInfoExtended_t *game_info) {
  int error = 0;
  game_info->figure_current = malloc(sizeof(Figure_t));
  game_info->figure_next = malloc(sizeof(Figure_t));
  if (game_info->figure_current == NULL && game_info->next == NULL) {
    error = 1;
    return error;
  }

  game_info->figure_current->figure = malloc(4 * sizeof(int *));
  game_info->figure_next->figure = malloc(4 * sizeof(int *));
  if (game_info->figure_current->figure == NULL ||
      game_info->figure_next->figure == NULL) {
    error = 1;
    free(game_info->figure_current);
    if (game_info->figure_current->figure != NULL)
      free(game_info->figure_current->figure);
    if (game_info->figure_next->figure != NULL)
      free(game_info->figure_next->figure);
    return error;
  }

  for (int i = 0; i < 4; i++) {
    game_info->figure_current->figure[i] = malloc(4 * sizeof(int));
    game_info->figure_next->figure[i] = malloc(4 * sizeof(int));
    if (game_info->figure_current->figure[i] == NULL ||
        game_info->figure_next->figure[i] == NULL) {
      error = 1;
      for (int j = 0; j <= i; j++) {
        if (game_info->figure_current->figure[j] != NULL)
          free(game_info->figure_current->figure[j]);
        if (game_info->figure_next->figure[j] != NULL)
          free(game_info->figure_next->figure[j]);
      }
      free(game_info->figure_current->figure);
      free(game_info->figure_next->figure);
      free(game_info->figure_current);
      return error;
    }
  }

  return error;
}

/**
 * @brief Frees the memory allocated for the game figures.
 *
 * This function frees the memory allocated for the game figures, both the
 * current figure and the next figure.
 *
 * @param game_info Pointer to the GameInfoExtended_t structure containing the
 * game figures.
 */

void free_figure(GameInfoExtended_t *game_info) {
  if (game_info != NULL) {
    if (game_info->figure_current != NULL) {
      if (game_info->figure_current->figure != NULL) {
        for (int i = 0; i < 4; i++) {
          free(game_info->figure_current
                   ->figure[i]);  // Free memory for each row of the current
                                  // figure
        }
        free(game_info->figure_current
                 ->figure);  // Free memory for the current figure
      }
      free(game_info->figure_current);  // Free memory for the structure
                                        // containing the current figure
    }
    if (game_info->figure_next != NULL) {
      if (game_info->figure_next->figure != NULL) {
        for (int i = 0; i < 4; i++) {
          free(game_info->figure_next
                   ->figure[i]);  // Free memory for each row of the next figure
        }
        free(
            game_info->figure_next->figure);  // Free memory for the next figure
      }
      free(game_info->figure_next);  // Free memory for the structure containing
                                     // the next figure
    }
  }
}

/**
 * @brief Allocates memory for a temporary figure used in the game.
 *
 * This function allocates memory for a temporary figure used in the game.
 * The figure is represented as a 2D array of integers with a size of 4x4.
 *
 * @return Returns a pointer to the allocated memory for the temporary figure if
 * successful, otherwise returns NULL.
 */

int **alloc_temp_figure() {
  int size = 4;
  int **figure = (int **)malloc(size * sizeof(int *));

  if (figure == NULL) return NULL;

  for (int i = 0; i < size; i++) {
    figure[i] = (int *)malloc(size * sizeof(int));

    if (figure[i] == NULL) {
      for (int j = 0; j < i; j++) {
        free(figure[j]);
      }
      free(figure);
      return NULL;
    }

    for (int j = 0; j < size; j++) {
      figure[i][j] = 0;
    }
  }

  return figure;
}

/**
 * @brief Frees the memory allocated for a temporary figure used in the game.
 *
 * This function frees the memory allocated for a temporary figure used in the
 * game.
 *
 * @param figure Pointer to the 2D array of integers representing the temporary
 * figure.
 * @param size   Size of the temporary figure (both dimensions are assumed to be
 * the same).
 */

void free_temp_figure(int **figure, int size) {
  if (figure != NULL) {
    for (int i = 0; i < size; i++) {
      free(figure[i]);
    }
    free(figure);
  }
}
