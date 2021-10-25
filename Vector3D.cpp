// Vector3D.cpp
// application of Vector3D class

#include "Vector3D.h"
#include <iostream>
#include <cmath> //così possiamo usare il pi greco M_PI
using namespace std;

extern void emptyLine();

int main(){
  emptyLine();

  Vector3D v1, v2, v3, v4;
  v1 = Vector3D();
  v2 = Vector3D::Cartesian(1., 2., 3.);
  v3 = Vector3D::Spherical(1., M_PI, 0.);
  v4 = Vector3D::Spherical(1., -M_PI*0.5, M_PI*0.5);

  cout << "v1: ";
  v1.printCartesian();
  cout << "v2: ";
  v2.printCartesian();
  cout << "v3: ";
  v3.printCartesian();
  cout << "v4: ";
  v4.printCartesian();
  emptyLine();

  // copy constructor
  v1 = Vector3D(v3);
  // setters
  v1.setX(0.);
  v3.setX(0.);

  cout << "v1: ";
  v1.printCartesian();
  cout << "v2: ";
  v2.printCartesian();
  cout << "v3: ";
  v3.printCartesian();
  emptyLine();

  // getters
  cout << "|v3| = " << v3.magnitude() << endl;
  cout << "v3.theta = " << v3.theta() << endl;
  cout << "v4.phi = " << v4.phi() << endl;
  cout << "v2.scalarProduct(v3) = " << v2.scalarProduct(v3) << endl;
  cout << "v3.scalarProduct(v2) = " << v3.scalarProduct(v2) << endl;

  emptyLine();
  return 0;
}



void emptyLine(){
  cout << "\n" << endl;
}
