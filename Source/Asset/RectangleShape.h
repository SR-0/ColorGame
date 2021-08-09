#ifndef RECTANGLE_SHAPE_H
#define RECTANGLE_SHAPE_H

#include "Asset/Shape.h"

class RectangleShape : public Shape
{
public:

	RectangleShape(const std::string& id, const sf::Vector2f& size = sf::Vector2f(100.f, 100.f))
		:
		Shape(id, SHAPE_TYPE::RECTANLGE),
		size(size)
	{
		setSize(size);
		Shape::update();
	}

	RectangleShape(const sf::Vector2f& size = sf::Vector2f(100.f, 100.f))
		: 
		Shape("unidentified", SHAPE_TYPE::RECTANLGE),
		size(size)
	{ 
		setSize(size);
		Shape::update();
	}

	virtual ~RectangleShape() override {}

public:

	void setSize(const sf::Vector2f& size)
	{
		this->size = size;
		Shape::update();
	}

	void setSize(float x, float y)
	{
		setSize(sf::Vector2f(x, y));
		Shape::update();
	}

	void setPosition(float x, float y)
	{
		Shape::setPosition(sf::Vector2f(x, y));
	}

	const sf::Vector2f& getSize() const
	{
		return size;
	}

	virtual std::size_t getPointCount() const override final
	{
		return 4;
	}

	virtual sf::Vector2f getPoint(std::size_t index) const override final
	{
		switch (index)
		{
			case 0: return sf::Vector2f(0, 0);
			case 1: return sf::Vector2f(size.x, 0);
			case 2: return sf::Vector2f(size.x, size.y);
			case 3: return sf::Vector2f(0, size.y);
		}
	}

public:

	sf::Vector2f size;

};

#endif