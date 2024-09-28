#include "glwidget.h"

// struct View
// {
//     float backColor[3];  // цвет фона (R, G, B, Прозрачность)           / glClearColor(0-1, 0-1, 0-1, 0-1) (тип GLclampf)
//     float lineColor[3];  // линии: цвет                                 / glColor3fv(*array) || glColor3f(R, G, B) (тип double)
//     float pointColor[3]; // точки: цвет                                 / glColor3fv(*array) || glColor3f(R, G, B) (тип double)

//     float pointSize;      // точки: размер                              / glPointSize(float);
//     int pointType;        // точки: тип (нет, квадратные, круглые)     / не отрисовывать || по умолчанию || glEnable(GL_POINT_SMOOTH);

//     float lineWidth;      // линии: толщина                             / glLineWidth(float)
//     bool lineType;        // линии: тип (сплошная, штриховка)           / по умолчанию || glEnable(GL_LINE_STIPPLE)+ glLineStipple(1, 000F)

//     bool ortho;           // тип проекции (параллельная и центральная)  / glFrustum() || glOrtho()
// };

GLWidget::GLWidget(QWidget* parent) : QOpenGLWidget(parent)
{
    // property = {{0}, {0.8, 0.9, 0}, {1, 1, 1}, 5.0, 2, 1.0, 0, 0};
    // qDebug("HELLO");
    // qDebug()<<QString::number(model.polygons[0].numbers_of_vertices[0]);

}

void GLWidget::initializeGL()
{
    // qDebug("INITIALIZE_GL");

    glMatrixMode(GL_MODELVIEW);  // выбираем матрицу
    glLoadIdentity();             // загружаем единичную матрицу?

    // определяем проекцию и систему координат (xLeft,xRight,yBottom,yTop,zNear,zFar)
    // умножает текущую матрицу на орфографическую матрицу

    // glOrtho(-1, 1, -1, 1, 1, 3);  // центральная проекция
    glFrustum(-1, 1, -1, 1, 1, 3);  // параллельная проекция
}

void GLWidget::resizeGL(int w, int h)
{
    // qDebug("RESIZE_GL");

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
        }

        // загружаем координаты точек в вершинный буфер
        glVertexPointer(3, GL_DOUBLE, 0, model.vertices);

        glEnableClientState(GL_VERTEX_ARRAY);     // разрешаем OpenGL использоввать вершинный буфер

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
                glDrawArrays(GL_POINTS, 1, model.total_vertices);
            }

        glDisableClientState(GL_VERTEX_ARRAY);    // выключаем вершинный буфер

        glFlush(); // принудительно выполняет функции OpenGL в конечное время
    }
}

void GLWidget::on_paintButton_clicked()
{
    update();
    // qDebug("UPDATE");
}

void GLWidget::on_openButton_clicked()
{
    s21_parser(&model);
    // qDebug("PAINT_BUTTON");
}

GLWidget::~GLWidget()
{
    s21_cleaner(&model);
}
