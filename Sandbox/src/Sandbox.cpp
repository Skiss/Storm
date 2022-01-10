#include <Storm.h>


class Sandbox : public storm::Application
{

};

storm::Application* storm::createApplication()
{
	return new Sandbox;
}
