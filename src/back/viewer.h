#ifndef SRC_VIEWER_H_
#define SRC_VIEWER_H_


#include <stdio.h>
#include <stdlib.h>

// рёбра твои
typedef struct {
    int *numbers_of_vertices;   // массив номеров вершин грани
    int count_of_vertices;      // количество вершин грани
} Polygon; 

// typedef struct {
//     double x;
//     double y;
//     double z;
// } Facet;

// вершины
typedef struct {
    double x;
    double y;
    double z;
} Vertex;

typedef struct {
    Vertex *vertices;
    Polygon *facets;
    unsigned int vertex_count;  // кол во вершин
    unsigned int facets_count;  // кол во граней
} Model;

void s21_parse_file(const char *filename, Model *model);
void s21_get_vector(Model *model, char *line);
void s21_get_facet(Model *model, char *line);





void moveX();
void moveY();
void moveZ();
void rotateX();
void rotateY();
void rotateZ();


#endif  // SRC_VIEWER_H_