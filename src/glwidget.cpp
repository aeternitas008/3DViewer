#include "glwidget.h"

GLWidget::GLWidget(QWidget* parent) : QOpenGLWidget(parent)
{

}

void GLWidget::initializeGL()
{
    glMatrixMode(GL_PROJECTION);  // выбираем матрицу
    glLoadIdentity();             // загружаем единичную матрицу?
    //glOrtho(-1, 1, -1, 1, 1, 3);  // (xLeft,xRight,yBottom,yTop,zNear,zFar) умножает текущую матрицу на орфографическую матрицу
    // определяет систему координат
    glFrustum(-1, 1, -1, 1, 1, 32);
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

double arr_ver[] = {0.5, 0.5, -1.5,
                    0.5, -0.5, -1.5,
                    -0.5, -0.5, -1.5,
                    -0.5, 0.5, -1.5,
                    -0.5, 0.5, -2.5,
                    -0.5, -0.5, -2.5,
                    0.5, -0.5, -2.5,
                    0.5, 0.5, -2.5,
                    };

double arr_pol[] = {0.5, 0.5, -1.5, -0.5, 0.5, -1.5,
                    -0.5, 0.5, -2.5, 0.5, 0.5, -2.5,
                    0.5, -0.5, -1.5,
                    -0.5, -0.5, -1.5,
                    -0.5, 0.5, -1.5,
                    -0.5, 0.5, -2.5,
                    -0.5, -0.5, -2.5,
                    0.5, -0.5, -2.5,
                    0.5, 0.5, -2.5,
                    };

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
    glVertexPointer(3, GL_DOUBLE, 0, &arr_ver);

    glEnableClientState(GL_VERTEX_ARRAY);  // разрешаем OpenGL использоввать вершинный буфер

    glColor3d(1, 1, 1);         // цвет точек
    glPointSize(5);            // размер точек
    glEnable(GL_POINT_SMOOTH);  // форма точек (без этого квадратные)

    glDrawArrays(GL_POINTS, 0, 8);

    glColor3d(0.8, 1, 0);   // цвета проще задать через массив glColor3dv(color_array);
    glLineWidth(1);

    glDrawArrays(GL_LINE_LOOP, 0, 8);

    /*
         * void glDrawArrays
         *   GLenum  mode,  - тип рисуемого примитива
         *   GLint   first, - стартовая точка
         *   GLsizei count  - количство элементов массива на точку
         */
    glDisableClientState(GL_VERTEX_ARRAY); // выключаем вершинный буфер

    glVertexPointer(3, GL_DOUBLE, 0, &arr_pol);

    glEnableClientState(GL_VERTEX_ARRAY);

    glColor3d(0, 0, 1);
    glLineWidth(5);

    glDrawArrays(GL_LINES, 0, 4);

    glDisableClientState(GL_VERTEX_ARRAY); // выключаем вершинный буфер

    glFlush(); // принудительно выполняет функции OpenGL в конечное время

}

/*
 *  glFrustum(-1, 1, -1, 1, 1, 2); параллельная проекция
 *  glOrtho(-1, 1, -1, 1, 1, 2); центральная проекция
 */
