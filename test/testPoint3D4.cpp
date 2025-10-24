#include "../src/point3D4.h"
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <sys/types.h>

TEST_CASE("Point3D4 are created", "[Point3D4]")
{
    REQUIRE_NOTHROW(Point3D4<int> {});
    REQUIRE_NOTHROW(Point3D4<short int> {});
    REQUIRE_NOTHROW(Point3D4<long int> {});
    REQUIRE_NOTHROW(Point3D4<float> {});
    REQUIRE_NOTHROW(Point3D4<double> {});
    REQUIRE_NOTHROW(Point3D4<long long> {});
    REQUIRE_NOTHROW(Point3D4<long double> {});
    REQUIRE_NOTHROW(Point3D4<uint> {});

    REQUIRE_NOTHROW(Point3D4<int> {12, 23, 34});
    REQUIRE_NOTHROW(Point3D4<int> {12, 23, 34, 1});
    REQUIRE_NOTHROW(Point3D4<int> {12, 23, 34, 45});

    REQUIRE_NOTHROW(Point3D4<float> {12, 23, 34});
    REQUIRE_NOTHROW(Point3D4<float> {12.f, 23.f, 34.f});
    REQUIRE_NOTHROW(Point3D4<float> {12.f, 23.f, 34.f, 1});
    REQUIRE_NOTHROW(Point3D4<float> {12.f, 23.f, 34.f, 1.f});
    REQUIRE_NOTHROW(Point3D4<float> {12.f, 23.f, 34.f, 45});
    REQUIRE_NOTHROW(Point3D4<float> {12.f, 23.f, 34.f, 45.f});

    REQUIRE_NOTHROW(Point3D4<double> {12, 23, 34});
    REQUIRE_NOTHROW(Point3D4<double> {12., 23., 34.});
    REQUIRE_NOTHROW(Point3D4<double> {12, 23, 34, 1});
    REQUIRE_NOTHROW(Point3D4<double> {12., 23., 34., 1.});
    REQUIRE_NOTHROW(Point3D4<double> {12, 23, 34, 45});
    REQUIRE_NOTHROW(Point3D4<double> {12., 23., 34., 45.});
}

TEST_CASE("Point3D4 values are checked", "[Point3D4 values]")
{
    int x_int {34};
    int y_int {12};
    int z_int {65};
    int s_int {2};

    float x_float {34.45f};
    float y_float {12.34f};
    float z_float {23.43f};
    float s_float {2.f};


    double x_double {23.34};
    double y_double {328};
    double z_double {98.3};
    double s_double {2.};

    Point3D4 point3D4int1(x_int, y_int, z_int);
    REQUIRE(point3D4int1.get().at(0) == 34);
    REQUIRE(point3D4int1.get().at(1) == 12);
    REQUIRE(point3D4int1.get().at(2) == 65);
    REQUIRE(point3D4int1.get() == std::array<int, 4>({x_int, y_int, z_int, 1}));

    Point3D4<int> point3D4int2(x_int, y_int, z_int, s_int);
    REQUIRE(point3D4int2.get().at(0) == 34);
    REQUIRE(point3D4int2.get().at(1) == 12);
    REQUIRE(point3D4int2.get().at(2) == 65);
    REQUIRE(point3D4int2.get().at(3) == 2);
    REQUIRE(point3D4int2.get() == std::array<int, 4>({x_int, y_int, z_int, 2}));


    Point3D4<float> point3D4float1(x_float, y_float, z_float);
    REQUIRE(point3D4float1.get().at(0) == 34.45f);
    REQUIRE(point3D4float1.get().at(1) == 12.34f);
    REQUIRE(point3D4float1.get().at(2) == 23.43f);
    REQUIRE(point3D4float1.get() == std::array<float, 4>({x_float, y_float, z_float, 1.0f}));

    Point3D4<float> point3D4float2(x_float, y_float, z_float, s_float);
    REQUIRE(point3D4float2.get().at(0) == 34.45f);
    REQUIRE(point3D4float2.get().at(1) == 12.34f);
    REQUIRE(point3D4float2.get().at(2) == 23.43f);
    REQUIRE(point3D4float2.get().at(3) == 2.f);
    REQUIRE(point3D4float2.get() == std::array<float, 4>({x_float, y_float, z_float, 2.0f}));


    Point3D4<double> point3D4double1(x_double, y_double, z_double);
    REQUIRE(point3D4double1.get().at(0) == 23.34);
    REQUIRE(point3D4double1.get().at(1) == 328);
    REQUIRE(point3D4double1.get().at(2) == 98.3);
    REQUIRE(point3D4double1.get() == std::array<double, 4>({x_double, y_double, z_double, 1.0}));

    Point3D4<double> point3D4double2(x_double, y_double, z_double, s_double);
    REQUIRE(point3D4double2.get().at(0) == 23.34);
    REQUIRE(point3D4double2.get().at(1) == 328);
    REQUIRE(point3D4double2.get().at(2) == 98.3);
    REQUIRE(point3D4double2.get().at(3) == 2.);
    REQUIRE(point3D4double2.get() == std::array<double, 4>({x_double, y_double, z_double, 2.0}));
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

TEST_CASE("Point3D4 set() function are tested ", "[Point3D4 set()]")
{
    Point3D4<int> pt1 {493, 9392, 482392};
    pt1.set("x", 34);
    pt1.set("y", 3);
    pt1.set("z", 4);
    pt1.set("s", 5);
    REQUIRE(pt1.get().at(0) == 34);
    REQUIRE(pt1.get().at(1) == 3);
    REQUIRE(pt1.get().at(2) == 4);
    REQUIRE(pt1.get().at(3) == 5);

    pt1.set("X", 36);
    pt1.set("Y", 37);
    pt1.set("Z", 48);
    pt1.set("S", 6);
    REQUIRE(pt1.get().at(0) == 36);
    REQUIRE(pt1.get().at(1) == 37);
    REQUIRE(pt1.get().at(2) == 48);
    REQUIRE(pt1.get().at(3) == 6);

    REQUIRE_THROWS(pt1.set("a", 10));
    REQUIRE_THROWS(pt1.set("b", 20));
    REQUIRE_THROWS(pt1.set("c", 30));

    REQUIRE_THROWS(pt1.set("A", 1));
    REQUIRE_THROWS(pt1.set("B", 2));
    REQUIRE_THROWS(pt1.set("C", 3));

    REQUIRE_THROWS(pt1.set("AWERT", 1));
    REQUIRE_THROWS(pt1.set("BDFG", 2));
    REQUIRE_THROWS(pt1.set("CGH", 3));
}
