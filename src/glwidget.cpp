#include "glwidget.h"

// конструктор модуля GLWidget
GLWidget::GLWidget(QWidget* parent) : QOpenGLWidget(parent)
{
    s21_cleaner(&model);
    // s21_parser(&model);
    // qDebug()<<QString::number(model.polygons[0].numbers_of_vertices[0]);

}

void GLWidget::initializeGL()
{
    // работа с матрицами
    glMatrixMode(GL_PROJECTION);  // выбираем матрицу
    glLoadIdentity();             // загружаем единичную матрицу?
   
    // тут наоборот ortho это параллельная а frustum это центральная/перспективная

    // @todo как обновить контекст отображения в процессе работы?
    if(property.projection_type) {
    // определяем проекцию и систему координат (xLeft,xRight,yBottom,yTop,zNear,zFar)
    // умножает текущую матрицу на орфографическую матрицу
        glOrtho(-3, 3, -3, 3, 1, 7);  // ortho это параллельная 
    } else {
        glFrustum(-1, 1, -1, 1, 1, 7);  // frustum это центральная
    }

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
        glClearColor(property.back_color[0], property.back_color[1], property.back_color[2], 0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // задаём цвет для рисования
        glColor3fv(property.line_color);

        // настройки линий
        glLineWidth(property.line_width);          // толщина линий

        // @todo may be shorter
        if(property.line_type == 1) {
            glLineStipple(1, 0x000F);              // прерывистость линий
            glEnable(GL_LINE_STIPPLE);             // включает рисование прерывистой линии
        } else {
            glLineStipple(1, 0xFFFF);              
            glDisable(GL_LINE_STIPPLE);  
        }
            // возможно сделать property.lineType = 0x000F || 0xFFFF и вставить в glLineStipple (убрать иф)

        // загружаем координаты точек в вершинный буфер
        glVertexPointer(3, GL_DOUBLE, 0, model.vertices);

        glEnableClientState(GL_VERTEX_ARRAY);     // разрешаем OpenGL использовать вершинный буфер

            // РИСУЕМ ПОЛИГОНЫ
            for(unsigned i = 0; i < model.polygons_count; i++)
            {
                glDrawElements( GL_LINE_LOOP, model.polygons[i].count_of_vertices,
                                GL_UNSIGNED_INT, model.polygons[i].numbers_of_vertices);
            }

            if(property.point_type) {

                // настройки точек
                glPointSize(property.point_size);  // размер точек
                glColor3fv(property.point_color);  // задаём цвет для рисования точек

                if(property.point_type > 1) {
                    glEnable(GL_POINT_SMOOTH);    // форма точек (без этого квадратные)
                } else if(property.point_type == 1) {
                    glDisable(GL_POINT_SMOOTH);    // форма точек (без этого квадратные)
                } 

                // РИСУЕМ ТОЧКИ
                glDrawArrays(GL_POINTS, 1, model.total_vertices);
            }

        glDisableClientState(GL_VERTEX_ARRAY);    // выключаем вершинный буфер

        glFlush(); // принудительно выполняет функции OpenGL в конечное время
    }
}

GLWidget::~GLWidget()
{
    s21_cleaner(&model);
}