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
	return (acos(dot(other) / (magnitude() * other.magnitude()))) * 180/3.15159f;
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
	*this = this->normalised();
}

Vector2 Vector2::normalised() const
{
	
	return {x / magnitude(), y / magnitude()};
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

float Vector3::dot(const Vector3& other) const
{
	return x * other.x + y * other.y + z * other.z;
}

float Vector3::angleBetween(const Vector3& other) const
{
	return (acos(dot(other) / (magnitude() * other.magnitude()))) * 180 / 3.15159f;
}

Vector3 Vector3::cross(const Vector3& other) const
{
	return { (y * other.z) - (z * other.y), (z * other.x) - (x * other.z), (x * other.y) - (y * other.x) };
}

float Vector3::magnitude() const
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

float Vector3::magnitudeSqr() const
{
	return pow(magnitude(), 2);
}

void Vector3::normalise()
{
	x /= magnitude();
	y /= magnitude();
	z /= magnitude();
}

Vector3 Vector3::normalised() const
{
	return { x / magnitude(), y / magnitude(), z / magnitude() };
}

float Vector3::distanceTo(const Vector3& other) const
{
	return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2) + pow(z - other.z, 2));
}

float Vector3::distanceToSqr(const Vector3& other) const
{
	return pow(distanceTo(other), 2);
}

Vector3::operator Vector4() const
{
	return { x, y, z, 0 };
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

float Vector4::dot(const Vector4& other) const
{
	return x * other.x + y * other.y + z * other.z + w * other.w;
}

float Vector4::angleBetween(const Vector4& other) const
{
	return (acos(dot(other) / (magnitude() * other.magnitude()))) * 180 / 3.15159f;
}

Vector4 Vector4::cross(const Vector4& other) const
{
	return { (y * other.z) - (z * other.y), (z * other.x) - (x * other.z), (x * other.y) - (y * other.x), w };
}

float Vector4::magnitude() const
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2));
}

float Vector4::magnitudeSqr() const
{
	return pow(magnitude(), 2);
}

void Vector4::normalise()
{
	x /= magnitude();
	y /= magnitude();
	z /= magnitude();
	w /= magnitude();
}

Vector4 Vector4::normalised() const
{
	return { x / magnitude(), y / magnitude(), z / magnitude(), w / magnitude() };
}

float Vector4::distanceTo(const Vector4& other) const
{
	return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2) + pow(z - other.z, 2) + pow(w - other.w, 2));
}

float Vector4::distanceToSqr(const Vector4& other) const
{
	return pow(distanceTo(other), 2);
}

Vector4::operator Vector3() const
{
	return { x, y, z };
}