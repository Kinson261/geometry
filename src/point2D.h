#pragma once
#include "axis.h"
#include <algorithm>
#include <array>
#include <cassert>
#include <concepts>
#include <format>
#include <iostream>
#include <ostream>
#include <print>
#include <stdexcept>
#include <type_traits>
#include <vector>

template <typename T>
    requires std::integral<T> || std::floating_point<T>
class Point2D
{
    protected:
        T x, y;

    public:
        // Default constructor
        Point2D() : x(T {}), y(T {})
        {
            std::clog << "Point2D created without initialization." << "\n";
        }

        Point2D(T x_val, T y_val) : x(x_val), y(y_val)
        {
            std::print("Point2D created with value [{0}, {1}]\n", x_val, y_val);
        }

        Point2D(std::array<T, 2> arr) : x(arr.at(0)), y(arr.at(1)) {}

        Point2D(std::vector<T> vec)
        {
            assert(vec.size() == 2);
            x = vec.at(0);
            y = vec.at(1);
        }

        // With different type
        template <typename U>
            requires std::integral<U> || std::floating_point<U>
        Point2D(Point2D<U>& other) : x(static_cast<T>(other.get().at(0))), y(static_cast<T>(other.get().at(1)))
        {}

        template <typename U>
            requires std::integral<U> || std::floating_point<U>
        Point2D(U x_val, U y_val) : x(static_cast<T>(x_val)), y(static_cast<T>(y_val))
        {}

        // Default destructor
        virtual ~Point2D()
        {
            std::print("Point2D destroyed.\n");
        }

        // Copy constructor
        Point2D(const Point2D& other) : x(other.x), y(other.y)
        {
            std::print("Point2D is copied.\n");
        }

        // Copy assignment
        Point2D& operator=(const Point2D& other)
        {
            if (this != &other)
            {
                x = other.x;
                y = other.y;
                std::print("Point2D is copied by assignment.\n");
            }
            return *this;
        }

        // Move constructor
        Point2D(Point2D&& other) noexcept
        {
            if (this != &other)
            {
                x = std::move(other.x);
                y = std::move(other.y);
                other.x = T {};
                other.y = T {};
                std::print("Point2D is moved.\n");
            }
        }

        // Move assignment
        Point2D& operator=(Point2D&& other) noexcept
        {
            if (this != &other)
            {
                x = std::move(other.x);
                y = std::move(other.y);
                other.x = T {};
                other.y = T {};
                std::print("Point2D is moved by assignment.\n");
            }
            return *this;
        }

        template <typename U>
            requires std::integral<U> || std::floating_point<U>
        auto operator+(const Point2D<U>& other) const
        {
            std::array<U, 2> pt2 = other.get();
            using ResultType = std::common_type_t<T, U>;
            return Point2D<ResultType> {
                x + pt2.at(0),
                y + pt2.at(1),
            };
        }

        template <typename U>
            requires std::integral<U> || std::floating_point<U>
        auto operator-(const Point2D<U>& other) const
        {
            std::array<U, 2> pt2 = other.get();
            using ResultType = std::common_type_t<T, U>;
            return Point2D<ResultType> {
                x - pt2.at(0),
                y - pt2.at(1),
            };
        }

        template <typename U>
            requires std::integral<U> || std::floating_point<U>
        auto operator*(const U& scalar) const
        {
            using ResultType = decltype(this->x * scalar);
            return Point2D<ResultType> {
                x * scalar,
                y * scalar,
            };
        }

        template <typename U>
            requires std::integral<U> || std::floating_point<U>
        auto operator/(const U& scalar) const
        {
            if(scalar==0){
                throw std::invalid_argument("Cannot divide by 0.");
            }
            using ResultType = decltype(this->x / scalar);
            return Point2D<ResultType> {
                x / scalar,
                y / scalar,
            };
        }

        template <typename U>
        Point2D& operator=(const Point2D<U>& other)
        {
            x = static_cast<T>(other.get().at(0));
            y = static_cast<T>(other.get().at(1));
            std::print("Point2D is copied by assignment from another type.\n");
            return *this;
        }


        template <typename U>
        auto operator+=(const Point2D<U>& other)
        {
            using ResultType = std::common_type_t<T, U>;    // Same as line above C++14
            Point2D<ResultType> tmp {static_cast<ResultType>(x) + static_cast<ResultType>(other.get().at(0)),
                                     static_cast<ResultType>(y) + static_cast<ResultType>(other.get().at(1))};
            *this = std::move(tmp);
            return *this;
        }

        // Required for operator subtractable
        Point2D& operator-=(const Point2D& rhs)
        {
            x -= rhs.x;
            y -= rhs.y;
            return *this;
        }

        // required for operation equal
        bool operator==(const Point2D& other)
        {
            return (x == other.x && y == other.y);
        }

        // required for operation not equal
        bool operator!=(const Point2D& other)
        {
            return !(x == other.x && y == other.y);
        }

        // Getter method for x and y
        std::array<T, 2> get() const
        {
            return std::array<T, 2> {x, y};
        }

        // Setter method
        void set(T x_val, T y_val)
        {
            x = x_val;
            y = y_val;
        }

        virtual void set(const Axis axis, const T value)
        {
            switch (axis)
            {
                case Axis::X:
                    this->x = value;
                    break;
                case Axis::Y:
                    y = value;
                    break;
                default:
                    throw std::invalid_argument("Invalid axis");
            }
        }

        friend std::ostream& operator<<(std::ostream& os, const Point2D<T>& pt)
        {
            os << "Point2D(" << pt.get().at(0) << ", " << pt.get().at(1) << ")";
            return os;
        }

        // TODO: Add support for std::print() in c++23
};
