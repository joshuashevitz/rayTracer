#include "math/simpleMath.h"

tup TupleMath::addTuples(tup a, tup b) 
{
	tup c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	c.w = a.w + b.w;
	return c;	
}
tup TupleMath::subtTuples(tup a, tup b) 
{
	tup c;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	c.w = a.w - b.w;
	return c;
}
tup TupleMath::tupleNegation(tup a)
{
	tup c; 
	c.x = (a.x * -1);
	c.y = (a.y * -1);
	c.z = (a.z * -1);
	c.w = (a.w * -1);
	return c;
}

tup TupleMath::scalarMultiplcation(tup a, float m)
{
	tup b;
	b.x = (a.x * m);
	b.y = (a.y * m);
	b.z = (a.z * m);
	b.w = (a.w * m);
	return b;
}

tup TupleMath::scalarDivision(tup a, float m)
{
	tup b;
	b.x = (a.x / m);
	b.y = (a.y / m);
	b.z = (a.z / m);
	b.w = (a.w / m);
	return b;
}

float TupleMath::vectorMagnitude(const tup& a)
{
	if (a.w != 0) {
		std::cout << "Can't calculate magnitude of a non-vector!" << std::endl;
		return -1;
	}
	float power = 2.0;
	return sqrtf((pow(a.x, power))+(pow(a.y, power))+(pow(a.z, power))+(pow(a.w, power)));
}

tup TupleMath::normilize(const tup& a)
{
	float magnitude = vectorMagnitude(a);
	tup norm;
	norm.x = a.x / magnitude;
	norm.y = a.y / magnitude;
	norm.z = a.z / magnitude;
	norm.w = a.w / magnitude;
	return norm;
}

float TupleMath::dotProduct(const tup& a, const tup& b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w));
}

tup TupleMath::crossProd(const tup& a, const tup& b)
{
	tup c = tups.createTupleVector(((a.y * b.z) - (a.z * b.y)),
								   ((a.z * b.x) - (a.x * b.z)),
							       ((a.x * b.y) - (a.y * b.x)));
	return c;
}