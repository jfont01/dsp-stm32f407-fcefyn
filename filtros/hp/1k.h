/*
 * Filter Coefficients (C Source) generated by the Filter Design and Analysis Tool
 * Generated by MATLAB(R) 24.1 and DSP System Toolbox 24.1.
 * Generated on: 12-Mar-2025 18:25:47
 */

/*
 * Discrete-Time FIR Filter (real)
 * -------------------------------
 * Filter Structure  : Direct-Form FIR
 * Filter Length     : 1500
 * Stable            : Yes
 * Linear Phase      : Yes (Type 4)
 * Arithmetic        : fixed
 * Numerator         : s16,15 -> [-1 1)
 * Input             : s16,15 -> [-1 1)
 * Filter Internals  : Full Precision
 *   Output          : s34,30 -> [-8 8)  (auto determined)
 *   Product         : s31,30 -> [-1 1)  (auto determined)
 *   Accumulator     : s34,30 -> [-8 8)  (auto determined)
 *   Round Mode      : No rounding
 *   Overflow Mode   : No overflow
 */

/* General type conversion for MATLAB generated C-code  */
#include "tmwtypes.h"
/* 
 * Expected path to tmwtypes.h 
 * C:\Program Files\MATLAB\R2024a\extern\include\tmwtypes.h 
 */
const int BL = 1500;
const int16_T B[1500] = {
      -10,      0,      0,      0,     -1,     -1,     -1,     -1,     -1,
       -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,
       -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,
       -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,
       -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,
       -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,
       -1,     -1,     -1,     -1,     -1,     -1,     -1,     -2,     -2,
       -2,     -2,     -2,     -2,     -2,     -2,     -2,     -2,     -2,
       -2,     -2,     -2,     -2,     -2,     -2,     -2,     -2,     -2,
       -2,     -2,     -2,     -2,     -2,     -2,     -2,     -2,     -2,
       -2,     -2,     -2,     -2,     -2,     -2,     -2,     -2,     -3,
       -3,     -3,     -3,     -3,     -3,     -3,     -3,     -3,     -3,
       -3,     -3,     -3,     -3,     -3,     -3,     -3,     -3,     -3,
       -3,     -3,     -3,     -3,     -3,     -3,     -3,     -3,     -3,
       -4,     -4,     -4,     -4,     -4,     -4,     -4,     -4,     -4,
       -4,     -4,     -4,     -4,     -4,     -4,     -4,     -4,     -4,
       -4,     -4,     -4,     -4,     -4,     -4,     -4,     -5,     -5,
       -5,     -5,     -5,     -5,     -5,     -5,     -5,     -5,     -5,
       -5,     -5,     -5,     -5,     -5,     -5,     -5,     -5,     -5,
       -5,     -5,     -6,     -6,     -6,     -6,     -6,     -6,     -6,
       -6,     -6,     -6,     -6,     -6,     -6,     -6,     -6,     -6,
       -6,     -6,     -6,     -6,     -7,     -7,     -7,     -7,     -7,
       -7,     -7,     -7,     -7,     -7,     -7,     -7,     -7,     -7,
       -7,     -7,     -7,     -7,     -7,     -7,     -8,     -8,     -8,
       -8,     -8,     -8,     -8,     -8,     -8,     -8,     -8,     -8,
       -8,     -8,     -8,     -8,     -8,     -8,     -8,     -8,     -9,
       -9,     -9,     -9,     -9,     -9,     -9,     -9,     -9,     -9,
       -9,     -9,     -9,     -9,     -9,     -9,     -9,     -9,     -9,
      -10,    -10,    -10,    -10,    -10,    -10,    -10,    -10,    -10,
      -10,    -10,    -10,    -10,    -10,    -10,    -10,    -10,    -10,
      -10,    -10,    -10,    -11,    -11,    -11,    -11,    -11,    -11,
      -11,    -11,    -11,    -11,    -11,    -11,    -11,    -11,    -11,
      -11,    -11,    -11,    -11,    -11,    -11,    -11,    -11,    -12,
      -12,    -12,    -12,    -12,    -12,    -12,    -12,    -12,    -12,
      -12,    -12,    -12,    -12,    -12,    -12,    -12,    -12,    -12,
      -12,    -12,    -12,    -12,    -12,    -12,    -12,    -12,    -12,
      -12,    -12,    -12,    -12,    -13,    -13,    -13,    -13,    -13,
      -13,    -13,    -13,    -13,    -13,    -13,    -13,    -13,    -13,
      -13,    -13,    -13,    -13,    -13,    -13,    -13,    -13,    -13,
      -13,    -13,    -13,    -13,    -13,    -13,    -13,    -13,    -13,
      -13,    -13,    -13,    -13,    -13,    -13,    -13,    -13,    -13,
      -13,    -13,    -13,    -13,    -13,    -13,    -13,    -13,    -13,
      -13,    -13,    -13,    -13,    -13,    -13,    -13,    -13,    -13,
      -13,    -13,    -13,    -13,    -12,    -12,    -12,    -12,    -12,
      -12,    -12,    -12,    -12,    -12,    -12,    -12,    -12,    -12,
      -12,    -12,    -12,    -12,    -12,    -12,    -12,    -12,    -12,
      -11,    -11,    -11,    -11,    -11,    -11,    -11,    -11,    -11,
      -11,    -11,    -11,    -11,    -11,    -11,    -10,    -10,    -10,
      -10,    -10,    -10,    -10,    -10,    -10,    -10,    -10,     -9,
       -9,     -9,     -9,     -9,     -9,     -9,     -9,     -9,     -9,
       -8,     -8,     -8,     -8,     -8,     -8,     -8,     -8,     -7,
       -7,     -7,     -7,     -7,     -7,     -7,     -7,     -6,     -6,
       -6,     -6,     -6,     -6,     -6,     -5,     -5,     -5,     -5,
       -5,     -5,     -4,     -4,     -4,     -4,     -4,     -4,     -3,
       -3,     -3,     -3,     -3,     -2,     -2,     -2,     -2,     -2,
       -1,     -1,     -1,     -1,     -1,      0,      0,      0,      0,
        1,      1,      1,      1,      1,      2,      2,      2,      2,
        3,      3,      3,      3,      4,      4,      4,      4,      5,
        5,      5,      6,      6,      6,      6,      7,      7,      7,
        8,      8,      8,      9,      9,      9,      9,     10,     10,
       10,     11,     11,     11,     12,     12,     12,     13,     13,
       14,     14,     14,     15,     15,     15,     16,     16,     17,
       17,     17,     18,     18,     19,     19,     19,     20,     20,
       21,     21,     22,     22,     22,     23,     23,     24,     24,
       25,     25,     26,     26,     27,     27,     28,     28,     29,
       29,     30,     30,     31,     32,     32,     33,     33,     34,
       34,     35,     36,     36,     37,     37,     38,     39,     39,
       40,     41,     41,     42,     43,     43,     44,     45,     45,
       46,     47,     47,     48,     49,     50,     51,     51,     52,
       53,     54,     55,     55,     56,     57,     58,     59,     60,
       61,     62,     63,     63,     64,     65,     66,     67,     68,
       69,     71,     72,     73,     74,     75,     76,     77,     78,
       80,     81,     82,     83,     85,     86,     87,     89,     90,
       91,     93,     94,     96,     97,     99,    101,    102,    104,
      105,    107,    109,    111,    113,    115,    116,    118,    120,
      123,    125,    127,    129,    131,    134,    136,    139,    141,
      144,    146,    149,    152,    155,    158,    161,    164,    168,
      171,    175,    178,    182,    186,    190,    194,    199,    203,
      208,    213,    218,    224,    229,    235,    241,    248,    255,
      262,    269,    277,    285,    294,    303,    313,    324,    335,
      346,    359,    373,    387,    403,    420,    438,    458,    480,
      504,    530,    559,    592,    628,    669,    716,    769,    831,
      904,    991,   1096,   1225,   1389,   1603,   1895,   2317,   2979,
     4172,   6953,  20861, -20861,  -6953,  -4172,  -2979,  -2317,  -1895,
    -1603,  -1389,  -1225,  -1096,   -991,   -904,   -831,   -769,   -716,
     -669,   -628,   -592,   -559,   -530,   -504,   -480,   -458,   -438,
     -420,   -403,   -387,   -373,   -359,   -346,   -335,   -324,   -313,
     -303,   -294,   -285,   -277,   -269,   -262,   -255,   -248,   -241,
     -235,   -229,   -224,   -218,   -213,   -208,   -203,   -199,   -194,
     -190,   -186,   -182,   -178,   -175,   -171,   -168,   -164,   -161,
     -158,   -155,   -152,   -149,   -146,   -144,   -141,   -139,   -136,
     -134,   -131,   -129,   -127,   -125,   -123,   -120,   -118,   -116,
     -115,   -113,   -111,   -109,   -107,   -105,   -104,   -102,   -101,
      -99,    -97,    -96,    -94,    -93,    -91,    -90,    -89,    -87,
      -86,    -85,    -83,    -82,    -81,    -80,    -78,    -77,    -76,
      -75,    -74,    -73,    -72,    -71,    -69,    -68,    -67,    -66,
      -65,    -64,    -63,    -63,    -62,    -61,    -60,    -59,    -58,
      -57,    -56,    -55,    -55,    -54,    -53,    -52,    -51,    -51,
      -50,    -49,    -48,    -47,    -47,    -46,    -45,    -45,    -44,
      -43,    -43,    -42,    -41,    -41,    -40,    -39,    -39,    -38,
      -37,    -37,    -36,    -36,    -35,    -34,    -34,    -33,    -33,
      -32,    -32,    -31,    -30,    -30,    -29,    -29,    -28,    -28,
      -27,    -27,    -26,    -26,    -25,    -25,    -24,    -24,    -23,
      -23,    -22,    -22,    -22,    -21,    -21,    -20,    -20,    -19,
      -19,    -19,    -18,    -18,    -17,    -17,    -17,    -16,    -16,
      -15,    -15,    -15,    -14,    -14,    -14,    -13,    -13,    -12,
      -12,    -12,    -11,    -11,    -11,    -10,    -10,    -10,     -9,
       -9,     -9,     -9,     -8,     -8,     -8,     -7,     -7,     -7,
       -6,     -6,     -6,     -6,     -5,     -5,     -5,     -4,     -4,
       -4,     -4,     -3,     -3,     -3,     -3,     -2,     -2,     -2,
       -2,     -1,     -1,     -1,     -1,     -1,      0,      0,      0,
        0,      1,      1,      1,      1,      1,      2,      2,      2,
        2,      2,      3,      3,      3,      3,      3,      4,      4,
        4,      4,      4,      4,      5,      5,      5,      5,      5,
        5,      6,      6,      6,      6,      6,      6,      6,      7,
        7,      7,      7,      7,      7,      7,      7,      8,      8,
        8,      8,      8,      8,      8,      8,      9,      9,      9,
        9,      9,      9,      9,      9,      9,      9,     10,     10,
       10,     10,     10,     10,     10,     10,     10,     10,     10,
       11,     11,     11,     11,     11,     11,     11,     11,     11,
       11,     11,     11,     11,     11,     11,     12,     12,     12,
       12,     12,     12,     12,     12,     12,     12,     12,     12,
       12,     12,     12,     12,     12,     12,     12,     12,     12,
       12,     12,     13,     13,     13,     13,     13,     13,     13,
       13,     13,     13,     13,     13,     13,     13,     13,     13,
       13,     13,     13,     13,     13,     13,     13,     13,     13,
       13,     13,     13,     13,     13,     13,     13,     13,     13,
       13,     13,     13,     13,     13,     13,     13,     13,     13,
       13,     13,     13,     13,     13,     13,     13,     13,     13,
       13,     13,     13,     13,     13,     13,     13,     13,     13,
       13,     13,     12,     12,     12,     12,     12,     12,     12,
       12,     12,     12,     12,     12,     12,     12,     12,     12,
       12,     12,     12,     12,     12,     12,     12,     12,     12,
       12,     12,     12,     12,     12,     12,     12,     11,     11,
       11,     11,     11,     11,     11,     11,     11,     11,     11,
       11,     11,     11,     11,     11,     11,     11,     11,     11,
       11,     11,     11,     10,     10,     10,     10,     10,     10,
       10,     10,     10,     10,     10,     10,     10,     10,     10,
       10,     10,     10,     10,     10,     10,      9,      9,      9,
        9,      9,      9,      9,      9,      9,      9,      9,      9,
        9,      9,      9,      9,      9,      9,      9,      8,      8,
        8,      8,      8,      8,      8,      8,      8,      8,      8,
        8,      8,      8,      8,      8,      8,      8,      8,      8,
        7,      7,      7,      7,      7,      7,      7,      7,      7,
        7,      7,      7,      7,      7,      7,      7,      7,      7,
        7,      7,      6,      6,      6,      6,      6,      6,      6,
        6,      6,      6,      6,      6,      6,      6,      6,      6,
        6,      6,      6,      6,      5,      5,      5,      5,      5,
        5,      5,      5,      5,      5,      5,      5,      5,      5,
        5,      5,      5,      5,      5,      5,      5,      5,      4,
        4,      4,      4,      4,      4,      4,      4,      4,      4,
        4,      4,      4,      4,      4,      4,      4,      4,      4,
        4,      4,      4,      4,      4,      4,      3,      3,      3,
        3,      3,      3,      3,      3,      3,      3,      3,      3,
        3,      3,      3,      3,      3,      3,      3,      3,      3,
        3,      3,      3,      3,      3,      3,      3,      2,      2,
        2,      2,      2,      2,      2,      2,      2,      2,      2,
        2,      2,      2,      2,      2,      2,      2,      2,      2,
        2,      2,      2,      2,      2,      2,      2,      2,      2,
        2,      2,      2,      2,      2,      2,      2,      2,      1,
        1,      1,      1,      1,      1,      1,      1,      1,      1,
        1,      1,      1,      1,      1,      1,      1,      1,      1,
        1,      1,      1,      1,      1,      1,      1,      1,      1,
        1,      1,      1,      1,      1,      1,      1,      1,      1,
        1,      1,      1,      1,      1,      1,      1,      1,      1,
        1,      1,      1,      1,      1,      1,      1,      1,      1,
        1,      1,      0,      0,      0,     10
};
