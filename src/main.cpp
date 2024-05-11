#if defined(UNICODE) && !defined(_UNICODE)
#define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
#define UNICODE
#endif

/* Includes */
#include <tchar.h>
#include <windows.h>
#include <wingdi.h>
#include <utility>
#include <vector>
#include <iostream>
// #include <cmath>

#include "circle/circle.h"
#include "fillingAlgorithm/filling.h"

// #include "FillingAlgorithms/FillingAlgorithms.h"

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
TCHAR szClassName[] = _T("Windows App");

int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow)
{
    HWND hwnd;        /* This is the handle for our window */
    MSG messages;     /* Here messages to the application are saved */
    WNDCLASSEX wincl; /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure; /* This function is called by windows */
    wincl.style = CS_DBLCLKS;            /* Catch double-clicks */
    wincl.cbSize = sizeof(WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL; /* No menu */
    wincl.cbClsExtra = 0;      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    COLORREF color = RGB(0, 0, 0);
    wincl.hbrBackground = (HBRUSH)color;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx(&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd =
        CreateWindowEx(0,                           /* Extended possibilites for variation */
                       szClassName,                 /* Classname */
                       _T(" Template Windows App"), /* Title Text */
                       WS_OVERLAPPEDWINDOW,         /* default window */
                       CW_USEDEFAULT,               /* Windows decides the position */
                       CW_USEDEFAULT,               /* where the window ends up on the screen */
                       1200,                        /* The programs width */
                       1200,                        /* and height in pixels */
                       HWND_DESKTOP,                /* The window is a child-window to desktop */
                       NULL,                        /* No menu */
                       hThisInstance,               /* Program Instance handler */
                       NULL                         /* No Window Creation data */
        );

    /* Make the window visible on the screen */
    ShowWindow(hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage(&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    static int x, y;
    // int count = 0, length = 5;
    // static vector<pair<int, int>> points;
    static COLORREF c = RGB(255, 255, 255);
    switch (message)
    {

    case WM_LBUTTONDOWN:
    { // Down Left Click
        hdc = GetDC(hwnd);
        x = LOWORD(lParam);
        y = HIWORD(lParam);

        ReleaseDC(hwnd, hdc);
        break;
    }

    // WM_RBUTTONDOWN -> Down Right Click
    // WM_LBUTTONUP -> relase
    case WM_RBUTTONDOWN:
    {
        hdc = GetDC(hwnd);
        x = LOWORD(lParam);
        y = HIWORD(lParam);

        // drawing 8 with filling alogrithm
        // COLORREF white = RGB(255, 255, 255);
        // int R = 50;
        // Circle eight1 = Circle(hdc, x, y, x, y, white, 80);
        // Circle eight2 = Circle(hdc, x, y, x, y, white, 40);
        // Circle eight3 = Circle(hdc, x, y - 130, x, y, white, 70);
        // Circle eight4 = Circle(hdc, x, y - 130, x, y, white, 35);
        // eight1.DrawCircleBresenham2();
        // eight2.DrawCircleBresenham2();
        // eight3.DrawCircleBresenham2();
        // eight4.DrawCircleBresenham2();
        // MyFloodFill(hdc, x, y - 42, white, white);
        // MyFloodFill(hdc, x, y - 62, white, white);
        // MyFloodFill(hdc, x, y - 82, white, white);

        ReleaseDC(hwnd, hdc);
    }
    case WM_LBUTTONUP:
    {
        hdc = GetDC(hwnd);
        // COLORREF c = RGB(255, 0, 0);
        int x1 = LOWORD(lParam);
        int y1 = HIWORD(lParam);

        // Drawing Face
        Circle face = Circle(hdc, x, y, x1, y1, c);
        face.DrawFace();
        ReleaseDC(hwnd, hdc);
        break;
    }
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}
