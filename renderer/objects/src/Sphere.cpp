#include "objects/Sphere.h"

sphere Sphere::_init_sphere(sphere& s2)
{
	_clear();
	Tuples t;
	Matrix_4x4 id;
	s.origin = t.createTuplePoint(0, 0, 0);
	s.sid = &s2;
	s.transform = mats._get_identity();
	s.transform1 = id;
	s.materials = _materials();
	return s;
}

tup Sphere::_normal_at( sphere& s, const tup& point)
{
	Matrix_4x4 identity, inverse, transpose;
	if (s.transform1 != identity)
	{
		inverse = s.transform1.Inverse(s.transform1);
		transpose = inverse.Transpose();
		tup op = inverse.xtup(point);
		tup object_normal = math.subtTuples(op, tups.createTuplePoint(0, 0, 0));
		tup wn = transpose.xtup(object_normal);
		wn.w = 0;
		return math.normilize(wn);
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
	Matrix_4x4 id;
	s.sid = 0;
	s.transform = mats._get_identity();
	s.transform1 = id;
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

color Sphere::lighting(const material& m, const tup& point, const point_light& pl, const tup& eye, const tup& normal)
{
	color effective_color = col.colorMult(m.color, pl.intensity);
	tup light = math.normilize(math.subtTuples(pl.position, point));
	color ambient = col.colorScalMul(effective_color, m.ambient);
	color diffuse;
	color specular;
	float light_dot_normal = math.dotProduct(light, normal);
	if (light_dot_normal < 0)
	{
		diffuse = col.createColor(0, 0, 0);
		specular = col.createColor(0, 0, 0);
	}
	else
	{
		diffuse = col.colorScalMul(col.colorScalMul(effective_color, m.diffuse), light_dot_normal);
		tup reflect = _reflect(math.scalarMultiplcation(light, -1), normal);
		float reflective_dot_eye = math.dotProduct(reflect, eye);
		if (reflective_dot_eye <= 0)
		{
			specular = col.createColor(0, 0, 0);
		}
		else
		{
			float factor = pow(reflective_dot_eye, m.shininess);
			specular = col.colorScalMul(col.colorScalMul(pl.intensity, m.specular),factor);
		}
	}
	return col.colorAddition(col.colorAddition(ambient, diffuse),specular);
}
