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
    Model model = {nullptr, nullptr, 0, 0};

    GLWidget(QWidget* parent = nullptr);
    ~GLWidget();

public slots:
    void on_paintButton_clicked();
    void on_openButton_clicked();

};

#endif // GLWIDGET_H
