#define CATCH_CONFIG_MAIN

#include "../src/point2D.h"
#include "../src/point3D.h"
#include "../src/point3D4.h"
#include <catch2/catch.hpp>
#include <vector>

TEST_CASE("Point2D are created", "[Point2D]")
{
    int x_int(34), y_int(12);
    float x_float(34.45), y_float(12.34);
    double x_double(23.34), y_double(328);

    Point2D point2Dint(x_int, y_int);
    REQUIRE(point2Dint.getX() == x_int);
    REQUIRE(point2Dint.getY() == y_int);
    REQUIRE(point2Dint.get() == std::vector<int>({x_int, y_int}));

    Point2D point2Dfloat(x_float, y_float);
    REQUIRE(point2Dfloat.getX() == x_float);
    REQUIRE(point2Dfloat.getY() == y_float);
    REQUIRE(point2Dfloat.get() == std::vector<float>({x_float, y_float}));

    Point2D point2Ddouble(x_double, y_double);
    REQUIRE(point2Ddouble.getX() == x_double);
    REQUIRE(point2Ddouble.getY() == y_double);
    REQUIRE(point2Ddouble.get() == std::vector<double>({x_double, y_double}));
}

TEST_CASE("Point3D are created", "[Point3D]")
{
    int x_int(34), y_int(12), z_int(65);
    float x_float(34.45), y_float(12.34), z_float(23.43);
    double x_double(23.34), y_double(328), z_double(98.3);

    Point3D point3Dint(x_int, y_int, z_int);
    REQUIRE(point3Dint.getX() == x_int);
    REQUIRE(point3Dint.getY() == y_int);
    REQUIRE(point3Dint.getZ() == z_int);
    REQUIRE(point3Dint.get() == std::vector<int>({x_int, y_int, z_int}));

    Point3D point3Dfloat(x_float, y_float, z_float);
    REQUIRE(point3Dfloat.getX() == x_float);
    REQUIRE(point3Dfloat.getY() == y_float);
    REQUIRE(point3Dfloat.getZ() == z_float);
    REQUIRE(point3Dfloat.get() == std::vector<float>({x_float, y_float, z_float}));

    Point3D point3Ddouble(x_double, y_double, z_double);
    REQUIRE(point3Ddouble.getX() == x_double);
    REQUIRE(point3Ddouble.getY() == y_double);
    REQUIRE(point3Ddouble.getZ() == z_double);
    REQUIRE(point3Ddouble.get() == std::vector<double>({x_double, y_double, z_double}));
}

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
