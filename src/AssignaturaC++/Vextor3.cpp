#include "Vextor3.h"
using namespace std;


float Vector3::magnitud() const
{
	return sqrt((x * x) + (y * y) + (z * z));
}

Vector3 Vector3::Normalize() const
{
	float m = magnitud();

	return Vector3(x/m, y/ m, z/m);
}

void Vector3::Normalized()
{
	float m = magnitud();
	x = x / m;
	y = y / m;
	z = z / m;
}

float Vector3::distance_to(const Vector3& v) const
{
	float xPow = (x - v.x) * (x - v.x);
	float yPow = (y - v.y) * (y - v.y);
	float zPow = (z - v.z) * (z - v.z);

	return sqrt(xPow + yPow + zPow);
}

float Vector3::dot_product(const Vector3& v) const
{
	return x*v.x + y * v.y + z*v.z;
}

Vector3 Vector3::cross_product(const Vector3& v) const
{
	float crossX = (y * v.z) - (z * v.y);
	float crossY = (z * v.x) - (x * v.z);
	float crossZ = (x * v.y) - (y * v.x);

	return Vector3(crossX, crossY, crossZ);
}

float Vector3::angle_between(const Vector3& v) const
{
	float dot = dot_product(v);
	float m1 = magnitud();
	float m2 = v.magnitud();
	float angle = acos(dot / sqrt(m1 * m2));

	return angle;
}


