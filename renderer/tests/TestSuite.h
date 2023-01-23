#pragma once

#include "math/comparisonTests.h"
#include "math/tuples.h"
#include "math/simpleMath.h"
#include "core/Color.h"
#include "math/matrix.h"
#include "objects/Sphere.h"
#include "objects/Ray.h"

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
	bool TestMatrixComparison(const Matrix_4x4& a, const Matrix_4x4& b);
	bool TestSubmatrix(const Matrix_4x4& m, const int& r, const int& c);
	bool TestMinor(const Matrix_3x3& m, const int& r, const int& c);
	bool TestCofactor(const Matrix_3x3& m, const int& r, const int& c);
	bool TestDeterminant(const Matrix_4x4& m);
	bool TestInverse(const Matrix_4x4& m);
	bool TestInverseMultiple(const Matrix_4x4& m1, const Matrix_4x4& m2);
	bool TestTranslation(const tup& t, const tup& vec);
	bool TestInverseTranslation(const tup& t, const tup& vec);
	bool TestScaling(const tup& orig, const tup& vec);
	bool TestInverseScaling(const tup& orig, const tup& vec);
	bool TestRotations_x(const tup& t, const tup& comp, const double& rads);
	bool TestRotations_y(const tup& t, const tup& comp, const double& rads);
	bool TestRotations_z(const tup& t, const tup& comp, const double& rads);
	bool TestInverseRotations_x(const tup& t, const tup& comp, const double& rads);
	bool TestShearing(const tup& t, const float& x1, const float& x2, const float& y1, const float& y2, const float& z1, const float& z2);
	bool TestChaining(const tup& p1, const tup& s1, const tup& t1, const double& rads);
	bool TestReverseChainApplication(const tup& p1, const tup& s1, const tup& t1, const double& rads);
	bool TestTwoIntersections(const ray& r, const sphere& s);
	bool TestTangentIntersections(const ray& r, const sphere& s);
	bool TestNoIntersections(const ray& r,  sphere& s);
	bool TestOriginInSphere(const ray& r, const sphere& s);
	bool TestBehindSphere(const ray& r, const sphere& s);
	bool TestIntersectStruct(const sphere& s, const float& t);
	bool TestIntersectVector(const std::vector<intersection>& inters);
	bool TestAggregateIntersections(const std::vector<intersection>& inters, const sphere& s);
	bool TestHits();
	bool TestTransformRay(const ray& r, const tup& t);
	bool TestScalingRay(const ray& r, const tup& t);
	bool TestSphereTransformation(const sphere& s, const tup& t);
	bool TestIntersectingScaledSphere(const ray& r, const sphere& s);
	bool TestIntersectingTransformedSphere(const ray& r, const sphere& s); 
	bool TestShapeNormal( sphere& s, const tup& point);
	bool TestTranslatedNormal( sphere& s, const tup& point);
	bool TestTransformedNormal( sphere& s, const tup& point);
	bool TestReflect45Degree(const tup& in, const tup& normal);
	bool TestReflectingSlantSurface(const tup& in, const tup& normal);
	bool TestPointLightValues(const tup& position, const color& c);
	bool TestDefaultSphereMaterials(const sphere& s);
	bool TestEyeBetween(const material& m, const tup& point, const point_light& pl, const tup& eyev, const tup& normalv);
	bool TestEyeAt45(const material& m, const tup& point, const point_light& pl, const tup& eyev, const tup& normalv);
	bool TestLightAt45(const material& m, const tup& point, const point_light& pl, const tup& eyev, const tup& normalv);
	bool TestEyeInReflectPath(const material& m, const tup& point, const point_light& pl, const tup& eyev, const tup& normalv);
	bool TestLightBehindSurface(const material& m, const tup& point, const point_light& pl, const tup& eyev, const tup& normalv);

private:
	Tuples tups; 
	TupleMath math;
	Comparison comp;
	Color col;
	MatrixOps matrix1;
	Sphere s;
	Rays rays;
	Sphere SP;
	const double pi = 2 * asin(1.0);
};
