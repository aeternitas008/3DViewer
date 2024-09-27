#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <gl/gl.h>

extern "C" {
    #include "parcer.h"
}


class GLWidget : public QOpenGLWidget
{

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

public:
    Model model;

    GLWidget(QWidget* parent = nullptr);
    ~GLWidget();
};

#endif // GLWIDGET_H
