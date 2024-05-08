#include "gui.h"

/**
 * @brief Prints the game interface including the game panel and score panel.
 *
 * This function prints the game interface, which consists of the game panel and
 * the score panel, using the provided game information.
 *
 * @param game_info The structure containing the game information such as the
 * game field, score, level, etc.
 */
void print_game(GameInfo_t game_info) {
  print_game_panel(game_info);   // Print the game panel
  print_score_panel(game_info);  // Print the score panel
  refresh();                     // Refresh the screen
}

/**
 * @brief Prints the game panel within the game interface.
 *
 * This function creates a new window for the game panel, prints the game field
 * and next figure using the provided game information, and refreshes the
 * window.
 *
 * @param game_info The structure containing the game information such as the
 * game field, score, level, etc.
 */
void print_game_panel(GameInfo_t game_info) {
  WINDOW *game_win = newwin(GAME_WALL_Y_END, GAME_WALL_X_END, 0,
                            0);  // Create a new window for the game panel
  box(game_win, 0, 0);           // Draw a box around the window

  for (int i = 0; i < GAME_FIELD_Y_END; i++) {
    for (int j = 0, jForGUI = 1; j < GAME_FIELD_X_END; j++, jForGUI += 2) {
      if (game_info.next[i][j] == BRICK) {
        mvwprintw(game_win, i + 1, jForGUI,
                  BRICK_GUI);  // Print a brick symbol at the specified position
      } else {
        mvwprintw(
            game_win, i + 1, jForGUI,
            EMPTY_GUI);  // Print an empty symbol at the specified position
      }
    }
  }

  wrefresh(game_win);  // Refresh the game panel window
}

void print_next_figure(GameInfo_t game_info, WINDOW *panel_win) {
  mvwprintw(panel_win, 12, 7, "NEXT FIGURE:");

  for (int i = 0; i < 4; i++) {
    for (int j = 0, jForGUI = 1; j < 4; j++, jForGUI += 2) {
      if (game_info.field[i][j] == BRICK) {
        mvwprintw(panel_win, i + 13, jForGUI + 7, BRICK_GUI);
      }
    }
  }
}

/**
 * @brief Prints the score panel within the game interface.
 *
 * This function creates a new window for the score panel, prints the best
 * score, current score, level, speed, and the next figure using the provided
 * game information, and refreshes the window.
 *
 * @param game_info The structure containing the game information such as the
 * game field, score, level, etc.
 */

void print_score_panel(GameInfo_t game_info) {
  WINDOW *panel_win = newwin(GAME_WALL_Y_END, GAME_WALL_X_END + 5,
                             GAME_WALL_Y_START, GAME_WALL_X_END);
  box(panel_win, 0, 0);

  move(1, GAME_WALL_X_END + 1);
  printw("Best Score: %d", game_info.high_score);

  move(4, GAME_WALL_X_END + 1);
  printw("Score: %d", game_info.score);

  move(7, GAME_WALL_X_END + 1);
  printw("Level: %d", game_info.level);

  move(10, GAME_WALL_X_END + 1);
  printw("Speed: %d", game_info.speed);

  print_next_figure(game_info, panel_win);

  wrefresh(panel_win);
}

/**
 * @brief Displays the pause screen with a message and instructions.
 *
 * This function creates a new window for the pause screen, displays the "PAUSE"
 * message and instructions to continue, and refreshes the window. It also
 * handles the deletion of the window after it's no longer needed.
 */
void print_pause() {
  // Create a new window for the pause screen
  WINDOW *pause_win = newwin(5, 35, 8, 7);
  // Draw a box around the window
  box(pause_win, 0, 0);
  // Refresh the pause screen window
  wrefresh(pause_win);

  // Print the "PAUSE" message at the specified position
  mvwprintw(pause_win, 1, 15, "PAUSE");
  // Print the instruction to continue
  mvwprintw(pause_win, 3, 6, "PRESS 'ENTER' TO CONTINUE");

  wrefresh(pause_win);  // Refresh the pause screen window
  delwin(pause_win);    // Delete the pause screen window
}
