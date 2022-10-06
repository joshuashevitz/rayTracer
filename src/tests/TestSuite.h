#pragma once

#include "comparisonTests.h"
#include "tuples.h"
#include "simpleMath.h"
#include "Color.h"
#include "matrix.h"

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
	bool colorEqual(const color& a, const color& b);
	bool TestColorScalMul(const color& a, const float& m);
	bool TestColorMult(const color& c1, const color& c2);
	bool TestMatrixComparison(const matrix& a, const matrix& b);
	bool TestSubmatrix(const matrix& m, const int& r, const int& c);
	bool TestMinor(const matrix& m, const int& r, const int& c);
	bool TestCofactor(const matrix& m, const int& r, const int& c);
	bool TestDeterminant(const matrix& m);
	bool TestInvertible(const matrix& m);
	bool TestInverse(const matrix& m);
	bool TestInverseMultiple(const matrix& m1, const matrix& m2);
private:
	Tuples tups; 
	TupleMath math;
	Comparison comp;
	Color col;
	MatrixOps matrix1;
};
