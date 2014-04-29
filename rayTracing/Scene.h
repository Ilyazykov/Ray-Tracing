#pragma once

#include <vector>
#include <cmath>

#include "Shape.h"
#include "Light.h"

#include "Camera.h"

class Scene //TODO
{
	Camera camera;

	std::vector<Shape*> shapes;
	std::vector<Light*> lights;

	int reflectionLevel;
	int reflectionMaxLevel;

	Colour ambient;

public:
	Scene(void);
	Scene(Camera camera, int reflectionMaxLevel, Colour ambient);
	~Scene(void);

	Scene& operator<<(Shape* shape);

	Scene& operator<<(Light* light);

	Shape* intersect(float &t, const Ray &ray) const;

	bool isShadowed(const Ray& ray) const;

	Colour getShapeColor(Shape *shape, const vec3f& incidentRay, const vec3f& point);

	Colour trace(const Ray& ray);

	Colour getColourOfPoint(int x, int y);
};