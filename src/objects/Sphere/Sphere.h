#pragma once

#include <iostream>
#include "Tuples.h"
#include "Matrix.h" 

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
	void _clear();
private:
	sphere s;
	MatrixOps mats;
};