#pragma once
#include <string>
namespace ariel{
    class Point
    {
    private:
        double _xCor;
        double _yCor;
    public:
        Point();
        Point(double xCor , double yCor);
        double distance( Point other) const;
        std :: string print()const;
        static Point moveTowards(const Point& src ,const  Point& dst , double distance);
        double getX()const;
        double getY()const;
        
    };
}


