#pragma once

#include <iostream>
#include "tuples.h"
#include "simpleMath.h"

struct ray
{
	tup origin; 
	tup direction;
};

class Rays
{
public: 
	Rays(const tup& origin, const tup& direction) { 
		_init_ray(origin,direction); 
	};
	~Rays() = default;

	void _init_ray(const tup& origin, const tup& direction);
	ray _get_ray()
	{
		return R;
	};
	tup _position(const ray& r, const float& t);
	void _clear();
private:
	Tuples tups;  
	ray R;
	TupleMath math;

};