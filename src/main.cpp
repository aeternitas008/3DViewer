#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow 
    mWindow;
    mWindow.setWindowTitle("3DViewer_v1.0");
    mWindow.setFixedSize(800, 640);
    mWindow.show();


    return app.exec();
}
