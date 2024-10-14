#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QtWidgets>
#include "QtGifImage/gifimage/qgifimage.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void saveSettings();
  void loadSettings();


private:
    Ui::MainWindow *ui;
    QSettings *settings;
    QTimer gifTimer;
    QGifImage *gifImage;

 signals:
  void shot(const QString &);

 private slots:
  // снимки экрана
  void snapShot(QString extension);
  void on_jpegButton_clicked();
  void on_bmpButton_clicked();
  void on_gifButton_clicked();
  // запись экрана
  void on_gifREC_clicked();
  void on_gifSTOP_clicked();
  void gifShot();

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
  void on_radioTypeCentral_clicked();
  void on_radioTypeParallel_clicked();
  void on_radioLineDashed_clicked();
  void on_radioLineSolid_clicked();
  void on_sliderLineWidth_valueChanged(int value);
  void on_sliderPointSize_valueChanged(int value);
  void on_comboBoxPointType_currentIndexChanged(int index);

  void on_comboBoxLineColor_currentIndexChanged(int index);
  void on_comboBoxPointColor_currentIndexChanged(int index);
  void on_comboBoxBackColor_currentIndexChanged(int index);

  void on_lineEditLineWidth_valueChanged(int arg1);
  void on_lineEditPointSize_valueChanged(int arg1);
};

#endif  // MAINWINDOW_H