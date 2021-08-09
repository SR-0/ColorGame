#ifndef TCP_CONNECTION_H
#define TCP_CONNECTION_H

#include "Core/Component.h"

class Connection
{
public:

	Connection(const CONNECTION_TYPE& connectionType);
	Connection(const Connection&) = delete;

public:

	void test();
	CONNECTION_TYPE getConnectionType() const;

private:

	sf::IpAddress		ip				= sf::IpAddress::getLocalAddress();
	sf::TcpSocket		socket;
	size_t				port			= 2000;
	CONNECTION_TYPE		connectionType	= CONNECTION_TYPE::UNIDENTIFIED;
	std::string			text			= std::string("Connected to: ");
	size_t				bytesReceived	= 0;

};

#endif