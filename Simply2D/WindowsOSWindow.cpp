#include "WindowsOSWindow.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_ACTIVATEAPP:
         //(bool)wParam;  Window is active/inactive
        break;
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        break;
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}

WindowsOSWindow::WindowsOSWindow(const char* name, int x, int y, int width, int height) : AppWindow(name, x, y, width, height)
{
    bool reg = RegisterWindowClass();
    //GF_ASSERT(reg, "Windows OS register window returned false");

    bool create = CreateNewWindow();
    //GF_ASSERT(create, "Failed to create new Windows OS window");
}

bool WindowsOSWindow::RegisterWindowClass()
{
    WNDCLASSEX wc = {};

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = (WNDPROC)WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = GetModuleHandleW(NULL);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "WindowsClass";
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClassEx(&wc))
    {
        return false;
    }

    return true;
}

bool WindowsOSWindow::CreateNewWindow()
{
    windowHandle = CreateWindowEx(
        WS_EX_ACCEPTFILES,
        "WindowsClass",
        windowTitle,
        WS_OVERLAPPEDWINDOW,
        windowX, windowY, windowWidth, windowHeight,
        NULL, NULL, GetModuleHandleW(NULL), NULL);

    if (windowHandle == NULL)
    {
        return false;
    }

    ShowWindow(windowHandle, SW_SHOWNA);

    return true;
}

void WindowsOSWindow::UpdateWindowEvents()
{
    MSG msg;

    while (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE))
    {
        if (msg.message == WM_QUIT)
        {

        }
        else
        {
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }
    }
}

glm::vec2 WindowsOSWindow::GetWindowCursorPos()
{
    POINT cursorPos;
    GetCursorPos(&cursorPos);
    ScreenToClient(windowHandle, &cursorPos);

    return glm::vec2(cursorPos.x, cursorPos.y);
}

void WindowsOSWindow::SetTitle(const char* title)
{
    SetWindowTextA(windowHandle, title);
}