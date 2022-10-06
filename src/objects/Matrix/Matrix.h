#pragma once

#include <vector>
#include <iostream>
#include "tuples.h"

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
	tup _matxtup(const matrix& m, const tup& t);
	matrix _submatrix(const matrix& m, int r, int c);
	matrix _create(const int& rows, const int& col);
	matrix add_to_matrix(const float& x, const int& row, const int& col);
	matrix populate_matrix(const std::vector<float>& vec);
	matrix _mat_multiplier(const matrix& A, const matrix& B);
	matrix _transpose(const matrix& m);
	matrix _inverse(const matrix& m);
	matrix _get_identity()
	{
		return identity;
	}
private:
	matrix mat;
	matrix identity;
};