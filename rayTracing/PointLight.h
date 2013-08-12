#pragma once
#include "light.h"

#include "Vector3d.h"

typedef Vector3d<float> vec3f;

class PointLight : public Light //TODO
{
	vec3f location;

public:
	PointLight(void)
	{
		location = 0;
		colour = Colour::white();
	}

	PointLight (const vec3f& location, const Colour& colour = Colour::white() )
	{
		this->location = location;
		this->colour = colour;
	}

	virtual ~PointLight(void)
	{

	}
};

