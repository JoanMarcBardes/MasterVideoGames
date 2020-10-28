#pragma once
#include <vector>

using namespace std;

class Animation
{
public:
	float speed;
	vector<SDL_Rect> frames;
	bool finish;

private:
	float current_frame;

public:
	Animation() : frames(), speed(1.0f), current_frame(0.0f), finish(false)
	{}

	SDL_Rect& GetCurrentFrame(int blockFrame = -1)
	{
		current_frame += speed;
		if (current_frame >= frames.size()) {
			current_frame = 0.0f;
			finish = true;
		}
		else if (blockFrame != -1 && current_frame >= blockFrame)
			current_frame = blockFrame;
		else {
			finish = false;
		}

		return frames[(int)current_frame];
	}
};