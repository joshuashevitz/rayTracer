#pragma once

#pragma once

#include "core/Color.h"

#include "math/tuples.h"

class Comparison
{
public:
	Comparison() {};

	~Comparison() = default;

	bool compare(tup a, tup b) {
		if (a.w == b.w) {
			return true;
		}
		else
		{
			return false;
		}
	}

	bool equalElem(float a, float b) {
		if (abs(a - b) < EPSILON)
		{
			return true;
		}
		else {
			return false;
		}
	}

	bool equalC(color a, color b)
	{
		if (((a.blue - b.blue) <EPSILON) && ((a.red - b.red) < EPSILON) && ((a.green - b.green) < EPSILON))
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	bool equal(tup a, tup b)
	{
		if (a.w != b.w)
		{
			if (equalElem(a.x, b.x) && equalElem(a.y, b.y) && equalElem(a.z, b.z))
			{
				return true;
			}
			return false;
		}
		if (equalElem(a.x, b.x) && equalElem(a.y, b.y)  && equalElem(a.z, b.z)  && equalElem(a.w, b.w) ) {
			return true;
		}
		else {
			return false;
		}

	}
	bool isAVector(tup a) {
		if (a.w == 0.0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isAPoint(tup a) {
		if (a.w == 1.0) {
			return true;
		}
		else
		{
			return false;
		}
	}
private: 
	const float EPSILON = 0.00001;
};