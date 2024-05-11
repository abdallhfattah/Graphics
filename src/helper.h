#ifndef helper
#define helper

#include <math.h>
#include <cmath>
#include <tchar.h>

#include <windows.h>

#include <iostream>

#include <wingdi.h>


inline void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

inline int Round(double x)
{
	return (int)(x + 0.5);
}

#endif
