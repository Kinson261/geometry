#include "point2D.h"
#include "point3D.h"
#include "point3D4.h"
#include <optional>
#include <stdexcept>

template <typename T>
class Vector
{
    private:
        T dx;
        T dy;
        std::optional<T> dz;
        std::optional<T> scale;

    public:
    // Default constructor
    Vector<T>() : dx(), dy () , dz () {};
    Vector<T>(T x, T y) : dx(x), dy (y) , dz (std::nullopt), scale(std::nullopt) {};
    Vector<T>(T x, T y, T z) : dx(x), dy (y) , dz (z) {};
    Vector<T>(T x, T y, T z, T s) : dx(x), dy (y) , dz (z), scale(s) {};

    // Destructor
    virtual ~Vector() {}

    //Constructor from Points of different types
    template<typename U, typename V>
    requires (std::integral<U> || std::floating_point<U>) || (std::integral<V> || std::floating_point<V>)
    Vector<T>(const Point2D<U>& pt1, const Point2D<V>& pt2): dz(std::nullopt), scale(std::nullopt)
    {
        auto pt1_coord = pt1.get();
        auto pt2_coord = pt2.get();
        dx = static_cast<T>(pt2_coord.at(0) - pt1_coord.at(0));
        dy = static_cast<T>(pt2_coord.at(1) - pt1_coord.at(1));
    }

    template<typename U, typename V>
    requires (std::integral<U> || std::floating_point<U>) || (std::integral<V> || std::floating_point<V>)
    Vector<T>(const Point3D<U>& pt1, const Point3D<V>& pt2): scale(std::nullopt)
    {
        auto pt1_coord = pt1.get();
        auto pt2_coord = pt2.get();
        dx = static_cast<T>(pt2_coord.at(0) - pt1_coord.at(0));
        dy = static_cast<T>(pt2_coord.at(1) - pt1_coord.at(1));
        dy = static_cast<T>(pt2_coord.at(2) - pt1_coord.at(2));
    }

    template<typename U, typename V>
    requires (std::integral<U> || std::floating_point<U>) || (std::integral<V> || std::floating_point<V>)
    Vector<T>(const Point3D4<U>& pt1, const Point3D4<V>& pt2): scale(std::nullopt)
    {
        auto pt1_coord = pt1.get();
        auto pt2_coord = pt2.get();
        pt2_coord.at(3) != pt1_coord.at(3) ? throw std::invalid_argument("Scale must be the same.") : true;
        dx = static_cast<T>(pt2_coord.at(0) - pt1_coord.at(0));
        dy = static_cast<T>(pt2_coord.at(1) - pt1_coord.at(1));
        dy = static_cast<T>(pt2_coord.at(2) - pt1_coord.at(2));
    }
};
