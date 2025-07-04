#include "chatserver.h"
#include <QDebug>

ChatServer::ChatServer(QObject *parent)
    : QTcpServer(parent) {}

ChatServer::~ChatServer() {}
