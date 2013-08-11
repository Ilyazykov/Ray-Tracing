#pragma once
#include "shape.h"

#include <cmath>

#include "Vector3d.h"

typedef Vector3d<float> vec3f;

class Sphere : public Shape
{
	vec3f center;
	float radius;
public:
	Sphere(void) {}
	Sphere(const vec3f& center, float radius,
		   const Material& material) 
	{
		this->center = center;
		this->radius = radius;
		this->material = material;
	}
	virtual ~Sphere(void) {}

	virtual float intersect(const Ray& ray) const 
	{
		vec3f temp = ray.getLocation() - this->center;
		
		float b = temp * ray.getDirection();
		float c = temp*temp - radius*radius;

		float discriminant = b*b - c;

		if (discriminant < 0)
			return -1;

		float d = sqrt(discriminant);

		float smallerDistance = -b - d;
 		float greaterDistance = -b + d;
 
 		if (greaterDistance < 0) return -1;
 
 		if (smallerDistance >= 0) return smallerDistance;
 		return -1;
	}
};

