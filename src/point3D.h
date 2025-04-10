#pragma once
#include "point2D.h"
#include <boost/operators.hpp>
#include <iostream>
#include <vector>

template <typename T>
class Point3D
    : public Point2D<T>
    , public boost::addable<Point3D<T>>
    , public boost::subtractable<Point3D<T>>
{
    protected:
        T z;

    public:
        // Constructor to initialize x, y from the base class, and z for this class
        Point3D(T x_val, T y_val, T z_val) : Point2D<T>(x_val, y_val), z(z_val) {}

        Point3D() {}

        ~Point3D() {}

        // Required for operator addable
        Point3D<T> operator+=(const Point3D<T>& rhs)
        {
            this->x += rhs.x;
            this->y += rhs.y;
            this->z += rhs.z;
            return *this;
        }

        // Required for operator substractable
        Point3D<T> operator-=(const Point3D<T>& rhs)
        {
            this->x -= rhs.x;
            this->y -= rhs.y;
            this->z -= rhs.z;
            return *this;
        }

        // Getter method for z
        T getZ() const
        {
            return z;
        }

        std::vector<T> get() const override
        {
            std::vector<T> coord({this->x, this->y, z});
            return coord;
        }

        // Setter method
        void set(T x_val, T y_val, T z_val)
        {
            this->x = x_val;
            this->y = y_val;
            z = z_val;
        }

        // Override the print method to include z
        void print() const override
        {
            std::cout << "Point3D(" << this->x << ", " << this->y << ", " << z << ")\n";
        }
};
