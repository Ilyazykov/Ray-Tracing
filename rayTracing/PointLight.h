#pragma once
#include "light.h"

#include "Vector3d.h"

typedef Vector3d<float> vec3f;

class PointLight : public Light //TODO
{
	vec3f location;

public:
	PointLight(void);

	PointLight (const vec3f& location, const Colour& colour = Colour::white() );

	virtual ~PointLight(void);

	virtual float shade(vec3f &reflectionRay, const vec3f &shapePoint, const vec3f &normale);
};

