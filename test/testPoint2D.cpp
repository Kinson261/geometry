#define CATCH_CONFIG_MAIN
#include "../src/point2D.h"
#include <catch2/catch.hpp>

TEST_CASE("Point2D are created", "[Point2D creation]")
{
    int x_int(34), y_int(12);
    Point2D<int> pt_d {x_int, y_int};
}

TEST_CASE("Copy constructor and assignment operator with different types of data", "[Point2D]")
{
    Point2D point2Dint(34, 12);
    Point2D point2Dfloat = point2Dint;
    Point2D point2Ddouble(point2Dint);
}

TEST_CASE("Equality operator with different types of data", "[Point2D]")
{
    Point2D point2Dint(34, 12);
    Point2D point2Dfloat(34.0f, 12.0f);
    Point2D point2Ddouble(34.0, 12.0);
}

TEST_CASE("Arithmetic operations", "[Point2D]")
{
    Point2D<int> p1(5, 10);
    Point2D<int> p2(3, 4);
}

TEST_CASE("Edge cases", "[Point2D]")
{
    Point2D<int> zero(0, 0);
    Point2D<int> negative(-5, -10);
    Point2D<int> max(std::numeric_limits<int>::max(), std::numeric_limits<int>::max());
    Point2D<int> min(std::numeric_limits<int>::min(), std::numeric_limits<int>::min());
}

// TEST_CASE("Type conversion", "[Point2D]") {
//     Point2D<int> p_int(5, 10);
//     Point2D<float> p_float = p_int;

//     REQUIRE(p_float.getX() == Approx(5.0f));
//     REQUIRE(p_float.getY() == Approx(10.0f));

//     Point2D<double> p_double = p_int;
//     REQUIRE(p_double.getX() == Approx(5.0));
//     REQUIRE(p_double.getY() == Approx(10.0));
// }

TEST_CASE("Stream output", "[Point2D]")
{
    Point2D<int> p(5, 10);
    std::ostringstream oss;
    oss << p;

    REQUIRE(oss.str() == "Point2D(5, 10)");
}
