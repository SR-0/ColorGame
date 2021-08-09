#ifndef SOUND_H
#define SOUND_H

#include "Core/Object.h"

class Sound : public Object<sf::Sound>, public Activator
{
public:

	Sound(const std::string& id = "unidentified") : Object<sf::Sound>(id), Activator(false) {}
	virtual ~Sound() override {}

};

#endif