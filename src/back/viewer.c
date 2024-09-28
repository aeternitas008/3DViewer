#include "viewer.h"

// обработка ошибок
void s21_parse_file(const char *filename, Model *model){
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
    model->vertices = (Vertex *)malloc(model->vertex_count * sizeof(Vertex));
    model->facets = (Polygon *)malloc(model->facets_count * sizeof(Polygon));
    int id_vertex = 1;
    int id_facet = 0;
    while (fgets(line, sizeof(line), file)){
        if(line[0]=='v' && line[1] == ' '){
            s21_parse_file_v(model, line, id_vertex);
            id_vertex++;
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
    Vertex vertex;
    char *ptr = line + 2;
    vertex.x = strtod(ptr, &ptr);
    vertex.y = strtod(ptr, &ptr);
    vertex.z = strtod(ptr, &ptr);
    model->vertices[id_vertex] = vertex;
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