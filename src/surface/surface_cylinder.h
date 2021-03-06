#pragma once

#include <string>
#include "constant.h"
#include "surface/surface_cartesian.h"

/************************************************************
 Cylinder Surface with parameter: [r, z_upper, z_lower]

 Equation : (x^2 + y^2) = r^2 where r is constant

 Suggested domain: [-4,4;-4,4;-4,4] for grid (20,40,80,160)
 ************************************************************/
class Surface_Cylinder : public Surface_Cartesian {
private:
  double r, z_upper, z_lower;

  virtual double func(const Doub_I, const Doub_I, const Doub_I) const;
  virtual double dfx(const Doub_I, const Doub_I, const Doub_I) const;
  virtual double dfy(const Doub_I, const Doub_I, const Doub_I) const;

  // Not defined
  virtual double dfz(const Doub_I, const Doub_I, const Doub_I) const;

public:
  Surface_Cylinder(VecDoub_I);
  virtual double Set_Node(Doub_I, Doub_I, Doub_I) const;
  virtual VecDoub normal(Doub_I, Doub_I, Doub_I);
  virtual void display();
  virtual double check(Doub_I, Doub_I, Doub_I);

  // Override the member function defined in Surface_Cartesian
  virtual double Gamma_z(Doub_I, Doub_I, Doub_I, Doub_I);
};
