#pragma once

#include "Hazel/Input.h"

namespace Hazel {

class WindowsInput : public Input {
  protected:
    // Inherited via Input
    virtual bool IsKeyPressedImpl(int keycode) override;

    virtual bool IsMouseButtonPressedImpl(int button) override;

    virtual MOUSE_POS GetMousePositionImpl() override;

    virtual float GetMouseXImpl() override;

    virtual float GetMouseYImpl() override;
};

} // namespace Hazel
