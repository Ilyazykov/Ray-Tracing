#pragma once

#include "shape.h"
#include "Vector3d.h"

#include <cmath>

class Sphere : public Shape
{
	vec3f center;
	float radius;
public:
	Sphere(void)
	{
		//TODO
	}

	Sphere(const vec3f& center, float radius, const Material& material);
	virtual ~Sphere(void);

	virtual float intersect(const Ray& ray) const;
	virtual vec3f getNormale(const vec3f& point) const;
};

