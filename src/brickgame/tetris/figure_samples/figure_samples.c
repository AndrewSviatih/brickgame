#include "../bricks_logic.h"

/**
 * @brief Sets the figure for a straight line in the next figure container.
 *
 * This function sets the figure for a straight line in the next figure
 * container of the game_info.
 *
 * @param game_info Pointer to the GameInfoExtended_t structure containing game
 * information.
 */

void getFigureLine(GameInfoExtended_t *game_info) {
  for (int i = 0; i < 4; i++) {
    game_info->figure_next->figure[i][1] = BRICK;
  }
}

/**
 * @brief Sets the figure for a straight line in the next figure container.
 *
 * This function sets the figure for a straight line in the next figure
 * container of the game_info.
 *
 * @param game_info Pointer to the GameInfoExtended_t structure containing game
 * information.
 */

void getFigureBox(GameInfoExtended_t *game_info) {
  for (int i = 1; i < 3; i++) {
    for (int j = 1; j < 3; j++) {
      game_info->figure_next->figure[i][j] = BRICK;
    }
  }
}

/**
 * @brief Sets the figure for a left angle shape in the next figure container.
 *
 * This function sets the figure for a left angle shape in the next figure
 * container of the game_info. The left angle shape consists of three bricks
 * forming an L shape.
 *
 * @param game_info Pointer to the GameInfoExtended_t structure containing game
 * information.
 */

void getFigureLeftAngle(GameInfoExtended_t *game_info) {
  game_info->figure_next->figure[1][1] = BRICK;
  for (int i = 1; i < 4; i++) {
    game_info->figure_next->figure[2][i] = BRICK;
  }
}

/**
 * @brief Sets the figure for a triangle shape in the next figure container.
 *
 * This function sets the figure for a triangle shape in the next figure
 * container of the game_info.
 *
 * @param game_info Pointer to the GameInfoExtended_t structure containing game
 * information.
 */

void getFigureTriangle(GameInfoExtended_t *game_info) {
  game_info->figure_next->figure[1][2] = BRICK;
  for (int i = 1; i < 4; i++) {
    game_info->figure_next->figure[2][i] = BRICK;
  }
}

/**
 * @brief Sets the figure for a right angle shape in the next figure container.
 *
 * This function sets the figure for a right angle shape in the next figure
 * container of the game_info. The right angle shape consists of three bricks
 * forming a 90-degree angle.
 *
 * @param game_info Pointer to the GameInfoExtended_t structure containing game
 * information.
 */

void getFigureRightAngle(GameInfoExtended_t *game_info) {
  game_info->figure_next->figure[1][3] = BRICK;
  for (int i = 1; i < 4; i++) {
    game_info->figure_next->figure[2][i] = BRICK;
  }
}

/**
 * @brief Sets the figure for a right-oriented snake shape in the next figure
 * container.
 *
 * This function sets the figure for a right-oriented snake shape in the next
 * figure container of the game_info. The right-oriented snake shape consists of
 * four bricks forming an "S" shape in a right-oriented manner.
 *
 * @param game_info Pointer to the GameInfoExtended_t structure containing game
 * information.
 */

void getFigureSnakeRight(GameInfoExtended_t *game_info) {
  game_info->figure_next->figure[2][1] = BRICK;
  game_info->figure_next->figure[2][2] = BRICK;
  game_info->figure_next->figure[1][2] = BRICK;
  game_info->figure_next->figure[1][3] = BRICK;
}

/**
 * @brief Sets the figure for a left-oriented snake shape in the next figure
 * container.
 *
 * This function sets the figure for a left-oriented snake shape in the next
 * figure container of the game_info. The left-oriented snake shape consists of
 * four bricks forming an "S" shape in a left-oriented manner.
 *
 * @param game_info Pointer to the GameInfoExtended_t structure containing game
 * information.
 */

void getFigureSnakeLeft(GameInfoExtended_t *game_info) {
  game_info->figure_next->figure[1][1] = BRICK;
  game_info->figure_next->figure[1][2] = BRICK;
  game_info->figure_next->figure[2][2] = BRICK;
  game_info->figure_next->figure[2][3] = BRICK;
}
