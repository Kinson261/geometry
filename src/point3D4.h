#pragma once
#include "axis.h"
#include "point3D.h"
#include <algorithm>
#include <boost/operators.hpp>
#include <iostream>
#include <ostream>
#include <stdexcept>

template <typename T>
class Point3D4
    : public Point3D<T>
    , public boost::addable<Point3D4<T>>
    , public boost::subtractable<Point3D4<T>>
{
    private:
        T s;

    public:
        // default constructor
        Point3D4() : Point3D<T>(), s(T {1})
        {
            std::print("Point3D4 created without initialization.\n");
        }

        Point3D4(T x_val, T y_val, T z_val) : Point3D<T>(x_val, y_val, z_val), s(T {1})
        {
            std::print("Point3D4 created with value [{0}, {1}, {2}, {3}].\n", x_val, y_val, z_val, s);
        }

        Point3D4(T x_val, T y_val, T z_val, T s_val) : Point3D<T>(x_val, y_val, z_val), s(s_val)
        {
            std::print("Point3D4 created with value [{0}, {1}, {2}, {3}].\n", x_val, y_val, z_val, s_val);
        }

        // default destructor
        ~Point3D4()
        {
            std::print("Point3D4 is destroyed\n");
        }

        // Copy constructor
        Point3D4(const Point3D4& other)
        {
            if (this != &other)
            {
                this->x = other.x;
                this->y = other.y;
                this->z = other.z;
                s = other.s;
                std::print("Point3D4 is copied\n");
            }
        }

        // Move constructor
        Point3D4(Point3D4&& other) noexcept
        {
            if (this != &other)
            {
                this->x = std::move(other.x);
                this->y = std::move(other.y);
                this->z = std::move(other.z);
                s = std::move(other.s);
                other.x = T {};
                other.y = T {};
                other.z = T {};
                s = T {};
                std::print("Point3D4 is moved\n");
            }
        }

        // Copy assigment
        Point3D4& operator=(const Point3D4& other)
        {
            if (this != &other)
            {
                this->x = other.x;
                this->y = other.y;
                this->z = other.z;
                s = other.s;
                std::print("Point3D4 is copied\n");
            }
            return *this;
        }

        // Move assignment
        Point3D4& operator=(Point3D4&& other) noexcept
        {
            if (this != &other)
            {
                this->x = std::move(other.x);
                this->y = std::move(other.y);
                this->z = std::move(other.z);
                s = std::move(other.s);
                other.x = T {};
                other.y = T {};
                other.z = T {};
                s = T {};
                std::print("Point3D4 is moved\n");
            }
            return *this;
        }

        // Required for operator addable
        Point3D4& operator+=(const Point3D4& rhs)
        {
            this->x += rhs.x;
            this->y += rhs.y;
            this->z += rhs.z;
            (s == 1 && rhs.s == 1) ? this->s = 1 : throw std::invalid_argument("scale of one of the point is not equal to `1`");
            return *this;
        }

        // Required for operator substractable
        Point3D4& operator-=(const Point3D4<T>& rhs)
        {
            this->x -= rhs.x;
            this->y -= rhs.y;
            this->z -= rhs.z;
            (this->s == 1 && rhs.s == 1) ? this->s = 1 : throw std::invalid_argument("scale of one of the point is not equal to `1`");
            return *this;
        }

        // Require for operator equal
        bool operator==(const Point3D4& rhs)
        {
            return ((this->x == rhs.x) && (this->y == rhs.y) && (this->z == rhs.z) && (s == rhs.s));
        }

        // Require for operator not equal
        bool operator!=(const Point3D4& rhs)
        {
            return !((this->x == rhs.x) && (this->y == rhs.y) && (this->z == rhs.z) && (s == rhs.s));
        }

        void set(T x_val, T y_val, T z_val)
        {
            this->x = x_val;
            this->y = y_val;
            this->z = z_val;
            s = T {1};
        }

        void set(T x_val, T y_val, T z_val, T s_val)
        {
            this->x = x_val;
            this->y = y_val;
            this->z = z_val;
            s = s_val;
        }

        void set(const Axis axis, const T value) override
        {
            switch (axis)
            {
                case Axis::X:
                    this->x = value;
                    break;
                case Axis::Y:
                    this->y = value;
                    break;
                case Axis::Z:
                    this->z = value;
                    break;
                case Axis::S:
                    s = value;
                    break;
                default:
                    throw std::invalid_argument("Invalid axis");
            }
        }

        std::array<T, 4> get() const
        {
            return std::array<T, 4> {this->x, this->y, this->z, s};
        }

        friend std::ostream& operator<<(std::ostream& os, const Point3D4<T>& pt)
        {
            os << "Point3D4(" << pt.get().at(0) << ", " << pt.get().at(1) << ", " << pt.get().at(2) << ", " << pt.get().at(3) << ")";
            return os;
        }

        // TODO: Add support for std::print() in c++23
};
