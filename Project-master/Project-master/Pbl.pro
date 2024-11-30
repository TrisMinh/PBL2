QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Account.cpp \
    AddService.cpp \
    Addroom.cpp \
    Addroomtype.cpp \
    Contract.cpp \
    Createpayment.cpp \
    Date.cpp \
    Editroom.cpp \
    Editroomtype.cpp \
    Editservice.cpp \
    Edittenant.cpp \
    LinkedList.cpp \
    Login.cpp \
    Payment.cpp \
    PaymentStatistics.cpp \
    Reservation.cpp \
    Room.cpp \
    RoomType.cpp \
    Service.cpp \
    ServiceUsage.cpp \
    Tenant.cpp \
    Test.cpp \
    admin.cpp \
    main.cpp

HEADERS += \
    Account.h \
    AddService.h \
    Addroom.h \
    Addroomtype.h \
    Contract.h \
    Createpayment.h \
    Date.h \
    Editroom.h \
    Editroomtype.h \
    Editservice.h \
    Edittenant.h \
    LinkedList.h \
    Login.h \
    Payment.h \
    PaymentStatistics.h \
    Reservation.h \
    Room.h \
    RoomType.h \
    Service.h \
    ServiceUsage.h \
    Tenant.h \
    Test.h \
    admin.h

FORMS += \
    AddService.ui \
    Addroom.ui \
    Addroomtype.ui \
    Createpayment.ui \
    Editroom.ui \
    Editroomtype.ui \
    Editservice.ui \
    Edittenant.ui \
    Login.ui \
    admin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Icon.qrc
