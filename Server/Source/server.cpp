#include "../Header/server.h"
#include <QDataStream>
#include <QDebug>
#include <QString>

namespace
{
    static QString ok = "<ok> ";
    static QString err = "<error> ";
}

Server::Server()
{
    if (this->listen(QHostAddress::Any, 2323))
        qDebug() << ok << "start of server";
    else
        qDebug() << err << "error with starting server";
}

void Server::slotReadyRead()
{
    auto socket = qobject_cast<QTcpSocket*>(sender());

    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_12);

    quint16 nextBlockSize = 0;

    if (in.status() == QDataStream::Ok)
    {
        qDebug() << ok << "start reading info from client " << socket->socketDescriptor();

        while (true)
        {
            // if nextBlockSize == 0, it means error from client while sending information, as 2 bytes should be at least (size of block)
            if (nextBlockSize == 0)
            {
                if (socket->bytesAvailable() < 2)
                    break;

                in >> nextBlockSize;
            }

            if (socket->bytesAvailable() < nextBlockSize)
                break;

            // get data from dataStream and send to client
            QString str;
            in >> str;
            nextBlockSize = 0;
            SendToClient(str);
            break;
        }
    }
    else
    {
        qDebug() << err << "Datastream error";
    }
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    auto socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    m_sockets.push_back(socket);
    qDebug() << "client connected " << socketDescriptor;
}

void Server::SendToClient(const QString &str)
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_12);

    out << quint16(0) << str;
    out.device()->seek(0);
    out << quint16(data.size() - sizeof(quint16));

    out << str;

    for (const auto & socket : m_sockets)
        socket->write(data);
}


