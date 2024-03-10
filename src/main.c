#include "brickgame/tetris/bricks_logic.h"
#include "gui/sli/gui.h"

void tetris_game(UserAction_t user_action, GameInfo_t game_info) {
  initscr();
  init_game_field(&game_info);

  getch();
  print_game(game_info);
  refresh();
  getch();

  endwin();
}

int main() {
  UserAction_t user_action = Start;
  GameInfo_t game_info;
  int error = 0;

  error = allocate_memory_fields(&game_info);

  if (!error) {
    tetris_game(user_action, &game_info);
    free_fields(&game_info);
  } else {
    printf("Memory error. Restart Game\n");
  }

  return 0;
}