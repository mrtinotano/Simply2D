#pragma once

class Module
{
public:

	Module() :  moduleName("") {}

	Module(const char* moduleName, bool gameModule = false) : moduleName(moduleName)
	{
	}

	virtual ~Module() {}

	virtual bool Init()
	{
		return true;
	}

	virtual bool Start()
	{
		return true;
	}

	virtual bool PreUpdate(float deltaTime)
	{
		return true;
	}

	virtual bool Update(float deltaTime)
	{
		return true;
	}

	virtual bool PostUpdate(float deltaTime)
	{
		return true;
	}

	virtual bool Finish()
	{
		return true;
	}

	const char* GetModuleName() const
	{
		return moduleName;
	}

private:
	const char* moduleName;
};