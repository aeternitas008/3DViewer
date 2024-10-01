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

// typedef struct {
//     int *numbers_of_vertices;   // массив номеров вершин грани
//     int count_of_vertices;      // количество вершин грани
// } polygon;                      // грань(полигон)

// typedef struct {
//     double *vertices;           // массив вершин
//     Polygon *polygons;          // массив граней
//     unsigned total_vertices;    // кол-во вершин
//     unsigned total_polygons;    // кол-во граней
// } Model;


typedef struct {
    int *numbers_of_vertices;   // массив номеров вершин грани
    int count_of_vertices;      // количество вершин грани
} Polygon; 


typedef struct {
    double *vertices;
    Polygon *polygons;
    unsigned int total_vertices;  // кол во вершин
    unsigned int polygons_count;  // кол во граней
    double max[3];
    double min[3];
} Model;

void s21_parser(Model *model);
void s21_parser2(const char *filename, Model *model);
void s21_get_vector(Model *model, char *line, int x);
void s21_get_facet(Model *model, char *line, int x);

void s21_cleaner(Model *model);

void print_model(Model model);

#endif // PARCER_H
