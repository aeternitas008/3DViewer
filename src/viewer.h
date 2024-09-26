#ifndef SRC_VIEWER_H_
#define SRC_VIEWER_H_


#include <stdio.h>
#include <stdlib.h>


// вершины
typedef struct {
    double x;
    double y;
    double z;
} Vertex;
typedef struct {
    Vertex *vertices;
    float *facets;
    unsigned int vertex_count;  // кол во вершин
    unsigned int facets_count;  // кол во граней
} Model;

void s21_parse_file(const char *filename, Model *model);
void s21_parse_file_v(Model *model, char *line);
void s21_parse_file_f(Model *model, char *line);





void moveX();
void moveY();
void moveZ();
void rotateX();
void rotateY();
void rotateZ();


#endif  // SRC_VIEWER_H_