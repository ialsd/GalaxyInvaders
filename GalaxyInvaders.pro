QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    alien.cpp \
    ball.cpp \
    bonus.cpp \
    button.cpp \
    game.cpp \
    gif.cpp \
    health.cpp \
    main.cpp \
    player.cpp \
    score.cpp \
    stone.cpp

HEADERS += \
    alien.h \
    ball.h \
    bonus.h \
    button.h \
    game.h \
    gif.h \
    health.h \
    player.h \
    score.h \
    stone.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
