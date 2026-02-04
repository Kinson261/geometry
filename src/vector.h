#include "axis.h"
#include "point2D.h"
#include "point3D.h"
#include "point3D4.h"
#include <algorithm>
#include <array>
#include <cstddef>
#include <stdexcept>
#include <type_traits>

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

        // Copy Constructor
        Vector(const Vector& other) : dx(other.dx), dy(other.dy), dz(other.dz), scale(other.scale) {}

        // Copy assignment
        Vector& operator=(const Vector& other)
        {
            if (this != other)
            {
                auto other_coordinate = other.get();
                dx = other_coordinate.at(0);
                dy = other_coordinate.at(1);
                dz = other_coordinate.at(2);
                scale = other_coordinate.at(3);
            }
            return *this;
        }

        // Move constructor
        Vector(Vector&& other) noexcept
        {
            dx = std::move(other.dx);
            dy = std::move(other.dy);
            dz = std::move(other.dz);
            scale = std::move(other.scale);
            other.dx = T {};
            other.dy = T {};
            other.dz = T {};
            other.scale = T {};
        }

        // Move assignment
        Vector& operator=(Vector&& other) noexcept
        {
            if (this != other)
            {
                dx = std::move(other.dx);
                dy = std::move(other.dy);
                dz = std::move(other.dz);
                scale = std::move(other.scale);
                other.dx = T {};
                other.dy = T {};
                other.dz = T {};
                other.scale = T {};
            }
            return *this;
        }

        std::array<T, 4> get() const
        {
            return std::array<T, 4> {dx, dy, dz, scale};
        }

        void set(T x, T y, T z)
        {
            dx = x;
            dy = y;
            dz = z;
            scale = 1;
        }

        void set(T x, T y, T z, T s)
        {
            dx = x;
            dy = y;
            dz = z;
            scale = s;
        }

        void set(const Axis& axis, T value)
        {
            if (axis == Axis::X)
            {
                dx = value;
            }
            else if (axis == Axis::Y)
            {
                dy = value;
            }
            else if (axis == Axis::Z)
            {
                dz = value;
            }
            else if (axis == Axis::S)
            {
                scale = value;
            }
            else
            {
                throw std::invalid_argument("Wrong axis.");
            }
        }

        template <typename U>
        bool collinear(const Vector<U, 4>& other) const
        {
            std::array<T, 4> coord1 = get();
            std::array<U, 4> coord2 = other.get();
            if (coord1.at(3) != coord2.at(3))
            {
                throw std::invalid_argument("Scale must be equal");
            }
            return static_cast<bool>(((coord1.at(0) / coord2.at(0)) == (coord1.at(1) / coord2.at(1))) && ((coord1.at(0) / coord2.at(0)) == (coord1.at(2) / coord2.at(2))));
        }

        template <typename U>
        bool orthogonal(const Vector<U, 4>& other) const
        {
            std::array<T, 4> coord1 = get();
            std::array<U, 4> coord2 = other.get();
            if (coord1.at(3) != coord2.at(3))
            {
                throw std::invalid_argument("Scale must be equal");
            }
            return static_cast<bool>(((coord1.at(0) * coord2.at(0)) + (coord1.at(1) * coord2.at(1)) + (coord1.at(2) * coord2.at(2))) == 0);
        }

        template <typename U>
        Vector& operator+(const std::array<U, 4>& other) const
        {
            using ResultType = std::common_type_t<T, U>;
            auto coord1 = get();
            if (coord1.at(3) != other.at(3))
            {
                throw std::invalid_argument("Scale must be the same");
            }
            return Vector<ResultType, 4> {(coord1.at(0) + other.at(0)), coord1.at(1) + other.at(1), coord1.at(2) + other.at(2), (coord1.at(3))};
        }

        template <typename U>
        Vector& operator+(const Vector<U, 4>& other) const
        {
            using ResultType = std::common_type_t<T, U>;
            auto coord1 = get();
            auto coord2 = other.get();
            if (coord1.at(3) != coord2.at(3))
            {
                throw std::invalid_argument("Scale must be the same");
            }
            return Vector<ResultType, 4> {(coord1.at(0) + coord2.at(0)), coord1.at(1) + coord2.at(1), coord1.at(2) + coord2.at(2), (coord1.at(3))};
        }

        template <typename U>
        Vector& operator-(const std::array<U, 4>& other) const
        {
            using ResultType = std::common_type_t<T, U>;
            auto coord1 = get();
            if (coord1.at(3) != other.at(3))
            {
                throw std::invalid_argument("Scale must be the same");
            }
            return Vector<ResultType, 4> {(coord1.at(0) - other.at(0)), coord1.at(1) - other.at(1), coord1.at(2) - other.at(2), (coord1.at(3))};
        }

        template <typename U>
        Vector& operator-(const Vector<U, 4>& other) const
        {
            using ResultType = std::common_type_t<T, U>;
            auto coord1 = get();
            auto coord2 = other.get();
            if (coord1.at(3) != coord2.at(3))
            {
                throw std::invalid_argument("Scale must be the same");
            }
            return Vector<ResultType, 4> {(coord1.at(0) - coord2.at(0)), coord1.at(1) - coord2.at(1), coord1.at(2) - coord2.at(2), (coord1.at(3))};
        }

        template <typename U>
        auto& operator*(const std::array<U, 4>& other) const
        {
            using ResultType = std::common_type_t<T, U>;
            auto coord1 = get();
            if (coord1.at(3) != other.at(3))
            {
                throw std::invalid_argument("Scale must be the same");
            }
            return ResultType {(coord1.at(0) * other.at(0)) + (coord1.at(1) * other.at(1)) + (coord1.at(2) * other.at(2))};
        }

        template <typename U>
        auto& operator*(const Vector<U, 4>& other) const
        {
            using ResultType = std::common_type_t<T, U>;
            auto coord1 = get();
            auto coord2 = other.get();
            if (coord1.at(3) != coord2.at(3))
            {
                throw std::invalid_argument("Scale must be the same");
            }
            return ResultType {(coord1.at(0) * coord2.at(0)) + (coord1.at(1) * coord2.at(1)) + (coord1.at(2) * coord2.at(2))};
        }

        template <typename U>
        auto& dot(const Vector<U, 4>& other) const
        {
            return (*this * other);
        }

        template <typename U>
        auto& dot(const std::array<U, 4>& other) const
        {
            return (*this * other);
        }

        template <typename U>
        auto& cross(const Vector<U, 4>& other) const
        {
            using ResultType = std::common_type_t<T, U>;
            auto coord1 = get();
            auto coord2 = other.get();
            if (coord1.at(3) != coord2.at(3))
            {
                throw std::invalid_argument("Scale must be the same");
            }
            return Vector<ResultType, 4>
            {
                (coord1.at(1) * coord2.at(2)) - (coord2.at(1) * coord1.at(2)),
                (coord1.at(0) * coord2.at(2)) - (coord2.at(0) * coord1.at(2)),
                (coord1.at(0) * coord2.at(1)) - (coord2.at(0) * coord1.at(1)), 
                (coord1.at(3))};
        }

        template <typename U>
        auto& cross(const std::array<U, 4>& other) const
        {
            using ResultType = std::common_type_t<T, U>;
            auto coord1 = get();
            if (coord1.at(3) != other.at(3))
            {
                throw std::invalid_argument("Scale must be the same");
            }
            return Vector<ResultType, 4> {(coord1.at(1) * other.at(2)) - (other.at(1) * coord1.at(2)), (coord1.at(0) * other.at(2)) - (other.at(0) * coord1.at(2)),
                                          (coord1.at(0) * other.at(1)) - (other.at(0) * coord1.at(1)), (coord1.at(3))};
        }

        template <typename U>
        Vector& operator/(const std::array<U, 4>& other) = delete;

        template <typename U>
        Vector& operator/(const Vector<U, 4>& other) = delete;
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

        // Copy Constructor
        Vector(const Vector& other) : dx(other.dx), dy(other.dy), dz(other.dz) {}

        // Copy assignment
        Vector& operator=(const Vector& other)
        {
            if (this != other)
            {
                auto other_coordinate = other.get();
                dx = other_coordinate.at(0);
                dy = other_coordinate.at(1);
                dz = other_coordinate.at(2);
            }
            return *this;
        }

        // Move constructor
        Vector(Vector&& other) noexcept
        {
            dx = std::move(other.dx);
            dy = std::move(other.dy);
            dz = std::move(other.dz);
            other.dx = T {};
            other.dy = T {};
            other.dz = T {};
        }

        // Move assignment
        Vector& operator=(Vector&& other) noexcept
        {
            if (this != other)
            {
                dx = std::move(other.dx);
                dy = std::move(other.dy);
                dz = std::move(other.dz);
                other.dx = T {};
                other.dy = T {};
                other.dz = T {};
            }
            return *this;
        }

        std::array<T, 3> get() const
        {
            return std::array<T, 3> {dx, dy, dz};
        }

        void set(T x, T y, T z)
        {
            dx = x;
            dy = y;
            dz = z;
        }

        void set(const Axis& axis, T value)
        {
            if (axis == Axis::X)
            {
                dx = value;
            }
            else if (axis == Axis::Y)
            {
                dy = value;
            }
            else if (axis == Axis::Z)
            {
                dz = value;
            }
            else
            {
                throw std::invalid_argument("Wrong axis.");
            }
        }

        template <typename U>
        bool collinear(const Vector<U, 3>& other) const
        {
            std::array<T, 3> coord1 = get();
            std::array<U, 3> coord2 = other.get();
            return static_cast<bool>(((coord1.at(0) / coord2.at(0)) == (coord1.at(1) / coord2.at(1))) && ((coord1.at(0) / coord2.at(0)) == (coord1.at(2) / coord2.at(2))));
        }

        template <typename U>
        bool orthogonal(const Vector<U, 3>& other) const
        {
            std::array<T, 3> coord1 = get();
            std::array<U, 3> coord2 = other.get();
            return static_cast<bool>(((coord1.at(0) * coord2.at(0)) + (coord1.at(1) * coord2.at(1)) + (coord1.at(2) * coord2.at(2))) == 0);
        }

        template <typename U>
        Vector& operator+(const std::array<U, 3>& other) const
        {
            using ResultType = std::common_type_t<T, U>;
            auto coord1 = get();
            return Vector<ResultType, 3> {(coord1.at(0) + other.at(0)), coord1.at(1) + other.at(1), (coord1.at(2) + other.at(2))};
        }

        template <typename U>
        Vector& operator+(const Vector<U, 3>& other) const
        {
            using ResultType = std::common_type_t<T, U>;
            auto coord1 = get();
            auto coord2 = other.get();
            return Vector<ResultType, 3> {(coord1.at(0) + coord2.at(0)), coord1.at(1) + coord2.at(1), (coord1.at(2) + coord2.at(2))};
        }

        template <typename U>
        Vector& operator-(const std::array<U, 3>& other) const
        {
            using ResultType = std::common_type_t<T, U>;
            auto coord1 = get();
            return Vector<ResultType, 3> {(coord1.at(0) - other.at(0)), coord1.at(1) - other.at(1), (coord1.at(2) - other.at(2))};
        }

        template <typename U>
        Vector& operator-(const Vector<U, 3>& other) const
        {
            using ResultType = std::common_type_t<T, U>;
            auto coord1 = get();
            auto coord2 = other.get();
            return Vector<ResultType, 3> {(coord1.at(0) - coord2.at(0)), coord1.at(1) - coord2.at(1), (coord1.at(2) - coord2.at(2))};
        }

        template <typename U>
        auto& operator*(const std::array<U, 3>& other) const
        {
            using ResultType = std::common_type_t<T, U>;
            auto coord1 = get();
            return ResultType {(coord1.at(0) * other.at(0)) + (coord1.at(1) * other.at(1)) + (coord1.at(2) * other.at(2))};
        }

        template <typename U>
        auto& operator*(const Vector<U, 3>& other) const
        {
            using ResultType = std::common_type_t<T, U>;
            auto coord1 = get();
            auto coord2 = other.get();
            return ResultType {(coord1.at(0) * coord2.at(0)) + (coord1.at(1) * coord2.at(1)) + (coord1.at(2) * coord2.at(2))};
        }

        template <typename U>
        auto& dot(const Vector<U, 3>& other) const
        {
            return (*this * other);
        }

        template <typename U>
        auto& dot(const std::array<U, 3>& other) const
        {
            return (*this * other);
        }

        template <typename U>
        auto& cross(const Vector<U, 3>& other) const
        {
            using ResultType = std::common_type_t<T, U>;
            auto coord1 = get();
            auto coord2 = other.get();

            return Vector<ResultType, 3> {
                (coord1.at(1) * coord2.at(2)) - (coord2.at(1) * coord1.at(2)),
                (coord1.at(0) * coord2.at(2)) - (coord2.at(0) * coord1.at(2)),
                (coord1.at(0) * coord2.at(1)) - (coord2.at(0) * coord1.at(1)),
            };
        }

        template <typename U>
        auto& cross(const std::array<U, 3>& other) const
        {
            using ResultType = std::common_type_t<T, U>;
            auto coord1 = get();
            return Vector<ResultType, 4> {
                (coord1.at(1) * other.at(2)) - (other.at(1) * coord1.at(2)),
                (coord1.at(0) * other.at(2)) - (other.at(0) * coord1.at(2)),
                (coord1.at(0) * other.at(1)) - (other.at(0) * coord1.at(1)),
            };
        }

        template <typename U>
        Vector& operator/(const std::array<U, 3>& other) = delete;

        template <typename U>
        Vector& operator/(const Vector<U, 3>& other) = delete;
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

        // Copy Constructor
        Vector(const Vector& other) : dx(other.dx), dy(other.dy) {}

        // Copy assignment
        Vector& operator=(const Vector& other)
        {
            if (this != other)
            {
                auto other_coordinate = other.get();
                dx = other_coordinate.at(0);
                dy = other_coordinate.at(1);
            }
            return *this;
        }

        // Move constructor
        Vector(Vector&& other) noexcept
        {
            dx = std::move(other.dx);
            dy = std::move(other.dy);
            other.dx = T {};
            other.dy = T {};
        }

        // Move assignment
        Vector& operator=(Vector&& other) noexcept
        {
            if (this != other)
            {
                dx = std::move(other.dx);
                dy = std::move(other.dy);
                other.dx = T {};
                other.dy = T {};
            }
            return *this;
        }

        std::array<T, 2> get() const
        {
            return std::array<T, 2> {dx, dy};
        }

        void set(T x, T y)
        {
            dx = x;
            dy = y;
        }

        void set(const Axis& axis, T value)
        {
            if (axis == Axis::X)
            {
                dx = value;
            }
            else if (axis == Axis::Y)
            {
                dy = value;
            }
            else
            {
                throw std::invalid_argument("Wrong axis.");
            }
        }

        template <typename U>
        bool collinear(const Vector<U, 2>& other) const
        {
            std::array<T, 2> coord1 = get();
            std::array<U, 2> coord2 = other.get();
            return static_cast<bool>((coord1.at(0) / coord2.at(0)) == (coord1.at(1) / coord2.at(1)));
        }

        template <typename U>
        bool orthogonal(const Vector<U, 2>& other) const
        {
            std::array<T, 2> coord1 = get();
            std::array<U, 2> coord2 = other.get();
            return static_cast<bool>(((coord1.at(0) * coord2.at(0)) + (coord1.at(1) * coord2.at(1))) == 0);
        }

        template <typename U>
        Vector& operator+(const std::array<U, 2>& other) const
        {
            using ResultType = std::common_type_t<T, U>;
            auto coord1 = get();
            return Vector<ResultType, 2> {(coord1.at(0) + other.at(0)), (coord1.at(1) + other.at(1))};
        }

        template <typename U>
        Vector& operator+(const Vector<U, 2>& other) const
        {
            using ResultType = std::common_type_t<T, U>;
            auto coord1 = get();
            auto coord2 = other.get();
            return Vector<ResultType, 2> {(coord1.at(0) + coord2.at(0)), (coord1.at(1) + coord2.at(1))};
        }

        template <typename U>
        Vector& operator-(const std::array<U, 2>& other) const
        {
            using ResultType = std::common_type_t<T, U>;
            auto coord1 = get();
            return Vector<ResultType, 2> {(coord1.at(0) - other.at(0)), (coord1.at(1) - other.at(1))};
        }

        template <typename U>
        Vector& operator-(const Vector<U, 2>& other) const
        {
            using ResultType = std::common_type_t<T, U>;
            auto coord1 = get();
            auto coord2 = other.get();
            return Vector<ResultType, 2> {(coord1.at(0) - coord2.at(0)), (coord1.at(1) - coord2.at(1))};
        }

        template <typename U>
        auto& operator*(const std::array<U, 2>& other) const
        {
            using ResultType = std::common_type_t<T, U>;
            auto coord1 = get();
            return ResultType {(coord1.at(0) * other.at(0)) + (coord1.at(1) * other.at(1))};
        }

        template <typename U>
        auto& operator*(const Vector<U, 2>& other) const
        {
            using ResultType = std::common_type_t<T, U>;
            auto coord1 = get();
            auto coord2 = other.get();
            return ResultType {(coord1.at(0) * coord2.at(0)) + (coord1.at(1) * coord2.at(1))};
        }

        template <typename U>
        auto& dot(const Vector<U, 2>& other) const
        {
            return (*this * other);
        }

        template <typename U>
        auto& dot(const std::array<U, 2>& other) const
        {
            return (*this * other);
        }

        template <typename U>
        Vector& operator/(const std::array<U, 2>& other) = delete;

        template <typename U>
        Vector& operator/(const Vector<U, 2>& other) = delete;
};
