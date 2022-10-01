#pragma once

#include <iostream>
#include <thread>
#include <tuple>
#include "tuples.h"

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

	bool equal(tup a, tup b)
	{
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