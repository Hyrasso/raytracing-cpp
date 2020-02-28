#pragma once
#include "Object3d.h"
#include "Vector3.h"
#include "Color.h"

class Sphere :
	public Object3d
{
public:
	Sphere(Vector3 center, float radius=1, Colorf color=Colorf());
	~Sphere();
	bool Intersect(Ray r, Vector3& intersection) const override;
	Vector3 GetNormal(Vector3 point) const override;
	Colorf GetColor(Vector3 point) const override;
private:
	Vector3 center;
	float radius;
	Colorf color;
};

