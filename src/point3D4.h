#pragma once
#include "point3D.h"
#include <boost/operators.hpp>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <vector>

template <typename T>
class Point3D4
    : public Point3D<T>
    , public boost::addable<Point3D4<T>>
    , public boost::subtractable<Point3D4<T>>
{
    protected:
        T s;

    public:
        Point3D4() {}

        Point3D4(T _x, T _y, T _z) : Point3D<T>(_x, _y, _z), s(1) {}

        Point3D4(T _x, T _y, T _z, T _s) : Point3D<T>(_x, _y, _z), s(_s) {}

        ~Point3D4() {}

        // Required for operator addable
        Point3D4<T> operator+=(const Point3D4<T>& rhs)
        {
            this->x += rhs.x;
            this->y += rhs.y;
            this->z += rhs.z;
            (this->s == 1 && rhs.s == 1) ? this->s = 1 : throw std::invalid_argument("scale of one of the point is not equal to `1`");
            return *this;
        }

        // Required for operator substractable
        Point3D4<T> operator-=(const Point3D4<T>& rhs)
        {
            this->x -= rhs.x;
            this->y -= rhs.y;
            this->z -= rhs.z;
            (this->s == 1 && rhs.s == 1) ? this->s = 1 : throw std::invalid_argument("scale of one of the point is not equal to `1`");
            return *this;
        }

        void print() const override
        {
            std::cout << "Point3D4(" << this->x << ", " << this->y << ", " << this->z << ", " << s << ")\n";
        }

        void set(T x_val, T y_val, T z_val)
        {
            this->x = x_val;
            this->y = y_val;
            this->z = z_val;
        }

        void set(T x_val, T y_val, T z_val, T s_val)
        {
            this->x = x_val;
            this->y = y_val;
            this->z = z_val;
            s = s_val;
        }

        std::vector<T> get() const override
        {
            std::vector<T> coord({this->x, this->y, this->z, s});
            return coord;
        }

        T getS() const
        {
            return s;
        }
};
