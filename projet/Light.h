#pragma once
#include "Vector3.h"
#include "Color.h"

class Light
{
public:
	Light();
	~Light();
	virtual Vector3 GetDirection(Vector3 point) const = 0;
	virtual Colorf GetColor() const= 0;
};

