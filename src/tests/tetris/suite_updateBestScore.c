#include "tetris_tests.h"

START_TEST(checkFopen_updBestScore) {
  GameInfoExtended_t game_info;

  int error = init_game_info(&game_info);
  ck_assert_int_eq(error, 0);

  updateBestScore(&game_info);
  ck_assert_int_eq(game_info.high_score, game_info.high_score);

  free_game_info(&game_info);
}

START_TEST(checkFopen_getBestScore) {
  GameInfoExtended_t game_info;

  int error = init_game_info(&game_info);
  ck_assert_int_eq(error, 0);
  getBestScore(&game_info);
  ck_assert_int_eq(game_info.high_score, (game_info.high_score));
  free_game_info(&game_info);
}
END_TEST

Suite *suite_updateBestScore(void) {
  Suite *s = suite_create("suite_updateBestScore");
  TCase *tc = tcase_create("case_updateBestScore");

  tcase_add_test(tc, checkFopen_updBestScore);
  tcase_add_test(tc, checkFopen_getBestScore);

  suite_add_tcase(s, tc);

  return s;
}