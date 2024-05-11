#ifndef circle
#define circle

#include "../helper.h"
#include <windows.h>

const double PI = 3.14159265358979323846;

/**
 * @brief A class for drawing circles using various algorithms.
 *
 * This class provides methods to draw circles using different algorithms,
 * including Cartesian, polar, and Bresenham's algorithms.
 * The algorithms are implemented as methods of this class, allowing for easy
 * use and comparison of different circle drawing techniques.
 */

class Circle
{
private:
    /**
     * @brief Draws 8 symmetric points of a circle centered at (xc, yc) with radius R and specified color.
     *
     * This function draws 8 symmetric points of a circle centered at (xc, yc) with radius R and the specified color.
     * The points are drawn using the SetPixel function of the specified device context hdc.
     *
     * @param hdc The device context handle.
     * @param c The color of the points.
     * @param x x point.
     * @param y y point.
     */
    void Draw8Points(int x, int y);

    HDC hdc;        // The device context handle
    int xc;         // The x-coordinate of the center of the circle
    int yc;         // The y-coordinate of the center of the circle
    int R;          // The radius of the circle
    COLORREF color; // The color of the circle

public:
    /**
     * @brief Constructor for Circle class.
     * @param hdc The device context handle.
     * @param xc The x-coordinate of the center of the circle.
     * @param yc The y-coordinate of the center of the circle.
     * @param x The x-coordinate of a point on the circumference of the circle.
     * @param y The y-coordinate of a point on the circumference of the circle.
     * @param color The color of the circle.
     * @param R optional raduis
     */
    Circle(HDC hdc, int xc, int yc, int x, int y, COLORREF color, int R = 0);
    /**
     * @brief Destructor.
     */
    ~Circle();

    /**
     * @brief Draws a circle using the Cartesian equation (x^2 + y^2 = R^2).
     */
    void DrawCircleCartesian();

    /**
     * @brief Draws a circle using the naive polar approach.
     */
    void DrawCirclePolarNaive();
    void ShurkainDrawing();
    /**
     * @brief Draws a circle using the iterative polar approach.
     */
    void DrawCirclePolarNaiveIterative();
    void DrawFace();
    /**
     * @brief Draws a circle using the improved polar approach.
     */
    void DrawCirclePolarImproved();

    /**
     * @brief Draws a circle using Bresenham's first-order difference algorithm.
     */
    void DrawCircleBresenham1();

    /**
     * @brief Draws a circle using Bresenham's second-order difference algorithm.
     */
    void DrawCircleBresenham2();
};

#endif
