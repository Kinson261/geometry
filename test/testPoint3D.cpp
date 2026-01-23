#include "../src/point3D.h"
#define CATCH_CONFIG_MAIN
#include <array>
#include <catch2/catch.hpp>
#include <sys/types.h>

TEST_CASE("Point3D are created", "[Defaut Constructor]")
{
    REQUIRE_NOTHROW(Point3D<int> {});
    REQUIRE_NOTHROW(Point3D<short int> {});
    REQUIRE_NOTHROW(Point3D<long int> {});
    REQUIRE_NOTHROW(Point3D<float> {});
    REQUIRE_NOTHROW(Point3D<double> {});
    REQUIRE_NOTHROW(Point3D<long long> {});
    REQUIRE_NOTHROW(Point3D<long double> {});
    REQUIRE_NOTHROW(Point3D<uint> {});

    int x_int {34};
    int y_int {12};
    int z_int {1};
    float x_float {34.0F};
    float y_float {12.0F};
    float z_float {1.0F};
    double x_double {34.0};
    double y_double {12.0};
    double z_double {1.0};

    SECTION("Point3D<int> are created")
    {
        REQUIRE_NOTHROW(Point3D<int> {x_int, y_int, z_int});
        REQUIRE_NOTHROW(Point3D<int> {2, 3, 5});
        REQUIRE_NOTHROW(Point3D {x_int, y_int, z_int});
        REQUIRE_NOTHROW(Point3D {2, 3, 5});
    }

    SECTION("Point3D<float> are created")
    {
        REQUIRE_NOTHROW(Point3D<float> {x_float, y_float, z_float});
        REQUIRE_NOTHROW(Point3D<float> {4.F, 0.5F, 1.0F});
        REQUIRE_NOTHROW(Point3D {x_float, y_float, z_float});
        REQUIRE_NOTHROW(Point3D {4.F, 0.5F, 1.0F});
    }

    SECTION("Point3D<double> are created")
    {
        REQUIRE_NOTHROW(Point3D<double> {x_double, y_double, z_float});
        REQUIRE_NOTHROW(Point3D<double> {4., 0., 2.});
        REQUIRE_NOTHROW(Point3D {x_double, y_double, z_double});
        REQUIRE_NOTHROW(Point3D {4., 0., 2.});
    }
}

TEST_CASE("Copy constructor and assignment of Point3D", "[Copy constructor]")
{
    SECTION("Point3D<int> are copied using copy constructor and copy assignment")
    {
        int x_int = 31;
        int y_int = 32;
        int z_int = 33;
        Point3D point3D1 {x_int, y_int, z_int};
        Point3D<int> point3D2;

        REQUIRE_NOTHROW(point3D2 == point3D1);
        REQUIRE_NOTHROW(point3D2 == point3D2);
        REQUIRE_NOTHROW(Point3D<int>(point3D1));
        REQUIRE_NOTHROW(Point3D<int> {point3D1});

        point3D2 = point3D1;
        Point3D point3D3(point3D1);
        Point3D point3D4 {point3D1};

        REQUIRE(point3D2.get() == std::array<int, 3> {x_int, y_int, z_int});
        REQUIRE(point3D3.get() == std::array<int, 3> {x_int, y_int, z_int});
        REQUIRE(point3D4.get() == std::array<int, 3> {x_int, y_int, z_int});
    }


    SECTION("Point3D<float> are copied using copy constructor and copy assignment")
    {
        float x_float = 31.0F;
        float y_float = 32.0F;
        float z_float = 33.0F;
        Point3D point3D1 {x_float, y_float, z_float};
        Point3D<float> point3D2;

        REQUIRE_NOTHROW(point3D2 = point3D1);
        REQUIRE_NOTHROW(point3D2 = point3D2);
        REQUIRE_NOTHROW(Point3D<float>(point3D1));
        REQUIRE_NOTHROW(Point3D<float> {point3D1});

        point3D2 = point3D1;
        Point3D point3D3(point3D1);
        Point3D point3D4 {point3D1};
        REQUIRE(point3D2.get() == std::array<float, 3> {x_float, y_float, z_float});
        REQUIRE(point3D3.get() == std::array<float, 3> {x_float, y_float, z_float});
        REQUIRE(point3D4.get() == std::array<float, 3> {x_float, y_float, z_float});
    }

    SECTION("Point3D<double> are copied using copy constructor and copy assignment")
    {
        double x_double = 31.;
        double y_double = 32.;
        double z_double = 33.;
        Point3D point3D1 {x_double, y_double, z_double};
        Point3D<double> point3D2;

        REQUIRE_NOTHROW(point3D2 = point3D1);
        REQUIRE_NOTHROW(point3D2 = point3D2);
        REQUIRE_NOTHROW(Point3D<double>(point3D1));
        REQUIRE_NOTHROW(Point3D<double> {point3D1});

        point3D2 = point3D1;
        Point3D point3D3(point3D1);
        Point3D point3D4 {point3D1};
        REQUIRE(point3D2.get() == std::array<double, 3> {x_double, y_double, z_double});
        REQUIRE(point3D3.get() == std::array<double, 3> {x_double, y_double, z_double});
        REQUIRE(point3D4.get() == std::array<double, 3> {x_double, y_double, z_double});
    }
}

TEST_CASE("Poind 3D arithmetic functions are checked", "[Point3D arithmetic]")
{
    Point3D<int> pi1 {2, 3, 4};
    Point3D<int> pi2 {5, 6, 7};
    Point3D<int> pira = pi1 + pi2;
    Point3D<int> pirs = pi1 - pi2;

    REQUIRE(pira.get() == std::array<int, 3> {7, 9, 11});
    REQUIRE(pirs.get() == std::array<int, 3> {-3, -3, -3});

    Point3D<float> pf1 {2, 3, 4};
    Point3D<float> pf2 {5, 6, 7};
    Point3D<float> pfra = pf1 + pf2;
    Point3D<float> pfrs = pf1 - pf2;

    REQUIRE(pfra.get() == std::array<float, 3> {7, 9, 11});
    REQUIRE(pfrs.get() == std::array<float, 3> {-3, -3, -3});

    Point3D<double> pd1 {2., 3., 4.};
    Point3D<double> pd2 {5., 6., 7.};
    Point3D<double> pdra = pd1 + pd2;
    Point3D<double> pdrs = pd1 - pd2;

    REQUIRE(pdra.get() == std::array<double, 3> {7, 9, 11});
    REQUIRE(pdrs.get() == std::array<double, 3> {-3, -3, -3});
}

TEST_CASE("Set function is being tested", "[Set]")
{
    SECTION("Set <int> value for Point3D")
    {
        Point3D<int> pt1;
        SECTION("Arguments are values")
        {
            pt1.set(32, 43, 3);
            REQUIRE(pt1.get() == std::array<int, 3> {32, 43, 3});
        }
        SECTION("With axis")
        {
            pt1.set(Axis::X, 17);
            pt1.set(Axis::Y, 13);
            pt1.set(Axis::Z, 15);
            REQUIRE(pt1.get() == std::array<int, 3> {17, 13, 15});
            REQUIRE_THROWS_AS(pt1.set(Axis::S, 54), std::invalid_argument);
        }
    }

    SECTION("Set <float> value for Point3D")
    {
        Point3D<float> pt1;
        SECTION("Arguments are values")
        {
            pt1.set(32.0F, 43.0F, 2.0F);
            REQUIRE(pt1.get() == std::array<float, 3> {32, 43, 2});
        }
        SECTION("With axis")
        {
            pt1.set(Axis::X, 17.0F);
            pt1.set(Axis::Y, 13.0F);
            pt1.set(Axis::Z, 3.0F);
            REQUIRE(pt1.get() == std::array<float, 3> {17, 13, 3});
            REQUIRE_THROWS_AS(pt1.set(Axis::S, 54), std::invalid_argument);
        }
    }

    SECTION("Set <double> value for Point3D")
    {
        Point3D<double> pt1;
        SECTION("Arguments are values")
        {
            pt1.set(32., 43., 8.);
            REQUIRE(pt1.get() == std::array<double, 3> {32, 43, 8});
        }
        SECTION("With axis")
        {
            pt1.set(Axis::X, 17.);
            pt1.set(Axis::Y, 13.);
            pt1.set(Axis::Z, 82.);
            REQUIRE(pt1.get() == std::array<double, 3> {17, 13, 82});
            REQUIRE_THROWS_AS(pt1.set(Axis::S, 54), std::invalid_argument);
        }
    }
}

TEST_CASE("Point3d equality check is tested", "[Point3D equality]")
{
    Point3D<int> pt1 {23, 45, 67};
    Point3D<float> pt2 {23, 45, 67};
    Point3D<double> pt3 {23, 45, 67};

    REQUIRE(pt1.get().at(0) == pt2.get().at(0));
    REQUIRE(pt1.get().at(1) == pt2.get().at(1));
    REQUIRE(pt1.get().at(2) == pt2.get().at(2));

    // REQUIRE(pt1.get() == pt3.get());
    REQUIRE(pt1.get().at(0) == pt3.get().at(0));
    REQUIRE(pt1.get().at(1) == pt3.get().at(1));
    REQUIRE(pt1.get().at(2) == pt3.get().at(2));

    // REQUIRE(pt2.get() == pt3.get());
    REQUIRE(pt2.get().at(0) == pt3.get().at(0));
    REQUIRE(pt2.get().at(1) == pt3.get().at(1));
    REQUIRE(pt2.get().at(2) == pt3.get().at(2));
}

TEST_CASE("Arithmetic operations", "[Point3D]")
{
    Point3D<int> pt1 {2, 3, 4};
    Point3D<float> pt2 {3.F, 4.F, 5.F};
    Point3D<double> pt3 {8., 9., 10.};

    SECTION("Addition")
    {
        REQUIRE_NOTHROW(Point3D(pt1 + pt2));
        REQUIRE_NOTHROW(Point3D(pt1 + pt3));
        REQUIRE_NOTHROW(Point3D(pt2 + pt3));
        REQUIRE(Point3D(pt1 + pt2).get() == std::array<float, 3> {5, 7, 9});
        REQUIRE(Point3D(pt1 + pt3).get() == std::array<double, 3> {10, 12, 14});
        REQUIRE(Point3D(pt2 + pt3).get() == std::array<double, 3> {11, 13, 15});
    }

    SECTION("Subtraction")
    {
        REQUIRE_NOTHROW(Point3D(pt1 - pt2));
        REQUIRE_NOTHROW(Point3D(pt1 - pt3));
        REQUIRE_NOTHROW(Point3D(pt2 - pt3));
        REQUIRE(Point3D(pt1 - pt2).get() == std::array<float, 3> {-1, -1, -1});
        REQUIRE(Point3D(pt1 - pt3).get() == std::array<double, 3> {-6, -6, -6});
        REQUIRE(Point3D(pt2 - pt3).get() == std::array<double, 3> {-5, -5, -5});
    }

    SECTION("Multiplication")
    {
        REQUIRE_NOTHROW(Point3D(pt1 * 10));
        REQUIRE_NOTHROW(Point3D(pt1 * 10));
        REQUIRE_NOTHROW(Point3D(pt2 * 10));
        REQUIRE(Point3D(pt1 * 3).get() == std::array<int, 3> {6, 9, 12});
        REQUIRE(Point3D(pt2 * 3).get() == std::array<float, 3> {9, 12, 15});
        REQUIRE(Point3D(pt3 * 3).get() == std::array<double, 3> {24, 27, 30});
    }

    SECTION("Division")
    {
        REQUIRE_THROWS(Point3D(pt1 / 0));
        REQUIRE_THROWS(Point3D(pt2 / 0));
        REQUIRE_THROWS(Point3D(pt3 / 0));
        REQUIRE_NOTHROW(Point3D(pt1 / 10));
        REQUIRE_NOTHROW(Point3D(pt1 / 10));
        REQUIRE_NOTHROW(Point3D(pt2 / 10));
        REQUIRE(Point3D(pt1 / 3).get() == std::array<int, 3> {2 / 3, 3 / 3, 4 / 3});
        REQUIRE(Point3D(pt2 / 3).get() == std::array<float, 3> {3. / 3, 4. / 3, 5. / 3});
        REQUIRE(Point3D(pt3 / 3).get() == std::array<double, 3> {8. / 3, 9. / 3, 10. / 3});
    }
}
