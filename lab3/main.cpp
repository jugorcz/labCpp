#include <iostream>
#include "object.h"
using namespace std;

int main(int argc, char** argv)
{

    try{
        Polygon p1(5);
        Polygon p2=p1;
        Point point1(2,3);
        Point point2(10,10);
        Point point3;
        p1.insert(point1);
        p1.insert(point2);
        p1.insert(point3);
        cout<<p1.getCount()<<"\n";
    }
    catch (int e){
        cout<< "ERROR "<< endl;
    }
    catch (exception &e) {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}
