#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <gl/gl.h>

extern "C" {
    #include "parcer.h"
}

struct View
{
    float backColor[3];   // цвет фона (R, G, B, Прозрачность)          / glClearColor(0-1, 0-1, 0-1, 0-1) (тип GLclampf)
    float lineColor[3];   // линии: цвет                                / glColor3fv(*array) || glColor3f(R, G, B) (тип double)
    float pointColor[3];  // точки: цвет                                / glColor3fv(*array) || glColor3f(R, G, B) (тип double)

    float pointSize;      // точки: размер                              / glPointSize(float);
    int pointType;        // точки: тип (нет, квадратные, круглые)      / не отрисовывать || по умолчанию || glEnable(GL_POINT_SMOOTH);

    float lineWidth;      // линии: толщина                             / glLineWidth(float)
    bool lineType;        // линии: тип (сплошная, штриховка)           / по умолчанию || glEnable(GL_LINE_STIPPLE)+ glLineStipple(1, 000F)

    bool ortho;           // тип проекции (параллельная и центральная)  / glFrustum() || glOrtho()
};


class GLWidget : public QOpenGLWidget
{

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

public:
    Model model = {nullptr, nullptr, 0, 0};
    View property = {{0}, {0.8, 0.9, 0}, {1, 1, 1}, 5.0, 2, 1.0, 0, 0}; // данные по умолчанию

    GLWidget(QWidget* parent = nullptr);
    ~GLWidget();

public slots:
    void on_paintButton_clicked();
    void on_openButton_clicked();

};

#endif // GLWIDGET_H
