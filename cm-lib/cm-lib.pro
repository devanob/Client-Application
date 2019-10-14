#-------------------------------------------------
#
# Project created by QtCreator 2019-06-07T16:58:22
#
#-------------------------------------------------

QT       -= gui

TARGET = cm-lib
TEMPLATE = lib
CONFIG += c++11
DEFINES += CMLIB_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += source

SOURCES += \
        source/Data/data-decorator.cpp \
        source/Data/date-time-decorator.cpp \
        source/Data/entity-collection-base.cpp \
        source/Data/entity.cpp \
        source/Data/entitycollectionobject.cpp \
        source/Data/enumerator-decorator.cpp \
        source/Data/int-decorator.cpp \
        source/Data/string-decorator.cpp \
        source/LibClasses/libcommand.cpp \
        source/controllers/commandcontroller.cpp \
        source/controllers/mastercontroller.cpp \
        source/controllers/navigationcontroller.cpp \
        source/models/client.cpp

HEADERS += \
        cm-lib_global.h  \
        source/Data/data-decorator.h \
        source/Data/date-time-decorator.h \
        source/Data/entity-collection-base.h \
        source/Data/entity.h \
        source/Data/entitycollectionobject.h \
        source/Data/enumerator-decorator.h \
        source/Data/int-decorator.h \
        source/Data/string-decorator.h \
        source/LibClasses/libcommand.h \
        source/controllers/commandcontroller.h \
        source/controllers/mastercontroller.h \
        source/controllers/navigationcontroller.h \
        source/models/client.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
