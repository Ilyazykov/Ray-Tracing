#pragma once

#include <iostream>
#include <cmath>

#define EPS 0.0005

template <class T>
class Vector3d
{
	T x, y, z;
public:
	Vector3d(void)
	{
		x = y = z = 0;
	}
	Vector3d(T a)
	{
		x = y = z = a;
	}
	Vector3d(T x, T y, T z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	Vector3d(const Vector3d<T>& vec)
	{
		this->x = vec.x;
		this->y = vec.y;
		this->z = vec.z;
	}

	Vector3d(Vector3d<T>&& vec)
	{
		this->x = std::move(vec.x);
		this->y = std::move(vec.y);
		this->z = std::move(vec.z);
	}

	Vector3d& operator=(const Vector3d<T>& vec)
	{
		this->x = vec.x;
		this->y = vec.y;
		this->z = vec.z;

		return *this;
	}

	Vector3d& operator=(Vector3d<T>&& vec)
	{
		this->x = std::move(vec.x);
		this->y = std::move(vec.y);
		this->z = std::move(vec.z);

		return *this;
	}

	Vector3d operator*(const float& a) const
	{
		Vector3d<T> result(this->x * a, this->y * a, this->z * a); 

		return result;
	}

	Vector3d operator+(const Vector3d<T>& vec) const
	{
		Vector3d<T> result (this->x + vec.x, 
							this->y + vec.y, 
							this->z + vec.z);

		return result;
	}

	Vector3d operator-(const Vector3d<T>& vec) const
	{
		Vector3d<T> result (this->x - vec.x, 
							this->y - vec.y, 
							this->z - vec.z);

		return result;
	}

	T operator*(const Vector3d<T>& vec) const
	{
		return x*vec.x + y*vec.y + z*vec.z;
	}

	Vector3d operator%(const Vector3d<T>& vec) const
	{
		Vector3d<T> result;

		result.x = y*vec.z - z*vec.y;
		result.y = z*vec.x - x*vec.z;
		result.z = x*vec.y - y*vec.x;

		return result;
	}

	float getLength()
	{
		return sqrt(x*x + y*y + z*z);
	}
	Vector3d normalize()
	{
		float length = this->getLength();

		Vector3d<T> result(x/length, y/length, z/length);
		
		return result;
	}

	~Vector3d(void)
	{

	}
};

typedef Vector3d<float> vec3f;