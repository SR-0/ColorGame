#ifndef TEXT_H
#define TEXT_H

#include "Core/Object.h"

class Text : public Object<sf::Text>, public AutoRenderable, public Activator
{
public:

	Text(const std::string& id = "unidentified") 
		: 
		Object<sf::Text>(id),
		AutoRenderable(1, true),
		Activator(false)
	{ 
		/*text's string will be the same as it's ID as default*/
		setString(id); 
	}

	virtual ~Text() override {}

public:

	sf::Uint8 getOpacity() const
	{
		return getFillColor().a;
	}

	void setOpacity(float opacity)
	{
		if (opacity < 0)
		{
			setFillColor(sf::Color(
				getFillColor().r,
				getFillColor().g,
				getFillColor().b,
				0));
		}
		else if (opacity > 255)
		{
			setFillColor(sf::Color(
				getFillColor().r,
				getFillColor().g,
				getFillColor().b,
				255));
		}
		else
		{
			setFillColor(sf::Color(
				getFillColor().r,
				getFillColor().g,
				getFillColor().b,
				opacity));
		}
	}

	bool isTransparent() const
	{
		return getFillColor().a == sf::Uint8(0);
	}

	bool isOpaque() const
	{
		return getFillColor().a == sf::Uint8(255);
	}

public:

	void fadeIn(float alphaIncrement, const sf::Uint8& max = 255)
	{
		if (getOpacity() + alphaIncrement < max)
		{
			setOpacity(getOpacity() + alphaIncrement);
		}
		else
		{
			setOpacity(max);
		}
	}

	void fadeOut(float alphaDecrement, const sf::Uint8& min = 0)
	{
		if (getOpacity() - alphaDecrement > min)
		{
			setOpacity(getOpacity() - alphaDecrement);
		}
		else
		{
			setOpacity(min);
		}
	}

public:

	void setPosition(float x, float y)
	{
		sf::Text::setPosition(sf::Vector2f(x, y));
	}
};

#endif