#ifndef AFFINE_TRANSFORMATIONS_H
#define AFFINE_TRANSFORMATIONS_H

#include "parcer.h"
#include <math.h>

typedef enum {X = 3, Y, Z} Axis_t;

    void s21_shift(Model *model, double value, Axis_t axis);
    void s21_scale(Model *model, double value);
    void s21_rotate_forward(Model *model, double value, Axis_t axis);
    void s21_rotate_back(Model *model, double value, Axis_t axis);


#endif // AFFINE_TRANSFORMATIONS_H
