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
#include <QtWidgets/QGroupBox>
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
    QPushButton *applyButton;
    QLabel *backgroundLabel;
    QLabel *lineLabel;
    QLabel *pointLabel;
    QLabel *lineLabel_2;
    QComboBox *comboBoxLineColor;
    QLabel *lineLabel_3;
    QSlider *sliderLineWidth;
    QComboBox *comboBoxPointColor;
    QLabel *pointLabel_3;
    QLabel *pointLabel_2;
    QSlider *sliderPointSize;
    QLabel *pointLabel_1;
    QComboBox *comboBoxPointType;
    QLabel *label_14;
    QComboBox *comboBoxBackColor;
    QLineEdit *lineEditLineWidth;
    QLineEdit *lineEditPointSize;
    QGroupBox *groupBox;
    QRadioButton *radioTypeCentral;
    QRadioButton *radioTypeParallel;
    QGroupBox *groupBox_2;
    QRadioButton *radioLineSolid;
    QRadioButton *radioLineDashed;
    QLabel *pathFile;
    QLabel *labelVertex;
    QLabel *labelPolygon;
    QLineEdit *countVertex;
    QLineEdit *countPolygon;
    QLabel *projectionLabel;

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
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("QIcon::ThemeIcon::DocumentOpen");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
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
        QIcon icon1;
        iconThemeName = QString::fromUtf8("QIcon::ThemeIcon::MailMessageNew");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
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
        label_2 = new QLabel(Transform);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 120, 170, 30));
        label_2->setFont(font3);
        increaseButton = new QPushButton(Transform);
        increaseButton->setObjectName("increaseButton");
        increaseButton->setGeometry(QRect(0, 160, 90, 30));
        QIcon icon2;
        iconThemeName = QString::fromUtf8("QIcon::ThemeIcon::ZoomIn");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        increaseButton->setIcon(icon2);
        decreaseButton = new QPushButton(Transform);
        decreaseButton->setObjectName("decreaseButton");
        decreaseButton->setGeometry(QRect(100, 160, 90, 30));
        QIcon icon3;
        iconThemeName = QString::fromUtf8("QIcon::ThemeIcon::ZoomOut");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        decreaseButton->setIcon(icon3);
        rotateButtonZ = new QPushButton(Transform);
        rotateButtonZ->setObjectName("rotateButtonZ");
        rotateButtonZ->setGeometry(QRect(140, 250, 50, 30));
        rotateButtonZ->setFont(font);
        rotateButtonZ->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        QIcon icon4;
        iconThemeName = QString::fromUtf8("QIcon::ThemeIcon::ViewRefresh");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon4 = QIcon::fromTheme(iconThemeName);
        } else {
            icon4.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
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
        QIcon icon5;
        iconThemeName = QString::fromUtf8("QIcon::ThemeIcon::SystemReboot");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon5 = QIcon::fromTheme(iconThemeName);
        } else {
            icon5.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        rotateButtonZ_2->setIcon(icon5);
        rotateButtonZ_2->setIconSize(QSize(12, 12));
        QIcon icon6;
        iconThemeName = QString::fromUtf8("QIcon::ThemeIcon::MailAttachment");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon6 = QIcon::fromTheme(iconThemeName);
        } else {
            icon6.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        glWidgetMenu->addItem(Transform, icon6, QString::fromUtf8("Transform"));
        Properties = new QWidget();
        Properties->setObjectName("Properties");
        Properties->setGeometry(QRect(0, 0, 190, 395));
        Properties->setContextMenuPolicy(Qt::NoContextMenu);
        applyButton = new QPushButton(Properties);
        applyButton->setObjectName("applyButton");
        applyButton->setGeometry(QRect(0, 350, 190, 30));
        applyButton->setFont(font);
        applyButton->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        QIcon icon7;
        iconThemeName = QString::fromUtf8("appointment-new");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon7 = QIcon::fromTheme(iconThemeName);
        } else {
            icon7.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        applyButton->setIcon(icon7);
        applyButton->setIconSize(QSize(12, 12));
        backgroundLabel = new QLabel(Properties);
        backgroundLabel->setObjectName("backgroundLabel");
        backgroundLabel->setGeometry(QRect(10, 270, 170, 30));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Arial")});
        font4.setPointSize(12);
        font4.setUnderline(true);
        backgroundLabel->setFont(font4);
        backgroundLabel->setAlignment(Qt::AlignCenter);
        lineLabel = new QLabel(Properties);
        lineLabel->setObjectName("lineLabel");
        lineLabel->setGeometry(QRect(10, 40, 170, 21));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Arial")});
        font5.setPointSize(14);
        font5.setUnderline(true);
        lineLabel->setFont(font5);
        lineLabel->setLayoutDirection(Qt::LeftToRight);
        lineLabel->setAlignment(Qt::AlignCenter);
        pointLabel = new QLabel(Properties);
        pointLabel->setObjectName("pointLabel");
        pointLabel->setGeometry(QRect(10, 160, 170, 30));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Arial")});
        font6.setPointSize(16);
        font6.setUnderline(true);
        pointLabel->setFont(font6);
        pointLabel->setAlignment(Qt::AlignCenter);
        lineLabel_2 = new QLabel(Properties);
        lineLabel_2->setObjectName("lineLabel_2");
        lineLabel_2->setGeometry(QRect(10, 100, 50, 20));
        lineLabel_2->setFont(font);
        lineLabel_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        comboBoxLineColor = new QComboBox(Properties);
        comboBoxLineColor->setObjectName("comboBoxLineColor");
        comboBoxLineColor->setGeometry(QRect(70, 100, 110, 22));
        comboBoxLineColor->setEditable(false);
        lineLabel_3 = new QLabel(Properties);
        lineLabel_3->setObjectName("lineLabel_3");
        lineLabel_3->setGeometry(QRect(10, 130, 51, 31));
        lineLabel_3->setFrameShape(QFrame::NoFrame);
        sliderLineWidth = new QSlider(Properties);
        sliderLineWidth->setObjectName("sliderLineWidth");
        sliderLineWidth->setGeometry(QRect(60, 130, 81, 31));
        sliderLineWidth->setOrientation(Qt::Horizontal);
        comboBoxPointColor = new QComboBox(Properties);
        comboBoxPointColor->setObjectName("comboBoxPointColor");
        comboBoxPointColor->setGeometry(QRect(70, 220, 110, 22));
        comboBoxPointColor->setEditable(false);
        pointLabel_3 = new QLabel(Properties);
        pointLabel_3->setObjectName("pointLabel_3");
        pointLabel_3->setGeometry(QRect(10, 240, 50, 20));
        pointLabel_3->setFrameShape(QFrame::NoFrame);
        pointLabel_2 = new QLabel(Properties);
        pointLabel_2->setObjectName("pointLabel_2");
        pointLabel_2->setGeometry(QRect(10, 220, 50, 20));
        sliderPointSize = new QSlider(Properties);
        sliderPointSize->setObjectName("sliderPointSize");
        sliderPointSize->setGeometry(QRect(70, 240, 70, 31));
        sliderPointSize->setOrientation(Qt::Horizontal);
        pointLabel_1 = new QLabel(Properties);
        pointLabel_1->setObjectName("pointLabel_1");
        pointLabel_1->setGeometry(QRect(10, 190, 50, 20));
        comboBoxPointType = new QComboBox(Properties);
        comboBoxPointType->setObjectName("comboBoxPointType");
        comboBoxPointType->setGeometry(QRect(70, 190, 110, 22));
        comboBoxPointType->setEditable(false);
        label_14 = new QLabel(Properties);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 300, 40, 20));
        comboBoxBackColor = new QComboBox(Properties);
        comboBoxBackColor->setObjectName("comboBoxBackColor");
        comboBoxBackColor->setGeometry(QRect(70, 300, 110, 22));
        comboBoxBackColor->setEditable(false);
        lineEditLineWidth = new QLineEdit(Properties);
        lineEditLineWidth->setObjectName("lineEditLineWidth");
        lineEditLineWidth->setGeometry(QRect(150, 130, 30, 20));
        lineEditPointSize = new QLineEdit(Properties);
        lineEditPointSize->setObjectName("lineEditPointSize");
        lineEditPointSize->setGeometry(QRect(150, 250, 30, 20));
        groupBox = new QGroupBox(Properties);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 0, 171, 41));
        groupBox->setFont(font);
        groupBox->setAlignment(Qt::AlignCenter);
        radioTypeCentral = new QRadioButton(groupBox);
        radioTypeCentral->setObjectName("radioTypeCentral");
        radioTypeCentral->setGeometry(QRect(0, 20, 81, 20));
        radioTypeParallel = new QRadioButton(groupBox);
        radioTypeParallel->setObjectName("radioTypeParallel");
        radioTypeParallel->setGeometry(QRect(80, 20, 91, 20));
        groupBox_2 = new QGroupBox(Properties);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 70, 171, 21));
        radioLineSolid = new QRadioButton(groupBox_2);
        radioLineSolid->setObjectName("radioLineSolid");
        radioLineSolid->setGeometry(QRect(0, 0, 71, 20));
        radioLineDashed = new QRadioButton(groupBox_2);
        radioLineDashed->setObjectName("radioLineDashed");
        radioLineDashed->setGeometry(QRect(80, 0, 91, 20));
        QIcon icon8;
        iconThemeName = QString::fromUtf8("QIcon::ThemeIcon::DocumentProperties");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon8 = QIcon::fromTheme(iconThemeName);
        } else {
            icon8.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        glWidgetMenu->addItem(Properties, icon8, QString::fromUtf8("Properties"));
        pathFile = new QLabel(centralwidget);
        pathFile->setObjectName("pathFile");
        pathFile->setGeometry(QRect(210, 10, 380, 30));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Arial")});
        font7.setPointSize(16);
        font7.setBold(false);
        pathFile->setFont(font7);
        labelVertex = new QLabel(centralwidget);
        labelVertex->setObjectName("labelVertex");
        labelVertex->setGeometry(QRect(10, 10, 35, 30));
        labelVertex->setFont(font7);
        labelPolygon = new QLabel(centralwidget);
        labelPolygon->setObjectName("labelPolygon");
        labelPolygon->setGeometry(QRect(110, 10, 35, 30));
        labelPolygon->setFont(font7);
        countVertex = new QLineEdit(centralwidget);
        countVertex->setObjectName("countVertex");
        countVertex->setGeometry(QRect(40, 10, 61, 30));
        countPolygon = new QLineEdit(centralwidget);
        countPolygon->setObjectName("countPolygon");
        countPolygon->setGeometry(QRect(139, 10, 61, 30));
        projectionLabel = new QLabel(centralwidget);
        projectionLabel->setObjectName("projectionLabel");
        projectionLabel->setGeometry(QRect(610, 60, 170, 30));
        projectionLabel->setFont(font4);
        projectionLabel->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        glWidgetMenu->setCurrentIndex(1);
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
        applyButton->setText(QCoreApplication::translate("MainWindow", " Apply", nullptr));
#if QT_CONFIG(shortcut)
        applyButton->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        backgroundLabel->setText(QCoreApplication::translate("MainWindow", "BACKGROUND", nullptr));
        lineLabel->setText(QCoreApplication::translate("MainWindow", "LINE", nullptr));
        pointLabel->setText(QCoreApplication::translate("MainWindow", "POINT", nullptr));
        lineLabel_2->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        lineLabel_3->setText(QCoreApplication::translate("MainWindow", "Width", nullptr));
        pointLabel_3->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        pointLabel_2->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        pointLabel_1->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "PROJECTION TYPE", nullptr));
        radioTypeCentral->setText(QCoreApplication::translate("MainWindow", "Central", nullptr));
        radioTypeParallel->setText(QCoreApplication::translate("MainWindow", "Parallel", nullptr));
        groupBox_2->setTitle(QString());
        radioLineSolid->setText(QCoreApplication::translate("MainWindow", "Solid", nullptr));
        radioLineDashed->setText(QCoreApplication::translate("MainWindow", "Dashed", nullptr));
        glWidgetMenu->setItemText(glWidgetMenu->indexOf(Properties), QCoreApplication::translate("MainWindow", "Properties", nullptr));
        pathFile->setText(QCoreApplication::translate("MainWindow", "File Name", nullptr));
        labelVertex->setText(QCoreApplication::translate("MainWindow", "ver", nullptr));
        labelPolygon->setText(QCoreApplication::translate("MainWindow", "pol", nullptr));
        projectionLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>PROJECTION TYPE</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
