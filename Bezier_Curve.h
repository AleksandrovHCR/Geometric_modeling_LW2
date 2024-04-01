#pragma once
#include "Advanced_curve.h"
#include <iostream>
//#include "C:/Users/Aleksandrov/Desktop/Учёба/Геоммод/LabWork/Lab2/GL/glut.h"
#include "C:\Users\Aleksandrov\Desktop\Учёба\Геоммод\LabWork\Lab2\code\graphObject.h"
//#include "C:\Users\Aleksandrov\Desktop\Учёба\Геоммод\LabWork\Lab2\code\vector.h"
class bezier_curve :public advanced_curve {
private:
	double u0_, u1_;

	double r_i, r_n; // Опорные точки

	int* lut[7]; // тругольник паскаля
public:
    bezier_curve(double ri, double rn);
    ~bezier_curve();

    double begin() const override; // get
    double end() const override; // get

    vector<2> operator()(double u) const override
    {
        return vector<2>::comps(u);
    }
	
};