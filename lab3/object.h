//
// Created by Justyna on 19.09.2017.
//

#ifndef LAB3_OBJECT_H
#define LAB3_OBJECT_H

#include <iostream>
class Polygon;
class Point
{
    float x;
    float y;
    friend class Polygon;
public:
    Point();
    Point(float x = 1, float y = 1) : x(x), y(y) {}
    friend std::ostream& operator<< (std::ostream&, const Point&);
    float getX() const {return x;}
    float getY() const {return y;}
};

class Polygon
{
    Point* array;
    int size;
    int count = 0;
public:
    Polygon(int size = 20);
    friend std::ostream& operator<< (std::ostream&, const Polygon&);
    Polygon(const Polygon&); //konstruktor kopiujący
    virtual ~Polygon(); //domyślne funkcje skłądowe nie są dynamicznie wiązene, potrzebny modyfikator "virtual"
    Polygon& operator= (Polygon&);
    int getCount() const { return count;}
    void insert(const Point&);
    Point& operator[] (int i);
    Point* getPoint(int i) const;
};
