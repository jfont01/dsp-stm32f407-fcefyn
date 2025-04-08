/*
 * Filter Coefficients (C Source) generated by the Filter Design and Analysis Tool
 * Generated by MATLAB(R) 24.1 and DSP System Toolbox 24.1.
 * Generated on: 12-Mar-2025 19:00:06
 */

/*
 * Discrete-Time FIR Filter (real)
 * -------------------------------
 * Filter Structure  : Direct-Form FIR
 * Filter Length     : 800
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
const int BL = 800;
const int16_T B[800] = {
       -7,     -4,     25,     44,     22,    -22,    -44,    -25,      4,
        7,     -7,     -4,     26,     45,     23,    -23,    -45,    -26,
        4,      7,     -7,     -4,     26,     46,     24,    -24,    -47,
      -27,      4,      7,     -8,     -4,     27,     48,     24,    -24,
      -48,    -27,      4,      8,     -8,     -4,     28,     49,     25,
      -25,    -50,    -28,      4,      8,     -8,     -4,     29,     51,
       26,    -26,    -51,    -29,      4,      8,     -8,     -4,     30,
       52,     27,    -27,    -53,    -30,      4,      8,     -9,     -4,
       31,     54,     28,    -28,    -55,    -31,      4,      9,     -9,
       -4,     32,     56,     29,    -29,    -57,    -32,      5,      9,
       -9,     -5,     33,     58,     30,    -30,    -59,    -33,      5,
        9,     -9,     -5,     34,     60,     31,    -31,    -61,    -35,
        5,     10,    -10,     -5,     35,     62,     32,    -32,    -63,
      -36,      5,     10,    -10,     -5,     37,     65,     33,    -33,
      -66,    -37,      5,     11,    -11,     -5,     38,     67,     34,
      -35,    -68,    -39,      6,     11,    -11,     -6,     40,     70,
       36,    -36,    -71,    -41,      6,     11,    -11,     -6,     41,
       73,     37,    -38,    -74,    -42,      6,     12,    -12,     -6,
       43,     76,     39,    -39,    -77,    -44,      6,     12,    -12,
       -6,     45,     80,     41,    -41,    -81,    -46,      7,     13,
      -13,     -7,     47,     84,     43,    -43,    -85,    -48,      7,
       14,    -14,     -7,     50,     88,     45,    -45,    -89,    -51,
        7,     14,    -14,     -7,     52,     92,     47,    -48,    -94,
      -54,      8,     15,    -15,     -8,     55,     98,     50,    -50,
      -99,    -57,      8,     16,    -16,     -8,     58,    103,     53,
      -53,   -105,    -60,      9,     17,    -17,     -9,     62,    110,
       56,    -57,   -112,    -64,      9,     18,    -18,     -9,     66,
      117,     60,    -60,   -119,    -68,     10,     19,    -19,    -10,
       70,    125,     64,    -65,   -128,    -73,     10,     21,    -21,
      -11,     76,    134,     69,    -69,   -137,    -79,     11,     22,
      -22,    -12,     82,    145,     74,    -75,   -148,    -85,     12,
       24,    -24,    -12,     89,    158,     81,    -82,   -162,    -93,
       13,     26,    -27,    -14,     97,    172,     89,    -90,   -177,
     -102,     15,     29,    -29,    -15,    107,    190,     98,    -99,
     -197,   -113,     16,     32,    -33,    -17,    119,    213,    110,
     -111,   -220,   -127,     18,     36,    -37,    -19,    135,    241,
      124,   -126,   -250,   -144,     21,     41,    -42,    -22,    155,
      277,    143,   -145,   -290,   -167,     24,     48,    -49,    -25,
      182,    326,    169,   -172,   -344,   -199,     29,     58,    -59,
      -31,    220,    396,    206,   -211,   -424,   -246,     36,     72,
      -74,    -39,    279,    505,    265,   -272,   -550,   -322,     47,
       96,    -99,    -52,    381,    696,    368,   -384,   -785,   -466,
       69,    142,   -150,    -80,    599,   1118,    606,   -648,  -1366,
     -838,    129,    278,   -307,   -175,   1397,   2838,   1709,  -2088,
    -5270,  -4192,    992,   5843,   5843,    992,  -4192,  -5270,  -2088,
     1709,   2838,   1397,   -175,   -307,    278,    129,   -838,  -1366,
     -648,    606,   1118,    599,    -80,   -150,    142,     69,   -466,
     -785,   -384,    368,    696,    381,    -52,    -99,     96,     47,
     -322,   -550,   -272,    265,    505,    279,    -39,    -74,     72,
       36,   -246,   -424,   -211,    206,    396,    220,    -31,    -59,
       58,     29,   -199,   -344,   -172,    169,    326,    182,    -25,
      -49,     48,     24,   -167,   -290,   -145,    143,    277,    155,
      -22,    -42,     41,     21,   -144,   -250,   -126,    124,    241,
      135,    -19,    -37,     36,     18,   -127,   -220,   -111,    110,
      213,    119,    -17,    -33,     32,     16,   -113,   -197,    -99,
       98,    190,    107,    -15,    -29,     29,     15,   -102,   -177,
      -90,     89,    172,     97,    -14,    -27,     26,     13,    -93,
     -162,    -82,     81,    158,     89,    -12,    -24,     24,     12,
      -85,   -148,    -75,     74,    145,     82,    -12,    -22,     22,
       11,    -79,   -137,    -69,     69,    134,     76,    -11,    -21,
       21,     10,    -73,   -128,    -65,     64,    125,     70,    -10,
      -19,     19,     10,    -68,   -119,    -60,     60,    117,     66,
       -9,    -18,     18,      9,    -64,   -112,    -57,     56,    110,
       62,     -9,    -17,     17,      9,    -60,   -105,    -53,     53,
      103,     58,     -8,    -16,     16,      8,    -57,    -99,    -50,
       50,     98,     55,     -8,    -15,     15,      8,    -54,    -94,
      -48,     47,     92,     52,     -7,    -14,     14,      7,    -51,
      -89,    -45,     45,     88,     50,     -7,    -14,     14,      7,
      -48,    -85,    -43,     43,     84,     47,     -7,    -13,     13,
        7,    -46,    -81,    -41,     41,     80,     45,     -6,    -12,
       12,      6,    -44,    -77,    -39,     39,     76,     43,     -6,
      -12,     12,      6,    -42,    -74,    -38,     37,     73,     41,
       -6,    -11,     11,      6,    -41,    -71,    -36,     36,     70,
       40,     -6,    -11,     11,      6,    -39,    -68,    -35,     34,
       67,     38,     -5,    -11,     11,      5,    -37,    -66,    -33,
       33,     65,     37,     -5,    -10,     10,      5,    -36,    -63,
      -32,     32,     62,     35,     -5,    -10,     10,      5,    -35,
      -61,    -31,     31,     60,     34,     -5,     -9,      9,      5,
      -33,    -59,    -30,     30,     58,     33,     -5,     -9,      9,
        5,    -32,    -57,    -29,     29,     56,     32,     -4,     -9,
        9,      4,    -31,    -55,    -28,     28,     54,     31,     -4,
       -9,      8,      4,    -30,    -53,    -27,     27,     52,     30,
       -4,     -8,      8,      4,    -29,    -51,    -26,     26,     51,
       29,     -4,     -8,      8,      4,    -28,    -50,    -25,     25,
       49,     28,     -4,     -8,      8,      4,    -27,    -48,    -24,
       24,     48,     27,     -4,     -8,      7,      4,    -27,    -47,
      -24,     24,     46,     26,     -4,     -7,      7,      4,    -26,
      -45,    -23,     23,     45,     26,     -4,     -7,      7,      4,
      -25,    -44,    -22,     22,     44,     25,     -4,     -7
};
