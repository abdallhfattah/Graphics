#include "line.h"
#include <iostream>

using namespace std;

int Round(double val)
{
    return int(val + 0.5);
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void DrawLineNaive(HDC hdc, int x1, int y1, int x2, int y2, COLORREF c)
{
    // calc dy , dx
    int dx = x2 - x1;
    int dy = y2 - y1;

    // slope < 1
    if (abs(dy) <= abs(dx))
    {
        double slope = (double)dy / dx;
        if (x1 > x2)
        {
            swap(x1, x2);
            swap(y1, y2);
        }
        for (int x = x1; x <= x2; x++)
        {
            int y = Round(y1 + (x - x1) * slope);
            SetPixel(hdc, x, y, c);
        }
    }
    else
    {
        double re_slope = (double)dx / dy;
        if (y1 > y2)
        {
            swap(x1, x2);
            swap(y1, y2);
        }
        for (int y = y1; y <= y2; y++)
        {
            int x = Round(x1 + (y - y1) * re_slope);
            SetPixel(hdc, x, y, c);
        }
    }
}

void DrawLineDDA(HDC hdc, int x1, int y1, int x2, int y2, COLORREF c)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    if (abs(dy) <= abs(dx))
    {
        if (x1 > x2)
        {
            swap(x1, x2);
            swap(y1, y2);
        }

        int x = x1;
        double y = y1;
        double slope = double(dy) / double(dx);
        SetPixel(hdc, x, y, c);
        while (x < x2)
        {
            y += slope;
            x++;
            SetPixel(hdc, x, Round(y), c);
        }
    }
    else
    {
        if (y1 > y2)
        {
            swap(y1, y2);
            swap(x1, x2);
        }
        int y = y1;
        double x = x1;
        double slope = double(dx) / double(dy);
        SetPixel(hdc, x, y, c);
        while (y < y2)
        {
            x += slope;
            y++;
            SetPixel(hdc, Round(x), y, c);
        }
    }
}