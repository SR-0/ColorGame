#ifndef SPRITE_H
#define SPRITE_H

#include "Core/Object.h"
#include "Asset/Texture.h"
#include <SFML/Graphics/Sprite.hpp>

class Sprite : public Object<sf::Sprite>, public AutoRenderable, public Activator
{
public:

	Sprite(const std::string& id, Texture* texture = nullptr)
		:
		Object<sf::Sprite>(id),
		AutoRenderable(1, true),
		Activator(true)
	{
		if (texture)
		{
			sf::Sprite::setTexture(*texture);
		}
	}

	Sprite(Texture* texture)
		:
		Object<sf::Sprite>("unidentified"),
		AutoRenderable(1, true),
		Activator(true)
	{
		if (texture)
		{
			sf::Sprite::setTexture(*texture);
		}
	}

	virtual ~Sprite() { if (this->getTexture()) delete this->getTexture(); }
};

#endif