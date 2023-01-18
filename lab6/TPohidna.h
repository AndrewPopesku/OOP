#ifndef TPohidna_h
#define TPohidna_h
#include "TPolinom.h"

class TPohidna : public TPolinom
{
    double derMaxPower;
    double derCoefs[MAX_SIZE];

public:
    TPohidna();
    TPohidna(double *);
    TPohidna(TPolinom);

    void output();
    double derInPoint(double);

    void equation(double, double, double);
    void draw(double, double);
};

#endif