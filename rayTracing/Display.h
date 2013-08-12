#pragma once

#include "Colour.h"

class Display
{
protected:
	int width;
	int height;
public:
	Display(void);
	
	int getWidth();
	int getHeight();

	virtual void setPixel(int x, int y, Colour colour) = 0;
	virtual void show() = 0;

	virtual ~Display(void);
};