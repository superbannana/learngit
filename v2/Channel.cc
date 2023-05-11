#include "Channel.h"
Channel::Channel(int epollfd, int sockfd): _epollfd(epollfd)
, _sockfd(sockfd)
, _events(0)
, _revents(0)
{
}
Channel::~Channel()
{
}
void Channel::handleEvent()
{
	if (_revents & EPOLLIN)
		readCallback_();
}
void Channel::setReadCallback(ReadEventCallback cb) {

	readCallback_ = cb;
}
void Channel::setRevents(int revent) {
	_revents = revent;
}
void Channel::enableReading() {
	_events |= EPOLLIN;
	update();
}
void Channel::update() {
	struct epoll_event ev;
	ev.data.ptr = this;
	ev.events = _events;
	epoll_ctl(_epollfd, EPOLL_CTL_ADD, _sockfd, &ev);
}
