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
#include <QtWidgets/QSplitter>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
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
    QLineEdit *lineEdit_2;
    QPushButton *rotateButtonZ;
    QPushButton *rotateButtonZ_2;
    QLineEdit *lineEdit_3;
    QSplitter *splitter_33;
    QPushButton *increaseButton;
    QLineEdit *lineEdit_13;
    QPushButton *decreaseButton;
    QPushButton *rotateButtonZ1;
    QPushButton *rotateButtonZ_2;
    QLineEdit *lineEdit_3;
    QSplitter *splitter_33;
    QPushButton *increaseButton1;
    QLineEdit *lineEdit_13;
    QPushButton *decreaseButton1;
    QWidget *Properties;
    QWidget *layoutWidget;
    QVBoxLayout *vert;
    QLabel *lineLabel_4;
    QSplitter *splitter;
    QRadioButton *radioTypeCentral;
    QRadioButton *radioTypeParallel;
    QLabel *lineLabel;
    QSplitter *splitter_2;
    QRadioButton *radioLineSolid;
    QRadioButton *radioLineDashed;
    QSplitter *splitter_3;
    QLabel *lineLabel_2;
    QComboBox *comboBoxLineColor;
    QSplitter *splitter_8;
    QLabel *lineLabel_3;
    QSlider *sliderLineWidth;
    QLineEdit *lineEditLineWidth;
    QLabel *pointLabel;
    QSplitter *splitter_4;
    QLabel *pointLabel_1;
    QComboBox *comboBoxPointType;
    QSplitter *splitter_5;
    QLabel *pointLabel_2;
    QComboBox *comboBoxPointColor;
    QSplitter *splitter_6;
    QLabel *pointLabel_3;
    QSlider *sliderPointSize;
    QLineEdit *lineEditPointSize;
    QLabel *backgroundLabel;
    QSplitter *splitter_7;
    QLabel *label_14;
    QComboBox *comboBoxBackColor;
    QPushButton *applyButton;
    QWidget *Snapshot;
    QPushButton *jpegButton;
    QPushButton *bmpButton;
    QPushButton *gifButton;
    QLabel *pathFile;
    QLabel *labelVertex;
    QLabel *labelPolygon;
    QLineEdit *countVertex;
    QLineEdit *countPolygon;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(801, 652);
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
        paintButton->setGeometry(QRect(600, 600, 191, 32));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(14);
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
        glWidgetMenu->setGeometry(QRect(600, 40, 190, 541));
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
        Transform->setGeometry(QRect(0, 0, 190, 485));
        rotateButtonX = new QPushButton(Transform);
        rotateButtonX->setObjectName("rotateButtonX");
        rotateButtonX->setGeometry(QRect(59, 260, 55, 32));
        rotateButtonX->setFont(font);
        rotateButtonX->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        rotateButtonX->setIconSize(QSize(12, 12));
        leftButton = new QPushButton(Transform);
        leftButton->setObjectName("leftButton");
        leftButton->setGeometry(QRect(0, 60, 55, 32));
        upButton = new QPushButton(Transform);
        upButton->setObjectName("upButton");
        upButton->setGeometry(QRect(59, 29, 55, 32));
        rightButton = new QPushButton(Transform);
        rightButton->setObjectName("rightButton");
        rightButton->setGeometry(QRect(120, 60, 55, 32));
        downButton = new QPushButton(Transform);
        downButton->setObjectName("downButton");
        downButton->setGeometry(QRect(60, 90, 55, 32));
        closerButton = new QPushButton(Transform);
        closerButton->setObjectName("closerButton");
        closerButton->setGeometry(QRect(0, 90, 31, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(15);
        font2.setBold(true);
        closerButton->setFont(font2);
        furtherButton = new QPushButton(Transform);
        furtherButton->setObjectName("furtherButton");
        furtherButton->setGeometry(QRect(140, 30, 31, 31));
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
        label_2->setGeometry(QRect(10, 130, 170, 30));
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
        rotateButtonY->setGeometry(QRect(0, 290, 55, 32));
        rotateButtonY->setFont(font);
        rotateButtonY->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        rotateButtonY->setIconSize(QSize(12, 12));
        label_3 = new QLabel(Transform);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 220, 170, 30));
        label_3->setFont(font3);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        rotateButtonX_2 = new QPushButton(Transform);
        rotateButtonX_2->setObjectName("rotateButtonX_2");
        rotateButtonX_2->setGeometry(QRect(60, 330, 55, 32));
        rotateButtonX_2->setFont(font);
        rotateButtonX_2->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        rotateButtonX_2->setIconSize(QSize(12, 12));
        rotateButtonY_2 = new QPushButton(Transform);
        rotateButtonY_2->setObjectName("rotateButtonY_2");
        rotateButtonY_2->setGeometry(QRect(120, 290, 55, 32));
        rotateButtonY_2->setFont(font);
        rotateButtonY_2->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        rotateButtonY_2->setIconSize(QSize(12, 12));
        lineEdit_2 = new QLineEdit(Transform);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(60, 290, 51, 32));
        rotateButtonZ = new QPushButton(Transform);
        rotateButtonZ->setObjectName("rotateButtonZ");
        rotateButtonZ->setGeometry(QRect(120, 260, 55, 32));
        rotateButtonZ->setFont(font);
        rotateButtonZ->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        QIcon icon2;
        iconThemeName = QString::fromUtf8("QIcon::ThemeIcon::ViewRefresh");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        rotateButtonZ->setIcon(icon2);
        rotateButtonZ->setIconSize(QSize(12, 12));
        rotateButtonZ_2 = new QPushButton(Transform);
        rotateButtonZ_2->setObjectName("rotateButtonZ_2");
        rotateButtonZ_2->setGeometry(QRect(0, 330, 55, 32));
        rotateButtonZ_2->setFont(font);
        rotateButtonZ_2->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        QIcon icon3;
        iconThemeName = QString::fromUtf8("QIcon::ThemeIcon::SystemReboot");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        rotateButtonZ_2->setIcon(icon3);
        rotateButtonZ_2->setIconSize(QSize(12, 12));
        lineEdit_3 = new QLineEdit(Transform);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(60, 60, 51, 32));
        splitter_33 = new QSplitter(Transform);
        splitter_33->setObjectName("splitter_33");
        splitter_33->setGeometry(QRect(0, 170, 171, 32));
        splitter_33->setOrientation(Qt::Horizontal);
        increaseButton = new QPushButton(splitter_33);
        increaseButton->setObjectName("increaseButton");
        QIcon icon4;
        iconThemeName = QString::fromUtf8("QIcon::ThemeIcon::ZoomIn");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon4 = QIcon::fromTheme(iconThemeName);
        } else {
            icon4.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        increaseButton->setIcon(icon4);
        splitter_33->addWidget(increaseButton);
        lineEdit_13 = new QLineEdit(splitter_33);
        lineEdit_13->setObjectName("lineEdit_13");
        splitter_33->addWidget(lineEdit_13);
        decreaseButton = new QPushButton(splitter_33);
        decreaseButton->setObjectName("decreaseButton");
        QIcon icon5;
        iconThemeName = QString::fromUtf8("QIcon::ThemeIcon::ZoomOut");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon5 = QIcon::fromTheme(iconThemeName);
        } else {
            icon5.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        decreaseButton->setIcon(icon5);
        splitter_33->addWidget(decreaseButton);
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
        Properties->setGeometry(QRect(0, 0, 190, 485));
        Properties->setContextMenuPolicy(Qt::NoContextMenu);
        layoutWidget = new QWidget(Properties);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 191, 441));
        vert = new QVBoxLayout(layoutWidget);
        vert->setObjectName("vert");
        vert->setContentsMargins(0, 0, 0, 0);
        lineLabel_4 = new QLabel(layoutWidget);
        lineLabel_4->setObjectName("lineLabel_4");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Arial")});
        font4.setPointSize(14);
        font4.setUnderline(true);
        lineLabel_4->setFont(font4);
        lineLabel_4->setLayoutDirection(Qt::LeftToRight);
        lineLabel_4->setAlignment(Qt::AlignCenter);

        vert->addWidget(lineLabel_4);

        splitter = new QSplitter(layoutWidget);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        radioTypeCentral = new QRadioButton(splitter);
        radioTypeCentral->setObjectName("radioTypeCentral");
        radioTypeCentral->setChecked(true);
        splitter->addWidget(radioTypeCentral);
        radioTypeParallel = new QRadioButton(splitter);
        radioTypeParallel->setObjectName("radioTypeParallel");
        splitter->addWidget(radioTypeParallel);

        vert->addWidget(splitter);

        lineLabel = new QLabel(layoutWidget);
        lineLabel->setObjectName("lineLabel");
        lineLabel->setFont(font4);
        lineLabel->setLayoutDirection(Qt::LeftToRight);
        lineLabel->setAlignment(Qt::AlignCenter);

        vert->addWidget(lineLabel);

        splitter_2 = new QSplitter(layoutWidget);
        splitter_2->setObjectName("splitter_2");
        splitter_2->setOrientation(Qt::Horizontal);
        radioLineSolid = new QRadioButton(splitter_2);
        radioLineSolid->setObjectName("radioLineSolid");
        radioLineSolid->setChecked(true);
        splitter_2->addWidget(radioLineSolid);
        radioLineDashed = new QRadioButton(splitter_2);
        radioLineDashed->setObjectName("radioLineDashed");
        splitter_2->addWidget(radioLineDashed);

        vert->addWidget(splitter_2);

        splitter_3 = new QSplitter(layoutWidget);
        splitter_3->setObjectName("splitter_3");
        splitter_3->setOrientation(Qt::Horizontal);
        lineLabel_2 = new QLabel(splitter_3);
        lineLabel_2->setObjectName("lineLabel_2");
        lineLabel_2->setFont(font);
        lineLabel_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        splitter_3->addWidget(lineLabel_2);
        comboBoxLineColor = new QComboBox(splitter_3);
        comboBoxLineColor->addItem(QString());
        comboBoxLineColor->addItem(QString());
        comboBoxLineColor->addItem(QString());
        comboBoxLineColor->addItem(QString());
        comboBoxLineColor->addItem(QString());
        comboBoxLineColor->addItem(QString());
        comboBoxLineColor->addItem(QString());
        comboBoxLineColor->addItem(QString());
        comboBoxLineColor->addItem(QString());
        comboBoxLineColor->setObjectName("comboBoxLineColor");
        comboBoxLineColor->setEditable(false);
        splitter_3->addWidget(comboBoxLineColor);

        vert->addWidget(splitter_3);

        splitter_8 = new QSplitter(layoutWidget);
        splitter_8->setObjectName("splitter_8");
        splitter_8->setOrientation(Qt::Horizontal);
        lineLabel_3 = new QLabel(splitter_8);
        lineLabel_3->setObjectName("lineLabel_3");
        lineLabel_3->setFrameShape(QFrame::NoFrame);
        splitter_8->addWidget(lineLabel_3);
        sliderLineWidth = new QSlider(splitter_8);
        sliderLineWidth->setObjectName("sliderLineWidth");
        sliderLineWidth->setMinimum(1);
        sliderLineWidth->setValue(1);
        sliderLineWidth->setOrientation(Qt::Horizontal);
        splitter_8->addWidget(sliderLineWidth);
        lineEditLineWidth = new QLineEdit(splitter_8);
        lineEditLineWidth->setObjectName("lineEditLineWidth");
        splitter_8->addWidget(lineEditLineWidth);

        vert->addWidget(splitter_8);

        pointLabel = new QLabel(layoutWidget);
        pointLabel->setObjectName("pointLabel");
        pointLabel->setFont(font4);
        pointLabel->setAlignment(Qt::AlignCenter);

        vert->addWidget(pointLabel);

        splitter_4 = new QSplitter(layoutWidget);
        splitter_4->setObjectName("splitter_4");
        splitter_4->setOrientation(Qt::Horizontal);
        pointLabel_1 = new QLabel(splitter_4);
        pointLabel_1->setObjectName("pointLabel_1");
        splitter_4->addWidget(pointLabel_1);
        comboBoxPointType = new QComboBox(splitter_4);
        comboBoxPointType->addItem(QString());
        comboBoxPointType->addItem(QString());
        comboBoxPointType->addItem(QString());
        comboBoxPointType->setObjectName("comboBoxPointType");
        comboBoxPointType->setEditable(false);
        splitter_4->addWidget(comboBoxPointType);

        vert->addWidget(splitter_4);

        splitter_5 = new QSplitter(layoutWidget);
        splitter_5->setObjectName("splitter_5");
        splitter_5->setOrientation(Qt::Horizontal);
        pointLabel_2 = new QLabel(splitter_5);
        pointLabel_2->setObjectName("pointLabel_2");
        splitter_5->addWidget(pointLabel_2);
        comboBoxPointColor = new QComboBox(splitter_5);
        comboBoxPointColor->addItem(QString());
        comboBoxPointColor->addItem(QString());
        comboBoxPointColor->addItem(QString());
        comboBoxPointColor->addItem(QString());
        comboBoxPointColor->addItem(QString());
        comboBoxPointColor->addItem(QString());
        comboBoxPointColor->addItem(QString());
        comboBoxPointColor->addItem(QString());
        comboBoxPointColor->addItem(QString());
        comboBoxPointColor->setObjectName("comboBoxPointColor");
        comboBoxPointColor->setEditable(false);
        splitter_5->addWidget(comboBoxPointColor);

        vert->addWidget(splitter_5);

        splitter_6 = new QSplitter(layoutWidget);
        splitter_6->setObjectName("splitter_6");
        splitter_6->setOrientation(Qt::Horizontal);
        pointLabel_3 = new QLabel(splitter_6);
        pointLabel_3->setObjectName("pointLabel_3");
        pointLabel_3->setFrameShape(QFrame::NoFrame);
        splitter_6->addWidget(pointLabel_3);
        sliderPointSize = new QSlider(splitter_6);
        sliderPointSize->setObjectName("sliderPointSize");
        sliderPointSize->setMinimum(1);
        sliderPointSize->setOrientation(Qt::Horizontal);
        splitter_6->addWidget(sliderPointSize);
        lineEditPointSize = new QLineEdit(splitter_6);
        lineEditPointSize->setObjectName("lineEditPointSize");
        splitter_6->addWidget(lineEditPointSize);

        vert->addWidget(splitter_6);

        backgroundLabel = new QLabel(layoutWidget);
        backgroundLabel->setObjectName("backgroundLabel");
        backgroundLabel->setFont(font4);
        backgroundLabel->setAlignment(Qt::AlignCenter);

        vert->addWidget(backgroundLabel);

        splitter_7 = new QSplitter(layoutWidget);
        splitter_7->setObjectName("splitter_7");
        splitter_7->setOrientation(Qt::Horizontal);
        label_14 = new QLabel(splitter_7);
        label_14->setObjectName("label_14");
        splitter_7->addWidget(label_14);
        comboBoxBackColor = new QComboBox(splitter_7);
        comboBoxBackColor->addItem(QString());
        comboBoxBackColor->addItem(QString());
        comboBoxBackColor->addItem(QString());
        comboBoxBackColor->addItem(QString());
        comboBoxBackColor->addItem(QString());
        comboBoxBackColor->addItem(QString());
        comboBoxBackColor->addItem(QString());
        comboBoxBackColor->addItem(QString());
        comboBoxBackColor->addItem(QString());
        comboBoxBackColor->setObjectName("comboBoxBackColor");
        comboBoxBackColor->setEditable(false);
        splitter_7->addWidget(comboBoxBackColor);

        vert->addWidget(splitter_7);

        applyButton = new QPushButton(layoutWidget);
        applyButton->setObjectName("applyButton");
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Arial")});
        font5.setPointSize(14);
        applyButton->setFont(font5);
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

        vert->addWidget(applyButton);

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
        pathFile->setGeometry(QRect(219, 10, 371, 30));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Arial")});
        font6.setPointSize(16);
        font6.setBold(false);
        pathFile->setFont(font6);
        labelVertex = new QLabel(centralwidget);
        labelVertex->setObjectName("labelVertex");
        labelVertex->setGeometry(QRect(10, 10, 35, 30));
        labelVertex->setFont(font6);
        labelPolygon = new QLabel(centralwidget);
        labelPolygon->setObjectName("labelPolygon");
        labelPolygon->setGeometry(QRect(110, 10, 35, 30));
        labelPolygon->setFont(font6);
        countVertex = new QLineEdit(centralwidget);
        countVertex->setObjectName("countVertex");
        countVertex->setGeometry(QRect(40, 10, 61, 30));
        countPolygon = new QLineEdit(centralwidget);
        countPolygon->setObjectName("countPolygon");
        countPolygon->setGeometry(QRect(139, 10, 61, 30));
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
        rotateButtonZ->setText(QCoreApplication::translate("MainWindow", " Z", nullptr));
#if QT_CONFIG(shortcut)
        rotateButtonZ->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        rotateButtonZ_2->setText(QCoreApplication::translate("MainWindow", " Z", nullptr));
#if QT_CONFIG(shortcut)
        rotateButtonZ_2->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        increaseButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        decreaseButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        glWidgetMenu->setItemText(glWidgetMenu->indexOf(Transform), QCoreApplication::translate("MainWindow", "Transform", nullptr));
        lineLabel_4->setText(QCoreApplication::translate("MainWindow", "PROJECTION TYPE", nullptr));
        radioTypeCentral->setText(QCoreApplication::translate("MainWindow", "Central", nullptr));
        radioTypeParallel->setText(QCoreApplication::translate("MainWindow", "Parallel", nullptr));
        lineLabel->setText(QCoreApplication::translate("MainWindow", "LINE", nullptr));
        radioLineSolid->setText(QCoreApplication::translate("MainWindow", "Solid", nullptr));
        radioLineDashed->setText(QCoreApplication::translate("MainWindow", "Dashed", nullptr));
        lineLabel_2->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        comboBoxLineColor->setItemText(0, QCoreApplication::translate("MainWindow", "\320\266\320\265\320\273\321\202\321\213\320\271", nullptr));
        comboBoxLineColor->setItemText(1, QCoreApplication::translate("MainWindow", "\321\204\320\270\320\276\320\273\320\265\321\202\320\276\320\262\321\213\320\271", nullptr));
        comboBoxLineColor->setItemText(2, QCoreApplication::translate("MainWindow", "\321\207\320\265\321\200\320\275\321\213\320\271", nullptr));
        comboBoxLineColor->setItemText(3, QCoreApplication::translate("MainWindow", "\320\272\321\200\320\260\321\201\320\275\321\213\320\271", nullptr));
        comboBoxLineColor->setItemText(4, QCoreApplication::translate("MainWindow", "\321\201\320\270\320\275\320\270\320\271", nullptr));
        comboBoxLineColor->setItemText(5, QCoreApplication::translate("MainWindow", "\320\267\320\265\320\273\320\265\320\275\321\213\320\271", nullptr));
        comboBoxLineColor->setItemText(6, QCoreApplication::translate("MainWindow", "\320\276\321\200\320\260\320\275\320\266\320\265\320\262\321\213\320\271", nullptr));
        comboBoxLineColor->setItemText(7, QCoreApplication::translate("MainWindow", "\320\261\320\265\320\273\321\213\320\271", nullptr));
        comboBoxLineColor->setItemText(8, QCoreApplication::translate("MainWindow", "\321\200\320\260\320\275\320\264\320\276\320\274\320\275\321\213\320\271", nullptr));

        lineLabel_3->setText(QCoreApplication::translate("MainWindow", "Width", nullptr));
        lineEditLineWidth->setInputMask(QCoreApplication::translate("MainWindow", "d0", nullptr));
        lineEditLineWidth->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pointLabel->setText(QCoreApplication::translate("MainWindow", "POINT", nullptr));
        pointLabel_1->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        comboBoxPointType->setItemText(0, QCoreApplication::translate("MainWindow", "\320\232\321\200\321\203\320\263\320\273\321\213\320\265", nullptr));
        comboBoxPointType->setItemText(1, QCoreApplication::translate("MainWindow", "\320\232\320\262\320\260\320\264\321\200\320\260\321\202\320\275\321\213\320\265", nullptr));
        comboBoxPointType->setItemText(2, QCoreApplication::translate("MainWindow", "\320\235\320\265\321\202", nullptr));

        pointLabel_2->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        comboBoxPointColor->setItemText(0, QCoreApplication::translate("MainWindow", "\320\261\320\265\320\273\321\213\320\271", nullptr));
        comboBoxPointColor->setItemText(1, QCoreApplication::translate("MainWindow", "\321\207\320\265\321\200\320\275\321\213\320\271", nullptr));
        comboBoxPointColor->setItemText(2, QCoreApplication::translate("MainWindow", "\321\204\320\270\320\276\320\273\320\265\321\202\320\276\320\262\321\213\320\271", nullptr));
        comboBoxPointColor->setItemText(3, QCoreApplication::translate("MainWindow", "\320\272\321\200\320\260\321\201\320\275\321\213\320\271", nullptr));
        comboBoxPointColor->setItemText(4, QCoreApplication::translate("MainWindow", "\320\266\320\265\320\273\321\202\321\213\320\271", nullptr));
        comboBoxPointColor->setItemText(5, QCoreApplication::translate("MainWindow", "\321\201\320\270\320\275\320\270\320\271", nullptr));
        comboBoxPointColor->setItemText(6, QCoreApplication::translate("MainWindow", "\320\267\320\265\320\273\320\265\320\275\320\275\321\213\320\271", nullptr));
        comboBoxPointColor->setItemText(7, QCoreApplication::translate("MainWindow", "\320\276\321\200\320\260\320\275\320\266\320\265\320\262\321\213\320\271", nullptr));
        comboBoxPointColor->setItemText(8, QCoreApplication::translate("MainWindow", "\321\200\320\260\320\275\320\264\320\276\320\274\320\275\321\213\320\271", nullptr));

        pointLabel_3->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        lineEditPointSize->setInputMask(QCoreApplication::translate("MainWindow", "d0", nullptr));
        lineEditPointSize->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        backgroundLabel->setText(QCoreApplication::translate("MainWindow", "BACKGROUND", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        comboBoxBackColor->setItemText(0, QCoreApplication::translate("MainWindow", "\321\207\320\265\321\200\320\275\321\213\320\271", nullptr));
        comboBoxBackColor->setItemText(1, QCoreApplication::translate("MainWindow", "\321\204\320\270\320\276\320\273\320\265\321\202\320\276\320\262\321\213\320\271", nullptr));
        comboBoxBackColor->setItemText(2, QCoreApplication::translate("MainWindow", "\320\272\321\200\320\260\321\201\320\275\321\213\320\271", nullptr));
        comboBoxBackColor->setItemText(3, QCoreApplication::translate("MainWindow", "\320\266\320\265\320\273\321\202\321\213\320\271", nullptr));
        comboBoxBackColor->setItemText(4, QCoreApplication::translate("MainWindow", "\321\201\320\270\320\275\320\270\320\271", nullptr));
        comboBoxBackColor->setItemText(5, QCoreApplication::translate("MainWindow", "\320\267\320\265\320\273\320\265\320\275\321\213\320\271", nullptr));
        comboBoxBackColor->setItemText(6, QCoreApplication::translate("MainWindow", "\320\276\321\200\320\260\320\275\320\266\320\265\320\262\321\213\320\271", nullptr));
        comboBoxBackColor->setItemText(7, QCoreApplication::translate("MainWindow", "\320\261\320\265\320\273\321\213\320\271", nullptr));
        comboBoxBackColor->setItemText(8, QCoreApplication::translate("MainWindow", "\321\200\320\260\320\275\320\264\320\276\320\274\320\275\321\213\320\271", nullptr));

        applyButton->setText(QCoreApplication::translate("MainWindow", " Apply", nullptr));
#if QT_CONFIG(shortcut)
        applyButton->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        glWidgetMenu->setItemText(glWidgetMenu->indexOf(Properties), QCoreApplication::translate("MainWindow", "Properties", nullptr));
        jpegButton->setText(QCoreApplication::translate("MainWindow", "JPEG", nullptr));
        bmpButton->setText(QCoreApplication::translate("MainWindow", "BMP", nullptr));
        gifButton->setText(QCoreApplication::translate("MainWindow", "GIF", nullptr));
        glWidgetMenu->setItemText(glWidgetMenu->indexOf(Snapshot), QCoreApplication::translate("MainWindow", " Snapshot", nullptr));
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
