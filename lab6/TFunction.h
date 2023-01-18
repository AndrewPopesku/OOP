#ifndef TFunction_h
#define TFunction_h
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <graphics.h>
#define MAX_SIZE 250
using namespace std;

class TFunction
{
public:
    virtual void equation(double, double, double) = 0;
    virtual void draw(double, double) = 0;
};

#endif