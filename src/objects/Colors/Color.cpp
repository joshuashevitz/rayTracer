#include "Color.h"

color Color::createColor(float red, float blue, float green)
{
	color col;
	col.red = red;
	col.blue = blue;
	col.green = green;
	return col;
}

color Color::colorAddition(const color& c1, const color& c2)
{
	return createColor((c1.blue + c2.blue), (c1.red + c2.red), (c1.green + c2.green));
}

color Color::colorSubtraction(const color& c1, const color& c2)
{
	return createColor((c1.blue - c2.blue), (c1.red - c2.red), (c1.green - c2.green));
}

color Color::colorScalMul(const color& col, const float& m)
{
	return createColor((col.blue * m), (col.red * m), (col.green * m));
}
color Color::colorMult(const color& c1, const color& c2)
{
	return createColor((c1.blue * c2.blue), (c1.red * c2.red), (c1.green * c2.green));
}

