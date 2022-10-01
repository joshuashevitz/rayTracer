
#ifdef NDEBUG
#define assert(condition, message) 0
#else
#define ASSERT(condition, message)\
   (!(condition)) ?\
      (std::cerr << "Assertion failed: (" << #condition << "), \n"\
      << "function " << __FUNCTION__\
      << ", file " << __FILE__\
      << ", line " << __LINE__ << "."\
      << std::endl << message << std::endl, abort() ,0) : 1
#endif

#include <assert.h>
#include "TestSuite.h"

TestSuite::TestSuite() 
{
	const tup& a = tups.createTuplePoint(-1, 2, -3);
	const tup& b = tups.createTuplePoint(-1, 2, -3);
	const tup& c = tups.createTupleVector(1, 4, 3);
	const tup& d = tups.createTupleVector(5, 3, 5);
	const tup& e = tups.createTuplePoint(-2, 4, -6);
	const tup& m = tups.createTupleVector(-1, -2, -3);
	const tup& dot = tups.createTupleVector(1, 2, 3);
	const tup& prod = tups.createTupleVector(2, 3, 4);
	const tup& zero = tups.createTupleVector(0, 0, 0);
	
	ASSERT((testType(c, 0.0)), "type testing is NOT functioning as correctly: ");
	ASSERT((testEquality(a, b)), "Tuple equality is NOT functioning correctly: ");
	ASSERT((testAddition(a, c)), "Tuple addition is NOT functioning correctly: ");
	ASSERT((testSubtraction(c, d)), "Tuple Subtraction is NOT functioning correctly: ");
	ASSERT((testNegation(d)), "Tuple Negation is NOT functioning correctly: ");
	ASSERT((zeroNegation(c, zero)), "Tuple Zero Negation is NOT functioning correctly: ");
	ASSERT((TestScalMul(e, 3.5)), "Scalar Mulitplcation is NOT functioning correctly: ");
	ASSERT((TestScalMul(e, 0.5)), "Scalar Mulitplcation is NOT functioning correctly: ");
	ASSERT((TestScalDiv(e, 2)), "Scalar Division is NOT functioning correctly: ");
	ASSERT((TestMagnitude(m, sqrtf(14))), "Magnitude is NOT being calculated correctly: ");
	ASSERT((TestNormal(d)), "Normalization is NOT functioning correctly: ");
	ASSERT((TestDotProd(dot, prod, 20.0)), "Dot Product is NOT functioning correctly: ");
	ASSERT((TestCrossProd(dot, prod)), "Cross Product is NOT being calculated correctly: ");
	std::cout << "ALL TESTS HAVE PASSED SUCCESSFULLY" << std::endl;
}

bool TestSuite::testEquality(const tup& a, const tup& b) 
{
	if (comp.equal(a, b)) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TestSuite::testAddition(const tup& a, const tup& b)
{
	tup e = tups.createTuplePoint(0, 6, 0) , c;
	c = math.addTuples(a, b);
	if (testType(a, 1) && testType(b, 1))
	{
		std::cout << "ADDING TWO POINTS IS INVALID" << std::endl;
		return false ;
	}
	if (testEquality(c, e)) 
	{
		return true;
	}else
	{
		return false;
	}
}

bool TestSuite::testSubtraction(const tup& a, const tup& b)
{
	tup c, e = tups.createTupleVector(-4, 1, -2);
	c = math.subtTuples(a, b);
	if (testEquality(c, e))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TestSuite::zeroNegation(const tup& a, const tup& zero)
{
	tup b = tups.createTupleVector(-1, -4, -3);
	tup c = math.subtTuples(zero, a);
	if (testEquality(b, c))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TestSuite::testNegation(const tup& a)
{
	tup b = tups.createTupleVector(-5, -3, -5);
	tup c = math.tupleNegation(a);
	if (testEquality(b, c)) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TestSuite::TestScalMul(const tup& a, const float& m)
{
	tup& b = tups.createTuplePoint(a.x * m, a.y * m, a.z * m);
	b.w = a.w * m;
	const tup& d = b;
	const tup& c = math.scalarMultiplcation(a, m);
	if (testEquality(c, d))
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool TestSuite::TestScalDiv(const tup& a, const float& m) 
{
	tup& b = tups.createTuplePoint(a.x / m, a.y / m, a.z / m);
	b.w = a.w / m;
	const tup& d = b;
	const tup& c = math.scalarDivision(a, m);
	if (testEquality(c, d))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TestSuite::TestMagnitude(const tup& a, const float& m)
{
	float b = math.vectorMagnitude(a);
	if (b == m)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TestSuite::TestNormal(const tup& a)
{
	tup b = math.normilize(a);
	if (TestMagnitude(b, 1.0)) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool TestSuite::TestDotProd(const tup& a, const tup& b, const float& dot)
{
	float c = math.dotProduct(a, b);
	if (c == dot)
	{
		return true;
	}else
	{
		return false;
	}
}

bool TestSuite::TestCrossProd(const tup& a, const tup& b)
{
	bool result = false;
	tup c = math.crossProd(a, b);
	tup d = math.crossProd(b, a);
	tup e = tups.createTupleVector(-1, 2, -1);
	tup f = tups.createTupleVector(1, -2, 1);
	if (testEquality(c, e)) {
		if (testEquality(d, f))
		{
			result = true;
		}
	}
	return result;
}

bool TestSuite::testType(const tup& a, float w)
{
	if (a.w == w)
	{
		return true;
	}
	else
	{
		return false;
	}
}