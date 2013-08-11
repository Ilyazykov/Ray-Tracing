#pragma once

#include <vector>

#include "Shape.h"
#include "Light.h"

#include "Camera.h"

class Scene
{
	Camera camera;

	std::vector<Shape*> shapes;
	std::vector<Light*> lights;

	int reflectionLevel;
	int reflectionMaxLevel;

	Colour ambient;

public:
	Scene(void)
	{
		camera = Camera(vec3f(0,5,10), vec3f(0,0,0), vec3f(0,1,0), 
			640, 480, 0.4f, 0.3f, 1);
		reflectionMaxLevel = 5;
		reflectionLevel = 0;
		ambient = Colour::white();
	}
	Scene(Camera camera, int reflectionMaxLevel, Colour ambient)
	{
		this->camera = camera;
		this->reflectionMaxLevel = reflectionMaxLevel;
		this->reflectionLevel = 0;
		this->ambient = ambient;
	}
	~Scene(void)
	{
		for (int i = shapes.size()-1; i>=0; i--)
		{
			delete shapes[i];
			shapes[i] = NULL;
		}

		for (int i = lights.size()-1; i>=0; i--)
		{
			delete lights[i];
			lights[i] = NULL;
		}
	}

	Scene& operator<<(Shape* shape)
	{
		shapes.push_back(shape);
		return *this;
	}

	Scene& operator<<(Light* light)
	{
		lights.push_back(light);
		return *this;
	}

	Shape* intersect(float &t, const Ray &ray) const
	{
		float minT, tmpT;
		Shape *minShape;

		minT = -255;
		minShape = NULL;

		for (unsigned int i=0; i<shapes.size(); i++) {
			tmpT = shapes[i]->intersect(ray);
			if (tmpT != -1) {
				if (minT == -255 || tmpT < minT)
				{
					minT = tmpT;
					minShape = shapes[i];
				}
			}
		}

		if (minShape != NULL) {
			t = minT;
		}

		return minShape;
	}

	Colour trace(const Ray& ray) const
	{
		Shape *shape;
		float t = -255;

 		shape = intersect(t, ray); //t is change

 		if (shape == NULL)
 			return Colour::black();
 
		return Colour::blue(); //TODO возвращать нормальный цвет
	}

	Colour getColourOfPoint(int x, int y)
	{
 		Ray ray = camera.apply(x, y);
 
 		Colour colour = trace(ray);

		return colour; 
	}
};