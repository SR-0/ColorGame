#ifndef SHAPE_H
#define SHAPE_H

#include "Core/Object.h"

enum class SHAPE_TYPE
{
	UNDEFINED	= 0,
	RECTANLGE	= 1,
	CIRCLE		= 2,
	CONVEX		= 3
};

class Shape : public Object<sf::Shape>, public AutoRenderable, public Activator
{
public:

	Shape(const std::string& id = "unidentified", const SHAPE_TYPE& type = SHAPE_TYPE::UNDEFINED) 
		: 
		Object<sf::Shape>(id),
		AutoRenderable(1, true),
		Activator(false),
		type(type)
	{}

	virtual ~Shape() override {}

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

	SHAPE_TYPE getType() const { return type; }

private:

	SHAPE_TYPE type;

};

#endif