#ifndef TEXTURE_H
#define TEXTURE_H

#include "Core/Object.h"

class Texture : public Object<sf::Texture>
{
public:

	Texture(const std::string& id = "unidentified") : Object<sf::Texture>(id) {}
	virtual ~Texture() override {}

};

#endif