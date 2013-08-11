#pragma once

#include "Colour.h"

class Light
{
protected:
	Colour colour;
public:
	Light(void) {}
	virtual ~Light(void) {}
};

