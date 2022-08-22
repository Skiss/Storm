#include <Pch.h>

#include "LayerStack.h"


namespace storm
{

LayerStack::LayerStack()
{
	m_layersEndIt = m_layers.begin();
}

LayerStack::~LayerStack()
{
	for (Layer* l : m_layers)
		delete l;
}

void LayerStack::pushLayer(Layer* layer)
{
	m_layersEndIt = m_layers.emplace(m_layersEndIt, layer);
}

void LayerStack::popLayer(Layer* layer)
{
	const auto& it = std::find(m_layers.begin(), m_layers.end(), layer);
	if (it != m_layers.end())
	{
		m_layers.erase(it);
		--m_layersEndIt;
	}
}

void LayerStack::pushOverlay(Layer* overlay)
{
	m_layers.emplace_back(overlay);
}

void LayerStack::popOverlay(Layer* overlay)
{
	const auto& it = std::find(m_layers.begin(), m_layers.end(), overlay);
	if (it != m_layers.end())
		m_layers.erase(it);
}

}
