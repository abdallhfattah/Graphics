#if defined(UNICODE) && !defined(_UNICODE)
#define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
#define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include <iostream>
#include <wingdi.h>
#include "line/line.h"
#include <cmath>

using namespace std;
// #include "LineAlgorithms.h"
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
    wincl.hbrBackground = (HBRUSH)COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx(&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd =
        CreateWindowEx(0,                                                               /* Extended possibilites for variation */
                       szClassName,                                                     /* Classname */
                       _T(" Template Windows App"),                                     /* Title Text */
                       WS_OVERLAPPEDWINDOW,                                             /* default window */
                       CW_USEDEFAULT,                                                   /* Windows decides the position */
                       CW_USEDEFAULT, /* where the window ends up on the screen */ 544, /* The programs width */
                       375,                                                             /* and height in pixels */
                       HWND_DESKTOP,                                                    /* The window is a child-window to desktop */
                       NULL,                                                            /* No menu */
                       hThisInstance,                                                   /* Program Instance handler */
                       NULL                                                             /* No Window Creation data */
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

/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    static int x, y;
    switch (message)
    {
    case WM_LBUTTONDOWN:
    {
        // hdc = GetDC(hwnd);
        x = LOWORD(lParam);
        y = HIWORD(lParam);
        // ReleaseDC(hwnd, hdc);
        cout << x << " " << y << el;
        break;
    }

    case WM_LBUTTONUP:
    { // Release of left click
        hdc = GetDC(hwnd);
        COLORREF c = RGB(255, 0, 0);
        int x1 = LOWORD(lParam);
        int y1 = HIWORD(lParam);
        cout << x1 << " " << y1 << el;
        DrawLineBresenham(hdc , x , y , x1 , y1 , c);
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
