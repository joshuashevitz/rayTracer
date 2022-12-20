#pragma once

#include <iostream>
#include "Tuples.h"
#include "Matrix.h" 
#include "simpleMath.h"
#include "Color.h"

struct point_light
{
	tup position;
	color intensity;
};

struct material
{
	color color;
	float ambient;
	float diffuse;
	float shininess;
	float specular;
};

struct sphere
{
	sphere* sid;
	tup origin;
	Matrix_4x4 transform;
	material materials;
};

class Sphere
{
public: 
	Sphere() {};
	~Sphere() = default;
	sphere _init_sphere(sphere& s1);
	tup _normal_at(const sphere& s, const tup& point);
	tup _reflect(const tup& in,const tup& normal);
	material _materials();
	material _fill_materials(const color& c, const float& ambient, const float& diffuse, const float& shininess, const float& specular);
	color lighting(const material& m, const tup& point, const point_light& pl, const tup& eye, const tup& normal);
	void _clear();

private:
	sphere s;
	MatrixOps mats;
	Tuples tups;
	TupleMath math;
	Color col;
};