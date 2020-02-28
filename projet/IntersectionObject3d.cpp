#include "stdafx.h"
#include "IntersectionObject3d.h"


IntersectionObject3d::IntersectionObject3d()
{
}


IntersectionObject3d::~IntersectionObject3d()
{
}

bool IntersectionObject3d::Intersect(Ray r, Intersection& intersection) const
{
	Intersection tmpIntersection, closestIntersection = Intersection{ Vector3(1e5, 1e5, 1e5) };
	int hitCount = 0;
	for (auto& obj : objects) {
		if (obj->Intersect(r, tmpIntersection)) {
			hitCount++;
			float dist1 = (tmpIntersection.point - r.GetStart()).norm();
			float dist2 = (closestIntersection.point - r.GetStart()).norm();
			if (dist1 < dist2) {
				closestIntersection = tmpIntersection;
			}
		}
	}
	intersection = closestIntersection;
	return hitCount > 0 && (hitCount % 2) == 0;
}

void IntersectionObject3d::AddObject(std::unique_ptr<Object3d> obj)
{
	objects.push_back(std::move(obj));
}