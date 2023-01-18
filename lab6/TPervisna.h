#ifndef TPervisna_h
#define TPervisna_h
#include "TPolinom.h"

class TPervisna : public TPolinom
{
public:
    TPervisna();
    TPervisna(TPolinom);

    void output();
    double F_x(double);

    void equation(double, double, double);
    void draw(double, double);
};

#endif