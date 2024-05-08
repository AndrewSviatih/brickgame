#ifndef STRING_S21_BRICKS_GAME_H
#define STRING_S21_BRICKS_GAME_H

#include <time.h>

#include "ncurses.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

#define EMPTY 0
#define BRICK 1

#define GAME_FIELD_X_START 4
#define GAME_FIELD_Y_START 1

#define GAME_FIELD_X_END 10
#define GAME_FIELD_Y_END 20

#define GAME_FIELD_Y_ALLOC 25
#define GAME_FIELD_X_ALLOC 19

#define FIGURE_CENTR_X 3
#define FIGURE_SIZE 4

#define KEY_PAUSE 112
#define KEY_ESC 27
#define KEY_SPACE 32
#define KEY_ENTERR 10

/**
 * @enum UserAction_t
 * @brief Enumerates the possible actions a user can take while playing the
 * game.
 */
typedef enum {
  Start,     /**< Start the game or resume from pause. */
  Pause,     /**< Pause the ongoing game. */
  Terminate, /**< Terminate the game. */
  Left,      /**< Move the figure to the left. */
  Right,     /**< Move the figure to the right. */
  Up,        /**< Rotate the figure or move up in menus. */
  Down,      /**< Move the figure down faster or move down in menus. */
  Action,    /**< Perform the default action, like rotate the figure. */
  Skip       /**< Skip the current tick or action. */
} UserAction_t;

/**
 * @enum Automaton_t
 * @brief Enumerates the states of the game automaton which controls the game
 * flow.
 */
typedef enum {
  Start_automaton, /**< State where the game is initializing. */
  Spawn,           /**< State where a new figure is spawned. */
  Moving,          /**< State where the figure is moving/falling. */
  Shifting,        /**< State where a tick is skipped. */
  Collided, /**< State where the figure has collided and cannot move further. */
  Attaching, /**< State where the figure is attaching to the stack, checked for
                game over. */
  GameOver   /**< State where the game is over. */
} Automaton_t;

/**
 * @struct Figure_t
 * @brief Represents a game figure.
 */
typedef struct {
  int x_figure; /**< X position of the figure. */
  int y_figure; /**< Y position of the figure. */
  int **figure; /**< 2D array representing the shape of the figure. */
} Figure_t;

/**
 * @struct GameInfo_t
 * @brief Stores the basic state and configuration of the game.
 */
typedef struct {
  int **field;    /**< 2D array representing the game field. */
  int **next;     /**< 2D array representing the next figure to be played. */
  int score;      /**< Current score of the game. */
  int high_score; /**< Highest score achieved. */
  int level;      /**< Current level of the game. */
  int speed;      /**< Speed of the falling figures. */
  int pause;      /**< Whether the game is paused. */
} GameInfo_t;     // api

/**
 * @struct GameInfoExtended_t
 * @brief Stores the extended state and configuration of the game, including the
 * current and next figures.
 */
typedef struct {
  int **field; /**< 2D array representing the game field. */
  int **next;  /**< 2D array representing the next figure to be played. */
  Figure_t *figure_current; /**< Pointer to the current figure. */
  Figure_t *figure_next;    /**< Pointer to the next figure. */
  int score;                /**< Current score of the game. */
  int high_score;           /**< Highest score achieved. */
  int level;                /**< Current level of the game. */
  int speed;                /**< Speed of the falling figures. */
  int pause;                /**< Whether the game is paused. */
  int lose;                 /**< Whether the game has been lost. */
} GameInfoExtended_t;

void gameloop();
void backend(GameInfoExtended_t *game_info, UserAction_t *user_action,
             int *tick_count, int *collision);
/* api engine */
GameInfo_t *getGameInfo();
Automaton_t *getAutomaton();
GameInfo_t updateCurrentState();
int alloc_api_game_info(GameInfo_t *api);
void init_api_game_info(GameInfo_t *api);
void free_api_game_info();
void copy_game_info_extended_to_api(GameInfoExtended_t *game_info);

/* inits */
int init_game_info(GameInfoExtended_t *game_info);
void init_figure(GameInfoExtended_t *game_info);
void init_field(GameInfoExtended_t *game_info);
void init_ncurses_settings();
void init_after_menu(UserAction_t *user_action);
void getBestScore(GameInfoExtended_t *game_info);

/* memory funcs */
int alloc_game_info(GameInfoExtended_t *game_info);
int allocate_memory_fields(GameInfoExtended_t *game_info);
int allocate_memory_figure(GameInfoExtended_t *game_info);
int **alloc_temp_figure();

void free_game_info(GameInfoExtended_t *game_info);
void free_fields(GameInfoExtended_t *game_info);
void free_figure(GameInfoExtended_t *game_info);
void free_temp_figure(int **figure, int size);

/* get UserAction_t from keyboard */
int get_user_action();
void clear_cache_terminal();

/* figures funcs */
void game_move_procces(GameInfoExtended_t *game_info, UserAction_t *user_action,
                       int *collision);
int getRandomFigureNumber();
void get_figure_next(GameInfoExtended_t *game_info);
void copy_next_to_field(GameInfoExtended_t *game_info, int rows, int cols);
void spawn_figure_to_game(GameInfoExtended_t *game_info);
void copy_figure_next_to_current(GameInfoExtended_t *game_info);
void clear_current_figure_from_game(GameInfoExtended_t *game_info);
void clear_current_figure(GameInfoExtended_t *game_info);
void clear_next_figure(GameInfoExtended_t *game_info);
int skip_tick(GameInfoExtended_t *game_info, int *tick_count);

void move_figure(UserAction_t *user_action, GameInfoExtended_t *game_info);
void move_pos_figure_down(GameInfoExtended_t *game_info);
void move_pos_figure_left(GameInfoExtended_t *game_info);
void move_pos_figure_right(GameInfoExtended_t *game_info);
void add_next_pos_figure_to_game(GameInfoExtended_t *game_info);
void rotate_figure(GameInfoExtended_t *game_info, int **temp_figure);
int **rotated_figure(GameInfoExtended_t *game_info);
/* score_update */
void score_update(GameInfoExtended_t *game_info);
void lvlUp(GameInfoExtended_t *game_info, int last_score);
void add_score(GameInfoExtended_t *game_info, int count_fill_rows);
void updateBestScore(GameInfoExtended_t *game_info);

int check_full_rows(GameInfoExtended_t *game_info);
void remove_full_line(GameInfoExtended_t *game_info, int start_row);

/* collisions */
int is_collision(GameInfoExtended_t *game_info);
int can_spawn_figure(GameInfoExtended_t *game_info);
int can_move_left(GameInfoExtended_t *game_info);
int can_move_right(GameInfoExtended_t *game_info);
int can_rotate(GameInfoExtended_t *game_info, int **temp_figure,
               int can_rotate);
int check_intersection_when_rotate(GameInfoExtended_t *game_info, int i, int j,
                                   int can_rotate);

#endif  // STRING_S21_BRICKS_GAME_H