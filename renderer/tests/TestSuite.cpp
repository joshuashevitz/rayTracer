
#ifdef NDEBUG
#define assert(condition, message) 0
#else
#define ASSERT(condition, message)\
   (!(condition)) ?\
      (std::cerr << "Assertion failed: (" << #condition << "), \n"\
      << "function " << __FUNCTION__\
      << ", file " << __FILE__\
      << ", line " << __LINE__ << "."\
      << std::endl << message << std::endl , abort(), 0) : 1
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
	const tup& translate = tups.createTupleVector(5, -3, 2);
	const tup& transPoint = tups.createTuplePoint(-3, 4, 5);
	const tup& scalable = tups.createTuplePoint(-4, 6, 8);
	const tup& scaler = tups.createTupleVector(2, 3, 4);
	const tup& scaler2 = tups.createTupleVector(-4, 6, 8);
	const tup& rotate_x = tups.createTuplePoint(0, 1, 0);
	const tup& rotate_y = tups.createTuplePoint(0, 0, 1);
	const tup& comp_x = tups.createTuplePoint(0, (sqrt(2) / 2), (sqrt(2) / 2));
	const tup& comp_x_i = tups.createTuplePoint(0, (sqrt(2) / 2), -(sqrt(2) / 2));
	const tup& comp_y = tups.createTuplePoint((sqrt(2) / 2), 0, (sqrt(2) / 2));
	const tup& comp_z = tups.createTuplePoint(-(sqrt(2) / 2), (sqrt(2) / 2), 0);
	const tup& shear = tups.createTuplePoint(2, 3, 4);
	const tup& chainPoint = tups.createTuplePoint(1, 0, 1);
	const tup& chainScaling = tups.createTuplePoint(5, 5, 5);
	const tup& chainTranslation = tups.createTuplePoint(10, 5, 7);
	const tup& ray_transformation = tups.createTupleVector(3, 4, 5);
	const tup& sphereNormal_x = tups.createTuplePoint(1, 0, 0);
	const tup& sphereNormalTranslated = tups.createTuplePoint(0, 1.70711, -0.70711);
	const tup& sphereNormalTransformed = tups.createTuplePoint(0, sqrt(2)/2, -sqrt(2)/2);
	const tup& in = tups.createTupleVector(1, -1, 0);
	const tup& in2 = tups.createTupleVector(0, -1, 0);
	const tup& normal = tups.createTupleVector(0, 1, 0);
	const tup& normal2 = tups.createTupleVector(sqrt(2) / 2, sqrt(2) / 2, 0);
	const tup& eyev = tups.createTupleVector(0, 0, -1);
	const tup& normalv = tups.createTupleVector(0, 0, -1);
	const tup& zeroPos = tups.createTuplePoint(0, 0, 0);
	const tup& eyev45 = tups.createTupleVector(0, sqrt(2) / 2, -sqrt(2) / 2);
	const tup& eyevInPath = tups.createTupleVector(0, -sqrt(2) / 2, -sqrt(2) / 2);

	std::vector<float> vec{ 1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2 };
	std::vector<float> vec2{ -2,1,2,3,3,2,1,-1,4,3,6,5,1,2,7,8 };
	std::vector<float> vec3{ 1,2,3,4,2,4,4,2,8,6,4,1,0,0,0,1 };
	std::vector<float> vec4{ 3,5,0,2,-1,-7,6,-1,5 };
	std::vector<float> fourxfour{ -2,-8,3,5,-3,1,7,3,1,2,-9,6,-6,7,7,-9 };
	std::vector<float> invert{ -5, 2, 6, -8, 1, -5, 1, 8, 7, 7, -6, -7, 1, -3, 7, 4};
	std::vector<float> original{3, -9, 7, 3, 3, -8, 2, -9, -4, 4, 4, 1, -6, 5, -1, 1};
	std::vector<float> notOriginal{ 8,2,2,2,3,-1,7,0,7,0,5,4,6,-2,0,5 };

	Matrix_4x4 m1, m12, m13, m14, m15;
	Matrix_3x3 m9, m11;
	m1.Fill(vec);
	m9.Fill(vec4);
	m11.Fill(vec4);
	m12.Fill(fourxfour);
	m13.Fill(invert);
	m14.Fill(original);
	m15.Fill(notOriginal);
	
	sphere s1, s2, s3, s4, s5, s6, s7, s8, s9;
	s1 = s._init_sphere(s1), s2 = s._init_sphere(s2), s3 = s._init_sphere(s3);
	s4 = s1, s5 = s1, s6 = s1, s7 = s1, s8 = s1, s9 = s1;
	point_light pl;
	pl.position = tups.createTuplePoint(0, 0, -10);
	pl.intensity = col.createColor(1, 1, 1);
	
	point_light pl2 = pl, pl3 = pl;
	pl2.position.y = 10;
	pl3.position.z = 10;

	ray r1 = rays._init_ray(tups.createTuplePoint(0, 0, -5), tups.createTupleVector(0, 0, 1));
	ray r2 = rays._init_ray(tups.createTuplePoint(0, 1, -5), tups.createTupleVector(0, 0, 1));
	ray r3 = rays._init_ray(tups.createTuplePoint(0, 2, -5), tups.createTupleVector(0, 0, 1));
	ray r4 = rays._init_ray(tups.createTuplePoint(0, 0, 0), tups.createTupleVector(0, 0, 1));
	ray r5 = rays._init_ray(tups.createTuplePoint(0, 0, 5), tups.createTupleVector(0, 0, 1));
	ray r6 = rays._init_ray(tups.createTuplePoint(1, 2, 3), tups.createTupleVector(0, 1, 0));
	
	ASSERT((testType(c, 0.0)), "type testing is NOT operating as correctly: ");
	ASSERT((testEquality(a, b)), "Tuple equality is NOT operating correctly: ");
	ASSERT((testAddition(a, c)), "Tuple addition is NOT operating correctly: ");
	ASSERT((testSubtraction(c, d)), "Tuple Subtraction is NOT operating correctly: ");
	ASSERT((testNegation(d)), "Tuple Negation is NOT operating correctly: ");
	ASSERT((zeroNegation(c, zero)), "Tuple Zero Negation is NOT operating correctly: ");
	ASSERT((TestScalMul(e, 3.5)), "Scalar Mulitplcation is NOT operating correctly: ");
	ASSERT((TestScalMul(e, 0.5)), "Scalar Mulitplcation is NOT operating correctly: ");
	ASSERT((TestScalDiv(e, 2)), "Scalar Division is NOT operating correctly: ");
	ASSERT((TestMagnitude(m, sqrtf(14))), "Magnitude is NOT being calculated correctly: ");
	ASSERT((TestNormal(d)), "Normalization is NOT operating correctly: ");
	ASSERT((TestDotProd(dot, prod, 20.0)), "Dot Product is NOT operating correctly: ");
	ASSERT((TestCrossProd(dot, prod)), "Cross Product is NOT being calculated correctly: ");
	ASSERT((TestSubmatrix(m1, 2, 1)), "Submatrix is NOT operating as it should be: ");
	ASSERT((TestMinor(m9, 1, 0)), "NOT calculating the minor correctly: ");
	ASSERT((TestCofactor(m11, 1, 0)), "Cofactor is NOT being deterimined correctly: ");
	ASSERT((TestDeterminant(m12)), "Detetminant of 4x4 matrix operations NOT operating correctly: ");
	ASSERT((TestInverse(m13)),"Did NOT invert correctly: ");
	ASSERT((TestInverseMultiple(m14, m15)), "Inverse Multiple is NOT operating correctly: ");
	ASSERT((TestTranslation(transPoint, translate)), "Translation is NOT operating correctly: ");
	ASSERT((TestInverseTranslation(transPoint, translate)), "Inverse Translation did NOT operate correctly: ");
	ASSERT((TestScaling(scalable, scaler)), "Scaling NOT operating correctly: ");
	ASSERT((TestScaling(scaler2, scaler)), "Scaling with vector NOT operating correctly: ");
	ASSERT((TestInverseScaling(scaler2, scaler)), "Inverse Scaling NOT operating correctly: ");
	ASSERT((TestRotations_x(rotate_x, comp_x ,pi / 4)), "X Rotation is NOT operating correctly: ");
	ASSERT((TestInverseRotations_x(rotate_x, comp_x_i, pi / 4)), "Inverse Rotation NOT operating correctly: ");
	ASSERT((TestRotations_y(rotate_y, comp_y, pi / 4)), "Y Rotation is NOT operating correctly: ");
	ASSERT((TestRotations_z(rotate_x, comp_z, pi / 4)), "Z Rotations is NOT operating correctly: ");
	ASSERT((TestShearing(shear, 0, 0, 1, 0, 0, 0)), "Shearing is NOT operating correctly: ");
	ASSERT((TestChaining(chainPoint, chainScaling, chainTranslation, pi / 2)), "Chaining functions test is NOT operating correctly: ");
	ASSERT((TestReverseChainApplication(chainPoint, chainScaling, chainTranslation, pi / 2)), "Reverse Chaining is NOT operating as expected: ");
	ASSERT((TestTwoIntersections(r1, s1)), "Intersting two points is NOT operating as expected: ");
	ASSERT((TestTangentIntersections(r2, s1)), "Intersection tangent to sphere is NOT operating as expected: ");
	ASSERT((TestNoIntersections(r3, s3)), "Missed Intersection NOT operating as expected: ");
	ASSERT((TestOriginInSphere(r4, s1)), "Starting In Sphere NOT operating as expected: ");
	ASSERT((TestBehindSphere(r5, s2)), "Ray NOT appearing behind sphere as expected: ");
	ASSERT((TestIntersectVector(rays._get_inters())), "Intersections NOT being recorded properly: ");
	ASSERT((TestHits()), "Hits NOT operating as Expected: ");
	ASSERT((TestTransformRay(r6, ray_transformation)), "Ray Transformation NOT operating as expected: ");
	ASSERT((TestScalingRay(r6, prod)), "Ray Scaling is NOT operating as expected: ");
	ASSERT((TestSphereTransformation(s1, scaler)), "Setting Transform Matrix in Sphere is NOT operating as expected: ");
	ASSERT((TestIntersectingScaledSphere(r1, s1)), "Attempt to Intersect Scaled Sphere NOT operating as expected: ");
	ASSERT((TestIntersectingTransformedSphere(r1, s1)), "Attempt to Intersect Transformed sphere NOT operating as expected: ");
	ASSERT((TestShapeNormal(s1, sphereNormal_x)), "Normalization of x is NOT operating as expected: ");
	ASSERT((TestTranslatedNormal(s1, sphereNormalTranslated)), "Translated Normal is NOT operating as expected: ");
	ASSERT((TestTransformedNormal(s1, sphereNormalTransformed)), "Transformed Normal is NOT operating as expected: ");
	ASSERT((TestReflect45Degree(in, normal)), "Reflecting at 45 degrees is NOT operating as expected: ");
	ASSERT((TestReflectingSlantSurface(in2, normal2)), "Reflecting off a Slant Surface is NOT operating as expected: ");
	ASSERT((TestEyeBetween(s1.materials, zeroPos, pl, eyev, normalv)), "Lighting with eye between light and object is NOT operating as expected: ");
	ASSERT((TestEyeAt45(s1.materials, zeroPos, pl, eyev45, normalv)), "Lighting when eye is at a 45 is NOT operating as expected: ");
	ASSERT((TestLightAt45(s1.materials, zeroPos, pl2, eyev, normalv)), "Lighting when Light is at a 45 is NOT operating as expected: ");
	ASSERT((TestEyeInReflectPath(s1.materials, zeroPos, pl2, eyevInPath, normalv)), "Eye in Lights reflective path in NOT operating as expected: ");
	ASSERT((TestLightBehindSurface(s1.materials, zeroPos, pl3, eyev, normalv)), "Light behind surface is NOT operating as expected: ");
	//std::cout << "ALL TESTS HAVE PASSED SUCCESSFULLY" << std::endl;
	//matrix1._print(matrix1._add_rotation_x((2 * asin(1.0)) / 4));
	//tups.printTuple(matrix1._rotate_x(rotate_x,(2 * asin(1.0)) / 2));
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
	tup b = tups.createTuplePoint(a.x * m, a.y * m, a.z * m);
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
	tup b = tups.createTuplePoint(a.x / m, a.y / m, a.z / m);
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

bool TestSuite::TestMatrixComparison(const Matrix_4x4& a, const Matrix_4x4& b)
{
	Matrix<float, 4u, 4u> matA = a;
	matA.add_rotationX(2.0);
	if (matA != b)
	{
		return true;
	}
	return false;
}

bool TestSuite::TestSubmatrix(const Matrix_4x4& mat, const int& r, const int& c)
{
	Matrix_4x4 a = mat;
	Matrix_3x3 b, b1;
	b = Submatrix(a, r, c);

	std::vector<float> testvector{ 1, 3, 4,
								   5, 7, 8,
								   5, 3, 2}; 
	b1.Fill(testvector);
	if (b == b1)
	{
		return true;
	}
	return false;
}

bool TestSuite::TestMinor(const Matrix_3x3& m, const int& r, const int& c)
{
	Matrix_3x3 a = m, b;
	float result = Minor<3, 3>(a, r, c);
	float truth = 25;
	if (result == truth)
	{
		return true;
	}
	return false;
}

bool TestSuite::TestCofactor(const Matrix_3x3& m, const int& r, const int& c)
{
	Matrix_3x3 m1 = m;
	float result = Cofactor<3,3>(m1, r, c), truth = -25;
	if (result == truth)
	{
		return true;
	}
	return false;
}

bool TestSuite::TestDeterminant(const Matrix_4x4& m)
{
	Matrix_4x4 m1 = m;
	float result = Determinant(m1);
	if (result == (-4071))
	{
		return true;
	}
	return false;
}

bool TestSuite::TestInverse(const Matrix_4x4& m)
{
	Matrix_4x4 inverted, test, m1 = m;
	inverted = m1.Inverse(m1);
	//for (std::size_t i = 0; i < m1.GetRow(); i++)
	//{
	//	for (std::size_t j = 0; j < m1.GetCol(); j++)
	//	{
	//		std::cout << inverted.data[i][j] << " ";
	//	}
	//	std::cout << std::endl;
	//}
	std::vector<float> inverse{ 0.218045f, 0.451128f, 0.240602f, -0.0451128f,
							   -0.808271f, -1.45677f, -0.443609f, 0.520677f,
							   -0.0789474f, -0.223684f, -0.0526316f, 0.197368f,
							   -0.522556f, -0.81391f, -0.300752f, 0.306391f };
	test.Fill(inverse);

	if (inverted == test)
	{
		return true;
	}
	return false;
}

bool TestSuite::TestInverseMultiple(const Matrix_4x4& m1, const Matrix_4x4& m2)
{
	Matrix_4x4 m3, m4, m5 = m2;
	m3 = m3.xMatrix(m1, m2);
	m4 = m4.xMatrix(m3, m4.Inverse(m5));

	if (m4 == m1)
	{
		return true;
	}
	return false;
}

bool TestSuite::TestTranslation(const tup& t, const tup& vec)
{
	tup p = tups.createTuplePoint(2, 1, 7);
	return comp.equal(matrix1._translation(t, vec), p);
}
 
bool TestSuite::TestInverseTranslation(const tup& t, const tup& vec)
{	
	tup test = tups.createTuplePoint(-8, 7, 3);
	return comp.equal(matrix1._inverse_translation(t, vec), test);
}

bool TestSuite::TestScaling(const tup& orig, const tup& vec)
{
	tup test = tups.createTuplePoint(-8, 18, 32);
	return comp.equal(matrix1._scaling(orig, vec), test);
}

bool TestSuite::TestInverseScaling(const tup& orig, const tup& vec)
{
	tup test = tups.createTupleVector(-2, 2, 2);
	return comp.equal(matrix1._inverse_scaling(orig, vec), test);
}

bool TestSuite::TestRotations_x(const tup& t,const tup& comp_x ,const double& rads)
{

	return comp.equal(matrix1._rotate_x(t, rads), comp_x);
}
bool TestSuite::TestRotations_y(const tup& t, const tup& comp_x, const double& rads)
{

	return comp.equal(matrix1._rotate_y(t, rads), comp_x);
}

bool TestSuite::TestRotations_z(const tup& t, const tup& comp_x, const double& rads)
{

	return comp.equal(matrix1._rotate_z(t, rads), comp_x);
}

bool TestSuite::TestInverseRotations_x(const tup& t,const tup& comp_x, const double& rads)
{
	return comp.equal(matrix1._matxtup(matrix1._inverse(matrix1._add_rotation_x(rads)), t), comp_x);
}

bool TestSuite::TestShearing(const tup& t, const float& x1, const float& x2, const float& y1, const float& y2, const float& z1, const float& z2)
{
	tup test = tups.createTuplePoint(2, 5, 4);
	return comp.equal(matrix1._shearing(t, x1, x2, y1, y2, z1, z2), test);
}

bool TestSuite::TestChaining(const tup& p1, const tup& s1, const tup& t1, const double& rads)
{
	tup test1 = tups.createTuplePoint(1, -1, 0),
		test2 = tups.createTuplePoint(5, -5, 0),
		test3 = tups.createTuplePoint(15, 0, 7);
	
	tup p2 = matrix1._rotate_x(p1, rads);
	if (!comp.equal(p2, test1))
	{
		return false;
	}

	tup p3 = matrix1._scaling(p2, s1);
	if (!comp.equal(p3, test2))
	{
		return false;
	}

	tup p4 = matrix1._translation(p3, t1);
	if (!comp.equal(p4, test3))
	{
		return false;
	}

	return true;
}

bool TestSuite::TestReverseChainApplication(const tup& p1, const tup& s1, const tup& t1, const double& rads)
{
	tup test = tups.createTuplePoint(15, 0, 7);
	matrix m = matrix1._mat_multiplier(matrix1._add_translation(t1), matrix1._add_scaling(s1.x, s1.y, s1.z));
	m = matrix1._mat_multiplier(m, matrix1._add_rotation_x(pi / 2));
	tup pos = matrix1._matxtup(m, p1);
	if(comp.equal(pos, test))
	{
		return true;
	}
	return false;
}

bool TestSuite::TestTwoIntersections(const ray& r, const sphere& s) 
{
	sphere s1 = s;
	SP._init_sphere(s1);
	rays.intersect(s, r);
	if (rays._get_inters()[0].t == 4.0 && rays._get_inters()[1].t == 6.0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool TestSuite::TestTangentIntersections(const ray& r, const sphere& s) 
{
	rays.intersect(s, r);
	if (rays._get_inters()[rays._get_inters().size() -2].t == 5.0 && rays._get_inters()[rays._get_inters().size() -2].t == rays._get_inters()[rays._get_inters().size() -1].t)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool TestSuite::TestNoIntersections(const ray& r, sphere& s) 
{
	rays.intersect(s, r);
	for (auto& x : rays._get_inters())
	{
		if (x.object.sid == s.sid)
		{
			return false;
		}
	}
	return true;
}
bool TestSuite::TestOriginInSphere(const ray& r, const sphere& s) 
{
	rays.intersect(s, r);
	if (rays._get_inters()[rays._get_inters().size() -2].t == -1.0 && rays._get_inters().back().t == 1.0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool TestSuite::TestBehindSphere(const ray& r, const sphere& s) 
{
	rays.intersect(s, r);
	if (rays._get_inters()[rays._get_inters().size() - 2].t == -6.0 && rays._get_inters()[rays._get_inters().size() - 1].t == -4.0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool TestSuite::TestIntersectStruct(const sphere& s, const float& t1) 
{
	intersection i;
	i.object = s;
	i.t = t1;
	if (i.object.sid && i.t == t1) {
		return true;
	}
	else
	{
		return false;
	}
}

bool TestSuite::TestIntersectVector(const std::vector<intersection>& inters) 
{
	if (inters.size() == 0)
	{
		return false;
	}
	return true;
}

//=====================================================================
// add proper test function to test the aggregate intersection of
// a sphere and a ray to properly show it is working effectively
//=====================================================================
bool TestSuite::TestAggregateIntersections(const std::vector<intersection>& inters, const sphere& s)
{
	ray r = rays._init_ray(tups.createTuplePoint(0, 0, -7), tups.createTupleVector(0, 0, 1));
	ray r1 = rays._init_ray(tups.createTuplePoint(0, 0, 3), tups.createTupleVector(0, 0, 1));
	rays.intersect(s, r);
	rays.intersect(s, r1);
	

	return true;
}

bool TestSuite::TestHits()
{
	intersection lowest = rays._hit();
	if (lowest.t < 0)
	{
		return false;
	}
	if (lowest.t == 1.0)
	{
		return true;
	}
}

bool TestSuite::TestTransformRay(const ray& r, const tup& t)
{
	tup TestOrig = tups.createTuplePoint(4, 6, 8);
	tup TestVec = tups.createTupleVector(0, 1, 0);
	matrix m = matrix1._add_translation(t);
	ray r_test = rays._transform(r, m);
	if (comp.equal(r_test.origin, TestOrig) && comp.equal(r.direction, r_test.direction))
	{
		return true;
	}
	return false;
}

bool TestSuite::TestScalingRay(const ray& r, const tup& t) 
{
	tup TestOrig = tups.createTuplePoint(2, 6, 12);
	tup TestVec = tups.createTupleVector(0, 3, 0);
	matrix m = matrix1._add_scaling(t.x,t.y,t.z);
	ray r_test = rays._transform(r, m);
	if (comp.equal(r_test.origin, TestOrig) && comp.equal(r_test.direction, TestVec))
	{
		return true;
	}
	return false;
}

bool TestSuite::TestSphereTransformation(const sphere& s, const tup& t)
{
	sphere s1 = SP._init_sphere(s1);
	s1.transform = matrix1._add_translation(t);
	
	return true;
}

bool TestSuite::TestIntersectingScaledSphere(const ray& r, const sphere& s)
{
	sphere s1 = s;
	s1.transform1.add_scaler(2, 2, 2);
	s1.transform = matrix1._add_scaling(2, 2, 2);
	rays.intersect(s1, r);
	if (rays._get_inters().back().t == 7 && rays._get_inters()[rays._get_inters().size() - 2].t == 3)
	{
		return true;
	}
	return false;
}

bool TestSuite::TestIntersectingTransformedSphere(const ray& r, const sphere& s)
{
	sphere s1 = s;
	s1.transform = matrix1._add_translation(tups.createTupleVector(5, 0, 0));
	rays.intersect(s1, r);
	if (rays._get_inters().back().t == 7)
	{
		return true;
	}
	return false;
}

bool TestSuite::TestShapeNormal( sphere& s, const tup& point)
{
	sphere s1 = s;
	SP._init_sphere(s1);
	tup norm = SP._normal_at(s1, point);
	tup TestVec = tups.createTupleVector(1, 0, 0);
	if (comp.equal(norm, TestVec));
	{
		s.transform1.ToIdentity();
		return true;
	}
	return false;
}
bool TestSuite::TestTranslatedNormal(sphere& s, const tup& point)
{
	sphere s1 = s;
	s1.transform1.add_translation(0, 1, 0);
	tup norm = SP._normal_at(s1, point);
	tup TestVec = tups.createTupleVector(0, 0.70711, -0.70711);
	
	tups.printTuple(norm);

	if (comp.equal(norm, TestVec));
	{
		
		return true;
	}
	return false;
}
bool TestSuite::TestTransformedNormal(sphere& s, const tup& point)
{
	sphere s1 = s;
	s.transform1.add_scaler(1, 0.5, 1);
	s1.transform1.add_rotationZ((2 * asin(1.0)) / 5);
	s1.transform1.xMatrix(s.transform1, s1.transform1);
	s1.transform = matrix1._mat_multiplier(matrix1._add_scaling(1,0.5,1), matrix1._add_rotation_z(matrix1._get_pi()/5));
	tup norm = SP._normal_at(s1, point);
	tup TestVec = tups.createTupleVector(0, 0.97014, -0.24254);
	if (comp.equal(norm, TestVec));
	{
		return true;
	}
	return false;
}

bool TestSuite::TestReflect45Degree(const tup& in, const tup& normal)
{
	tup test_vec = tups.createTupleVector(1, 1, 0);
	if (comp.equal(test_vec, SP._reflect(in, normal)))
	{
		return true;
	}
	return false;
}

bool TestSuite::TestReflectingSlantSurface(const tup& in, const tup& normal)
{
	tup test_vec = tups.createTupleVector(1, 0, 0);
	if (comp.equal(test_vec, SP._reflect(in, normal)))
	{
		return true;
	}
	return false;
}

bool TestSuite::TestPointLightValues(const tup& position, const color& c)
{
	point_light pl; 
	pl.intensity = c;
	pl.position = position;

	if (comp.equalC(pl.intensity, c) && comp.equal(pl.position, position))
	{
		return true;
	}
	return false;
}

bool TestSuite::TestDefaultSphereMaterials(const sphere& s)
{
	material m = s.materials;
	if (comp.equalC(m.color, s.materials.color) && comp.equalElem(m.ambient, s.materials.ambient) && comp.equalElem(m.diffuse, s.materials.diffuse) && comp.equalElem(m.shininess, s.materials.shininess) && comp.equalElem(m.specular, s.materials.specular))
	{
		return true;
	}
	return false;
}

bool TestSuite::TestEyeBetween(const material& m, const tup& point, const point_light& pl, const tup& eyev, const tup& normalv)
{
	color result = col.createColor(1.9, 1.9, 1.9);
	if(comp.equalC(result, SP.lighting(m, point, pl, eyev, normalv)))
	{
		return true;
	}
	return false;
}

bool TestSuite::TestEyeAt45(const material& m, const tup& point, const point_light& pl, const tup& eyev, const tup& normalv)
{
	color result = col.createColor(1.0, 1.0, 1.0);
	if (comp.equalC(result, SP.lighting(m, point, pl, eyev, normalv)))
	{
		return true;
	}
	return false;
}

bool TestSuite::TestLightAt45(const material& m, const tup& point, const point_light& pl, const tup& eyev, const tup& normalv)
{
	color result = col.createColor(0.736396, 0.736396, 0.736396);
	if (comp.equalC(result, SP.lighting(m, point, pl, eyev, normalv)))
	{
		return true;
	}
	return false;
}

bool TestSuite::TestEyeInReflectPath(const material& m, const tup& point, const point_light& pl, const tup& eyev, const tup& normalv)
{
	color result = col.createColor(1.63639, 1.63639, 1.63639);
	if (comp.equalC(result, SP.lighting(m, point, pl, eyev, normalv)))
	{
		return true;
	}
	return false;
}

bool TestSuite::TestLightBehindSurface(const material& m, const tup& point, const point_light& pl, const tup& eyev, const tup& normalv)
{
	color result = col.createColor(0.1, 0.1, 0.1);
	if (comp.equalC(result, SP.lighting(m, point, pl, eyev, normalv)))
	{
		return true;
	}
	return false;
}