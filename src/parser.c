#include "parser.h"
#include <string.h>

int count_groups(const char *line) {
    int count_of_vertices = 0;  
    int in_group = 0;  
    for (const char *tmp = line + 2; *tmp != '\0'; tmp++) {
        if (*tmp != ' ' && !in_group) {
            in_group = 1;
            count_of_vertices++;
        } else if (*tmp == ' ') {
            in_group = 0;
        }
    }
    return count_of_vertices;
}


void s21_parser(const char *filename, Model *model){
    FILE *file =fopen(filename, "r");
    if (file== NULL){
        perror("error");
        return;
    }

    //вершины начинаем с 1 чтобы было удобно строить грани
    model->total_vertices = 0;
    model->total_polygons = 0;

    char line[255];
    while (fgets(line, sizeof(line), file)){
        if(line[0]== 'v' && line[1] == ' '){
            model->total_vertices++;
        } else if (line[0] == 'f' && line[1] == ' ') {
            model->total_polygons++;
        }
    }

    rewind(file);
    model->vertices = (double *)calloc((model->total_vertices + 1) * 3, sizeof(double));
    model->polygons = (Polygon *)malloc(model->total_polygons * sizeof(Polygon));
    model->vertices[0] = 0;
    model->vertices[1] = 0;
    model->vertices[2] = 0;
    int id_vertex = 1;
    int id_facet = 0;
    while (fgets(line, sizeof(line), file)){
        if(line[0]=='v' && line[1] == ' '){
            s21_get_vector(model, line, id_vertex);
            id_vertex ++;
        } else if (line[0] == 'f' && line[1] == ' ') {
            int count_of_vertices = 0;	// количество вхождений подстроки
            // ищем группы
            count_of_vertices = count_groups(line);
            model->polygons[id_facet].count_of_vertices = count_of_vertices;
            model->polygons[id_facet].numbers_of_vertices = (int * )malloc(count_of_vertices * sizeof(int));
            s21_get_facet(model, line, id_facet);
            id_facet++;
        }
    }
    fclose(file);
}

void set_extremum(Model *model) {
    for (int i = 0; i < 3; i++) {
        model->max[i] = model->vertices[i + 3];
        model->min[i] = model->vertices[i + 3];
    }
}

void check_extremum(Model *model, int id_vertex) {
    for (int i = 0; i < 3; i++) {
        if ( model->vertices[id_vertex * 3 + i] > model->max[i]) model->max[i] = model->vertices[id_vertex * 3 + i] ;
        if ( model->vertices[id_vertex * 3 + i] < model->min[i]) model->min[i] = model->vertices[id_vertex * 3 + i] ;
    }
}

void s21_get_vector(Model *model, char *line, int id_vertex){
    char *ptr = line + 2;
    for (int i = id_vertex * 3; i < id_vertex * 3 + 3; i++) {
        model->vertices[i] = strtod(ptr, &ptr);
    }

    if (id_vertex == 1) {
        set_extremum(model);
    } else {
        check_extremum(model, id_vertex);
    }

}

void s21_get_facet(Model *model, char *line, int id_facet){

    char *ptr = (char *)line + 2;  
    char *token = strtok(ptr, " ");  
    int count = 0;  

    while (token != NULL) {
        model->polygons[id_facet].numbers_of_vertices[count++] = atoi(token);
        token = strtok(NULL, " ");
    }
}

void s21_cleaner(Model *model) {
    if(model->polygons) {
        for(size_t i = 0; i < model->total_polygons; i++){
            free(model->polygons[i].numbers_of_vertices);
        }
        free(model->polygons);
    }
    if(model->vertices) {
        free(model->vertices);
    }
    model->total_vertices = 0;
    model->total_polygons = 0;
}
