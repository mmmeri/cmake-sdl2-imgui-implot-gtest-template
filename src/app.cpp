#include "app.h"

#include "implot.h"
#include "window.h"

#include <backends/imgui_impl_sdl2.h>
#include <backends/imgui_impl_sdlrenderer2.h>
#include <imgui.h>

#include <algorithm>
#include <iostream>

template <typename T>
inline T RandomRange(T min, T max)
{
	T scale = rand() / (T) RAND_MAX;
	return min + scale * (max - min);
}

float smoothstep(float edge0, float edge1, float x)
{
	// Scale, bias and saturate x to 0..1 range
	x = std::clamp((x - edge0) / (edge1 - edge0), 0.0f, 1.0f);
	// Evaluate polynomial
	return x * x * (3 - 2 * x);
}

namespace App
{
Application::Application()
{
	constexpr unsigned int init_flags{SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER};
	if (SDL_Init(init_flags) != 0)
	{
		printf("Error: %s\n", SDL_GetError());
		error = 1;
	}

	window = std::make_unique<Window>(Window::Settings{"App"});

	for (size_t i = 0; i < seed.size(); i++)
	{
		seed[i] = std::rand() / static_cast<float>(RAND_MAX);
	}
}

Application::~Application()
{
	ImGui_ImplSDLRenderer2_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImPlot::DestroyContext();
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
	ImPlot::CreateContext();
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

		// Get current time

		ImPlot::PushColormap(ImPlotColormap_Hot);
		ImGui::SameLine();

		if (ImPlot::BeginPlot("##Heatmap2", ImVec2(2000, 1000), ImPlotFlags_NoLegend))
		{
			ImPlot::SetupAxes(nullptr, nullptr);
			ImPlot::PlotHeatmap("heat1", seed.data(), n_x, n_y);
			ImPlot::EndPlot();
		}

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