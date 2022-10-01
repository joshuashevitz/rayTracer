#pragma once

#include "comparisonTests.h"
#include "tuples.h"
#include "simpleMath.h"

class TestSuite
{
public:
	TestSuite();
	~TestSuite() = default;
	bool testAddition(const tup& a,const tup& b);
	bool testSubtraction(const tup& a, const tup& b);
	bool testEquality(const tup& a, const tup& b);
	bool testType(const tup& a, float w);
	bool zeroNegation(const tup& a, const tup& zero);
	bool testNegation(const tup& a);
	bool TestScalMul(const tup& a, const float& m);
	bool TestScalDiv(const tup& a,const float& m);
	bool TestMagnitude(const tup& a, const float& m);
	bool TestNormal(const tup& a);
	bool TestDotProd(const tup& a, const tup& b, const float& dot);
	bool TestCrossProd(const tup& a, const tup& b);
private:
	Tuples tups; 
	TupleMath math;
	Comparison comp;

};
