#include "Core/Engine.h"

int main(int argc, char** argv)
{
	if (engine::initialize(argc, argv))
	{
		while (engine::isRunning())
		{
			engine::update();
			engine::render();
		}

		engine::terminate();
	}
}