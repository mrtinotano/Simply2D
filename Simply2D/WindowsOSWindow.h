#pragma once

#if defined(_WIN32) || defined(_WIN64)
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif

#include "AppWindow.h"

class WindowsOSWindow :
	public AppWindow
{
public:
	WindowsOSWindow(const char* name, int x, int y, int width, int height);

	void SetTitle(const char* title) override;
	void UpdateWindowEvents() override;
	glm::vec2 GetWindowCursorPos() override;

	HWND GetHandle() { return windowHandle; }
	HINSTANCE GetInstance() { return GetModuleHandleW(NULL); }

private:
	bool RegisterWindowClass();
	bool CreateNewWindow();

private:
	HWND windowHandle;
};