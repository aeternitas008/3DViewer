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
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void on_paintButton_clicked();
    void on_openButton_clicked();

    // сдвиг модели
    void on_leftButton_clicked();
    void on_rightButton_clicked();
    void on_upButton_clicked();
    void on_downButton_clicked();
    void on_closerButton_clicked();
    void on_furtherButton_clicked();

    // масштабирование модели
    void on_increaseButton_clicked();

    // вращение модели
    void on_decreaseButton_clicked();
    void on_rotateButtonX_clicked();
    void on_rotateButtonY_clicked();
    void on_rotateButtonZ_clicked();
    void on_rotateButtonX_2_clicked();
    void on_rotateButtonY_2_clicked();
    void on_rotateButtonZ_2_clicked();


    // настройки отображения
    void on_radioTypeCentral_clicked();
    void on_radioTypeParallel_clicked();
    void on_radioLineSolid_clicked();
    void on_radioLineDashed_clicked();

    void on_sliderLineWidth_valueChanged(int value);
    void on_lineEditLineWidth_returnPressed();
    void on_comboBoxLineColor_activated(int index);

    void on_sliderPointSize_valueChanged(int value);
    void on_lineEditPointSize_returnPressed();
    void on_comboBoxPointType_currentIndexChanged(int index);

};

#endif // MAINWINDOW_H
