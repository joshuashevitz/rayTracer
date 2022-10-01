#pragma once 

#include <iostream>
#include "simpleMath.h"
#include "tuples.h"
#include "../Environment/Environment.h"

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