#include <iostream>
#include "Vextor3.h"

using namespace std;

int main()
{
    Vector3 a = *new Vector3();
    Vector3 b = *new Vector3(1,0,1);
    Vector3 c = *new Vector3(b);
    Vector3 d = b + c;
    Vector3 e = *new Vector3(1, 0, -1);

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
    cout << "d: " << d << endl;

    cout << "Normalize b: " << b.Normalize() << endl;
    cout << "distance_to b: " << b.distance_to(d) << endl;
    cout << "dot_product b: " << b.dot_product(d) << endl;
    cout << "cross_product b: " << b.cross_product(e) << endl;
    cout << "cross_product b: " << b.angle_between(e) << endl;

    return 0;
}
