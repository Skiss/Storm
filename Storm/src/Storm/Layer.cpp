#include <Pch.h>

#include "Layer.h"


namespace storm
{

Layer::Layer(const char* debugName)
#ifdef STORM_DEBUG
	: m_debugName(debugName)
#endif
{
}

}
