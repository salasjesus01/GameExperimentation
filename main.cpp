#include "raylib.h"
const int WIDTH = 1080;
const int HEIGHT = 720;
const int MAX_FRAME_SPEED = 15;
const int MIN_FRAME_SPEED = 1;

int main()
{
	InitWindow(WIDTH, HEIGHT, "Window");


	Texture2D facGround = LoadTexture("Sprites/Factory.png");
	Texture2D megaTex = LoadTexture("Sprites/mega.png");

	int megaWidth = megaTex.width;
	int megaHeight = megaTex.height;

	int groundWidth = facGround.width;
	int groundHeight = facGround.height;

	Rectangle frameRec = { 0.0f, 0.0f, (float)megaWidth / 5, (float)megaHeight / 6 };
	Vector2 groundPosition = { WIDTH / 2.0f - megaWidth/5 / 2, HEIGHT / 2.0f - megaHeight/6 / 2 };

	int megaFrame = 0;
	float accel = 0.0;
	int framesCounter = 0;
	int framesSpeed = 8;
	SetTargetFPS(60);

	int rotation = 0;
	while (!WindowShouldClose())
	{
		framesCounter++;
		
		if (framesCounter >= (60 / framesSpeed)) {
			framesCounter = 0;
			megaFrame++;

			if (megaFrame > 3) megaFrame = 0;

			frameRec.x = (float)megaFrame * (float)megaWidth / 5;
			frameRec.y = (float)megaHeight / 6 ;
		}

		groundPosition.x += accel;


		if (IsKeyPressed(KEY_RIGHT)) framesSpeed++;
		else if (IsKeyPressed(KEY_LEFT)) framesSpeed--;





		BeginDrawing();

			ClearBackground(RAYWHITE);

			DrawTextureRec(megaTex, {0.0f, (float)megaHeight / 6,(float)megaWidth,(float)megaHeight/6}, {WIDTH/2.0f - (megaWidth/2), 40}, RAYWHITE);
			DrawRectangleLines(WIDTH / 2.0f - (megaWidth / 2), 40, megaWidth, (float)megaHeight / 6, LIME);
			DrawRectangleLines(WIDTH/2.0f - (megaWidth/2) + (int)frameRec.x, 40, frameRec.width, frameRec.height, RED);




			DrawTextureRec(megaTex, frameRec, groundPosition, WHITE);

			DrawFPS(5, 5);
		EndDrawing();
	}
	UnloadTexture(megaTex);
	UnloadTexture(facGround);
	CloseWindow();

	
}