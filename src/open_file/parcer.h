#ifndef PARCER_H
#define PARCER_H

#include <stdio.h>
#include <stdlib.h>

/*
 *  ПОЛИГОНЫ
 *  --------
 *  Для каждого полигона из файла создаём свой экземпляр
 *  структуры polygon по образцу:
 *
 *  f 1 4 6 9 2
 *
 *  numbers_of_vertices = {1, 4, 6, 9, 2}
 *  count_of_vertices = 5
 *
 *  Все эти экземпляры храним в виде массива, в структуре Model
 *  ---------------------------------------------
 *
 *  ТОЧКИ
 *  -----
 *  Парсим в массив vertices вида {0, 0, 0, X1, Y1, Z1, X2, ... Zn}
 *
 *  !!!ВАЖНО!!!
 *  ПЕРВЫЕ ТРИ ЭЛЕМЕНТА МАССИВА НУЛЕВЫЕ!
 *  Таким образом, при указании точек полигонов при отрисовке,
 *  приходим к классической индексации с первого элемента (не с нулевого)
 *
 *  ПРИМЕР:
 *
 *  v 3.76 9.17 -67.1
 *  v 35.10 2.01 8.345
 *  v 6 -5 2
 *
 *  vertces = {0, 0, 0, 3.76, 9.17, -67.1, 35.10, 2.01, 8.345, 6, -5, 2}
 *
 */

typedef struct {
    int *numbers_of_vertices;   // массив номеров вершин грани
    int count_of_vertices;      // количество вершин грани
} polygon;                      // грань(полигон)

typedef struct {
    double *vertices;           // массив вершин
    polygon *polygons;          // массив граней
    unsigned total_vertices;    // кол-во вершин
    unsigned total_polygons;    // кол-во граней
} Model;

void s21_parser(Model *model);
void s21_cleaner(Model *model);

#endif // PARCER_H
