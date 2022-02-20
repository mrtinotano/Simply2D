#pragma once
#include "Module.h"

class Window;

class WindowModule :
	public Module
{
public:
	WindowModule() : mainWindow(nullptr), Module("Window Module", true) {}
	~WindowModule() {}

	bool Init();
	bool PreUpdate(float deltaTime);
	bool CleanUp();

	Window* GetMainWindow() const { return mainWindow; }

private:
	Window* CreateNewWindow(const char* title, int x, int y, int widht, int height);

private:
	Window* mainWindow;
};