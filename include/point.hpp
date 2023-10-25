/** \file point.hpp */
#pragma once

#include <iostream>

/**
 * @struct Point
 * @brief 2D point: (x, y).
 *
 * @tparam T - type of Point internal x,y  data
 */
template <typename T>
struct Point {
    T x;
    T y;

    bool operator==(const Point& other) const { return x == other.x && y == other.y; }
    bool operator!=(const Point& other) const { return !(*this == other); }
};

template <typename T>
inline std::istream& operator>>(std::istream& is, Point<T>& point) {
    return is >> point.x >> point.y;
}

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const Point<T>& point) {
    return os << "(" << point.x << ", " << point.y << ")";
}
