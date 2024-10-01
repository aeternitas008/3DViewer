#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

#include <unistd.h>

#include <parcer.h>
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
    QString strQ = QFileDialog::getOpenFileName(this, "Open File", QString(), "*.obj");

    if (!strQ.isEmpty()) {
        // Обновляем QLabel с путем к файлу
        ui->pathFile->setText(strQ);

        // Преобразуем QString в C-строку
        std::string strStd = strQ.toStdString();   
        const char *str = strStd.c_str();  // Используем c_str() для получения C-строки
       
        //ui обновляется только после выполнения функции
        // sleep(10);
      
        // Запускаем парсер с выбранным файлом
        s21_parser2(str, &ui->glWidget->model);
        // s21_parser(&ui->glWidget->model);

        print_model(ui->glWidget->model);
        // s21_parser(&ui->glWidget->model);
    }
}