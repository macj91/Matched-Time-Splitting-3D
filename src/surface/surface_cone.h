#pragma once

#include <string>
#include "constant.h"
#include "surface/surface_cartesian.h"

/******************************************************************
 Ellipsoid Cone Surface with parameter: [a, b, c, z_upper, z_lower]

 Equation : (x^2 + y^2) / a^2 - (z - b)^2 - c = 0 where a,b,c are constants

 Suggested domain : [-4,4;-4,4;-4,1] for grid (20,40,80,160)
 *****************************************************************/
class Surface_Cone : public Surface_Cartesian {
private:
  double a, b, c, z_upper, z_lower;

  virtual double func(const Doub_I, const Doub_I, const Doub_I) const;
  virtual double dfx(const Doub_I, const Doub_I, const Doub_I) const;
  virtual double dfy(const Doub_I, const Doub_I, const Doub_I) const;
  virtual double dfz(const Doub_I, const Doub_I, const Doub_I) const;

public:
  Surface_Cone(VecDoub_I);
  virtual double Set_Node(Doub_I, Doub_I, Doub_I) const;
  virtual VecDoub normal(Doub_I, Doub_I, Doub_I);
  virtual void display();
  virtual double check(Doub_I, Doub_I, Doub_I);

  // Override the member function defined in Surface_Cartesian
  virtual double Gamma_z(Doub_I, Doub_I, Doub_I, Doub_I);
};
