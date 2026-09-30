#include "app.h"

#ifdef WIN32
int WinMain()
#else
int main()
#endif
{
	App::Application app{};
	return app.run();
}
