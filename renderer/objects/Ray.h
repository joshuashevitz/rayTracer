#pragma once

#include <math/tuples.h>
#include <math/simpleMath.h>
#include <math/Matrix.h>

#include <objects/Sphere.h>

#include <vector>

namespace Objects{
  template<typename T>
  class Ray{
  public:
    struct Hit{
      
    };

    Math::Tuple3<T> origin;
    Math::Tuple3<T> direction;

    Ray() = default;
    Ray(Math::Tuple3<T> origin, Math::Tuple3<T> direction): origin(origin), direction(direction){}

    bool Intersect(const sphere &s, Hit &hit){
      return false;
    }

  private:
  };
}

struct ray
{
	tup origin;
	tup direction;
};

struct intersection {
	float t;
	sphere object;
};

class Rays
{
public: 
	Rays() { 
		NULL_INTERSECTION.t = NULL; 
	};
	~Rays() = default;
	void _clear();
	ray _init_ray(const tup& origin, const tup& direction);
	ray _transform(const ray& r, const matrix& m);
	tup _position(const ray& r, const float& t);
	ray _get_ray()
	{
		return R;
	}
	std::vector<intersection> intersect(const sphere& s, const ray& r);
	std::vector<intersection> _get_inters() 
	{
		return inter;
	}
	intersection _init_intersection(const sphere& s, const float& r);
	intersection _hit();
	intersection _null()
	{
		return NULL_INTERSECTION;
	}
private:
	std::vector<intersection> inter;
	intersection NULL_INTERSECTION;
	MatrixOps mats;
	TupleMath math;
	Tuples tups; 
	Sphere S;
	ray R;
	
	
	
};

