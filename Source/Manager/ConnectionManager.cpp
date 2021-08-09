#include "Manager/ConnectionManager.h"
#include "Core/RenderWindow.h"
#include "Core/Connection.h"

RenderWindow*				ConnectionManager::renderWindow		= nullptr;
std::vector<Connection*>	ConnectionManager::connections		= std::vector<Connection*>();

bool ConnectionManager::initialize(class RenderWindow& renderWindow)
{
	attachRenderWindow(renderWindow);

	return true;
}

void ConnectionManager::update()
{
	//
}

void ConnectionManager::terminate()
{
	for (auto connection : connections)
	{
		delete connection;
	}

	connections.clear();

	detachRenderWindow();
}

void ConnectionManager::createConnection(const CONNECTION_TYPE& connectionType)
{
	connections.push_back(new Connection(connectionType));
}

size_t ConnectionManager::getConnectionCount()
{
	return connections.size();
}

Connection* ConnectionManager::getConnection(size_t connectionIndex)
{
	if (connectionIndex > 0 && connectionIndex < connections.size())
	{
		return connections[connectionIndex];
	}
	else
	{
		return nullptr; // debug to do
	}
}

void ConnectionManager::destroyConnection(size_t connectionIndex)
{
	if (connectionIndex > 0 && connectionIndex < connections.size())
	{
		delete connections[connectionIndex];
	}
	else
	{
		// debug to do
	}
}

void ConnectionManager::attachRenderWindow(RenderWindow& renderWindow)
{
	ConnectionManager::renderWindow = &renderWindow;
}

void ConnectionManager::detachRenderWindow()
{
	renderWindow = nullptr;
}