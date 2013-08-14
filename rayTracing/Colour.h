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
	Colour(uchar red, uchar green, uchar blue);
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

	Colour& operator*=(const Colour &colour)
	{
		r *= colour.r / 255;
		g *= colour.g / 255;
		b *= colour.b / 255;

		return *this;
	}

	Colour& operator+=(const Colour &colour)
	{
		if (((int)r + (int)colour.r) > 255) r = 255;
		else r += colour.r;

		if (((int)g + (int)colour.g) > 255) g = 255;
		else g += colour.g;

		if (((int)b + (int)colour.b) > 255) b = 255;
		else b += colour.b;

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