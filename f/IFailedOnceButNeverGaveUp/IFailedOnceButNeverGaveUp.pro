QT       += core gui multimedia multimediawidgets sql \
    quick \
    charts
QT       +=  sql  printsupport
QT += network
QT += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = smtp
TEMPLATE = app
QT += texttospeech
CONFIG += c++11
CONFIG += console
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    dialog.cpp \
    main.cpp \
    mainwindow.cpp \
    media.cpp \
    movie.cpp \
    smtp.cpp

HEADERS += \
    arduino.h \
    dialog.h \
    employer.h \
    mainwindow.h \
    media.h \
    movie.h \
    smtp.h

FORMS += \
    dialog.ui \
    mainwindow.ui

TRANSLATIONS += \
    IFailedOnceButNeverGaveUp_en_150.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target