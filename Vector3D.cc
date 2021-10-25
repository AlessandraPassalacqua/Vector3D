#include "Vector3D.h"
#include <iostream>
#include <cmath>


// constructors
Vector3D::Vector3D(double x, double y, double z){
  x_ = x;
  y_ = y;
  z_ = z;
}

Vector3D::Vector3D() { // nullo
  x_=0.;
  y_=0.;
  z_=0.;
}

Vector3D::Vector3D(const Vector3D& v){ //copy constructor
  x_ = v.x_;
  y_ = v.y_;
  z_ = v.z_;
}

// static functions to invoke private constructor
Vector3D Vector3D::Cartesian(double x, double y, double z){
  return Vector3D(x, y, z);
}
Vector3D Vector3D::Spherical(double r, double theta, double phi){
  // theta angolo azimutale, phi angolo polare
  return Vector3D(r*sin(theta)*cos(phi), r*sin(theta)*sin(phi), r*cos(theta));
}



// utility functions
void Vector3D::printCartesian(){ // è un attributo di Vector3D, non vuole nessun argomento
  using namespace std;
  cout << "\t"
       << "x = " << x_ << "\t\t"
       << "y = " << y_ << "\t\t"
       << "z = " << z_ << "\t"
       << endl;
}

void Vector3D::printSpherical(){

}




// setters
void Vector3D::setX(double x){
  x_=x;
}
void Vector3D::setY(double y){
  y_=y;
}
void Vector3D::setZ(double z){
  z_=z;
}



// getters

double Vector3D::magnitude() const {
  return sqrt(x_*x_ + y_*y_ + z_*z_);
}
double Vector3D::theta() const{
  Vector3D This = *this;
  return acos(z_/This.magnitude());
}

double Vector3D::phi() const{
  if(x_==0){
    if(y_>0){ return 0.5*M_PI; }
    else if (y_<0) { return 3*0.5*M_PI; }
    else { return 0; }
  }

  else if(x_>0){
    if(y_>=0){ return atan(y_/x_); }
    else { return ( atan(y_/x_) + 2*M_PI ) ;}
  }

  else { return ( atan(y_/x_) + M_PI ) ; }


}


// functions
double Vector3D::scalarProduct(const Vector3D& v) const{
  return ( x_*v.x_ + y_*v.y_ + z_*v.z_ ) ;
}
Vector3D Vector3D::vectorProduct(const Vector3D& rhs) const{ //
  double X = y_*rhs.z_ - z_*rhs.y_ ;
  double Y = -x_*rhs.z + z_*rhs.x_ ;
  double Z = x_*rhs.y - y_*rhs.x_ ;
  return Vector3D(X, Y, Z) ;
}
