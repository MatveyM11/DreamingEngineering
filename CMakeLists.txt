cmake_minimum_required(VERSION 3.10)
project(DreamEngine)

# Find the GLEW library
find_package(GLEW REQUIRED)

# Find the GLFW3 library and header files
find_library(GLFW3_LIBRARY NAMES glfw3 glfw)
find_path(GLFW3_INCLUDE_DIR GLFW/glfw3.h)

# Find the OpenGL library and set the preference to GLVND
set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL 4.6 REQUIRED)

# Add the tests library
add_library(Tests DreamEngine/Tests/Triangle_no_texture.cpp DreamEngine/Tests/Triangle_no_texture.h)


# Add the Window_Game library
add_library(Window_Game DreamEngine/Window/Window_Game.cpp DreamEngine/Window/Window_Game.h)
add_library(Events DreamEngine/Window/Events.cpp DreamEngine/Window/Events.h)
add_library(Graphics DreamEngine/Graphics/Shader.cpp DreamEngine/Graphics/Shader.h)
add_library(Primitives DreamEngine/Primitives/Primitives.cpp DreamEngine/Primitives/Primitives.h)


# Add the source files for the DreamEngine target
add_executable(DreamEngine DreamEngine/main.cpp)

# Link the libraries to the DreamEngine target
target_link_libraries(DreamEngine OpenGL::GL GLEW::GLEW ${GLFW3_LIBRARY} Window_Game Tests Events Graphics Primitives )
target_include_directories(DreamEngine PRIVATE ${GLFW3_INCLUDE_DIR})

# Set the build type to Debug
set(CMAKE_BUILD_TYPE Debug)
