#pragma once

#include <iostream>

struct sphere
{
	uint64_t sid;
};

class Sphere
{
public: 
	Sphere() {};
	~Sphere() = default;

private:
	sphere s;
};