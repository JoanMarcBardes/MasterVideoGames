#include <iostream>
#include "Vextor3.h"
#include "String.h"

using namespace std;

String GetMeAString()
{
    return String("another string");
}

int main()
{
    cout << "*** Vector3 ***" << endl;
    Vector3 a = Vector3();
    Vector3 b = Vector3(1,0,1);
    Vector3 c = Vector3(b);
    Vector3 d = b + c;
    Vector3 e = Vector3(1, 0, -1);

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
    cout << "d: " << d << endl;

    cout << "Normalize b: " << b.Normalize() << endl;
    c.Normalized();
    cout << "Normalized c: " << c << endl;
    cout << "distance_to b: " << b.distance_to(d) << endl;
    cout << "dot_product b: " << b.dot_product(d) << endl;
    cout << "cross_product b: " << b.cross_product(e) << endl;
    cout << "angle_between b: " << b.angle_between(e) << endl;

    cout << "*** String ***" << endl;
    String s1 = String();
    String s2 = String("hello");
    String s3 = String(s2);
    String s4 = s2 + s3;
    String s5 = s4;
    String s6 = GetMeAString();

    cout << "s1: " << s1.str << endl;
    cout << "s2: " << s2.str << endl;
    cout << "s3: " << s3.str << endl;
    cout << "s4: " << s4.str << endl;
    cout << "s2 == s3: " << (s2 == s3) << endl;
    cout << "s2 == s4: " << (s2 == s4) << endl;
    cout << "s2 == hello: " << (s2 == "hello") << endl;
    cout << "s5: " << s5.str << endl;
    s5.clear();
    cout << "after clean s5: " << s5.str << endl;
    cout << "s6: " << s6.str << endl;

    return 0;
}
