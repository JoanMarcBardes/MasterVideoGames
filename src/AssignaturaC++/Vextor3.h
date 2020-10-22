#ifndef _VECTOR3_HH_INCLUDE
#define _VECTOR3_HH_INCLUDE
#include <iostream>

class Vector3
{
public:
	Vector3() : x(0), y(0), z(0) {}
	Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
	Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
	~Vector3() {}

	void operator=(const Vector3& v) { x = v.x; y = v.y; z = v.z; }
	Vector3 operator+(const Vector3& v) const { return Vector3(x + v.x, y + v.y, z + v.z); }
	Vector3 operator-(const Vector3& v) const { return Vector3(x - v.x, y - v.y, z - v.z); }

	friend std::ostream& operator<<(std::ostream& os, const Vector3& v) { return os << "(" << v.x << ", " << v.y << ", " << v.z << ")"; }

	float magnitud() const;
	Vector3 Normalize() const;
	void Normalized();
	float distance_to(const Vector3& v) const;
	float dot_product(const Vector3& v) const;
	Vector3 cross_product(const Vector3& v) const;
	float angle_between(const Vector3& v) const;

	//En caso de vecot3 no hace falta que sean privados, pero en caso que lo fueran tendrían que tener un get/set 
	float x;
	float y;
	float z;
};
#endif _VECTOR3_HH_INCLUDE