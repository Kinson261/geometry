#include <array>
#include <stdexcept>
#define CATCH_CONFIG_MAIN
#include "../src/point2D.h"
#include <catch2/catch.hpp>

TEST_CASE("Point2D are created", "[Default Constructor]")
{
    SECTION("Point2D of many points are created")
    {
        REQUIRE_NOTHROW(Point2D<int> {});
        REQUIRE_NOTHROW(Point2D<short int> {});
        REQUIRE_NOTHROW(Point2D<long int> {});
        REQUIRE_NOTHROW(Point2D<float> {});
        REQUIRE_NOTHROW(Point2D<double> {});
        REQUIRE_NOTHROW(Point2D<long long> {});
        REQUIRE_NOTHROW(Point2D<long double> {});
        REQUIRE_NOTHROW(Point2D<uint> {});
    }

    int x_int {34};
    int y_int {12};
    float x_float {34.0F};
    float y_float {12.0F};
    double x_double {34.0};
    double y_double {12.0};

    SECTION("Point2D<int> are created")
    {
        REQUIRE_NOTHROW(Point2D<int> {x_int, y_int});
        REQUIRE_NOTHROW(Point2D<int> {2, 3});
        REQUIRE_NOTHROW(Point2D {x_int, y_int});
        REQUIRE_NOTHROW(Point2D {2, 3});
    }

    SECTION("Point2D<float> are created")
    {
        REQUIRE_NOTHROW(Point2D<float> {x_float, y_float});
        REQUIRE_NOTHROW(Point2D<float> {4.F, 0.5F});
        REQUIRE_NOTHROW(Point2D {x_float, y_float});
        REQUIRE_NOTHROW(Point2D {4.F, 0.5F});
    }

    SECTION("Point2D<double> are created")
    {
        REQUIRE_NOTHROW(Point2D<double> {x_double, y_double});
        REQUIRE_NOTHROW(Point2D<double> {4., 0.});
        REQUIRE_NOTHROW(Point2D {x_double, y_double});
        REQUIRE_NOTHROW(Point2D {4., 0.});
    }
}

TEST_CASE("Copy constructor and assignment of Point2D", "[Copy constructor]")
{
    SECTION("Point2D<int> are copied using copy constructor and copy assignment")
    {
        int x_int = 31;
        int y_int = 32;
        Point2D point2Dint1 {x_int, y_int};
        Point2D<int> point2Dint2;

        REQUIRE_NOTHROW(point2Dint2 == point2Dint1);
        REQUIRE_NOTHROW(point2Dint2 == point2Dint2);
        REQUIRE_NOTHROW(Point2D<int>(point2Dint1));
        REQUIRE_NOTHROW(Point2D<int> {point2Dint1});

        point2Dint2 = point2Dint1;
        Point2D point2Dint3(point2Dint1);
        Point2D point2Dint4 {point2Dint1};
    
        REQUIRE(point2Dint2.get() == std::array<int, 2>{x_int,y_int});
        REQUIRE(point2Dint3.get() == std::array<int, 2>{x_int,y_int});
        REQUIRE(point2Dint4.get() == std::array<int, 2>{x_int,y_int});
    }


    SECTION("Point2D<float> are copied using copy constructor and copy assignment")
    {
        float x_float = 31.0F;
        float y_float = 32.0F;
        Point2D point2Dfloat1 {x_float, y_float};
        Point2D<float> point2Dfloat2;

        REQUIRE_NOTHROW(point2Dfloat2 = point2Dfloat1);
        REQUIRE_NOTHROW(point2Dfloat2 = point2Dfloat2);
        REQUIRE_NOTHROW(Point2D<float>(point2Dfloat1));
        REQUIRE_NOTHROW(Point2D<float> {point2Dfloat1});

        point2Dfloat2 = point2Dfloat1;
        Point2D point2Dfloat3(point2Dfloat1);
        Point2D point2Dfloat4 {point2Dfloat1};
        REQUIRE(point2Dfloat2.get() == std::array<float, 2> {x_float, y_float});
        REQUIRE(point2Dfloat3.get() == std::array<float, 2> {x_float, y_float});
        REQUIRE(point2Dfloat4.get() == std::array<float, 2> {x_float, y_float});
    }

    SECTION("Point2D<double> are copied using copy constructor and copy assignment")
    {
        double x_double = 31.;
        double y_double = 32.;
        Point2D point2Ddouble1 {x_double, y_double};
        Point2D<double> point2Ddouble2;

        REQUIRE_NOTHROW(point2Ddouble2 = point2Ddouble1);
        REQUIRE_NOTHROW(point2Ddouble2 = point2Ddouble2);
        REQUIRE_NOTHROW(Point2D<double>(point2Ddouble1));
        REQUIRE_NOTHROW(Point2D<double> {point2Ddouble1});

        point2Ddouble2 = point2Ddouble1;
        Point2D point2Ddouble3(point2Ddouble1);
        Point2D point2Ddouble4 {point2Ddouble1};
        REQUIRE(point2Ddouble2.get() == std::array<double, 2> {x_double, y_double});
        REQUIRE(point2Ddouble3.get() == std::array<double, 2> {x_double, y_double});
        REQUIRE(point2Ddouble4.get() == std::array<double, 2> {x_double, y_double});
    }
}

TEST_CASE("Set function is being tested", "[Set]")
{
    SECTION("Set <int> value for Point2D")
    {
        Point2D<int> pt1;
        SECTION("Arguments are values")
        {
            pt1.set(32, 43);
            REQUIRE(pt1.get() == std::array<int, 2> {32, 43});
        }
        SECTION("With axis")
        {
            pt1.set(Axis::X, 17);
            pt1.set(Axis::Y, 13);
            REQUIRE(pt1.get() == std::array<int, 2> {17, 13});
            REQUIRE_THROWS_AS(pt1.set(Axis::Z, 54), std::invalid_argument);
            REQUIRE_THROWS_AS(pt1.set(Axis::S, 54), std::invalid_argument);
        }
    }

    SECTION("Set <float> value for Point2D")
    {
        Point2D<float> pt1;
        SECTION("Arguments are values")
        {
            pt1.set(32.0F, 43.0F);
            REQUIRE(pt1.get() == std::array<float, 2> {32, 43});
        }
        SECTION("With axis")
        {
            pt1.set(Axis::X, 17.0F);
            pt1.set(Axis::Y, 13.0F);
            REQUIRE(pt1.get() == std::array<float, 2> {17, 13});
            REQUIRE_THROWS_AS(pt1.set(Axis::Z, 54), std::invalid_argument);
            REQUIRE_THROWS_AS(pt1.set(Axis::S, 54), std::invalid_argument);
        }
    }

    SECTION("Set <double> value for Point2D")
    {
        Point2D<double> pt1;
        SECTION("Arguments are values")
        {
            pt1.set(32.0, 43.0);
            REQUIRE(pt1.get() == std::array<double, 2> {32, 43});
        }
        SECTION("With axis")
        {
            pt1.set(Axis::X, 17.0F);
            pt1.set(Axis::Y, 13.0F);
            REQUIRE(pt1.get() == std::array<double, 2> {17, 13});
            REQUIRE_THROWS_AS(pt1.set(Axis::Z, 54), std::invalid_argument);
            REQUIRE_THROWS_AS(pt1.set(Axis::S, 54), std::invalid_argument);
        }
    }
}

TEST_CASE("Equality operator with different types of data", "[Point2D]")
{
    Point2D point2Dint(34, 12);
    Point2D point2Dfloat(34.0f, 12.0f);
    Point2D point2Ddouble(34.0, 12.0);
}

TEST_CASE("Arithmetic operations", "[Point2D]")
{
    Point2D<int> pt1 {2, 3};
    Point2D<float> pt2 {3.F, 4.F};
    Point2D<double> pt3 {8., 9.};

    SECTION("Addition")
    {
        REQUIRE_NOTHROW(Point2D(pt1 + pt2));
        REQUIRE_NOTHROW(Point2D(pt1 + pt3));
        REQUIRE_NOTHROW(Point2D(pt2 + pt3));
        REQUIRE(Point2D(pt1 + pt2).get() == std::array<float, 2> {5, 7});
        REQUIRE(Point2D(pt1 + pt3).get() == std::array<double, 2> {10, 12});
        REQUIRE(Point2D(pt2 + pt3).get() == std::array<double, 2> {11, 13});
    }

    SECTION("Subtraction")
    {
        REQUIRE_NOTHROW(Point2D(pt1 - pt2));
        REQUIRE_NOTHROW(Point2D(pt1 - pt3));
        REQUIRE_NOTHROW(Point2D(pt2 - pt3));
        REQUIRE(Point2D(pt1 - pt2).get() == std::array<float, 2> {-1, -1});
        REQUIRE(Point2D(pt1 - pt3).get() == std::array<double, 2> {-6, -6});
        REQUIRE(Point2D(pt2 - pt3).get() == std::array<double, 2> {-5, -5});
    }

    SECTION("Multiplication")
    {
        REQUIRE_NOTHROW(Point2D(pt1 * 10));
        REQUIRE_NOTHROW(Point2D(pt1 * 10));
        REQUIRE_NOTHROW(Point2D(pt2 * 10));
        REQUIRE((pt1 * 3).get() == std::array<int, 2> {6, 9});
        REQUIRE((pt2 * 3).get() == std::array<float, 2> {9, 12});
        REQUIRE((pt3 * 3).get() == std::array<double, 2> {24, 27});
    }

    SECTION("Division")
    {
        REQUIRE_THROWS(Point2D(pt1/0));
        REQUIRE_THROWS(Point2D(pt2/0));
        REQUIRE_THROWS(Point2D(pt3/0));
        REQUIRE_NOTHROW(Point2D(pt1 / 10));
        REQUIRE_NOTHROW(Point2D(pt1 / 10));
        REQUIRE_NOTHROW(Point2D(pt2 / 10));
        REQUIRE((pt1 / 3).get() == std::array<int, 2> {0, 1});
        REQUIRE((pt2 / 3).get() == std::array<float, 2> {1, 4. / 3});
        REQUIRE((pt3 / 3).get() == std::array<double, 2> {8. / 3, 3});
    }
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
