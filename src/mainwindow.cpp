#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    s21_cleaner(&ui->glWidget->model);
    s21_parser(&ui->glWidget->model);
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

