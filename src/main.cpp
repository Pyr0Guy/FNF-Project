#include "include/Game.hpp"

#include <chrono>

int main()
{
	Game FNF(800, 600, "FNF-FanGame");

	constexpr std::chrono::nanoseconds framerate(16666667);
	using clock = std::chrono::high_resolution_clock;

	auto start = clock::now();
	std::chrono::nanoseconds lag(0);

	while (!FNF.GameShouldClose())
	{
		auto end = clock::now();
		std::chrono::nanoseconds elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

		start = end;
		lag += elapsed;

		while (lag >= framerate)
		{
			FNF.Update();
			lag -= framerate;
		}

		FNF.Render();
	}

	FNF.CleanUp();
}