#include "glwidget.h"

GLWidget::GLWidget(QWidget* parent) : QOpenGLWidget(parent)
{
    s21_parser(&model);
    // qDebug()<<QString::number(model.polygons[0].numbers_of_vertices[0]);

}

void GLWidget::initializeGL()
{
    glMatrixMode(GL_PROJECTION);  // выбираем матрицу
    glLoadIdentity();             // загружаем единичную матрицу?

    // определяем проекцию и систему координат (xLeft,xRight,yBottom,yTop,zNear,zFar)
    // умножает текущую матрицу на орфографическую матрицу

    // glOrtho(-1, 1, -1, 1, 1, 3);  // центральная проекция
    glFrustum(-1, 1, -1, 1, 1, 3);  // параллельная проекция
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void GLWidget::paintGL()
{
        // задает цвет, в который окно будет окрашиваться при его очистке (R, G, B, Прозрачность)
    glClearColor(0, 0, 0, 0);
        // очищает окно (тем самым окрашивая его в выбранный выше цвет)
        // цвет может быть изменён повторным вызовом glClearColor
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        /*
         * void glVertexPointer
         *  GLint   size,          - количество цифр на одну вершину
         *  GLenum  type,          - тип данных в массиве
         *  GLsizei stride,        - смещение?
         *  const GLvoid  *pointer - указатель на массив
         */

    glVertexPointer(3, GL_DOUBLE, 0, model.vertices);

    glEnableClientState(GL_VERTEX_ARRAY);  // разрешаем OpenGL использоввать вершинный буфер

    glColor3d(0.8, 0.9, 0);                // цвет линий
    glLineWidth(1);                        // толщина линий

    for(unsigned i = 0; i < model.total_polygons; i++)
    {
        glDrawElements( GL_LINE_LOOP, model.polygons[i].count_of_vertices,
                        GL_UNSIGNED_INT, model.polygons[i].numbers_of_vertices); // РИСУЕМ ПОЛИГОНЫ
    }

    glColor3d(1, 1, 1);                    // цвет точек
    glPointSize(5);                        // размер точек
    glEnable(GL_POINT_SMOOTH);             // форма точек (без этого квадратные)

        /*
         * void glDrawArrays
         *   GLenum  mode,  - тип рисуемого примитива
         *   GLint   first, - стартовая точка
         *   GLsizei count  - количство элементов массива на точку
         */

    glDrawArrays(GL_POINTS, 1, 8);  // РИСУЕМ ТОЧКИ

    glDisableClientState(GL_VERTEX_ARRAY);  // выключаем вершинный буфер


    glFlush(); // принудительно выполняет функции OpenGL в конечное время

}

GLWidget::~GLWidget()
{
    s21_cleaner(&model);
}
