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

    settings=new QSettings("s21","3d_viewer",this);
    loadSettings();
    gifTimer.setInterval(100);
    connect(&gifTimer, SIGNAL(timeout()), SLOT(gifShot()));

    connect(this, &MainWindow::shot, this, &MainWindow::snapShot);
}

MainWindow::~MainWindow()
{
    saveSettings();
    delete ui;
}

void MainWindow::saveSettings()
{
    settings->setValue("projection_type", ui->glWidget->property.projection_type);

    settings->setValue("line_type", ui->glWidget->property.line_type);

    settings->setValue("line_color_name", ui->comboBoxLineColor->currentText());
    settings->setValue("line_color_r", ui->glWidget->property.line_color[0]);
    settings->setValue("line_color_g", ui->glWidget->property.line_color[1]);
    settings->setValue("line_color_b", ui->glWidget->property.line_color[2]);

    settings->setValue("line_width", ui->glWidget->property.line_width);

    settings->setValue("point_type", ui->glWidget->property.point_type);

    settings->setValue("point_color_name", ui->comboBoxPointColor->currentText());
    settings->setValue("point_color_r", ui->glWidget->property.point_color[0]);
    settings->setValue("point_color_g", ui->glWidget->property.point_color[1]);
    settings->setValue("point_color_b", ui->glWidget->property.point_color[2]);

    settings->setValue("point_size", ui->glWidget->property.line_width);

    settings->setValue("back_color_name", ui->comboBoxBackColor->currentText());
    settings->setValue("back_color_r", ui->glWidget->property.back_color[0]);
    settings->setValue("back_color_g", ui->glWidget->property.back_color[1]);
    settings->setValue("back_color_b", ui->glWidget->property.back_color[2]);

}

void MainWindow::loadSettings() 
{

    ui->glWidget->property.line_type = settings->value("projection_type", 0).toInt();
    if (ui->glWidget->property.line_type == 0) {
        ui->radioTypeCentral->setChecked(true); 
    } else {
        ui->radioTypeParallel->setChecked(true); 
    }

    ui->glWidget->property.line_type = settings->value("line_type", 0xFFFF).toInt();
    if (ui->glWidget->property.line_type == 0x000F) {
        ui->radioLineDashed->setChecked(true);
    } else {
        ui->radioLineSolid->setChecked(true); 
    }
    QString colorName = settings->value("line_color_name", "желтый").toString(); 
    int index = ui->comboBoxLineColor->findText(colorName);
    if (index != -1) {
        ui->comboBoxLineColor->setCurrentIndex(index);
    }
    ui->glWidget->property.line_color[0] = settings->value("line_color_r", 0.9).toFloat(); 
    ui->glWidget->property.line_color[1] = settings->value("line_color_g", 0.7).toFloat(); 
    ui->glWidget->property.line_color[2] = settings->value("line_color_b", 0.2).toFloat();
    
    ui->glWidget->property.line_width=settings->value("line_width", 1.0).toFloat();
    ui->lineEditLineWidth->setValue(ui->glWidget->property.line_width);

    ui->glWidget->property.point_type=settings->value("point_type", 0).toInt();
    ui->comboBoxPointType->setCurrentIndex(ui->glWidget->property.point_type);

    QString colorName2 = settings->value("point_color_name", "белый").toString(); 
    int index2 = ui->comboBoxPointColor->findText(colorName2);
    if (index2 != -1) {
        ui->comboBoxPointColor->setCurrentIndex(index2);
    }
    ui->glWidget->property.point_color[0] = settings->value("point_color_r", 0.9).toFloat(); 
    ui->glWidget->property.point_color[1] = settings->value("point_color_g", 0.7).toFloat(); 
    ui->glWidget->property.point_color[2] = settings->value("point_color_b", 0.2).toFloat();

    ui->glWidget->property.point_size=settings->value("point_size", 0).toFloat();
    ui->lineEditPointSize->setValue(ui->glWidget->property.point_size);

    QString colorName3 = settings->value("back_color_name", "черный").toString(); 
    int index3 = ui->comboBoxBackColor->findText(colorName3);
    if (index3 != -1) {
        ui->comboBoxBackColor->setCurrentIndex(index3);
    }
    ui->glWidget->property.back_color[0] = settings->value("back_color_r", 0.9).toFloat(); 
    ui->glWidget->property.back_color[1] = settings->value("back_color_g", 0.7).toFloat(); 
    ui->glWidget->property.back_color[2] = settings->value("back_color_b", 0.2).toFloat();
    

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
    double value = -(ui->inputShift->text().toDouble() / 100);
    s21_shift(&ui->glWidget->model, value, X);
    ui->glWidget->update();
}

void MainWindow::on_rightButton_clicked()
{
    double value = ui->inputShift->text().toDouble() / 100;
    s21_shift(&ui->glWidget->model, value, X);
    ui->glWidget->update();
}

void MainWindow::on_upButton_clicked()
{
    double value = ui->inputShift->text().toDouble() / 100;
    s21_shift(&ui->glWidget->model, value, Y);
    ui->glWidget->update();
}

void MainWindow::on_downButton_clicked()
{
    double value = -(ui->inputShift->text().toDouble() / 100);
    s21_shift(&ui->glWidget->model, value, Y);
    ui->glWidget->update();
}

void MainWindow::on_closerButton_clicked()
{
    double value = ui->inputShift->text().toDouble() / 100;
    s21_shift(&ui->glWidget->model, value, Z);
    ui->glWidget->update();
}


void MainWindow::on_furtherButton_clicked()
{
    double value = -(ui->inputShift->text().toDouble() / 100);
    s21_shift(&ui->glWidget->model, value, Z);
    ui->glWidget->update();
}

// -------- КНОПКИ МАСШТАБИРОВАНИЯ ---------

void MainWindow::on_increaseButton_clicked()
{
    if(ui->glWidget->model.vertices)
    {
        double value = 1 + ui->inputScale->text().toDouble() / 100;
        s21_scale(&ui->glWidget->model, value);
        ui->glWidget->update();
    }
}


void MainWindow::on_decreaseButton_clicked()
{
    if(ui->glWidget->model.vertices)
    {
        double value = 1 - ui->inputScale->text().toDouble() / 100;
        s21_scale(&ui->glWidget->model, value);
        ui->glWidget->update();
    }
}



// ------------ КНОПКИ ВРАЩЕНИЯ ------------

void MainWindow::on_rotateButtonX_clicked()
{
    double value = ui->inputRotate->text().toDouble() / 10;
    s21_rotate(&ui->glWidget->model, value, X);
    ui->glWidget->update();
}

void MainWindow::on_rotateButtonX_2_clicked()
{
    double value = ui->inputRotate->text().toDouble() / 10;
    s21_rotate(&ui->glWidget->model, -value, X);
    ui->glWidget->update();
}

void MainWindow::on_rotateButtonY_clicked()
{
    double value = ui->inputRotate->text().toDouble() / 10;
    s21_rotate(&ui->glWidget->model, value, Y);
    ui->glWidget->update();
}

void MainWindow::on_rotateButtonY_2_clicked()
{
    double value = ui->inputRotate->text().toDouble() / 10;
    s21_rotate(&ui->glWidget->model, -value, Y);
    ui->glWidget->update();
}

void MainWindow::on_rotateButtonZ_clicked()
{
    double value = ui->inputRotate->text().toDouble() / 10;
    s21_rotate(&ui->glWidget->model, value, Z);
    ui->glWidget->update();
}

void MainWindow::on_rotateButtonZ_2_clicked()
{
    double value = ui->inputRotate->text().toDouble() / 10;
    s21_rotate(&ui->glWidget->model, -value, Z);
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
    ui->lineEditLineWidth->setValue(value);
    ui->glWidget->property.line_width = value;
    ui->glWidget->update();
}

void MainWindow::on_sliderPointSize_valueChanged(int value)
{
    ui->lineEditPointSize->setValue(value);
    ui->glWidget->property.point_size = value;
    ui->glWidget->update();
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

void MainWindow::on_lineEditLineWidth_valueChanged(int arg1)
{
     ui->sliderLineWidth->setValue(arg1);
     ui->glWidget->property.line_width = arg1;
     ui->glWidget->update();
}


void MainWindow::on_lineEditPointSize_valueChanged(int arg1)
{
     ui->sliderPointSize->setValue(arg1);
     ui->glWidget->property.point_size = arg1;
     ui->glWidget->update();
}

// -------- СОХРАНЕНИЕ ИЗОБРАЖЕНИЯ ---------

void MainWindow::on_jpegButton_clicked()
{
    emit shot(".jpeg");
}

void MainWindow::on_bmpButton_clicked()
{
    emit shot(".bmp");
}

void MainWindow::on_gifButton_clicked()
{
    emit shot(".gif");
}

void MainWindow::snapShot(QString extension) {
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
        name = "Screenshot/" + ui->pathFile->text();
        name.truncate(name.indexOf('.'));
        name += "_";

        // проверяем существование файла
        for(quint32 i = 0; ; i++) {
            if(!QFile().exists(name + QString::number(i) + extension)) {
                name += QString::number(i) + extension;
                break;
            }
        }

        // формируем изображение и сохраняем его
        if(extension == ".gif"){    // gif файл
            gifImage = new QGifImage;
            gifImage->addFrame(ui->glWidget->grabFramebuffer());
            gifImage->save(name);
            delete gifImage;
        } else {                    // jpeg/bmp файл
            QImage picture;
            picture = ui->glWidget->grabFramebuffer();
            picture.save(name);
        }
    }
}

// ---------- ЗАПИСЬ GIF-АНИМАЦИИ ----------

void MainWindow::on_gifREC_clicked()
{
    if(ui->pathFile->text() == "File Name")
    {
        QMessageBox::information(this, "3D_Viewer", "Ни один файл не открыт");
    }
    else
    {
        // блокируем нажатие кнопки
        ui->gifREC->setEnabled(false);
        ui->gifSTOP->setEnabled(true);

        gifImage = new QGifImage;
        gifImage->setDefaultDelay(100);

        gifTimer.start();
    }
    // вынести что-то в отдельные функции/методы?? (повторяющийся код)
}

void MainWindow::on_gifSTOP_clicked()
{
    gifTimer.stop();

    // проверяем существование каталога изображений
    if(!QDir().exists("Screenshot")) {
        QDir().mkdir("Screenshot");
    }

    // формируем имя файла
    QString name;
    name = "Screenshot/" + ui->pathFile->text();
    name.truncate(name.indexOf('.'));
    name += "_";

    // проверяем существование файла
    for(quint32 i = 0; ; i++) {
        if(!QFile().exists(name + QString::number(i) + ".gif")) {
            name += QString::number(i) + ".gif";
            break;
        }
    }

    gifImage->save(name);
    delete gifImage;

    // блокируем нажатие кнопки
    ui->gifSTOP->setEnabled(false);
    ui->gifREC->setEnabled(true);
}

void MainWindow::gifShot()
{
    // С уменьшением размера кадра(480x480)
    gifImage->addFrame(ui->glWidget->grabFramebuffer().scaled(480, 480));

    // Без уменьшения размера кадра (580x580)
    // gifImage->addFrame(ui->glWidget->grabFramebuffer());
}

