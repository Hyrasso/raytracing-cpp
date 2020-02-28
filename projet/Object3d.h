#pragma once
#include "Ray.h"
#include "Color.h"

class Object3d
{
public:
	Object3d();
	~Object3d();
	virtual bool Intersect(Ray r, Vector3& intersection) const = 0;
	virtual Vector3 GetNormal(Vector3 point) const = 0;
	virtual Colorf GetColor(Vector3 point) const = 0;
};

