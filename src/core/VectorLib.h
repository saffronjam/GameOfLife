#pragma once

#include <utility>
#include <cmath>

#include <SFML/System/Vector2.hpp>

class vl
{
public:
    template <typename T>
    static sf::Vector2<T> LineMiddlePoint(const sf::Vector2<T> &point1, const sf::Vector2<T> &point2);
    template <typename T>
    static sf::Vector2<T> Direction(const sf::Vector2<T> &point1, const sf::Vector2<T> &point2);
    template <typename T>
    static sf::Vector2<T> Unit(const sf::Vector2<T> &vector);
    template <typename T>
    static sf::Vector2<T> Null();
    template <typename T>
    static sf::Vector2<T> Perpendicular(const sf::Vector2<T> &vector);
    template <typename T>
    static sf::Vector2<T> Rotate(const sf::Vector2<T> &vector, float angle, const sf::Vector2<T> &around);
    template <typename T>
    static float Length(const sf::Vector2<T> &vector);
    template <typename T>
    static float LengthSq(const sf::Vector2<T> &vector);
    template <typename T>
    static float Distance(const sf::Vector2<T> &u, const sf::Vector2<T> &v);
    template <typename T>
    static void Normalize(sf::Vector2<T> &vector);
    template <typename T>
    static float Angle(const sf::Vector2<T> &v1, const sf::Vector2<T> &v2);
    template <typename T>
    static float Slope(sf::Vector2<T> point1, sf::Vector2<T> point2);
    template <typename T>
    static float DistanceFromLine(sf::Vector2<T> linePoint1, sf::Vector2<T> linePoint2, sf::Vector2<T> point);
    template <typename T>
    static float Determinant(const sf::Vector2<T> &u, const sf::Vector2<T> &v);
    template <typename T>
    static float DotProduct(const sf::Vector2<T> &u, const sf::Vector2<T> &v);
};

template <typename T>
sf::Vector2<T> vl::LineMiddlePoint(const sf::Vector2<T> &point1, const sf::Vector2<T> &point2)
{
    sf::Vector2<T> delta = point2 - point1;
    delta.x /= 2.0f;
    delta.y /= 2.0f;
    return point1 + delta;
}

template <typename T>
sf::Vector2<T> vl::Direction(const sf::Vector2<T> &point1, const sf::Vector2<T> &point2)
{
    return vl::Unit(point2 - point1);
}

template <typename T>
sf::Vector2<T> vl::Unit(const sf::Vector2<T> &vector)
{
    return vector / vl::Length(vector);
}

template <typename T>
sf::Vector2<T> vl::Null()
{
    return sf::Vector2<T>(0, 0);
}

template <typename T>
sf::Vector2<T> vl::Perpendicular(const sf::Vector2<T> &vector)
{
    return sf::Vector2<T>(-vector.y, vector.x);
}

template <typename T>
sf::Vector2<T> vl::Rotate(const sf::Vector2<T> &vector, float angle, const sf::Vector2<T> &around)
{
    auto anchor = vector -= around;

    const float cosTheta = cos(angle);
    const float sinTheta = sin(angle);
    const float new_x = anchor.x * cosTheta - anchor.y * sinTheta;
    anchor.y = anchor.x * sinTheta + anchor.y * cosTheta;
    anchor.x = new_x;

    return anchor + around;
}

template <typename T>
float vl::Length(const sf::Vector2<T> &vector)
{
    return sqrt(vl::LengthSq(vector));
}

template <typename T>
float vl::LengthSq(const sf::Vector2<T> &vector)
{
    return vector.x * vector.x + vector.y * vector.y;
}

template <typename T>
float vl::Distance(const sf::Vector2<T> &u, const sf::Vector2<T> &v)
{
    return sqrt(pow(u.x - v.x, 2) + pow(u.y - v.y, 2));
}

template <typename T>
void vl::Normalize(sf::Vector2<T> &vector)
{
    float length = vl::Length(vector);
    if (length != 0.0f)
    {
        vector.x /= length;
        vector.y /= length;
    }
}

template <typename T>
float vl::Slope(sf::Vector2<T> point1, sf::Vector2<T> point2)
{
    if (point1.x > point2.x)
    {
        std::swap(point1, point2);
    }
    return (point2.y - point1.y) / (point2.x - point1.x);
}

template <typename T>
float vl::DistanceFromLine(sf::Vector2<T> linePoint1, sf::Vector2<T> linePoint2, sf::Vector2<T> point)
{
    return abs(((linePoint2.x - linePoint1.x) * (point.y - linePoint1.y) - (linePoint2.y - linePoint1.y) * (point.x - linePoint1.x)) / vl::Length(linePoint2 - linePoint1));
}
