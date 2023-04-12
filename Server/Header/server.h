#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <vector>

class Server : public QTcpServer
{
    // Q_OBJECT in QTcpServer
public:
    Server();

public slots:
    void slotReadyRead();

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private:
    void SendToClient(const QString & str);

private:
    std::vector<QTcpSocket*> m_sockets;
};

#endif // SERVER_H
