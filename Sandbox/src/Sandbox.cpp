#include <Storm.h>


class ExampleLayer : public storm::Layer
{
public:
	ExampleLayer(const char* name)
		: storm::Layer(name)
	{}

	virtual void onAttach() override {}
	virtual void onDetach() override {}

	virtual void update() override {}
	virtual void onEvent(const storm::Event& e) override {}
};

class Sandbox : public storm::Application
{
public:
	Sandbox()
	{
		pushLayer(new ExampleLayer("ExampleLayer"));
	}
};

storm::Application* storm::createApplication()
{
	return new Sandbox;
}
