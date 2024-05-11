#include "filling.h"

#include <iostream>
#include <stack>
#include <queue>
using namespace std;
void MyFloodFill(HDC hdc, int x, int y, COLORREF BorderColor, COLORREF FillColor)
{
    std::queue<Point> S;
    // std::stack<Point> S;
    S.push(Point(x, y));
    while (!S.empty())
    {
        // cout << "x : " << x << " y:" << y << "\n";
        Point p = S.front();
        // Point p = S.front();
        S.pop();
        COLORREF c = GetPixel(hdc, p.x, p.y);
        if (c == BorderColor || c == FillColor )//|| y > 1079 || y <= 0 || x > 1919 || x <= 0)
            continue;
        SetPixel(hdc, p.x, p.y, FillColor);
        S.push(Point(p.x, p.y - 1));
        S.push(Point(p.x, p.y + 1));
        S.push(Point(p.x - 1, p.y));
        S.push(Point(p.x + 1, p.y));
    }
}