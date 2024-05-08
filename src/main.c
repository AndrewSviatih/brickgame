#include "brickgame/tetris/bricks_logic.h"
#include "gui/sli/gui.h"

/**
 * @brief Initializes ncurses settings and starts the game loop
 *
 * @return int 0 on success, -1 on failure
 */
int main() {
  init_ncurses_settings();
  gameloop();
  endwin();

  return 0;
}