#include "stdafx.h"
#include "Color.h"
#include <algorithm>

Colorf::Colorf(float red, float green, float blue) : red(red), green(green), blue(blue) 
{
}


Colorf::~Colorf()
{
}

Colorf Colorf::operator+(Colorf other) const
{
	return Colorf(red + other.red, green + other.green, blue + other.blue);
}

Colorf Colorf::operator*(float coeff) const
{
	return Colorf(red * coeff, green * coeff, blue * coeff);
}

Colorf Colorf::operator*(Colorf other) const
{
	return Colorf(red * other.red, green * other.green, blue * other.blue);
}

unsigned char Colorf::GetRedAsuchar() const
{
	return std::max(0.0, std::min(red * 255.0, 255.0));
}

unsigned char Colorf::GetGreenAsuchar() const
{
	return std::max(0.0, std::min(green * 255.0, 255.0));
}

unsigned char Colorf::GetBlueAsuchar() const
{
	return std::max(0.0, std::min(blue * 255.0, 255.0));
}

Colorf Colorf::WHITE()
{
	return Colorf(1.0, 1.0, 1.0);
}

std::ostream & operator<<(std::ostream & out, const Colorf & v)
{
	out << "(" << v.red << ", " << v.green << ", " << v.blue << ")";
	return out;
}
