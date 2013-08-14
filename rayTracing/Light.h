#pragma once

#include "Colour.h"
#include "Vector3d.h"

class Light
{
protected:
	Colour colour;
public:
	Light(void) 
	{
		//TODO
	}
	virtual ~Light(void) 
	{
		//TODO
	}

	virtual float shade(vec3f &incidentRay, const vec3f &point, const vec3f &normale) = 0;

	Colour getColour()
	{
		return colour;
	}
};