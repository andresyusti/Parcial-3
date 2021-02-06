QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bala_uno.cpp \
    canon_uno.cpp \
    circulo.cpp \
    condiciones.cpp \
    fisicas.cpp \
    main.cpp \
    mainwindow.cpp \
    rastro.cpp

HEADERS += \
    bala_uno.h \
    canon_uno.h \
    circulo.h \
    condiciones.h \
    fisicas.h \
    mainwindow.h \
    rastro.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagenes.qrc
