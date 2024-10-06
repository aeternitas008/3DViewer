#include "glwidget.h"

// конструктор модуля GLWidget
GLWidget::GLWidget(QWidget* parent) : QOpenGLWidget(parent)
{
    // qDebug("HELLO");
    // qDebug()<<QString::number(model.polygons[0].numbers_of_vertices[0]);

}

void GLWidget::initializeGL()
{
    // qDebug("INITIALIZE");

    glEnable(GL_DEPTH_TEST);                // контролирует сравнение по глубине и обновление буфера глубины
    glEnable(GL_LINE_STIPPLE);              // включаем шаблонирование для линий
    glEnableClientState(GL_VERTEX_ARRAY);

}

void GLWidget::resizeGL(int w, int h)
{

    // qDebug("RESIZE");

    glViewport(0, 0, w, h);
}

void GLWidget::paintGL()
{
    // qDebug("PAINT_GL");

    if(model.vertices)
    {
    // ----- выставляем камеру -----

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(0.0, 0.0, 1.0 + property.scene, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // ----- выбираем проекцию -----

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        if(property.ortho) {
            glOrtho(-property.scene, property.scene, -property.scene, property.scene, 1, 10 + 2 * property.scene);
        } else {
            glFrustum(-1, 1, -1, 1, 1, 10 + 2 * property.scene);
        }

    // ----- задам цвет и очищаем экран в этот цвет -----

        glClearColor(property.backColor[0], property.backColor[1], property.backColor[2], 0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // --------------------------------------
    //          РИСУЕТ СЕТКУ КООРДИНАТ
    //          СЛУЖЕБНОЕ, НЕ В ПРОЕКТ
    // --------------------------------------

        // glColor3d(0.0, 0.3, 0.0);
        // glLineStipple(1, 0xFFFF);
        // glLineWidth(1.0);

        // glBegin(GL_LINES);
        //     glVertex3d(-500.0, 0.0, 0.0);
        //     glVertex3d(500.0, 0.0, 0.0);
        //     glVertex3d(0.0, -500.0, 0.0);
        //     glVertex3d(0.0, 500.0, 0.0);
        //     glVertex3d(0.0, 0.0, -500.0);
        //     glVertex3d(0.0, 0.0, 500.0);
        // glEnd();
    // --------------------------------------

        // загружаем координаты точек в вершинный буфер
        glVertexPointer(3, GL_DOUBLE, 0, model.vertices);

        // задаём цвет для рисования
        glColor3fv(property.lineColor);

        // настройки линий
        glLineWidth(property.lineWidth);        // толщина линии
        glLineStipple(1, property.lineType);    // тип линии

        // Рисуем полигоны
        for(unsigned i = 0; i < model.total_polygons; i++)
        {
            glDrawElements(GL_LINE_LOOP, model.polygons[i].count_of_vertices,
                           GL_UNSIGNED_INT, model.polygons[i].numbers_of_vertices);
        }

        // Если включено отображение точек
        if(property.pointType)
        {
            // настройки точек
            glPointSize(property.pointSize);    // размер точек
            glColor3fv(property.pointColor);    // задаём цвет для рисования точек
            glDisable(GL_POINT_SMOOTH);

            if(property.pointType > 1) {
                glEnable(GL_POINT_SMOOTH);      // форма точек (без этого квадратные)
            }

            // Рисуем точки
            glDrawArrays(GL_POINTS, 1, model.total_vertices);
        }

        glFlush();
    }
}

void GLWidget::centering()
{
    // максимальная ПОЛУдлина модели по осям
    double half_length_X {(model.max[0] - model.min[0]) / 2};
    double half_length_Y {(model.max[1] - model.min[1]) / 2};
    double half_length_Z {(model.max[2] - model.min[2]) / 2};

    // центр модели
    double centr_X {model.min[0] + half_length_X};
    double centr_Y {model.min[1] + half_length_Y};
    double centr_Z {model.min[2] + half_length_Z};

    // переносим все точки относительно центра
    for (size_t i = 3; i < (model.total_vertices + 1) * 3; i += 3) {
        model.vertices[i] -= centr_X;
        model.vertices[i + 1] -= centr_Y;
        model.vertices[i + 2] -= centr_Z;
    }

    // Вычисляем размер сцены
    property.scene = std::max(half_length_X, std::max(half_length_Y, half_length_Z)) * 1.7;
}


GLWidget::~GLWidget()
{
    s21_cleaner(&model);
}
