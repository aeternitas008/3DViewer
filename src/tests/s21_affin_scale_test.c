#include "s21_test.h"

START_TEST(s21_scale_increase) {

  Model model;

double array[] = { 0.0,  0.0,  0.0,
                   1.1, -1.1, -1.1,
                   1.1, -1.1,  1.1,
                  -1.1, -1.1,  1.1,
                  -1.1, -1.1, -1.1,
                   1.1,  1.1, -1.1,
                   1.1,  1.1,  1.1,
                  -1.1,  1.1,  1.1,
                  -1.1,  1.1, -1.1};

  s21_parser("tests/my_cube.obj", &model);
  s21_scale(&model, 1.1);

    for(size_t i = 3; i < (model.total_vertices + 1) * 3; i++) {
        ck_assert_double_eq_tol(array[i], model.vertices[i], 1e-06);
    }
  

  s21_cleaner(&model);
}
END_TEST

START_TEST(s21_scale_increase_2) {

  Model model;

double array[] = { 0.0,  0.0,  0.0,
                   1.5, -1.5, -1.5,
                   1.5, -1.5,  1.5,
                  -1.5, -1.5,  1.5,
                  -1.5, -1.5, -1.5,
                   1.5,  1.5, -1.5,
                   1.5,  1.5,  1.5,
                  -1.5,  1.5,  1.5,
                  -1.5,  1.5, -1.5};

  s21_parser("tests/my_cube.obj", &model);
  s21_scale(&model, 1.5);

    for(size_t i = 3; i < (model.total_vertices + 1) * 3; i++) {
        ck_assert_double_eq_tol(array[i], model.vertices[i], 1e-06);
    }
  

  s21_cleaner(&model);
}
END_TEST

START_TEST(s21_scale_increase_3) {

  Model model;

double array[] = { 0.0,  0.0,  0.0,
                   2.0, -2.0, -2.0,
                   2.0, -2.0,  2.0,
                  -2.0, -2.0,  2.0,
                  -2.0, -2.0, -2.0,
                   2.0,  2.0, -2.0,
                   2.0,  2.0,  2.0,
                  -2.0,  2.0,  2.0,
                  -2.0,  2.0, -2.0};

  s21_parser("tests/my_cube.obj", &model);
  s21_scale(&model, 2.0);

    for(size_t i = 3; i < (model.total_vertices + 1) * 3; i++) {
        ck_assert_double_eq_tol(array[i], model.vertices[i], 1e-06);
    }
  

  s21_cleaner(&model);
}
END_TEST

START_TEST(s21_scale_decrease) {

  Model model;

double array[] = { 0.0,  0.0,  0.0,
                   0.9, -0.9, -0.9,
                   0.9, -0.9,  0.9,
                  -0.9, -0.9,  0.9,
                  -0.9, -0.9, -0.9,
                   0.9,  0.9, -0.9,
                   0.9,  0.9,  0.9,
                  -0.9,  0.9,  0.9,
                  -0.9,  0.9, -0.9};

  s21_parser("tests/my_cube.obj", &model);
  s21_scale(&model, 0.9);

    for(size_t i = 3; i < (model.total_vertices + 1) * 3; i++) {
        ck_assert_double_eq_tol(array[i], model.vertices[i], 1e-06);
    }
  

  s21_cleaner(&model);
}
END_TEST

START_TEST(s21_scale_decrease_2) {

  Model model;

double array[] = { 0.0,  0.0,  0.0,
                   0.5, -0.5, -0.5,
                   0.5, -0.5,  0.5,
                  -0.5, -0.5,  0.5,
                  -0.5, -0.5, -0.5,
                   0.5,  0.5, -0.5,
                   0.5,  0.5,  0.5,
                  -0.5,  0.5,  0.5,
                  -0.5,  0.5, -0.5};

  s21_parser("tests/my_cube.obj", &model);
  s21_scale(&model, 0.5);

    for(size_t i = 3; i < (model.total_vertices + 1) * 3; i++) {
        ck_assert_double_eq_tol(array[i], model.vertices[i], 1e-06);
    }
  

  s21_cleaner(&model);
}
END_TEST

START_TEST(s21_scale_decrease_3) {

  Model model;

double array[] = { 0.0,  0.0,  0.0,
                   0.2, -0.2, -0.2,
                   0.2, -0.2,  0.2,
                  -0.2, -0.2,  0.2,
                  -0.2, -0.2, -0.2,
                   0.2,  0.2, -0.2,
                   0.2,  0.2,  0.2,
                  -0.2,  0.2,  0.2,
                  -0.2,  0.2, -0.2};

  s21_parser("tests/my_cube.obj", &model);
  s21_scale(&model, 0.2);

    for(size_t i = 3; i < (model.total_vertices + 1) * 3; i++) {
        ck_assert_double_eq_tol(array[i], model.vertices[i], 1e-06);
    }
  

  s21_cleaner(&model);
}
END_TEST

Suite* s21_affin_scale_suite(void) {
  Suite* s;
  s = suite_create("\033[33ms21_scale\033[0m");

  TCase* tc_core;
  tc_core = tcase_create("s21_scale_core");
  tcase_add_test(tc_core, s21_scale_increase);
  tcase_add_test(tc_core, s21_scale_increase_2);
  tcase_add_test(tc_core, s21_scale_increase_3);
  tcase_add_test(tc_core, s21_scale_decrease);
  tcase_add_test(tc_core, s21_scale_decrease_2);
  tcase_add_test(tc_core, s21_scale_decrease_3);

  suite_add_tcase(s, tc_core);

  return s;
}
