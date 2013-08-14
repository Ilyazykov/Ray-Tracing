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

	virtual float shade(vec3f &reflectionRay, const vec3f &shapePoint, const vec3f &normale)
	{
		vec3f directionOfReflection;
		float cosOfAngle;

		reflectionRay = this->location - shapePoint;
		directionOfReflection = reflectionRay.normalize();

		cosOfAngle = normale * directionOfReflection;

		if (cosOfAngle < 0) return 0;
		if (cosOfAngle > 1) return 1;

		return cosOfAngle;
	}
};

