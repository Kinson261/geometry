#define CATCH_CONFIG_MAIN

#include "../src/point2D.h"
#include <catch2/catch.hpp>
#include <vector>
#include <string>

TEST_CASE("Point2D are created", "[Point2D]")
{
    int x_int(34), y_int(12);
    float x_float(34.45), y_float(12.34);
    double x_double(23.34), y_double(328);
    std::string x_str("x"), y_str("str");

    Point2D point2Dint(x_int, y_int);
    REQUIRE(point2Dint.getX() == x_int);
    REQUIRE(point2Dint.getY() == y_int);
    // REQUIRE(point2Dint.get() == std::vector<int>({x_int, y_int}));

    Point2D point2Dfloat(x_float, y_float);
    REQUIRE(point2Dfloat.getX() == x_float);
    REQUIRE(point2Dfloat.getY() == y_float);
    REQUIRE(point2Dfloat.get() == std::vector<float>({x_float, y_float}));

    Point2D point2Ddouble(x_double, y_double);
    REQUIRE(point2Ddouble.getX() == x_double);
    REQUIRE(point2Ddouble.getY() == y_double);
    // REQUIRE(point2Ddouble.get() == std::vector<double>({x_double, y_double}));

    // Point2D point2Dstring(x_str, y_str);
    // REQUIRE(point2Dstring.getX() == x_str);

    Point2D p2CCi(point2Dint);
    Point2D p2CCf(point2Dfloat);
    Point2D p2CCd(point2Ddouble);
    REQUIRE(p2CCi.getX() == point2Dint.getX());
    REQUIRE(p2CCi.getY() == point2Dint.getY());
    REQUIRE(p2CCf.getX() == point2Dfloat.getX());
    REQUIRE(p2CCf.getY() == point2Dfloat.getY());
    REQUIRE(p2CCd.getX() == point2Ddouble.getX());
    REQUIRE(p2CCd.getY() == point2Ddouble.getY());

    Point2D p2CAi = p2CCi;
    Point2D p2CAf = p2CCf;
    Point2D p2CAd = p2CCd;
    REQUIRE(p2CAi.getX() == p2CCi.getX());
    REQUIRE(p2CAi.getY() == p2CCi.getY());
    REQUIRE(p2CAi.get() == p2CCi.get());
    REQUIRE(p2CAf.getX() == p2CCf.getX());
    REQUIRE(p2CAf.getY() == p2CCf.getY());
    REQUIRE(p2CAf.get() == p2CCf.get());
    REQUIRE(p2CAd.getX() == p2CCd.getX());
    REQUIRE(p2CAd.getY() == p2CCd.getY());
    REQUIRE(p2CAd.get() == p2CCd.get());
}
