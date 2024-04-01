#pragma once
#ifndef __ADVANCED__CURVE__
#define __ADVANCED_CURVE__
#include "C:\Users\Aleksandrov\Desktop\׃ק¸בא\ֳומללמה\LabWork\Lab2\code\graphObject.h"

class advanced_curve {
public:
    virtual double begin() const;
    virtual double end() const;

    virtual vector<2> operator()(double u) const;
};
#endif