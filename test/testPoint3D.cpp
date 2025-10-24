#include "../src/point3D.h"
#define CATCH_CONFIG_MAIN
#include <array>
#include <catch2/catch.hpp>
#include <string>
#include <sys/types.h>

TEST_CASE("Point3D are created", "[Point3D]")
{
    REQUIRE_NOTHROW(Point3D<int> {});
    REQUIRE_NOTHROW(Point3D<short int> {});
    REQUIRE_NOTHROW(Point3D<long int> {});
    REQUIRE_NOTHROW(Point3D<float> {});
    REQUIRE_NOTHROW(Point3D<double> {});
    REQUIRE_NOTHROW(Point3D<long long > {});
    REQUIRE_NOTHROW(Point3D<long double> {});
    REQUIRE_NOTHROW(Point3D<uint> {});

    REQUIRE_NOTHROW(Point3D<int> {23, 34, 43});
    REQUIRE_NOTHROW(Point3D<float>(23.4, 4.3, .531));
    REQUIRE_NOTHROW(Point3D<double>(23.4, 4, .531));
}

TEST_CASE("Point3D values are checked", "[Point3D values]")
{

    int x_int {34};
    int y_int {12};
    int z_int {65};
    
    float x_float {34.45};
    float y_float {12.34};
    float z_float {23.43};
    
    double x_double {23.34};
    double y_double {328};
    double z_double {98.3};

    Point3D point3Dint(x_int, y_int, z_int);
    REQUIRE(point3Dint.get().at(0) == 34);
    REQUIRE(point3Dint.get().at(1) == 12);
    REQUIRE(point3Dint.get().at(2) == 65);
    
    Point3D<float> point3Dfloat(x_float, y_float, z_float);
    REQUIRE(point3Dfloat.get().at(0) == 34.45f);
    REQUIRE(point3Dfloat.get().at(1) == 12.34f);
    REQUIRE(point3Dfloat.get().at(2) == 23.43f);
    
    Point3D<double> point3Ddouble(x_double, y_double, z_double);
    REQUIRE(point3Ddouble.get().at(0) == 23.34);
    REQUIRE(point3Ddouble.get().at(1) == 328);
    REQUIRE(point3Ddouble.get().at(2) == 98.3);
}

TEST_CASE("Poind 3D arithmetic functions are checked", "[Point3D arithmetic]")
{
    Point3D<int> pi1 {2,3,4};
    Point3D<int> pi2 {5, 6, 7};
    Point3D<int> pira = pi1 + pi2;
    Point3D<int> pirs = pi1 - pi2;
    
    REQUIRE(pira.get() == std::array<int, 3>{7,9,11});
    REQUIRE(pirs.get() == std::array<int, 3>{-3,-3,-3});
    
    Point3D<float> pf1 {2,3,4};
    Point3D<float> pf2 {5, 6, 7};
    Point3D<float> pfra = pf1 + pf2;
    Point3D<float> pfrs = pf1 - pf2;

    REQUIRE(pfra.get() == std::array<float, 3>{7,9,11});
    REQUIRE(pfrs.get() == std::array<float, 3>{-3,-3,-3});

    Point3D<double> pd1 {2.,3.,4.};
    Point3D<double> pd2 {5.,6.,7.};
    Point3D<double> pdra = pd1 + pd2;
    Point3D<double> pdrs = pd1 - pd2;
    
    REQUIRE(pdra.get() == std::array<double, 3>{7,9,11});
    REQUIRE(pdrs.get() == std::array<double, 3>{-3,-3,-3});
}

TEST_CASE("Point3d equality check is tested", "[Point3D equality]")
{
    Point3D<int> pt1 {23,45,67};
    Point3D<float> pt2 {23,45,67};
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

TEST_CASE("Point3D set() function are tested ", "[Point3D set()]")
{
    Point3D<int> pt1 {493, 9392, 482392};
    pt1.set("x", 34);
    pt1.set("y", 3);
    pt1.set("z", 4);
    REQUIRE(pt1.get().at(0) == 34);
    REQUIRE(pt1.get().at(1) == 3);
    REQUIRE(pt1.get().at(2) == 4);

    pt1.set("X", 36);
    pt1.set("Y", 37);
    pt1.set("Z", 48);
    REQUIRE(pt1.get().at(0) == 36);
    REQUIRE(pt1.get().at(1) == 37);
    REQUIRE(pt1.get().at(2) == 48);

    REQUIRE_THROWS(pt1.set("a", 10));
    REQUIRE_THROWS(pt1.set("b", 20));
    REQUIRE_THROWS(pt1.set("c", 30));

    REQUIRE_THROWS(pt1.set("A", 1));
    REQUIRE_THROWS(pt1.set("B", 2));
    REQUIRE_THROWS(pt1.set("C", 3));

    pt1.set(56,54,32);
    REQUIRE(pt1.get().at(0) == 56);
    REQUIRE(pt1.get().at(1) == 54);
    REQUIRE(pt1.get().at(2) == 32);
}
