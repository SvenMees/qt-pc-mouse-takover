QT += network widgets

HEADERS       = receiver.h
SOURCES       = broadcast.cpp \
                main.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/network/broadcastreceiver
INSTALLS += target
