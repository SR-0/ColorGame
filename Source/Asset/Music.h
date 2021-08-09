#ifndef MUSIC_H
#define MUSIC_H

#include "Core/Object.h"

class Music : public Object<sf::Music>
{
public:

	Music(const std::string& id = "unidentified") : Object<sf::Music>(id) {}
	virtual ~Music() override {}

};

#endif