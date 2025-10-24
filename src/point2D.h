#pragma once
#include <boost/operators.hpp>
#include <concepts>
#include <iostream>
#include <print>

template <typename T>
    requires std::integral<T> || std::floating_point<T>
class Point2D
    : public boost::addable<Point2D<T>>
    , public boost::subtractable<Point2D<T>>
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
            if (this != other)
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

        // Required for operation addable
        Point2D& operator+=(const Point2D& rhs)
        {
            x += rhs.x;
            y += rhs.y;
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

        friend std::ostream& operator<<(std::ostream& os, const Point2D<T>& pt)
        {
            os << "Point2D(" << pt.get().at(0) << ", " << pt.get().at(1) << ")";
            return os;
        }
};
