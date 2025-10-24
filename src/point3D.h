#pragma once
#include "point2D.h"
#include <algorithm>
#include <boost/operators.hpp>
#include <cctype>
#include <iostream>
#include <print>
#include <stdexcept>
#include <string>

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
        Point3D() : Point2D<T>(), z(T {}) {std::print("Point3D created without initialization.\n");}
        Point3D(T x_val, T y_val, T z_val) : Point2D<T>(x_val, y_val), z(z_val) {std::print("Point3D created with value [{0}, {1}, {2}].\n", x_val,y_val, z_val);}

        // default destructor
        virtual ~Point3D() {std::print("Point3D is destroyed.\n");}

        // Copy constructor
        Point3D(const Point3D& other)
        {
            if (this != &other) {
                this->x = other.x;
                this->y = other.y;
                z = other.z;
                std::print("Point3D is copied.\n");
            }
        }

        // Move constructor
        Point3D(Point3D&& other) noexcept
        {
            if (this != &other) {
                this->x = std::move(other.x);
                this->y = std::move(other.y);
                z = std::move(other.z);
                other.x = T{};
                other.y = T{};
                other.z = T {};
                std::print("Point3D is moved.\n");
            }
        }

        // Copy assigment
        Point3D& operator=(const Point3D& other)
        {
            if (this != &other) {
                this->x = other.x;
                this->y = other.y;
                z = other.z;
                std::print("Point3D is copied.\n");
            }
            return *this;
        }

        // Move asignment
        Point3D& operator=(Point3D&& other) noexcept
        {
            if (this != &other)
            {
                this->x = std::move(other.x);
                this->y = std::move(other.y);
                z = std::move(other.z);
                other.x = T {};
                other.y = T {};
                other.z = T {};
                std::print("Point3D is moved.\n");
            }
            return *this;
        }

        // Required for operator addable
        Point3D& operator+=(const Point3D& rhs)
        {
            this->x += rhs.x;
            this->y += rhs.y;
            z += rhs.z;
            return *this;
        }

        // Required for operator substractable
        Point3D& operator-=(const Point3D<T>& rhs)
        {
            this->x -= rhs.x;
            this->y -= rhs.y;
            z -= rhs.z;
            return *this;
        }

        // Required for operation equal
        bool operator==(const Point3D& rhs)
        {
            return ((this->x == rhs.x) && (this->y == rhs.y) && (z == rhs.z));
        }

        // required for not equal
        bool operator!=(const Point3D& rhs)
        {
            return !((this->x == rhs.x) && (this->y == rhs.y) && (z == rhs.z));
        }

        // Getter method
        std::array<T, 3> get() const
        {
            return std::array<T, 3> {this->x, this->y, z};
        }

        // Setter method
        void set(T x_val, T y_val, T z_val)
        {
            this->x = x_val;
            this->y = y_val;
            z = z_val;
        }

        void set(std::string axis, T value)
        {
            std::for_each(axis.begin(), axis.end(),
                          [](char& c) { c = std::tolower(c); }
                          );
            
            if (axis == "x") {
                this->x = value;
            }
            else if (axis == "y") {
                this->y = value;
            }
            else if (axis == "z") {
                z = value;
            }
            else {
                throw std::invalid_argument("Invalid argument. Argument must be either `x`, `y`, `z`");
            }
        }

        friend std::ostream& operator<<(std::ostream& os, const Point3D<T>& pt)
        {
            os << "Point3D(" << pt.get().at(0) << ", " << pt.get().at(1) << ", " << pt.get().at(2) << ")";
            return os;
        }
};
