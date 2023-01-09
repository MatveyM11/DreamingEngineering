#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Events.h"

const int WIDTH = 1280;
const int HEIGHT = 720;

int Window_Game()
{

    glfwInit(); // GLFW Initialization

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);                 // stands for 4.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);                 // stands for 0.6
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // CORE_PROFILE uses only new OpenGL features, and GLFW_OPENGL_COMPAT_PROFILE uses both new and Old
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);                      // literally means you cannot or can resize yours window

    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "DreamingEngineering", nullptr, nullptr); // initialising window parameters

    if (window == nullptr)
    { // Checks if window created properly properly, else returns error and closes program
        std::cerr << "Failed to create GLFW Window" << std::endl;
        return -1;
    }

    glfwMakeContextCurrent(window); // Specifying for OpenGL a current window in current flow to work with. Important in case if we would have multiple windows to render.

    glewExperimental = GL_TRUE; // turning on experimental features
    if (glewInit() != GLEW_OK)
    {                                                          // Checks if GLEW loaded properly, else returns error and closes program
        std::cerr << "Failed to initialize GLEW" << std::endl; // std::cerr in compare to std::cout wont't be logged and used for errors. std::clog - for logs, also buffered.
        return -1;
    }

    bool ShiftPressed = false;
    bool CapsPressed = false;

    glViewport(0, 0, WIDTH, HEIGHT); // tells OpenGL which part of the window to render, and from which corner, (0,0) - top-left
    while (!glfwWindowShouldClose(window))
    {

        glfwPollEvents(); // Listening for every user's action, window resize, keyboard or mouse input, etc.

        // Set the character callback function
        glfwSetCharCallback(window, char_callback);
        if (PassEvents.isPressed == true)
        {
            std::cout << "Globals - " << PassEvents.button_UTF << std::endl;
            PassEvents.isPressed = false;
        }

        glfwSetKeyCallback(window, key_callback);
        glfwSetMouseButtonCallback(window, mouse_button_callback);
        glfwSetScrollCallback(window, scroll_callback);

        pointer_position(window, PassEvents.delta_x, PassEvents.delta_y);

        switch (PassEvents.mouse_button_id)
        {
        case 0:
            std::cout << PassEvents.mouse_button_id << "Mouse id" << std::endl;
            glClearColor(0, 0, 1, 1);
            break;

        case 1:
            std::cout << PassEvents.mouse_button_id << "Mouse id" << std::endl;
            glClearColor(1, 0, 0, 1);
            break;
        }

        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window); // One frame calculated in background, other being displayed on the screen. After displaying is finished, they're being swapped.
        // Which prevents image flickering and tearing in the most of the cases, in compare to X11, which by default has no buffer(HATE IT)
    }

    glfwTerminate(); // Entirely destroys window to correctly and entirely free memory from the laucnhed program
    return 0;
}