#pragma once
#include "C:\Users\Aleksandrov\Desktop\�����\�������\LabWork\Lab2\code\graphObject.h"
#include<iostream>
#include <fstream>
class txt_points {
private:
	int Npoints = 0;//����� �����
	vector<2,double>* Points;
	
public:
	vector<2, double>*  Read_file(char *filename);
	int get_points();
	~txt_points();
};