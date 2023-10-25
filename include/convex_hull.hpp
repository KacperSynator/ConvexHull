/** \file convex_hull.hpp */
#pragma once

#include <algorithm>
#include <cmath>
#include <vector>

#include "point.hpp"

namespace convex_hull {
namespace {
template <typename T>
using Points = std::vector<Point<T>>;

/**
 * @brief Orientation of three ordered points. The points can be `Coolinear`, `Clockkwise`  or `CountterClockwise`
 * @enum Orientation
 */
enum class Orientation { Collinear = 0, Clockwise = 1, CounterClockwise = 2 };

/**
 * @brief Calculates the orientaion between three points, based on their slopes.
 * The following equation is used for calculating the orientaion: \n
 * `(b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y)`
 * @tparam T - data type of a `Point`
 * @param a - first  `Point`
 * @param b - second `Point`
 * @param c - third `Point`
 * @return `Orientation` enum
 */
template <typename T>
Orientation calculateOrientation(Point<T> a, Point<T> b, Point<T> c) {
    T val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);

    if (val < 0) {
        return Orientation::CounterClockwise;
    }

    if (val > 0) {
        return Orientation::Clockwise;
    }

    return Orientation::Collinear;
}

/**
 * @brief Compares two Points based on y value. If equals compares the x value.
 * @tparam T - data type of a `Point`
 * @param a - first `Point`
 * @param b  - second `Point`
 * @return true if Point a is smaller than Point b based on y value (if equals on x) otherwise false
 */
template <typename T>
bool comparePointsByY(Point<T> a, Point<T> b) {
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}

/**
 * @brief Calculates the a squared distance between two Points:
 * The following equation is used for calculating the orientaion: \n
 * `(a.x - b.x)^2 + (a.y - b.y)^2`
 * @tparam T - data type of a `Point`
 * @param a - first `Point`
 * @param b - second `Point`
 * @return T
 */
template <typename T>
T distanceSquared(Point<T> a, Point<T> b) {
    return std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2);
}
}  // namespace

/**
 * @brief Calculates the convex hull of set of `Points` using Graham scan algorithm.
 * The algorithm consist of few key parts:
 * 1. Check if at least 4 `Points` were given.
 * 2. Find the minimal element based on y value (x when y equal) and insert it at the beginning of the `points` vector.
 * 3. Sort the rest of the vector based on polar angle (distance when equal,here the distance squared is calculated).
 * 4. For each 3 next points in `Points` vector check if the orientation is `CounterClockwise` if yes then push the
 * smallest (by polar angle) `Point` to the stack, if not pop the last point from stack, repeat until the end of
 * `points`.
 * 5. Return the stack (vector) containig all the convex hull points.
 * For further reference look at [Wikipedia - Graham scan](https://en.wikipedia.org/wiki/Graham_scan).
 * @tparam T - data type of `Points`
 * @param points - vector of points, to run the algorithm the size of at least 4 `Points` is neede
 * @return Points<T> - the convex hull points as a vector or given `points` if its size is less than 3
 */
template <typename T>
inline Points<T> convexHull(Points<T> points) {
    if (points.size() < 3) {
        return points;
    }

    auto minPointIter = std::min_element(points.begin(), points.end(), comparePointsByY<T>);
    std::swap(*minPointIter, *points.begin());
    auto minPoint = points.front();

    auto comparePointsByPolarAngle = [&minPoint](const auto& a, const auto& b) {
        auto orientation = calculateOrientation(minPoint, a, b);

        if (Orientation::Collinear == orientation) {
            return distanceSquared(minPoint, a) > distanceSquared(minPoint, b);
        }

        return Orientation::CounterClockwise == orientation;
    };

    std::sort(points.begin() + 1, points.end(), comparePointsByPolarAngle);

    Points<T> hull;

    for (const auto& point : points) {
        while (hull.size() >= 2 &&
               calculateOrientation(*(hull.end() - 2), *(hull.end() - 1), point) != Orientation::CounterClockwise) {
            hull.pop_back();
        }
        hull.push_back(point);
    }

    return hull;
}
}  // namespace convex_hull
