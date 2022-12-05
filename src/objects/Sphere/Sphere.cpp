#include "Sphere.h"

sphere Sphere::_init_sphere(sphere& s2)
{
	_clear();
	Tuples t;
	s.origin = t.createTuplePoint(0, 0, 0);
	s.sid = &s2;
	s.transform = mats._get_identity();
	return s;
}

tup Sphere::_normal_at(const sphere& s, const tup& point)
{
	if (!mats._compare(s.transform, mats._get_identity()))
	{
		tup object_point = mats._matxtup(mats._inverse(s.transform), point);
		tup object_normal = math.subtTuples(object_point, tups.createTuplePoint(0, 0, 0));
		tup world_normal = mats._matxtup(mats._transpose(mats._inverse(s.transform)), object_normal);
		world_normal.w = 0;
		return math.normilize(world_normal);
	}
	return math.normilize(math.subtTuples(point, s.origin));
}

void Sphere::_clear() {
	Tuples t;
	s.sid = 0;
	s.transform = mats._get_identity();
}
