#pragma once
#include "Ray.h"
#include "Color.h"

class Object3d
{
public:
	Object3d();
	~Object3d();
	virtual bool Intersect(Ray r, Intersection& intersection) const = 0;
};
