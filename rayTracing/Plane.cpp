#include "Plane.h"

Plane::Plane( void )
{
	this->normale = vec3f(0.0f, 0.0f, 1.0f);
	this->a = 0;
	this->material = setMaterial(GOLD);
}

Plane::Plane( const vec3f& point, const vec3f& normale, const Material& material )
{
	this->normale = normale;
	a = point * normale;
	this->material = material;
}

Plane::~Plane( void )
{

}

float Plane::intersect( const Ray& ray ) const
{
	float distance = (a - normale*ray.getLocation()) / (normale*ray.getDirection());

	if (distance < 0) distance = -1;

	return distance;
}

vec3f Plane::getNormale( const vec3f& point ) const
{
	return normale;
}
