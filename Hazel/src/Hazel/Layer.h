#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Hazel {
class Layer {
  public:
    Layer(const std::string& debugname = "Layer");
    virtual ~Layer();

    virtual void OnAttach() {}
    virtual void OnDetatch() {}
    virtual void OnUpdate() {}
    virtual void OnImGuiRender() {}
    virtual void OnEvent(Event& event) {}

    inline const std::string& GetName() const { return m_DebugName; }

  protected:
    std::string m_DebugName;
};
} // namespace Hazel
