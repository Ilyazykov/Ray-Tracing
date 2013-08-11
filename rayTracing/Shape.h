#pragma once

#include "Material.h"
#include "Ray.h"
#include "setMaterial.h"

class Shape
{
protected:
	Material material;

public:
	Shape() {}
	virtual ~Shape() {}
	virtual float intersect(const Ray& ray) const = 0;
};

