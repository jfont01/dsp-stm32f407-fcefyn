/*
 * Filter Coefficients (C Source) generated by the Filter Design and Analysis Tool
 * Generated by MATLAB(R) 24.1 and DSP System Toolbox 24.1.
 * Generated on: 12-Mar-2025 19:05:16
 */

/*
 * Discrete-Time FIR Filter (real)
 * -------------------------------
 * Filter Structure  : Direct-Form FIR
 * Filter Length     : 320
 * Stable            : Yes
 * Linear Phase      : Yes (Type 2)
 * Arithmetic        : fixed
 * Numerator         : s16,15 -> [-1 1)
 * Input             : s16,15 -> [-1 1)
 * Filter Internals  : Full Precision
 *   Output          : s33,30 -> [-4 4)  (auto determined)
 *   Product         : s30,30 -> [-5.000000e-01 5.000000e-01)  (auto determined)
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
const int BL = 320;
const int16_T B[320] = {
      -18,     -1,    -40,   -100,   -125,    -93,    -33,      0,    -26,
      -88,   -129,   -112,    -52,     -4,    -13,    -72,   -128,   -129,
      -74,    -13,     -3,    -55,   -121,   -142,    -97,    -28,      2,
      -37,   -109,   -149,   -120,    -47,      2,    -19,    -92,   -151,
     -141,    -71,     -5,     -5,    -72,   -146,   -158,    -97,    -18,
        6,    -49,   -134,   -170,   -125,    -38,     10,    -26,   -116,
     -176,   -151,    -63,      8,     -5,    -92,   -174,   -175,    -93,
       -2,     13,    -64,   -164,   -194,   -126,    -21,     25,    -34,
     -145,   -206,   -161,    -48,     29,     -3,   -117,   -209,   -194,
      -82,     23,     25,    -83,   -202,   -223,   -123,      7,     48,
      -43,   -184,   -246,   -168,    -20,     63,      1,   -153,   -259,
     -216,    -60,     67,     46,   -110,   -260,   -263,   -111,     59,
       89,    -55,   -245,   -306,   -174,     33,    126,     11,   -213,
     -341,   -248,    -11,    154,     89,   -159,   -365,   -333,    -80,
      169,    177,    -78,   -372,   -429,   -179,    163,    278,     39,
     -354,   -540,   -322,    128,    400,    215,   -298,   -679,   -545,
       39,    564,    509,   -162,   -891,   -966,   -181,    870,   1187,
      235,  -1431,  -2346,  -1135,   2373,   6767,   9799,   9799,   6767,
     2373,  -1135,  -2346,  -1431,    235,   1187,    870,   -181,   -966,
     -891,   -162,    509,    564,     39,   -545,   -679,   -298,    215,
      400,    128,   -322,   -540,   -354,     39,    278,    163,   -179,
     -429,   -372,    -78,    177,    169,    -80,   -333,   -365,   -159,
       89,    154,    -11,   -248,   -341,   -213,     11,    126,     33,
     -174,   -306,   -245,    -55,     89,     59,   -111,   -263,   -260,
     -110,     46,     67,    -60,   -216,   -259,   -153,      1,     63,
      -20,   -168,   -246,   -184,    -43,     48,      7,   -123,   -223,
     -202,    -83,     25,     23,    -82,   -194,   -209,   -117,     -3,
       29,    -48,   -161,   -206,   -145,    -34,     25,    -21,   -126,
     -194,   -164,    -64,     13,     -2,    -93,   -175,   -174,    -92,
       -5,      8,    -63,   -151,   -176,   -116,    -26,     10,    -38,
     -125,   -170,   -134,    -49,      6,    -18,    -97,   -158,   -146,
      -72,     -5,     -5,    -71,   -141,   -151,    -92,    -19,      2,
      -47,   -120,   -149,   -109,    -37,      2,    -28,    -97,   -142,
     -121,    -55,     -3,    -13,    -74,   -129,   -128,    -72,    -13,
       -4,    -52,   -112,   -129,    -88,    -26,      0,    -33,    -93,
     -125,   -100,    -40,     -1,    -18
};
