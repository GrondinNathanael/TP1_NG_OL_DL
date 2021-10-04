#include "RevolvairWebServer.h"

WebServer * server;

RevolvairWebServer::RevolvairWebServer(int port)
{
    server = new WebServer(port);
}

void RevolvairWebServer::handleClient()
{
    server->handleClient();
}