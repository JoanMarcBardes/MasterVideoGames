#include <iostream>
using namespace std;

class Vector3
{
public:
	Vector3();
	Vector3(double x, double y, double z);
	Vector3(Vector3& v);
	~Vector3();

	Vector3& operator=(const Vector3& v);
	Vector3& operator+(const Vector3& v);

	//ostream& operator<<(ostream& os);
	friend ostream& operator<<(ostream& os, const Vector3& v);

	Vector3& Normalize();
	double distance_to(const Vector3& v);
	double dot_product(const Vector3& v);
	Vector3& cross_product(const Vector3& v);
	double angle_between(const Vector3& v);

private:
	double x;
	double y;
	double z;
};
