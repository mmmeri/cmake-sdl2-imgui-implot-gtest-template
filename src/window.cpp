#include "window.h"

namespace App
{

	Window::Window(const Settings& settings)
	{
		constexpr auto window_flags{
			static_cast<SDL_WindowFlags>(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI)};
		constexpr int window_center_flag{SDL_WINDOWPOS_CENTERED};

		window = SDL_CreateWindow(settings.title.c_str(), window_center_flag, window_center_flag,
			settings.width, settings.height, window_flags);

		constexpr auto renderer_flags{
			static_cast<SDL_RendererFlags>(SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED)};
		renderer = SDL_CreateRenderer(window, -1, renderer_flags);

		if (renderer == nullptr)
		{
			printf("Could not create renderer: %s\n", SDL_GetError());
			return;
		}
	}

	Window::~Window()
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
	}

	SDL_Window* Window::get_window() const
	{
		return window;
	}

	SDL_Renderer* Window::get_renderer() const
	{
		return renderer;
	}

}	 // namespace App