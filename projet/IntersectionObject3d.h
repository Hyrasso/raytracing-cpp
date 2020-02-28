#pragma once
#include "Object3d.h"
#include <vector>
#include <memory>

class IntersectionObject3d :
	public Object3d
{
public:
	IntersectionObject3d();
	~IntersectionObject3d();

	bool Intersect(Ray r, Intersection& intersection) const override;
	void AddObject(std::unique_ptr<Object3d> obj);

	std::vector<std::unique_ptr<Object3d>> objects;
};

