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
	currentAnimation = idle;

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

	// jump animation
	jump.frames.push_back({  16, 797, 57, 137 });
	jump.frames.push_back({ 100, 797, 57, 137 });
	jump.frames.push_back({ 172, 797, 57, 137 });
	jump.frames.push_back({ 250, 797, 57, 137 });
	jump.frames.push_back({ 322, 797, 57, 137 });
	jump.frames.push_back({ 393, 797, 57, 137 });
	jump.frames.push_back({ 463, 797, 57, 137 });
	jump.speed = 0.1f;

	// down animation
	down.frames.push_back({  27, 1206, 63, 90 });
	down.frames.push_back({ 112, 1206, 63, 90 });
	down.frames.push_back({ 196, 1206, 63, 90 });
	down.frames.push_back({ 196, 1206, 63, 90 });
	down.frames.push_back({ 112, 1206, 63, 90 });
	down.frames.push_back({  27, 1206, 63, 90 });
	down.speed = 0.1f;
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
	
	if (keys[SDL_SCANCODE_D] && typeAnimation == NON_BLOCKING)
	{
		++_xOffset;
		App->renderer->Blit(graphics, 80 + _xOffset, 125, &(forward.GetCurrentFrame()), 1.0f); // forward animation
		typeAnimation = NON_BLOCKING;
	}
	else if (keys[SDL_SCANCODE_A] && typeAnimation == NON_BLOCKING)
	{
		--_xOffset;
		App->renderer->Blit(graphics, 80 + _xOffset, 125, &(backward.GetCurrentFrame()), 1.0f); // backward animation
		typeAnimation = NON_BLOCKING;
	}
	else if (keys[SDL_SCANCODE_W] && typeAnimation == NON_BLOCKING)
	{
		App->renderer->Blit(graphics, 80 + _xOffset, 80, &(jump.GetCurrentFrame()), 1.0f); // jump animation
		currentAnimation = jump;
		typeAnimation = JUMP;
	}
	else if (keys[SDL_SCANCODE_S] && typeAnimation == NON_BLOCKING)
	{
		App->renderer->Blit(graphics, 80 + _xOffset, 125, &(down.GetCurrentFrame()), 1.0f); // down animation
		currentAnimation = down;
		typeAnimation = DOWN;
	}
	else
	{
		switch (typeAnimation)
		{
		case ModulePlayer::NON_BLOCKING:
			App->renderer->Blit(graphics, 80 + _xOffset, 125, &(idle.GetCurrentFrame()), 1.0f);
			typeAnimation = NON_BLOCKING;
			break;
		case ModulePlayer::JUMP:
			App->renderer->Blit(graphics, 80 + _xOffset, 80, &(currentAnimation.GetCurrentFrame()), 1.0f);
			if (currentAnimation.finish)
				typeAnimation = NON_BLOCKING;
			break;
		case ModulePlayer::DOWN:
			int blockFrame = -1;
			if (keys[SDL_SCANCODE_S]) blockFrame = 3;
			App->renderer->Blit(graphics, 80 + _xOffset, 125, &(currentAnimation.GetCurrentFrame(blockFrame)), 1.0f);
			if (currentAnimation.finish)
				typeAnimation = NON_BLOCKING;
			break;
		}
	}

	return UPDATE_CONTINUE;
}