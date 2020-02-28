#include "stdafx.h"
#include "Ray.h"


Ray::Ray(Vector3 start, Vector3 dir):
	start(start), dir(dir.normalize())
{
}


Ray::~Ray()
{
}

Vector3 Ray::GetDirection() const
{
	return dir;
}

Vector3 Ray::GetStart() const
{
	return start;
}
