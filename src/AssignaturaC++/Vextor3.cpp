#include <iostream>   // std::cout
#include "Vextor3.h"
using namespace std;

Vector3& Vector3::Normalize()
{
	float  lenght = sqrt((x * x) + (y * y) + (z * z));

	return *new Vector3(x/lenght, y/ lenght, z/ lenght);
}

float Vector3::distance_to(const Vector3& v)
{
	float xPow = (x - v.x) * (x - v.x);
	float yPow = (y - v.y) * (y - v.y);
	float zPow = (z - v.z) * (z - v.z);

	return sqrt(xPow + yPow + zPow);
}

float Vector3::dot_product(const Vector3& v)
{
	return x*v.x + y * v.y + z*v.z;
}

Vector3& Vector3::cross_product(const Vector3& v)
{
	float crossX = (y * v.z) - (z * v.y);
	float crossY = (z * v.x) - (x * v.z);
	float crossZ = (x * v.y) - (y * v.x);

	return *new Vector3(crossX, crossY, crossZ);
}

float Vector3::angle_between(const Vector3& v)
{
	float dot = dot_product(v);
	float lenSq1 = x * x + y * y + z * z;
	float lenSq2 = v.x * v.x + v.y * v.y + v.z * v.z;
	float angle = acos(dot / sqrt(lenSq1 * lenSq2));

	return angle;
}


