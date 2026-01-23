#define CATCH_CONFIG_MAIN
#include "../src/point2D.h"
#include "../src/point3D.h"
#include "../src/point3D4.h"
#include "../src/vector.h"
#include <catch2/catch.hpp>

TEST_CASE("Vector Constructor", "[Line]")
{
    SECTION("Vector2D", "[simple constructor]")
    {
        REQUIRE_NOTHROW(Vector<int>(3, 5));
        REQUIRE_NOTHROW(Vector<float>(3.6F, 7.98F));
        REQUIRE_NOTHROW(Vector<double>(3.1243, 7.46));
    }

    SECTION("Vector3D", "[simple constructor]")
    {
        REQUIRE_NOTHROW(Vector<int>(3, 5, 7));
        REQUIRE_NOTHROW(Vector<float>(2.4F, 3.6F, 7.98F));
        REQUIRE_NOTHROW(Vector<double>(3.1243, 5.354, 7.46));
    }

    SECTION("Vector3D4", "[simple constructor]")
    {
        REQUIRE_NOTHROW(Vector<int>(3, 5, 7, 1));
        REQUIRE_NOTHROW(Vector<float>(2.4F, 3.6F, 7.98F, 1));
        REQUIRE_NOTHROW(Vector<double>(3.1243, 5.354, 7.46, 1));
    }

    SECTION("Vector2D", "[Constructor from Points]")
    {
        REQUIRE_NOTHROW(Vector<int>(Point2D<int> {1, 5}, Point2D<float> {9.54F, 4.324F}));
        REQUIRE_NOTHROW(Vector<float>(Point2D<int> {1, 5}, Point2D<float> {9.54F, 4.324F}));
        REQUIRE_NOTHROW(Vector<double>(Point2D<int> {1, 5}, Point2D<float> {9.54F, 4.324F}));
    }
    SECTION("Vector3D", "[Constructor from Points]")
    {
        REQUIRE_NOTHROW(Vector<int>(Point3D<int> {1, 5, 2}, Point3D<float> {9.54F, 4.324F, 71.F}));
        REQUIRE_NOTHROW(Vector<float>(Point3D<int> {1, 5, 2}, Point3D<float> {9.54F, 4.324F, 71.F}));
        REQUIRE_NOTHROW(Vector<double>(Point3D<int> {1, 5, 2}, Point3D<float> {9.54F, 4.324F, 71.F}));
    }
    SECTION("Vector3D4", "[Constructor from Points]")
    {
        REQUIRE_NOTHROW(Vector<int>(Point3D4<int> {1, 5, 2}, Point3D4<float> {9.54F, 4.324F, 71.F}));
        REQUIRE_NOTHROW(Vector<float>(Point3D4<int> {1, 5, 2}, Point3D4<float> {9.54F, 4.324F, 71.F}));
        REQUIRE_NOTHROW(Vector<double>(Point3D4<int> {1, 5, 2}, Point3D4<float> {9.54F, 4.324F, 71.F}));
    }
}
