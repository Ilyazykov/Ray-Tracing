#include "Sphere.h"

Sphere::Sphere( const vec3f& center, float radius, const Material& material )
{
	this->center = center;
	this->radius = radius;
	this->material = material;
}

Sphere::Sphere(void)
{
	//TODO
}

float Sphere::intersect( const Ray& ray ) const
{
	vec3f temp = ray.getLocation() - this->center;

	float b = temp * ray.getDirection();
	float c = temp*temp - radius*radius;

	float discriminant = b*b - c;

	if (discriminant < 0)
		return -1;

	float d = sqrt(discriminant);

	float smallerDistance = -b - d;
	float greaterDistance = -b + d;

	if (greaterDistance < 0) return -1;

	if (smallerDistance >= 0) return smallerDistance;
	return -1;
}

vec3f Sphere::getNormale( const vec3f& point ) const
{
	return (point - center).normalize();
}

Sphere::~Sphere( void )
{

}
