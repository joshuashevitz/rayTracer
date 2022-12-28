#include "objects/Projectiles.h"

projectile Projectiles::CreateProj(const tup& pos, const tup& vel)
{
	projectile pr;
	pr.pos = pos;
	pr.velocity = vel;
	return pr;
}

projectile Projectiles::tick(environment env, projectile proj) 
{
	projectile p;
	p.pos = math.addTuples(proj.pos, proj.velocity);
	p.velocity = math.addTuples(proj.velocity, math.addTuples(env.wind, env.gravity));

	return p;
}
