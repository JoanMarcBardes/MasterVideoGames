#include "Globals.h"
#include "Application.h"
#include "ModuleSceneKen.h"
#include "ModuleSceneHonda.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "SDL/include/SDL.h"

ModuleSceneHonda::ModuleSceneHonda(bool start_enabled) : Module(start_enabled)
{
	// ground
	ground.x = 8;
	ground.y = 376;
	ground.w = 850;
	ground.h = 65;

	// Background
	background.x = 121;
	background.y = 129;
	background.w = 671;
	background.h = 198;

	//Foreground
	foreground.x = 164;
	foreground.y = 66;
	foreground.w = 336;
	foreground.h = 51;

	//Roof
	roof.x = 91;
	roof.y = 7;
	roof.w = 765;
	roof.h = 49;

	// water animation
	water.frames.push_back({ 8, 448, 283, 8 });
	water.frames.push_back({ 297, 448, 283, 12 });
	water.frames.push_back({ 589, 448, 283, 19 });
	water.speed = 0.05f;
}

ModuleSceneHonda::~ModuleSceneHonda()
{}

// Load assets
bool ModuleSceneHonda::Start()
{
	LOG("Loading ken scene");

	graphics = App->textures->Load("honda_stage.png");
	graphics2 = App->textures->Load("honda_stage2.png");

	App->player->Enable();

	App->audio->PlayMusic("honda.ogg");

	return true;
}

// UnLoad assets
bool ModuleSceneHonda::CleanUp()
{
	LOG("Unloading ken scene");

	App->textures->Unload(graphics);
	App->textures->Unload(graphics2);
	App->player->Disable();

	return true;
}

// Update: draw background
update_status ModuleSceneHonda::Update()
{
	float speedGroundBath = 1.4f;
	float speedRoofbackground = 1.0f;
	App->renderer->Blit(graphics, 0, 160, &ground, speedGroundBath);
	App->renderer->Blit(graphics2, 50, -15, &background, speedRoofbackground); // background
	App->renderer->Blit(graphics, 0, -15, &roof, speedRoofbackground); // roof
	App->renderer->Blit(graphics2, 300, 125, &foreground, speedGroundBath); // bath 
	App->renderer->Blit(graphics, 300, 141, &(water.GetCurrentFrame()), speedGroundBath); // water animation

	const Uint8* keys = SDL_GetKeyboardState(NULL);
	if (keys[SDL_SCANCODE_SPACE]) App->fade->FadeToBlack(App->scene_ken, App->scene_honda, 1.0f);

	return UPDATE_CONTINUE;
}