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
	Material(void);
	Material(const Colour& colour, const Colour& ambient,
			 const Colour& diffuse, const Colour& specular);
	
	~Material(void);

	void setAmbient(Colour ambient);
	void setDiffuse(Colour diffuse);
	void setSpecular(Colour specular);

	void setPhong(float phong);
	void setReflection(Colour reflection);

	Colour getColour();
	Colour getAmbient();
	Colour getDiffuse();
	Colour getSpecular();
	Colour getReflection();

	float getPhong();
};