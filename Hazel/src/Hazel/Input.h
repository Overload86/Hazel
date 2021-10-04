#pragma once

#include "Hazel/Core.h"

#define MOUSE_POS std::pair<float, float>

namespace Hazel {

class Input {
  public:
    inline static bool IsKeyPressed(int keycode) {
        return s_Instance->IsKeyPressedImpl(keycode);
    }
    inline static bool IsMouseButtonPressed(int button) {
        return s_Instance->IsMouseButtonPressedImpl(button);
    }
    inline static MOUSE_POS GetMousePosition() {
        return s_Instance->GetMousePositionImpl();
    }
    inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
    inline static float GetMouseY() { return s_Instance->GetMouseYImpl(); }

  protected:
    virtual bool      IsKeyPressedImpl(int keycode)        = 0;
    virtual bool      IsMouseButtonPressedImpl(int button) = 0;
    virtual MOUSE_POS GetMousePositionImpl()               = 0;
    virtual float     GetMouseXImpl()                      = 0;
    virtual float     GetMouseYImpl()                      = 0;

  private:
    static Input* s_Instance;
};

} // namespace Hazel
