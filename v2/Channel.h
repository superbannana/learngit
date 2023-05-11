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
	typedef std::function<void()> ReadEventCallback;  //可读事件
	void setReadCallback(ReadEventCallback cb);
	void handleEvent();
	void setRevents(int revent);
	int getSockfd();
	void enableReading();
private:
	void update();
	int _epollfd;
	int _sockfd;
	int _events;    //要关注的事件
	int _revents;   //发生的事件
	ReadEventCallback readCallback_;
	EventCallback writeCallback_;
};

