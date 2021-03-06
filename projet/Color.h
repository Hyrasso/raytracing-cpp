#pragma once

#include <iostream>

class Colorf
{
public:
	Colorf(float red=0.0, float green=0.0, float blue=0.0);
	~Colorf();
	float red, green, blue;
	Colorf operator+(Colorf other) const;
	Colorf operator*(float coeff) const;
	Colorf operator*(Colorf other) const;

	unsigned char GetRedAsuchar() const;
	unsigned char GetGreenAsuchar() const;
	unsigned char GetBlueAsuchar() const;

	friend std::ostream& operator<<(std::ostream & out, const Colorf & v);
};
