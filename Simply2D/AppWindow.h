#pragma once

#include <vec2.hpp>

class AppWindow
{
public:

	AppWindow(const char* name, int x, int y, int width, int height);
	~AppWindow();

	virtual void SetTitle(const char* tittle) = 0;
	virtual void UpdateWindowEvents() = 0;
	virtual glm::vec2 GetWindowCursorPos() = 0;

	int GetWidth() { return windowWidth; }
	int GetHeight() { return windowHeight; }

	float GetAspectRatio() { return (float)windowWidth / (float)windowHeight; }

private:
	//void OnWindowResized(WindowResizedEvent& event);
	//void OnWindowMoved(WindowMovedEvent& event);

protected:
	int windowX;
	int windowY;
	int windowWidth;
	int windowHeight;

	const char* windowTitle;
};