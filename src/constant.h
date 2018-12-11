#pragma once

#include <cmath>
#include <vector>

using namespace std;

const double PI = acos(-1);
const int NPRINT = 1;
const double TOL_SETUP = 1.0e-12;
const double TOL_RTSAFE = 1.0e-14;

// region of approximated jump condition ('o': for outside only; others)
const char REG = 'i';
// jump condition ('r': for real jump only; others)
const char JP = 'r';

const bool DEBUGFLAG = false;
const bool WARNINGS = false;

typedef int Int_I, Int_O, Int_IO;
typedef double Doub_I, Doub_O, Doub_IO;
typedef char Char_I, Char_O, Char_IO;
typedef vector<int> VecInt, VecInt_I, VecInt_O, VecInt_IO;
typedef vector<char> VecChar, VecChar_I, VecChar_O, VecChar_IO;
typedef vector<double> VecDoub, VecDoub_I, VecDoub_O, VecDoub_IO;
typedef vector<vector<double>> MatrixDoub, MatrixDoub_I, MatrixDoub_O,
    MatrixDoub_IO;
typedef vector<vector<vector<double>>> CubicDoub, CubicDoub_I, CubicDoub_O,
    CubicDoub_IO;

enum Config {
  MAX_X,
  MIN_X,
  MAX_Y,
  MIN_Y,
  MAX_Z,
  MIN_Z,
  TIME_START,
  TIME_TERMINATE,
  TIME_STEP,
  NX,
  NY,
  NZ,
  SURFACE,
  EQUATION,
  TEMPORAL_METHOD,
  SPATIAL_METHOD,
  SPATIAL_ACCURACY,
  DIFFUSION_COEFFICIENT,
  COMMENT,
};

enum class Temporal_Method_Type {
  ADI,
  LOD_IE,
  LOD_CN,
  TS,
};

enum class Surface_Type {
  TANGLECUBE,
  CUBE,
  CYLINDER,
  ELLIPSOID,
  CONE,
  PILE,
  TORUS,
  DUPIN_CYCLIDE,
  MOLECULAR,
  HEART,
};

enum class Spatial_Method_Type {
  MIB_V1,
  MIB_V2
};
