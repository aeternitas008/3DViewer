#ifndef PROPERTIES_H
#define PROPERTIES_H


typedef struct {
    int projection_type;
    int line_type;
    float line_color[3];
    float line_width;
    int point_type;
    float point_color[3];
    float point_size;
    float back_color[3];
} Properties;

// 
void set_properties(Properties props);

Properties get_start_props();
#endif // PROPERTIES_H