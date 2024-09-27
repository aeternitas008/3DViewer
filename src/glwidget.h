#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <gl/gl.h>

class GLWidget : public QOpenGLWidget
{

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

public:
    GLWidget(QWidget* parent = nullptr);
};

#endif // GLWIDGET_H
