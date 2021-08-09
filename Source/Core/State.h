#ifndef STATE_H
#define STATE_H

#include "Core/Component.h"
#include "Core/RenderWindow.h"

#include "Asset/SoundBuffer.h"
#include "Asset/Sound.h"
#include "Asset/Music.h"
#include "Asset/Font.h"
#include "Asset/Texture.h"
#include "Asset/Shape.h"
#include "Asset/RectangleShape.h"
#include "Asset/CircleShape.h"
#include "Asset/ConvexShape.h"
#include "Asset/Sprite.h"
#include "Asset/Text.h"

#include "Manager/DeltaManager.h"
#include "Manager/EventManager.h"
#include "Manager/InputManager.h"
#include "Manager/ConnectionManager.h"
#include "Manager/FileManager.h"

#include "Utility/RandomNumberGenerator.h"
#include "Utility/ColorConverter.h"

/*
	////////////////////////////////////////////////////////////

	States have 5 stages:

	- CREATE:
		
		this stage is for allocation/initialization
		for non-temporary variables/objects in this
		State

	- SETUP:
	
		this stage is for pre-update modification
		(not required depending on style or initialization
		stage but recommended to seperate from initialization 
		stage for fast resets)

	- UPDATE

		this stage is for the runtime logic of the
		entire State (called every frame) and is a
		required in each class with a manual call
		to 'setStage' to break out of update loop

	- RESOLVE

		this stage is highly optional and might come in handy
		for auto saves and unexpected exits. Feel free to leave
		skip

	- DESRTOY

		this stage is for deallocation/destruction
		for non-temporary variables/objects in this
		State

	///////////////////////////////////////////////////////////

	All State stages will automatically change to the next
	stage *except* for 'UPDATE' stage which will have to
	manually call "setStage' with the parameter of either
	STATE_STAGE::SETUP, STATE_STAGE::RESOLVE or 
	STATE_STAGE::DESTROY at the desired time based on your
	needs for that particular State

	If you don't override 'virtual ~State() {}' destructor,
	'destroyAll()' will automatically get called at end of
	state lifetime, making it possible to skip 'DESTROY'
	stage all together in niche situations, but this is
	not recommended when using the StateManager

	NOTE - Skipping a STATE_STAGE:

		***skipping a stage is completely fine (except for
		UPDATE stage) is done simply by overidding the
		pure virtual function and giving it a empty
		function body - e.g. "virtual resolve() override 
		final {}" in the derived class. DO NOT do this
		with UPDATE stage.***

	////////////////////////////////////////////////////////////

	Managable Assets:

		- SoundBuffer
		- Sound
		- Music
		- Font
		- Texture
		- RectangleShape
		- CircleShape
		- ConvexShape
		- Sprite
		- Text

	MORE COMING SOON

	////////////////////////////////////////////////////////////
*/

enum class STATE_STAGE
{
	CREATE	= 1,
	SETUP	= 2,
	UPDATE	= 3,
	RESOLVE	= 4,
	DESRTOY	= 5,
};

class State : public Identifier, public Activator
{

public:

	State(const std::string& id, RenderWindow* renderWindow = nullptr) 
		: 
		Identifier(id), 
		Activator(false), 
		stage(STATE_STAGE::CREATE),
		renderWindow(renderWindow)
	{}

	virtual ~State() { destroyAll(); } // make sure to call destroyAll() if overidden

public:

	virtual void create()	= 0;
	virtual void setup()	= 0;
	virtual void update()	= 0;
	virtual void resolve()	= 0;
	virtual void destroy()	= 0;

public:

	STATE_STAGE getStage() const;
	void		setStage(const STATE_STAGE& stage);

public:

	void				attachRenderWindow(class RenderWindow& renderWindow);
	void				detachRenderWindow();
	class RenderWindow& getRenderWindow() const;

public:

	SoundBuffer*	createSoundBuffer(const std::string& id = std::string("unidentified"));
	Sound*			createSound(const std::string& id = std::string("unidentified"));
	Music*			createMusic(const std::string& id = std::string("unidentified"));
	Font*			createFont(const std::string& id = std::string("unidentified"));
	Texture*		createTexture(const std::string& id = std::string("unidentified"));
	RectangleShape*	createRectangleShape(const std::string& id = std::string("unidentified"));
	CircleShape*	createCircleShape(const std::string& id = std::string("unidentified"));
	ConvexShape*	createConvexShape(const std::string& id = std::string("unidentified"));
	Sprite*			createSprite(const std::string& id = std::string("unidentified"));
	Text*			createText(const std::string& id = std::string("unidentified"));

public:

	SoundBuffer*	getSoundBuffer(std::size_t index);
	Sound*			getSound(std::size_t index);
	Music*			getMusic(std::size_t index);
	Font*			getFont(std::size_t index);
	Texture*		getTexture(std::size_t index);
	Shape*			getShape(std::size_t index);
	Sprite*			getSprite(std::size_t index);
	Text*			getText(std::size_t index);

public:

	SoundBuffer*	getSoundBuffer(const std::string& id = std::string("unidentified")) const;
	Sound*			getSound(const std::string& id = std::string("unidentified")) const;
	Music*			getMusic(const std::string& id = std::string("unidentified")) const;
	Font*			getFont(const std::string& id = std::string("unidentified")) const;
	Texture*		getTexture(const std::string& id = std::string("unidentified")) const;
	Shape*			getShape(const std::string& id = std::string("unidentified")) const;
	Sprite*			getSprite(const std::string& id = std::string("unidentified")) const;
	Text*			getText(const std::string& id = std::string("unidentified")) const;

public:

	std::size_t getSoundBufferCount() const;
	std::size_t getSoundCount() const;
	std::size_t getMusicCount() const;
	std::size_t getFontCount() const;
	std::size_t getTextureCount() const;
	std::size_t getShapeCount() const;
	std::size_t getSpriteCount() const;
	std::size_t getTextCount() const;

public:

	void destroySoundBuffer(std::size_t index);
	void destroySound(std::size_t index);
	void destroyMusic(std::size_t index);
	void destroyFont(std::size_t index);
	void destroyTexture(std::size_t index);
	void destroyShape(std::size_t index);
	void destroySprite(std::size_t index);
	void destroyText(std::size_t index);

public:

	void destroySoundBuffer(const std::string& id = std::string("unidentified"));
	void destroySound(const std::string& id = std::string("unidentified"));
	void destroyMusic(const std::string& id = std::string("unidentified"));
	void destroyFont(const std::string& id = std::string("unidentified"));
	void destroyTexture(const std::string& id = std::string("unidentified"));
	void destroyShape(const std::string& id = std::string("unidentified"));
	void destroySprite(const std::string& id = std::string("unidentified"));
	void destroyText(const std::string& id = std::string("unidentified"));

public:

	void destroySoundBuffer(SoundBuffer* soundBuffer);
	void destroySound(Sound* sound);
	void destroyMusic(Music* track);
	void destroyFont(Font* font);
	void destroyTexture(Texture* texture);
	void destroyShape(Shape* shape);
	void destroySprite(Sprite* shape);
	void destroyText(Text* text);

public:

	void destroySoundBuffers();
	void destroySounds();
	void destroyMusics();
	void destroyFonts();
	void destroyTextures();
	void destroyShapes();
	void destroySprites();
	void destroyTexts();

public:

	void destroyAll();

private:

	std::vector<SoundBuffer*>	soundBuffers;
	std::vector<Sound*>			sounds;
	std::vector<Music*>			music;
	std::vector<Font*>			fonts;
	std::vector<Texture*>		textures;
	std::vector<Shape*>			shapes;
	std::vector<Sprite*>		sprites;
	std::vector<Text*>			texts;

private:

	STATE_STAGE stage;

private:

	class RenderWindow* renderWindow;

};

#endif