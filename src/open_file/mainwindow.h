#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QLabel * lbl;
    ~MainWindow();

private:
    Ui::MainWindow *ui;

signals:
    void paintButton();
    void openButton();

private slots:
    void on_paintButton_clicked();
    void on_openButton_clicked();
};

#endif // MAINWINDOW_H
