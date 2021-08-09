#include "Core/State.h"

STATE_STAGE State::getStage() const
{
	return stage;
}

void State::setStage(const STATE_STAGE& stage)
{
	this->stage = stage;
}

RenderWindow& State::getRenderWindow() const
{
	if (renderWindow)
	{
		return *renderWindow;
	}
	else
	{
		// debug todo
	}
}

void State::attachRenderWindow(RenderWindow& renderWindow)
{
	this->renderWindow = &renderWindow;
}

void State::detachRenderWindow()
{
	renderWindow = nullptr;
}

SoundBuffer* State::createSoundBuffer(const std::string& id)
{
	auto soundBuffer = new SoundBuffer(id);
	soundBuffers.push_back(soundBuffer);
	return soundBuffer;
}

Sound* State::createSound(const std::string& id)
{
	auto sound = new Sound(id);
	sounds.push_back(sound);
	return sound;
}

Music* State::createMusic(const std::string& id)
{
	auto track = new Music(id);
	music.push_back(track);
	return track;
}

Font* State::createFont(const std::string& id)
{
	auto font = new Font(id);
	fonts.push_back(font);
	return font;
}

Texture* State::createTexture(const std::string& id)
{
	auto texture = new Texture(id);
	textures.push_back(texture);
	return texture;
}

RectangleShape* State::createRectangleShape(const std::string& id)
{
	auto shape = new RectangleShape(id); shape->setRenderEnabled(true);
	shapes.push_back(shape);
	return shape;
}

CircleShape* State::createCircleShape(const std::string& id)
{
	auto shape = new CircleShape(id);
	shapes.push_back(shape);
	return shape;
}

ConvexShape* State::createConvexShape(const std::string& id)
{
	auto shape = new ConvexShape(id);
	shapes.push_back(shape);
	return shape;
}

Sprite* State::createSprite(const std::string& id)
{
	auto sprite = new Sprite(id);
	sprites.push_back(sprite);
	return sprite;
}

Text* State::createText(const std::string& id)
{
	auto text = new Text(id);
	texts.push_back(text);
	return text;
}

SoundBuffer* State::getSoundBuffer(std::size_t index)
{
	return soundBuffers[index];
}

Sound* State::getSound(std::size_t index)
{
	return sounds[index];
}

Music* State::getMusic(std::size_t index)
{
	return music[index];
}

Font* State::getFont(std::size_t index)
{
	return fonts[index];
}

Texture* State::getTexture(std::size_t index)
{
	return textures[index];
}

Shape* State::getShape(std::size_t index)
{
	return shapes[index];
}

Sprite* State::getSprite(std::size_t index)
{
	return sprites[index];
}

Text* State::getText(std::size_t index)
{
	return texts[index];
}

SoundBuffer* State::getSoundBuffer(const std::string& id) const
{
	for (size_t i = 0; i < soundBuffers.size(); i++)
	{
		if (soundBuffers[i]->getID() == id)
		{
			return soundBuffers[i];
		}
	}

	return nullptr;
}

Sound* State::getSound(const std::string& id) const
{
	for (size_t i = 0; i < sounds.size(); i++)
	{
		if (sounds[i]->getID() == id)
		{
			return sounds[i];
		}
	}

	return nullptr;
}

Music* State::getMusic(const std::string& id) const
{
	for (size_t i = 0; i < music.size(); i++)
	{
		if (music[i]->getID() == id)
		{
			return music[i];
		}
	}

	return nullptr;
}

Font* State::getFont(const std::string& id) const
{
	for (size_t i = 0; i < fonts.size(); i++)
	{
		if (fonts[i]->getID() == id)
		{
			return fonts[i];
		}
	}

	return nullptr;
}

Texture* State::getTexture(const std::string& id) const
{
	for (size_t i = 0; i < textures.size(); i++)
	{
		if (textures[i]->getID() == id)
		{
			return textures[i];
		}
	}

	return nullptr;
}

Shape* State::getShape(const std::string& id) const
{
	for (size_t i = 0; i < shapes.size(); i++)
	{
		if (shapes[i]->getID() == id)
		{
			return shapes[i];
		}
	}

	return nullptr;
}

Sprite* State::getSprite(const std::string& id) const
{
	for (size_t i = 0; i < sprites.size(); i++)
	{
		if (sprites[i]->getID() == id)
		{
			return sprites[i];
		}
	}

	return nullptr;
}

Text* State::getText(const std::string& id) const
{
	for (size_t i = 0; i < texts.size(); i++)
	{
		if (texts[i]->getID() == id)
		{
			return texts[i];
		}
	}

	return nullptr;
}

std::size_t State::getSoundBufferCount() const
{
	return soundBuffers.size();
}

std::size_t State::getSoundCount() const
{
	return sounds.size();
}

std::size_t State::getMusicCount() const
{
	return music.size();
}

std::size_t State::getFontCount() const
{
	return fonts.size();
}

std::size_t State::getTextureCount() const
{
	return textures.size();
}
std::size_t State::getShapeCount() const
{
	return shapes.size();
}

std::size_t State::getSpriteCount() const
{
	return sprites.size();
}

std::size_t State::getTextCount() const
{
	return texts.size();
}

void State::destroySoundBuffer(std::size_t index)
{
	delete soundBuffers[index];
	soundBuffers.erase(soundBuffers.begin() + index);
}

void State::destroySound(std::size_t index)
{
	delete sounds[index];
	sounds.erase(sounds.begin() + index);
}

void State::destroyMusic(std::size_t index)
{
	delete music[index];
	music.erase(music.begin() + index);
}

void State::destroyFont(std::size_t index)
{
	delete fonts[index];
	fonts.erase(fonts.begin() + index);
}

void State::destroyTexture(std::size_t index)
{
	delete textures[index];
	textures.erase(textures.begin() + index);
}

void State::destroyShape(std::size_t index)
{
	delete shapes[index];
	shapes.erase(shapes.begin() + index);
}

void State::destroySprite(std::size_t index)
{
	delete sprites[index];
	sprites.erase(sprites.begin() + index);
}

void State::destroyText(std::size_t index)
{
	delete texts[index];
	texts.erase(texts.begin() + index);
}

void State::destroySoundBuffer(const std::string& id)
{
	for (size_t i = 0; i < soundBuffers.size(); i++)
	{
		if (soundBuffers[i]->getID() == id)
		{
			delete soundBuffers[i];
			soundBuffers.erase(soundBuffers.begin() + i);
		}
	}
}

void State::destroySound(const std::string& id)
{
	for (size_t i = 0; i < sounds.size(); i++)
	{
		if (sounds[i]->getID() == id)
		{
			delete sounds[i];
			sounds.erase(sounds.begin() + i);
		}
	}
}

void State::destroyMusic(const std::string& id)
{
	for (size_t i = 0; i < music.size(); i++)
	{
		if (music[i]->getID() == id)
		{
			delete music[i];
			music.erase(music.begin() + i);
		}
	}
}

void State::destroyFont(const std::string& id)
{
	for (size_t i = 0; i < fonts.size(); i++)
	{
		if (fonts[i]->getID() == id)
		{
			delete fonts[i];
			fonts.erase(fonts.begin() + i);
		}
	}
}

void State::destroyTexture(const std::string& id)
{
	for (size_t i = 0; i < textures.size(); i++)
	{
		if (textures[i]->getID() == id)
		{
			delete textures[i];
			textures.erase(textures.begin() + i);
		}
	}
}

void State::destroyShape(const std::string& id)
{
	for (size_t i = 0; i < shapes.size(); i++)
	{
		if (shapes[i]->getID() == id)
		{
			delete shapes[i];
			shapes.erase(shapes.begin() + i);
		}
	}
}

void State::destroySprite(const std::string& id)
{
	for (size_t i = 0; i < sprites.size(); i++)
	{
		if (sprites[i]->getID() == id)
		{
			delete sprites[i];
			sprites.erase(sprites.begin() + i);
		}
	}
}

void State::destroyText(const std::string& id)
{
	for (size_t i = 0; i < texts.size(); i++)
	{
		if (texts[i]->getID() == id)
		{
			delete texts[i];
			texts.erase(texts.begin() + i);
		}
	}
}

void State::destroySoundBuffer(SoundBuffer* soundBuffer)
{
	for (size_t i = 0; i < soundBuffers.size(); i++)
	{
		if (soundBuffers[i] == soundBuffer)
		{
			delete soundBuffers[i];
			soundBuffers.erase(soundBuffers.begin() + i);
		}
	}
}

void State::destroySound(Sound* sound)
{
	for (size_t i = 0; i < sounds.size(); i++)
	{
		if (sounds[i] == sound)
		{
			delete sounds[i];
			sounds.erase(sounds.begin() + i);
		}
	}
}

void State::destroyMusic(Music* track)
{
	for (size_t i = 0; i < music.size(); i++)
	{
		if (music[i] == track)
		{
			delete music[i];
			music.erase(music.begin() + i);
		}
	}
}

void State::destroyFont(Font* font)
{
	for (size_t i = 0; i < fonts.size(); i++)
	{
		if (fonts[i] == font)
		{
			delete fonts[i];
			fonts.erase(fonts.begin() + i);
		}
	}
}

void State::destroyTexture(Texture* texture)
{
	for (size_t i = 0; i < textures.size(); i++)
	{
		if (textures[i] == texture)
		{
			delete textures[i];
			textures.erase(textures.begin() + i);
		}
	}
}

void State::destroyShape(Shape* shape)
{
	for (size_t i = 0; i < shapes.size(); i++)
	{
		if (shapes[i] == shape)
		{
			delete shapes[i];
			shapes.erase(shapes.begin() + i);
		}
	}
}

void State::destroySprite(Sprite* sprite)
{
	for (size_t i = 0; i < sprites.size(); i++)
	{
		if (sprites[i] == sprite)
		{
			delete sprites[i];
			sprites.erase(sprites.begin() + i);
		}
	}
}

void State::destroyText(Text* text)
{
	for (size_t i = 0; i < texts.size(); i++)
	{
		if (texts[i] == text)
		{
			delete texts[i];
			texts.erase(texts.begin() + i);
		}
	}
}

void State::destroySoundBuffers()
{
	for (auto soundBuffer : soundBuffers)
	{
		delete soundBuffer;
	}

	soundBuffers.clear();
}

void State::destroySounds()
{
	for (auto sound : sounds)
	{
		delete sound;
	}

	sounds.clear();
}

void State::destroyMusics()
{
	for (auto track : music)
	{
		delete track;
	}

	music.clear();
}

void State::destroyFonts()
{
	for (auto font : fonts)
	{
		delete font;
	}

	fonts.clear();
}

void State::destroyTextures()
{
	for (auto texture : textures)
	{
		delete texture;
	}

	textures.clear();
}

void State::destroyShapes()
{
	for (auto shape : shapes)
	{
		delete shape;
	}

	shapes.clear();
}

void State::destroySprites()
{
	for (auto sprite : sprites)
	{
		delete sprite;
	}

	sprites.clear();
}

void State::destroyTexts()
{
	for (auto text : texts)
	{
		delete text;
	}

	texts.clear();
}

void State::destroyAll()
{
	destroySoundBuffers();
	destroySounds();
	destroyMusics();
	destroyFonts();
	destroyTextures();
	destroyShapes();
	destroySprites();
	destroyTexts();
}
