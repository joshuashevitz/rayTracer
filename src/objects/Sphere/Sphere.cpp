#include "Sphere.h"

sphere Sphere::_init_sphere(sphere& s2)
{
	_clear();
	Tuples t;
	s.origin = t.createTuplePoint(0, 0, 0);
	s.sid = &s2;
	s.transform = mats._get_identity();
	s.materials = _materials();
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

tup Sphere::_reflect(const tup& in, const tup& normal)
{
	tup reflect;
	float product = math.dotProduct(in, normal);
	reflect.x = in.x - normal.x * (2 * product);
	reflect.y = in.y - normal.y * (2 * product);
	reflect.z = in.z - normal.z * (2 * product);
	reflect.w = in.w - normal.w * (2 * product);
	return reflect;
}

void Sphere::_clear() {
	Tuples t;
	s.sid = 0;
	s.transform = mats._get_identity();
}

material Sphere::_fill_materials(const color& c, const float& ambient, const float& diffuse, const float& shininess, const float& specular)
{
	material m; 
	m.ambient = ambient;
	m.color = c;
	m.diffuse = diffuse;
	m.specular = specular;
	m.shininess = shininess;
	return m;
}

material Sphere::_materials()
{
	material materials;
	color c; 
	c.red = 1, c.blue = 1, c.green = 1;
	materials.color = c;
	materials.ambient = 0.1;
	materials.diffuse = 0.9;
	materials.specular = 0.9;
	materials.shininess = 200.0;
	return materials;
}