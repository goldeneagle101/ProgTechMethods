QT += core gui

QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 console
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    authform.cpp \
    functionsforclient.cpp \
    info_about_orders.cpp \
    main.cpp \
    mainwindow.cpp \
    prod_order.cpp \
    productsinformation.cpp

HEADERS += \
    Client.h \
    authform.h \
    functionsforclient.h \
    info_about_orders.h \
    mainwindow.h \
    prod_order.h \
    productsinformation.h

FORMS += \
    authform.ui \
    info_about_orders.ui \
    mainwindow.ui \
    prod_order.ui \
    productsinformation.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
