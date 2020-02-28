#pragma once
#include "Light.h"

class DirectionalLight :
	public Light
{
public:
	DirectionalLight(Vector3 direction, Colorf color);
	~DirectionalLight();
	Vector3 GetDirection(Vector3 point) const override;
	Colorf GetColor() const override;
private:
	Vector3 direction;
	Colorf color;
};

