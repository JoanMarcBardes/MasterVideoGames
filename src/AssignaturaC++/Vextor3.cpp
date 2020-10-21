#include <iostream>   // std::cout
#include "Vextor3.h"
using namespace std;

Vector3::Vector3() :
	x(0), y(0), z(0)
{
}

Vector3::Vector3(double x, double y, double z) :
	x(x), y(y), z(z)
{
}

Vector3::Vector3(Vector3& v) :
	x(v.x), y(v.y), z(v.z)
{

}

// Destructor
Vector3::~Vector3()
{
}

Vector3& Vector3::operator=(const Vector3& v)
{
	return *this;
}

Vector3& Vector3::operator+(const Vector3 &v) 
{
	return *new Vector3(x + v.x, y + v.y, z + v.z );
}

/*ostream& Vector3::operator<<(ostream & os)
{
	os << "(" << x << ", " << y << ", " << z << ")";
	return os;
}*/

ostream& operator<<(ostream& os, const Vector3& v)
{
	os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
	return os;
}

Vector3& Vector3::Normalize()
{
	double  lenght = sqrt((x * x) + (y * y) + (z * z));

	return *new Vector3(x/lenght, y/ lenght, z/ lenght);
}

double Vector3::distance_to(const Vector3& v)
{
	double xPow = (x - v.x) * (x - v.x);
	double yPow = (y - v.y) * (y - v.y);
	double zPow = (z - v.z) * (z - v.z);

	return (double)sqrt(xPow + yPow + zPow);
}

double Vector3::dot_product(const Vector3& v)
{
	return x*v.x + y * v.y + z*v.z;
}

Vector3& Vector3::cross_product(const Vector3& v)
{
	double crossX = (y * v.z) - (z * v.y);
	double crossY = (z * v.x) - (x * v.z);
	double crossZ = (x * v.y) - (y * v.x);

	return *new Vector3(crossX, crossY, crossZ);
}

double Vector3::angle_between(const Vector3& v)
{
	double dot = dot_product(v);
	double lenSq1 = x * x + y * y + z * z;
	double lenSq2 = v.x * v.x + v.y * v.y + v.z * v.z;
	double angle = acos(dot / sqrt(lenSq1 * lenSq2));

	return angle;
}


