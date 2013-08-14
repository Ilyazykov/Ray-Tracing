#pragma once

#include <iostream>

typedef unsigned char uchar;

class Colour
{
	uchar b;
	uchar g;
	uchar r;

public:
	Colour(void);
	Colour(uchar a);
	Colour(uchar blue, uchar green, uchar red);
	Colour(const Colour& colour);
	Colour(Colour&& colour);
	Colour& operator=(const Colour& colour);
	Colour& operator=(Colour&& colour);

	Colour operator*(const Colour &colour) const
	{
		Colour res;

		res.r = r*colour.r /255;
		res.g = g*colour.g /255;
		res.b = b*colour.b /255;

		return res;
	}

	Colour operator*(float a) const
	{
		Colour res;

		res.r = r*a;
		res.g = g*a;
		res.b = b*a;

		return res;
	}

	Colour& operator+=(const Colour &colour)
	{
		r += colour.r;
		g += colour.g;
		b += colour.b;

		return *this;
	}

	uchar getBlue();
	uchar getGreen();
	uchar getRed();

	static Colour white();
	static Colour black();
	static Colour blue();
	static Colour green();
	static Colour red();

	~Colour(void);
};