#include "Ray.h"


void Rays::_init_ray(const tup& origin, const tup& direction)
{
	R.origin = origin;
	R.direction = direction;
}

void Rays::_clear()
{
	R.origin = math.scalarMultiplcation(R.origin, 0);
	R.origin.w = 1;
	R.direction = math.scalarMultiplcation(R.direction, 0);
}

tup Rays::_position(const ray& r, const float& t)
{
	_clear();
	R.direction = math.scalarMultiplcation(r.direction, t);
	R.origin = r.origin;
	return math.addTuples(R.origin, R.direction);
}