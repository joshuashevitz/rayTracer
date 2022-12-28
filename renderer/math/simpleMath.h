#pragma once

#include <cmath>
#include <math.h>
#include <iostream>
#include "math/tuples.h"

class TupleMath
{
public:
	TupleMath(){};
	~TupleMath() = default;
	tup addTuples(tup a, tup b);
	tup subtTuples(tup a, tup b);
	tup tupleNegation(tup a);
	tup scalarMultiplcation(tup a, float m);
	tup scalarDivision(tup a, float m);
	tup crossProd(const tup& a, const tup& b);
	tup normilize(const tup& a);
	float dotProduct(const tup& a, const tup& b);
	float vectorMagnitude(const tup& a);
private: 
	Tuples tups;
};