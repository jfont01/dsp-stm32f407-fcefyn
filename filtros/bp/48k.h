/*
 * Filter Coefficients (C Source) generated by the Filter Design and Analysis Tool
 * Generated by MATLAB(R) 24.1 and DSP System Toolbox 24.1.
 * Generated on: 12-Mar-2025 19:09:49
 */

/*
 * Discrete-Time FIR Filter (real)
 * -------------------------------
 * Filter Structure  : Direct-Form FIR
 * Filter Length     : 150
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
const int BL = 150;
const int16_T B[150] = {
       10,     58,     86,     88,     63,     14,    -49,   -112,   -164,
     -192,   -190,   -157,   -100,    -29,     41,     96,    123,    116,
       75,      7,    -75,   -153,   -212,   -239,   -225,   -173,    -92,
        2,     91,    155,    180,    158,     92,     -6,   -118,   -221,
     -291,   -314,   -281,   -197,    -75,     60,    181,    262,    282,
      234,    122,    -34,   -205,   -355,   -452,   -469,   -397,   -243,
      -30,    200,    402,    530,    546,    435,    202,   -121,   -480,
     -804,  -1018,  -1057,   -871,   -444,    210,   1039,   1963,   2883,
     3691,   4292,   4613,   4613,   4292,   3691,   2883,   1963,   1039,
      210,   -444,   -871,  -1057,  -1018,   -804,   -480,   -121,    202,
      435,    546,    530,    402,    200,    -30,   -243,   -397,   -469,
     -452,   -355,   -205,    -34,    122,    234,    282,    262,    181,
       60,    -75,   -197,   -281,   -314,   -291,   -221,   -118,     -6,
       92,    158,    180,    155,     91,      2,    -92,   -173,   -225,
     -239,   -212,   -153,    -75,      7,     75,    116,    123,     96,
       41,    -29,   -100,   -157,   -190,   -192,   -164,   -112,    -49,
       14,     63,     88,     86,     58,     10
};
