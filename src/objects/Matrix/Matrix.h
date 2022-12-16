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


template<typename type, std::size_t row_count, std::size_t column_count>
class Matrix{
public:
  type data[row_count][column_count];

  Matrix(bool identity = false){
    if(identity){
      ToIdentity();
    }
  }

  void Blank(){
    memset(data, 0, sizeof(type)*row_count*column_count);
  }

  void ToIdentity(){
    Blank();
    for(std::size_t i = 0; i < row_count; i++){
      data[i][i] = 1.0;
    }
  }

  template<std::size_t row_count_sub, std::size_t column_count_sub>
  Matrix<type, row_count_sub, column_count_sub> Submatrix(){
    // Check if we are trying to create a sub-matrix of the same size as the current one.
    if(row_count_sub == row_count && colum_count_sub == colum_count){
      return this;
    }

    Matrix<type, row_count_sub, colum_count_sub> subMatrix;
    for(std::size_t row = 0; row < row_count_sub; row++){
      for(std::size_t column = 0; column < column_count_sub; column++){
        subMatrix[row][column] = data[row][column];
      }
    }

    return subMatrix;
  }


  float Minor(const Matrix<type, row_count, column_count>& mat, const int r, const int c){
    auto subMat = Submatrix<r, c>();

    // Idk probably do something math-y here.
  }

  Matrix<type, row_count, colum_count> Inverse(){
    // Should probably check if it can be inverted first...

    float co = 0.0f;
    Matrix<type, row_count, colum_count> inverseMatrix;
    for(std::size_t i = 0; i < row_count; i++){
      for(std::size_t j = 0; j < colum_count; j++){
        co = Cofactor(i, j);
      }
    }
  }

  tup xtup(const tup &t){
    tup p;
    p.x = ((m.matrices[0][0] * t.x) + (m.matrices[0][1] * t.y) + (m.matrices[0][2] * t.z) + (m.matrices[0][3] * t.w));
    p.y = ((m.matrices[1][0] * t.x) + (m.matrices[1][1] * t.y) + (m.matrices[1][2] * t.z) + (m.matrices[1][3] * t.w));
    p.z = ((m.matrices[2][0] * t.x) + (m.matrices[2][1] * t.y) + (m.matrices[2][2] * t.z) + (m.matrices[2][3] * t.w));
    p.w = ((m.matrices[3][0] * t.x) + (m.matrices[3][1] * t.y) + (m.matrices[3][2] * t.z) + (m.matrices[3][3] * t.w));

    return p;
  }

  static const Matrix<type, row_count, colum_count> Identity = Matrix<type, row_count, colum_count>(true);
private:

};

typedef Matrix<float, 3, 3> Matrix_3x3;
typedef Matrix<float, 4, 4> Matrix_4x4;

#define EPSILON_F 0.00001f
inline bool operator==(const Matrix_4x4 &lhs, const Matrix_4x4 &rhs){
  for(std::size_t i = 0; i < 4*4; i++){
    if(std::abs(((float*)lhs.data)[i]) - std::abs(((float*)rhs.data)[i]) > EPSILON_F){
      return false;
    }
  }

  return true;
}

inline bool operator!=(const Matrix_4x4 &lhs, const Matrix_4x4 &rhs){
  return !(lhs == rhs);
}