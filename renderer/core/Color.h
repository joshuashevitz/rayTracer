#pragma once

struct color
{
	float red;
	float blue;
	float green;
};

class Color
{
public: 
	Color() {};
	~Color() = default;
	color createColor(float red, float blue, float green);
	color colorAddition(const color& a,const color& b);
	color colorSubtraction(const color& a,const color& b);
	color colorScalMul(const color& col,const float& m);
	color colorMult(const color& c1, const color& c2);
};