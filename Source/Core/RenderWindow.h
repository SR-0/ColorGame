#ifndef RENDER_WINDOW_H
#define RENDER_WINDOW_H

#include "Core/Component.h"
#include <SFML/Graphics/RenderWindow.hpp>

class RenderWindow : public sf::RenderWindow
{
public:

	RenderWindow(
		const sf::VideoMode&		videoMode,
		const sf::String&			title,
		const sf::Uint32&			style,
		const sf::ContextSettings&	settings,
		const sf::Uint8&			framerateLimit,
		const sf::Color&			clearColor);

public:

	void draw(class State* state);

public:

	bool		isFullscreen() const;
	bool		isResizable() const;
	bool		isBorderless() const;
	bool		isDefault() const;
	sf::Uint32	getStyle() const;
	sf::Color	getClearColor() const;
	void		setClearColor(const sf::Color& clearColor);
	sf::Uint8	getFramerateLimit() const;
	void		setFramerateLimit(const sf::Uint8& framerateLimit);
	sf::Uint8	getRenderLayerMax() const;
	void		setRenderLayerMax(const sf::Uint8& renderLayerMax);

protected:

	sf::VideoMode		videoMode		= sf::VideoMode();
	sf::String			title			= sf::String();
	sf::Uint32			style			= sf::Uint32();
	sf::ContextSettings	settings		= sf::ContextSettings();
	sf::Uint8			framerateLimit	= sf::Uint8();
	sf::Color			clearColor		= sf::Color();
	sf::Uint8			renderLayerMax	= sf::Uint8();

};

#endif