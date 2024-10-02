#ifndef PARCER_H
#define PARCER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *numbers_of_vertices;   // массив номеров вершин грани
    int count_of_vertices;      // количество вершин грани
} Polygon; 


typedef struct {
    double *vertices;
    Polygon *facets;
    unsigned int vertex_count;  // кол во вершин
    unsigned int facets_count;  // кол во граней
} Model;

void s21_parser(Model *model);
void s21_parser2(const char *filename, Model *model);
void s21_get_vector(Model *model, char *line, int x);
void s21_get_facet(Model *model, char *line, int x);

void s21_cleaner(Model *model);

void print_model(Model model);
void print_extremum(Model model);
#endif // PARCER_H
