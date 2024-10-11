#include "mainwindow.h"
#include "ui_mainwindow.h"

// -------------------

// #include <QRadioButton>
// #include <QMessageBox>

// #include <unistd.h>
// #include <parcer.h>

// --------------------

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBoxLineColor->addItems({"White", "Red", "Green", "Blue", "Black"});
    ui->comboBoxPointType->addItems({"None", "Square", "Round"});
}

MainWindow::~MainWindow()
{
    delete ui;
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
        s21_parser(str, &ui->glWidget->model);

        // Центрируем модель
        ui->glWidget->centering();

        ui->countVertex->setText(QString::number(ui->glWidget->model.total_vertices));
        ui->countPolygon->setText(QString::number(ui->glWidget->model.total_polygons));

        // qDebug()<<QString::number(ui->glWidget->model.max[0]);
        // qDebug()<<QString::number(ui->glWidget->model.max[1]);
        // qDebug()<<QString::number(ui->glWidget->model.max[2]);

        // вывести экстремумы модели
        // print_extremum(ui->glWidget->model);
        // вывести вектора и модель
        // print_model(ui->glWidget->model);
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
    s21_scale(&ui->glWidget->model, 1.1);
    ui->glWidget->update();
}

void MainWindow::on_decreaseButton_clicked()
{
    s21_scale(&ui->glWidget->model, 0.9);
    ui->glWidget->update();
}

// ------------ КНОПКИ ВРАЩЕНИЯ ------------

void MainWindow::on_rotateButtonX_clicked()
{
    s21_rotate(&ui->glWidget->model, 5.0, X);
    ui->glWidget->update();
}

void MainWindow::on_rotateButtonX_2_clicked()
{
    s21_rotate(&ui->glWidget->model, -5.0, X);
    ui->glWidget->update();
}

void MainWindow::on_rotateButtonY_clicked()
{
    s21_rotate(&ui->glWidget->model, 5.0, Y);
    ui->glWidget->update();
}

void MainWindow::on_rotateButtonY_2_clicked()
{
    s21_rotate(&ui->glWidget->model, -5.0, Y);
    ui->glWidget->update();
}

void MainWindow::on_rotateButtonZ_clicked()
{
    s21_rotate(&ui->glWidget->model, 5.0, Z);
    ui->glWidget->update();
}

void MainWindow::on_rotateButtonZ_2_clicked()
{
    s21_rotate(&ui->glWidget->model, -5.0, Z);
    ui->glWidget->update();
}

// --------- НАСТРОЙКИ ОТОБРАЖЕНИЯ ---------

// ПРОЕКЦИЯ

void MainWindow::on_radioTypeCentral_clicked()
{
    ui->glWidget->property.ortho = 1;
    ui->glWidget->update();
}

void MainWindow::on_radioTypeParallel_clicked()
{
    ui->glWidget->property.ortho = 0;
    ui->glWidget->update();
}

// ЛИНИИ

void MainWindow::on_radioLineSolid_clicked()
{
    ui->glWidget->property.lineType = 0xFFFF;
    ui->glWidget->update();
}

void MainWindow::on_radioLineDashed_clicked()
{
    ui->glWidget->property.lineType = 0x000F;
    ui->glWidget->update();
}

void MainWindow::on_sliderLineWidth_valueChanged(int value)
{
    ui->lineEditLineWidth->setText(QString::number(value));
    ui->glWidget->property.lineWidth = value;
    ui->glWidget->update();
}


void MainWindow::on_lineEditLineWidth_returnPressed()
{
    int value = ui->lineEditLineWidth->text().toInt();
    ui->sliderLineWidth->setValue(value);
    //    this->clearFocus();
    ui->glWidget->property.lineWidth = value;
    //    ui->sliderPointSize->setFocus();
    ui->lineEditLineWidth->clearFocus();
    ui->glWidget->update();
}

void MainWindow::on_comboBoxLineColor_activated()
{
    // if(index == 0) {
    //     ui->glWidget->property.lineColor = {0, 0, 0};
    // }
}


void MainWindow::on_sliderPointSize_valueChanged(int value)
{
    // ui->lineEditPointSize->setText(QString::number(value));
    ui->glWidget->property.pointSize = value;
    ui->glWidget->update();
}


void MainWindow::on_lineEditPointSize_returnPressed()
{
    //    this->clearFocus();
    int value = ui->lineEditPointSize->text().toInt();
    ui->sliderPointSize->setValue(value);

    ui->glWidget->property.pointSize = value;
    ui->glWidget->update();

    ui->lineEditPointSize->clearFocus();
}


void MainWindow::on_comboBoxPointType_currentIndexChanged(int index)
{
    // qDebug()<<QString::number(ui->glWidget->model.max[0]);
    ui->glWidget->property.pointType = index;

    ui->glWidget->update();
}

// -------- СОХРАНЕНИЕ ИЗОБРАЖЕНИЯ ---------

void MainWindow::on_jpegButton_clicked()
{
    // проверяем открыт ли файл
    if(ui->pathFile->text() == "File Name") {
        QMessageBox::information(this, "3D_Viewer", "Ни один файл не открыт");
    } else {

        // проверяем существование каталога изображений
        if(!QDir().exists("Screenshot")) {
            QDir().mkdir("Screenshot");
        }

        // формируем имя файла
        QString name;
        name = ui->pathFile->text();
        name.truncate(name.indexOf('.'));

        // проверяем существование файла
        if(QFile().exists("Screenshot/" + name + ".jpeg")) {
            static quint32 i{1};
            name += "_" + QString::number(i++);
        }

        // формируем изображение и сохраняем его
        QImage picture;
        picture = ui->glWidget->grabFramebuffer();
        picture.save("Screenshot/" + name + ".jpeg", "jpeg", 100);
    }
}

void MainWindow::on_bmpButton_clicked()
{
    if(ui->pathFile->text() == "File Name")
    {
        QMessageBox::information(this, "3D_Viewer", "Ни один файл не открыт");
    }
    else
    {
        // проверяем существование каталога изображений
        if(!QDir().exists("Screenshot")) {
            QDir().mkdir("Screenshot");
        }

        // формируем имя файла
        QString name;
        name = ui->pathFile->text();
        name.truncate(name.indexOf('.'));

        // проверяем существование файла
        if(QFile().exists("Screenshot/" + name + ".bmp")) {
            static quint32 i{1};
            name += "_" + QString::number(i++);
        }

        // формируем изображение и сохраняем его
        QImage picture;
        picture = ui->glWidget->grabFramebuffer();
        picture.save("Screenshot/" + name + ".bmp", "bmp", 100);
    }
}

