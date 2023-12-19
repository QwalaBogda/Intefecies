QT = core
QT += widgets testlib
QT -= gui
CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ../src/form.cpp \
        ../src/mycode.cpp \
        test_form.cpp

HEADERS += \
    ../src/form.h \
    ../src/mycode.h \
    test_form.h

FORMS += \
    ../src/form.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
