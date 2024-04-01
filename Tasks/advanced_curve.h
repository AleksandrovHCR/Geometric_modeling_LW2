#pragma once
#include "C:\Users\Aleksandrov\Desktop\׃ק¸בא\ֳומללמה\LabWork\Lab2\code\graphObject.h"
class advanced_curve {
	virtual double begin() const=0;
	virtual double end() const=0;
	virtual vector<2> operator()(double u) const=0;
};