#include "stdafx.h"
#include "PointLight.h"


PointLight::PointLight(Vector3 origin, Colorf color) :
	origin(origin), color(color)
{
}

PointLight::~PointLight()
{
}

Vector3 PointLight::GetDirection(Vector3 point) const
{
	return (origin - point).normalize();
}

Colorf PointLight::GetColor() const
{
	return color;
}
