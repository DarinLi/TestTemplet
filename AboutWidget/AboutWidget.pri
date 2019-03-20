SOURCES += \
    $$PWD/aboutwidget.cpp

HEADERS += \
    $$PWD/aboutwidget.h

win32 {
QT += winextras
LIBS += -luser32 -ldwmapi
}

INCLUDEPATH += $$PWD

include(AboutCentralWidget/AboutCentralWidget.pri)
include(AboutTitleBar/AboutTitleBar.pri)
