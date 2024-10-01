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

// а что будет если попробую повернуть не загрузив модель
// проверку return'ом???
// будет ли ситуация нулевого value???
void s21_rotate_forward(Model *model, double value, Axis_t axis) {

    value *= M_PI / 180;

    for (size_t i = 3; i < (model->total_vertices + 1) * 3; i += 3) {

        double x = model->vertices[i];
        double y = model->vertices[i + 1];
        double z = model->vertices[i + 2];

        if(axis == X) {
            model->vertices[i + 1] = y * cos(value) + z * sin(value);
            model->vertices[i + 2] = y * -sin(value) + z * cos(value);
        }

        if(axis == Y) {
            model->vertices[i] = x * cos(value) + z * -sin(value);
            model->vertices[i + 2] = x * sin(value) + z * cos(value);
        }

        if(axis == Z) {
            model->vertices[i] = x * cos(value) + y * sin(value);
            model->vertices[i + 1] =  x * -sin(value) + y * cos(value);
        }
    }
} // s21_rotate_forward

void s21_rotate_back(Model *model, double value, Axis_t axis) {

    value *= M_PI / 180;

    for (size_t i = 3; i < (model->total_vertices + 1) * 3; i += 3) {

        double x = model->vertices[i];
        double y = model->vertices[i + 1];
        double z = model->vertices[i + 2];

        if(axis == X) {
            model->vertices[i + 1] = y * cos(value) + z * -sin(value);
            model->vertices[i + 2] = y * sin(value) + z * cos(value);
        }

        if(axis == Y) {
            model->vertices[i] = x * cos(value) + z * sin(value);
            model->vertices[i + 2] = x * -sin(value) + z * cos(value);
        }

        if(axis == Z) {
            model->vertices[i] = x * cos(value) + y * -sin(value);
            model->vertices[i + 1] =  x * sin(value) + y * cos(value);
        }
    }
} // s21_rotate_back
