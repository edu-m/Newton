#ifndef ZERO_H
#define ZERO_H
#include <iostream>
using namespace std;
#include "vals.h"
double iterative_zero(double, double, int);
double func(double);

#define CONDITION func(a) * func(b) > 0 || a == b || cont <= 0
#define CONDEVALP func(a) * func(b) > 0 || a == b

void print(double a)
{
    cout<<a;
}

double eval(double a, double b)
{
    if (CONDEVALP)
        {cout << "Input non valido" << endl;
        return 0;}
    else
        return iterative_zero(a, b, 50);
}

void swap(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

double iterative_zero(double a, double b, int c)
{
    if (b < a)
        swap(&a, &b);
    double m = (a + b) / 2;
    double fm = func(m);
    if (c >= 0)
    {
        if (fm == 0)
        {
            //std::cout << fm << std::endl;
            return fm;
        } //se fa 0 siamo fortunati, non c'è bisogno di procedere
        else if (fm > 0)
        {
            //std::cout << fm << std::endl;
            return iterative_zero(a, m, --c);
        } //consideriamo la funzione tra "a" e il punto medio tra "a" e "b"
        else
        {
            //std::cout << fm << std::endl;
            return iterative_zero(m, b, --c);
        } //consideriamo la funzione tra il punto medio tra "a" e "b" e "b"
        cout<<fm<<endl;
    }
    return m;
}

double func(double x)
{
    return FUN; //inserire qui la legge della funzione
}
double derfunc(double x)
{
    return DERFUN;
}

#endif