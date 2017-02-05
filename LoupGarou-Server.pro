#-------------------------------------------------
#
# Project created by QtCreator 2017-01-08T01:03:48
#
#-------------------------------------------------

QT       += core gui \
            core gui network


CONFIG += console \ c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LoupGarou-Server
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES +=  lib/core/src/main.cpp\
            lib/core/src/Services/Loggers/nulllogger.cpp \
            lib/core/src/locator.cpp \
            lib/core/src/logger.cpp \
            lib/core/src/application.cpp \
            lib/network/src/client.cpp \
            lib/network/src/server.cpp \
            lib/network/src/Services/Loggers/networklogger.cpp \
            lib/UI/src/command.cpp \
            lib/UI/src/commandmanager.cpp \
            lib/UI/src/Commands/helpcommand.cpp \
            lib/UI/src/Commands/stopcommand.cpp \
            lib/UI/src/Commands/listcommand.cpp \
            lib/UI/src/mmi.cpp

HEADERS  += \
    lib/core/include/Services/Loggers/nulllogger.h \
    lib/core/include/locator.h \
    lib/core/include/logger.h \
    lib/core/include/application.h \
    lib/network/include/client.h \
    lib/network/include/server.h \
    lib/network/include/Services/Loggers/networklogger.h \
    lib/UI/include/command.h \
    lib/UI/include/commandmanager.h \
    lib/UI/include/Commands/helpcommand.h \
    lib/UI/include/Commands/stopcommand.h \
    lib/UI/include/Commands/listcommand.h \
    lib/UI/include/mmi.h


FORMS    +=
