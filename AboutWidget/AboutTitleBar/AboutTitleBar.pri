SOURCES += \
        $$PWD/abouttitlebarui.cpp

HEADERS += \
        $$PWD/abouttitlebarui.h

win32 {
QT += winextras
LIBS += -luser32 -ldwmapi
}

INCLUDEPATH += $$PWD

