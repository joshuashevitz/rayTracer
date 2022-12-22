#pragma once

#include <iostream>

struct tup {
	float x;
	float y;
	float z;
	float w;
};

class Tuples
{
public: 
	Tuples(){};
	
	~Tuples() = default;

	tup createTuplePoint(float x, float y, float z) 
	{
		tup p;
		p.x = x;
		p.y = y;
		p.z = z;
		p.w = 1.0;
		return p;
	}
	tup createTupleVector(float x, float y, float z)
	{
		tup p;
		p.x = x;
		p.y = y;
		p.z = z;
		p.w = 0.0;
		return p;
	}

	tup _invert(const tup& t)
	{
		return createTuplePoint((-1 * t.x), (-1 * t.y), (-1 * t.z));
	}

	void printTuple(const tup& a)
	{
		std::cout << a.x << "\t" << a.y << "\t" << a.z << "\t" << a.w << std::endl;
	}

private:
};