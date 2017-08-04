#include <iostream>
#include <fstream>

class Point
{
    static int counter; //zmienna statyczna jest powi?zana z klas?, nie obiektem, wyst?puje tylko jeden jej egzemplarz
    float x;
    float y;
    float z;

public:
    Point();
    Point(float a, float b, float c = 0);

    float getX() { return x; }
    float getY() { return y; }
    float getZ() { return z; }
    void setX(float a) { x = a; }
    void setY(float b) { y = b; }
    void setZ(float c) { z = c; }

    float distance (Point p);

    void displayPoint() {std::cout<<std::endl<<"Punkt p: ("<<x<<","<<y<<","<<z<<")";}
    static void displayCounter() { std::cout << "Licznik: " << counter; }

    void write(std::ofstream& os) { os << "(" << x << "," << y << "," << z << ")" << std::endl;}
    void read(std::ifstream& is);
};
