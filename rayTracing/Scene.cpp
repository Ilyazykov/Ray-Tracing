#include "Scene.h"

Scene::Scene(void)
{
	camera = Camera(vec3f(0, 5, 10), vec3f(0, 0, 0), vec3f(0, 1, 0),
		640, 480, 0.4f, 0.3f, 1);
	reflectionMaxLevel = 5;
	reflectionLevel = 0;
	ambient = Colour::white();
}

Scene::Scene(Camera camera, int reflectionMaxLevel, Colour ambient)
{
	this->camera = camera;
	this->reflectionMaxLevel = reflectionMaxLevel;
	this->reflectionLevel = 0;
	this->ambient = ambient;
}

Scene::~Scene(void)
{
	for (int i = shapes.size() - 1; i >= 0; i--)
	{
		delete shapes[i];
		shapes[i] = NULL;
	}

	for (int i = lights.size() - 1; i >= 0; i--)
	{
		delete lights[i];
		lights[i] = NULL;
	}
}

Scene& Scene::operator<<(Shape* shape)
{
	shapes.push_back(shape);
	return *this;
}

Scene& Scene::operator<<(Light* light)
{
	lights.push_back(light);
	return *this;
}

Shape* Scene::intersect(float &t, const Ray &ray) const
{
	float minT, tmpT;
	Shape *minShape;

	minT = -255;
	minShape = NULL;

	for (unsigned int i = 0; i < shapes.size(); i++) {
		tmpT = shapes[i]->intersect(ray);
		if (tmpT != -1) {
			if (minT == -255 || tmpT < minT)
			{
				minT = tmpT;
				minShape = shapes[i];
			}
		}
	}

	if (minShape != NULL) {
		t = minT;
	}

	return minShape;
}

bool Scene::isShadowed(const Ray& ray) const
{
	float k;

	for (unsigned int i = 0; i < shapes.size(); i++)
	{
		k = shapes[i]->intersect(ray);
		if (k != -1) return false;
	}
	return true;
}

Colour Scene::getShapeColor(Shape *shape, const vec3f& incidentRay, const vec3f& point)
{
	Colour colour(0);

	vec3f normale = shape->getNormale(point);

	//Ambient
	colour += ambient * shape->getMaterial().getColour()
		* shape->getMaterial().getAmbient();

	for (unsigned int i = 0; i < lights.size(); i++)
	{
		vec3f vectorPointToLight;
		float cosOfAngleNormaleReflection = lights[i]->shade(vectorPointToLight, point, normale);//vectorPointToLight is change TODO исправить

		Ray ray(point, vectorPointToLight.normalize());
		ray.setLocation(ray.getLocation() + ray.getDirection()*EPS);

		if (isShadowed(ray))
		{
			//Diffuse
			colour += lights[i]->getColour() * cosOfAngleNormaleReflection *
				shape->getMaterial().getColour() *
				shape->getMaterial().getDiffuse();

			//Specular
			float rDir = (vectorPointToLight.normalize() - incidentRay).normalize() * normale;
			if (rDir > 0)
				colour += lights[i]->getColour() *
				shape->getMaterial().getSpecular() *
				pow(rDir, shape->getMaterial().getPhong());
		}

		Colour reflectionPower = Colour::white();
		vec3f reflection = (incidentRay - normale * 2 * (incidentRay*normale)).normalize();

		if (reflectionLevel < reflectionMaxLevel)
		{
			reflectionLevel++;
			reflectionPower = reflectionPower * shape->getMaterial().getReflection();

			ray.setLocation(point + reflection*EPS);
			ray.setDirection(reflection);

			colour += trace(ray)*shape->getMaterial().getReflection() *
				reflectionPower;

			reflectionLevel--;
		}
	}

	return colour;
}

Colour Scene::trace(const Ray& ray)
{
	Shape *shape;
	float t = -255;

	shape = intersect(t, ray); //t is change

	if (shape == NULL)
		return Colour::black();


	vec3f incidentRay = ray.getDirection();
	vec3f point = ray.apply(t);

	return getShapeColor(shape, incidentRay, point);
}

Colour Scene::getColourOfPoint(int x, int y)
{
	Ray ray = camera.apply(x, y);

	Colour colour = trace(ray);

	return colour;
}
