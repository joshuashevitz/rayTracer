#pragma once

#include <iostream>

namespace Math{
  template<typename T>
  struct Tuple3{
    union{
      struct { T x, y, z; };
      struct { T r, g, b; };

      T data[3];
    };

    Tuple3() = default;
    Tuple3(T x, T y, T z): x(x), y(y), z(z){}

    Tuple3 Invert(){
      return Tuple3(x * -1, y * -1, z * -1);
    }

    Tuple3 operator+ (const Tuple3 &first) const{
      return Tuple3(x + first.x, y + first.y, z + first.z);
    }
  };

  template<typename T>
  std::ostream &operator<<(std::ostream &os, const Tuple3<T> &t){
    os << "{" << t.x << ", " << t.y << ", " << t.z << "}";
    return os;
  }

  typedef Tuple3<float> Vec3F;
  typedef Tuple3<double> Vec3D;


  template<typename T>
  struct Tuple4{
    union {
      struct { T x, y, z, w; };
      struct { T r, g, b, a; };

      T data[4];
    };

    Tuple4() = default;
    Tuple4(T x, T y, T z, T w): x(x), y(y), z(z), w(w){}

    Tuple4 Invert(){
      return Tuple4(x * -1, y * -1, z * -1, w * -1);
    }

    Tuple4 operator+ (const Tuple4 &first) const{
      return Tuple3(x + first.x, y + first.y, z + first.z, w + first.w);
    }
  };

  template<typename T>
  std::ostream &operator<<(std::ostream &os, const Tuple4<T> &t){
    os << "{" << t.x << ", " << t.y << ", " << t.z << ", " << t.w << "}";
    return os;
  }

  typedef Tuple4<float> Vec4F;
  typedef Tuple4<double> Vec4D;
}

struct tup {
	float x;
	float y;
	float z;
	float w;
};

class Tuples
{
public: 
	Tuples(){};
	
	~Tuples() = default;

	tup createTuplePoint(float x, float y, float z) 
	{
		tup p;
		p.x = x;
		p.y = y;
		p.z = z;
		p.w = 1.0;
		return p;
	}
	tup createTupleVector(float x, float y, float z)
	{
		tup p;
		p.x = x;
		p.y = y;
		p.z = z;
		p.w = 0.0;
		return p;
	}

	tup _invert(const tup& t)
	{
		return createTuplePoint((-1 * t.x), (-1 * t.y), (-1 * t.z));
	}

	void printTuple(const tup& a)
	{
		std::cout << a.x << "\t" << a.y << "\t" << a.z << "\t" << a.w << std::endl;
	}

private:
};