#include <iostream>
#include "objects.h"
#include <math.h>

using namespace std;

Point::Point()
{
  x = 0;
  y = 0;
}

ostream& operator<< (ostream& os, const Point& p)
{
    os << "x: " << p.x << ", y: " << p.y <<endl;
}

Point& Point::operator-= (Point& p)
{
  cout<<"Point -= p   ";
  x -= p.x;
  y -= p.y;
  return *this;
}

Point Point::operator- (const Point& p)
{
    cout<<"p = Point - p  ";
    double x1 = x - p.x;
    double y1 = y - p.y;
    Point tmp(x1,y1);
    return tmp;
}

Point& Point::operator- ()
{
  cout<<"-Point  ";
    x = -x;
    y = -y;
    return *this;
}

Point Point::operator-- () //--x
{
    cout<<endl<<"Operator-- ";
    Point tmp;
    x -= 1.0;
    y -= 1.0;
    tmp.x = x;
    tmp.y = y;
    return tmp;
}

Point Point::operator-- (int) //x--
{
    cout<<endl<<"Operator-- int ";
    Point tmp;
    tmp.x = x;
    tmp.y = y;
    x -= 1.0;
    y -= 1.0;
    return tmp;
}

Point operator* (const Point& p, Matrix& m)
{
  cout<<"Point*Matrix  ";
  Point tmp;
  tmp.x = p.x*m.mxx + p.y*m.mxy;
  tmp.y = p.x*m.mxy + p.y*m.myy;
  return tmp;
}

Point operator* (Matrix& m, const Point& p)
{
  cout<<"Matrix*Point  ";
  Point tmp;
  tmp.x = p.x*m.mxx + p.y*m.mxy;
  tmp.y = p.x*m.mxy + p.y*m.myy;
  return tmp;
}

void Point::displayPoint()
{
  cout<<"("<<x<<","<<y<<")"<<endl;
}

//---------Matrix------------------------------------------------------------
Matrix::Matrix()
{
  mxx = 0;
  myy = 0;
  mxy = 0;
}

ostream& operator<< (ostream& os, const Matrix& m)
{
    os << "mxx: " << m.mxx << ", myy: " << m.myy<< ", mxy:" <<m.mxy<<endl;
}

Matrix& Matrix::operator-= (Matrix& m1)
{
  cout<<"Matrix -= m"<<endl;
  mxx -= m1.mxx;
  myy -= m1.myy;
  mxy -= m1.mxy;
  return *this;
}

Matrix Matrix::operator- (const Matrix& m1)
{
  cout<<"m = Matrix - m"<<endl;
  double mxx1 = mxx - m1.mxx;
  double myy1 = myy - m1.myy;
  double mxy1 = mxy - m1.mxy;
  Matrix tmp(mxx1, myy1, mxy1);
  return tmp;
}

Matrix& Matrix::operator- ()
{
  cout<<"-Matrix"<<endl;
    mxx = -mxx;
    myy = -myy;
    mxy = -mxy;
    return *this;
}

Matrix operator* (const Matrix& m, int a)
{
    cout<<"m * p"<<endl;
    Matrix tmp;
    tmp.mxx = a * m.mxx;
    tmp.myy = a * m.myy;
    tmp.mxy = a * m.mxy;
    return tmp;
}

Matrix operator* (int a, const Matrix& m)
{
    cout<<"p * m"<<endl;
    Matrix tmp;
    tmp.mxx = a * m.mxx;
    tmp.myy = a * m.myy;
    tmp.mxy = a * m.mxy;
    return tmp;
}

Matrix Matrix::operator-- (int)
{
    cout<<"Matrix--"<<endl;
    Matrix tmp;
    tmp.mxx = mxx;
    tmp.myy = myy;
    tmp.mxy = mxy;
    mxx -= 1.0;
    myy -= 1.0;
    mxy -= 1.0;
    return tmp;
}

Matrix Matrix::operator-- ()
{
    cout<<"--Matrix"<<endl;
    Matrix tmp;
    mxx -= 1.0;
    myy -= 1.0;
    mxy -= 1.0;
    tmp.mxx = mxx;
    tmp.myy = myy;
    tmp.mxy = mxy;
    return tmp;
}

void Matrix::displayMatrix()
{
  cout<<"|"<<mxx<<","<<mxy<<"|"<<endl;
  cout<<"|"<<mxy<<","<<myy<<"|"<<endl;
}
