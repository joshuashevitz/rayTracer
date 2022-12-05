#pragma once

#include <iostream>
#include "Tuples.h"
#include "Matrix.h" 
#include "simpleMath.h"

struct sphere
{
	sphere* sid;
	tup origin;
	matrix transform;
};

class Sphere
{
public: 
	Sphere() {};
	~Sphere() = default;
	sphere _init_sphere(sphere& s1);
	tup _normal_at(const sphere& s, const tup& point);
	void _clear();

private:
	sphere s;
	MatrixOps mats;
	Tuples tups;
	TupleMath math;
};