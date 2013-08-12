#pragma once

#include "Vector3d.h"
#include "Ray.h"

#include <iostream>

class Camera
{
	vec3f location;
	vec3f direction;

	vec3f up;
	vec3f right;

	int resolutionX, resolutionY;
	float realWidth, realHeight;

	float distance;
public:
	Camera(void) 
	{
		//TODO
	}

	Camera(vec3f location, vec3f lookAt, vec3f up, int x, int y, 
		float w, float h, float distance);

	Camera(const Camera& cam);

	Camera(Camera&& cam);

	void move(vec3f location, vec3f lookAt, vec3f up) 
	{
		//TODO
	}

	~Camera(void) {}

	Ray apply (int x, int y);
};