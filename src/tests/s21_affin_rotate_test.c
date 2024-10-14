#include "s21_test.h"

START_TEST(s21_rotate_X) {

  Model model;

double array[] = { 0.0,  0.0,  0.0,
                   1.0, -1.083350, -0.909038,
                   1.0, -0.909038,  1.083350,
                  -1.0, -0.909038,  1.083350,
                  -1.0, -1.083350, -0.909038,
                   1.0,  0.909038, -1.083350,
                   1.0,  1.083350,  0.909038,
                  -1.0,  1.083350,  0.909038,
                  -1.0,  0.909038, -1.083350};

  s21_parser("tests/tests_object/my_cube.obj", &model);
  s21_rotate(&model, 5.0, X);

    for(size_t i = 3; i < (model.total_vertices + 1) * 3; i++) {
        ck_assert_double_eq_tol(array[i], model.vertices[i], 1e-06);
    }
 
  s21_cleaner(&model);
}
END_TEST

START_TEST(s21_rotate_Y) {

  Model model;

double array[] = { 0.0,  0.0,  0.0,
                   1.083350, -1.0, -0.909038,
                   0.909038, -1.0,  1.083350,
                  -1.083350, -1.0,  0.909038,
                  -0.909038, -1.0, -1.083350,
                   1.083350,  1.0, -0.909038,
                   0.909038,  1.0,  1.083350,
                  -1.083350,  1.0,  0.909038,
                  -0.909038,  1.0, -1.083350};

  s21_parser("tests/tests_object/my_cube.obj", &model);
  s21_rotate(&model, 5.0, Y);

    for(size_t i = 3; i < (model.total_vertices + 1) * 3; i++) {
        ck_assert_double_eq_tol(array[i], model.vertices[i], 1e-06);
    }
  

  s21_cleaner(&model);
}
END_TEST

START_TEST(s21_rotate_Z) {

  Model model;

double array[] = { 0.0,  0.0,  0.0,
                   0.909038, -1.083350, -1.0,
                   0.909038, -1.083350,  1.0,
                  -1.083350, -0.909038,  1.0,
                  -1.083350, -0.909038, -1.0,
                   1.083350,  0.909038, -1.0,
                   1.083350,  0.909038,  1.0,
                  -0.909038,  1.083350,  1.0,
                  -0.909038,  1.083350, -1.0};

  s21_parser("tests/tests_object/my_cube.obj", &model);
  s21_rotate(&model, 5.0, Z);

    for(size_t i = 3; i < (model.total_vertices + 1) * 3; i++) {
        ck_assert_double_eq_tol(array[i], model.vertices[i], 1e-06);
    }
  

  s21_cleaner(&model);
}
END_TEST

START_TEST(s21_rotate_X_back) {

  Model model;

double array[] = { 0.0,  0.0,  0.0,
                   1.0, -0.909038, -1.083350,
                   1.0, -1.083350,  0.909038,
                  -1.0, -1.083350,  0.909038,
                  -1.0, -0.909038, -1.083350,
                   1.0,  1.083350, -0.909038,
                   1.0,  0.909038,  1.083350,
                  -1.0,  0.909038,  1.083350,
                  -1.0,  1.083350, -0.909038};

  s21_parser("tests/tests_object/my_cube.obj", &model);
  s21_rotate(&model, -5.0, X);

    for(size_t i = 3; i < (model.total_vertices + 1) * 3; i++) {
        ck_assert_double_eq_tol(array[i], model.vertices[i], 1e-06);
    }

  s21_cleaner(&model);
}
END_TEST

START_TEST(s21_rotate_Y_back) {

  Model model;

double array[] = { 0.0,  0.0,  0.0,
                   0.909038, -1.0, -1.083350,
                   1.083350, -1.0,  0.909038,
                  -0.909038, -1.0,  1.083350,
                  -1.083350, -1.0, -0.909038,
                   0.909038,  1.0, -1.083350,
                   1.083350,  1.0,  0.909038,
                  -0.909038,  1.0,  1.083350,
                  -1.083350,  1.0, -0.909038};

  s21_parser("tests/tests_object/my_cube.obj", &model);
  s21_rotate(&model, -5.0, Y);

    for(size_t i = 3; i < (model.total_vertices + 1) * 3; i++) {
        ck_assert_double_eq_tol(array[i], model.vertices[i], 1e-06);
    }
  

  s21_cleaner(&model);
}
END_TEST

START_TEST(s21_rotate_Z_back) {

  Model model;

double array[] = { 0.0,  0.0,  0.0,
                   1.083350, -0.909038, -1.0,
                   1.083350, -0.909038,  1.0,
                  -0.909038, -1.083350,  1.0,
                  -0.909038, -1.083350, -1.0,
                   0.909038,  1.083350, -1.0,
                   0.909038,  1.083350,  1.0,
                  -1.083350,  0.909038,  1.0,
                  -1.083350,  0.909038, -1.0};

  s21_parser("tests/tests_object/my_cube.obj", &model);
  s21_rotate(&model, -5.0, Z);

    for(size_t i = 3; i < (model.total_vertices + 1) * 3; i++) {
        ck_assert_double_eq_tol(array[i], model.vertices[i], 1e-06);
    }
  

  s21_cleaner(&model);
}
END_TEST


Suite* s21_affin_rotate_suite() {
  Suite* s;
  s = suite_create("\033[33ms21_rotate\033[0m");

  TCase* tc_core;
  tc_core = tcase_create("s21_rotate_core");
  tcase_add_test(tc_core, s21_rotate_X);
  tcase_add_test(tc_core, s21_rotate_Y);
  tcase_add_test(tc_core, s21_rotate_Z);
  tcase_add_test(tc_core, s21_rotate_X_back);
  tcase_add_test(tc_core, s21_rotate_Y_back);
  tcase_add_test(tc_core, s21_rotate_Z_back);

  suite_add_tcase(s, tc_core);

  return s;
}
