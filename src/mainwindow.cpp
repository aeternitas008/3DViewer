#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QRadioButton>
#include <QMessageBox>

#include <unistd.h>
#include <parser.h>

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
        QFileInfo fileInfo(strQ);
        QString fileName = fileInfo.fileName();
        ui->pathFile->setText(fileName);

        std::string strStd = strQ.toStdString();   
        const char *str = strStd.c_str();  // Используем c_str() для получения C-строки

        // Запускаем парсер с выбранным файлом
        s21_cleaner(&ui->glWidget->model);
        s21_parser(str, &ui->glWidget->model);

        // Центрируем модель
        ui->glWidget->centering();

        ui->countVertex->setText(QString::number(ui->glWidget->model.total_vertices));
        ui->countPolygon->setText(QString::number(ui->glWidget->model.total_polygons));
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
}


void MainWindow::on_furtherButton_clicked()
{
    s21_shift(&ui->glWidget->model, -0.1, Z);
    ui->glWidget->update();
}

// -------- КНОПКИ МАСШТАБИРОВАНИЯ ---------

void MainWindow::on_increaseButton_clicked()
{
    if(ui->glWidget->model.vertices)
    {
        s21_scale(&ui->glWidget->model, 1.1);
        ui->glWidget->update();
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
    s21_rotate_forward(&ui->glWidget->model, 5.0, Z);
    ui->glWidget->update();
}

void MainWindow::on_rotateButtonZ_2_clicked()
{
    s21_rotate_back(&ui->glWidget->model, 5.0, Z);
    ui->glWidget->update();
}

// --------- НАСТРОЙКИ ОТОБРАЖЕНИЯ ---------

// ПРОЕКЦИЯ

void MainWindow::on_radioTypeCentral_clicked()
{
    ui->glWidget->property.projection_type = 0;
    ui->glWidget->update();
}

void MainWindow::on_radioTypeParallel_clicked()
{
    ui->glWidget->property.projection_type = 1;
    ui->glWidget->update();
}



// ЛИНИИ

void MainWindow::on_radioLineDashed_clicked()
{
    ui->glWidget->property.line_type = 0x000F;
    ui->glWidget->update();
}

void MainWindow::on_radioLineSolid_clicked()
{
    ui->glWidget->property.line_type = 0xFFFF;
    ui->glWidget->update();
}

void MainWindow::on_sliderLineWidth_valueChanged(int value)
{
    ui->lineEditLineWidth->setText(QString::number(value));
    ui->glWidget->property.line_width = value;
    ui->glWidget->update();
}

void MainWindow::on_lineEditLineWidth_returnPressed()
{
    int value = ui->lineEditLineWidth->text().toInt();
    ui->sliderLineWidth->setValue(value);
    ui->glWidget->property.line_width = value;
    ui->lineEditLineWidth->clearFocus();
    ui->glWidget->update();
}

void MainWindow::on_sliderPointSize_valueChanged(int value)
{
    ui->lineEditPointSize->setText(QString::number(value));
    ui->glWidget->property.point_size = value;
    ui->glWidget->update();
}

void MainWindow::on_lineEditPointSize_returnPressed()
{
    int value = ui->lineEditPointSize->text().toInt();
    ui->sliderPointSize->setValue(value);

    ui->glWidget->property.point_size = value;
    ui->glWidget->update();

    ui->lineEditPointSize->clearFocus();
}

void MainWindow::on_comboBoxPointType_currentIndexChanged(int index)
{
    ui->glWidget->property.point_type = index;
    ui->glWidget->update();
}

QColor getColorFromString(const QString &colorName)
{
    if (colorName == "черный") return QColor(Qt::black);
    if (colorName == "красный") return QColor(Qt::red);
    if (colorName == "желтый") return QColor(Qt::yellow);
    if (colorName == "синий") return QColor(Qt::blue);
    if (colorName == "зеленый") return QColor(Qt::green);
    if (colorName == "оранжевый") return QColor(255, 165, 0);  // Оранжевый
    if (colorName == "фиолетовый") return QColor(128, 0, 128);  // Фиолетовый
    if (colorName == "белый") return QColor(Qt::white);
    if (colorName == "рандомный") return QColor::fromRgb(rand() % 256, rand() % 256, rand() % 256);  // Рандомный цвет
    return QColor(Qt::black);  // Цвет по умолчанию
}

void MainWindow::on_comboBoxLineColor_currentIndexChanged(int index)
{
    QString selectedColor = ui->comboBoxLineColor->itemText(index);
        QColor color = getColorFromString(selectedColor);
        ui->glWidget->property.line_color[0] = color.redF();
        ui->glWidget->property.line_color[1] = color.greenF();
        ui->glWidget->property.line_color[2] = color.blueF();

        ui->glWidget->update();

}

void MainWindow::on_comboBoxPointColor_currentIndexChanged(int index)
{
    QString selectedColor = ui->comboBoxPointColor->itemText(index);
        QColor color = getColorFromString(selectedColor);
        ui->glWidget->property.point_color[0] = color.redF();
        ui->glWidget->property.point_color[1] = color.greenF();
        ui->glWidget->property.point_color[2] = color.blueF();

        ui->glWidget->update();

}

void MainWindow::on_comboBoxBackColor_currentIndexChanged(int index)
{
    QString selectedColor = ui->comboBoxBackColor->itemText(index);
        QColor color = getColorFromString(selectedColor);
        ui->glWidget->property.back_color[0] = color.redF();
        ui->glWidget->property.back_color[1] = color.greenF();
        ui->glWidget->property.back_color[2] = color.blueF();
        ui->glWidget->update();

}