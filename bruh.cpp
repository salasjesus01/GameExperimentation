#include "raylib.h"
const int WIDTH = 600;
const int HEIGHT = 400;
const double GRAV = 9.1;



int mX, mY, mSpeedX, mSpeedY;
Rectangle floor()
{
	return DrawRectangle(0, HEIGHT - 10, WIDTH, 5, BLACK);
}
int main()
{
	InitWindow(WIDTH, HEIGHT, "MyGame");
	SetTargetFPS(60);





	mX = WIDTH / 2 + 5;
	mY = HEIGHT / 2 + 5;
	mSpeedY = GRAV * 10;
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);
		
		//gravity
		
		mY += mSpeedY * GetFrameTime();

		DrawCircleLines(mX, mY,10, BLACK);
		DrawRectangle(0, HEIGHT - 10, WIDTH, 5, BLACK);
		
		//coll
		if (CheckCollisionCircleRec(Vector2{mX ,mY}, 10, floor))
		{
			mSpeedY = 0;
		}



		DrawFPS(5, 5);
		EndDrawing();
	}
	CloseWindow();
}