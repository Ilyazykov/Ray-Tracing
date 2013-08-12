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