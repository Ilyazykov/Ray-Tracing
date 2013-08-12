#pragma once
#include "shape.h"

#include "Vector3d.h"

class Plane : public Shape
{
	// u*x + v*y + q*z = a;
	vec3f normale;
	float a;

public:
	Plane(void);
	Plane(const vec3f& point, const vec3f& normale, const Material& material);
	virtual ~Plane(void);

	virtual float intersect(const Ray& ray) const;
	virtual vec3f getNormale(const vec3f& point) const;
};

