#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this, &MainWindow::paintButton, ui->glWidget, &GLWidget::on_paintButton_clicked);
    connect(this, &MainWindow::openButton, ui->glWidget, &GLWidget::on_openButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// кнопка Paint
void MainWindow::on_paintButton_clicked()
{
    emit paintButton();
}

// кнопка Open File
void MainWindow::on_openButton_clicked()
{
    emit openButton();
}

