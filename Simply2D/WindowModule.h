#pragma once
#include "Module.h"

class AppWindow;

class WindowModule :
	public Module
{
public:
	WindowModule() : mainWindow(nullptr), Module("Window Module", true) {}
	~WindowModule() {}

	bool Init();
	bool PreUpdate(float deltaTime);
	bool Finish();

	AppWindow* GetMainWindow() const { return mainWindow; }

private:
	AppWindow* CreateNewWindow(const char* title, int x, int y, int width, int height);

private:
	AppWindow* mainWindow;
};