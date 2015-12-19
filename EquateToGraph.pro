#-------------------------------------------------
#
# Project created by QtCreator 2015-11-25T01:13:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = EquateToGraph
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    main_gui/about_gui.cpp \
    main_gui/help_gui.cpp \
    main_gui/linear_gui.cpp \
    main_gui/quadritic_gui.cpp \
    main_gui/cubic_gui.cpp \
    qcustomplot.cpp \
    saveimage.cpp


HEADERS  += mainwindow.h \
    main_gui/about_gui.h \
    main_gui/help_gui.h \
    main_gui/linear_gui.h \
    main_gui/quadritic_gui.h \
    qcustomplot.h \
    main_gui/cubic_gui.h \
    saveimage.h


FORMS    += mainwindow.ui \
    main_gui/about_gui.ui \
    main_gui/help_gui.ui \
    main_gui/linear_gui.ui \
    main_gui/quadritic_gui.ui \
    main_gui/cubic_gui.ui

RESOURCES += \
    equatetograph.qrc

DISTFILES += \
    images
