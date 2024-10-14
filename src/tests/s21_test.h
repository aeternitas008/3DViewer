#ifndef TEST_S21_TEST_H
#define TEST_S21_TEST_H

#include <check.h>
#include <locale.h>
#include <string.h>

#include "../qt/parser.h"
#include "../qt/affine_transformations.h"


Suite *parser_suite ();
Suite* s21_affin_rotate_suite();
Suite* s21_affin_scale_suite();
Suite* s21_affin_shift_suite();

// typedef enum {X = 3, Y, Z} Axis_t;

#endif // TEST_S21_TEST_H

