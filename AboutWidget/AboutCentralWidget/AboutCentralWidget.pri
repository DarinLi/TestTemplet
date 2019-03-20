SOURCES += \
    $$PWD/aboutcentralwidgetui.cpp

HEADERS += \
    $$PWD/aboutcentralwidgetui.h
	
FORMS += \
    $$PWD/aboutcentralwidgetui.ui

win32 {
QT += winextras
LIBS += -luser32 -ldwmapi
}

INCLUDEPATH += $$PWD

