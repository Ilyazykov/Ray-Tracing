#include "DisplayWithOpenCV.h"
#include "Colour.h"
#include <iostream>

#include "Scene.h"
#include "Plane.h"
#include "Sphere.h"
#include "PointLight.h"
#include "setMaterial.h"

using namespace std;

Scene scene; //TODO ���������� ���������� - ���. ������������

void constructScene()
{
	Camera camera(vec3f(0,4,0.3f), vec3f(0, 0, 0.5f), vec3f(0, 0, 1), 
		640, 480, 0.64f, 0.48f, 1);	//TODO ������� ����� ����������
										//TODO ��������� display � camera �������� ������
	scene = Scene(camera, 5, Colour::white()); //TODO �������� ���������� ����� 5 �� ���������

	Shape *plane = new Plane(vec3f(0,0,0), vec3f(0,0,1), setMaterial(GOLD)); //TODO �������� �� �����-��������
	Shape *sphere = new Sphere(vec3f(0, 0, 0.5f), 0.5f, setMaterial(SILVER));	//TODO �������� �� �����-��������, a setMaterial ������� ����������� ������ ������ material
	
	scene << plane << sphere; //TODO ����� �� ����������� ��������?
	
// 	scene << new PointLight(vec3f(8,3,8), Colour(255,0,0));
 	scene << new PointLight(vec3f(-8,3,8), Colour(255,255,255));
// 	scene << new PointLight(vec3f(0,4,5), Colour(0,0,255));
}

///////////////////////////////////////////////////////////

void main()
{
	constructScene();

	Display *display = new DisplayWithOpenCV;

	int height = display->getHeight();
	int width = display->getWidth();

#pragma omp parallel for
	for (int x=0; x<width; ++x)
	{
		for (int y=0; y<height; ++y)
		{
			display->setPixel( x, y, scene.getColourOfPoint(x,y));
		}
	}

	display->show();

	delete display;
}