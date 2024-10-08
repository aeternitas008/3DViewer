QT       += core gui
QT       += openglwidgets

!defined(Q_OS_MAC) {
    # LIBS += -lopengl32 -lglu32   # библиотека для Windows
}

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    affine_transformations.c \
    glwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    parcer.c \

HEADERS += \
    affine_transformations.h \
    glwidget.h \
    mainwindow.h \
    parcer.h \

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
