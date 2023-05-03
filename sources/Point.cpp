#include "Point.hpp"
#include <stdexcept>
#include <cmath>
using namespace std;
namespace ariel
{

    Point::Point(double x, double y) : x(x), y(y) {}

    // Functions

    double Point::distance(const Point &other) const
    {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(pow(dx, 2) + pow(dy, 2));
    }

    void Point::print() const
    {
        cout << "(" << x << "," << y << ")";
    }

    Point Point::moveTowards(const Point &source, const Point &dest, double dist) const
    {
        double maxDistance = source.distance(dest);
        if (maxDistance < dist)
        {
            throw invalid_argument("Can't move byond the destination");
        }
        double ratio = dist / maxDistance;
        double newX = source.x + ratio * (dest.x - source.x);
        double newY = source.y + ratio * (dest.y - source.y);
        return Point(newX, newY);
    }

    // Getters and Setters

    double Point::getX() const
    {
        return x;
    }

    double Point::getY() const
    {
        return y;
    }

    void Point::setX(double x)
    {
        this->x = x;
    }

    void Point::setY(double y)
    {
        this->y = y;
    }

}