#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *numbers_of_vertices;   // массив номеров вершин грани
    int count_of_vertices;      // количество вершин грани
} Polygon; 


typedef struct {
    double *vertices;
    Polygon *polygons;
    unsigned int total_vertices;  // кол во вершин
    unsigned int total_polygons;  // кол во граней
    double max[3];
    double min[3];
} Model;

bool s21_parser(const char *filename, Model *model);
void s21_get_vector(Model *model, char *line, int x);
void s21_get_facet(Model *model, char *line, int x);

void s21_cleaner(Model *model);

// void print_model(Model model);
// void print_extremum(Model model);
#endif // PARCER_H
