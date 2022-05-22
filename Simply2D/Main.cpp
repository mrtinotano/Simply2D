#if defined(_WIN32) || defined(_WIN64)
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "Application.h"

Application* App = nullptr;

int CALLBACK WinMain
(
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
)
{
	App = new Application();

	if (App->Init()) {
		if (App->Start()) {
			while (App->DoUpdate()) {}
			App->Finish();
		}
	}

	delete App;

	return 0;
}

#endif