#include "parcer.h"
#include <string.h>
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
    model->vertex_count = 8;
    model->facets_count = 4;

    // ------------------------------------------

    // allocate memory for the vertex array
    model->vertices = (double *)calloc((model->vertex_count + 1) * 3, sizeof(double));

    // fill the vertex array
    for(size_t i = 3; i < (model->vertex_count + 1) * 3; i++) {
        model->vertices[i] = arr_ver[i - 3];
    }

    // ------------------------------------------

    // allocate memory for the polygon array
    model->facets = (Polygon *)malloc(model->facets_count * sizeof(Polygon));


    // fill the polygon array

    // fill the number of vertices of each polygon
    for(size_t i = 0; i < model->facets_count; i++) {
        model->facets[i].count_of_vertices = 4;
    }

    // allocate memory for vertex arrays in each polygon
    for(size_t i = 0; i < model->facets_count; i++) {
        model->facets[i].numbers_of_vertices = (int *)malloc(model->facets[i].count_of_vertices * sizeof(int));
    }

    // fill the vertex arrays of each polygon
    for(size_t i = 0; i < model->facets_count; i++) {
        for(int j = 0; j < model->facets[i].count_of_vertices; j++) {
            model->facets[i].numbers_of_vertices[j] = f[i][j];
        }
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


// обработка ошибок
void s21_parser2(const char *filename, Model *model){
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
            char *tmp = (char *)line;	// временный указатель
            // Пропускаем 'f ' в начале строки
            char *token = strtok(tmp, " ");
            // ищем вхождения
            while (token != NULL)
            {
                count_of_vertices++;
                token = strtok(NULL, " ");
            }
            model->facets[id_facet].count_of_vertices = count_of_vertices;
            model->facets[id_facet].numbers_of_vertices = (int * )malloc(count_of_vertices * sizeof(int));
            
            s21_get_facet(model, line, id_facet);
            id_facet++;
        }
    }

    fclose(file);

    for(int x = 0; x < model->vertex_count * 3; x++) {
        printf("%f ", model->vertices[x]);
        printf("\n");
    }

    // for(int x = 0; x < model->facets_count * 3; x++) {
    //     printf("%f ", model->facets.[x]);
    //     printf("\n");
    // }
}

// обработка ошибок
void s21_get_vector(Model *model, char *line, int id_vertex){
    // Vertex vertex;
    char *ptr = line + 2;
    int x = 0;
    model->vertices[id_vertex * 3 + x++] = strtod(ptr, &ptr);
    model->vertices[id_vertex * 3 + x++] = strtod(ptr, &ptr);
    model->vertices[id_vertex * 3 + x++] = strtod(ptr, &ptr);
}

// обработка ошибок
void s21_get_facet(Model *model, char *line, int id_facet){
    char *ptr = (char *)line + 2;  // Пропускаем 'f ' в начале строки
    char *token = strtok(ptr, " ");  // Разбиваем строку по пробелам

    int count = 0;  // Инициализируем счетчик вершин

    // Пока есть токены (группы вида v/vt/vn)
    while (token != NULL) {
        // Преобразуем строку в число (индекс вершины)
        model->facets[id_facet].numbers_of_vertices[count++] = atoi(token);
        
        // Переходим к следующему токену
        token = strtok(NULL, " ");
    }
}

// void s21_cleaner(Model *model) {

//     // clean array of polygon's
//     if(model->facets) {

//         for(size_t i = 0; i < model->facets_count; i++){
//             free(model->facets[i].numbers_of_vertices);
//         }
//         free(model->facets);

//     }

//     // clean array of vertice's
//     if(model->vertices) {
//         free(model->vertices);
//     }

//     // null all counter's
//     model->vertex_count = 0;
//     model->facets_count = 0;

// } // s21_cleaner
