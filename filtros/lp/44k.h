/*
 * Filter Coefficients (C Source) generated by the Filter Design and Analysis Tool
 * Generated by MATLAB(R) 24.1 and DSP System Toolbox 24.1.
 * Generated on: 12-Mar-2025 17:51:49
 */

/*
 * Discrete-Time FIR Filter (real)
 * -------------------------------
 * Filter Structure  : Direct-Form FIR
 * Filter Length     : 200
 * Stable            : Yes
 * Linear Phase      : Yes (Type 2)
 * Arithmetic        : fixed
 * Numerator         : s16,15 -> [-1 1)
 * Input             : s16,15 -> [-1 1)
 * Filter Internals  : Full Precision
 *   Output          : s33,30 -> [-4 4)  (auto determined)
 *   Product         : s29,30 -> [-2.500000e-01 2.500000e-01)  (auto determined)
 *   Accumulator     : s33,30 -> [-4 4)  (auto determined)
 *   Round Mode      : No rounding
 *   Overflow Mode   : No overflow
 */

/* General type conversion for MATLAB generated C-code  */
#include "tmwtypes.h"
/* 
 * Expected path to tmwtypes.h 
 * C:\Program Files\MATLAB\R2024a\extern\include\tmwtypes.h 
 */
const int BL = 200;
const int16_T B[200] = {
     -137,    434,     14,    -95,   -104,    -81,    -48,    -14,     18,
       43,     57,     58,     46,     23,     -7,    -36,    -57,    -65,
      -56,    -32,      1,     36,     63,     76,     69,     43,      5,
      -37,    -72,    -89,    -84,    -56,    -11,     39,     82,    106,
      102,     72,     20,    -40,    -93,   -124,   -124,    -91,    -32,
       40,    105,    146,    151,    116,     47,    -38,   -118,   -172,
     -184,   -147,    -68,     34,    134,    204,    225,    187,     96,
      -27,   -151,   -244,   -279,   -241,   -135,     15,    173,    298,
      353,    317,    193,      5,   -202,   -375,   -464,   -436,   -286,
      -40,    247,    502,    654,    647,    458,    110,   -331,   -765,
    -1074,  -1145,   -900,   -310,    591,   1709,   2901,   3999,   4840,
     5296,   5296,   4840,   3999,   2901,   1709,    591,   -310,   -900,
    -1145,  -1074,   -765,   -331,    110,    458,    647,    654,    502,
      247,    -40,   -286,   -436,   -464,   -375,   -202,      5,    193,
      317,    353,    298,    173,     15,   -135,   -241,   -279,   -244,
     -151,    -27,     96,    187,    225,    204,    134,     34,    -68,
     -147,   -184,   -172,   -118,    -38,     47,    116,    151,    146,
      105,     40,    -32,    -91,   -124,   -124,    -93,    -40,     20,
       72,    102,    106,     82,     39,    -11,    -56,    -84,    -89,
      -72,    -37,      5,     43,     69,     76,     63,     36,      1,
      -32,    -56,    -65,    -57,    -36,     -7,     23,     46,     58,
       57,     43,     18,    -14,    -48,    -81,   -104,    -95,     14,
      434,   -137
};
