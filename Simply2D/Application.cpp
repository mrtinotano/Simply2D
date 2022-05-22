#include "Application.h"
#include "WindowModule.h"

Application::Application()
{
    finishApp = false;

    appModules.push_back(new WindowModule());
}

Application::~Application()
{
}

bool Application::Init()
{
    for (Module* appModule : appModules)
    {
        if (!appModule->Init())
            return false;
    }

    return true;
}

bool Application::Start()
{
    for (Module* appModule : appModules)
    {
        if (!appModule->Start())
            return false;
    }

    return true;
}

bool Application::DoUpdate()
{
    if (finishApp) return false;

    if (!PreUpdate()) return false;
    if (!Update()) return false;
    if (!PostUpdate()) return false;

    return true;
}

bool Application::PreUpdate()
{
    for (Module* appModule : appModules)
    {
        if (!appModule->PreUpdate(0))
            return false;
    }

    return true;
}

bool Application::Update()
{
    for (Module* appModule : appModules)
    {
        if (!appModule->Update(0))
            return false;
    }

    return true;
}

bool Application::PostUpdate()
{
    for (Module* appModule : appModules)
    {
        if (!appModule->PostUpdate(0))
            return false;
    }

    return true;
}

bool Application::Finish()
{
    for (Module* appModule : appModules)
    {
        if (!appModule->Finish())
            return false;
    }

    return true;
}
