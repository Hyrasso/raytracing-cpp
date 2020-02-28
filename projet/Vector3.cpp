#include "stdafx.h"
#include "Vector3.h"


Vector3::Vector3(float x, float y, float z) :
	x(x), y(y), z(z)
{
}


Vector3::~Vector3()
{
}

Vector3 Vector3::multiply(Vector3 v) const
{
	return Vector3(v.x * x, v.y * y, v.z * z);
}

float Vector3::dot(Vector3 v) const
{
	return v.x * x + v.y * y + v.z * z;
}

Vector3 Vector3::multiply(float a) const
{
	return Vector3(x * a, y * a, z * a);
}

Vector3 Vector3::normalize() const
{
	return this->multiply(1 / sqrt(dot(*this)));
}

float Vector3::norm() const
{
	return sqrt(dot(*this));
}

Vector3 Vector3::operator+(Vector3 v) const
{
	return Vector3(v.x + x, v.y + y, v.z + z);
}

Vector3 Vector3::operator-(Vector3 v) const
{
	return Vector3(x - v.x, y - v.y, z - v.z);
}

float Vector3::operator*(Vector3 v) const
{
	return dot(v);
}

void Vector3::set(Vector3 v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}

std::ostream & operator<<(std::ostream & out, const Vector3 & v)
{
	out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
	return out;
}

std::istream & operator>>(std::istream & in, Vector3 & v)
{
	in >> v.x >> v.y >> v.z;
	return in;
}
