#pragma once

#include "Layer.h"

#include <vector>


namespace storm
{

class LayerStack
{
public:
	using LayerVec = std::vector<Layer*>;
	using LayerVecIt = std::vector<Layer*>::iterator;
	using LayerVecConstIt = std::vector<Layer*>::const_iterator;

	LayerStack();
	~LayerStack();

	void pushLayer(Layer* layer);
	void popLayer(Layer* layer);

	void pushOverlay(Layer* overlay);
	void popOverlay(Layer* overlay);

	LayerVecIt begin() { return m_layers.begin(); }
	LayerVecIt end() { return m_layers.end(); }

	LayerVecConstIt begin() const { return m_layers.cbegin(); }
	LayerVecConstIt end() const { return m_layers.cend(); }

private:
	LayerVec m_layers;
	LayerVecIt m_layersEndIt;
};

}
