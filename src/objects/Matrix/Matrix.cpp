#include "Matrix.h"

void MatrixOps::create(const int& rows, const int& col) 
{
	mat.rows = rows;
	mat.columns = col;
	std::vector<float> v(col, 0);
	for (int h = 0; h <= rows; h++)
	{
		mat.matrices.resize(h, v);
	}
}

matrix MatrixOps::_create(const int& rows, const int& col)
{
	mat.rows = rows;
	mat.columns = col;
	std::vector<float> v(col, 0);
	for (int h = 0; h <= rows; h++)
	{
		mat.matrices.resize(h, v);
	}
	return mat;
}

void MatrixOps::_clear()
{
	mat.matrices.clear();
	if (mat.matrices.size() != 0)
	{
		std::cout << "mat was not cleared" << std::endl;
	}
}

matrix MatrixOps::add_to_matrix(const float& x, const int& row, const int& col)
{
	mat.matrices[col][row] = x;
	return mat;
}

matrix MatrixOps::populate_matrix(const std::vector<float>& numbers)
{
	int placeholder = 0;
		for (int i = 0; i <= mat.columns-1;i++)
		{
			for (int j = 0; j <= mat.rows-1; j++)
			{
				add_to_matrix(numbers[placeholder], j, i);
				placeholder += 1;
			}
		}

		return mat;
}

matrix MatrixOps::_add_translation(const tup& t)
{
	_clear();
	mat = identity;
	mat.matrices[0][3] = t.x;
	mat.matrices[1][3] = t.y;
	mat.matrices[2][3] = t.z;
	return mat;
}

matrix MatrixOps::_add_shear(const float& x1, const float& x2, const float& y1, const float& y2, const float& z1, const float& z2)
{
	_clear();
	mat = identity;
	mat.matrices[0][1] = x1;
	mat.matrices[0][2] = x2;
	mat.matrices[1][0] = y1;
	mat.matrices[1][2] = y2;
	mat.matrices[2][0] = z1;
	mat.matrices[2][1] = z2;
	return mat;
}

bool MatrixOps::_compare(const matrix& a, const matrix& b)
{
	float EPSILON = 0.00001;
	if(a.matrices.size() == 0 || b.matrices.size() == 0)
	{
		std::cout << "one or both matrices is empty. Try again after filling matrix! " << std::endl;
		return false;
	}
	for (int i = 0; i <= a.rows-1; i++) {
		for (int j = 0; j <= a.columns-1; j++)
		{
			if (abs(a.matrices[i][j]) -  abs(b.matrices[i][j]) > EPSILON) {
				std::cout << abs(a.matrices[i][j]) - abs(b.matrices[i][j]) << "is greater than: " << EPSILON << std::endl;
				return false;
			}			
		}
	}
	return true;
}

matrix MatrixOps::_mat_multiplier(const matrix& A, const matrix& B)
{
	_clear();
	create(A.rows, B.columns);
	for (int i = 0; i <= A.rows - 1; i++)
	{
		for (int j = 0; j <= B.columns - 1; j++)
		{
			mat.matrices[i][j] = ((A.matrices[i][0] * B.matrices[0][j]) +
								  (A.matrices[i][1] * B.matrices[1][j]) + 
								  (A.matrices[i][2] * B.matrices[2][j]) +
								  (A.matrices[i][3] * B.matrices[3][j]));
		}
	}
	return mat;
}

matrix MatrixOps::_transpose(const matrix& m)
{
	_clear();
	create(m.rows, m.columns);
	for (int i = 0; i <= m.rows - 1; i++)
	{
		mat.matrices[0][i] = m.matrices[i][0];
		mat.matrices[1][i] = m.matrices[i][1];
		mat.matrices[2][i] = m.matrices[i][2];
		mat.matrices[3][i] = m.matrices[i][3];
	}
	return mat;
}

float MatrixOps::_2d_determinant(const matrix& m)
{
	float det = 0;
	if (m.rows > 2 || m.columns > 2)
	{
		for (int col = 0; col <= m.columns - 1; col++)
		{
			det = det + (m.matrices[0][col] * _cofactor(m, 0, col));
		}
		return det;
	}
	return ((m.matrices[0][0] * m.matrices[1][1]) - (m.matrices[0][1] * m.matrices[1][0]));
}

bool MatrixOps::_invertible(const matrix& m)
{
	if (_2d_determinant(m) == 0)
	{
		return false;
	}
	return true;
}
matrix MatrixOps::_inverse(const matrix& m)
{
	if (!_invertible(m))
	{
		std::cout << "matrix is not invertible: matrix determinant is 0 " << std::endl;
	}

	float co = 0;
	matrix m2 = _create(m.rows, m.columns);
	for (int i = 0; i <= m.rows - 1; i++)
	{
		for (int j = 0; j <= m.columns - 1; j++)
		{
			co = _cofactor(m, i, j);
			m2.matrices[j][i] = (co / _2d_determinant(m));
		}
	}
	return m2;
}


matrix MatrixOps::_submatrix(const matrix& m, int r, int c)
{
	_clear();
	std::vector<float> vec;
	if (m.rows <= 2)
	{
		std::cout << "can't find submatrix of 2x2 matrices" << std::endl;
		return mat;
	}
	create(m.rows-1, m.columns-1);
	for (int i = 0; i <= m.rows - 1; i++)
	{
		if (i != r)
		{
			for (int j = 0; j <= m.columns - 1; j++)
			{
				if (j != c) {
					vec.push_back( m.matrices[i][j]);
				}
			}
		}
	}
	populate_matrix(vec);
	return mat;
}

void MatrixOps::_fill_identity()
{
	identity.rows = 4;
	identity.columns = 4;
	std::vector<float> v(identity.columns, 0);
	for (int h = 0; h <= identity.rows; h++)
	{
		identity.matrices.resize(h, v);
	}
	identity.matrices[0][0] = 1;
	identity.matrices[1][1] = 1;
	identity.matrices[2][2] = 1;
	identity.matrices[3][3] = 1;
}

tup MatrixOps::_matxtup(const matrix& m, const tup& t)
{
	tup p;
	p.x = ((m.matrices[0][0] * t.x) + (m.matrices[0][1] * t.y) + (m.matrices[0][2] * t.z) + (m.matrices[0][3] * t.w));
	p.y = ((m.matrices[1][0] * t.x) + (m.matrices[1][1] * t.y) + (m.matrices[1][2] * t.z) + (m.matrices[1][3] * t.w));
	p.z = ((m.matrices[2][0] * t.x) + (m.matrices[2][1] * t.y) + (m.matrices[2][2] * t.z) + (m.matrices[2][3] * t.w));
	p.w = ((m.matrices[3][0] * t.x) + (m.matrices[3][1] * t.y) + (m.matrices[3][2] * t.z) + (m.matrices[3][3] * t.w));

	return p;
}

float MatrixOps::_minor(const matrix& m, const int& r, const int& c)
{
	if (m.rows == 2)
	{
		return _2d_determinant(m);
	}
	matrix sub = _submatrix(m, r, c);
	return _2d_determinant(sub);
}

float MatrixOps::_cofactor(const matrix& m, const int& r, const int& c)
{
	float result = _minor(m, r, c);
	if (((c+r) % 2) == 0)
	{
		return result;
	}
	else {
		return result * -1;
	}
}

tup MatrixOps::_translation(const tup& orig, const tup& vec)
{
	if (orig.w == 0)
	{
		return orig;
	}
	_clear();
	mat = _add_translation(vec);
	return _matxtup(mat, orig);
}

tup MatrixOps::_inverse_translation(const tup& orig, const tup& vec)
{
	if (orig.w == 0)
	{
		return orig;
	}
	
return _matxtup(_inverse(_add_translation(vec)), orig);
}

matrix MatrixOps::_add_scaling(const float& x, const float& y, const float& z)
{
	_clear();
	mat = identity;
	mat.matrices[0][0] = x;
	mat.matrices[1][1] = y;
	mat.matrices[2][2] = z;
	return mat;
}

matrix MatrixOps::_add_rotation_x(const double& r)
{
	_clear();
	mat = identity;
	mat.matrices[1][1] = cos(r);
	mat.matrices[1][2] = -(sin(r));
	mat.matrices[2][2] = cos(r);
	mat.matrices[2][1] = sin(r);
	return mat;
}

matrix MatrixOps::_add_rotation_y(const double& r)
{
	_clear();
	mat = identity;
	mat.matrices[0][0] = cos(r);
	mat.matrices[0][2] = sin(r);
	mat.matrices[2][2] = cos(r);
	mat.matrices[2][0] = -(sin(r));
	return mat;
}

matrix MatrixOps::_add_rotation_z(const double& r)
{
	_clear();
	mat = identity;
	mat.matrices[0][0] = cos(r);
	mat.matrices[1][0] = sin(r);
	mat.matrices[1][1] = cos(r);
	mat.matrices[0][1] = -(sin(r));
	return mat;
}



tup MatrixOps::_scaling(const tup& orig, const tup& vec)
{
	_clear();
	mat = identity;
	tup s = _matxtup(_add_scaling(vec.x, vec.y, vec.z), orig);
	return s;
}

tup MatrixOps::_inverse_scaling(const tup& orig, const tup& vec)
{
	mat = identity;
	tup s = _matxtup(_inverse(_add_scaling(vec.x, vec.y, vec.z)), orig);
	return s;
}

tup MatrixOps::_rotate_x(const tup& t, const double& rads)
{
	_add_rotation_x(rads);
	

	return _matxtup(mat, t);
}
tup MatrixOps::_rotate_y(const tup& t, const double& rads)
{
	_add_rotation_y(rads);


	return _matxtup(mat, t);
}
tup MatrixOps::_rotate_z(const tup& t, const double& rads)
{
	_add_rotation_z(rads);


	return _matxtup(mat, t);
}
tup MatrixOps::_shearing(const tup& t, const float& x1, const float& x2, const float& y1, const float& y2, const float& z1, const float& z2)
{
	return _matxtup(_add_shear(x1, x2, y1, y2, z1, z2), t);
}

void MatrixOps::_print(const matrix& m)
{
	for (const auto& x : m.matrices)
	{
		for (const auto& y : x)
		{
			std::cout << y << " | ";
		}
		std::cout << std::endl;
	}
}

