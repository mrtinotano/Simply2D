#pragma once
#include <vector>
#include "Module.h"

class Application
{
public:
	Application();
	~Application();

	bool Init();
	bool Start();
	bool DoUpdate();
	bool Finish();

private:
	bool PreUpdate();
	bool Update();
	bool PostUpdate();

private:
	std::vector<Module*> appModules;
	bool finishApp;
};

extern Application* App;