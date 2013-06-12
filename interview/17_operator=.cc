#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Point2D
{
    Point2D():x(0), y(0) {}
    Point2D(int px, int py) : x(px), y(py) {}
    int x, y;
};

ostream& operator<<(ostream& os, const Point2D& p)
{ os << "(" << p.x << "," << p.y << ")" << endl; return os;}

struct Point3D : public Point2D
{
    Point3D():Point2D(0, 0), z(0) {}
    Point3D(int px, int py, int pz) : Point2D(px, py), z(pz) {}
    // why reference returned and const argument?
    Point3D& operator=(const Point3D& r)
    {
        if (this == &r) // why self-assignment check is need?
            return *this;
        z = r.z;
        return *this;
    }

    int z;
};

ostream& operator<<(ostream& os, const Point3D& p)
{ os << "(" << p.x << "," << p.y << "," << p.z << ")" << endl; return os;}

int main()
{
    Point3D p1(1, 2, 3), p2;
    p2 = p1;
    cout << p1 << p2;
    // guess output?
    // what about Point2D::operator=(...)?
}