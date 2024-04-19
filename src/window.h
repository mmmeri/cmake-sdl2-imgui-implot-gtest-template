#pragma once

#include <SDL.h>

#include <string>

namespace App
{
	class Window
	{
	public:
		struct Settings
		{
			std::string title;
			int width{1280};
			int height{1280};
		};

		explicit Window(const Settings& settings);
		~Window();

		// no copy or move
		Window(const Window& Other) = delete;
		Window& operator=(const Window& Other) = delete;
		Window(Window&& Other) = delete;
		Window& operator=(Window&& Other) = delete;

		[[nodiscard]] SDL_Window* get_window() const;
		[[nodiscard]] SDL_Renderer* get_renderer() const;

	private:
		SDL_Window* window{nullptr};
		SDL_Renderer* renderer{nullptr};
	};

}	 // namespace App