//
// Created by Justyna on 19.09.2017.
//

#include "object.h"
using namespace std;

Point::Point() {
    x = 1.0;
    y = 1.0;
}

ostream& operator<< (ostream& os, const Point& o) {
    os << "x: " << o.x <<"y: "<<o.y<< endl;
    return os;
}

//----------------------------------------

Polygon::Polygon(int size) : size(size)
{
    array = new Point[size];
}

ostream& operator<< (ostream& os, const Polygon& p)
{
    for(int i=0;i<p.count;i++)
        os << ": " << p.array[i].getX() << ": "<<p.array[i].getY()<< endl;
    return os;
}

/* KONSTRUKTOR KOPIUJĄCY
 * może zostać wywołany niejawnie przez kompilator jeśli zajdzie potrzeba
 * stworzenia drugiej instancji obiektu
 * trzeba go zadeklarować jako konstruktor o jednym parametrze będącym referencją
 * na obiekt tej samej klasy
 * w przypadku insrukcji inicjujących alokację pamięci niejawny konstruktor kopiujący
 * stworzy obiekt wskazzujący na ten sm fragment pamięci co objekt wzorowany  co nie
 * jest zamierzany mefektem
 * w takim przypadku trzeba samemu zaimplementować konstruktor kopiujący:
 */

Polygon::Polygon(const Polygon& p)
{
    array = new Point[p.size];
    size = p.size;
    count = p.count;
    for(int i=0; i<p.size; i++)
    {
        array[i].x = p.array[i].x;
        array[i].x = p.array[i].y;
    }
}

Polygon::~Polygon()
{
    delete [] array;
}

Polygon& Polygon::operator=(Polygon &p)
{
    size = p.size;
    count = p.count;
    delete []array;
    array = new Point[size];
    for (int i=0; i<count; ++i)
    {
        array[i].x = p.array[i].x;
        array[i].y = p.array[i].y;
    }
}

void Polygon::insert(const Point& p)
{
    if(count == size)
    {
        string e = "Array is full.";
        throw e;
    }
    array[count] = p;
    count++;
}

Point& Polygon::operator[](int i)
{
    if (i < 0 or i >= count)
    {
        string e = "Wrong index";
        throw e;
    }
    return array[i];
}

Point* Polygon::getPoint(int i) const
{
    if (i < 0 or i >= count)
    {
        string e = "Wrong index";
        throw e;
    }
    return &array[i];
}
