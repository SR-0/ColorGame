#ifndef OBJECT_H
#define OBJECT_H

#include "Core/Component.h"

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include<SFML/Graphics/Text.hpp>

template<typename T> struct Allowed;

template<> struct Allowed<sf::SoundBuffer>		{};
template<> struct Allowed<sf::Sound>			{};
template<> struct Allowed<sf::Music>			{};
template<> struct Allowed<sf::Font>				{};
template<> struct Allowed<sf::Texture>			{};
template<> struct Allowed<sf::Shape>			{};
template<> struct Allowed<sf::RectangleShape>	{};
template<> struct Allowed<sf::CircleShape>		{};
template<> struct Allowed<sf::ConvexShape>		{};
template<> struct Allowed<sf::Sprite>			{};
template<> struct Allowed<sf::Text>				{};

template<typename T> class Object : public T, public Identifier
{
public:

	Object(const std::string& id = "unidentified") : Identifier(id) {};
	virtual ~Object() override {}

};

#endif