#include "Shader.h"

#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

Shader::Shader(unsigned int id) : id(id)
{ // : id(id) - initializer list, initializing
  // member of the class when object is contructed
}

Shader::~Shader()
{ // Destructor by id
    glDeleteProgram(id);
}

void Shader::use()
{
    glUseProgram(id);
}

Shader *load_shader(std::string vertexFile, std::string fragmentFile)
{
    // Declare variables to store the shader code
    std::string vertexCode;
    std::string fragmentCode;

    // Try to open and read the files
    try
    {
        // Declare and open the std::ifstream objects in a single line of code
        std::ifstream vShaderFile(vertexFile);
        std::ifstream fShaderFile(fragmentFile);

        // Declare string streams to store the contents of the files
        std::stringstream vShaderStream, fShaderStream;

        // Read the contents of the files into the string streams
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();

        // Convert the string streams to strings
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    // Catch any exceptions thrown by the stream objects
    catch (std::ifstream::failure &e)
    {
        // Print an error message and return nullptr on failure
        std::cerr << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        return nullptr;
    }

    const GLchar* vShaderCode = vertexCode.c_str();
	const GLchar* fShaderCode = fragmentCode.c_str();

    GLuint vertex, fragment; // linking it into the same program
	GLint success; // state of the program
	GLchar infoLog[512]; // stores error log information

    // Vertex Shader
	vertex = glCreateShader(GL_VERTEX_SHADER); // creating vertex shader
	glShaderSource(vertex, 1, &vShaderCode, nullptr); // loading vertex shader
	glCompileShader(vertex); // compiling vertex shader
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success); // gets the compile status
	if (!success){
		glGetShaderInfoLog(vertex, 512, nullptr, infoLog);
		std::cerr << "SHADER::VERTEX: compilation failed" << std::endl;
		std::cerr << infoLog << std::endl;
		return nullptr; 
	}

    // Fragment Shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER); // creating fragment shader
	glShaderSource(fragment, 1, &fShaderCode, nullptr); // loading fragment shader
	glCompileShader(fragment); // compiling fragment shader 
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success); // gets the compile status
	if (!success){
		glGetShaderInfoLog(fragment, 512, nullptr, infoLog);
		std::cerr << "SHADER::FRAGMENT: compilation failed" << std::endl;
		std::cerr << infoLog << std::endl;
		return nullptr;
	}

    // Shader Program
	GLuint id = glCreateProgram();
	glAttachShader(id, vertex);
	glAttachShader(id, fragment);
	glLinkProgram(id);

	glGetProgramiv(id, GL_LINK_STATUS, &success);
	if (!success){
		glGetProgramInfoLog(id, 512, nullptr, infoLog);
		std::cerr << "SHADER::PROGRAM: linking failed" << std::endl;
		std::cerr << infoLog << std::endl;

		glDeleteShader(vertex);
		glDeleteShader(fragment);
		return nullptr;
	}

	glDeleteShader(vertex);
	glDeleteShader(fragment);

	return new Shader(id);

}
