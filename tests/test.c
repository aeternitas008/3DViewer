#include "s21_test.h"

int main() {
  int number_failed;
  //Suite *parser_s;
  // *s21_affin_rotate_s, *s21_affin_scale_s, *s21_affin_shift_s;
    
  SRunner *sr;

  // parser_s = parser_suite();
  // s21_affin_rotate_s
  // s21_affin_scale_s
  // s21_affin_shift_s

  sr = srunner_create(parser_suite());
  srunner_add_suite(sr, s21_affin_rotate_suite());
  srunner_add_suite(sr, s21_affin_scale_suite());
  srunner_add_suite(sr, s21_affin_shift_suite());
  srunner_set_fork_status(sr, CK_FORK);



  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
