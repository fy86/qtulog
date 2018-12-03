#include "udplog.h"

udplog::udplog(QObject *parent) : QObject(parent)
{

}

void udplog::init()
{
    m_pUdp = new QUdpSocket(this);
    m_pUdp->bind(QHostAddress::LocalHost,9109);
    connect(m_pUdp,SIGNAL(readyRead()),this,SLOT(slotPrintUDP()));
}
void udplog::slotPrintUDP()
{
    while (m_pUdp->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(m_pUdp->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        m_pUdp->readDatagram(datagram.data(), datagram.size(),
                                &sender, &senderPort);
        datagram.append((char)0x00);

        qDebug("%s",datagram.data());
    }
}
