#include "vector.h"
#include <cmath>

// Vector 2:

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(float a, float b)
{
	x = a;
	y = b;
}

Vector2::Vector2(const Vector2& other)
{
	x = other.x;
	y = other.y;
}

float Vector2::operator [] (int index) const
{
	return data[index];
}

float& Vector2::operator [] (int index)
{

	return data[index];
}

Vector2& Vector2::operator = (const Vector2& other)
{
	x = other.x;
	y = other.y;
	return *this;
}

Vector2 Vector2::operator + (const Vector2& other) const
{
	return { x + other.x, y + other.y };
}

Vector2& Vector2::operator += (const Vector2& other)
{
	x += other.x;
	y += other.y;
	return *this;
}

Vector2 Vector2::operator - (const Vector2& other) const
{
	return { x - other.x, y - other.y };
}

Vector2& Vector2::operator -= (const Vector2& other)
{
	x -= other.x;
	y -= other.y;
	return *this;
}

Vector2 Vector2::operator * (float scalar) const
{
	return { x * scalar, y * scalar };
}

Vector2& Vector2::operator *= (float scalar)
{
	x *= scalar;
	y *= scalar;
	return *this;
}

Vector2 Vector2::operator / (float scalar) const
{
	return { x / scalar, y / scalar };
}

Vector2& Vector2::operator /= (float scalar)
{
	x /= scalar;
	y /= scalar;
	return *this;

}

float Vector2::dot(const Vector2& other) const
{
	return x * other.x + y * other.y;
}

// sin-1(a.b)/(|a||b|)

float Vector2::angleBetween(const Vector2& other) const
{
	return (asin(dot(other) / (magnitude() * other.magnitude()))) * 180/3.15159f;
}

float Vector2::magnitude() const
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

float Vector2::magnitudeSqr() const
{
	return pow(Vector2::magnitude(), 2);
}

void Vector2::normalise()
{
	x /= magnitude();
	y /= magnitude();
}

Vector2 Vector2::normalised() const
{
	Vector2::normalise;
	return {x, y};
}


float Vector2::distanceTo(const Vector2& other) const
{
	return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}

float Vector2::distanceToSqr(const Vector2& other) const
{
	return pow(Vector2::distanceTo(other), 2);
}




// Vector 3:

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(float a, float b, float c)
{
	x = a;
	y = b;
	z = c;
}

Vector3::Vector3(const Vector3& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
}



float Vector3::operator [] (int index) const
{
	return data[index];
}

float& Vector3::operator [] (int index)
{
	return data[index];
}

Vector3& Vector3::operator = (const Vector3& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	return *this;
}

Vector3 Vector3::operator + (const Vector3& other) const
{
	return { x + other.x, y + other.y, z + other.z };
}

Vector3& Vector3::operator += (const Vector3& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}

Vector3 Vector3::operator - (const Vector3& other) const
{
	return { x - other.x, y - other.y, z - other.z };
}

Vector3& Vector3::operator -= (const Vector3& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}

Vector3 Vector3::operator * (float scalar) const
{
	return { x * scalar, y * scalar, z * scalar };
}

Vector3& Vector3::operator *= (float scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
	return *this;
}

Vector3 Vector3::operator / (float scalar) const
{
	return { x / scalar, y / scalar, z / scalar };
}

Vector3& Vector3::operator /= (float scalar)
{
	x /= scalar;
	y /= scalar;
	z /= scalar;
	return *this;
}



// Vector 4:

Vector4::Vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}
Vector4::Vector4(float a, float b, float c, float d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}
Vector4::Vector4(const Vector4& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	w = other.w;
}

Vector4& Vector4::operator = (const Vector4& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	w = other.w;
	return *this;
}

float Vector4::operator [] (int index) const
{
	return data[index];
}

float& Vector4::operator [] (int index)
{
	return data[index];
}

Vector4 Vector4::operator + (const Vector4& other) const
{
	return { x + other.x, y + other.y, z + other.y, w + other.w };
}

Vector4& Vector4::operator += (const Vector4& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
	return *this;
}

Vector4 Vector4::operator - (const Vector4& other) const
{
	return { x - other.x, y - other.y, z - other.y, w - other.w };
}

Vector4& Vector4::operator -= (const Vector4& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;
	return *this;
}

Vector4 Vector4::operator * (float scalar) const
{
	return { x * scalar, y * scalar, z * scalar, w * scalar };
}

Vector4& Vector4::operator *= (float scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
	w *= scalar;
	return *this;
}

Vector4 Vector4::operator / (float scalar) const
{
	return { x / scalar, y / scalar, z / scalar, w / scalar };
}

Vector4& Vector4::operator /= (float scalar)
{
	x /= scalar;
	y /= scalar;
	z /= scalar;
	w /= scalar;
	return *this;
}
