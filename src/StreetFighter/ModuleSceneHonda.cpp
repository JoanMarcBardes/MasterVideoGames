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
	background.x = 127;
	background.y = 128;
	background.w = 671;
	background.h = 199;

	//Foreground
	foreground.x = 164;
	foreground.y = 66;
	foreground.w = 336;
	foreground.h = 51;

	//Roof
	roof.x = 91;
	roof.y = 8;
	roof.w = 765;
	roof.h = 48;

	// water animation
	water.frames.push_back({ 8, 448, 283, 8 });
	water.frames.push_back({ 297, 448, 283, 12 });
	water.frames.push_back({ 589, 448, 283, 19 }); //224 64
	water.speed = 0.05f;

	// picture animation
	picture.frames.push_back({ 224, 64, 224, 104 });
	picture.frames.push_back({ 456, 64, 224, 104 });
	picture.speed = 0.05f;

	// guy animation
	guy.frames.push_back({ 0, 0, 0, 0 });
	guy.frames.push_back({ 760, 64, 96, 104 });
	guy.frames.push_back({ 664, 64, 96, 104 });
	guy.frames.push_back({ 760, 64, 96, 104 });
	guy.speed = 0.05f;
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
	float speedGroundBath = 1.2f;
	float speedRoofbackground = 1.0f;
	App->renderer->Blit(graphics, -82, 160, &ground, speedGroundBath); //ground
	App->renderer->Blit(graphics2, 0, -15, &background, speedRoofbackground); // background
	App->renderer->Blit(graphics, -57, -15, &roof, speedRoofbackground); // roof
	App->renderer->Blit(graphics, 185, 41, &(picture.GetCurrentFrame()), speedRoofbackground); // picture animation
	App->renderer->Blit(graphics2, 409, 41, &(guy.GetCurrentFrame()), speedRoofbackground); // guy animation
	App->renderer->Blit(graphics2, 250, 125, &foreground, speedGroundBath); // bath 
	App->renderer->Blit(graphics, 276, 141, &(water.GetCurrentFrame()), speedGroundBath); // water animation

	const Uint8* keys = SDL_GetKeyboardState(NULL);
	if (keys[SDL_SCANCODE_SPACE]) App->fade->FadeToBlack(App->scene_ken, App->scene_honda, 1.0f);

	return UPDATE_CONTINUE;
}