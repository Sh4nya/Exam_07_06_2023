#ifndef MYTCPSERVER_EX_H
#define MYTCPSERVER_EX_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QMap>
#include "singldb.h"
class MyTcpServer_ex : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer_ex(QObject *parent = nullptr);
    ~MyTcpServer_ex();
public slots:
    void slotNewConnection();
    void slotClientDisconnected();
    void sendToClient(QString);
    void slotServerRead();
    //void slotReadClient();
private:
    void parce(QString);
    QTcpServer * mTcpServer;
    QVector<QTcpSocket *> user;
    QMap<QString, int> rooms;
    int server_status;
};
#endif // MYTCPSERVER_EX_H
