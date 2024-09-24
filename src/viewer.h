#ifndef SRC_VIEWER_H_
#define SRC_VIEWER_H_
// вершины
typedef struct {
    double x;
    double y;
    double z;
} Vertex;
// центр для перемещения
typedef struct {
  double x_center;
  double y_center;
  double z_center;
} centers;
// для уменьшения 
typedef struct {
  double x_max;
  double x_min;
  double y_max;
  double y_min;
  double z_max;
  double z_min;
} max_min;


typedef struct {
    Vertex *vertices;
    int vertex_count;  // кол во вершин
} Model;


#endif  // SRC_VIEWER_H_