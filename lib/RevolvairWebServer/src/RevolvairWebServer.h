#include <WebServer.h>

class RevolvairWebServer
{
private:
    int serverPort;
public:
    RevolvairWebServer(int port);
    ~RevolvairWebServer();
    void handleClient();
};
