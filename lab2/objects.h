#ifndef OBJECTS_H
#define OBJECTS_H
#include <iostream>

class Matrix;

 class Point
 {
    double x;
    double y;

public:
  Point();
  Point(double x1, double y1) : x(x1), y(y1) {};

  friend std::ostream &operator<< (std::ostream &os, const Point&);

  Point& operator-= (Point&); //x -= y
  Point operator- (const Point&); //a = x - y
  Point& operator- (); //-x
  Point operator-- (int);
  Point operator-- ();

  friend Point operator* (const Point&, Matrix&);
  friend Point operator* (Matrix&, const Point&);

  void displayPoint();
 };

 class Matrix
 {
    double mxx;
    double myy;
    double mxy;

public:
    Matrix();
    Matrix(double mxx1, double myy1, double mxy1) : mxx(mxx1), myy(myy1), mxy(mxy1) {};

    friend std::ostream &operator << (std::ostream &os, const Matrix&);

    Matrix& operator-= (Matrix&);
    Matrix operator- (const Matrix&);
    Matrix& operator- ();
    Matrix operator-- (int);
    Matrix operator-- ();

    friend Point operator* (const Point&, Matrix&);
    friend Point operator* (Matrix&, const Point&);

    friend Matrix operator* (int, const Matrix&);
    friend Matrix operator* (const Matrix&, int);

    void displayMatrix();
 };
 #endif
