#-------------------------------------------------
#
# Project created by QtCreator 2017-08-05T20:27:07
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = japaneseTeacher_demo
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    management.cpp \
    functionselectionui.cpp \
    wordlistui.cpp \
    wordstudyui.cpp \
    problemui.cpp \
    words.cpp \
    grammarstudyui.cpp \
    grammarlistui.cpp \
    topwindowsui.cpp \
    problem.cpp \
    make_problems.cpp

HEADERS  += mainwindow.h \
    management.h \
    functionselectionui.h \
    wordlistui.h \
    wordstudyui.h \
    problemui.h \
    words.h \
    grammarstudyui.h \
    grammarlistui.h \
    topwindowsui.h \
    qheadfile.h \
    problem.h \
    make_problems.h

RESOURCES += \
    icon.qrc \
    csv.qrc \
    video.qrc \
    qss.qrc
