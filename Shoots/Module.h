#ifndef __MODULE_H__
#define __MODULE_H__

#include "Globals.h"
class Module
{
public:
	virtual ~Module() {}
	virtual bool Init() { return true; }
	virtual update_status PreUpdate() { return UPDATE_CONTINUE; }
	virtual update_status Update() { return UPDATE_CONTINUE; }
	virtual update_status PostUpdate() { return UPDATE_CONTINUE; }
	virtual bool CleanUp() { return true; }
};

#endif // __MODULE_H__