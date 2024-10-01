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
    QToolBox *glWidgetMenu;
    QWidget *Transform;
    QPushButton *rotateButtonX;
    QPushButton *leftButton;
    QPushButton *upButton;
    QPushButton *rightButton;
    QPushButton *downButton;
    QPushButton *closerButton;
    QPushButton *furtherButton;
    QLabel *label;
    QLabel *label_2;
    QPushButton *increaseButton;
    QPushButton *decreaseButton;
    QPushButton *rotateButtonZ;
    QPushButton *rotateButtonY;
    QLabel *label_3;
    QPushButton *rotateButtonX_2;
    QPushButton *rotateButtonY_2;
    QPushButton *rotateButtonZ_2;
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
    QLabel *labelVertex;
    QLabel *labelPolygon;
    QLineEdit *countVertex;
    QLineEdit *countPolygon;

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
        glWidgetMenu = new QToolBox(centralwidget);
        glWidgetMenu->setObjectName("glWidgetMenu");
        glWidgetMenu->setGeometry(QRect(600, 110, 190, 451));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(glWidgetMenu->sizePolicy().hasHeightForWidth());
        glWidgetMenu->setSizePolicy(sizePolicy);
        glWidgetMenu->setFont(font);
        glWidgetMenu->setAcceptDrops(false);
        glWidgetMenu->setToolTipDuration(-1);
        Transform = new QWidget();
        Transform->setObjectName("Transform");
        Transform->setGeometry(QRect(0, 0, 190, 395));
        rotateButtonX = new QPushButton(Transform);
        rotateButtonX->setObjectName("rotateButtonX");
        rotateButtonX->setGeometry(QRect(0, 250, 50, 30));
        rotateButtonX->setFont(font);
        rotateButtonX->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        rotateButtonX->setIconSize(QSize(12, 12));
        leftButton = new QPushButton(Transform);
        leftButton->setObjectName("leftButton");
        leftButton->setGeometry(QRect(0, 40, 40, 30));
        upButton = new QPushButton(Transform);
        upButton->setObjectName("upButton");
        upButton->setGeometry(QRect(50, 40, 40, 30));
        rightButton = new QPushButton(Transform);
        rightButton->setObjectName("rightButton");
        rightButton->setGeometry(QRect(150, 40, 40, 30));
        downButton = new QPushButton(Transform);
        downButton->setObjectName("downButton");
        downButton->setGeometry(QRect(100, 40, 40, 30));
        closerButton = new QPushButton(Transform);
        closerButton->setObjectName("closerButton");
        closerButton->setGeometry(QRect(50, 80, 40, 30));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(15);
        font2.setBold(true);
        closerButton->setFont(font2);
        furtherButton = new QPushButton(Transform);
        furtherButton->setObjectName("furtherButton");
        furtherButton->setGeometry(QRect(100, 80, 40, 30));
        furtherButton->setFont(font2);
        label = new QLabel(Transform);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 0, 170, 30));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial")});
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setUnderline(true);
        label->setFont(font3);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(Transform);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 120, 170, 30));
        label_2->setFont(font3);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        increaseButton = new QPushButton(Transform);
        increaseButton->setObjectName("increaseButton");
        increaseButton->setGeometry(QRect(0, 160, 90, 30));
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::ZoomIn")));
        increaseButton->setIcon(icon2);
        decreaseButton = new QPushButton(Transform);
        decreaseButton->setObjectName("decreaseButton");
        decreaseButton->setGeometry(QRect(100, 160, 90, 30));
        QIcon icon3(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::ZoomOut")));
        decreaseButton->setIcon(icon3);
        rotateButtonZ = new QPushButton(Transform);
        rotateButtonZ->setObjectName("rotateButtonZ");
        rotateButtonZ->setGeometry(QRect(140, 250, 50, 30));
        rotateButtonZ->setFont(font);
        rotateButtonZ->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        QIcon icon4(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::ViewRefresh")));
        rotateButtonZ->setIcon(icon4);
        rotateButtonZ->setIconSize(QSize(12, 12));
        rotateButtonY = new QPushButton(Transform);
        rotateButtonY->setObjectName("rotateButtonY");
        rotateButtonY->setGeometry(QRect(70, 250, 50, 30));
        rotateButtonY->setFont(font);
        rotateButtonY->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        rotateButtonY->setIconSize(QSize(12, 12));
        label_3 = new QLabel(Transform);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 210, 170, 30));
        label_3->setFont(font3);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        rotateButtonX_2 = new QPushButton(Transform);
        rotateButtonX_2->setObjectName("rotateButtonX_2");
        rotateButtonX_2->setGeometry(QRect(0, 290, 50, 30));
        rotateButtonX_2->setFont(font);
        rotateButtonX_2->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        rotateButtonX_2->setIconSize(QSize(12, 12));
        rotateButtonY_2 = new QPushButton(Transform);
        rotateButtonY_2->setObjectName("rotateButtonY_2");
        rotateButtonY_2->setGeometry(QRect(70, 290, 50, 30));
        rotateButtonY_2->setFont(font);
        rotateButtonY_2->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        rotateButtonY_2->setIconSize(QSize(12, 12));
        rotateButtonZ_2 = new QPushButton(Transform);
        rotateButtonZ_2->setObjectName("rotateButtonZ_2");
        rotateButtonZ_2->setGeometry(QRect(140, 290, 50, 30));
        rotateButtonZ_2->setFont(font);
        rotateButtonZ_2->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        QIcon icon5(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::SystemReboot")));
        rotateButtonZ_2->setIcon(icon5);
        rotateButtonZ_2->setIconSize(QSize(12, 12));
        QIcon icon6(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::MailAttachment")));
        glWidgetMenu->addItem(Transform, icon6, QString::fromUtf8("Transform"));
        Properties = new QWidget();
        Properties->setObjectName("Properties");
        Properties->setGeometry(QRect(0, 0, 190, 395));
        Properties->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        openButton_5 = new QPushButton(Properties);
        openButton_5->setObjectName("openButton_5");
        openButton_5->setGeometry(QRect(0, 340, 190, 30));
        openButton_5->setFont(font);
        openButton_5->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        QIcon icon7(QIcon::fromTheme(QString::fromUtf8("appointment-new")));
        openButton_5->setIcon(icon7);
        openButton_5->setIconSize(QSize(12, 12));
        projectionLabel = new QLabel(Properties);
        projectionLabel->setObjectName("projectionLabel");
        projectionLabel->setGeometry(QRect(10, 0, 170, 30));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Arial")});
        font4.setPointSize(12);
        font4.setUnderline(true);
        projectionLabel->setFont(font4);
        projectionLabel->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        projectionLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        backgroundLabel = new QLabel(Properties);
        backgroundLabel->setObjectName("backgroundLabel");
        backgroundLabel->setGeometry(QRect(10, 270, 170, 30));
        backgroundLabel->setFont(font4);
        backgroundLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineLabel = new QLabel(Properties);
        lineLabel->setObjectName("lineLabel");
        lineLabel->setGeometry(QRect(9, 50, 170, 30));
        lineLabel->setFont(font4);
        lineLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pointLabel = new QLabel(Properties);
        pointLabel->setObjectName("pointLabel");
        pointLabel->setGeometry(QRect(10, 160, 170, 30));
        pointLabel->setFont(font4);
        pointLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        radioButton_2 = new QRadioButton(Properties);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(10, 30, 81, 20));
        radioButton = new QRadioButton(Properties);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(90, 30, 91, 20));
        lineLabel_2 = new QLabel(Properties);
        lineLabel_2->setObjectName("lineLabel_2");
        lineLabel_2->setGeometry(QRect(10, 110, 50, 20));
        lineLabel_2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        comboBox_2 = new QComboBox(Properties);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(70, 110, 110, 22));
        comboBox_2->setEditable(false);
        lineLabel_3 = new QLabel(Properties);
        lineLabel_3->setObjectName("lineLabel_3");
        lineLabel_3->setGeometry(QRect(10, 140, 50, 20));
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
        pointLabel_3->setGeometry(QRect(10, 250, 50, 20));
        pointLabel_3->setFrameShape(QFrame::Shape::NoFrame);
        pointLabel_2 = new QLabel(Properties);
        pointLabel_2->setObjectName("pointLabel_2");
        pointLabel_2->setGeometry(QRect(10, 220, 50, 20));
        pointLabel_2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        horizontalSlider_2 = new QSlider(Properties);
        horizontalSlider_2->setObjectName("horizontalSlider_2");
        horizontalSlider_2->setGeometry(QRect(70, 250, 70, 20));
        horizontalSlider_2->setOrientation(Qt::Orientation::Horizontal);
        pointLabel_1 = new QLabel(Properties);
        pointLabel_1->setObjectName("pointLabel_1");
        pointLabel_1->setGeometry(QRect(10, 190, 50, 20));
        pointLabel_1->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        comboBox_4 = new QComboBox(Properties);
        comboBox_4->setObjectName("comboBox_4");
        comboBox_4->setGeometry(QRect(70, 190, 110, 22));
        comboBox_4->setEditable(false);
        label_14 = new QLabel(Properties);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 300, 40, 20));
        label_14->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        comboBox_5 = new QComboBox(Properties);
        comboBox_5->setObjectName("comboBox_5");
        comboBox_5->setGeometry(QRect(70, 300, 110, 22));
        comboBox_5->setEditable(false);
        radioButton_3 = new QRadioButton(Properties);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setGeometry(QRect(10, 80, 71, 20));
        radioButton_4 = new QRadioButton(Properties);
        radioButton_4->setObjectName("radioButton_4");
        radioButton_4->setGeometry(QRect(90, 80, 91, 20));
        lineEdit_4 = new QLineEdit(Properties);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(150, 140, 30, 20));
        lineEdit_5 = new QLineEdit(Properties);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(150, 250, 30, 20));
        QIcon icon8(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::DocumentProperties")));
        glWidgetMenu->addItem(Properties, icon8, QString::fromUtf8("Properties"));
        pathFile = new QLabel(centralwidget);
        pathFile->setObjectName("pathFile");
        pathFile->setGeometry(QRect(210, 10, 380, 30));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Arial")});
        font5.setPointSize(16);
        font5.setBold(false);
        pathFile->setFont(font5);
        labelVertex = new QLabel(centralwidget);
        labelVertex->setObjectName("labelVertex");
        labelVertex->setGeometry(QRect(10, 10, 35, 30));
        labelVertex->setFont(font5);
        labelPolygon = new QLabel(centralwidget);
        labelPolygon->setObjectName("labelPolygon");
        labelPolygon->setGeometry(QRect(110, 10, 35, 30));
        labelPolygon->setFont(font5);
        countVertex = new QLineEdit(centralwidget);
        countVertex->setObjectName("countVertex");
        countVertex->setGeometry(QRect(50, 10, 40, 30));
        countPolygon = new QLineEdit(centralwidget);
        countPolygon->setObjectName("countPolygon");
        countPolygon->setGeometry(QRect(150, 10, 40, 30));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        glWidgetMenu->setCurrentIndex(0);
        glWidgetMenu->layout()->setSpacing(4);


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
        rotateButtonX->setText(QCoreApplication::translate("MainWindow", "\342\226\262 X", nullptr));
#if QT_CONFIG(shortcut)
        rotateButtonX->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        leftButton->setText(QCoreApplication::translate("MainWindow", "\342\227\204", nullptr));
        upButton->setText(QCoreApplication::translate("MainWindow", "\342\226\262", nullptr));
        rightButton->setText(QCoreApplication::translate("MainWindow", "\342\226\272", nullptr));
        downButton->setText(QCoreApplication::translate("MainWindow", "\342\226\274", nullptr));
        closerButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        furtherButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "_________SHIFT_________", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "________SCALE________", nullptr));
        increaseButton->setText(QString());
        decreaseButton->setText(QString());
        rotateButtonZ->setText(QCoreApplication::translate("MainWindow", " Z", nullptr));
#if QT_CONFIG(shortcut)
        rotateButtonZ->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        rotateButtonY->setText(QCoreApplication::translate("MainWindow", "\342\227\204 Y", nullptr));
#if QT_CONFIG(shortcut)
        rotateButtonY->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        label_3->setText(QCoreApplication::translate("MainWindow", "________ROTATE________", nullptr));
        rotateButtonX_2->setText(QCoreApplication::translate("MainWindow", "\342\226\274 X", nullptr));
#if QT_CONFIG(shortcut)
        rotateButtonX_2->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        rotateButtonY_2->setText(QCoreApplication::translate("MainWindow", "\342\226\272 Y", nullptr));
#if QT_CONFIG(shortcut)
        rotateButtonY_2->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        rotateButtonZ_2->setText(QCoreApplication::translate("MainWindow", " Z", nullptr));
#if QT_CONFIG(shortcut)
        rotateButtonZ_2->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        glWidgetMenu->setItemText(glWidgetMenu->indexOf(Transform), QCoreApplication::translate("MainWindow", "Transform", nullptr));
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
        radioButton_4->setText(QCoreApplication::translate("MainWindow", "Dashed", nullptr));
        glWidgetMenu->setItemText(glWidgetMenu->indexOf(Properties), QCoreApplication::translate("MainWindow", "Properties", nullptr));
        pathFile->setText(QCoreApplication::translate("MainWindow", "File Name", nullptr));
        labelVertex->setText(QCoreApplication::translate("MainWindow", "ver", nullptr));
        labelPolygon->setText(QCoreApplication::translate("MainWindow", "pol", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
