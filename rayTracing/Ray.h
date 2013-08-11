#pragma once

#include <iostream>

#include "Vector3d.h"

class Ray
{
	vec3f location;
	vec3f direction;
public:
	Ray(void)
	{
		location = vec3f(0);
		direction = vec3f(0);
	}

	Ray(vec3f location, vec3f direction)
	{
		this->location = location;
		this->direction = direction;
	}

	Ray(const Ray& ray)
	{
		this->location = ray.location;
		this->direction = ray.direction;
	}

	Ray(Ray&& ray)
	{
		this->location = std::move(ray.location);
		this->direction = std::move(ray.direction);
	}

	vec3f getLocation() const
	{
		return location;
	}

	vec3f getDirection() const
	{
		return direction;
	}

	~Ray(void) {}

	vec3f apply(float t) const
	{
		return location + direction*t;
	}
};

