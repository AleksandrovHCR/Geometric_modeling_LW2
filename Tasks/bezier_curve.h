#pragma once
#include"advanced_curve.h"
#include<iostream>
class bezier_curve :public advanced_curve {
private:
	vector<2, double> Start;
	vector<2, double> Middle;
	vector<2, double> Middle2;
	vector<2, double> End;
	vector<2, double> Function(double t);
	vector<2, double> Function2(double t);
	int flag = 0;
public:
	//bezier_curve(double StX, double StY, double MiX, double MiY, double EnX, double EnY);
	bezier_curve(vector<2, double> Start, vector<2, double> Middle, vector<2, double> End);
	bezier_curve(vector<2, double> Start, vector<2, double> Middle, vector<2, double> Middle2, vector<2, double> End);
	 double begin() const override;
	 double end() const override;
	 vector<2> operator()(double u) const override {
		 return vector<2>::comps(u);
	 }
	 void Build();
};