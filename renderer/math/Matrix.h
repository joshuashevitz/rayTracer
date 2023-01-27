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

    void Fill(const std::vector<float>& v)
    {
        int i = 0;
        for (size_t row = 0; row < row_count; row++)
        {
            for (size_t col = 0; col < column_count; col++)
            {
                data[row][col] = v[i];
                i++;
            }
        }
    }

    void add_shear(const float& x1, const float& x2, const float& y1, const float& y2, const float& z1, const float& z2)
    {
        ToIdentity();
        data[0][1] = x1;
        data[0][2] = x2;
        data[1][0] = y1;
        data[1][2] = y2;
        data[2][0] = z1;
        data[2][1] = z2;
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
        data[1][1] = cos(r);
        data[1][2] = -(sin(r));
        data[2][2] = cos(r);
        data[2][1] = sin(r);
    }
    void add_rotationY(const float& r)
    {
        ToIdentity();
        data[0][0] = cos(r);
        data[0][2] = sin(r);
        data[2][2] = cos(r);
        data[2][0] = -(sin(r));
    }

    tup RotateX(const tup& t, const double& rads)
    {
        add_rotationX(rads);
        return xtup(t);   
    }

    tup RotateY(const tup& t, const double& rads)
    {
        add_rotationY(rads);
        return xtup(t);
    }

    tup RotateZ(const tup& t, const double& rads)
    {
        add_rotationZ(rads);
        return xtup(t);
    }

    Matrix<type, row_count, column_count> Transpose()
    {
        Matrix<float, 4, 4> mat;

        for (std::size_t i = 0; i < row_count; i++)
        {
            mat.data[0][i] = data[i][0];
            mat.data[1][i] = data[i][1];
            mat.data[2][i] = data[i][2];
            mat.data[3][i] = data[i][3];
        }
        return mat;
    }

    Matrix<type, row_count, column_count> Inverse(Matrix<type, row_count, column_count>& m) {
        // Should probably check if it can be inverted first...

        float co = 0.0f;
        Matrix <float, 4, 4> inverseMatrix;
        for (std::size_t i = 0; i < row_count; i++) {
            for (std::size_t j = 0; j < column_count; j++) {
                co = Cofactor(m, i, j);
                inverseMatrix.data[j][i] = (co/Determinant(m));
            }
        }
        return inverseMatrix;
    }

    void Invert_self()
    {
        Matrix < type, row_count, column_count > m;
        float co = 0.0f;
        for (std::size_t i = 0; i < row_count; i++) {
            for (std::size_t j = 0; j < column_count; j++) {
                m.data[i][j] = data[i][j];
                co = Cofactor(m, i, j);
                data[j][i] = (co / Determinant(m));
            }
        }
    }

    tup Scale(const tup& orig, const tup& vec)
    {
        add_scaler(vec.x, vec.y, vec.z);
        return xtup(orig);
    }

    tup xtup(const tup& t) {
        tup p;
        p.x = ((data[0][0] * t.x) + (data[0][1] * t.y) + (data[0][2] * t.z) + (data[0][3] * t.w));
        p.y = ((data[1][0] * t.x) + (data[1][1] * t.y) + (data[1][2] * t.z) + (data[1][3] * t.w));
        p.z = ((data[2][0] * t.x) + (data[2][1] * t.y) + (data[2][2] * t.z) + (data[2][3] * t.w));
        p.w = ((data[3][0] * t.x) + (data[3][1] * t.y) + (data[3][2] * t.z) + (data[3][3] * t.w));

        return p;
    }
    Matrix xMatrix(const Matrix<type,row_count, column_count>& A, const Matrix<type, row_count, column_count>& B)
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

    tup Translation(const tup& orig, const tup& vec)
    {
        if (orig.w == 0)
        {
            std::cout << "Given a vector as an origin; Must be a Point. " << std::endl;
            return orig;
        }
        add_translation(vec.x, vec.y, vec.z);    
        return xtup(orig);
    }

    tup InverseTranslation(const tup& orig, const tup& vec)
    {
        if (orig.w == 0)
        {
            std::cout << "Given a vector as an origin; Must be a Point. " << std::endl;
            return orig;
        }
        add_translation(vec.x, vec.y, vec.z);
        Invert_self();
        return xtup(orig);
    }
    
    tup InverseScaling(const tup& orig, const tup& vec)
    {
        add_scaler(vec.x, vec.y, vec.z);
        Invert_self();
        return xtup(orig);
    }
    
    tup Shear(const tup& t, const float& x1, const float& x2, const float& y1, const float& y2, const float& z1, const float& z2)
    {
        add_shear(x1, x2, y1, y2, z1, z2);
        return xtup(t);
    }

    size_t GetRow()
    {
        return row_count;
    }
    size_t GetCol()
    {
        return column_count;
    }

    void PrintMatrix() {

        for (std::size_t i = 0; i < row_count; i++)
        {
            for (std::size_t j = 0; j < column_count; j++)
            {
                std::cout << data[i][j] << " | ";
            }
            std::cout << std::endl;
        }
    }

    static const Matrix<type, row_count, column_count> Identity;
};

typedef Matrix<float, 2u, 2u> Matrix_2x2;
typedef Matrix<float, 3u, 3u> Matrix_3x3;
typedef Matrix<float, 4u, 4u> Matrix_4x4;

template<std::size_t row, std::size_t col> 
Matrix<float, row-1, col-1> Submatrix(Matrix<float, row, col>& mat, int r, int c)
{
    Matrix<float, row - 1, col - 1> sub;
    std::size_t crow=0, ccol=0;
    for (std::size_t i = 0; i < row; i++)
    {
        if (i != r) {
            for (std::size_t j = 0; j < col; j++)
            {
                if (j != c)
                {
                    sub.data[crow][ccol] = mat.data[i][j];
                    ccol++;
                }
            }
            ccol = 0;
            crow++;
        }
    }
    return sub;
}

template<std::size_t row, std::size_t col>
float Determinant(Matrix<float, row, col>& mat)
{
    float det = 0.0f;
    if (row > 2 || col > 2)
    {
        for (std::size_t c = 0; c < col; c++)
        {
            det = det + (mat.data[0][c] * Cofactor<row, col>(mat, 0, c));
        }
        return det;
    }
    return ((mat.data[0][0] * mat.data[1][1]) - (mat.data[0][1] * mat.data[1][0]));
}

template<std::size_t row, std::size_t col>
float Minor(Matrix<float, row, col>& mat, int r, int c)
{
  /*  if (col < 3)
    {
        return Determinant<row, col>(mat);
    }*/
    Matrix<float, row, col> m = mat;
    if (row == 4)
    {
        

        Matrix_3x3 subMat;
        std::size_t crow = 0, ccol = 0;
        for (std::size_t i = 0; i < row; i++)
        {
            if (i != r) {
                for (std::size_t j = 0; j < col; j++)
                {
                    if (j != c)
                    {
                        subMat.data[crow][ccol] = m.data[i][j];
                        ccol++;
                    }
                }
                ccol = 0;
                crow++;
            }
        }
        return Determinant<3, 3>(subMat);
    }    
    if (row == 3)
    {

        Matrix_2x2 subMat;
        std::size_t crow = 0, ccol = 0;
            for (std::size_t i = 0; i < row; i++)
            {
                if (i != r) {
                    for (std::size_t j = 0; j < col; j++)
                    {
                        if (j != c)
                        {
                            subMat.data[crow][ccol] = m.data[i][j];
                            ccol++;
                        }
                    }
                    ccol = 0;
                    crow++;
                }
            }
        return Determinant<2, 2>(subMat);
    }
    else {
        return 0.0f;
    }
   // Matrix<float,row-1,col-1> subMat = Submatrix<row, col>(mat, r, c);
    
    //return Determinant<row, col>(subMat);
    //return Determinant<row - 1, col - 1>(mat);
    // Idk probably do something math-y here.
}

template<std::size_t row, std::size_t col>
float Cofactor(Matrix<float, row, col>& m, int r, int c)
{
    float result = Minor<row, col>(m, r, c);
    if (((c + r) % 2) == 0)
    {
        return result;
    }
    else {
        return result * -1;
    }
}

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

inline bool operator==(const Matrix_3x3& lhs, const Matrix_3x3& rhs) {
    for (std::size_t i = 0; i < 3 * 3; i++) {
        if (std::abs(((float*)lhs.data)[i]) - std::abs(((float*)rhs.data)[i]) > EPSILON_F) {
            return false;
        }
    }

    return true;
}

inline bool operator!=(const Matrix_3x3& lhs, const Matrix_3x3& rhs) {
    return !(lhs == rhs);
}