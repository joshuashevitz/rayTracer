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

const double pi = 2 * asin(1.0);

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

void a_clock()
{
	Color col;
	Canvas c(900, 900);
	Tuples tups;
	MatrixOps mats;
	float cHeight = (c._get_height() / 2);
	float cWidth = (c._get_width() / 2);
	float radius2 = 3;
	float radius = (radius2 / 8)*c._get_width();

	matrix m = mats._get_identity();
	tup starting = tups.createTuplePoint(0, 0, 0), twelve = tups.createTuplePoint(0,0,1);
	c.write_pixel(col.createColor(1, 1, 1), (starting.x + cWidth), (starting.z + cHeight));
	c.write_pixel(col.createColor(1, 1, 1), (twelve.x*radius) + cWidth, c._get_height() - ((twelve.z * radius) + cHeight));
	for (int i = 1; i <= 12; i++)
	{
		tup three = mats._rotate_y(twelve, i * (pi / 6));
		tups.printTuple(three);
		c.write_pixel(col.createColor(1, 1, 1), (three.x * radius) + cWidth, c._get_height() - ((three.z* radius) + cHeight));
	}
	c.write_to_ppm();
}
void my_first_sphere_trace()
{
	Color col;
	Canvas c(100, 100);
	Tuples tups;
	TupleMath math;
	MatrixOps mats;
	Sphere spheres;
	sphere s = spheres._init_sphere(s);
	Rays rays;
	ray r;
	tup wallPoint;
	float wall_z = 10;
	float wall_size = 7.0;
	float pixelsize = wall_size / 100;
	float half = wall_size / 2;
	r.origin = tups.createTuplePoint(0, 0, -5);
	//std::cout << c._get_height() << " " << c._get_width() << std::endl;
	for (int y = 0; y <= c._get_height() - 1; y++)
	{
		float world_y = half - (pixelsize * y);
		//std::cout << "this world_y value is " << world_y << std::endl;
		for (int x = 0; x <= c._get_width() - 1; x++)
		{
			float world_x = -half + (pixelsize * x);
			//std::cout << "The world_x value is " << world_x << std::endl;
			wallPoint = tups.createTuplePoint(world_x, world_y, wall_z);
			//std::cout << "The wall point value is ";
			//tups.printTuple(wallPoint);
			r.direction = math.normilize(math.subtTuples(wallPoint, r.origin));
			rays.intersect(s, r);
			/*if (rays._get_inters().size() > 0)
			{
				std::cout << rays._get_inters().back().t << std::endl;
			}*/
			if (rays._hit().t > 0)
			{
				c.write_pixel(col.createColor(1, 0, 0), x, y);
			}
		}
		/*for (const auto x : rays._get_inters())
		{
			std::cout << x.t << " ";
		}
		*/
		//std::cout << rays._get_inters().size() << std::endl;
		rays._clear();
		//std::cout << rays._get_inters().size() << std::endl;
	}
	//c.write_to_ppm();
}

int main() {
	
	//MyFirstPPm();
	//a_clock();
	//TestSuite test;
	my_first_sphere_trace();
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

