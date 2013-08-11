#pragma once
#include "shape.h"

#include "Vector3d.h"

class Plane : public Shape
{
	// u*x + v*y + q*z = a;

	vec3f normale;
	float a;
public:
	Plane(void) 
	{
		this->normale = vec3f(0.0f, 0.0f, 1.0f);
		this->a = 0;
		this->material = setMaterial(GOLD);
	}
	Plane(const vec3f& point, const vec3f& normale,
		  const Material& material) 
	{
		this->normale = normale;
		a = point * normale;
		this->material = material;
	}
	virtual ~Plane(void) {}

	virtual float intersect(const Ray& ray) const 
	{
		float distance = (a - normale*ray.getLocation()) / (normale*ray.getDirection());

		if (distance < 0) distance = -1;

		return distance;
	}
};

