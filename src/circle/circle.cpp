#include "circle.h"

// using std::cos, std::sin, std::sqrt;

Circle::Circle(HDC hdc, int xc, int yc, int x, int y, COLORREF color, int R)
{
    this->hdc = hdc;
    this->xc = xc;
    this->yc = yc;
    this->R = (R != 0 ? R : sqrtl((x - xc) * (x - xc) + (y - yc) * (y - yc)));
    this->color = color;
}

Circle::~Circle()
{
    // Destructor code
}

void Circle::DrawFace()
{
    DrawCircleBresenham1();
    Circle eye1 = Circle(hdc, this->xc - this->R / 2, this->yc - this->R / 2, this->xc, this->yc, this->color, this->R / 8);
    eye1.DrawCircleBresenham1();
    Circle eye2 = Circle(hdc, this->xc + this->R / 2, this->yc - this->R / 2, this->xc, this->yc, this->color, this->R / 8);
    eye2.DrawCircleBresenham1();
    Circle mouth = Circle(hdc, this->xc, this->yc + this->R / 2, this->xc, this->yc, this->color, this->R / 4);
    mouth.DrawCircleBresenham1();
}

void Circle::Draw8Points(int x, int y)
{
    SetPixel(this->hdc, xc + x, yc + y, this->color);
    SetPixel(this->hdc, xc - x, yc + y, this->color);
    SetPixel(this->hdc, xc + x, yc - y, this->color);
    SetPixel(this->hdc, xc - x, yc - y, this->color);
    // swap
    SetPixel(this->hdc, xc + y, yc + x, this->color);
    SetPixel(this->hdc, xc - y, yc + x, this->color);
    SetPixel(this->hdc, xc + y, yc - x, this->color);
    SetPixel(this->hdc, xc - y, yc - x, this->color);
}

void Circle::DrawCircleCartesian()
{
    int x = 0;
    int y = this->R;
    long long R2 = this->R * this->R;
    Draw8Points(x, y);
    while (x < y)
    {
        x++;
        y = Round(sqrt(R2 - (x * x)));
        Draw8Points(x, y);
    }
}

void Circle::DrawCirclePolarNaive()
{
    int x = R, y = 0;
    Draw8Points(x, y);
    double theta = 0, dtheta = 1.0 / R;
    while (x > y)
    {
        theta += dtheta;
        x = Round(R * cos(theta));
        y = Round(R * sin(theta));
        Draw8Points(x, y);
    }
}

void Circle::DrawCirclePolarNaiveIterative()
{
    double x, y;
    for (double angle = 0; angle <= 45; angle += 0.5)
    {
        x = this->R * cos(angle * PI / 180);
        y = this->R * sin(angle * PI / 180);
        Draw8Points(x, y);
    }
}

void Circle::ShurkainDrawing()
{
    double x = R;
    double y = 0;
    double dtheta = 1.0 / double(R);
    double cos_change = cos(dtheta), sin_change = sin(dtheta);
    while (x >= y)
    {
        Draw8Points(Round(x), Round(y));
        int tmp = (x * cos_change) - (y * sin_change);
        y = (x * sin_change) + y * cos_change;
        x = tmp;
    }
}

void Circle::DrawCirclePolarImproved()
{
    double x = R;
    double y = 0;
    double dtheta = 1.0 / double(R);
    double cos_change = cos(dtheta), sin_change = sin(dtheta);
    while (x >= y)
    {
        Draw8Points(Round(x), Round(y));
        double tmp = (x * cos_change) - (y * sin_change);
        y = (x * sin_change) + y * cos_change;
        x = tmp;
    }
}
// void Circle::DrawCircleBresenham()
// {
//     // unoptimized
//     int x = 0;
//     int y = this->R;
//     int R2 = R * R;
//     Draw8Points(x, y);
//     // int change1 = 2 * x + 3;
//     while (y > x)
//     {
//         double test = (x + 1) * (x + 1) + (y * y - y) - R2;
//         if (test >= 0)
//         {
//             y--;
//         }
//         x++;
//         Draw8Points(x, y);
//     }
// }
void Circle::DrawCircleBresenham1()
{
    // x^2 + y^2 - R^2
    int x = 0;
    int y = this->R;
    int d = 1 - this->R;
    Draw8Points(x, y);
    while (x <= y)
    {

        if (d >= 0)
        {
            d += 2 * (x - y) + 5;
            y--;
        }
        else
        {
            d += 2 * x + 3;
        }
        x++;
        Draw8Points(x, y);
    }
}

void Circle::DrawCircleBresenham2()
{
    int x = 0;
    int y = this->R;
    int d = 1 - R;
    int dE = 3;
    int dSE = 5 - 2 * R;
    Draw8Points(x, y);
    while (y > x)
    {
        if (d < 0)
        {
            d += dE;
            dSE += 2;
        }
        else
        {
            d += dSE;
            dSE += 4;
            y--;
        }
        dE += 2;
        x++;
        Draw8Points(x, y);
    }
}
