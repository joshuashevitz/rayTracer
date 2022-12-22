#pragma once

#include "math/tuples.h"

#include <vector>

struct matrix
{
	int rows;
	int columns;
	std::vector<std::vector<float>> matrices;
};

class MatrixOps
{
public:
	MatrixOps() { _fill_identity(); };
	~MatrixOps() = default;
	void create(const int& rows, const int& col);
	void _print(const matrix& m);
	void _fill_identity();
	void _clear();
	bool _compare(const matrix& a, const matrix& b);
	bool _invertible(const matrix& m);
	float _2d_determinant(const matrix& m);
	float _minor(const matrix& m, const int& r, const int& c);
	float _cofactor(const matrix& m, const int& r, const int& c);
	matrix _submatrix(const matrix& m, int r, int c);
	matrix _create(const int& rows, const int& col);
	matrix add_to_matrix(const float& x, const int& row, const int& col);
	matrix _add_translation(const tup& t);
	matrix _add_rotation_x(const double& r);
	matrix _add_rotation_y(const double& r);
	matrix _add_rotation_z(const double& r);
	matrix populate_matrix(const std::vector<float>& vec);
	matrix _mat_multiplier(const matrix& A, const matrix& B);
	matrix _transpose(const matrix& m);
	matrix _inverse(const matrix& m);
	matrix _add_scaling(const float& x, const float& y, const float& z);
	matrix _add_shear(const float& x1, const float& x2, const float& y1, const float& y2, const float& z1, const float& z2);
	tup _translation(const tup& orig, const tup& t);
	tup _inverse_translation(const tup& orig, const tup& vec);
	tup _inverse_scaling(const tup& orig, const tup& vec);
	tup _scaling(const tup& t, const tup& vec);
	tup _rotate_x(const tup& t,const double& rads);
	tup _rotate_y(const tup& t, const double& rads);
	tup _rotate_z(const tup& t, const double& rads);
	tup _shearing(const tup& t, const float& x1, const float& x2, const float& y1, const float& y2, const float& z1, const float& z2);
	tup _matxtup(const matrix& m, const tup& t);

	matrix _get_identity()
	{
		return identity;
	}
	double _get_pi()
	{
		return pi;
	}
private:
	matrix mat;
	matrix identity;
	Tuples tups;
	double pi = 2 * asin(1.0);
};