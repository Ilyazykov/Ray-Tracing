#include "Camera.h"

Camera::Camera( vec3f location, vec3f lookAt, vec3f up, int x, int y, float w, float h, float distance )
{
	this->location = location;

	this->direction = (lookAt - location).normalize();
	this->right = (this->direction % up).normalize();
	this->up = (this->right % this->direction).normalize();

	this->resolutionX = x;
	this->resolutionY = y;
	this->realWidth = w;
	this->realHeight = h;

	this->distance = distance;
}

Camera::Camera( const Camera& cam )
{
	this->location = cam.location;
	this->direction = cam.direction;
	this->right = cam.right;
	this->up = cam.up;
	this->resolutionX = cam.resolutionX;
	this->resolutionY = cam.resolutionY;
	this->realWidth = cam.realWidth;
	this->realHeight = cam.realHeight;
	this->distance = cam.distance;
}

Camera::Camera( Camera&& cam )
{
	this->location = std::move(cam.location);
	this->direction = std::move(cam.direction);
	this->right = std::move(cam.right);
	this->up = std::move(cam.up);
	this->resolutionX = std::move(cam.resolutionX);
	this->resolutionY = std::move(cam.resolutionY);
	this->realWidth = std::move(cam.realWidth);
	this->realHeight = std::move(cam.realHeight);
	this->distance = std::move(cam.distance);
}

Ray Camera::apply( int x, int y )
{
	Ray ray;

	vec3f toScreen;

	float widthOfPixel = realWidth/resolutionX;
	float heightOfPixel = realHeight/resolutionY;

	toScreen =	direction * distance +
		right * ((x - resolutionX/2) * widthOfPixel) +
		up * ((resolutionY/2 - y) * heightOfPixel);

	vec3f pointOfScreen = location + toScreen;
	vec3f directionOfRay = toScreen.normalize();

	ray = Ray(pointOfScreen, directionOfRay);

	return ray;
}
