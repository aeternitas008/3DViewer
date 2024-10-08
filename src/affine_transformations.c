#include "affine_transformations.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * ФУНКЦИЯ ПЕРЕМЕЩЕНИЯ МОДЕЛИ
 * -----------------------------------------------------------
 * Model *model - указатель на модель;
 * double value - коэффициент сдвига (насколько сдвинуть);
 *                знак определяет направление сдвига
 * Axis_t axis  - ось сдвига (X, Y, Z);
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void s21_shift(Model *model, double value, Axis_t axis) {

  if(model && model->vertices && model->polygons) {

    for (size_t i = axis; i < (model->total_vertices + 1) * 3; i += 3) {
        model->vertices[i] += value;
    }

  }
} // s21_shift

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * ФУНКЦИЯ МАСШТАБИРОВАНИЯ МОДЕЛИ
 * -----------------------------------------------------------
 * Model *model - указатель на модель;
 * double value - коэффициент масштабирования;
 *                value > 1 - увеличение   
 *                value < 1 - уменьшение
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void s21_scale(Model *model, double value) {

  if(model && model->vertices && model->polygons && value > 0) {

    for (size_t i = 3; i < (model->total_vertices + 1) * 3; i++) {
        model->vertices[i] *= value;
    }

  }
} // s21_scale

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * ФУНКЦИЯ ПОВОРОТА МОДЕЛИ (ПО ЧАСОВОЙ СТРЕЛКЕ)
 * -----------------------------------------------------------
 * Model *model - указатель на модель;
 * double value - угол поворота;
 *                value > 0 - по часовой стрелке  
 *                value < 0 - против часовой стрелки
 * Axis_t axis  - ось поворота (X, Y, Z);
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void s21_rotate(Model *model, double value, Axis_t axis) {

  if(model && model->vertices && model->polygons && value != 0) {

    // переводим угол в радианы
    value *= M_PI / 180;

    // проходим по массиву точек модели
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
  }
} // s21_rotate
