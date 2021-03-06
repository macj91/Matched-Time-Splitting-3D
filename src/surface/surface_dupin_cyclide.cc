#include <cmath>
#include <iostream>
#include "surface/surface_dupin_cyclide.h"
#include "constant.h"

using namespace std;

/****************************************************
 Constructor

 INPUT
 arg : arguments of Dupin Cyclide object
 *****************************************************/
Surface_Dupin_Cyclide::Surface_Dupin_Cyclide(VecDoub_I arg) {
  a = arg[0];
  b = arg[1];
  c = arg[2];
}

/**********************************************************************
 Implicit function with little perturbation

 INPUT
 x : x coordinate of given point
 y : y coordinate of given point
 z : z coordinate of given point

 OUTPUT
 value of implicit function with perturbation
 ***********************************************************************/
double Surface_Dupin_Cyclide::Set_Node(Doub_I x, Doub_I y, Doub_I z) const {
  double diff;

  diff = pow((a - sqrt(x * x + y * y)), 2) + z * z + b * x - c * c + TOL_SETUP;

  return diff;
}

/*********************************************************************************
 Private member function to get value of implicit function without perturbation

 INPUT
 x : x coordinate of given point
 y : y coordinate of given point
 z : z coordinate of given point

 OUTPUT
 value of function
 **********************************************************************************/
double Surface_Dupin_Cyclide::func(const Doub_I x, const Doub_I y,
                                   const Doub_I z) const {
  double temp;

  temp = pow((a - sqrt(x * x + y * y)), 2) + z * z + b * x - c * c;

  return temp;
}

/**********************************************************************
 Calculate derivative of function in x-direction

 INPUT
 x : x coordinate of given point
 y : y coordinate of given point
 z : z coordinate of given point

 OUTPUT
 derivative of function in x-direction
 ***********************************************************************/
double Surface_Dupin_Cyclide::dfx(const Doub_I x, const Doub_I y,
                                  const Doub_I z) const {
  double temp;

  temp = (-2.0 * a * x) / (sqrt(x * x + y * y)) + 2.0 * x + b;

  return temp;
}

/**********************************************************************
 Calculate derivative of function in y-direction

 INPUT
 x : x coordinate of given point
 y : y coordinate of given point
 z : z coordinate of given point

 OUTPUT
 derivative of function in y-direction
 ***********************************************************************/
double Surface_Dupin_Cyclide::dfy(const Doub_I x, const Doub_I y,
                                  const Doub_I z) const {
  double temp;

  temp = (-2.0 * a * y) / (sqrt(x * x + y * y)) + 2.0 * y;

  return temp;
}

/**********************************************************************
 Calculate derivative of function in z-direction

 INPUT
 x : x coordinate of given point
 y : y coordinate of given point
 z : z coordinate of given point

 OUTPUT
 derivative of function in z-direction
 ***********************************************************************/
double Surface_Dupin_Cyclide::dfz(const Doub_I x, const Doub_I y,
                                  const Doub_I z) const {
  double temp;

  temp = 2.0 * z;

  return temp;
}

/**********************************************************************
 Get normal direction at given point

 INPUT
 x : x coordinate of given point
 y : y coordinate of given point
 z : z coordinate of given point

 OUTPUT
 vector of normal direction with 3 components
 ***********************************************************************/
VecDoub Surface_Dupin_Cyclide::normal(Doub_I x, Doub_I y, Doub_I z) {
  VecDoub normal;
  double total, temp;

  total = sqrt(pow((-2.0 * a * x) / (sqrt(x * x + y * y)) + 2.0 * x + b, 2) +
               pow((-2.0 * a * y) / (sqrt(x * x + y * y)) + 2.0 * y, 2) +
               pow(2.0 * z, 2));

  temp = ((-2.0 * a * x) / (sqrt(x * x + y * y)) + 2.0 * x + b) / total;
  normal.push_back(temp);
  temp = ((-2.0 * a * y) / (sqrt(x * x + y * y)) + 2.0 * y) / total;
  normal.push_back(temp);
  temp = (2.0 * z) / total;
  normal.push_back(temp);

  return normal;
}

/**********************************************************************
 Show the quation of implicit function
 ***********************************************************************/
void Surface_Dupin_Cyclide::display() {
  cout << "The equation of Torus surface is:" << endl;
  cout << "f(x) = [" << a << "-(x^y+y^2)^(1/2)]^2+z^2+" << b << "*x-" << c * c
       << " = 0" << endl;
}

/*****************************************************************************************
 Public member function to get the value of implicit function without
 perturbation

 INPUT
 x : x coordinate of given point
 y : y coordinate of given point
 z : z coordinate of given point

 OUTPUT
 value of implicit function without perturbation
 ******************************************************************************************/
double Surface_Dupin_Cyclide::check(Doub_I x, Doub_I y, Doub_I z) {
  double temp;

  temp = pow((a - sqrt(x * x + y * y)), 2) + z * z + b * x - c * c;

  return temp;
}
