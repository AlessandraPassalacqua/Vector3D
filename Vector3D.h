// Vector3D.h
// header file of the Vector3D class


class Vector3D {

private:
  // data members
  double x_, y_, z_ ;
  // Cartesian constructor
  Vector3D(double x, double y, double z);

public:

  // constructors
  Vector3D();
  Vector3D(const Vector3D& v);

  // static to invoke private constructor
  static Vector3D Cartesian(double x, double y, double z);
  // theta angolo azimutale, phi angolo polare
  static Vector3D Spherical(double r, double theta, double phi);

  // utility
  void printCartesian();
  void printSpherical();

  // setters
  void setX(double x) ;
  void setY(double y) ;
  void setZ(double z) ;
  void setR(double r) ;
  void setTheta(double theta) ;
  void setPhi(double phi) ;

  // getters
  double magnitude() const ;
  double theta() const ; // azimutale [0, M_PI]
  double phi() const ; // polare [0, 2M_PI)

  // functions
  double scalarProduct(const Vector3D& v) const ;
  vector3D vectorProduct(const Vector3D& v) const ;


};
