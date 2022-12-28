#include "objects/Environment.h"

environment Environment::createEnv(const tup& gravity, const tup& wind)
{
	environment env; 
	env.gravity = gravity;
	env.wind = wind;
	return env;
}