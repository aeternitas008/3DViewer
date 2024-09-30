/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    GLWidget *glWidget;
    QPushButton *openButton;
    QPushButton *paintButton;
    QToolBox *toolBox;
    QWidget *Transform;
    QPushButton *shiftButton;
    QRadioButton *Shift_X;
    QRadioButton *Shift_Y;
    QRadioButton *Shift_Z;
    QLineEdit *lineEdit;
    QSlider *shiftSlider;
    QRadioButton *Rotate_X;
    QPushButton *rotateButton;
    QLineEdit *lineEdit_2;
    QSlider *rotateSlider;
    QRadioButton *Rotate_Z;
    QRadioButton *Rotate_Y;
    QRadioButton *Scale_X;
    QPushButton *scaleButton;
    QLineEdit *lineEdit_3;
    QSlider *scaleSlider;
    QRadioButton *Scale_Z;
    QRadioButton *Scale_Y;
    QWidget *Properties;
    QPushButton *openButton_5;
    QLabel *projectionLabel;
    QLabel *backgroundLabel;
    QLabel *lineLabel;
    QLabel *pointLabel;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QLabel *lineLabel_2;
    QComboBox *comboBox_2;
    QLabel *lineLabel_3;
    QSlider *horizontalSlider;
    QComboBox *comboBox_3;
    QLabel *pointLabel_3;
    QLabel *pointLabel_2;
    QSlider *horizontalSlider_2;
    QLabel *pointLabel_1;
    QComboBox *comboBox_4;
    QLabel *label_14;
    QComboBox *comboBox_5;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLabel *pathFile;
    QLabel *pathFile_2;
    QLabel *pathFile_3;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 640);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        glWidget = new GLWidget(centralwidget);
        glWidget->setObjectName("glWidget");
        glWidget->setGeometry(QRect(10, 50, 580, 580));
        openButton = new QPushButton(centralwidget);
        openButton->setObjectName("openButton");
        openButton->setGeometry(QRect(600, 10, 190, 30));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(12);
        openButton->setFont(font);
        openButton->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::DocumentOpen")));
        openButton->setIcon(icon);
        openButton->setIconSize(QSize(12, 12));
        paintButton = new QPushButton(centralwidget);
        paintButton->setObjectName("paintButton");
        paintButton->setGeometry(QRect(600, 600, 190, 30));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setKerning(true);
        paintButton->setFont(font1);
        paintButton->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::MailMessageNew")));
        paintButton->setIcon(icon1);
        paintButton->setIconSize(QSize(12, 12));
        toolBox = new QToolBox(centralwidget);
        toolBox->setObjectName("toolBox");
        toolBox->setGeometry(QRect(600, 110, 190, 451));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy);
        toolBox->setFont(font);
        toolBox->setAcceptDrops(false);
        toolBox->setToolTipDuration(-1);
        Transform = new QWidget();
        Transform->setObjectName("Transform");
        Transform->setGeometry(QRect(0, 0, 190, 395));
        shiftButton = new QPushButton(Transform);
        shiftButton->setObjectName("shiftButton");
        shiftButton->setGeometry(QRect(0, 100, 190, 30));
        shiftButton->setFont(font);
        shiftButton->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::ViewFullscreen")));
        shiftButton->setIcon(icon2);
        shiftButton->setIconSize(QSize(12, 12));
        Shift_X = new QRadioButton(Transform);
        Shift_X->setObjectName("Shift_X");
        Shift_X->setGeometry(QRect(20, 40, 51, 30));
        Shift_Y = new QRadioButton(Transform);
        Shift_Y->setObjectName("Shift_Y");
        Shift_Y->setGeometry(QRect(80, 40, 51, 30));
        Shift_Z = new QRadioButton(Transform);
        Shift_Z->setObjectName("Shift_Z");
        Shift_Z->setGeometry(QRect(140, 40, 51, 30));
        lineEdit = new QLineEdit(Transform);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(20, 70, 40, 22));
        shiftSlider = new QSlider(Transform);
        shiftSlider->setObjectName("shiftSlider");
        shiftSlider->setGeometry(QRect(80, 70, 100, 21));
        shiftSlider->setOrientation(Qt::Orientation::Horizontal);
        Rotate_X = new QRadioButton(Transform);
        Rotate_X->setObjectName("Rotate_X");
        Rotate_X->setGeometry(QRect(20, 140, 51, 30));
        rotateButton = new QPushButton(Transform);
        rotateButton->setObjectName("rotateButton");
        rotateButton->setGeometry(QRect(0, 200, 190, 30));
        rotateButton->setFont(font);
        rotateButton->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        QIcon icon3(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::ViewRestore")));
        rotateButton->setIcon(icon3);
        rotateButton->setIconSize(QSize(12, 12));
        lineEdit_2 = new QLineEdit(Transform);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(20, 170, 40, 22));
        rotateSlider = new QSlider(Transform);
        rotateSlider->setObjectName("rotateSlider");
        rotateSlider->setGeometry(QRect(80, 170, 100, 21));
        rotateSlider->setOrientation(Qt::Orientation::Horizontal);
        Rotate_Z = new QRadioButton(Transform);
        Rotate_Z->setObjectName("Rotate_Z");
        Rotate_Z->setGeometry(QRect(140, 140, 51, 30));
        Rotate_Y = new QRadioButton(Transform);
        Rotate_Y->setObjectName("Rotate_Y");
        Rotate_Y->setGeometry(QRect(80, 140, 51, 30));
        Scale_X = new QRadioButton(Transform);
        Scale_X->setObjectName("Scale_X");
        Scale_X->setGeometry(QRect(20, 240, 51, 30));
        scaleButton = new QPushButton(Transform);
        scaleButton->setObjectName("scaleButton");
        scaleButton->setGeometry(QRect(0, 300, 190, 30));
        scaleButton->setFont(font);
        scaleButton->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        QIcon icon4(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::SystemSearch")));
        scaleButton->setIcon(icon4);
        scaleButton->setIconSize(QSize(12, 12));
        lineEdit_3 = new QLineEdit(Transform);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(20, 270, 40, 22));
        scaleSlider = new QSlider(Transform);
        scaleSlider->setObjectName("scaleSlider");
        scaleSlider->setGeometry(QRect(80, 270, 100, 21));
        scaleSlider->setOrientation(Qt::Orientation::Horizontal);
        Scale_Z = new QRadioButton(Transform);
        Scale_Z->setObjectName("Scale_Z");
        Scale_Z->setGeometry(QRect(140, 240, 51, 30));
        Scale_Y = new QRadioButton(Transform);
        Scale_Y->setObjectName("Scale_Y");
        Scale_Y->setGeometry(QRect(80, 240, 51, 30));
        QIcon icon5(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::MailAttachment")));
        toolBox->addItem(Transform, icon5, QString::fromUtf8("Transform"));
        Properties = new QWidget();
        Properties->setObjectName("Properties");
        Properties->setGeometry(QRect(0, 0, 190, 395));
        openButton_5 = new QPushButton(Properties);
        openButton_5->setObjectName("openButton_5");
        openButton_5->setGeometry(QRect(0, 340, 190, 30));
        openButton_5->setFont(font);
        openButton_5->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        QIcon icon6(QIcon::fromTheme(QString::fromUtf8("appointment-new")));
        openButton_5->setIcon(icon6);
        openButton_5->setIconSize(QSize(12, 12));
        projectionLabel = new QLabel(Properties);
        projectionLabel->setObjectName("projectionLabel");
        projectionLabel->setGeometry(QRect(10, 0, 170, 30));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(12);
        font2.setUnderline(true);
        projectionLabel->setFont(font2);
        projectionLabel->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        projectionLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        backgroundLabel = new QLabel(Properties);
        backgroundLabel->setObjectName("backgroundLabel");
        backgroundLabel->setGeometry(QRect(10, 270, 170, 30));
        backgroundLabel->setFont(font2);
        backgroundLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineLabel = new QLabel(Properties);
        lineLabel->setObjectName("lineLabel");
        lineLabel->setGeometry(QRect(9, 50, 170, 30));
        lineLabel->setFont(font2);
        lineLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pointLabel = new QLabel(Properties);
        pointLabel->setObjectName("pointLabel");
        pointLabel->setGeometry(QRect(10, 160, 170, 30));
        pointLabel->setFont(font2);
        pointLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        radioButton_2 = new QRadioButton(Properties);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(20, 30, 60, 20));
        radioButton = new QRadioButton(Properties);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(110, 30, 60, 20));
        lineLabel_2 = new QLabel(Properties);
        lineLabel_2->setObjectName("lineLabel_2");
        lineLabel_2->setGeometry(QRect(20, 110, 50, 20));
        lineLabel_2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        comboBox_2 = new QComboBox(Properties);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(70, 110, 110, 22));
        comboBox_2->setEditable(false);
        lineLabel_3 = new QLabel(Properties);
        lineLabel_3->setObjectName("lineLabel_3");
        lineLabel_3->setGeometry(QRect(20, 140, 50, 20));
        lineLabel_3->setFrameShape(QFrame::Shape::NoFrame);
        horizontalSlider = new QSlider(Properties);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(70, 140, 70, 20));
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);
        comboBox_3 = new QComboBox(Properties);
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(70, 220, 110, 22));
        comboBox_3->setEditable(false);
        pointLabel_3 = new QLabel(Properties);
        pointLabel_3->setObjectName("pointLabel_3");
        pointLabel_3->setGeometry(QRect(20, 250, 50, 20));
        pointLabel_3->setFrameShape(QFrame::Shape::NoFrame);
        pointLabel_2 = new QLabel(Properties);
        pointLabel_2->setObjectName("pointLabel_2");
        pointLabel_2->setGeometry(QRect(20, 220, 50, 20));
        pointLabel_2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        horizontalSlider_2 = new QSlider(Properties);
        horizontalSlider_2->setObjectName("horizontalSlider_2");
        horizontalSlider_2->setGeometry(QRect(70, 250, 70, 20));
        horizontalSlider_2->setOrientation(Qt::Orientation::Horizontal);
        pointLabel_1 = new QLabel(Properties);
        pointLabel_1->setObjectName("pointLabel_1");
        pointLabel_1->setGeometry(QRect(20, 190, 50, 20));
        pointLabel_1->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        comboBox_4 = new QComboBox(Properties);
        comboBox_4->setObjectName("comboBox_4");
        comboBox_4->setGeometry(QRect(70, 190, 110, 22));
        comboBox_4->setEditable(false);
        label_14 = new QLabel(Properties);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(20, 300, 40, 20));
        label_14->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        comboBox_5 = new QComboBox(Properties);
        comboBox_5->setObjectName("comboBox_5");
        comboBox_5->setGeometry(QRect(70, 300, 110, 22));
        comboBox_5->setEditable(false);
        radioButton_3 = new QRadioButton(Properties);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setGeometry(QRect(20, 80, 60, 20));
        radioButton_4 = new QRadioButton(Properties);
        radioButton_4->setObjectName("radioButton_4");
        radioButton_4->setGeometry(QRect(110, 80, 60, 20));
        lineEdit_4 = new QLineEdit(Properties);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(150, 140, 30, 20));
        lineEdit_5 = new QLineEdit(Properties);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(150, 250, 30, 20));
        QIcon icon7(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::DocumentProperties")));
        toolBox->addItem(Properties, icon7, QString::fromUtf8("Properties"));
        pathFile = new QLabel(centralwidget);
        pathFile->setObjectName("pathFile");
        pathFile->setGeometry(QRect(210, 10, 380, 30));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial")});
        font3.setPointSize(16);
        font3.setBold(false);
        pathFile->setFont(font3);
        pathFile_2 = new QLabel(centralwidget);
        pathFile_2->setObjectName("pathFile_2");
        pathFile_2->setGeometry(QRect(10, 10, 35, 30));
        pathFile_2->setFont(font3);
        pathFile_3 = new QLabel(centralwidget);
        pathFile_3->setObjectName("pathFile_3");
        pathFile_3->setGeometry(QRect(110, 10, 35, 30));
        pathFile_3->setFont(font3);
        lineEdit_6 = new QLineEdit(centralwidget);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(50, 10, 40, 30));
        lineEdit_7 = new QLineEdit(centralwidget);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(150, 10, 40, 30));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(1);
        toolBox->layout()->setSpacing(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        openButton->setText(QCoreApplication::translate("MainWindow", " Open File", nullptr));
#if QT_CONFIG(shortcut)
        openButton->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        paintButton->setText(QCoreApplication::translate("MainWindow", " Paint", nullptr));
#if QT_CONFIG(shortcut)
        paintButton->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        shiftButton->setText(QCoreApplication::translate("MainWindow", "SHIFT", nullptr));
#if QT_CONFIG(shortcut)
        shiftButton->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        Shift_X->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        Shift_Y->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        Shift_Z->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        Rotate_X->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        rotateButton->setText(QCoreApplication::translate("MainWindow", "ROTATE", nullptr));
#if QT_CONFIG(shortcut)
        rotateButton->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        Rotate_Z->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        Rotate_Y->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        Scale_X->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        scaleButton->setText(QCoreApplication::translate("MainWindow", "SCALE", nullptr));
#if QT_CONFIG(shortcut)
        scaleButton->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        Scale_Z->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        Scale_Y->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        toolBox->setItemText(toolBox->indexOf(Transform), QCoreApplication::translate("MainWindow", "Transform", nullptr));
        openButton_5->setText(QCoreApplication::translate("MainWindow", " Apply", nullptr));
#if QT_CONFIG(shortcut)
        openButton_5->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        projectionLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>PROJECTION TYPE</p></body></html>", nullptr));
        backgroundLabel->setText(QCoreApplication::translate("MainWindow", "BACKGROUND", nullptr));
        lineLabel->setText(QCoreApplication::translate("MainWindow", "LINE", nullptr));
        pointLabel->setText(QCoreApplication::translate("MainWindow", "POINT", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "Central", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "Parallel", nullptr));
        lineLabel_2->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        lineLabel_3->setText(QCoreApplication::translate("MainWindow", "Width", nullptr));
        pointLabel_3->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        pointLabel_2->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        pointLabel_1->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        radioButton_3->setText(QCoreApplication::translate("MainWindow", "Solid", nullptr));
        radioButton_4->setText(QCoreApplication::translate("MainWindow", "Stipple", nullptr));
        toolBox->setItemText(toolBox->indexOf(Properties), QCoreApplication::translate("MainWindow", "Properties", nullptr));
        pathFile->setText(QCoreApplication::translate("MainWindow", "File Name", nullptr));
        pathFile_2->setText(QCoreApplication::translate("MainWindow", "ver", nullptr));
        pathFile_3->setText(QCoreApplication::translate("MainWindow", "pol", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
