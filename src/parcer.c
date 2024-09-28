#include "parcer.h"

void s21_parser(Model *model) {

    double arr_ver[] = {0.5, 0.5, -1.5,
                        0.5, -0.5, -1.5,
                        -0.5, -0.5, -1.5,
                        -0.5, 0.5, -1.5,
                        -0.5, 0.5, -2.5,
                        -0.5, -0.5, -2.5,
                        0.5, -0.5, -2.5,
                        0.5, 0.5, -2.5,
                        };

    int f[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {1, 2, 7, 8}, {3, 4, 5, 6}};

    // ------------------------------------------
    // ------------------------------------------

    // total number of vertices and polygons
    model->total_vertices = 8;
    model->total_polygons = 4;

    // ------------------------------------------

    // allocate memory for the vertex array
    model->vertices = (double *)calloc((model->total_vertices + 1) * 3, sizeof(double));

    // fill the vertex array
    for(size_t i = 3; i < (model->total_vertices + 1) * 3; i++) {
        model->vertices[i] = arr_ver[i - 3];
    }

    // ------------------------------------------

    // allocate memory for the polygon array
    model->polygons = (polygon *)malloc(model->total_polygons * sizeof(polygon));

    // fill the polygon array

    // fill the number of vertices of each polygon
    for(size_t i = 0; i < model->total_polygons; i++) {
        model->polygons[i].count_of_vertices = 4;
    }

    // allocate memory for vertex arrays in each polygon
    for(size_t i = 0; i < model->total_polygons; i++) {
        model->polygons[i].numbers_of_vertices = (int *)malloc(model->polygons[i].count_of_vertices * sizeof(int));
    }

    // fill the vertex arrays of each polygon
    for(size_t i = 0; i < model->total_polygons; i++) {
        for(int j = 0; j < model->polygons[i].count_of_vertices; j++) {
            model->polygons[i].numbers_of_vertices[j] = f[i][j];
        }
    }

} // s21_parser

void s21_cleaner(Model *model) {

    // clean array of polygon's
    if(model->polygons) {

        for(size_t i = 0; i < model->total_polygons; i++){
            free(model->polygons[i].numbers_of_vertices);
        }
        free(model->polygons);

    }

    // clean array of vertice's
    if(model->vertices) {
        free(model->vertices);
    }

    // null all counter's
    model->total_vertices = 0;
    model->total_polygons = 0;

} // s21_cleaner
