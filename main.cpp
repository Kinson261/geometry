#include <iostream>

#include "src/point2D.h"
#include "src/point3D.h"
#include "src/point3D4.h"

template <typename T>
void printPoint(T& pt)
{
    for (auto i : pt.get())
    {
        std::cout << i << std::endl;
    }
}

int main()
{
    // Create a Point2D with type double
    Point2D<double> p2d(3.0, 4.0);
    p2d.print();
    p2d.set(8.9, 4.3);
    p2d.print();
    // for (auto i:p2d.get()){std::cout << i << std::endl;}

    // Create a Point3D with type int
    Point3D<float> p3d(1.233, 2.245345, 3.56);
    p3d.print();
    std::cout << p3d.getX() << "\t";
    std::cout << p3d.getY() << "\t";
    std::cout << p3d.getZ() << "\t" << std::endl;
    p3d.print();
    p3d.set(23678, 45, 76);
    p3d.print();

    Point3D4<int> as1;
    Point3D4<int> as2(23, 324, 546);
    Point3D4<int> as3(23, 324, 546, 345);
    as2.print();
    as2.set(34, 657, 546);
    as2.print();

    return 0;
}
