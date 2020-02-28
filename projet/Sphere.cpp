#include "stdafx.h"
#include "Sphere.h"

Sphere::Sphere(Vector3 center, float radius, Colorf color) :
	center(center), radius(radius), color(color)
{
}

Sphere::~Sphere()
{
}

bool Sphere::Intersect(Ray ray, Vector3& intersection) const
{
	// solve for t
	// point = rayStart + rayDir * t
	// (point - center) ^ 2 = radius ^ 2
	Vector3 sr = ray.GetStart() - center;
	float b = ray.GetDirection().multiply(2).dot(sr);
	float c = sr.dot(sr) - (radius * radius);
	float delta = b * b - 4 * c;
	// if delta >= 0 there is a solution
	if (delta >= 0 && sr.dot(ray.GetDirection()) < 0)
	{
		float t1 = (-b - sqrt(delta)) / 2.f;
		float t2 = (-b + sqrt(delta)) / 2.f;
		// keep only the closest solution
		float t = t1 < t2 ? t1 : t2;
		intersection.set(ray.GetStart() + ray.GetDirection().multiply(t));
		return true;
	}
	return false;
}

Vector3 Sphere::GetNormal(Vector3 point) const
{
	return (point - center).normalize();
}

Colorf Sphere::GetColor(Vector3 point) const
{
	return color;
}
