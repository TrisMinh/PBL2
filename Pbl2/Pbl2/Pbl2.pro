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
    Adminaccount.cpp \
    Booking.cpp \
    Contract.cpp \
    Createpayment.cpp \
    Date.cpp \
    Editroom.cpp \
    Editroomtype.cpp \
    Editservice.cpp \
    Edittenant.cpp \
    LinkedList.cpp \
    Paybill.cpp \
    Payment.cpp \
    PaymentStatistics.cpp \
    Reservation.cpp \
    Room.cpp \
    RoomType.cpp \
    Service.cpp \
    ServiceUsage.cpp \
    Signin.cpp \
    Tenant.cpp \
    User.cpp \
    admin.cpp \
    main.cpp

HEADERS += \
    Account.h \
    AddService.h \
    Addroom.h \
    Addroomtype.h \
    Adminaccount.h \
    Booking.h \
    Contract.h \
    Createpayment.h \
    Date.h \
    Editroom.h \
    Editroomtype.h \
    Editservice.h \
    Edittenant.h \
    LinkedList.h \
    Paybill.h \
    Payment.h \
    PaymentStatistics.h \
    Reservation.h \
    Room.h \
    RoomType.h \
    Service.h \
    ServiceUsage.h \
    Signin.h \
    Tenant.h \
    User.h \
    admin.h

FORMS += \
    AddService.ui \
    Addroom.ui \
    Addroomtype.ui \
    Adminaccount.ui \
    Booking.ui \
    Createpayment.ui \
    Editroom.ui \
    Editroomtype.ui \
    Editservice.ui \
    Edittenant.ui \
    Paybill.ui \
    Signin.ui \
    User.ui \
    admin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
