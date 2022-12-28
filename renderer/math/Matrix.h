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


//////////////////////////////////////////////////////////////////////////
// New Matrix class and functionality to replace previous implementation 
//////////////////////////////////////////////////////////////////////////
template<typename type, std::size_t row_count, std::size_t column_count>
class Matrix {
public:
    type data[row_count][column_count];

    Matrix(bool identity = true) {
        if (identity) {
            ToIdentity();
        }
    }

    void Blank() {
        memset(data, 0, sizeof(type) * row_count * column_count);
    }

    void ToIdentity() {
        Blank();
        for (std::size_t i = 0; i < row_count; i++) {
            data[i][i] = 1.0;
        }
    }

 
    Matrix<type, row_count-1, column_count-1> Submatrix( Matrix<float, row_count, column_count>& m, size_t r, size_t c) {
        // Check if we are trying to create a sub-matrix of the same size as the current one.

        for (size_t ro = 0; ro < m.GetRow(); ro++)
        {
            for (size_t co = 0; co < m.GetCol(); co++)
            {
                std::cout << m.data[ro][co] << " ";
            }
            std::cout << std::endl;
        }

        std::size_t row = m.GetRow() - 1, col = m.GetCol() - 1;
        Matrix<float, row_count - 1, column_count - 1> subMatrix;

        if (row_count-1 == row_count && column_count-1 == column_count) {
            return subMatrix;
        }
        std::size_t currentr = 0.0f, currentc = 0.0f;
        for (std::size_t rows = 0; rows < row; rows++) {
            if (rows != r)
            {
                
                for (std::size_t column = 0; column < col; column++) {
                    if (column != c)
                    {
                        subMatrix.data[currentr][currentc] = m.data[row][column];
                        //std::cout << data[row][column] << std::endl;
                        currentc++;
                    }
                }
                currentr++;
            }
            
        }

        return subMatrix;
    }

    void add_translation(const float& x, const float y, const float z)
    {
        ToIdentity();
        data[0][3] = x;
        data[1][3] = y;
        data[2][3] = z;
    }

    void add_scaler(const float& x, const float& y, const float& z)
    {
        ToIdentity();
        data[0][0] = x;
        data[1][1] = y;
        data[2][2] = z;
    }
    void add_rotationZ(const float& r)
    {
        ToIdentity();
        data[0][0] = cos(r);
        data[1][0] = sin(r);
        data[1][1] = cos(r);
        data[0][1] = -(sin(r));
    }

    void add_rotationX(const float& r)
    {
        ToIdentity();
        data[0][0] = cos(r);
        data[1][0] = -(sin(r));
        data[1][1] = cos(r);
        data[0][1] = sin(r);
    }

    float Determinant(const Matrix<type, row_count, column_count>& mat)
    {
        float det = 0.0f;
        if(mat.GetRow() > 2 || mat.GetCol() > 2)
        {
            for(std::size_t col = 0; col < mat.GetCol(); col++)
            {
                det = det + (mat.data[0][col] * Cofactor(mat, 0, col));
            }
            return det;
        }
        return ((data[0][0] * data[1][1]) - (data[0][1] * data[1][0]));
    }

    float Cofactor(const Matrix<type, row_count, column_count>& m, const int r, const int c)
    {
        float result = Minor(m, r, c);
        if (((c + r) % 2) == 0)
        {
            return result;
        }
        else {
            return result * -1;
        }
    }

    float Minor(const Matrix<type, row_count, column_count>& mat, const int r, const int c) 
    {


        if (mat.GetRow() == 2)
        {
            return Determinant(mat);
        }
        auto subMat = Submatrix(r,c);
        return Determinant(subMat);
        // Idk probably do something math-y here.
    }

    Matrix<type, row_count, column_count> Inverse(const Matrix<type, row_count, column_count>& m) {
        // Should probably check if it can be inverted first...

        float co = 0.0f;
        Matrix<type, row_count, column_count> inverseMatrix;
        for (std::size_t i = 0; i < m.GetRow(); i++) {
            for (std::size_t j = 0; j < m.GetCol(); j++) {
                co = Cofactor(m, i, j);
                inverseMatrix.data[j][i] = (co/Determinant(m));
            }
        }
        return inverseMatrix;
    }

    tup xtup(const tup& t) {
        tup p;
        p.x = ((data[0][0] * t.x) + (data[0][1] * t.y) + (data[0][2] * t.z) + (data[0][3] * t.w));
        p.y = ((data[1][0] * t.x) + (data[1][1] * t.y) + (data[1][2] * t.z) + (data[1][3] * t.w));
        p.z = ((data[2][0] * t.x) + (data[2][1] * t.y) + (data[2][2] * t.z) + (data[2][3] * t.w));
        p.w = ((data[3][0] * t.x) + (data[3][1] * t.y) + (data[3][2] * t.z) + (data[3][3] * t.w));

        return p;
    }
    Matrix xMatrix(const Matrix& A, const Matrix& B)
    {
        Matrix<float, 4, 4> newMatrix;
        for (std::size_t i = 0; i < row_count; i++)
        {
            for (std::size_t j = 0; j < column_count; j++)
            {
                newMatrix.data[i][j] = ((A.data[i][0] * B.data[0][j]) +
                    (A.data[i][1] * B.data[1][j]) +
                    (A.data[i][2] * B.data[2][j]) +
                    (A.data[i][3] * B.data[3][j]));
            }
        }
        return newMatrix;
    }

    size_t GetRow()
    {
        return row_count;
    }
    size_t GetCol()
    {
        return column_count;
    }

    static const Matrix<type, row_count, column_count> Identity;
};

typedef Matrix<float, 2u, 2u> Matrix_2x2;
typedef Matrix<float, 3u, 3u> Matrix_3x3;
typedef Matrix<float, 4u, 4u> Matrix_4x4;

#define EPSILON_F 0.00001f
inline bool operator==(const Matrix_4x4& lhs, const Matrix_4x4& rhs) {
    for (std::size_t i = 0; i < 4 * 4; i++) {
        if (std::abs(((float*)lhs.data)[i]) - std::abs(((float*)rhs.data)[i]) > EPSILON_F) {
            return false;
        }
    }

    return true;
}

inline bool operator!=(const Matrix_4x4& lhs, const Matrix_4x4& rhs) {
    return !(lhs == rhs);
}