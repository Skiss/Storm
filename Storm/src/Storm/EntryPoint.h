#pragma once


#ifdef STORM_PLATFORM_WINDOWS
int main(int argc, char** argv)
{
	storm::Log::init();

	storm::Application* app = storm::createApplication();
	app->run();

	delete app;

	return 0;
}
#else
#error "Only Windows is supported for now."
#endif // STORM_PLATFORM_WINDOWS
