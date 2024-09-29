#include "parcer.h"

// void s21_parser(Model *model) {



    // double arr_ver[] = {0.5, 0.5, -1.5,
    //                     0.5, -0.5, -1.5,
    //                     -0.5, -0.5, -1.5,
    //                     -0.5, 0.5, -1.5,
    //                     -0.5, 0.5, -2.5,
    //                     -0.5, -0.5, -2.5,
    //                     0.5, -0.5, -2.5,
    //                     0.5, 0.5, -2.5,
    //                     };

    // int f[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {1, 2, 7, 8}, {3, 4, 5, 6}};

    // // ------------------------------------------
    // // ------------------------------------------

    // // total number of vertices and polygons
    // model->total_vertices = 8;
    // model->total_polygons = 4;

    // // ------------------------------------------

    // // allocate memory for the vertex array
    // model->vertices = (double *)calloc((model->total_vertices + 1) * 3, sizeof(double));

    // // fill the vertex array
    // for(size_t i = 3; i < (model->total_vertices + 1) * 3; i++) {
    //     model->vertices[i] = arr_ver[i - 3];
    // }

    // // ------------------------------------------

    // // allocate memory for the polygon array
    // model->polygons = (polygon *)malloc(model->total_polygons * sizeof(polygon));

    // // fill the polygon array

    // // fill the number of vertices of each polygon
    // for(size_t i = 0; i < model->total_polygons; i++) {
    //     model->polygons[i].count_of_vertices = 4;
    // }

    // // allocate memory for vertex arrays in each polygon
    // for(size_t i = 0; i < model->total_polygons; i++) {
    //     model->polygons[i].numbers_of_vertices = (int *)malloc(model->polygons[i].count_of_vertices * sizeof(int));
    // }

    // // fill the vertex arrays of each polygon
    // for(size_t i = 0; i < model->total_polygons; i++) {
    //     for(int j = 0; j < model->polygons[i].count_of_vertices; j++) {
    //         model->polygons[i].numbers_of_vertices[j] = f[i][j];
    //     }
    // }

 // s21_parser

// void s21_cleaner(Model *model) {

//     // clean array of polygon's
//     if(model->polygons) {

//         for(size_t i = 0; i < model->total_polygons; i++){
//             free(model->polygons[i].numbers_of_vertices);
//         }
//         free(model->polygons);

//     }

//     // clean array of vertice's
//     if(model->vertices) {
//         free(model->vertices);
//     }

//     // null all counter's
//     model->total_vertices = 0;
//     model->total_polygons = 0;

// } // s21_cleaner


// обработка ошибок
void s21_parser(const char *filename, Model *model){
    FILE *file =fopen(filename, "r");
    if (file== NULL){
        perror("error");
        return;
    }

    //вершины начинаем с 1 чтобы было удобно строить грани
    model->vertex_count=1;
    model->facets_count=0;
    char line[255];
    while (fgets(line, sizeof(line), file)){
        if(line[0]== 'v' && line[1] == ' '){
            model->vertex_count++;
        } else if (line[0] == 'f' && line[1] == ' ') {
            model->facets_count++;
        }
    }

    rewind(file);
    model->vertices = (double *)malloc(model->vertex_count * sizeof(double) * 3 + 1);
    model->facets = (Polygon *)malloc(model->facets_count * sizeof(Polygon));
    int id_vertex = 1;
    int id_facet = 0;
    while (fgets(line, sizeof(line), file)){
        if(line[0]=='v' && line[1] == ' '){
            s21_parse_file_v(model, line, id_vertex);
            id_vertex ++;
        } else if (line[0] == 'f' && line[1] == ' ') {
            int count_of_vertices = 0;	// количество вхождений подстроки
            char *tmp = line;	// временный указатель
           
            // ищем вхождения
            while (( tmp = strstr(tmp, ' ')) != NULL)
            {
                count_of_vertices++;
            }
            model->facets[id_facet].count_of_vertices = count_of_vertices;
            model->facets[id_facet].numbers_of_vertices = (int * )malloc(count_of_vertices * sizeof(int));
            
            s21_parse_file_f(model, line, id_facet);
            id_facet++;
        }
    }
    fclose(file);

}

// обработка ошибок
void s21_get_vector(Model *model, char *line, int id_vertex){
    // Vertex vertex;
    char *ptr = line + 2;
    int x = 0;
    // vertex.x = strtod(ptr, &ptr);
    // vertex.y = strtod(ptr, &ptr);
    // vertex.z = strtod(ptr, &ptr);
    model->vertices[id_vertex * 3 + x++] = strtod(ptr, &ptr);
    model->vertices[id_vertex * 3 + x++] = strtod(ptr, &ptr);
    model->vertices[id_vertex * 3 + x++] = strtod(ptr, &ptr);
}

// обработка ошибок
void s21_get_facet(Model *model, char *line, int id_facet){
    Polygon facet;
    char *ptr = line + 2;
    int id_vertex, x = 0;
    while (ptr != NULL) {
        id_vertex = strtol(ptr, &ptr, 10);
        model->facets[id_facet].numbers_of_vertices[x++] = id_vertex;
    }
}

void s21_cleaner(Model *model) {

    // clean array of polygon's
    if(model->facets) {

        for(size_t i = 0; i < model->facets_count; i++){
            free(model->facets[i].numbers_of_vertices);
        }
        free(model->facets);

    }

    // clean array of vertice's
    if(model->vertices) {
        free(model->vertices);
    }

    // null all counter's
    model->vertex_count = 0;
    model->facets_count = 0;

} // s21_cleaner
