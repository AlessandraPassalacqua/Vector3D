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
    using namespace std;
    Vector3D This = *this;
    cout << "\t"
         << "r = " << This.magnitude() << "\t\t"
         << "theta = " << This.theta() << "\t\t"
         << "phi = " << This.phi() << "\t"
         << endl;
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

void Vector3D::setR(double r) {
    Vector3D This = *this;
    x_= r*sin(This.theta())*cos(This.phi());
    y_= r*sin(This.theta())*sin(This.phi());
    z_= r*cos(This.theta());
}

void Vector3D::setTheta(double theta) {
    Vector3D This = *this;
    x_= This.magnitude()*sin(theta)*cos(This.phi());
    y_= This.magnitude()*sin(theta)*sin(This.phi());
    z_= This.magnitude()*cos(theta);
}

void Vector3D::setPhi(double phi) {
    Vector3D This = *this;
    x_= This.magnitude()*sin(This.theta())*cos(phi);
    y_= This.magnitude()*sin(This.theta())*sin(phi);
}



// getters

double Vector3D::getX() const { return x_;}
double Vector3D::getY() const { return y_;}
double Vector3D::getZ() const { return z_;}


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
  double Y = -x_*rhs.z_ + z_*rhs.x_ ;
  double Z = x_*rhs.y_ - y_*rhs.x_ ;
  return Vector3D(X, Y, Z) ;
}


//angle between two vectors
double Vector3D::angle(Vector3D v){
    Vector3D This = *this;
    double cos = This.scalarProduct(v)/(This.magnitude()*v.magnitude());
    return acos(cos);
}

//overloads
Vector3D Vector3D::operator+(const Vector3D& v) const {
    return Cartesian(x_+v.x_, y_+v.y_, z_+v.z_);
}

Vector3D Vector3D::operator-(const Vector3D& v) const {
    return Cartesian(x_-v.x_, y_-v.y_, z_-v.z_);
}

Vector3D Vector3D::operator=(const Vector3D& v) {
    x_ = v.x_;
    y_ = v.y_;
    z_ = v.z_;
    return *this;
}

Vector3D Vector3D::operator*(const double& d) const {
    return Cartesian(x_*d, y_*d, z_*d);
}

Vector3D Vector3D::operator/(const double& d) const {
    return Cartesian(x_/d, y_/d, z_/d);
}



//global functions
//overload operator<<
ostream& operator<<(ostream& os, const Vector3D& rhs){
    os<< "\t"
    << "x = " << rhs.getX() << "\t\t"
    << "y = " << rhs.getY() << "\t\t"
    << "z = " << rhs.getZ() << "\t"
    << endl;
    return os;
}

//overload operator*
Vector3D operator*(const double& d, const Vector3D& v){
    return v.Vector3D::operator*(d);
}

