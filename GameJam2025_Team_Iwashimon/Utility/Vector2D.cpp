#include "Vector2D.h"

void Vector2D::operator=(const Vector2D& location)
{
    this->x = location.x;
    this->y = location.y;
}

void Vector2D::operator+=(const Vector2D& location)
{
    this->x += location.x;
    this->y += location.y;
}

void Vector2D::operator-=(const Vector2D& location)
{
    this->x -= location.x;
    this->y -= location.y;
}

void Vector2D::operator*=(const Vector2D& location)
{
    this->x *= location.x;
    this->y *= location.y;
}

void Vector2D::operator=(float scalar)
{
    this->x = scalar;
    this->y = scalar;
}

void Vector2D::operator+=(float scalar)
{
    this->x += scalar;
    this->y += scalar;
}

void Vector2D::operator-=(float scalar)
{
    this->x -= scalar;
    this->y -= scalar;
}

void Vector2D::operator*=(float scalar)
{
    this->x *= scalar;
    this->y *= scalar;
}

const Vector2D Vector2D::operator+(const Vector2D& location)
{
    Vector2D ret;

    ret.x = this->x + location.x;
    ret.y = this->y + location.y;

    return ret;
}

const Vector2D Vector2D::operator-(const Vector2D& location)
{
    Vector2D ret;

    ret.x = this->x - location.x;
    ret.y = this->y - location.y;

    return ret;
}

const Vector2D Vector2D::operator*(const Vector2D& location)
{
    Vector2D ret;

    ret.x = this->x * location.x;
    ret.y = this->y * location.y;

    return ret;
}

void Vector2D::ToInt(int* x, int* y)
{
    *x = static_cast<int>(this->x);
    *y = static_cast<int>(this->y);
}