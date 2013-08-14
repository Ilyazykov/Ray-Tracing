#pragma once

#include "Colour.h"

class Material
{
	Colour colour;

	Colour ambient;
	Colour diffuse;
	Colour specular;

	Colour reflection;

	float phong;

public:
	Material(void)
	{
		colour = 255;

		ambient = 26;
		diffuse = 229;
		specular = 0;

		reflection = 0;

		phong = 0;
	}
	Material(const Colour& colour, const Colour& ambient,
			 const Colour& diffuse, const Colour& specular)
	{
		this->colour = colour;
		this->ambient = ambient;
		this->diffuse = diffuse;
		this->specular = specular;
	}
	
	~Material(void) {}

	void setAmbient(Colour ambient)
	{
		this->ambient = ambient;
	}
	void setDiffuse(Colour diffuse)
	{
		this->diffuse = diffuse;
	}
	void setSpecular(Colour specular)
	{
		this->specular = specular;
	}

	void setPhong(float phong)
	{
		this->phong = phong;
	}

	Colour getColour()
	{
		return colour;
	}

	Colour getAmbient()
	{
		return ambient;
	}

	Colour getDiffuse()
	{
		return diffuse;
	}

	Colour getSpecular()
	{
		return specular;
	}

	Colour getReflection()
	{
		return reflection;
	}

	float getPhong()
	{
		return phong;
	}
};

