#ifndef lines
#define lines
#define el '\n'

#include "../helper.h"

#include <windows.h>
void DrawLineNaive(HDC hdc, int x1, int y1, int x2, int y2, COLORREF c);

void DrawLineDDA(HDC hdc, int x1, int y1, int x2, int y2, COLORREF c);

/* Draw using the mid point approach */
void DrawLineBresenham(HDC hdc, int x1, int y1, int x2, int y2, COLORREF c);

void Bresenham(HDC hdc, int x1, int y1, int x2, int y2, COLORREF c);

#endif
