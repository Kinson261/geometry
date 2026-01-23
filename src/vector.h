#include "point2D.h"
#include "point3D.h"
#include "point3D4.h"
#include <cstddef>
#include <stdexcept>

template <typename T, std::size_t N>
    requires((N >= 2) && (N <= 4))
class Vector;

template <typename T>
class Vector<T, 4>
{
    private:
        T dx;
        T dy;
        T dz;
        T scale;

    public:
        // Default constructor
        Vector() : dx(), dy(), dz(), scale() {}

        Vector(T x, T y, T z) : dx(x), dy(y), dz(z), scale(1) {}

        Vector(T x, T y, T z, T s) : dx(x), dy(y), dz(z), scale(s) {}

        // Destructor
        virtual ~Vector() {}

        // Constructor with points
        template <typename U, typename V>
            requires(std::integral<U> || std::floating_point<U>) && (std::integral<V> || std::floating_point<V>)
        Vector(const Point3D4<U>& pt1, const Point3D4<V>& pt2)
        {
            auto pt1_coord = pt1.get();
            auto pt2_coord = pt2.get();
            dx = static_cast<T>(pt2_coord.at(0) - pt1_coord.at(0));
            dy = static_cast<T>(pt2_coord.at(1) - pt1_coord.at(1));
            dz = static_cast<T>(pt2_coord.at(2) - pt1_coord.at(2));
            pt2_coord.at(3) != pt1_coord.at(3) ? throw std::invalid_argument("Scale must be the same.") : scale = pt1_coord.at(3);
        }
};

template <typename T>
class Vector<T, 3>
{
    private:
        T dx;
        T dy;
        T dz;

    public:
        // Default constructor
        Vector() : dx(), dy(), dz() {}

        Vector(T x, T y, T z) : dx(x), dy(y), dz(z) {}

        // Destructor
        virtual ~Vector() {}

        // Constructor with points
        template <typename U, typename V>
            requires(std::integral<U> || std::floating_point<U>) && (std::integral<V> || std::floating_point<V>)
        Vector(const Point3D<U>& pt1, const Point3D<V>& pt2)
        {
            auto pt1_coord = pt1.get();
            auto pt2_coord = pt2.get();
            dx = static_cast<T>(pt2_coord.at(0) - pt1_coord.at(0));
            dy = static_cast<T>(pt2_coord.at(1) - pt1_coord.at(1));
            dz = static_cast<T>(pt2_coord.at(2) - pt1_coord.at(2));
        }
};

template <typename T>
class Vector<T, 2>
{
    private:
        T dx;
        T dy;

    public:
        // Default constructor
        Vector() : dx(), dy() {}

        Vector(T x, T y) : dx(x), dy(y) {}

        // Destructor
        virtual ~Vector() {}

        // Constructor with points
        template <typename U, typename V>
            requires(std::integral<U> || std::floating_point<U>) && (std::integral<V> || std::floating_point<V>)
        Vector(const Point2D<U>& pt1, const Point2D<V>& pt2)
        {
            auto pt1_coord = pt1.get();
            auto pt2_coord = pt2.get();
            dx = static_cast<T>(pt2_coord.at(0) - pt1_coord.at(0));
            dy = static_cast<T>(pt2_coord.at(1) - pt1_coord.at(1));
        }
};
