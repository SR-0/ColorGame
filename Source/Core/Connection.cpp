#include "Core/Connection.h"

Connection::Connection(const CONNECTION_TYPE& connectionType) : connectionType(connectionType)
{
}

void Connection::test()
{
	switch (connectionType)
	{
		case CONNECTION_TYPE::SERVER:
		{
			sf::TcpListener tcpListener;
			tcpListener.listen(port);
			tcpListener.accept(socket);
			text += "Server";
		}
		break;

		case CONNECTION_TYPE::CLIENT:
		{
			socket.connect(ip, port, sf::Time(sf::seconds(10)));
			text += "Client";
		}
		break;
	}

	size_t buffer[2000];

	socket.send(text.c_str(), text.size() + 1);
	socket.receive(buffer, sizeof(buffer), bytesReceived);
	std::cout << buffer << std::endl;
}

CONNECTION_TYPE Connection::getConnectionType() const
{
	return connectionType;
}
