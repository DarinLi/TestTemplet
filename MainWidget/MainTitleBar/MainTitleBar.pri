SOURCES += \
        $$PWD/maintitlebarui.cpp

HEADERS += \
        $$PWD/maintitlebarui.h

win32 {
QT += winextras
LIBS += -luser32 -ldwmapi
}

INCLUDEPATH += $$PWD

