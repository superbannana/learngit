#pragma once
#include <functional>
#include <sys/epoll.h>
#include <iostream>
class Channel
{
public:
	Channel(int epollfd,int sockfd);
	~Channel();
	typedef std::function<void()> EventCallback;
	typedef std::function<void()> ReadEventCallback;  //�ɶ��¼�
	void setReadCallback(ReadEventCallback cb);
	void handleEvent();
	void setRevents(int revent);
	int getSockfd();
	void enableReading();
private:
	void update();
	int _epollfd;
	int _sockfd;
	int _events;    //Ҫ��ע���¼�
	int _revents;   //�������¼�
	ReadEventCallback readCallback_;
	EventCallback writeCallback_;
};

