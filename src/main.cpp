#include <iostream>
#include <chrono>
#include <thread>

#include "tuples.h"
#include "simpleMath.h"
#include "TestSuite.h"
#include "Environment.h"
#include "Projectiles.h"
#include "comparisonTests.h"
#include "Canvas.h"
#include "Matrix.h"

void MyFirstPPm() {

	Color col;

	Canvas c(900, 550);
	c.printPixelMapSize();

	TupleMath math;
	Comparison comp;
	Tuples tups;
	Projectiles proj;
	Environment env;

	tup start = tups.createTuplePoint(0, 1, 0);
	tup velocity = math.scalarMultiplcation(math.normilize(tups.createTupleVector(1, 1.8, 0)), 11.25);
	projectile p = proj.CreateProj(start, velocity);
	environment e = env.createEnv(tups.createTupleVector(0, -0.1, 0), tups.createTupleVector(-0.01, 0, 0));

	while (!(p.pos.y <= 0.0))
	{
		c.write_pixel(col.createColor(1, 0, 0), p.pos.x, c._get_height() - p.pos.y);
		p = proj.tick(e, p);
	}
	c.write_to_ppm();
}

int main() {
	
	//MyFirstPPm();
	 
	TestSuite test;
	//if (matrix1._compare(m1, m2))
	//{
	//	std::cout << "compare is working effectively" << std::endl;
	//}
	//if (matrix1._compare(m1, m3))
	//{
	//	std::cout << "should not be the same, there is a problem" << std::endl;
	//}
	//
	//matrix1._print(matrix1._get_identity());
	////matrix1._print(matrix1._mat_multiplier(m1, m2));
	//std::cout << std::endl;
	////tups.printTuple(matrix1._matxtup(m3, tups.createTuplePoint(1, 2, 3)));

	//matrix1._print(matrix1._transpose(matrix1._get_identity()));
	return 0;
}

