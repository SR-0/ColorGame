#ifndef COMPONENT_H
#define COMPONENT_H

#include <cstdlib>
#include <time.h>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <type_traits>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network/TcpListener.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/ContextSettings.hpp>

enum class CONNECTION_TYPE
{
	UNIDENTIFIED	= 0,
	SERVER			= 1,
	CLIENT			= 2
};

class Singleton
{
public:

	class NonInstantiable
	{
	protected:

		NonInstantiable() = default;
		virtual ~NonInstantiable() {}
		NonInstantiable(const NonInstantiable&) = delete;
		NonInstantiable& operator = (const NonInstantiable&) = delete;
		NonInstantiable(NonInstantiable&&) = delete;
		NonInstantiable&& operator = (NonInstantiable&&) = delete;

	};

	template<typename T> class Instantiable
	{
	protected:

		Instantiable<T>() = default;
		virtual ~Instantiable<T>() {}
		Instantiable(const Instantiable&) = delete;
		Instantiable& operator = (const Instantiable&) = delete;
		Instantiable(Instantiable&&) = delete;
		Instantiable&& operator = (Instantiable&&) = delete;

	public:

		static T& getInstance()
		{
			if (instance == nullptr)
			{
				instance = new T;
			}

			return *instance;
		}

		static void destroyInstance()
		{
			if (instance != nullptr)
			{
				delete instance;
				instance = nullptr;
			}
		}

	private:

		static T* instance;

	};
};

template<typename T>
T* Singleton::Instantiable<T>::instance = nullptr;

class Identifier
{
public:

	Identifier(const std::string& id = "unidentified") : id(id) {}
	virtual ~Identifier() {}

public:

	std::string getID() const { return id; }
	void setID(const std::string& id) { this->id = id; }

private:

	std::string id;
};

class Activator
{
public:

	Activator(bool active = false) : active(active) {}
	virtual ~Activator() {}

public:

	bool isActive() const { return active; }
	void setActive(bool active) { this->active = active; }

private:

	bool active;

};

class AutoRenderable
{
public:

	AutoRenderable(size_t renderLayer, bool renderEnabled = true) : renderLayer(renderLayer), renderEnabled(renderEnabled) {}

public:

	size_t	getRenderLayer() const { return renderLayer; }
	void	setRenderLayer(size_t renderLayer) { this->renderLayer = renderLayer; }
	bool	isRenderEnabled() const { return renderEnabled; }
	void	setRenderEnabled(bool renderEnabled) { this->renderEnabled = renderEnabled; }

private:

	size_t	renderLayer;
	bool	renderEnabled;

};

#endif