SOURCES += $$PWD/framelesshelper.cpp

HEADERS += $$PWD/framelesshelper.h

win32 {
QT += winextras
LIBS += -luser32 -ldwmapi
}

INCLUDEPATH += $$PWD
