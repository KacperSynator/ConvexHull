#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

#include "convex_hull.hpp"
#include "point.hpp"

using convex_hull::convexHull;

template <typename T>
using Points = std::vector<Point<T>>;

template <typename T>
std::ostream& operator<<(std::ostream& os, const Points<T>& points) {
    os << "[";
    std::for_each(points.begin(), points.end(), [&](const auto& point) {
        os << point;
        if (point != points.back()) {
            os << ", ";
        }
    });
    return os << "]";
}

int main(int argc, char* argv[]) {
    std::string filename;

    if (argc == 1) {
        std::cout << "Filepath not given, please enter filepath: ";
        std::cin >> filename;
    } else {
        filename = argv[1];
    }

    std::ifstream ifs(filename);
    if (!ifs.is_open()) {
        std::cerr << "Cannot open file: " << filename << "\n";
        return 1;
    }

    int num_points;
    ifs >> num_points;

    Points<float> points(num_points);

    std::for_each(points.begin(), points.end(), [&ifs](auto& point) { ifs >> point; });

    auto convexHullPoints = convexHull(points);

    std::cout << "Convex hull points: " << convexHullPoints << "\n";
}
