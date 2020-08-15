//author voidccc
#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h> //for bzero
#include <iostream>
#include<unistd.h>
#include "Channel.h"
#include<vector>
#define MAX_LINE 100
#define MAX_EVENTS 500
#define MAX_LISTENFD 5

using namespace std;

class TcpServer
{
    public:
        TcpServer();
        ~TcpServer();
		void OnIn(int sockfd);
        void start();
    private:
        int createAndListen();
		int _epollfd;
		int _listenfd;
		struct epoll_event _events[MAX_EVENTS];
		//map<int, Channel*> _channels;
};
