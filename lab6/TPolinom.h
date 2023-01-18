#ifndef TPolinom_h
#define TPolinom_h
#include "TFunction.h"

class TPolinom : public TFunction
{
protected:
    int maxPower;
    colors color;

public:
    double coef[MAX_SIZE];
    TPolinom();
    TPolinom(double *);

    int getPower() { return maxPower; }
    double* getCoefs() { return coef; }
    double f_x(double x);
    void input();
    void virtual output();

    void equation(double, double, double);
    void draw(double, double);
};

#endif