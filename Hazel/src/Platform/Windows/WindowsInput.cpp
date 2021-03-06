#include "hzpch.h"

#include "WindowsInput.h"

#include "Hazel/Application.h"
#include <GLFW/glfw3.h>

namespace Hazel {

Input* Input::s_Instance = new WindowsInput();

bool WindowsInput::IsKeyPressedImpl(int keycode) {
    auto window = static_cast<GLFWwindow*>(
        Application::Get().GetWindow().GetNativeWindow());

    auto state = glfwGetKey(window, keycode);
    return state == GLFW_PRESS || state == GLFW_REPEAT;
}

bool WindowsInput::IsMouseButtonPressedImpl(int button) {
    auto window = static_cast<GLFWwindow*>(
        Application::Get().GetWindow().GetNativeWindow());

    auto state = glfwGetMouseButton(window, button);
    return state == GLFW_PRESS;
}

MOUSE_POS WindowsInput::GetMousePositionImpl() {
    auto window = static_cast<GLFWwindow*>(
        Application::Get().GetWindow().GetNativeWindow());
    double xPos, yPos;
    glfwGetCursorPos(window, &xPos, &yPos);
    return {(float)xPos, (float)yPos};
}

float WindowsInput::GetMouseXImpl() { return GetMousePositionImpl().first; }

float WindowsInput::GetMouseYImpl() { return GetMousePositionImpl().second; }

} // namespace Hazel
