#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>

#if defined(__APPLE__)
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
#else
    #include <GL/gl.h>
    #include <GL/glu.h>
#endif


extern "C" {
    #include "parser.h"
    #include "affine_transformations.h"
}

struct Properties {
    int projection_type;
    int line_type;
    float line_color[3];
    float line_width;
    int point_type;
    float point_color[3];
    float point_size;
    float back_color[3];

    double scene;
};


class GLWidget : public QOpenGLWidget
{

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
// {0.8, 0.9, 0.0}
public:
    Model model = {nullptr, nullptr, 0, 0, {0.0}, {0.0}};
    Properties property = {0, 0xFFFF,  {0.9, 0.7, 0.2}, 1.0, 0, {1, 1, 1}, 5.0, {0}, 0};

    GLWidget(QWidget* parent = nullptr);
    ~GLWidget();

    void centering();
};

#endif // GLWIDGET_H
