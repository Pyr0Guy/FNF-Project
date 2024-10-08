#include <raylib.h>

int main()
{
	InitWindow(800, 600, "LOL");

	while(!WindowShouldClose())
	{
		BeginDrawing();
			ClearBackground(MAGENTA);
		EndDrawing();
	}

	CloseWindow();
	
}
