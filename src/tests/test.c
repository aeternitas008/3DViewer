#include "s21_test.h"

int main() {
  int number_failed;
  Suite *parser_s;
    
  SRunner *sr;

  parser_s = parser_suite();

  sr = srunner_create(parser_s);

  srunner_set_fork_status(sr, CK_FORK);


  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
