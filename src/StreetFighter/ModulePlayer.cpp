#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "SDL/include/SDL.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA
ModulePlayer::ModulePlayer(bool start_enabled) : Module(start_enabled)
{
	position.x = 100;
	position.y = 216;

	// idle animation (arcade sprite sheet)
	idle.frames.push_back({7, 14, 60, 90});
	idle.frames.push_back({95, 15, 60, 89});
	idle.frames.push_back({184, 14, 60, 90});
	idle.frames.push_back({276, 11, 60, 93});
	idle.frames.push_back({366, 12, 60, 92});
	idle.speed = 0.2f;
	
	// walk backward animation (arcade sprite sheet)
	backward.frames.push_back({542, 131, 61, 87});
	backward.frames.push_back({628, 129, 59, 90});
	backward.frames.push_back({713, 128, 57, 90});
	backward.frames.push_back({797, 127, 57, 90});
	backward.frames.push_back({883, 128, 58, 91});
	backward.frames.push_back({974, 129, 57, 89});
	backward.speed = 0.1f;

	// TODO 8: setup the walk forward animation from ryu4.png
	forward.frames.push_back({   9, 136, 52, 94 });
	forward.frames.push_back({  78, 130, 61, 90 });
	forward.frames.push_back({ 161, 130, 66, 93 });
	forward.frames.push_back({ 258, 130, 65, 92 });
	forward.frames.push_back({ 352, 130, 54, 94 });
	forward.frames.push_back({ 432, 130, 50, 92 });
	forward.speed = 0.1f;
}

ModulePlayer::~ModulePlayer()
{
	// Homework : check for memory leaks
}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	graphics = App->textures->Load("ryu4.png"); // arcade version

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);

	return true;
}

// Update
update_status ModulePlayer::Update()
{
	// TODO 9: Draw the player with its animation
	// make sure to detect player movement and change its
	// position while cycling the animation(check Animation.h)

	const Uint8* keys = SDL_GetKeyboardState(NULL);

	if (keys[SDL_SCANCODE_D])
	{
		++_xOffset;
		App->renderer->Blit(graphics, 80 + _xOffset, 125, &(forward.GetCurrentFrame()), 1.0f); // forward animation
	}
	else if (keys[SDL_SCANCODE_A])
	{
		--_xOffset;
		App->renderer->Blit(graphics, 80 + _xOffset, 125, &(backward.GetCurrentFrame()), 1.0f); // backward animation
	}
	else
	{
		App->renderer->Blit(graphics, 80 + _xOffset, 125, &(idle.GetCurrentFrame()), 1.0f); // idle animation
	}

	return UPDATE_CONTINUE;
}