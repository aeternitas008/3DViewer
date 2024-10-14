#include "s21_test.h"

int main() {
  int failed = 0;

  Suite* s21_affin_test[] = {s21_affin_shift_suite(),
                             s21_affin_scale_suite(),
                             s21_affin_rotate_suite(),
                              // s21_sub_suite(),
                              // s21_mult_suite(),
                              // s21_mult_number_suite(),
                              // s21_transpose_suite(),
                              // s21_determinant_suite(),
                              // s21_calc_complements_suite(),
                              // s21_inverse_suite(),
                              NULL};

  for (int i = 0; s21_affin_test[i] != NULL; i++) {
    printf("-----------------------------------------------\n      ");

    SRunner* sr = srunner_create(s21_affin_test[i]);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);

    srunner_free(sr);
  }

  if (failed == 0) {
    printf(
        "\033[32m------------------- SUCCESS -------------------\033[0m\n\n");
  } else {
    printf("\033[31m------------------ FAILED: %d -----------------\033[0m\n\n",
           failed);
  }

  return (failed == 0) ? 0 : 1;
}