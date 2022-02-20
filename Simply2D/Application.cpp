#include "Application.h"

Application::Application()
{
    finishApp = false;
}

Application::~Application()
{
}

bool Application::Init()
{
    return true;
}

bool Application::Start()
{
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

bool Application::CleanUp()
{
    return true;
}

bool Application::PreUpdate()
{
    return true;
}

bool Application::Update()
{
    return true;
}

bool Application::PostUpdate()
{
    return true;
}
