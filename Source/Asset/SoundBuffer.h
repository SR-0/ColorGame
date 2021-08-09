#ifndef SOUND_BUFFER_H
#define SOUND_BUFFER_H

#include "Core/Object.h"

class SoundBuffer : public Object<sf::SoundBuffer>
{
public:

	SoundBuffer(const std::string& id = "unidentified") : Object<sf::SoundBuffer>(id) {}
	virtual ~SoundBuffer() override {}

};

#endif