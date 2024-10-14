#ifndef S21_TEST_H
#define S21_TEST_H

#include <check.h>

#include "../affine_transformations.h"

#define TRUE 1
#define FALSE 0

Suite* s21_affin_shift_suite(void);
Suite* s21_affin_scale_suite(void);
Suite* s21_affin_rotate_suite(void);


#endif

// double array[] = { 0.0,  0.0,  0.0,
//                    1.0, -1.0, -1.0,
//                    1.0, -1.0,  1.0,
//                   -1.0, -1.0,  1.0,
//                   -1.0, -1.0, -1.0,
//                    1.0,  1.0, -1.0,
//                    1.0,  1.0,  1.0,
//                   -1.0,  1.0,  1.0,
//                   -1.0,  1.0, -1.0};