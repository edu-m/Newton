#ifndef FUNC_H
#define FUNC_H
//funzione attuale: x^2-2x
#include <math.h>
#include "vals.h"
#include "zero.h"

double evalNR(double a, double b, double iterations)
{
    if (iterations > 0)
    {
        cout << "a= " << a << endl;
        cout << "f(a)= " << func(a) << endl;
        cout << "f'(a)= " << derfunc(a) << endl;
        if (derfunc(a) != 0)
            a = a - (func(a) / derfunc(a));
        else
        {
            cerr << "divisione per zero";
            return -1;
        }
        return evalNR(a, b, --iterations);
    }
    else
        return a;
}

void NR(double a, double b)
{
    double zero1 = eval(a, b);
    double zero2 = evalNR(a, b, 15);
    cout<<zero1<<endl;
    cout<<zero2<<endl;
    if (intzero1 == zero2) cout<<"Awesome!"<<endl;
    else cout<<"Something's off :/"<<endl;
}
#endif