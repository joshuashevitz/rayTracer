#pragma once

#include <iostream>

#include <math/tuples.h>
#include <math/simpleMath.h>

struct environment
{
	tup gravity;
	tup wind;
};

class Environment
{
public: 
	Environment() {};
	~Environment() = default;
	environment createEnv(const tup& gravity, const tup& wind);
};