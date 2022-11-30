#pragma once

#include <iostream>
#include "tuples.h"
#include "simpleMath.h"
#include <vector>
#include "Sphere.h"
#include "matrix.h"

struct ray
{
	tup origin; 
	tup direction;
};

struct intersection {
	float t;
	sphere object;
};

class Rays
{
public: 
	Rays() { 
		NULL_INTERSECTION.t = NULL; 
	};
	~Rays() = default;
	ray _get_ray()
	{
		return R;
	}
	std::vector<intersection> _get_inters() 
	{
		return inter;
	}
	intersection _null()
	{
		return NULL_INTERSECTION;
	}
	intersection _init_intersection(const sphere& s, const float& r);
	intersection _hit();
	ray _init_ray(const tup& origin, const tup& direction);
	ray _transform(const ray& r, const matrix& m);
	tup _position(const ray& r, const float& t);
	std::vector<intersection> intersect(const sphere& s,const ray& r);
	void _clear();

private:
	intersection NULL_INTERSECTION;
	MatrixOps mats;
	Tuples tups;  
	ray R;
	Sphere S;
	TupleMath math;
	std::vector<intersection> inter;
};

