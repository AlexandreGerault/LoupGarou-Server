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

SOURCES += sources/main.cpp\
    sources/client.cpp \
    sources/command.cpp \
    sources/commandmanager.cpp \
    sources/server.cpp \
    sources/Commands/helpcommand.cpp \
    sources/Commands/stopcommand.cpp \
    sources/Commands/listcommand.cpp \
    sources/Services/Loggers/networklogger.cpp \
    sources/Services/Loggers/nulllogger.cpp \
    sources/locator.cpp \
    sources/logger.cpp \
    sources/application.cpp

HEADERS  += \
    includes/client.h \
    includes/command.h \
    includes/commandmanager.h \
    includes/server.h \
    includes/Commands/helpcommand.h \
    includes/Commands/stopcommand.h \
    includes/Commands/listcommand.h \
    includes/Services/Loggers/networklogger.h \
    includes/Services/Loggers/nulllogger.h \
    includes/locator.h \
    includes/logger.h \
    includes/application.h


FORMS    +=
