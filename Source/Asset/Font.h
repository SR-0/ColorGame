#ifndef FONT_H
#define FONT_H

#include "Core/Object.h"

class Font : public Object<sf::Font>
{
public:

	Font(const std::string& id = "unidentified") : Object<sf::Font>(id) {}
	virtual ~Font() override {}

};

#endif