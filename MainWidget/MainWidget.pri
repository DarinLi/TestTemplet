SOURCES += \
    $$PWD/mainwidget.cpp

HEADERS += \
    $$PWD/mainwidget.h

win32 {
QT += winextras
LIBS += -luser32 -ldwmapi
}

INCLUDEPATH += $$PWD

include(MainCentralWidget/MainCentralWidget.pri)
include(MainTitleBar/MainTitleBar.pri)
