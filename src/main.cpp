#include <iostream>
#include <chrono>
#include <thread>

#include "tuples.h"
#include "simpleMath.h"
#include "TestSuite.h"
#include "Environment.h"
#include "Projectiles.h"
#include "comparisonTests.h"


int main() {
	//TestSuite test;
	TupleMath math;
	Comparison comp;
	Tuples tups;
	Projectiles proj;
	Environment env;

	tup point1 =tups.createTuplePoint(0, 10, 0);	 
	tup zero = tups.createTupleVector(0, 0, 0);
	projectile p = proj.CreateProj(point1, math.normilize(tups.createTupleVector(1, 1, 0)));
	environment e = env.createEnv(tups.createTupleVector(0, -0.1, 0), tups.createTupleVector(-0.01, 0, 0));

	while (!(p.pos.y <= zero.y))
	{
		p = proj.tick(e, p);
		tups.printTuple(p.pos);
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}


	return 0;
}