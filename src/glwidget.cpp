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
    // Очищаем буфер цвета и глубины
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Переключаемся в режим работы с моделью
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Перемещаем камеру
    // glTranslatef(0.0f, 0.0f, -5.0f);

    // Применяем повороты, используя xRot и yRot
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    if(model.vertices)
    {
    // ----- выставляем камеру -----

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(0.0, 0.0, 1.0 + property.scene, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // ----- выбираем проекцию -----

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        if(property.projection_type) {
            glOrtho(-property.scene, property.scene, -property.scene, property.scene, 1, 10 + 2 * property.scene);
        } else {
            glFrustum(-1, 1, -1, 1, 1, 10 + 2 * property.scene);
        }

    // ----- задам цвет и очищаем экран в этот цвет -----

        //задам цвет и очищаем экран в этот цвет
        glClearColor(property.back_color[0], property.back_color[1], property.back_color[2], 0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // загружаем координаты точек в вершинный буфер
        glVertexPointer(3, GL_DOUBLE, 0, model.vertices);

        // задаём цвет для рисования
        glColor3fv(property.line_color);

        // настройки линий
        glLineWidth(property.line_width);          // толщина линий
        glLineStipple(1, property.line_type);    // тип линии

        // Рисуем полигоны
        for(unsigned i = 0; i < model.total_polygons; i++)
        {
            glDrawElements(GL_LINE_LOOP, model.polygons[i].count_of_vertices,
                           GL_UNSIGNED_INT, model.polygons[i].numbers_of_vertices);
        }

        // Если включено отображение точек
        if(property.point_type) {

                // настройки точек
                glPointSize(property.point_size);  // размер точек
                glColor3fv(property.point_color);  // задаём цвет для рисования точек
                glDisable(GL_POINT_SMOOTH);

                if(property.point_type > 1) glEnable(GL_POINT_SMOOTH);    // форма точек (без этого квадратные)
                
                // РИСУЕМ ТОЧКИ
                glDrawArrays(GL_POINTS, 1, model.total_vertices);
            }

        glFlush(); // принудительно выполняет функции OpenGL в конечное время
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

void GLWidget::mousePressEvent(QMouseEvent* mo) {
    mPos = mo->pos();
}

void GLWidget::mouseMoveEvent(QMouseEvent* mo) {
    // Вычисляем изменение позиции мыши
    int dx = mo->pos().x() - mPos.x();
    int dy = mo->pos().y() - mPos.y();

    // Изменяем углы поворота модели в зависимости от перемещения мыши
    xRot += dy * 0.5f; // Множитель 0.5 для плавности
    yRot += dx * 0.5f;

    // Ограничиваем углы, чтобы избежать слишком большого значения
    xRot = std::fmod(xRot, 360.0f);
    yRot = std::fmod(yRot, 360.0f);

    // Обновляем позицию мыши для следующего вызова
    mPos = mo->pos();

    // Запрашиваем перерисовку экрана
    update();
}