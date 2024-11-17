#pragma once
#include <vector>
#include <iostream>

template <typename T>
class Point2D
{
protected:
    T x, y;

public:
    // Constructor to initialize x and y
    Point2D(T x_val, T y_val) : x(x_val), y(y_val) {}
    Point2D() {}
    ~Point2D() {}

    // Getter methods for x and y
    T getX() const { return x; }
    T getY() const { return y; }
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

    // Virtual method to print the point
    virtual void print() const
    {
        std::cout << "Point2D(" << x << ", " << y << ")\n";
    }
};

template <typename T>
class Point3D : public Point2D<T>
{
protected:
    T z;

public:
    // Constructor to initialize x, y from the base class, and z for this class
    Point3D(T x_val, T y_val, T z_val) : Point2D<T>(x_val, y_val), z(z_val) {}
    Point3D() {}
    ~Point3D() {}

    // Getter method for z
    T getZ() const { return z; }
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

template <typename T>
class Point3D4 : public Point3D<T>
{
protected:
    T s;

public:
    Point3D4() {};
    Point3D4(T _x, T _y, T _z) : Point3D<T>(_x, _y, _z), s(1) {};
    Point3D4(T _x, T _y, T _z, T _s) : Point3D<T>(_x, _y, _z), s(_s) {};
    ~Point3D4() {};

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
    T getS() const { return s; }
};
