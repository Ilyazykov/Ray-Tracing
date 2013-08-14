#include "Material.h"

Material::Material( void )
{
	colour = 255;

	ambient = 26;
	diffuse = 229;
	specular = 0;

	reflection = 130;

	phong = 0;
}

Material::Material( const Colour& colour, const Colour& ambient, const Colour& diffuse, const Colour& specular )
{
	this->colour = colour;
	this->ambient = ambient;
	this->diffuse = diffuse;
	this->specular = specular;
}

Material::~Material( void )
{

}

void Material::setAmbient( Colour ambient )
{
	this->ambient = ambient;
}

void Material::setDiffuse( Colour diffuse )
{
	this->diffuse = diffuse;
}

void Material::setSpecular( Colour specular )
{
	this->specular = specular;
}

void Material::setPhong( float phong )
{
	this->phong = phong;
}

void Material::setReflection( Colour reflection )
{
	this->reflection = reflection;
}

Colour Material::getColour()
{
	return colour;
}

Colour Material::getAmbient()
{
	return ambient;
}

Colour Material::getDiffuse()
{
	return diffuse;
}

Colour Material::getSpecular()
{
	return specular;
}

Colour Material::getReflection()
{
	return reflection;
}

float Material::getPhong()
{
	return phong;
}
