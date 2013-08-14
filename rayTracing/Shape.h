#pragma once

#include "Material.h"
#include "Ray.h"
#include "setMaterial.h"

class Shape
{
protected:
	Material material;

public:
	Shape();
	virtual ~Shape();

	virtual float intersect(const Ray& ray) const = 0;
	virtual vec3f getNormale(const vec3f& point) const = 0;

	Material getMaterial()
	{
		return material;
	}
};

