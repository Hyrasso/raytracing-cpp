#pragma once
#include "Vector3.h"
#include "Color.h"

class Ray
{
public:
	Ray(Vector3 start, Vector3 dir);
	~Ray();
	Vector3 GetDirection() const;
	Vector3 GetStart() const;
private:
	Vector3 start, dir;
};

struct Intersection
{
	Vector3 point;
	Vector3 normal;
	Colorf color;
};
