#ifndef TCPCONNECT_H
#define TCPCONNECT_H

#include <QObject>
#include <QWidget>

class tcpconnect : public QObject
{
    Q_OBJECT
public:
    explicit tcpconnect(QObject *parent = 0);
    ~tcpconnect();

signals:

public slots:
};

#endif // TCPCONNECT_H
