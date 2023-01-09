#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Events.h"

// Handle character input

struct PassingCallbacks PassEvents, PassEvents_Server;

void char_callback(GLFWwindow *window, unsigned int UTF_code)
{
    // Output the Unicode code point of the character
    std::cout << "Character with UTF-8 code '" << UTF_code << "' was input" << std::endl;
    PassEvents.button_UTF = UTF_code;
    PassEvents.isPressed = true;
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    switch (key)
    {
    case GLFW_KEY_LEFT_SHIFT:
    case GLFW_KEY_RIGHT_SHIFT:
        switch (action)
        {
        case GLFW_PRESS:
            std::cout << "Shift key was pressed" << std::endl;
            break;
        case GLFW_RELEASE:
            std::cout << "Shift key was released" << std::endl;
            break;
        }
        break;
    case GLFW_KEY_CAPS_LOCK:
        switch (action)
        {
        case GLFW_PRESS:
            std::cout << "Caps lock key was pressed" << std::endl;
            break;
        case GLFW_RELEASE:
            std::cout << "Caps lock key was released" << std::endl;
            break;
        }
        break;
    case GLFW_KEY_LEFT_CONTROL:
    case GLFW_KEY_RIGHT_CONTROL:
        switch (action)
        {
        case GLFW_PRESS:
            std::cout << "Control key was pressed" << std::endl;
            break;
        case GLFW_RELEASE:
            std::cout << "Control key was released" << std::endl;
            break;
        }
        break;
    case GLFW_KEY_ENTER:
        switch (action)
        {
        case GLFW_PRESS:
            std::cout << "Enter lock key was pressed" << std::endl;
            break;
        case GLFW_RELEASE:
            std::cout << "Enter lock key was released" << std::endl;
            break;
        }
        break;
    case GLFW_KEY_ESCAPE:
        switch (action)
        {
        case GLFW_PRESS:
            std::cout << "Esc lock key was pressed" << std::endl;
            break;
        case GLFW_RELEASE:
            std::cout << "Esc lock key was released" << std::endl;
            break;
        }
        break;
        /* default:
            switch (action)
            {
                case GLFW_PRESS:
                    std::cout << "Other key was pressed" << std::endl;
                    break;
                case GLFW_RELEASE:
                    std::cout << "Other key was released" << std::endl;
                    break;
            }
            break;
            */
    }
}

void mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
{ // left mouse button = 0, right = 1, wheel_click = 2, side button right = 3, side left = 4
    if (action == GLFW_PRESS and GLFW_PRESS)
    {
        std::cout << "Mouse button " << button << " pressed" << std::endl;
        PassEvents.mouse_button_id = button;
    }
    else if (action == GLFW_RELEASE)
    {
        std::cout << "Mouse button " << button << " released" << std::endl;
        PassEvents.mouse_button_id = -1;
    }
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
    if (yoffset > 0)
    {
        std::cout << "Mouse wheel moved up" << std::endl;
    }
    else if (yoffset < 0)
    {
        std::cout << "Mouse wheel moved down" << std::endl;
    }
}

void pointer_position(GLFWwindow *window, double& xpos, double& ypos){

        glfwGetCursorPos(window, &xpos, &ypos);

        std::cout << "Mouse cursor at (" << xpos << ", " << ypos << ")" << std::endl;

        glClearColor(0, 0, 0, 1);

}