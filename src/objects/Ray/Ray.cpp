#include "Ray.h"


ray Rays::_init_ray(const tup& origin, const tup& direction)
{
	_clear();
	R.origin = origin;
	R.direction = direction;
	return R;
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

std::vector<intersection> Rays::intersect(const sphere& s, const ray& r) 
{
	ray r2 = _transform(r, mats._inverse(s.transform));
	tup sphere_to_ray = math.subtTuples(r2.origin, s.origin);
	float a = math.dotProduct(r2.direction, r2.direction);
	float b = 2 * math.dotProduct(r2.direction, sphere_to_ray);
	float c = math.dotProduct(sphere_to_ray, sphere_to_ray) - 1;
	float discriminant = ((b * b) - (4 * a * c));
	
	if (discriminant < 0) {
		return inter;
	}else 
	{ 
		
		inter.push_back(_init_intersection(s, ((-b) - sqrt(discriminant)) / (2 * a)));
		inter.push_back(_init_intersection(s, ((-b) + sqrt(discriminant)) / (2 * a)));
		
	}
	return inter;
}

intersection Rays::_init_intersection(const sphere& s,const float& t1) 
{	
	intersection i;
	i.object = s;
	i.t = t1;
	return i;
}

intersection Rays::_hit()
{
	intersection lowest;
	if (inter.size() > 0)
	{
		lowest = inter[0];
	}else
	{
		lowest = NULL_INTERSECTION;
	}
	for (const auto& x : inter)
	{
		if (x.t > 0 && (x.t < lowest.t || lowest.t == NULL_INTERSECTION.t))
		{
			lowest = x;
		}
	}
	return lowest;
}

ray Rays::_transform(const ray& r, const matrix& m)
{

	ray r1 = r;
	r1.origin = mats._matxtup(m, r.origin);
	if (m.matrices[0][3] == 0 && m.matrices[1][3] == 0 && m.matrices[2][3] == 0) 
	{
		r1.direction = mats._matxtup(m, r.direction);
	}
	return r1;
}