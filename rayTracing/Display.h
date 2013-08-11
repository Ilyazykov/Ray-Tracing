#pragma once

#include "Colour.h"

class Display
{
protected:
	int width;
	int height;
public:
	Display(void) {}
	virtual ~Display(void) {}

	int getWidth()
	{
		return width;
	}

	int getHeight()
	{
		return height;
	}

	virtual void setPixel(int x, int y, Colour colour) = 0;

	virtual void show() = 0;
};