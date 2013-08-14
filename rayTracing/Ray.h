#pragma once

#include <iostream>

#include "Vector3d.h"

class Ray
{
	vec3f location;
	vec3f direction;

public:
	Ray(void);
	Ray(vec3f location, vec3f direction);
	Ray(const Ray& ray);
	Ray(Ray&& ray);

	vec3f getLocation() const;
	vec3f getDirection() const;

	void setLocation(vec3f location);

	void setDirection(vec3f direction);

	vec3f apply(float t) const;

	~Ray(void);
};

