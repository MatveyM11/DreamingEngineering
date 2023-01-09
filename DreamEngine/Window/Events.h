#ifndef EVENTS_H
#define EVENTS_H

/// @brief passing all data from callbacks to this global struct
// I have no fucking idea how to pass callbacks without global variables, without modifying GLFW source I cannot pass by reference or pointer anywhere in this case
extern struct PassingCallbacks
{
    int button_UTF;
    int special_keys;
    bool isPressed;
    double delta_x;
    double delta_y;
    int mouse_button_id = -1;
    bool cursor_locked;
    bool cursor_started;
} PassEvents, PassEvents_Server;

void char_callback(GLFWwindow *window, unsigned int UTF_code);                      // looks for UTF-8 symbols
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods); // looks for special keys
void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);   // mouse buttons
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);           // mouse scroll up or down
void pointer_position(GLFWwindow *window, double& xpos, double& ypos); // gets mouse pointer X and Y position

#endif