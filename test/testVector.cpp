#include <algorithm>
#include <array>
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
        REQUIRE_NOTHROW(Vector<int, 2>(3, 5));
        REQUIRE_NOTHROW(Vector<float, 2>(3.6F, 7.98F));
        REQUIRE_NOTHROW(Vector<double, 2>(3.1243, 7.46));
    }

    SECTION("Vector3D", "[simple constructor]")
    {
        REQUIRE_NOTHROW(Vector<int, 3>(3, 5, 7));
        REQUIRE_NOTHROW(Vector<float, 3>(2.4F, 3.6F, 7.98F));
        REQUIRE_NOTHROW(Vector<double, 3>(3.1243, 5.354, 7.46));
    }

    SECTION("Vector3D4", "[simple constructor]")
    {
        REQUIRE_NOTHROW(Vector<int, 4>(3, 5, 7, 1));
        REQUIRE_NOTHROW(Vector<float, 4>(2.4F, 3.6F, 7.98F, 1));
        REQUIRE_NOTHROW(Vector<double, 4>(3.1243, 5.354, 7.46, 1));
    }

    SECTION("Vector2D", "[Constructor from Points]")
    {
        REQUIRE_NOTHROW(Vector<int, 2>(Point2D<int> {1, 5}, Point2D<float> {9.54F, 4.324F}));
        REQUIRE_NOTHROW(Vector<float, 2>(Point2D<int> {1, 5}, Point2D<float> {9.54F, 4.324F}));
        REQUIRE_NOTHROW(Vector<double, 2>(Point2D<int> {1, 5}, Point2D<float> {9.54F, 4.324F}));
    }
    SECTION("Vector3D", "[Constructor from Points]")
    {
        REQUIRE_NOTHROW(Vector<int, 3>(Point3D<int> {1, 5, 2}, Point3D<float> {9.54F, 4.324F, 71.F}));
        REQUIRE_NOTHROW(Vector<float, 3>(Point3D<int> {1, 5, 2}, Point3D<float> {9.54F, 4.324F, 71.F}));
        REQUIRE_NOTHROW(Vector<double, 3>(Point3D<int> {1, 5, 2}, Point3D<float> {9.54F, 4.324F, 71.F}));
    }
    SECTION("Vector3D4", "[Constructor from Points]")
    {
        REQUIRE_NOTHROW(Vector<int, 4>(Point3D4<int> {1, 5, 2}, Point3D4<float> {9.54F, 4.324F, 71.F}));
        REQUIRE_NOTHROW(Vector<float, 4>(Point3D4<int> {1, 5, 2}, Point3D4<float> {9.54F, 4.324F, 71.F}));
        REQUIRE_NOTHROW(Vector<double, 4>(Point3D4<int> {1, 5, 2}, Point3D4<float> {9.54F, 4.324F, 71.F}));
    }

    SECTION("Copy constructor", "[Vector<T,4>]")
    {
        Vector<int, 4> pt1 {64, 52, 95};
        Vector<int, 4> pt2(pt1);
        REQUIRE(pt2.get() == std::array<int, 4> {64, 52, 95, 1});
    }

    SECTION("Copy assignment", "[Vector<T,4>]")
    {
        Vector<int, 4> pt1 {64, 52, 95};
        Vector<int, 4> pt2 = pt1;
        REQUIRE(pt2.get() == std::array<int, 4> {64, 52, 95, 1});
    }

    SECTION("Move constructor", "[Vector<T,4>]")
    {
        Vector<int, 4> pt1 {64, 52, 95};
        Vector<int, 4> pt2(std::move(pt1));
        REQUIRE(pt2.get() == std::array<int, 4> {64, 52, 95, 1});
        std::cout << "(" << pt1.get().at(0) << ", " << pt1.get().at(1) << ", " << pt1.get().at(2) << ", " << pt1.get().at(3) << ")\n";
    }

    SECTION("Move assignment ", "[Vector<T,4>]")
    {
        Vector<int, 4> pt1 {64, 52, 95};
        Vector<int, 4> pt2 = std::move(pt1);
        REQUIRE(pt2.get() == std::array<int, 4> {64, 52, 95, 1});
        std::cout << "(" << pt1.get().at(0) << ", " << pt1.get().at(1) << ", " << pt1.get().at(2) << ", " << pt1.get().at(3) << ")\n";
    }

    SECTION("Copy constructor", "[Vector<T,3>]")
    {
        Vector<int, 3> pt1 {64, 52, 95};
        Vector<int, 3> pt2(pt1);
        REQUIRE(pt2.get() == std::array<int, 3> {64, 52, 95});
    }

    SECTION("Copy assignment", "[Vector<T,3>]")
    {
        Vector<int, 3> pt1 {64, 52, 95};
        Vector<int, 3> pt2 = pt1;
        REQUIRE(pt2.get() == std::array<int, 3> {64, 52, 95});
    }

    SECTION("Move constructor", "[Vector<T,3>]")
    {
        Vector<int, 3> pt1 {64, 52, 95};
        Vector<int, 3> pt2(std::move(pt1));
        REQUIRE(pt2.get() == std::array<int, 3> {64, 52, 95});
        std::cout << "(" << pt1.get().at(0) << ", " << pt1.get().at(1) << ", " << pt1.get().at(2) << ")\n";
    }

    SECTION("Move assignment ", "[Vector<T,3>]")
    {
        Vector<int, 3> pt1 {64, 52, 95};
        Vector<int, 3> pt2 = std::move(pt1);
        REQUIRE(pt2.get() == std::array<int, 3> {64, 52, 95});
        std::cout << "(" << pt1.get().at(0) << ", " << pt1.get().at(1) << ")\n";
    }

    SECTION("Copy constructor", "[Vector<T,2>]")
    {
        Vector<int, 2> pt1 {64, 52};
        Vector<int, 2> pt2(pt1);
        REQUIRE(pt2.get() == std::array<int, 2> {64, 52});
    }

    SECTION("Copy assignment", "[Vector<T,2>]")
    {
        Vector<int, 2> pt1 {64, 52};
        Vector<int, 2> pt2 = pt1;
        REQUIRE(pt2.get() == std::array<int, 2> {64, 52});
    }

    SECTION("Move constructor", "[Vector<T,2>]")
    {
        Vector<int, 2> pt1 {64, 52};
        Vector<int, 2> pt2(std::move(pt1));
        REQUIRE(pt2.get() == std::array<int, 2> {64, 52});
        std::cout << "(" << pt1.get().at(0) << ", " << pt1.get().at(1) << ")\n";
    }

    SECTION("Move assignment ", "[Vector<T,2>]")
    {
        Vector<int, 2> pt1 {64, 52};
        Vector<int, 2> pt2 = std::move(pt1);
        REQUIRE(pt2.get() == std::array<int, 2> {64, 52});
        std::cout << "(" << pt1.get().at(0) << ", " << pt1.get().at(1) << ")\n";
    }
}

TEST_CASE("Getter", "[Vector]")
{
    SECTION("Getter", "[Vector2D]")
    {
        Vector<int, 2> a(Point2D<int> {7, 4}, Point2D<double> {2, 9});
        REQUIRE(a.get() == std::array<int, 2> {-5, 5});

        Vector<double, 2> b(Point2D<int> {7, 4}, Point2D<double> {2.5, 9.6});
        REQUIRE(b.get() == std::array<double, 2> {-4.5, 5.6});
    }

    SECTION("Getter", "[Vector3D]")
    {
        Vector<int, 3> a(Point3D<int> {7, 4, 4}, Point3D<double> {2, 9, 2});
        REQUIRE(a.get() == std::array<int, 3> {-5, 5, -2});

        Vector<double, 3> b(Point3D<int> {7, 4, 4}, Point3D<double> {2.5, 9.6, 2.4});
        REQUIRE(b.get() == std::array<double, 3> {-4.5, 5.6, -1.6});
    }

    SECTION("Getter", "[Vector3D4]")
    {
        Vector<int, 4> a(Point3D4<int> {7, 4, 4}, Point3D4<double> {2, 9, 2});
        REQUIRE(a.get() == std::array<int, 4> {-5, 5, -2, 1});

        Vector<double, 4> b(Point3D4<int> {7, 4, 4}, Point3D4<double> {2.5, 9.6, 2.4});
        REQUIRE(b.get() == std::array<double, 4> {-4.5, 5.6, -1.6, 1});

        Vector<int, 4> c(Point3D4<int> {7, 4, 4, 2}, Point3D4<double> {2, 9, 2, 2});
        REQUIRE(c.get() == std::array<int, 4> {-5, 5, -2, 2});

        Vector<double, 4> d(Point3D4<int> {7, 4, 4, -8}, Point3D4<double> {2.5, 9.6, 2.4, -8});
        REQUIRE(d.get() == std::array<double, 4> {-4.5, 5.6, -1.6, -8});
    }
}

TEST_CASE("Setter", "[Vector]")
{
    SECTION("Setter", "[Vector2D]")
    {
        Vector<int, 2> a;
        a.set(9, 5);
        REQUIRE(a.get() == std::array<int, 2> {9, 5});
        a.set(Axis::X, 4);
        a.set(Axis::Y, 5);
        REQUIRE_THROWS(a.set(Axis::Z, 1));
        REQUIRE_THROWS(a.set(Axis::S, 2));
        REQUIRE(a.get() == std::array<int, 2> {4, 5});
    }

    SECTION("Setter", "[Vector3D]")
    {
        Vector<double, 3> a;
        a.set(9, 5, 8);
        REQUIRE(a.get() == std::array<double, 3> {9, 5, 8});
        a.set(Axis::X, 4);
        a.set(Axis::Y, 5);
        a.set(Axis::Z, 1);
        REQUIRE_THROWS(a.set(Axis::S, 2));
        REQUIRE(a.get() == std::array<double, 3> {4, 5, 1});
    }

    SECTION("Setter", "[Vector3D4]")
    {
        Vector<double, 4> a;
        a.set(9, 5, 8);
        REQUIRE(a.get() == std::array<double, 4> {9, 5, 8, 1});
        a.set(Axis::X, 4);
        a.set(Axis::Y, 5);
        a.set(Axis::Z, 1);
        a.set(Axis::S, 2);
        REQUIRE(a.get() == std::array<double, 4> {4, 5, 1, 2});

        Vector<double, 4> b;
        b.set(9, 5, 8, 4);
        REQUIRE(b.get() == std::array<double, 4> {9, 5, 8, 4});
        b.set(Axis::X, 4);
        b.set(Axis::Y, 5);
        b.set(Axis::Z, 1);
        b.set(Axis::S, -2);
        REQUIRE(b.get() == std::array<double, 4> {4, 5, 1, -2});
    }

    SECTION("collinear")
    {
        SECTION("[Vector<T,2>]")
        {
            Vector<int, 2> pt1(1, 2);
            Vector<int, 2> pt2(2, 4);
            std::array<int, 2> pt3 {2, 4};

            REQUIRE(pt1.is_collinear(pt2) == true);
            REQUIRE(pt1.is_collinear(Vector<int, 2>(pt3)) == true);
        }
        SECTION("[Vector<T,3>]")
        {
            Vector<int, 3> pt1 {1, 2, 2};
            Vector<int, 3> pt2 {2, 4, 4};
            std::array<int, 3> pt3 {2, 4, 4};

            REQUIRE(pt1.is_collinear(pt2) == true);
            REQUIRE(pt1.is_collinear(Vector<int, 3>(pt3)) == true);
        }
        SECTION("[Vector<T,4>]")
        {
            Vector<int, 4> pt1 {1, 2, 2, 1};
            Vector<int, 4> pt2 {2, 4, 4, 1};
            std::array<int, 4> pt3 {2, 4, 4, 1};

            REQUIRE(pt1.is_collinear(pt2) == true);
            REQUIRE(pt1.is_collinear(Vector<int, 4>(pt3)) == true);
        }
    }

    SECTION("orthogonal")
    {
        SECTION("[Vector<T,2>]")
        {
            Vector<int, 2> pt1 {1, 0};
            Vector<int, 2> pt2 {0, 1};
            std::array<int, 2> pt3 {0, 1};

            REQUIRE(pt1.is_orthogonal(pt2) == true);
            REQUIRE(pt1.is_orthogonal(Vector<int, 2>(pt3)) == true);
        }

        SECTION("[Vector<T,3>]")
        {
            Vector<int, 3> pt1 {1, 0, 0};
            Vector<int, 3> pt2 {0, 1, 0};
            std::array<int, 3> pt3 {0, 0, 1};

            REQUIRE(pt1.is_orthogonal(pt2) == true);
            REQUIRE(pt1.is_orthogonal(Vector<int, 3>(pt3)) == true);
            REQUIRE(pt2.is_orthogonal(Vector<int, 3>(pt3)) == true);
        }
        SECTION("[Vector<T,4>]")
        {
            Vector<int, 4> pt1 {1, 0, 0, 1};
            Vector<int, 4> pt2 {0, 1, 0, 1};
            std::array<int, 4> pt3 {0, 0, 1, 1};
            std::array<int, 4> pt4 {0, 0, 1, 2};

            REQUIRE(pt1.is_orthogonal(pt2) == true);
            REQUIRE(pt1.is_orthogonal(Vector<int, 4>(pt3)) == true);
            REQUIRE(pt2.is_orthogonal(Vector<int, 4>(pt3)) == true);
            REQUIRE_THROWS(pt2.is_orthogonal(Vector<int, 4>(pt4)));
        }
    }

    SECTION("operations")
    {
        SECTION("Addition")
        {
            SECTION("[Vector<T,2>]")
            {
                Vector<int, 2> pt1 {1, 0};
                Vector<int, 2> pt2 {0, 1};
                Vector<int, 2> pt3 {1, 1};
                REQUIRE((pt1 + pt2).get() == std::array<int, 2> {1, 1});
                REQUIRE((pt1 + pt2) == pt3);
            }
            SECTION("[Vector<T,3>]")
            {
                Vector<int, 3> pt1 {1, 0, 3};
                Vector<int, 3> pt2 {0, 1, 2};
                Vector<int, 3> pt3 {1, 1, 5};
                REQUIRE((pt1 + pt2).get() == std::array<int, 3> {1, 1, 5});
                REQUIRE((pt1 + pt2) == pt3);
            }
            SECTION("[Vector<T,4>]")
            {
                Vector<int, 4> pt1 {1, 0, 3, 1};
                Vector<int, 4> pt2 {0, 1, 2, 1};
                Vector<int, 4> pt3 {1, 1, 5, 1};
                Vector<int, 4> pt4 {1, 1, 5, 2};
                REQUIRE((pt1 + pt2).get() == std::array<int, 4> {1, 1, 5, 1});
                REQUIRE((pt1 + pt2) == pt3);
                REQUIRE_THROWS((pt1 + pt2) == pt4);
            }
        }

        SECTION("Subtraction")
        {
            SECTION("[Vector<T,2>]")
            {
                Vector<int, 2> pt1 {1, 0};
                Vector<int, 2> pt2 {0, 1};
                Vector<int, 2> pt3 {1, -1};
                REQUIRE((pt1 - pt2).get() == std::array<int, 2> {1, -1});
                REQUIRE((pt1 - pt2) == pt3);
            }
            SECTION("[Vector<T,3>]")
            {
                Vector<int, 3> pt1 {1, 0, 3};
                Vector<int, 3> pt2 {0, 1, 2};
                Vector<int, 3> pt3 {1, -1, 1};
                REQUIRE((pt1 - pt2).get() == std::array<int, 3> {1, -1, 1});
                REQUIRE((pt1 - pt2) == pt3);
            }
            SECTION("[Vector<T,4>]")
            {
                Vector<int, 4> pt1 {1, 0, 3, 1};
                Vector<int, 4> pt2 {0, 1, 2, 1};
                Vector<int, 4> pt3 {1, -1, 1, 1};
                Vector<int, 4> pt4 {1, -1, 1, 2};
                REQUIRE((pt1 - pt2).get() == std::array<int, 4> {1, -1, 1, 1});
                REQUIRE((pt1 - pt2) == pt3);
                REQUIRE_THROWS((pt1 - pt2) == pt4);
            }
        }
        SECTION("Multiplication")
        {
            SECTION("[Vector<T,2>]")
            {
                Vector<int, 2> pt1 {1, 4};
                Vector<int, 2> pt2 {4, 16};
                REQUIRE((pt1 * pt2) == 68);
            }
            SECTION("[Vector<T,3>]")
            {
                Vector<int, 3> pt1 {1, 4, 2};
                Vector<int, 3> pt2 {4, 16, 3};
                REQUIRE((pt1 * pt2) == 74);
            }
            SECTION("[Vector<T,4>]")
            {
                Vector<int, 4> pt1 {1, 4, 2, 1};
                Vector<int, 4> pt2 {4, 16, 3, 1};
                Vector<int, 4> pt3 {4, 16, 3, 2};
                REQUIRE((pt1 * pt2) == 74);
                REQUIRE_THROWS(pt1 * pt3);
            }
        }

        SECTION("Scalar Product")
        {
            SECTION("[Vector<T,2>]")
            {
                Vector<int, 2> pt1 {1, 4};
                Vector<int, 2> pt2 {4, 16};
                REQUIRE((pt1.dot(pt2)) == 68);
            }
            SECTION("[Vector<T,3>]")
            {
                Vector<int, 3> pt1 {1, 4, 2};
                Vector<int, 3> pt2 {4, 16, 3};
                REQUIRE((pt1.dot(pt2)) == 74);
            }
            SECTION("[Vector<T,4>]")
            {
                Vector<int, 4> pt1 {1, 4, 2, 1};
                Vector<int, 4> pt2 {4, 16, 3, 1};
                Vector<int, 4> pt3 {4, 16, 3, 2};
                REQUIRE((pt1.dot(pt2)) == 74);
                REQUIRE_THROWS(pt1.dot(pt3));
            }
        }
    }
}
