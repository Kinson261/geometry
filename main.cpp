#include <iostream>

#include "src/point2D.h"
#include "src/point3D.h"
#include "src/point3D4.h"

int main()
{
    // Create a Point2D with type double
    Point2D<double> p2d(3.0, 4.0);
    std::cout << p2d << "\n";
    p2d.set(8.9, 4.3);
    std::cout << p2d << "\n";
    // for (auto i:p2d.get()){std::cout << i << std::endl;}

    Point2D<double> p2d2(p2d);
    std::cout << p2d2 << "\n";
    std::cout << &p2d2 << "\n";

    // Create a Point3D with type int
    Point3D<float> p3d(1.233, 2.245345, 3.56);
    std::cout << p3d << "\n";
    std::cout << p3d.getX() << "\t";
    std::cout << p3d.getY() << "\t";
    std::cout << p3d.getZ() << "\t" << "\n";
    std::cout << "\n";
    std::cout << p3d << "\n";
    p3d.set(23678, 45, 76);
    std::cout << p3d << "\n";

    Point3D4<int> as1;
    Point3D4<int> as2(23, 324, 546);
    Point3D4<int> as3(23, 324, 546, 345);
    std::cout << as2 << "\n";   
    as2.set(34, 657, 546);
    std::cout << as2 << "\n";   
    

    return 0;
}
