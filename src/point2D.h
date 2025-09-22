#pragma once
#include <boost/operators.hpp>
#include <iostream>
#include <vector>

template <typename T>
class Point2D
    : public boost::addable<Point2D<T>>
    , public boost::subtractable<Point2D<T>>
{
    protected:
        T x, y;

    public:
        // Default constructor
        Point2D() : x(T {}), y(T {}) {}
        Point2D(T x_val, T y_val) : x(x_val), y(y_val) {}

        // Default destructor
        virtual ~Point2D() {}

        // Copy constructor
        Point2D(const Point2D& other) : x(other.x), y(other.y) {}

        // Copy assignment
        Point2D& operator=(const Point2D& other)
        {
            x = other.x;
            y = other.y;
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
            }
            return *this;
        }

        // Required for operator addable
        Point2D<T>& operator+=(const Point2D<T>& rhs)
        {
            x += rhs.x;
            y += rhs.y;
            return *this;
        }

        // Required for operator subtractable
        Point2D<T>& operator-=(const Point2D<T>& rhs)
        {
            x -= rhs.x;
            y -= rhs.y;
            return *this;
        }

        // Getter methods for x and y
        T getX() const
        {
            return x;
        }

        T getY() const
        {
            return y;
        }

        virtual std::vector<T> get() const
        {
            std::vector<T> coord({x, y});
            return coord;
        }

        // Setter method
        virtual void set(T x_val, T y_val)
        {
            x = x_val;
            y = y_val;
        }

        friend std::ostream& operator<<(std::ostream& os, const Point2D<T>& pt)
        {
            os << "Point2D(" << pt.getX() << ", " << pt.getY() << ")";
            return os;
        }
};
