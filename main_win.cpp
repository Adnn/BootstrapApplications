#include "appicon.h"

#include <iostream>

#include <windows.h>
#include <wincon.h>


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message)
    {
    case WM_CLOSE:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // Attach the parent console if present, or allocate a new console.
    if(AttachConsole(ATTACH_PARENT_PROCESS) || AllocConsole())
    {
        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);
    }

    std::cout << "I am a GUI application with an icon." << std::endl;

    WNDCLASS wc      = {0};
    wc.lpfnWndProc   = WndProc;
    wc.hInstance     = hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
    wc.lpszClassName = "minwindowsapp";
    // Set the icon Win32 GUI application icon.
    wc.hIcon         = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
    if(!RegisterClass(&wc))
    {
      return 1;
    }

    if(!CreateWindow(wc.lpszClassName,
                     "Minimal Windows Application",
                     WS_OVERLAPPEDWINDOW|WS_VISIBLE,
                     0,0,640,480,0,0,hInstance,NULL))
    {
        return 2;
    }

    MSG msg          = {0};
    while(GetMessage( &msg, NULL, 0, 0 ) > 0)
    {
        DispatchMessage( &msg );
    }

    std::cerr << "Goodbye." << std::endl;

    return 0;
}
