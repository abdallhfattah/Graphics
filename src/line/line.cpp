#include "line.h"
#include <iostream>

using namespace std;

/**
 * Draws a line using the naive approach.
 * @param hdc The device context handle.
 * @param x1 The x-coordinate of the start point.
 * @param y1 The y-coordinate of the start point.
 * @param x2 The x-coordinate of the end point.
 * @param y2 The y-coordinate of the end point.
 * @param c The color of the line.
 */
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

/**
 * Draws a line using the Digital Differential Analyzer (DDA) algorithm.
 * @param hdc The device context handle.
 * @param x1 The x-coordinate of the start point.
 * @param y1 The y-coordinate of the start point.
 * @param x2 The x-coordinate of the end point.
 * @param y2 The y-coordinate of the end point.
 * @param c The color of the line.
 */
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
/**
 * Draws a line using a Bresenham line drawing approach.
 * @param hdc The device context handle.
 * @param x1 The x-coordinate of the start point.
 * @param y1 The y-coordinate of the start point.
 * @param x2 The x-coordinate of the end point.
 * @param y2 The y-coordinate of the end point.
 * @param c The color of the line.
 */
void Bresenham(HDC hdc, int x1, int y1, int x2, int y2, COLORREF c)
{
    // Calculate the absolute differences in x and y
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    // Determine the direction of the line (1 or -1)
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;

    // Initialize the error term
    int err = dx - dy;
    int e2;

    // Loop until the end of the line is reached
    while (true)
    {
        // Plot the current pixel
        SetPixel(hdc, x1, y1, c);

        // If the end of the line is reached, exit the loop
        if (x1 == x2 && y1 == y2)
            break;

        // Calculate the double error term
        e2 = 2 * err;

        // Update the x coordinate if the error is greater than -dy
        if (e2 > -dy)
        {
            err = err - dy;
            x1 = x1 + sx;
        }

        // Update the y coordinate if the error is less than dx
        if (e2 < dx)
        {
            err = err + dx;
            y1 = y1 + sy;
        }
    }
}

// unfinished needs to cover other cases
void DrawLineBresenham(HDC hdc, int x1, int y1, int x2, int y2, COLORREF c)
{
    // linear discriminant function   dx (y-y1) - dy (x-x1) = 0
    int dx = (x2 - x1);
    int dy = (y2 - y1);

    // Case 1: slope < 1
    if (abs(dx) >= abs(dy))
    {
        if (x1 < x2)
        {
            swap(x1, x2);
            swap(y1, y2);
        }

        int x = x1;
        int y = y1;

        SetPixel(hdc, x, y, c);

        int incr = dx - 2 * dy;
        int change_1 = 2 * (dx - dy);
        int change_2 = -2 * dy;
        while (x < x2)
        {
            y += (incr <= 0);
            incr += (incr <= 0 ? change_1 : change_2);
            x++;
            SetPixel(hdc, x, y, c);
        }
    }
    // Case 2: slope >= 1
    else if (abs(dy) > abs(dx) && x1 < x2 && y1 < y2)
    {
        // dx  ((y+1) - y1) - dy (x+0.5 - x1);
        int x = x1;
        int y = y1;
    }
}
