/*
 * Filter Coefficients (C Source) generated by the Filter Design and Analysis Tool
 * Generated by MATLAB(R) 24.1 and DSP System Toolbox 24.1.
 * Generated on: 12-Mar-2025 19:27:53
 */

/*
 * Discrete-Time FIR Filter (real)
 * -------------------------------
 * Filter Structure  : Direct-Form FIR
 * Filter Length     : 801
 * Stable            : Yes
 * Linear Phase      : Yes (Type 1)
 * Arithmetic        : fixed
 * Numerator         : s16,15 -> [-1 1)
 * Input             : s16,15 -> [-1 1)
 * Filter Internals  : Full Precision
 *   Output          : s33,30 -> [-4 4)  (auto determined)
 *   Product         : s31,30 -> [-1 1)  (auto determined)
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
const int BL = 801;
const int16_T B[801] = {
       37,     37,     37,     37,     37,     37,     37,     37,     37,
       37,     36,     36,     36,     35,     34,     34,     33,     32,
       31,     31,     30,     29,     27,     26,     25,     24,     22,
       21,     20,     18,     17,     15,     13,     12,     10,      8,
        6,      5,      3,      1,     -1,     -3,     -5,     -7,     -9,
      -11,    -13,    -15,    -17,    -19,    -21,    -23,    -25,    -27,
      -29,    -30,    -32,    -34,    -36,    -38,    -40,    -41,    -43,
      -44,    -46,    -47,    -49,    -50,    -52,    -53,    -54,    -55,
      -56,    -57,    -58,    -59,    -59,    -60,    -60,    -61,    -61,
      -61,    -61,    -61,    -61,    -61,    -61,    -61,    -60,    -60,
      -59,    -58,    -57,    -56,    -55,    -54,    -53,    -52,    -50,
      -49,    -47,    -45,    -43,    -42,    -40,    -38,    -35,    -33,
      -31,    -29,    -26,    -24,    -21,    -19,    -16,    -13,    -11,
       -8,     -5,     -2,      0,      3,      6,      9,     12,     15,
       18,     21,     24,     26,     29,     32,     35,     38,     40,
       43,     46,     48,     51,     53,     56,     58,     60,     63,
       65,     67,     69,     71,     72,     74,     75,     77,     78,
       79,     80,     81,     82,     83,     84,     84,     84,     85,
       85,     85,     85,     84,     84,     83,     82,     82,     81,
       80,     78,     77,     75,     74,     72,     70,     68,     66,
       64,     61,     59,     56,     54,     51,     48,     45,     42,
       39,     36,     33,     29,     26,     22,     19,     15,     12,
        8,      4,      1,     -3,     -7,    -11,    -14,    -18,    -22,
      -26,    -29,    -33,    -37,    -40,    -44,    -47,    -51,    -54,
      -58,    -61,    -64,    -67,    -70,    -73,    -76,    -79,    -81,
      -84,    -86,    -88,    -90,    -92,    -94,    -96,    -98,    -99,
     -100,   -101,   -102,   -103,   -104,   -104,   -105,   -105,   -105,
     -105,   -104,   -104,   -103,   -102,   -101,   -100,    -99,    -98,
      -96,    -94,    -92,    -90,    -88,    -86,    -83,    -80,    -78,
      -75,    -72,    -68,    -65,    -62,    -58,    -55,    -51,    -47,
      -43,    -39,    -35,    -31,    -27,    -23,    -18,    -14,    -10,
       -5,     -1,      3,      8,     12,     17,     21,     26,     30,
       34,     39,     43,     47,     51,     55,     59,     63,     67,
       71,     74,     78,     81,     84,     88,     91,     94,     96,
       99,    101,    104,    106,    108,    110,    111,    113,    114,
      115,    116,    117,    118,    118,    119,    119,    118,    118,
      118,    117,    116,    115,    114,    112,    111,    109,    107,
      105,    103,    100,     98,     95,     92,     89,     86,     82,
       79,     75,     72,     68,     64,     60,     56,     51,     47,
       43,     38,     34,     29,     24,     20,     15,     10,      5,
        0,     -4,     -9,    -14,    -19,    -23,    -28,    -33,    -38,
      -42,    -47,    -51,    -55,    -60,    -64,    -68,    -72,    -76,
      -80,    -83,    -87,    -90,    -94,    -97,   -100,   -102,   -105,
     -108,   -110,   -112,   -114,   -116,   -117,   -119,   -120,   -121,
     -122,   -123,   -123,   -123,  32645,   -123,   -123,   -123,   -122,
     -121,   -120,   -119,   -117,   -116,   -114,   -112,   -110,   -108,
     -105,   -102,   -100,    -97,    -94,    -90,    -87,    -83,    -80,
      -76,    -72,    -68,    -64,    -60,    -55,    -51,    -47,    -42,
      -38,    -33,    -28,    -23,    -19,    -14,     -9,     -4,      0,
        5,     10,     15,     20,     24,     29,     34,     38,     43,
       47,     51,     56,     60,     64,     68,     72,     75,     79,
       82,     86,     89,     92,     95,     98,    100,    103,    105,
      107,    109,    111,    112,    114,    115,    116,    117,    118,
      118,    118,    119,    119,    118,    118,    117,    116,    115,
      114,    113,    111,    110,    108,    106,    104,    101,     99,
       96,     94,     91,     88,     84,     81,     78,     74,     71,
       67,     63,     59,     55,     51,     47,     43,     39,     34,
       30,     26,     21,     17,     12,      8,      3,     -1,     -5,
      -10,    -14,    -18,    -23,    -27,    -31,    -35,    -39,    -43,
      -47,    -51,    -55,    -58,    -62,    -65,    -68,    -72,    -75,
      -78,    -80,    -83,    -86,    -88,    -90,    -92,    -94,    -96,
      -98,    -99,   -100,   -101,   -102,   -103,   -104,   -104,   -105,
     -105,   -105,   -105,   -104,   -104,   -103,   -102,   -101,   -100,
      -99,    -98,    -96,    -94,    -92,    -90,    -88,    -86,    -84,
      -81,    -79,    -76,    -73,    -70,    -67,    -64,    -61,    -58,
      -54,    -51,    -47,    -44,    -40,    -37,    -33,    -29,    -26,
      -22,    -18,    -14,    -11,     -7,     -3,      1,      4,      8,
       12,     15,     19,     22,     26,     29,     33,     36,     39,
       42,     45,     48,     51,     54,     56,     59,     61,     64,
       66,     68,     70,     72,     74,     75,     77,     78,     80,
       81,     82,     82,     83,     84,     84,     85,     85,     85,
       85,     84,     84,     84,     83,     82,     81,     80,     79,
       78,     77,     75,     74,     72,     71,     69,     67,     65,
       63,     60,     58,     56,     53,     51,     48,     46,     43,
       40,     38,     35,     32,     29,     26,     24,     21,     18,
       15,     12,      9,      6,      3,      0,     -2,     -5,     -8,
      -11,    -13,    -16,    -19,    -21,    -24,    -26,    -29,    -31,
      -33,    -35,    -38,    -40,    -42,    -43,    -45,    -47,    -49,
      -50,    -52,    -53,    -54,    -55,    -56,    -57,    -58,    -59,
      -60,    -60,    -61,    -61,    -61,    -61,    -61,    -61,    -61,
      -61,    -61,    -60,    -60,    -59,    -59,    -58,    -57,    -56,
      -55,    -54,    -53,    -52,    -50,    -49,    -47,    -46,    -44,
      -43,    -41,    -40,    -38,    -36,    -34,    -32,    -30,    -29,
      -27,    -25,    -23,    -21,    -19,    -17,    -15,    -13,    -11,
       -9,     -7,     -5,     -3,     -1,      1,      3,      5,      6,
        8,     10,     12,     13,     15,     17,     18,     20,     21,
       22,     24,     25,     26,     27,     29,     30,     31,     31,
       32,     33,     34,     34,     35,     36,     36,     36,     37,
       37,     37,     37,     37,     37,     37,     37,     37,     37
};
