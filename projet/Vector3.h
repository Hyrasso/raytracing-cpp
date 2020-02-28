#pragma once
#include <iostream>

class Vector3
{
public:
	Vector3(float x=0, float y=0, float z=0);
	~Vector3();
	Vector3 multiply(Vector3 v) const;
	Vector3 multiply(float a) const;

	Vector3 normalize() const;
	float norm() const;

	Vector3 operator+(Vector3 v) const;
	Vector3 operator-(Vector3 v) const;

	float dot(Vector3 v) const;
	float operator*(Vector3 v) const;

	void set(Vector3 v);

	friend std::ostream& operator<<(std::ostream& out, const Vector3& v);
	friend std::istream& operator>>(std::istream& in, Vector3& v);
	float x, y, z;
};

