#include "setmaterial.h"

Material setMaterial( int materialID )
{
	Material material;

	switch(materialID) 
	{
	case 0:
		material.setAmbient(Colour(63, 51, 19));
		material.setDiffuse(Colour(192, 155, 58));
		material.setSpecular(Colour(160, 142, 93));
		material.setPhong(51.2f);
		break;
	case 1:
		material.setAmbient(Colour(49));
		material.setDiffuse(Colour(129));
		material.setSpecular(Colour(130));
		material.setPhong(51.2f);
		break;
	case 2:
		material.setAmbient(Colour(63, 51, 19));
		material.setDiffuse(Colour(192, 155, 58));
		material.setSpecular(Colour(160, 142, 93));
		material.setPhong(51.2f);
		break;
		/*
	case 3:
		material.setAmbient(Colour(63, 51, 19));
		material.setDiffuse(Colour(192, 155, 58));
		material.setSpecular(Colour(160, 142, 93));
		material.setPhong(51.2f);
		break;
	case 4:
		material.setAmbient(Colour(63, 51, 19));
		material.setDiffuse(Colour(192, 155, 58));
		material.setSpecular(Colour(160, 142, 93));
		material.setPhong(51.2f);
		break;
	case 5:
		material.setAmbient(Colour(63, 51, 19));
		material.setDiffuse(Colour(192, 155, 58));
		material.setSpecular(Colour(160, 142, 93));
		material.setPhong(51.2f);
		break;
	case 6:
		material.setAmbient(Colour(63, 51, 19));
		material.setDiffuse(Colour(192, 155, 58));
		material.setSpecular(Colour(160, 142, 93));
		material.setPhong(51.2f);
		break;
	case 7:
		material.setAmbient(Colour(63, 51, 19));
		material.setDiffuse(Colour(192, 155, 58));
		material.setSpecular(Colour(160, 142, 93));
		material.setPhong(51.2f);
		break;
	case 8:
		material.setAmbient(Colour(63, 51, 19));
		material.setDiffuse(Colour(192, 155, 58));
		material.setSpecular(Colour(160, 142, 93));
		material.setPhong(51.2f);
		break;
	case 9: 
		material.setAmbient(Colour(63, 51, 19));
		material.setDiffuse(Colour(192, 155, 58));
		material.setSpecular(Colour(160, 142, 93));
		material.setPhong(51.2f);
		break;
	case 10: 
		material.setAmbient(Colour(63, 51, 19));
		material.setDiffuse(Colour(192, 155, 58));
		material.setSpecular(Colour(160, 142, 93));
		material.setPhong(51.2f);
		break;
	case 11: 
		material.setAmbient(Colour(63, 51, 19));
		material.setDiffuse(Colour(192, 155, 58));
		material.setSpecular(Colour(160, 142, 93));
		material.setPhong(51.2f);
		break;
	case 12: 
		material.setAmbient(Colour(63, 51, 19));
		material.setDiffuse(Colour(192, 155, 58));
		material.setSpecular(Colour(160, 142, 93));
		material.setPhong(51.2f);
		break;
	case 13: 
		material.setAmbient(Colour(63, 51, 19));
		material.setDiffuse(Colour(192, 155, 58));
		material.setSpecular(Colour(160, 142, 93));
		material.setPhong(51.2f);
		break; */
	}

	return material;
}