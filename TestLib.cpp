#include "TestLib.hpp"

namespace TestLib {
    Point* coordsVector_impl(const Point& start, const Point& end) {
        Point coords {end.x - start.x, end.y - start.y};
        return new Point(coords);
    }

    Point coordsVector(const Point& start, const Point& end) {
        return *coordsVector_impl(start, end);
    }
}
