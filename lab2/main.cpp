#include "objects.h"
#include <fstream>

using namespace std;

int main()
{
  Point p1(2,2);
  Point p2(2.6,4.8);
  Matrix m1;
  Matrix m2(3.3,4.4,5.5);

  cout<<"Point 1: ";
  p1.displayPoint();
  cout<<"Point 2: ";
  p2.displayPoint();
  cout<<endl<<"Matrix 1:"<<endl;
  m1.displayMatrix();
  cout<<"Matrix 2:"<<endl;
  m2.displayMatrix();
  cout<<endl;

  ofstream out("plik1.txt");
  out<<m2<<p2<<p1<<m1;

  Point tmpP;
  Matrix tmpM(1,1,1);

  p1 -= p2;
  p1.displayPoint();

  -p1;
  p1.displayPoint();

  tmpP = p2 - p1;
  tmpP.displayPoint();

  --tmpP;
  tmpP.displayPoint();

  tmpP--;
  tmpP.displayPoint();

  tmpP = p1 * tmpM;
  tmpP.displayPoint();

  tmpP = tmpM * p1;
  tmpP.displayPoint();

//----------MatrixE----------------------------
  cout<<endl;
  tmpM -= m2;
  tmpM.displayMatrix();
  cout<<endl;

  tmpM = m1 - m2;
  tmpM.displayMatrix();

  -tmpM;
  tmpM.displayMatrix();

  tmpM--;
  tmpM.displayMatrix();

  --tmpM;
  tmpM.displayMatrix();

  tmpM = tmpM * 2;
  tmpM.displayMatrix();

  tmpM = 2 * tmpM;
  tmpM.displayMatrix();
}
