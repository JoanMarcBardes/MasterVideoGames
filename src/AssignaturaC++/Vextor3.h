#include <iostream>
using namespace std;

class Vector3
{
public:
	inline Vector3() : x(0), y(0), z(0) {}
	inline Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
	inline Vector3(Vector3& v) { x = v.x; y = v.y; z = v.z; }
	inline ~Vector3() {}

	inline Vector3& operator=(const Vector3& v) { return *this;	}
	inline Vector3& operator+(const Vector3& v)	{ return *new Vector3(x + v.x, y + v.y, z + v.z); }
	inline Vector3& operator-(const Vector3& v) { return *new Vector3(x - v.x, y - v.y, z - v.z); }
	inline Vector3& operator*(const Vector3& v) { return *new Vector3(x * v.x, y * v.y, z * v.z); }
	inline Vector3& operator/(const Vector3& v) { return *new Vector3(x / v.x, y / v.y, z / v.z); }

	//inline ostream& operator<<(ostream& os) { return os << "(" << x << ", " << y << ", " << z << ")"; }
	inline friend ostream& operator<<(ostream& os, const Vector3& v) { return os << "(" << v.x << ", " << v.y << ", " << v.z << ")"; }

	Vector3& Normalize();
	float distance_to(const Vector3& v);
	float dot_product(const Vector3& v);
	Vector3& cross_product(const Vector3& v);
	float angle_between(const Vector3& v);

private:
	float x;
	float y;
	float z;
};
