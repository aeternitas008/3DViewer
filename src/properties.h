#ifndef PROPERTIES_H
#define PROPERTIES_H

typedef struct {
    int projection_type;
    int line_type;
    int line_color;
    int line_width;
    int point_type;
    int point_color;
    int point_size;
    int back_color;
} Properties;

// 
void set_properties(Properties props);

void set_start_props(Properties props);
#endif // PROPERTIES_H