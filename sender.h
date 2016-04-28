#ifndef SENDER_H
#define SENDER_H

#include <QWidget>
#include <QDesktopWidget>
#include <QHostInfo>

#define QD qDebug() << __FILE__ << __LINE__

class QDialogButtonBox;
class QLabel;
class QPushButton;
class QTimer;
class QUdpSocket;

class Sender : public QWidget
{
    Q_OBJECT

public:
    Sender(QWidget *parent = 0);
    QString schermwaarde;
private slots:
    void startBroadcasting();
    void broadcastDatagram();


private:
    QLabel *statusLabel;
    QPushButton *startButton;
    QPushButton *quitButton;
    QDialogButtonBox *buttonBox;
    QUdpSocket *udpSocket;
    QTimer *timer;
    int messageNo;
    QHostInfo host;
};

#endif
