#include "WindowModule.h"
#include "AppWindow.h"
#include "WindowsOSWindow.h"


bool WindowModule::Init()
{
	mainWindow = CreateNewWindow("Simply2D", 0, 0, 800, 1200);
	return mainWindow != nullptr;
}

bool WindowModule::PreUpdate(float deltaTime)
{
	mainWindow->UpdateWindowEvents();
	return true;
}

bool WindowModule::Finish()
{
	delete mainWindow;
	return true;
}

AppWindow* WindowModule::CreateNewWindow(const char* title, int x, int y, int width, int height)
{
	return new WindowsOSWindow(title, x, y, width, height);
}
