#include "viewer.h"
// обработка ошибок
void s21_parse_file(const char *filename, Model *model){
    FILE *file =fopen(filename, "r");
    if (file== NULL){
        perror("error");
        return;
    }
    model->vertex_count=0;
    model->facets_count=0;
    char line[255];
    while (fgets(line, sizeof(line), file)){
        if(line[0]=='v' && line[1] == ' '){
            model->vertex_count++;
        } else if (line[0] == 'f' && line[1] == ' ') {
            model->facets_count++;

        }
    }

    rewind(file);
    model->vertices = (Vertex *)malloc(model->vertex_count * sizeof(Vertex));
    model->facets = (float *)malloc(model->facets_count * sizeof(float));
    while (fgets(line, sizeof(line), file)){
        if(line[0]=='v' && line[1] == ' '){
            s21_parse_file_v(model, line);
        } else if (line[0] == 'f' && line[1] == ' ') {
            s21_parse_file_f(model, line);
        }
    }
    fclose(file);

}
// обработка ошибок
void s21_parse_file_v(Model *model, char *line){
    Vertex vertex;
    char *ptr = line + 2;
    vertex.x = strtod(ptr, &ptr);
    vertex.y = strtod(ptr, &ptr);
    vertex.z = strtod(ptr, &ptr);
    model->vertices[model->vertex_count++] = vertex;
}