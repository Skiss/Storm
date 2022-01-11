#pragma once


#ifdef STORM_PLATFORM_WINDOWS

int main(int argc, char** argv)
{
	storm::Log::init();
	STORM_TRACE("TEST");

	storm::Application* app = storm::createApplication();
	app->run();
	delete app;

	return 0;
}

#endif // STORM_PLATFORM_WINDOWS

