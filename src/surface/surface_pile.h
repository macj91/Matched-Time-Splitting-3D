#pragma once

#include <string>
#include "constant.h"
#include "surface/surface_cartesian.h"

/***************************************************************
 Pile Surface

 Equation : 5 * (x^2 + y^2 + 5 * z^2 - 10)^3 + 5 * (x^2 + 60 * y^2 + 3 * z^2 -
 2)^2 = 0

 Suggested domain: [-7,7;-1,1;-3,3] for grid (20,40,80,160)
 ***************************************************************/
class Surface_Pile : public Surface_Cartesian {
private:
  virtual double func(const Doub_I, const Doub_I, const Doub_I) const;
  virtual double dfx(const Doub_I, const Doub_I, const Doub_I) const;
  virtual double dfy(const Doub_I, const Doub_I, const Doub_I) const;
  virtual double dfz(const Doub_I, const Doub_I, const Doub_I) const;

public:
  Surface_Pile();
  virtual double Set_Node(Doub_I, Doub_I, Doub_I) const;
  virtual VecDoub normal(Doub_I, Doub_I, Doub_I);
  virtual void display();
  virtual double check(Doub_I, Doub_I, Doub_I);
};
