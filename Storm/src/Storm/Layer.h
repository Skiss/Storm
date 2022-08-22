#pragma once

#include "Core.h"
#include "Events/Event.h"


namespace storm
{

class STORM_API Layer
{
public:
	Layer(const char* debugName);
	virtual ~Layer() = default;

	virtual void onAttach() = 0;
	virtual void onDetach() = 0;

	virtual void update() = 0;
	virtual void onEvent(const Event& e) = 0;

#ifdef STORM_DEBUG
	const char* getDebugName() const { return m_debugName; }
#endif

protected:
#ifdef STORM_DEBUG
	const char* m_debugName = nullptr;
#endif
};

}
