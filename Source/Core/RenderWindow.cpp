#include "Core/RenderWindow.h"
#include "Core/State.h"

RenderWindow::RenderWindow(
	const sf::VideoMode&		videoMode,
	const sf::String&			title,
	const sf::Uint32&			style,
	const sf::ContextSettings&	settings,
	const sf::Uint8&			framerateLimit,
	const sf::Color&			clearColor)
	:
	sf::RenderWindow(videoMode, title, style, settings),
	videoMode(videoMode),
	title(title),
	style(style),
	settings(settings),
	framerateLimit(framerateLimit),
	clearColor(clearColor),
	renderLayerMax(1)
{
	sf::RenderWindow::setFramerateLimit(framerateLimit);
}

void RenderWindow::draw(State* state)
{
	for (size_t renderLayer = 1; renderLayer <= renderLayerMax; renderLayer++)
	{
		for (size_t shapeIndex = 0; shapeIndex < state->getShapeCount(); shapeIndex++)
		{
			if (state->getShape(shapeIndex)->isRenderEnabled() && state->getShape(shapeIndex)->getRenderLayer() == renderLayer)
			{
				sf::RenderWindow::draw(*state->getShape(shapeIndex));
			}
		}

		for (size_t spriteIndex = 0; spriteIndex < state->getSpriteCount(); spriteIndex++)
		{
			if (state->getSprite(spriteIndex)->isRenderEnabled() && state->getSprite(spriteIndex)->getRenderLayer() == renderLayer)
			{
				sf::RenderWindow::draw(*state->getSprite(spriteIndex));
			}
		}

		for (size_t textIndex = 0; textIndex < state->getTextCount(); textIndex++)
		{
			if (state->getText(textIndex)->isRenderEnabled() && state->getText(textIndex)->getRenderLayer() == renderLayer)
			{
				sf::RenderWindow::draw(*state->getText(textIndex));
			}
		}
	}
}

bool RenderWindow::isFullscreen() const
{
	return style == (sf::Uint32(0) | sf::Style::Fullscreen) ? true : false;
}

bool RenderWindow::isResizable() const
{
	return style == (sf::Uint32(0) | sf::Style::Resize) ? true : false;;
}

bool RenderWindow::isBorderless() const
{
	return style == (sf::Uint32(0) | sf::Style::None) ? true : false;;
}

bool RenderWindow::isDefault() const
{
	return style == (sf::Uint32(0) | sf::Style::Default) ? true : false;;
}

sf::Uint32 RenderWindow::getStyle() const
{
	return style;
}

sf::Color RenderWindow::getClearColor() const
{
	return clearColor;
}

void RenderWindow::setClearColor(const sf::Color& clearColor)
{
	this->clearColor = clearColor;
}

sf::Uint8 RenderWindow::getFramerateLimit() const
{
	return framerateLimit;
}

void RenderWindow::setFramerateLimit(const sf::Uint8& framerateLimit)
{
	this->framerateLimit = framerateLimit;
	sf::RenderWindow::setFramerateLimit(framerateLimit);
}

sf::Uint8 RenderWindow::getRenderLayerMax() const
{
	return renderLayerMax;
}

void RenderWindow::setRenderLayerMax(const sf::Uint8& renderLayerMax)
{
	this->renderLayerMax = renderLayerMax;
}
