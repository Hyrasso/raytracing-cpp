#pragma once
#include "Light.h"

class PointLight : 
	public Light
{
public:
	PointLight(Vector3 origin, Colorf color);
	~PointLight();
	Vector3 GetDirection(Vector3 point) const override;
	Colorf GetColor() const override;
private:
	Vector3 origin;
	Colorf color;
};

