#ifndef CONVEX_SHAPE_H
#define CONVEX_SHAPE_H

#include "Asset/Shape.h"

class ConvexShape : public Shape
{
public:

	ConvexShape(const std::string& id, std::size_t pointCount = 4) 
		: 
		Shape(id, SHAPE_TYPE::CONVEX)
	{
		setPointCount(pointCount);
		Shape::update();
	}

	ConvexShape(std::size_t pointCount = 4) : Shape("unidentified", SHAPE_TYPE::CONVEX)
	{
		setPointCount(pointCount);
		Shape::update();
	}

	virtual ~ConvexShape() override {}

public:

	void setPointCount(std::size_t pointCount)
	{
		points.resize(pointCount);
		update();
	}

	virtual std::size_t getPointCount() const override final
	{
		return points.size();
	}

	void setPoint(std::size_t index, const sf::Vector2f& point)
	{
		points[index] = point;
		update();
	}

	sf::Vector2f getPoint(std::size_t index) const
	{
		return points[index];
	}

protected:

	std::vector<sf::Vector2f> points;

};

#endif