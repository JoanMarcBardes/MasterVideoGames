#ifndef __MODULEPLAYER_H__
#define __MODULEPLAYER_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "Point.h"

struct SDL_Texture;

class ModulePlayer : public Module
{
public:
	ModulePlayer(bool start_enabled = true);
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	Animation idle;
	Animation backward;
	Animation forward;
	Animation jump;
	Animation down;
	iPoint position;


private:
	int _xOffset = 0;
	Animation currentAnimation;

	enum type_animation
	{
		NON_BLOCKING,
		JUMP,
		DOWN
	};
	type_animation typeAnimation = NON_BLOCKING;
};

#endif // __MODULEPLAYER_H__