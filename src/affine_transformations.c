#include "affine_transformations.h"

void s21_shift(Model *model, double value, Axis_t axis) {

    for (size_t i = axis; i < (model->total_vertices + 1) * 3; i += 3) {
        model->vertices[i] += value;
    }

}

// ??? возможно масштабирование по всем осям сразу? (кнопки +/-)
// ??? масштабирование за счёт приближения/отдаления камеры?
// !!! нужно центрировать, если в фигура полность в отрицательной части оси Z, то расширяясь одновременно сдвигается назад и визуально не изменяется
void s21_scale(Model *model, double value) {

    for (size_t i = 3; i < (model->total_vertices + 1) * 3; i++) {
        model->vertices[i] *= value;
    }

}

void s21_rotate_forward(Model *model, double value, Axis_t axis) {

    value *= M_PI / 180;

    if(axis == X) {

        for (size_t i = 3; i < (model->total_vertices + 1) * 3; i += 3) {
            model->vertices[i + 1] = model->vertices[i + 1] * cos(value) + model->vertices[i + 2] * sin(value);
            model->vertices[i + 2] = model->vertices[i + 1] * -sin(value) + model->vertices[i + 2] * cos(value);
        }

    }

    if(axis == Y) {

        for (size_t i = 3; i < (model->total_vertices + 1) * 3; i += 3) {
            model->vertices[i] = model->vertices[i] * cos(value) + model->vertices[i + 2] * -sin(value);
            model->vertices[i + 2] = model->vertices[i] * sin(value) + model->vertices[i + 2] * cos(value);
        }

    }

    if(axis == Z) {

        for (size_t i = 3; i < (model->total_vertices + 1) * 3; i += 3) {
            model->vertices[i] = model->vertices[i] * cos(value) + model->vertices[i + 1] * sin(value);
            model->vertices[i + 1] =  model->vertices[i] * -sin(value) + model->vertices[i + 1] * cos(value);
        }

    }

}

void s21_rotate_back(Model *model, double value, Axis_t axis) {

    value *= M_PI / 180;

    if(axis == X) {

        for (size_t i = 3; i < (model->total_vertices + 1) * 3; i += 3) {
            model->vertices[i + 1] = model->vertices[i + 1] * cos(value) + model->vertices[i + 2] * -sin(value);
            model->vertices[i + 2] = model->vertices[i + 1] * sin(value) + model->vertices[i + 2] * cos(value);
        }

    }

    if(axis == Y) {

        for (size_t i = 3; i < (model->total_vertices + 1) * 3; i += 3) {
            model->vertices[i] = model->vertices[i] * cos(value) + model->vertices[i + 2] * sin(value);
            model->vertices[i + 2] = model->vertices[i] * -sin(value) + model->vertices[i + 2] * cos(value);
        }

    }

    if(axis == Z) {

        for (size_t i = 3; i < (model->total_vertices + 1) * 3; i += 3) {
            model->vertices[i] = model->vertices[i] * cos(value) + model->vertices[i + 1] * -sin(value);
            model->vertices[i + 1] =  model->vertices[i] * sin(value) + model->vertices[i + 1] * cos(value);
        }

    }

}
