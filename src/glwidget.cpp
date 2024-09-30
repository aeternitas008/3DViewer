#include "glwidget.h"

// конструктор модуля GLWidget
GLWidget::GLWidget(QWidget* parent) : QOpenGLWidget(parent)
{
    s21_cleaner(&model);
    s21_parser(&model);

    // qDebug("HELLO");
    // qDebug()<<QString::number(model.polygons[0].numbers_of_vertices[0]);

}

void GLWidget::initializeGL()
{
    // работа с матрицами
    glMatrixMode(GL_PROJECTION);  // выбираем матрицу
    glLoadIdentity();             // загружаем единичную матрицу?

    // определяем проекцию и систему координат (xLeft,xRight,yBottom,yTop,zNear,zFar)
    // умножает текущую матрицу на орфографическую матрицу
    // glOrtho(-3, 3, -3, 3, 1, 7);  // центральная проекция
    glFrustum(-1, 1, -1, 1, 1, 7);  // параллельная проекция

    glMatrixMode(GL_MODELVIEW);  // выбираем матрицу
    glLoadIdentity();
    glTranslated(0, 0, -3);

    glEnable(GL_DEPTH_BUFFER_BIT);

}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void GLWidget::paintGL()
{
    if(model.vertices)
    {
        // qDebug("PAINT_GL");

        //задам цвет и очищаем экран в этот цвет
        glClearColor(property.backColor[0], property.backColor[1], property.backColor[2], 0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // задаём цвет для рисования
        glColor3fv(property.lineColor);

        // настройки линий
        glLineWidth(property.lineWidth);          // толщина линий

        if(property.lineType) {
            glLineStipple(1, 0x000F);              // прерывистость линий
            glEnable(GL_LINE_STIPPLE);             // включает рисование прерывистой линии
        }// возможно сделать property.lineType = 0x000F || 0xFFFF и вставить в glLineStipple (убрать иф)

        // загружаем координаты точек в вершинный буфер
        glVertexPointer(3, GL_DOUBLE, 0, model.vertices);

        glEnableClientState(GL_VERTEX_ARRAY);     // разрешаем OpenGL использовать вершинный буфер

            // РИСУЕМ ПОЛИГОНЫ
            for(unsigned i = 0; i < model.total_polygons; i++)
            {
                glDrawElements( GL_LINE_LOOP, model.polygons[i].count_of_vertices,
                                GL_UNSIGNED_INT, model.polygons[i].numbers_of_vertices);
            }

            if(property.pointType) {

                // настройки точек
                glPointSize(property.pointSize);  // размер точек
                glColor3fv(property.pointColor);  // задаём цвет для рисования точек

                if(property.pointType > 1) {
                    glEnable(GL_POINT_SMOOTH);    // форма точек (без этого квадратные)
                }

                // РИСУЕМ ТОЧКИ
                // glDrawArrays(GL_POINTS, 1, model.total_vertices);
                glDrawElements(GL_POINTS, 1, GL_UNSIGNED_INT, model.polygons[0].numbers_of_vertices);
            }

        glDisableClientState(GL_VERTEX_ARRAY);    // выключаем вершинный буфер

        glFlush(); // принудительно выполняет функции OpenGL в конечное время
    }
}

GLWidget::~GLWidget()
{
    s21_cleaner(&model);
}
