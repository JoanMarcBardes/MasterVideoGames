#ifndef __MODULESCENEKEN_H__
#define __MODULESCENEKEN_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleSceneKen : public Module
{
public:
	ModuleSceneKen( bool start_enabled = true);
	~ModuleSceneKen();

	bool Start();
	update_status Update();
	bool CleanUp();
	int Offset();

public:
	
	SDL_Texture* graphics = nullptr;
	SDL_Rect ground;
	SDL_Rect background;
	SDL_Rect foreground;
	Animation flag;
	Animation girl;
	Animation greenGuy;
	Animation blueGuy;
	Animation brownGuy;
	Animation pinkGuy;
	Animation greyGuy;


private:
	int _increase;
	bool _up;
};

#endif // __MODULESCENEKEN_H__