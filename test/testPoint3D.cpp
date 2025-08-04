#include "../src/point3D.h"
#include <catch2/catch.hpp>
#include <vector>

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
