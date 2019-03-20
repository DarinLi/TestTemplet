SOURCES += \
    $$PWD/maincentralwidgetui.cpp

HEADERS += \
    $$PWD/maincentralwidgetui.h
	
FORMS += \
    $$PWD/maincentralwidgetui.ui

win32 {
QT += winextras
LIBS += -luser32 -ldwmapi
}

INCLUDEPATH += $$PWD

