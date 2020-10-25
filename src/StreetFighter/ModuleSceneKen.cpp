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

// Reference at https://youtu.be/OEhmUuehGOA?t=72

ModuleSceneKen::ModuleSceneKen(bool start_enabled) : Module(start_enabled)
{
	_increase = -1;
	_up = true;

	// ground
	ground.x = 8;
	ground.y = 391;
	ground.w = 896;
	ground.h = 72;

	// TODO 2 : setup the foreground (red ship) with
	// coordinates x,y,w,h from ken_stage.png
	foreground.x = 8;
	foreground.y = 24;
	foreground.w = 522;
	foreground.h = 182;

	// Background / sky
	background.x = 72;
	background.y = 208;
	background.w = 768;
	background.h = 176;

	// flag animation
	flag.frames.push_back({848, 208, 40, 40});
	flag.frames.push_back({848, 256, 40, 40});
	flag.frames.push_back({848, 304, 40, 40});
	flag.speed = 0.08f;
	
	// TODO 4: Setup Girl Animation from coordinates from ken_stage.png
	// girl animation
	girl.frames.push_back({ 624, 16, 32, 56 });
	girl.frames.push_back({ 624, 80, 32, 56 });
	girl.frames.push_back({ 624, 144, 32, 56 });
	girl.speed = 0.05f;

	// greenGuy animation
	greenGuy.frames.push_back({ 664, 16, 32, 56 });
	greenGuy.frames.push_back({ 664, 80, 32, 56 });
	greenGuy.speed = 0.05f;

	// blueGuy animation
	blueGuy.frames.push_back({ 705, 16, 47, 56 });
	blueGuy.frames.push_back({ 705, 80, 47, 56 });
	blueGuy.frames.push_back({ 705, 144, 47, 56 });
	blueGuy.speed = 0.05f;

	// brownGuy animation
	brownGuy.frames.push_back({ 760, 16, 40, 40 });
	brownGuy.frames.push_back({ 760, 64, 40, 40 });
	brownGuy.frames.push_back({ 760, 112, 40, 40 });
	brownGuy.speed = 0.05f;

	// pinkGuy animation
	pinkGuy.frames.push_back({ 808, 24, 48, 32 });
	pinkGuy.frames.push_back({ 808, 72, 48, 32 });
	pinkGuy.frames.push_back({ 808, 120, 48, 32 });
	pinkGuy.speed = 0.05f;

	// greyGuy animation
	greyGuy.frames.push_back({ 552, 8, 64, 64 });
	greyGuy.frames.push_back({ 552, 72, 64, 64 });
	greyGuy.frames.push_back({ 552, 136, 64, 64 });
	greyGuy.speed = 0.05f;
}

ModuleSceneKen::~ModuleSceneKen()
{}

// Load assets
bool ModuleSceneKen::Start()
{
	LOG("Loading ken scene");
	
	graphics = App->textures->Load("ken_stage.png");

	// TODO 7: Enable the player module
	App->player->Enable();

	// TODO 0: trigger background music
	App->audio->PlayMusic("ken.ogg");
	
	return true;
}

// UnLoad assets
bool ModuleSceneKen::CleanUp()
{
	LOG("Unloading ken scene");

	App->textures->Unload(graphics);
	App->player->Disable();
	
	return true;
}

// Update: draw background
update_status ModuleSceneKen::Update()
{
	// TODO 5: make sure the ship goes up and down
	int yOffset = Offset();
	
	// Draw everything --------------------------------------
	// TODO 1: Tweak the parallax movement speed of the sea&sky + flag to your taste
	float speed = 1.1f;
	App->renderer->Blit(graphics, 0, 0, &background, speed); // sea and sky
	App->renderer->Blit(graphics, 560, 8, &(flag.GetCurrentFrame()), speed); // flag animation

	// TODO 3: Draw the ship. Be sure to tweak the speed.
	App->renderer->Blit(graphics, 0, -yOffset, &foreground, speed); // foreground

	// TODO 6: Draw the girl. Make sure it follows the ship movement!
	App->renderer->Blit(graphics, 192, 104 - yOffset, &(girl.GetCurrentFrame()), speed); // girl animation
	App->renderer->Blit(graphics, 224, 104 - yOffset, &(greenGuy.GetCurrentFrame()), speed); // greenGuy animation
	App->renderer->Blit(graphics, 288, 96 - yOffset, &(blueGuy.GetCurrentFrame()), speed); // blueGuy animation
	App->renderer->Blit(graphics, 87, 24 - yOffset, &(brownGuy.GetCurrentFrame()), speed); // brownGuy animation
	App->renderer->Blit(graphics, 130, 24 - yOffset, &(pinkGuy.GetCurrentFrame()), speed); // pinkGuy animation
	App->renderer->Blit(graphics, 128, 96 - yOffset, &(greyGuy.GetCurrentFrame()), speed); // greyGuy animation

	App->renderer->Blit(graphics, 0, 170, &ground);

	// TODO 10: Build an entire new scene "honda", you can find its
	// and music in the Game/ folder

	// TODO 11: Make that pressing space triggers a switch to honda logic module
	// using FadeToBlack module
	const Uint8* keys = SDL_GetKeyboardState(NULL);
	if (keys[SDL_SCANCODE_SPACE])
	{
		App->fade->FadeToBlack(App->scene_honda, App->scene_ken, 1.0f);
	}

	return UPDATE_CONTINUE;
}

int ModuleSceneKen::Offset()
{
	if (_up)
	{
		++_increase;
		if (_increase == 100) _up = false;
	}
	else
	{
		--_increase;
		if (_increase == 0) _up = true;
	}

	return _increase / 20;
}