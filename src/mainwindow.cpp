#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QRadioButton>
#include <QMessageBox>

#include <unistd.h>

#include <parcer.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // QObject::connect(&ui->radioTypeCentral, &QRadioButton::checked, onClick);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// кнопка Paint
void MainWindow::on_paintButton_clicked()
{
    ui->glWidget->update();
}

 // кнопка Open File
void MainWindow::on_openButton_clicked()
{   
    QString strQ = QFileDialog::getOpenFileName(this, "Open File", QString(), "*.obj");

    if (!strQ.isEmpty()) {
        // Обновляем QLabel с путем к файлу
        // ui->pathFile->setText(strQ);
        QFileInfo fileInfo(strQ);
        QString fileName = fileInfo.fileName();
        ui->pathFile->setText(fileName);

        // Преобразуем QString в C-строку
        std::string strStd = strQ.toStdString();   
        const char *str = strStd.c_str();  // Используем c_str() для получения C-строки

        // Запускаем парсер с выбранным файлом
        s21_cleaner(&ui->glWidget->model);
        s21_parser2(str, &ui->glWidget->model);
        // s21_parser(&ui->glWidget->model);
        ui->countVertex->setText(QString::number(ui->glWidget->model.total_vertices));
        ui->countPolygon->setText(QString::number(ui->glWidget->model.polygons_count));
        print_extremum(ui->glWidget->model);
        // вывести вектора и модель
        print_model(ui->glWidget->model);
    }
}
// ------------- КНОПКИ СДВИГА -------------

void MainWindow::on_leftButton_clicked()
{
    s21_shift(&ui->glWidget->model, -0.1, X);
    ui->glWidget->update();
}

void MainWindow::on_rightButton_clicked()
{
    s21_shift(&ui->glWidget->model, 0.1, X);
    ui->glWidget->update();
}

void MainWindow::on_upButton_clicked()
{
    s21_shift(&ui->glWidget->model, 0.1, Y);
    ui->glWidget->update();
}

void MainWindow::on_downButton_clicked()
{
    s21_shift(&ui->glWidget->model, -0.1, Y);
    ui->glWidget->update();
}

void MainWindow::on_closerButton_clicked()
{
    s21_shift(&ui->glWidget->model, 0.1, Z);
    ui->glWidget->update();
    qDebug()<<QString::number(ui->glWidget->model.vertices[3]);
    qDebug()<<QString::number(ui->glWidget->model.vertices[4]);
    qDebug()<<QString::number(ui->glWidget->model.vertices[5]);
}


void MainWindow::on_furtherButton_clicked()
{
    s21_shift(&ui->glWidget->model, -0.1, Z);
    ui->glWidget->update();
    qDebug()<<QString::number(ui->glWidget->model.vertices[3]);
    qDebug()<<QString::number(ui->glWidget->model.vertices[4]);
    qDebug()<<QString::number(ui->glWidget->model.vertices[5]);
}

// -------- КНОПКИ МАСШТАБИРОВАНИЯ ---------

void MainWindow::on_increaseButton_clicked()
{
    if(ui->glWidget->model.vertices)
    {
        qDebug()<<QString::number(ui->glWidget->model.vertices[3]);
        qDebug()<<QString::number(ui->glWidget->model.vertices[4]);
        qDebug()<<QString::number(ui->glWidget->model.vertices[5]);
        s21_scale(&ui->glWidget->model, 1.1);
        ui->glWidget->update();
        qDebug()<<QString::number(ui->glWidget->model.vertices[3]);
        qDebug()<<QString::number(ui->glWidget->model.vertices[4]);
        qDebug()<<QString::number(ui->glWidget->model.vertices[5]);
    }
}

void MainWindow::on_decreaseButton_clicked()
{
    if(ui->glWidget->model.vertices)
    {
        s21_scale(&ui->glWidget->model, 0.9);
        ui->glWidget->update();
    }
}

// ------------ КНОПКИ ВРАЩЕНИЯ ------------

void MainWindow::on_rotateButtonX_clicked()
{
    s21_rotate_forward(&ui->glWidget->model, 5.0, X);
    ui->glWidget->update();
}

void MainWindow::on_rotateButtonX_2_clicked()
{
    s21_rotate_back(&ui->glWidget->model, 5.0, X);
    ui->glWidget->update();
}

void MainWindow::on_rotateButtonY_clicked()
{
    s21_rotate_forward(&ui->glWidget->model, 5.0, Y);
    ui->glWidget->update();
}

void MainWindow::on_rotateButtonY_2_clicked()
{
    s21_rotate_back(&ui->glWidget->model, 5.0, Y);
    ui->glWidget->update();
}

void MainWindow::on_rotateButtonZ_clicked()
{
    qDebug()<<QString::number(ui->glWidget->model.vertices[3]);
    qDebug()<<QString::number(ui->glWidget->model.vertices[4]);
    qDebug()<<QString::number(ui->glWidget->model.vertices[5]);

    s21_rotate_forward(&ui->glWidget->model, 5.0, Z);
    ui->glWidget->update();

    qDebug()<<QString::number(ui->glWidget->model.vertices[3]);
    qDebug()<<QString::number(ui->glWidget->model.vertices[4]);
    qDebug()<<QString::number(ui->glWidget->model.vertices[5]);
}

void MainWindow::on_rotateButtonZ_2_clicked()
{
    s21_rotate_back(&ui->glWidget->model, 5.0, Z);
    ui->glWidget->update();
}


    // как обновить тип проекции??
void MainWindow::on_radioTypeCentral_clicked()
{
    // как обновить тип проекции??
    ui->glWidget->property.projection_type = 0;
    QMessageBox::information(this, "type", "central");
    // ui->glWidget->update();
//    ui->glWidget->initializeGL();
}


void MainWindow::on_radioTypeParallel_clicked()
{
    ui->glWidget->property.projection_type = 1;
    QMessageBox::information(this, "type", "parallel");
    // ui->glWidget->update();
//    ui->glWidget->initializeGL();
}


void MainWindow::on_radioLineDashed_clicked()
{
    ui->glWidget->property.line_type = 1;
     ui->glWidget->update();
}


void MainWindow::on_radioLineSolid_clicked()
{
    ui->glWidget->property.line_type = 0;
     ui->glWidget->update();
}


void MainWindow::on_sliderLineWidth_valueChanged(int value)
{
    ui->lineEditLineWidth->setText(QString::number(value));
}


void MainWindow::on_lineEditLineWidth_returnPressed()
{
    this->clearFocus();
    ui->sliderPointSize->setFocus();
}



QStringList colorNames = {"White", "Black", "Red", "Green", "Blue", "Yellow", "Cyan", "Magenta"};