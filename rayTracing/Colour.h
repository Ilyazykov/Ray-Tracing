#pragma once

typedef unsigned char uchar;

class Colour
{
	uchar b;
	uchar g;
	uchar r;

public:
	Colour(void)
	{
		b = g = r = 0;
	}

	Colour(uchar a)
	{
		b = g = r = a;
	}

	Colour(uchar blue, uchar green, uchar red)
	{
		this->b = blue;
		this->g = green;
		this->r = red;
	}

	Colour(const Colour& colour)
	{
		this->b = colour.b;
		this->g = colour.g;
		this->r = colour.r;
	}

	Colour& operator=(const Colour& colour)
	{
		this->b = colour.b;
		this->g = colour.g;
		this->r = colour.r;

		return *this;
	}

	uchar getBlue()
	{
		return b;
	}

	uchar getGreen()
	{
		return g;
	}

	uchar getRed()
	{
		return r;
	}

	static Colour white()
	{
		return Colour(255);
	}

	static Colour black()
	{
		return Colour(0);
	}

	static Colour blue()
	{
		return Colour(255,0,0);
	}

	static Colour green()
	{
		return Colour(0,255,0);
	}

	static Colour red()
	{
		return Colour(0,0,255);
	}

	~Colour(void)
	{

	}
};