#include "parcer.h"
#include <string.h>

void print_extremum(Model model) {
    printf("max x y z: %f %f %f\n", model.max[0], model.max[1], model.max[2]);
    printf("min x y z: %f %f %f\n", model.min[0], model.min[1], model.min[2]);
}

void print_model(Model model) {
        printf("count_v: %d\n", model.total_vertices);
    for(unsigned x = 3; x < (model.total_vertices + 1)*3; x=x+3) {
        printf("v%d: %f ", x/3, model.vertices[x ]);
        printf("%f ", model.vertices[x + 1]);
        printf("%f ", model.vertices[x + 2]);
        printf("\n");
    }
    printf("polygons\n");
        printf("count_f: %d\n", model.polygons_count);
    for(unsigned x = 0; x < model.polygons_count; x++) {
        printf("f%d: ", x);
        for(int y = 0; y < model.polygons[x].count_of_vertices; y++) {
            printf("%d ", model.polygons[x].numbers_of_vertices[y]);
        }
        printf("\n");
    }

    // printf("max x y z: %f %f %f\n", model.max[0], model.max[1], model.max[2]);
    // printf("min x y z: %f %f %f\n", model.min[0], model.min[1], model.min[2]);
}


int count_groups(const char *line) {
    int count_of_vertices = 0;  // Счетчик групп значений
    int in_group = 0;  // Флаг, указывающий, находимся ли мы внутри группы
    // Пройдем по строке, начиная с третьего символа, чтобы пропустить 'f '.
    for (const char *tmp = line + 2; *tmp != '\0'; tmp++) {
        if (*tmp != ' ' && !in_group) {
            // Если встретили не пробел и ранее не были в группе, начинаем новую группу.
            in_group = 1;
            count_of_vertices++;
        } else if (*tmp == ' ') {
            // Если встретили пробел, завершаем группу.
            in_group = 0;
        }
    }
    return count_of_vertices;
}


// обработка ошибок
void s21_parser2(const char *filename, Model *model){
    FILE *file =fopen(filename, "r");
    if (file== NULL){
        perror("error");
        return;
    }

    //вершины начинаем с 1 чтобы было удобно строить грани
    model->total_vertices=0;
    model->polygons_count=0;

    char line[255];
    while (fgets(line, sizeof(line), file)){
        if(line[0]== 'v' && line[1] == ' '){
            model->total_vertices++;
        } else if (line[0] == 'f' && line[1] == ' ') {
            model->polygons_count++;
        }
    }

    rewind(file);
    model->vertices = (double *)calloc((model->total_vertices + 1) * 3, sizeof(double));
    model->polygons = (Polygon *)malloc(model->polygons_count * sizeof(Polygon));
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

// обработка ошибок
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

// обработка ошибок
void s21_get_facet(Model *model, char *line, int id_facet){

    char *ptr = (char *)line + 2;  // Пропускаем 'f ' в начале строки
    char *token = strtok(ptr, " ");  // Разбиваем строку по пробелам
    int count = 0;  // Инициализируем счетчик вершин

    while (token != NULL) {
        // Преобразуем оставшуюся часть в индекс вершины
        model->polygons[id_facet].numbers_of_vertices[count++] = atoi(token);
        // Переходим к следующему токену
        token = strtok(NULL, " ");
    }
}

void s21_cleaner(Model *model) {
    // clean array of polygon's
    if(model->polygons) {
        for(size_t i = 0; i < model->polygons_count; i++){
            free(model->polygons[i].numbers_of_vertices);
        }
        free(model->polygons);
    }
    // clean array of vertice's
    if(model->vertices) {
        free(model->vertices);
    }
    model->total_vertices = 0;
    model->polygons_count = 0;
} // s21_cleaner


void s21_parser(Model *model) {
    double arr_ver[] = {0.5, 0.5, 0.5,
                        0.5, -0.5, 0.5,
                        -0.5, -0.5, 0.5,
                        -0.5, 0.5, 0.5,
                        -0.5, 0.5, -0.5,
                        -0.5, -0.5, -0.5,
                        0.5, -0.5, -0.5,
                        0.5, 0.5, -0.5,
                        };

    int f[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {1, 2, 7, 8}, {3, 4, 5, 6}};
    // total number of vertices and polygons
    model->total_vertices = 8;
    model->polygons_count = 4;
    // ------------------------------------------
    // allocate memory for the vertex array
    model->vertices = (double *)calloc((model->total_vertices + 1) * 3, sizeof(double));

    // fill the vertex array
    for(size_t i = 3; i < (model->total_vertices + 1) * 3; i++) {
        model->vertices[i] = arr_ver[i - 3];
    }
    // ------------------------------------------
    // allocate memory for the polygon array
    model->polygons = (Polygon *)malloc(model->polygons_count * sizeof(Polygon));
    // fill the polygon array
    // fill the number of vertices of each polygon
    for(size_t i = 0; i < model->polygons_count; i++) {
        model->polygons[i].count_of_vertices = 4;
    }
    // allocate memory for vertex arrays in each polygon
    for(size_t i = 0; i < model->polygons_count; i++) {
        model->polygons[i].numbers_of_vertices = (int *)malloc(model->polygons[i].count_of_vertices * sizeof(int));
    }
    // fill the vertex arrays of each polygon
    for(size_t i = 0; i < model->polygons_count; i++) {
        for(int j = 0; j < model->polygons[i].count_of_vertices; j++) {
            model->polygons[i].numbers_of_vertices[j] = f[i][j];
        }
    }
}
