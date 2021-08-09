#ifndef CIRCLE_SHAPE_H
#define CIRCLE_SHAPE_H

#include "Asset/Shape.h"

class CircleShape : public Shape
{
public:

	CircleShape(const std::string& id, float radius = 10.f, std::size_t pointCount = 30U)
		:
		Shape(id, SHAPE_TYPE::CIRCLE),
		radius(radius),
		pointCount(pointCount)
	{
		setRadius(radius);
		setPointCount(pointCount);
		Shape::update();
	}

	CircleShape(float radius = 10.f, std::size_t pointCount = 30U)
		: 
		Shape("unidentified", SHAPE_TYPE::CIRCLE),
		radius(radius),
		pointCount(pointCount)
	{
		setRadius(radius);
		setPointCount(pointCount);
		Shape::update();
	}

	virtual ~CircleShape() override {}
	
public:

	void setRadius(float radius)
	{
	    this->radius = radius;
	    update();
	}
	
	float getRadius() const
	{
	    return radius;
	}
	
	void setPointCount(std::size_t pointCount)
	{
	    this->pointCount = pointCount;
	    update();
	}
	
	virtual std::size_t getPointCount() const override final
	{
	    return pointCount;
	}
	
	virtual sf::Vector2f getPoint(std::size_t index) const override final
	{
	    static const float pi = 3.141592654f;
	
	    float angle = index * 2 * pi / pointCount - pi / 2;
	    float x = std::cos(angle) * radius;
	    float y = std::sin(angle) * radius;
	
	    return sf::Vector2f(radius + x, radius + y);
	}

protected:

	float	radius;
	size_t	pointCount;

};

#endif