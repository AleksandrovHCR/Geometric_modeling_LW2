#pragma once
#include"advanced_curve.h"
//亚历山德罗夫·迪米特里·费多罗维奇
class b_spline :public advanced_curve {
private:
	int Degree;//Степень БФ
	int Points_col;//Число точек
	int Nodes;//Число узлов
	double* u_points;//Вектор узловых точек
	double** N_points;//Треугольник базисных функций
	double* plots; //Массив различных чисел
	int plots_len=0;//Длина массива plots
	
	int NP_h;//высота N_points
	double Cox_de_boor(int i, int p,double u);//Значения в матрице
	double C_function(double u, int value);//Основная функция по вычислению координат точек Б сплайна value: 0-x 1-y
	void init_N_points(int x, int y);
	void Calculate_N_points(double u);
	void Destroy_the_equivalents(int nU);//Создание отдельного массива из разных чисел в u_points
	
	void DebugMatrix();
	

	vector<2, double>* Points; //Точки

public:
	void Построить();
	b_spline(double* U, vector<2, double>* P, int nP, int nU);
	~b_spline();
	double begin() const override;
	double end() const override;
	vector<2> operator()(double u) const override {
		return vector<2>::comps(u);
	}
	void drawPoints();
};