#pragma once 

#include "objects/Environment.h"

#include <math/simpleMath.h>
#include <math/tuples.h>

struct projectile
{
	tup pos;
	tup velocity;
};

class Projectiles
{
public: 
	Projectiles() {};
	~Projectiles() = default;
	projectile CreateProj(const tup& pos, const tup& vel);
	projectile tick(environment env, projectile proj);

private:
	TupleMath math;
};