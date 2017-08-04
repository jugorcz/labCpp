#include <iostream>
#include <fstream>
#include "point.h"
using namespace std;

int main()
{
    Point p1;
    Point p2(1,2);
    Point p3(3,6,8);

    p1.displayPoint();
    p2.displayPoint();
    p3.displayPoint();

    float a = p1.distance(p2);
    cout<<endl<<"Odleglosz pomiedzy dwoma punktami: "<<a<<endl;

    Point::displayCounter();

    //ofstream os;
    //os.open("points.txt", ios::out|ios::app); //będzie dopisywane na koniec pliku
    ofstream os("points.txt");
    if(os.good())
        p3.write(os);

    ifstream is("points.txt");
    if(is.good())
        p1.read(is);
    p1.displayPoint();
    return 0;
}
