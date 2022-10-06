
#ifdef NDEBUG
#define assert(condition, message) 0
#else
#define ASSERT(condition, message)\
   (!(condition)) ?\
      (std::cerr << "Assertion failed: (" << #condition << "), \n"\
      << "function " << __FUNCTION__\
      << ", file " << __FILE__\
      << ", line " << __LINE__ << "."\
      << std::endl << message << std::endl ,0) : 1
#endif

#include <assert.h>
#include <vector>
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
	
	std::vector<float> vec{ 1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2 };
	std::vector<float> vec2{ -2,1,2,3,3,2,1,-1,4,3,6,5,1,2,7,8 };
	std::vector<float> vec3{ 1,2,3,4,2,4,4,2,8,6,4,1,0,0,0,1 };
	std::vector<float> vec4{ 3,5,0,2,-1,-7,6,-1,5 };
	std::vector<float> fourxfour{ -2,-8,3,5,-3,1,7,3,1,2,-9,6,-6,7,7,-9 };
	std::vector<float> invert{ -5, 2, 6, -8, 1, -5, 1, 8, 7, 7, -6, -7, 1, -3, 7, 4};
	std::vector<float> original{3, -9, 7, 3, 3, -8, 2, -9, -4, 4, 4, 1, -6, 5, -1, 1};
	std::vector<float> notOriginal{ 8,2,2,2,3,-1,7,0,7,0,5,4,6,-2,0,5 };

	matrix m1, m2, m3, m4, m5, m6, m7, m8;
	m1 = matrix1._create(4, 4);
	m1 = matrix1.populate_matrix(vec);

	m2 = matrix1._create(4, 4);
	m2 = matrix1.populate_matrix(vec2);

	m3 = matrix1._create(4, 4);
	m3 = matrix1.populate_matrix(vec3);

	m4 = matrix1._create(3, 3);
	m4 = matrix1.populate_matrix(vec4);

	m5 = matrix1._create(4, 4);
	m5 = matrix1.populate_matrix(fourxfour);

	m6 = matrix1._create(4, 4);
	m6 = matrix1.populate_matrix(invert);
	
	m7 = matrix1._create(4, 4);
	m7 = matrix1.populate_matrix(original);

	m8 = matrix1._create(4, 4);
	m8 = matrix1.populate_matrix(notOriginal);

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
	ASSERT((TestSubmatrix(m1, 2, 1)), "Submatrix is NOT functioning as it should be: ");
	ASSERT((TestMinor(m4, 1, 0)), "NOT calculating the minor correctly: ");
	ASSERT((TestCofactor(m4, 1, 0)), "Cofactor is NOT being deterimined correctly: ");
	ASSERT((TestDeterminant(m5)), "Detetminant of 4x4 matrix operations NOT working correctly: ");
	ASSERT((TestInverse(m6)),"Did NOT invert correctly: ");
	ASSERT((TestInverseMultiple(m7, m8)), "Inverse Multiple is NOT operating correctly: ");
	//std::cout << "ALL TESTS HAVE PASSED SUCCESSFULLY" << std::endl;
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
	else{
		return false;
	}
}
bool TestSuite::colorEqual(const color& c1, const color& c2)
{
	if (comp.equalC(c1, c2))
	{
		return true;
	}
	else {
		return false;
	}
}

bool TestSuite::TestColorScalMul(const color& a, const float& m)
{
	color c = col.createColor(a.blue * m, a.red * m, a.green * m);
	color b = col.colorScalMul(a, m);
	if (colorEqual(c, b))
	{
		return true;
	}
	else{
		return false;
	}
}

bool TestSuite::TestColorMult(const color& c1, const color& c2)
{
	color c3 = col.createColor((c1.blue * c2.blue), (c1.red * c2.red), (c1.green * c2.green));
	color c4 = col.colorMult(c1, c2);
	if (colorEqual(c3, c4))
	{
		return true;
	}
	else {
		return false;
	}
}

bool TestSuite::TestMatrixComparison(const matrix& a, const matrix& b) 
{
	if (!matrix1._compare(a, b))
	{
		return true;
	}
	return false;
}

bool TestSuite::TestSubmatrix(const matrix& mat, const int& r, const int& c)
{
	matrix m;
	m = matrix1._create(3, 3);
	std::vector<float> testvector{ 1, 3, 4,
								   5, 7, 8,
								   5, 3, 2}; 

	m = matrix1.populate_matrix(testvector);
	if (matrix1._compare(m, matrix1._submatrix(mat, r, c)))
	{
		return true;
	}
	return false;
}

bool TestSuite::TestMinor(const matrix& m, const int& r, const int& c)
{
	float truth= 25, result = matrix1._minor(m, r, c);
	if (result == truth)
	{
		return true;
	}
	return false;
}

bool TestSuite::TestCofactor(const matrix& m, const int& r, const int& c)
{
	float result = matrix1._cofactor(m, r, c), truth = -25;
	if (result == truth)
	{
		return true;
	}
	return false;
}

bool TestSuite::TestDeterminant(const matrix& m)
{
	float result = matrix1._2d_determinant(m);
	
	std::cout << result << std::endl;

	if (result == (-4071))
	{
		return true;
	}
	return false;
}

bool TestSuite::TestInverse(const matrix& m)
{
	matrix test, m2;
	std::vector<float> inverse{ 0.218045f, 0.451128f, 0.240602f, -0.0451128f,
							   -0.808271f, -1.45677f, -0.443609f, 0.520677f,
							   -0.0789474f, -0.223684f, -0.0526316f, 0.197368f,
							   -0.522556f, -0.81391f, -0.300752f, 0.306391f };
	test = matrix1._create(4, 4);
	test = matrix1.populate_matrix(inverse);
	m2 = matrix1._create(4, 4);
	m2 = matrix1._inverse(m);

	matrix1._print(test);
	std::cout << "\n\n" << std::endl;
	matrix1._print(m2);
	/*for (int i = 0; i <= test.rows - 1; i++)
	{
		for (int j = 0; j <= test.rows - 1; j++)
		{
			std::cout << test.matrices[i][j] - m2.matrices[i][j] << std::endl;
		}
	}*/

	//matrix1._print(test);
	//std::cout << "\n" << std::endl;
	//matrix1._print(matrix1._inverse(m));
	
	return matrix1._compare(matrix1._inverse(m), test);

}

bool TestSuite::TestInverseMultiple(const matrix& m1, const matrix& m2)
{
	matrix m; 
	m = matrix1._create(4, 4);
	m = matrix1._mat_multiplier(m1, m2);

	//matrix1._print(matrix1._mat_multiplier(m, matrix1._inverse(m2)));
	//std::cout << "\n\n" << std::endl;
	//matrix1._print(m1);

	return matrix1._compare(matrix1._mat_multiplier(m, matrix1._inverse(m2)), m1);
}