#include <WebServer.h>
class RevolvairWebServer
{
    private:
        int serverPort;
        WebServer * server;
    public:
        RevolvairWebServer(int port, const char* id, const char* pwd);
        void handleClient();
};
