#ifndef RANDOM_NUMBER_GENERATOR_H
#define	RANDOM_NUMBER_GENERATOR_H

#include "Core/Component.h"

class RandomNumberGenerator : public Singleton::NonInstantiable
{
public:

	static void seed(time_t* seed = nullptr)
	{
		srand(time(seed));
	}

	static float range(float min, float max)
	{
		return min + ((float)rand() / RAND_MAX) * (max - min);
	}

	static double range(double min, double max)
	{
		return min + ((double)rand() / RAND_MAX) * (max - min);
	}

	static unsigned int range(unsigned int min, unsigned int max)
	{
		return rand() % (unsigned int)(max + 1 - min) + min;
	}

	static int range(int min, int max)
	{
		return rand() % (int)(max + 1 - min) + min;
	}

};

typedef RandomNumberGenerator rng;

#endif