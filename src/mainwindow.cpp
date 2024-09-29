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
    s21_parser(&ui->glWidget->model);
}
