#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../Graphics/Shader.h"


void noTexture_triangle(Shader &shader, GLuint &VAO)
{
    shader.use();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}