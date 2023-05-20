#include <cmath>
#include <iostream>
#include "Point.hpp"
using namespace ariel;
using namespace std;

Point :: Point():_xCor(0),_yCor(0){}
Point::Point(double xCor , double yCor):_xCor(xCor),_yCor(yCor){}

double Point:: distance(Point other) const{
    double dx = _xCor - other._xCor;
    double dy = _yCor - other._yCor;
    return sqrt(dx * dx + dy * dy);
}
string Point:: print()const{
   return "("+to_string(_xCor)+","+to_string(_yCor)+")";
}
Point Point:: moveTowards(const Point& src ,const Point& dst , double distance){
     if (distance < 0) {
        throw std::invalid_argument("distance can't be below zero");
    }
    double dist = src.distance(dst);

    // If the distance is less than or equal to the maximum distance, the destination point is the closest point
    if (dist <= distance) {
        return dst;
    }

    // Otherwise, we need to find the point on the line between the source and destination points
    // that is at most the maximum distance away from the source point
    double ratio = distance / dist;
    double x = src.getX() + (dst.getX() - src.getX()) * ratio;
    double y = src.getY() + (dst.getY() - src.getY()) * ratio;

    Point closetPoint(x,y);
    return closetPoint;
}
double Point :: getX()const{
    return _xCor;
}
double Point :: getY()const{
    return _yCor;
}
