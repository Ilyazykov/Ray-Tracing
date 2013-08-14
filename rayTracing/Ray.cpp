#include "Ray.h"

Ray::Ray( void )
{
	location = vec3f(0);
	direction = vec3f(0);
}

Ray::Ray( vec3f location, vec3f direction )
{
	this->location = location;
	this->direction = direction;
}

Ray::Ray( const Ray& ray )
{
	this->location = ray.location;
	this->direction = ray.direction;
}

Ray::Ray( Ray&& ray )
{
	this->location = std::move(ray.location);
	this->direction = std::move(ray.direction);
}

vec3f Ray::getLocation() const
{
	return location;
}

vec3f Ray::getDirection() const
{
	return direction;
}

vec3f Ray::apply( float t ) const
{
	return location + direction*t;
}

Ray::~Ray( void )
{

}

void Ray::setLocation( vec3f location )
{
	this->location = location;
}

void Ray::setDirection( vec3f direction )
{
	this->direction = direction;
}
