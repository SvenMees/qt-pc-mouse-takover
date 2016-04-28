
#include <QtWidgets>
#include <QtNetwork>
#include <QLabel>
#include "sender.h"
#include <QString>

Sender::Sender(QWidget *parent)
    : QWidget(parent)
{
    statusLabel = new QLabel(tr("Ready to broadcast datagrams on port 40000"));
    statusLabel->setWordWrap(true);
    QString schermwaarde;
    startButton = new QPushButton(tr("&Start"));
    quitButton = new QPushButton(tr("&Quit"));

    buttonBox = new QDialogButtonBox;
    buttonBox->addButton(startButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    timer = new QTimer(this);
    udpSocket = new QUdpSocket(this);
    messageNo = 1;

    connect(startButton, SIGNAL(clicked()), this, SLOT(startBroadcasting()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(timer, SIGNAL(timeout()), this, SLOT(broadcastDatagram()));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(statusLabel);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle(tr("Broadcast Sender"));
}

void Sender::startBroadcasting()
{
    startButton->setEnabled(false);

    timer->start(1000);

}

void Sender::broadcastDatagram()
{   QDesktopWidget screens;
       // QD << QNetworkInterface::allAddresses(); //geeft alle adressen weer
        host.setHostName(QHostInfo::localHostName());
        QD << host.addresses();
        if (host.error() != QHostInfo::NoError) {
            QD << "Lookup failed:" << host.errorString();
            return;
        }

        foreach (const QHostAddress &address, host.addresses())
            QD << "Found address:" << address.toString();


//    if (udpSocket->bind(QHostAddress(het ipadres),poort)==1){

//        QD<<"het werkt"endl;
//    }
//    else{
//    QD<< "het werkt ni";
//    }

        schermwaarde = (tr("scherm %4x%5").arg(screens.availableGeometry().height(),4).arg(screens.availableGeometry().width(),4));
        QD<<schermwaarde<<endl; //print af
    statusLabel->setText(tr("verstuurde berichten = %1").arg(messageNo));

    QByteArray datagram (schermwaarde.toStdString().c_str()); //Convert QString to Byte Array Here
    udpSocket->writeDatagram(datagram.data(), datagram.size(),QHostAddress::Broadcast, 40000);++messageNo;

if (messageNo>=5){
    timer->stop();
    startButton->setEnabled(true);
    messageNo=0;
}
}


