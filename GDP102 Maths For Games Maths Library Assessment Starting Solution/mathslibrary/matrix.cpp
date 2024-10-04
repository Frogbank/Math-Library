#include "matrix.h"
#include <cmath>

// Matrix2:

Matrix2::Matrix2()
{
	m1 = 0;
	m2 = 0;
	m3 = 0;
	m4 = 0;
}

Matrix2::Matrix2(float _00, float _01, float _10, float _11)
{
	data[0][0] = _00;
	data[0][1] = _01;
	data[1][0] = _10;
	data[1][1] = _11;
}

Matrix2::Matrix2(const Matrix2& other)
{
	m1 = other.m1;
	m2 = other.m2;
	m3 = other.m3;
	m4 = other.m4;
}

Matrix2& Matrix2::operator = (const Matrix2& other)
{
	m1 = other.m1;
	m2 = other.m2;
	m3 = other.m3;
	m4 = other.m4;
	return *this;
}

// Indexing operators to retrieve columns
Vector2& Matrix2::operator[] (int index)
{
	return axis[index];
}

// Indexing operators to retrieve columns
const Vector2& Matrix2::operator[] (int index) const
{
	return axis[index];
}

Matrix2 Matrix2::operator * (const Matrix2& other) const
{
	Matrix2 result;
	for (int row = 0; row < 2; ++row) 
	{
		for (int column = 0; column < 2; ++column) 
		{
			for (int component = 0; component < 2; ++component)
			{
				result.data[column][row] += data[component][row] * other.data[column][component];
			}
		}
	}
	return result;
}

Vector2 Matrix2::operator * (const Vector2& v) const
{
	Vector2 result;
	for (int row = 0; row < 2; ++row)
	{
		for (int component = 0; component < 2; ++component)
		{
			result[row] += data[component][row] * v[component];
		}
	}
	return result;
}


void Matrix2::setIdentity()
{
	memset(this, 0, sizeof(float) * 4);
	for (int i = 0; i < 2; i++)
	{
		data[i][i] = 1;
	}
}

Matrix2 Matrix2::transposed() const
{
	Matrix2 result;
	for (int row = 0; row < 2; ++row)
	{
		for (int column = 0; column < 2; ++column)
		{
			result.data[row][column] = data[column][row];
		}
	}
	return result;
}

void Matrix2::setRotate(float radians)
{
	memset(this, 0, sizeof(float) * 4);
	data[0][0] = cosf(radians);
	data[1][0] = sinf(radians);
	data[0][1] = -sinf(radians);
	data[1][1] = cosf(radians);
}

void Matrix2::rotate(float radians)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (data[i][j] == 0)
			{
				data[i][j] = 1;
			}
		}
	}
	data[0][0] *= cosf(radians);
	data[1][0] *= sinf(radians);
	data[0][1] *= -sinf(radians);
	data[1][1] *= cosf(radians);
}

void Matrix2::setScaled(float x, float y)
{
	memset(this, 0, sizeof(float) * 4);
	data[0][0] = x;
	data[1][1] = y;
}

void Matrix2::setScaled(const Vector2& v)
{
	memset(this, 0, sizeof(float) * 4);
	data[0][0] = v.x;
	data[1][1] = v.y;
}

void Matrix2::scale(float x, float y)
{
	for (int i = 0; i < 2; i++)
	{
		xAxis[i] *= x;
	}
	for (int i = 0; i < 2; i++)
	{
		yAxis[i] *= y;
	}
}

void Matrix2::scale(const Vector2& v)
{
	for (int i = 0; i < 2; i++)
	{
		xAxis[i] *= v.x;
	}
	for (int i = 0; i < 2; i++)
	{
		yAxis[i] *= v.y;
	}
}

std::ostream& operator<<(std::ostream& os, const Matrix2& m)
{
	for (int row = 0; row < 2; row++)
	{
		for (int column = 0; column < 2; column++)
		{
			os << m.data[column][row] << ",";
		}
		os << std::endl;
	}

	return os;
}



// Matrix3:

Matrix3::Matrix3()
{
	for (int col = 0; col < 3; col++)
	{
		for (int row = 0; row < 3; row++)
		{
			data[col][row] = 0;
		}
	}
}
Matrix3::Matrix3(float _00, float _01, float _02, float _10, float _11, float _12, float _20, float _21, float _22)
{
	data[0][0] = _00;
	data[0][1] = _01;
	data[0][2] = _02;
	data[1][0] = _10;
	data[1][1] = _11;
	data[1][2] = _12;
	data[2][0] = _20;
	data[2][1] = _21;
	data[2][2] = _22;
}
Matrix3::Matrix3(const Matrix3& other)
{
	for (int col = 0; col < 3; col++)
	{
		for (int row = 0; row < 3; row++)
		{
			data[col][row] = other.data[col][row];
		}
	}
}

Matrix3& Matrix3::operator=(const Matrix3& other)
{
	for (int col = 0; col < 3; col++)
	{
		for (int row = 0; row < 3; row++)
		{
			data[col][row] = other.data[col][row];
		}
	}
	return *this;
}

Vector3& Matrix3::operator[](int index)
{
	return axis[index];
}

const Vector3& Matrix3::operator[](int index) const
{
	return axis[index];
}

Matrix3 Matrix3::operator * (const Matrix3& other) const
{
	Matrix3 result;
	Vector3 mult;
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			mult[k] = data[k][i];
		}
		for (int j = 0; j < 3; j++)
		{
			result.data[j][i] = mult.dot(other.axis[j]);
		}
	}

	return result;
}

Vector3 Matrix3::operator * (const Vector3& v) const
{
	Vector3 result(1, 1, 1);
	Vector3 mult;
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			mult[k] = data[k][i];
		}
		result[i] = mult.dot(v);
	}

	return result;
}



void Matrix3::setIdentity()
{
	memset(this, 0, sizeof(float) * 9);
	for (int i = 0; i < 3; i++)
	{
		data[i][i] = 1;
	}
}

Matrix3 Matrix3::transposed() const
{
	Matrix3 result;

	for (int col = 0; col < 3; col++)
	{
		for (int row = 0; row < 3; row++)
		{
			result.data[row][col] = data[col][row];
		}
	}
	return result;
}

void Matrix3::setTranslate(float x, float y)
{
	translation = { x, y, 0 };
}

void Matrix3::setTranslate(const Vector2& other)
{
	translation = { other.x, other.y, 0 };
}

void Matrix3::translate(float x, float y)
{
	translation = { translation.x += x, translation.y += y, translation.z};
}

void Matrix3::translate(const Vector2& other)
{
	translation = { translation.x += other.x, translation.y += other.y, translation.z };

}

void Matrix3::setEuler(float pitch, float yaw, float roll) 
{
	setRotateZ(roll);
	rotateY(yaw);
	rotateX(pitch);
}

void Matrix3::setRotateX(float radians)
{
	xAxis = { 1, 0, 0 };
	yAxis = { 0, cosf(radians), -sinf(radians) };
	zAxis = { 0, sinf(radians), cosf(radians) };
}

void Matrix3::rotateX(float radians)
{
	Matrix3 m;
	m.setRotateX(radians);
	*this = *this * m;
}

void Matrix3::setRotateY(float radians)
{
	xAxis = { cosf(radians), 0, sinf(radians)};
	yAxis = { 0, 1, 0};
	zAxis = { -sinf(radians), 0, cosf(radians)};
}

void Matrix3::rotateY(float radians)
{
	Matrix3 m;
	m.setRotateY(radians);
	*this = *this * m;
}

void Matrix3::setRotateZ(float radians)
{
	xAxis = { cosf(radians), -sinf(radians), 0};
	yAxis = { sinf(radians), cosf(radians), 0};
	zAxis = { 0, 0, 1};
}

void Matrix3::rotateZ(float radians)
{
	Matrix3 m;
	m.setRotateZ(radians);
	*this = *this * m;
}

void Matrix3::setScaled(float x, float y, float z)
{
	xAxis = { x, 0, 0 };
	yAxis = { 0, y, 0 };
	zAxis = { 0, 0, z };
}

void Matrix3::setScaled(const Vector3& v)
{
	xAxis = { v.x, 0, 0 };
	yAxis = { 0, v.y, 0 };
	zAxis = { 0, 0, v.z };
}

void Matrix3::scale(float x, float y, float z)
{
	Matrix3 m;
	m.setScaled(x, y, z);
	*this = *this * m;
}

void Matrix3::scale(const Vector3& v)
{
	Matrix3 m;
	m.setScaled(v);
	*this = *this * m;
}

std::ostream& operator<<(std::ostream& os, const Matrix3& m)
{
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			os << m.data[column][row] << ",";
		}
		os << std::endl;
	}

	return os;
}




// Matrix4:



Matrix4::Matrix4()
{
	for (int col = 0; col < 4; col++)
	{
		for (int row = 0; row < 4; row++)
		{
			data[col][row] = 0;
		}
	}
}
Matrix4::Matrix4(float _00, float _01, float _02, float _03, float _10, float _11, float _12, float _13, float _20, float _21, float _22, float _23, float _30, float _31, float _32, float _33)
{
	data[0][0] = _00;
	data[0][1] = _01;
	data[0][2] = _02;
	data[0][3] = _03;
	data[1][0] = _10;
	data[1][1] = _11;
	data[1][2] = _12;
	data[1][3] = _13;
	data[2][0] = _20;
	data[2][1] = _21;
	data[2][2] = _22;
	data[2][3] = _23;
	data[3][0] = _30;
	data[3][1] = _31;
	data[3][2] = _32;
	data[3][3] = _33;
}


Matrix4::Matrix4(const Matrix4& other)
{
	for (int col = 0; col < 4; col++)
	{
		for (int row = 0; row < 4; row++)
		{
			data[col][row] = other.data[col][row];
		}
	}
}

Matrix4& Matrix4::operator = (const Matrix4& other)
{
	for (int col = 0; col < 4; col++)
	{
		for (int row = 0; row < 4; row++)
		{
			data[col][row] = other.data[col][row];
		}
	}
	return *this;
}

Vector4& Matrix4::operator[](int index)
{
	return axis[index];
}

const Vector4& Matrix4::operator[](int index) const
{
	return axis[index];
}


Matrix4 Matrix4::operator * (const Matrix4& other) const
{
	Matrix4 result;
	Vector4 mult;
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			mult[k] = data[k][i];
		}
		for (int j = 0; j < 4; j++)
		{
			result.data[j][i] = mult.dot(other.axis[j]);
		}
	}

	return result;
}

Vector4 Matrix4::operator * (const Vector4& v) const
{
	Vector4 result;
	Vector4 mult;
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			mult[k] = data[k][i];
		}
		result[i] = mult.dot(v);
	}
	return result;
}

void Matrix4::setIdentity()
{
	memset(this, 0, sizeof(float) * 16);
	for (int i = 0; i < 4; i++)
	{
		data[i][i] = 1;
	}
}

Matrix4 Matrix4::transposed() const
{
	Matrix4 result;

	for (int col = 0; col < 4; col++)
	{
		for (int row = 0; row < 4; row++)
		{
			result.data[row][col] = data[col][row];
		}
	}
	return result;
}

void Matrix4::setTranslate(float x, float y, float z)
{
	translation = { x, y, z, translation.w };
}

void Matrix4::setTranslate(const Vector3& other)
{
	translation = { other.x, other.y, other.z, translation.w };
}

void Matrix4::translate(float x, float y, float z)
{
	translation = { translation.x += x, translation.y += y, translation.z += z, translation.w };
}

void Matrix4::translate(const Vector3& other)
{
	translation = { translation.x += other.x, translation.y += other.y, translation.z += other.z, translation.w };
}

void Matrix4::setEuler(float pitch, float yaw, float roll)
{
	setRotateZ(roll);
	rotateY(yaw);
	rotateX(pitch);
}

void Matrix4::setRotateX(float radians)
{
	xAxis = { 1, 0, 0, 0 };
	yAxis = { 0, cosf(radians), -sinf(radians), 0 };
	zAxis = { 0, sinf(radians), cosf(radians), 0 };
	translation = { 0, 0, 0, 1 };
}

void Matrix4::rotateX(float radians)
{
	Matrix4 m;
	m.setRotateX(radians);
	*this = *this * m;
}


void Matrix4::setRotateY(float radians)
{
	xAxis = { cosf(radians), 0, sinf(radians), 0 };
	yAxis = { 0, 1, 0, 0 };
	zAxis = { -sinf(radians), 0, cosf(radians), 0 };
	translation = { 0, 0, 0, 1 };
}

void Matrix4::rotateY(float radians)
{
	Matrix4 m;
	m.setRotateY(radians);
	*this = *this * m;
}

void Matrix4::setRotateZ(float radians)
{
	xAxis = { cosf(radians), -sinf(radians), 0, 0 };
	yAxis = { sinf(radians), cosf(radians), 0, 0 };
	zAxis = { 0, 0, 1, 0 };
	translation = { 0, 0, 0, 1 };
}

void Matrix4::rotateZ(float radians)
{
	Matrix4 m;
	m.setRotateZ(radians);
	*this = *this * m;
}

void Matrix4::setScaled(float x, float y, float z)
{
	xAxis = { x, 0, 0, translation.x };
	yAxis = { 0, y, 0, translation.y };
	zAxis = { 0, 0, z, translation.z };
}

void Matrix4::setScaled(const Vector3& v)
{
	xAxis = { v.x, 0, 0, translation.x };
	yAxis = { 0, v.y, 0, translation.y };
	zAxis = { 0, 0, v.z, translation.z };
}

void Matrix4::scale(float x, float y, float z)
{
	Matrix4 m;
	Vector4 temp;
	temp = this->translation;
	m.setScaled(x, y, z);
	*this = *this * m;
	this->translation = temp;
}

void Matrix4::scale(const Vector3& v)
{
	Matrix4 m;
	Vector4 temp;
	temp = this->translation;
	m.setScaled(v);
	*this = *this * m;
	this->translation = temp;
}

std::ostream& operator<<(std::ostream& os, const Matrix4& m)
{
	for (int row = 0; row < 4; row++)
	{
		for (int column = 0; column < 4; column++)
		{
			os << m.data[column][row] << ",";
		}
		os << std::endl;
	}

	return os;
}