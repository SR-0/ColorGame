#ifndef CONNECTION_MANAGER_H
#define CONNECTION_MANAGER_H

#include "Core/Component.h"

class ConnectionManager : public Singleton::NonInstantiable
{
public:

	static bool initialize(class RenderWindow& renderWindow);
	static void update();
	static void terminate();

public:

	static void					createConnection(const CONNECTION_TYPE& connectionType);
	static size_t				getConnectionCount();
	static class Connection*	getConnection(size_t connectionIndex);
	static void					destroyConnection(size_t connectionIndex);

public:

	static void attachRenderWindow(class RenderWindow& renderWindow);
	static void detachRenderWindow();

protected:

	static class RenderWindow*				renderWindow;
	static std::vector<class Connection*>	connections;

};

using cm = ConnectionManager;

#endif