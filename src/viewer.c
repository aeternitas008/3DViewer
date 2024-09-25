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
            model->vertex_count+1;
        } else if (line[0] == 'f' && line[1] == ' ') {
            model->facets_count++;
        }
    }
    fclose(file);

}
// обработка ошибок
void s21_parse_file_two(const char *filename, Model *model){
    FILE *file =fopen(filename, "r");
    if (file== NULL){
        perror("error");
        return;
    }

    fclose(file);

}