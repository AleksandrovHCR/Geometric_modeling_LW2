#include "Bezier_Curve.h"

#include <iostream>

/// https://pomax.github.io/bezierinfo/#introduction

bezier_curve::bezier_curve(double ri, double rn):r_i(ri), r_n(rn)
{
    lut[0] = new int[1] {1};
    lut[1] = new int[2] {1, 1};
    lut[2] = new int[3] {1, 2, 1};
    lut[3] = new int[4] {1, 3, 3, 1};
    lut[4] = new int[5] {1, 4, 6, 4, 1};
    lut[5] = new int[6] {1, 5, 10, 10, 5, 1};
    lut[6] = new int[7] {1, 6, 15, 20, 15, 6, 1};
}

bezier_curve::~bezier_curve()
{
    for (int i = 0; i < 7; i++)
    {
        delete[] lut[i];
    }
}

 double bezier_curve::begin() const 
{
    return this->r_i;
}

double bezier_curve::end() const
{
    return this->r_n;
}