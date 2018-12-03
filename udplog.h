#ifndef UDPLOG_H
#define UDPLOG_H

#include <QObject>
#include <QUdpSocket>
#include <QString>
#include <QByteArray>
#include <QHostAddress>

class udplog : public QObject
{
    Q_OBJECT
public:
    explicit udplog(QObject *parent = 0);

    void init();
    QUdpSocket *m_pUdp;

signals:

public slots:
    void slotPrintUDP();
};

#endif // UDPLOG_H
