#pragma once

#include <memory>

namespace App
{
	class Application
	{
	public:
		Application();
		~Application();

		// No copy or move
		Application(const Application&) = delete;
		Application& operator=(const Application&) = delete;
		Application(Application&&) = delete;
		Application& operator=(Application&&) = delete;

		int run();
		void stop();

	private:
		int error{0};
		bool running{true};

		std::unique_ptr<class Window> window{nullptr};
	};

}	 // namespace App