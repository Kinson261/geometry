#include "../src/point3D4.h"
#include <catch2/catch.hpp>
#include <vector>

TEST_CASE("Point3D4 are created", "[Point3D4]")
{
    int x_int(34), y_int(12), z_int(65);
    float x_float(34.45), y_float(12.34), z_float(23.43);
    double x_double(23.34), y_double(328), z_double(98.3);

    Point3D4 Point3D4int(x_int, y_int, z_int);
    REQUIRE(Point3D4int.getX() == x_int);
    REQUIRE(Point3D4int.getY() == y_int);
    REQUIRE(Point3D4int.getZ() == z_int);
    REQUIRE(Point3D4int.get() == std::vector<int>({x_int, y_int, z_int, 1}));

    Point3D4 Point3D4float(x_float, y_float, z_float);
    REQUIRE(Point3D4float.getX() == x_float);
    REQUIRE(Point3D4float.getY() == y_float);
    REQUIRE(Point3D4float.getZ() == z_float);
    REQUIRE(Point3D4float.get() == std::vector<float>({x_float, y_float, z_float, 1.0f}));

    Point3D4 Point3D4double(x_double, y_double, z_double);
    REQUIRE(Point3D4double.getX() == x_double);
    REQUIRE(Point3D4double.getY() == y_double);
    REQUIRE(Point3D4double.getZ() == z_double);
    REQUIRE(Point3D4double.get() == std::vector<double>({x_double, y_double, z_double, 1.0}));


    Point3D4 Point3D4int1(x_int, y_int, z_int, 1);
    REQUIRE(Point3D4int1.getX() == x_int);
    REQUIRE(Point3D4int1.getY() == y_int);
    REQUIRE(Point3D4int1.getZ() == z_int);
    REQUIRE(Point3D4int1.get() == std::vector<int>({x_int, y_int, z_int, 1}));

    Point3D4 Point3D4float1(x_float, y_float, z_float, 1.0f);
    REQUIRE(Point3D4float1.getX() == x_float);
    REQUIRE(Point3D4float1.getY() == y_float);
    REQUIRE(Point3D4float1.getZ() == z_float);
    REQUIRE(Point3D4float1.get() == std::vector<float>({x_float, y_float, z_float, 1.0f}));

    Point3D4 Point3D4double1(x_double, y_double, z_double, 1.0);
    REQUIRE(Point3D4double1.getX() == x_double);
    REQUIRE(Point3D4double1.getY() == y_double);
    REQUIRE(Point3D4double1.getZ() == z_double);
    REQUIRE(Point3D4double1.get() == std::vector<double>({x_double, y_double, z_double, 1.0}));
}
