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
	s.materials = spheres._materials();
	s.materials.color = col.createColor(1, 0.2, 1);
	Rays rays;
	ray r;
	tup wallPoint;
	point_light pl; 
	pl.intensity = col.createColor(1, 1, 1);
	pl.position = tups.createTuplePoint(-10, -10, -10);
	float wall_z = 10;
	float wall_size = 7.0;
	float pixelsize = wall_size / 100;
	float half = wall_size / 2;
	float world_x = 0, world_y = 0;
	r.origin = tups.createTuplePoint(0, 0, -5);
	//s.transform = mats._mat_multiplier(mats._add_shear(1, 0, 0.5, 0, 1, 0), mats._add_scaling(0.8, 1, 1));
	//s.transform = mats._add_translation(tups.createTuplePoint(0.5, 0, 0.5));
	for (int y = 0; y <= c._get_height() - 1; y++)
	{
		world_y = half - (pixelsize * y);
	
		for (int x = 0; x <= c._get_width() - 1; x++)
		{
			world_x = -half + (pixelsize * x);
			wallPoint = tups.createTuplePoint(world_x, world_y, wall_z);
			r.direction = math.normilize(math.subtTuples(wallPoint, r.origin));
			rays.intersect(s, r);
			intersection i = rays._hit();
			if (i.t > 0)
			{
				tup point = rays._position(r, i.t);
				tup normal = spheres._normal_at(i.object, point);
				tup eye = tups._invert(r.direction);
				c.write_pixel(spheres.lighting(i.object.materials, point, pl,eye, normal), x, y);
				//c.write_pixel(col.createColor(1, 0.2, 1), x, y);
				rays._clear();
			}
			
		}
	}
	c.write_to_ppm();
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

