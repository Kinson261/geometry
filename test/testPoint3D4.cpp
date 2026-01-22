#include "../src/point3D4.h"
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE("Point3D4 are created", "[Default Constructor]")
{
    REQUIRE_NOTHROW(Point3D4<int> {});
    REQUIRE_NOTHROW(Point3D4<short int> {});
    REQUIRE_NOTHROW(Point3D4<long int> {});
    REQUIRE_NOTHROW(Point3D4<float> {});
    REQUIRE_NOTHROW(Point3D4<double> {});
    REQUIRE_NOTHROW(Point3D4<long long> {});
    REQUIRE_NOTHROW(Point3D4<long double> {});
    REQUIRE_NOTHROW(Point3D4<uint> {});

    int x_int {34};
    int y_int {12};
    int z_int {11};
    int s_int {1};
    float x_float {34.0F};
    float y_float {12.0F};
    float z_float {11.0F};
    float s_float {1.0F};
    double x_double {34.0};
    double y_double {12.0};
    double z_double {11.0};
    double s_double {1.0};

    SECTION("Point3D4<int> are created")
    {
        REQUIRE_NOTHROW(Point3D4<int> {x_int, y_int, z_int});
        REQUIRE_NOTHROW(Point3D4<int> {2, 3, 5});
        REQUIRE_NOTHROW(Point3D4 {x_int, y_int, z_int});
        REQUIRE_NOTHROW(Point3D4 {2, 3, 5});

        REQUIRE_NOTHROW(Point3D4<int> {x_int, y_int, z_int, s_int});
        REQUIRE_NOTHROW(Point3D4<int> {2, 3, 5, 1});
        REQUIRE_NOTHROW(Point3D4<int> {2, 3, 5, 2});
        REQUIRE_NOTHROW(Point3D4 {x_int, y_int, z_int, s_int});
        REQUIRE_NOTHROW(Point3D4 {2, 3, 5, 4});
    }

    SECTION("Point3D4<float> are created")
    {
        REQUIRE_NOTHROW(Point3D4<float> {x_float, y_float, z_float});
        REQUIRE_NOTHROW(Point3D4<float> {4.F, 0.5F, 1.0F});
        REQUIRE_NOTHROW(Point3D4 {x_float, y_float, z_float});
        REQUIRE_NOTHROW(Point3D4 {4.F, 0.5F, 1.0F});

        REQUIRE_NOTHROW(Point3D4<float> {x_float, y_float, z_float, s_float});
        REQUIRE_NOTHROW(Point3D4<float> {4.F, 0.5F, 1.0F, 1.0F});
        REQUIRE_NOTHROW(Point3D4<float> {4.F, 0.5F, 1.0F, 2.0F});
        REQUIRE_NOTHROW(Point3D4 {x_float, y_float, z_float, s_float});
        REQUIRE_NOTHROW(Point3D4 {4.F, 0.5F, 1.0F, 1.0F});
        REQUIRE_NOTHROW(Point3D4 {4.F, 0.5F, 1.0F, 2.0F});
    }

    SECTION("Point3D4<double> are created")
    {
        REQUIRE_NOTHROW(Point3D4<double> {x_double, y_double, z_float});
        REQUIRE_NOTHROW(Point3D4<double> {4., 0., 2.});
        REQUIRE_NOTHROW(Point3D4 {x_double, y_double, z_double});
        REQUIRE_NOTHROW(Point3D4 {4., 0., 2.});

        REQUIRE_NOTHROW(Point3D4<double> {x_double, y_double, z_float, s_double});
        REQUIRE_NOTHROW(Point3D4<double> {4., 0., 2., 1.});
        REQUIRE_NOTHROW(Point3D4<double> {4., 0., 2., 3.});
        REQUIRE_NOTHROW(Point3D4 {x_double, y_double, z_double, s_double});
        REQUIRE_NOTHROW(Point3D4 {4., 0., 2., 1.});
        REQUIRE_NOTHROW(Point3D4 {4., 0., 2., 3.});
    }
}

TEST_CASE("Copy constructor and assignment of Point3D4", "[Copy constructor]")
{
    SECTION("Point3D4<int> are copied using copy constructor and copy assignment")
    {
        int x_int = 31;
        int y_int = 32;
        int z_int = 33;
        int s_int = 1;
        Point3D4 point3D1 {x_int, y_int, z_int, s_int};
        Point3D4<int> point3D2;

        REQUIRE_NOTHROW(point3D2 == point3D1);
        REQUIRE_NOTHROW(point3D2 == point3D2);
        REQUIRE_NOTHROW(Point3D4<int> (point3D1));
        REQUIRE_NOTHROW(Point3D4<int> {point3D1});

        point3D2 = point3D1;
        Point3D4 point3D3 (point3D1);
        Point3D4 point3D4 {point3D1};

        REQUIRE(point3D2.get() == std::array<int, 4> {x_int, y_int, z_int, s_int});
        REQUIRE(point3D3.get() == std::array<int, 4> {x_int, y_int, z_int, s_int});
        REQUIRE(point3D4.get() == std::array<int, 4> {x_int, y_int, z_int, s_int});
    }


    SECTION("Point3D4<float> are copied using copy constructor and copy assignment")
    {
        float x_float = 31.0F;
        float y_float = 32.0F;
        float z_float = 33.0F;
        Point3D4 point3D1 {x_float, y_float, z_float};
        Point3D4<float> point3D2;

        REQUIRE_NOTHROW(point3D2 = point3D1);
        REQUIRE_NOTHROW(point3D2 = point3D2);
        REQUIRE_NOTHROW(Point3D4<float> (point3D1));
        REQUIRE_NOTHROW(Point3D4<float> {point3D1});

        point3D2 = point3D1;
        Point3D4 point3D3 (point3D1);
        Point3D4 point3D4 {point3D1};
        REQUIRE(point3D2.get() == std::array<float, 4> {x_float, y_float, z_float, 1.0F});
        REQUIRE(point3D3.get() == std::array<float, 4> {x_float, y_float, z_float, 1.0F});
        REQUIRE(point3D4.get() == std::array<float, 4> {x_float, y_float, z_float, 1.0F});
    }

    SECTION("Point3D4<double> are copied using copy constructor and copy assignment")
    {
        double x_double = 31.;
        double y_double = 32.;
        double z_double = 33.;
        double s_double = 1.;
        Point3D4 point3D1 {x_double, y_double, z_double, s_double};
        Point3D4<double> point3D2;

        REQUIRE_NOTHROW(point3D2 = point3D1);
        REQUIRE_NOTHROW(point3D2 = point3D2);
        REQUIRE_NOTHROW(Point3D4<double> (point3D1));
        REQUIRE_NOTHROW(Point3D4<double> {point3D1});

        point3D2 = point3D1;
        Point3D4 point3D3 (point3D1);
        Point3D4 point3D4 {point3D1};
        REQUIRE(point3D2.get() == std::array<double, 4> {x_double, y_double, z_double, s_double});
        REQUIRE(point3D3.get() == std::array<double, 4> {x_double, y_double, z_double, s_double});
        REQUIRE(point3D4.get() == std::array<double, 4> {x_double, y_double, z_double, s_double});
    }
}

TEST_CASE("Poind 3D4 arithmetic functions are checked", "[Point3D4 arithmetic]")
{
    Point3D4<int> pi1 {2, 3, 4};
    Point3D4<int> pi2 {5, 6, 7};
    Point3D4<int> pira = pi1 + pi2;
    Point3D4<int> pirs = pi1 - pi2;
    REQUIRE(pira.get() == std::array<int, 4> {7, 9, 11, 1});
    REQUIRE(pirs.get() == std::array<int, 4> {-3, -3, -3, 1});

    Point3D4<float> pf1 {2, 3, 4};
    Point3D4<float> pf2 {5, 6, 7};
    Point3D4<float> pfra = pf1 + pf2;
    Point3D4<float> pfrs = pf1 - pf2;
    REQUIRE(pfra.get() == std::array<float, 4> {7, 9, 11, 1});
    REQUIRE(pfrs.get() == std::array<float, 4> {-3, -3, -3, 1});

    Point3D4<double> pd1 {2., 3., 4.};
    Point3D4<double> pd2 {5., 6., 7.};
    Point3D4<double> pdra = pd1 + pd2;
    Point3D4<double> pdrs = pd1 - pd2;
    REQUIRE(pdra.get() == std::array<double, 4> {7, 9, 11, 1});
    REQUIRE(pdrs.get() == std::array<double, 4> {-3, -3, -3, 1});


    Point3D4<int> pi3 {2, 3, 4, 1};
    Point3D4<int> pi4 {5, 6, 7, 1};
    Point3D4<int> pira2 = pi3 + pi4;
    Point3D4<int> pirs2 = pi3 - pi4;
    REQUIRE(pira2.get() == std::array<int, 4> {7, 9, 11, 1});
    REQUIRE(pirs2.get() == std::array<int, 4> {-3, -3, -3, 1});

    Point3D4<float> pf3 {2, 3, 4, 1};
    Point3D4<float> pf4 {5, 6, 7, 1};
    Point3D4<float> pfra2 = pf3 + pf4;
    Point3D4<float> pfrs2 = pf3 - pf4;
    REQUIRE(pfra2.get() == std::array<float, 4> {7, 9, 11, 1});
    REQUIRE(pfrs2.get() == std::array<float, 4> {-3, -3, -3, 1});

    Point3D4<double> pd3 {2., 3., 4., 3};
    Point3D4<double> pd4 {5., 6., 7., 4};
    REQUIRE_THROWS(pd3 + pd4);
    REQUIRE_THROWS(pd3 - pd4);

    Point3D4<int> pi5 {2, 3, 4, 1};
    Point3D4<int> pi6 {5, 6, 7, 4};
    REQUIRE_THROWS(pi5 + pi6);
    REQUIRE_THROWS(pi5 - pi6);

    Point3D4<float> pf5 {2, 3, 4, 5};
    Point3D4<float> pf6 {5, 6, 7, 1};
    REQUIRE_THROWS(pf5 + pf6);
    REQUIRE_THROWS(pf5 - pf6);

    Point3D4<double> pd5 {2., 3., 4., 6};
    Point3D4<double> pd6 {5., 6., 7., 8};
    REQUIRE_THROWS(pd5 + pd6);
    REQUIRE_THROWS(pd5 - pd6);
}

TEST_CASE("Set function is being tested", "[Set]")
{
    SECTION("Set <int> value for Point3D4")
    {
        Point3D4<int> pt1;
        SECTION("Arguments are values")
        {
            pt1.set(32, 43, 3, 5);
            REQUIRE(pt1.get() == std::array<int, 4> {32, 43, 3, 5});
        }
        SECTION("With axis")
        {
            pt1.set(Axis::X, 17);
            pt1.set(Axis::Y, 13);
            pt1.set(Axis::Z, 15);
            pt1.set(Axis::S, 19);
            REQUIRE(pt1.get() == std::array<int, 4> {17, 13, 15, 19});
        }
    }

    SECTION("Set <float> value for Point3D4")
    {
        Point3D4<float> pt1;
        SECTION("Arguments are values")
        {
            pt1.set(32.0F, 43.0F, 2.0F, 3);
            REQUIRE(pt1.get() == std::array<float, 4> {32, 43, 2, 3});
        }
        SECTION("With axis")
        {
            pt1.set(Axis::X, 17.0F);
            pt1.set(Axis::Y, 13.0F);
            pt1.set(Axis::Z, 3.0F);
            pt1.set(Axis::S, 2.0F);
            REQUIRE(pt1.get() == std::array<float, 4> {17, 13, 3, 2});
        }
    }

    SECTION("Set <double> value for Point3D4")
    {
        Point3D4<double> pt1;
        SECTION("Arguments are values")
        {
            pt1.set(32., 43., 8., 2);
            REQUIRE(pt1.get() == std::array<double, 4> {32, 43, 8, 2});
        }
        SECTION("With axis")
        {
            pt1.set(Axis::X, 17.);
            pt1.set(Axis::Y, 13.);
            pt1.set(Axis::Z, 82.);
            pt1.set(Axis::S, 4.);
            REQUIRE(pt1.get() == std::array<double, 4> {17, 13, 82, 4});
        }
    }
}

TEST_CASE("Point3D4 equality check is tested", "[Point3D4 equality]")
{
    Point3D4<int> pt1 {23, 45, 67};
    Point3D4<float> pt2 {23.f, 45.f, 67.f};
    Point3D4<double> pt3 {23., 45., 67.};

    Point3D4<int> pt1s {23, 45, 67, 1};
    Point3D4<float> pt2s {23.f, 45.f, 67.f, 1.f};
    Point3D4<double> pt3s {23., 45., 67., 1.};

    Point3D4<int> pt1sw {23, 45, 67, 4};
    Point3D4<float> pt2sw {23.f, 45.f, 67.f, 5.f};
    Point3D4<double> pt3sw {23., 45., 67., 6.};

    REQUIRE(pt1.get().at(0) == pt2.get().at(0));
    REQUIRE(pt1.get().at(1) == pt2.get().at(1));
    REQUIRE(pt1.get().at(2) == pt2.get().at(2));
    REQUIRE(pt1.get().at(3) == pt2.get().at(3));
    REQUIRE(pt1.get().at(0) == pt3.get().at(0));
    REQUIRE(pt1.get().at(1) == pt3.get().at(1));
    REQUIRE(pt1.get().at(2) == pt3.get().at(2));
    REQUIRE(pt1.get().at(3) == pt3.get().at(3));
    REQUIRE(pt2.get().at(0) == pt3.get().at(0));
    REQUIRE(pt2.get().at(1) == pt3.get().at(1));
    REQUIRE(pt2.get().at(2) == pt3.get().at(2));
    REQUIRE(pt2.get().at(3) == pt3.get().at(3));

    REQUIRE(pt1s.get().at(0) == pt2s.get().at(0));
    REQUIRE(pt1s.get().at(1) == pt2s.get().at(1));
    REQUIRE(pt1s.get().at(2) == pt2s.get().at(2));
    REQUIRE(pt1s.get().at(3) == pt2s.get().at(3));
    REQUIRE(pt1s.get().at(0) == pt3s.get().at(0));
    REQUIRE(pt1s.get().at(1) == pt3s.get().at(1));
    REQUIRE(pt1s.get().at(2) == pt3s.get().at(2));
    REQUIRE(pt1s.get().at(3) == pt3s.get().at(3));
    REQUIRE(pt2s.get().at(0) == pt3s.get().at(0));
    REQUIRE(pt2s.get().at(1) == pt3s.get().at(1));
    REQUIRE(pt2s.get().at(2) == pt3s.get().at(2));
    REQUIRE(pt2s.get().at(3) == pt3s.get().at(3));

    REQUIRE(pt1sw.get().at(0) == pt2sw.get().at(0));
    REQUIRE(pt1sw.get().at(1) == pt2sw.get().at(1));
    REQUIRE(pt1sw.get().at(2) == pt2sw.get().at(2));
    REQUIRE(pt1sw.get().at(3) != pt2sw.get().at(3));
    REQUIRE(pt1sw.get().at(0) == pt3sw.get().at(0));
    REQUIRE(pt1sw.get().at(1) == pt3sw.get().at(1));
    REQUIRE(pt1sw.get().at(2) == pt3sw.get().at(2));
    REQUIRE(pt1sw.get().at(3) != pt3sw.get().at(3));
    REQUIRE(pt2sw.get().at(0) == pt3sw.get().at(0));
    REQUIRE(pt2sw.get().at(1) == pt3sw.get().at(1));
    REQUIRE(pt2sw.get().at(2) == pt3sw.get().at(2));
    REQUIRE(pt2sw.get().at(3) != pt3sw.get().at(3));
}

TEST_CASE("Arithmetic operations", "[Point3D4]")
{
    Point3D4<int> pt1 {2, 3, 4};
    Point3D4<float> pt2 {3.F, 4.F, 5.F};
    Point3D4<double> pt3 {8., 9., 10.};

    SECTION("Addition")
    {
        REQUIRE_NOTHROW(Point3D4(pt1 + pt2));
        REQUIRE_NOTHROW(Point3D4(pt1 + pt3));
        REQUIRE_NOTHROW(Point3D4(pt2 + pt3));
        REQUIRE(Point3D4(pt1 + pt2).get() == std::array<float, 4> {5, 7, 9, 1});
        REQUIRE(Point3D4(pt1 + pt3).get() == std::array<double, 4> {10, 12, 14, 1});
        REQUIRE(Point3D4(pt2 + pt3).get() == std::array<double, 4> {11, 13, 15, 1});
    }

    SECTION("Subtraction")
    {
        REQUIRE_NOTHROW(Point3D4(pt1 - pt2));
        REQUIRE_NOTHROW(Point3D4(pt1 - pt3));
        REQUIRE_NOTHROW(Point3D4(pt2 - pt3));
        REQUIRE(Point3D4(pt1 - pt2).get() == std::array<float, 4> {-1, -1, -1, 1});
        REQUIRE(Point3D4(pt1 - pt3).get() == std::array<double, 4> {-6, -6, -6, 1});
        REQUIRE(Point3D4(pt2 - pt3).get() == std::array<double, 4> {-5, -5, -5, 1});
    }

    SECTION("Multiplication")
    {
        REQUIRE_NOTHROW(Point3D4(pt1 * 10));
        REQUIRE_NOTHROW(Point3D4(pt1 * 10));
        REQUIRE_NOTHROW(Point3D4(pt2 * 10));
        REQUIRE(Point3D4(pt1 * 3).get() == std::array<int, 4> {6, 9, 12, 1});
        REQUIRE(Point3D4(pt2 * 3).get() == std::array<float, 4> {9, 12, 15, 1});
        REQUIRE(Point3D4(pt3 * 3).get() == std::array<double, 4> {24, 27, 30, 1});
    }

    SECTION("Division")
    {
        REQUIRE_THROWS(Point3D4(pt1/0));
        REQUIRE_THROWS(Point3D4(pt2/0));
        REQUIRE_THROWS(Point3D4(pt3/0));
        REQUIRE_NOTHROW(Point3D4(pt1 / 10));
        REQUIRE_NOTHROW(Point3D4(pt1 / 10));
        REQUIRE_NOTHROW(Point3D4(pt2 / 10));
        REQUIRE(Point3D4(pt1 / 3).get() == std::array<int, 4> {2/3, 3/3, 4/3, 1});
        REQUIRE(Point3D4(pt2 / 3).get() == std::array<float, 4> {3./3, 4./3, 5./3, 1});
        REQUIRE(Point3D4(pt3 / 3).get() == std::array<double, 4> {8./3, 9./3, 10./3, 1});
    }
}
