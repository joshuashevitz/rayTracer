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

void Sphere::_clear() {
	Tuples t;
	s.sid = 0;
	s.transform = mats._get_identity();
}
