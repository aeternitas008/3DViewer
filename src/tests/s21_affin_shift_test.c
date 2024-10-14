#include "s21_test.h"

START_TEST(s21_shift_up) {

  Model model;

double array[] = { 0.0, 0.0,  0.0,
                   1.0, 1.0, -1.0,
                   1.0, 1.0,  1.0,
                  -1.0, 1.0,  1.0,
                  -1.0, 1.0, -1.0,
                   1.0, 3.0, -1.0,
                   1.0, 3.0,  1.0,
                  -1.0, 3.0,  1.0,
                  -1.0, 3.0, -1.0};

  s21_parser("tests/tests_object/my_cube.obj", &model);
  s21_shift(&model, 2, Y);

    for(size_t i = 3; i < (model.total_vertices + 1) * 3; i++) {
        ck_assert_double_eq_tol(array[i], model.vertices[i], 1e-06);
    }
  

  s21_cleaner(&model);
}
END_TEST

START_TEST(s21_shift_down) {

  Model model;

  double array[] = { 0.0,  0.0,  0.0,
                     1.0, -3.0, -1.0,
                     1.0, -3.0,  1.0,
                    -1.0, -3.0,  1.0,
                    -1.0, -3.0, -1.0,
                     1.0, -1.0, -1.0,
                     1.0, -1.0,  1.0,
                    -1.0, -1.0,  1.0,
                    -1.0, -1.0, -1.0};

  s21_parser("tests/tests_object/my_cube.obj", &model);
  s21_shift(&model, -2, Y);

    for(size_t i = 3; i < (model.total_vertices + 1) * 3; i++) {
        ck_assert_double_eq_tol(array[i], model.vertices[i], 1e-06);
    }
  

  s21_cleaner(&model);
}
END_TEST

START_TEST(s21_shift_left) {

  Model model;

  double array[] = { 0.0,  0.0,  0.0,
                    -1.0, -1.0, -1.0,
                    -1.0, -1.0,  1.0,
                    -3.0, -1.0,  1.0,
                    -3.0, -1.0, -1.0,
                    -1.0,  1.0, -1.0,
                    -1.0,  1.0,  1.0,
                    -3.0,  1.0,  1.0,
                    -3.0,  1.0, -1.0};

  s21_parser("tests/tests_object/my_cube.obj", &model);
  s21_shift(&model, -2, X);

    for(size_t i = 3; i < (model.total_vertices + 1) * 3; i++) {
        ck_assert_double_eq_tol(array[i], model.vertices[i], 1e-06);
    }
  

  s21_cleaner(&model);
}
END_TEST

START_TEST(s21_shift_right) {

  Model model;

  double array[] = { 0.0,  0.0,  0.0,
                     3.0, -1.0, -1.0,
                     3.0, -1.0,  1.0,
                     1.0, -1.0,  1.0,
                     1.0, -1.0, -1.0,
                     3.0,  1.0, -1.0,
                     3.0,  1.0,  1.0,
                     1.0,  1.0,  1.0,
                     1.0,  1.0, -1.0};

  s21_parser("tests/tests_object/my_cube.obj", &model);
  s21_shift(&model, 2, X);

    for(size_t i = 3; i < (model.total_vertices + 1) * 3; i++) {
        ck_assert_double_eq_tol(array[i], model.vertices[i], 1e-06);
    }
  

  s21_cleaner(&model);
}
END_TEST

START_TEST(s21_shift_closer) {

  Model model;

  double array[] = { 0.0,  0.0,  0.0,
                     1.0, -1.0,  1.0,
                     1.0, -1.0,  3.0,
                    -1.0, -1.0,  3.0,
                    -1.0, -1.0,  1.0,
                     1.0,  1.0,  1.0,
                     1.0,  1.0,  3.0,
                    -1.0,  1.0,  3.0,
                    -1.0,  1.0,  1.0};

  s21_parser("tests/tests_object/my_cube.obj", &model);
  s21_shift(&model, 2, Z);

    for(size_t i = 3; i < (model.total_vertices + 1) * 3; i++) {
        ck_assert_double_eq_tol(array[i], model.vertices[i], 1e-06);
    }
  

  s21_cleaner(&model);
}
END_TEST

START_TEST(s21_shift_further) {

  Model model;

  double array[] = { 0.0,  0.0,  0.0,
                     1.0, -1.0, -3.0,
                     1.0, -1.0, -1.0,
                    -1.0, -1.0, -1.0,
                    -1.0, -1.0, -3.0,
                     1.0,  1.0, -3.0,
                     1.0,  1.0, -1.0,
                    -1.0,  1.0, -1.0,
                    -1.0,  1.0, -3.0};

  s21_parser("tests/tests_object/my_cube.obj", &model);
  s21_shift(&model, -2, Z);

    for(size_t i = 3; i < (model.total_vertices + 1) * 3; i++) {
        ck_assert_double_eq_tol(array[i], model.vertices[i], 1e-06);
    }
  

  s21_cleaner(&model);
}
END_TEST

Suite* s21_affin_shift_suite() {
  Suite* s;
  s = suite_create("\033[33ms21_shift\033[0m");

  TCase* tc_core;
  tc_core = tcase_create("s21_shift_core");
  tcase_add_test(tc_core, s21_shift_up);
  tcase_add_test(tc_core, s21_shift_down);
  tcase_add_test(tc_core, s21_shift_left);
  tcase_add_test(tc_core, s21_shift_right);
  tcase_add_test(tc_core, s21_shift_closer);
  tcase_add_test(tc_core, s21_shift_further);

  suite_add_tcase(s, tc_core);

  return s;
}
