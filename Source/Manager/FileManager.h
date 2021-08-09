#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "Core/Component.h"

class FileManager : public Singleton::NonInstantiable
{
public:

	static bool initialize();
	static void update();
	static void terminate();

public:

	static void save(const std::string& filename, class RenderWindow* renderWindow);
	static void load(const std::string& filename, class RenderWindow* renderWindow);

public:

	static void save(const std::string& filename, class State* state);
	static void load(const std::string& filename, class State* state);

};

using fm = FileManager;

#endif