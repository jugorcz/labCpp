#include <iostream>
#include <fstream>
#include "point.h"
#include <math.h>
using namespace std;

int Point::counter = 0; //statyczne dane muszą być zadeklarowane poza definicją klasy

Point::Point()
{
    x=0;
    y=0;
    z=0;
    counter++;
}

Point::Point(float a, float b, float c)
{
    x=a,
    y=b;
    z=c;
    counter++;
}

float Point::distance(Point p)
{
    float a = p.x-x;
    float b = p.y-y;
    float c = p.z-z;
    return ((float)sqrt(a*a + b*b + c*c));
}

void Point::read(ifstream &is)
{
    string line;
    is >> line;
    x = line[1] - 48;
    y = line[3] - 48;
    z = line[5] - 48;
}
