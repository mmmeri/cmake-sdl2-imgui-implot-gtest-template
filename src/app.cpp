#include "app.h"

#include "window.h"

#include <backends/imgui_impl_sdl2.h>
#include <backends/imgui_impl_sdlrenderer2.h>
#include <imgui.h>

#include <iostream>

namespace App
{
	Application::Application()
	{
		constexpr unsigned int init_flags{
			SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER};
		if (SDL_Init(init_flags) != 0)
		{
			printf("Error: %s\n", SDL_GetError());
			error = 1;
		}

		window = std::make_unique<Window>(Window::Settings{"GOAI"});
	}

	Application::~Application()
	{
		ImGui_ImplSDLRenderer2_Shutdown();
		ImGui_ImplSDL2_Shutdown();
		ImGui::DestroyContext();
		SDL_Quit();
	}

	int Application::run()
	{
		if (error == 1)
		{
			return error;
		}

		// ImGui context
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io{ImGui::GetIO()};

		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

		ImGui_ImplSDL2_InitForSDLRenderer(window->get_window(), window->get_renderer());
		ImGui_ImplSDLRenderer2_Init(window->get_renderer());

		running = true;
		while (running)
		{
			// SDL event loop
			SDL_Event event{};
			while (SDL_PollEvent(&event) == 1)
			{
				ImGui_ImplSDL2_ProcessEvent(&event);
				if (event.type == SDL_QUIT)
				{
					stop();
				}
			}

			ImGui_ImplSDLRenderer2_NewFrame();
			ImGui_ImplSDL2_NewFrame();

			// Imgui
			ImGui::NewFrame();

			ImGui::DockSpaceOverViewport();

			ImGui::Begin("App");
			ImGui::Text("Hi");
			ImGui::End();

			ImGui::Render();

			// Render
			SDL_SetRenderDrawColor(window->get_renderer(), 100, 100, 100, 255);
			SDL_RenderClear(window->get_renderer());
			ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
			SDL_RenderPresent(window->get_renderer());
		}

		return error;
	}

	void Application::stop()
	{
		running = false;
	}

}	 // namespace App