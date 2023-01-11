# Notes on development

## Packages

Strangely, on my Arch system(EndeavourOS) there was no glfw installed by default, though it's quite easy to install:

```bash
sudo pacman -S glfw
```

## OOP

1. Initializer lists

Shader.h
```CPP
class Shader{ // Constructor
    public:
    unsigned int id; 
        Shader(unsigned int id); // Each OpenGL object has it's own id, so the shader program has it too
        ~Shader(); // Destructor, automatically destroying object when it's no more used, to free memory

        void use(); // method that is needed to use the shader program

};

extern Shader* load_shader(); // Here shader object will be initialized and it's ID will be given
```

Shader.cpp
```CPP

Shader::Shader(unsigned int id) : id(id){

}

```
1.
In the code you provided, : id(id) is an initializer list.

Initializer lists are used in C++ to initialize member variables of a class when an object is constructed. They are placed after the function arguments in the constructor function definition and consist of a list of variable names followed by the corresponding initial values, separated by commas.

In this case, id(id) is initializing the member variable id of the Shader class with the value of the id argument passed to the constructor. The member variable id will be set to the value of the id argument when the Shader object is created.

Initializer lists are used to initialize member variables in the order in which they are declared in the class definition, rather than in the order in which they are listed in the initializer list. This can be useful if you want to initialize member variables in a specific order or if some of the member variables depend on the values of others.

It is important to note that member variables can also be initialized using assignments in the body of the constructor function, but initializer lists are generally considered to be more efficient and are the preferred method for initializing member variables in C++.

2. 
There are a few reasons why initializer lists are preferred over assignments in the body of the constructor function for initializing member variables in C++:

Efficiency: Initializer lists are generally more efficient than assignments for initializing member variables. This is because initializer lists initialize the variables directly, rather than assigning to them after they have already been constructed.

Order of initialization: Initializer lists initialize member variables in the order in which they are declared in the class definition, rather than in the order in which they appear in the initializer list. This can be useful if you want to ensure that member variables are initialized in a specific order or if some of the member variables depend on the values of others.

Constant member variables: Member variables that are declared as const or constexpr can only be initialized using an initializer list. They cannot be assigned to after they have been constructed.

Reference member variables: Member variables that are declared as references must be initialized using an initializer list. They cannot be assigned to after they have been constructed.

Overall, initializer lists are considered to be a more flexible and efficient way to initialize member variables in C++, and they are the preferred method for many developers. However, it is important to note that member variables can also be initialized using assignments in the body of the constructor function, and there may be cases where this is necessary or more convenient.


## Functions Explanation

1. Loading shader vertexFile and fragmentFile to link them in a shader program
```CPP
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
        // Print an error message and return -1 on failure
        std::cerr << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        return -1;
    }
}
```

1. The load_shader() function is declared and takes two std::string arguments: vertexFile and fragmentFile. It returns a pointer to a Shader object.

2. Two variables are declared: vertexCode and fragmentCode, which will be used to store the contents of the shader files.

3. The try block is started. This block of code will be executed and any exceptions thrown by the stream objects will be caught in the catch block.

4. The std::ifstream objects vShaderFile and fShaderFile are declared and opened in a single line of code. The vertexFile and fragmentFile arguments are passed to the std::ifstream constructors, respectively, to open the files.

5. The std::stringstream objects vShaderStream and fShaderStream are declared. These will be used to store the contents of the shader files.

6. The contents of the vShaderFile and fShaderFile streams are read into the vShaderStream and fShaderStream streams, respectively, using the << operator.

7. The vertexCode and fragmentCode variables are set to the contents of the vShaderStream and fShaderStream streams, respectively, using the str() member function.

8. If an exception is thrown by the stream objects, it is caught in the catch block. An error message is printed to std::cerr and the function returns -1.

9. I hope this helps clarify what the code does! Let me know if you have any other questions.

## C++ Theory

### Memory Allocation

In C++, when an object is dynamically allocated, it is created in the heap memory. The heap is a region of memory that is separate from the stack, and it is typically much larger than the stack. Heap memory is typically allocated by using the new keyword, and it is deallocated by using the delete keyword.

When an object is stack-allocated, it is created in the stack memory. The stack is a region of memory that is reserved for a program's use during its execution. It stores data such as function call frames and local variables. When a function is called, a new frame is created on the stack, and when the function returns, that frame is removed. Stack memory is typically allocated automatically by the compiler, and it is deallocated automatically when the function exits or a block of code is exited.

To distinguish whether an object is stack-allocated or dynamically allocated, you can check whether it is created using the new keyword or whether it is declared as a local variable, for example.

You can also distinguish by checking if the pointer is involved or not.
For example:
```CPP
int x;    // stack-allocated 
int* y = new int;  // dynamically allocated
```

In this example, x is stack-allocated, because it is declared as a local variable, whereas y is dynamically allocated, because it is created using the new keyword and is a pointer.

In general, it's a good practice to use stack allocation whenever you can as it is faster and safer, but remember that in cases when objects are big or data needs to be shared among functions, dynamic allocation can be a better choice.

* Otherwordly:
Memory is stack-allocated when controlled by the runtime itself and dynamic allocation is when memory allocation, freeing of it and other processes are controled by the programmer on his own. 

## Weird Behavior

### CMake

1. Importance of the linkage order

This will work -
```CMake
target_link_libraries(DreamEngine OpenGL::GL GLEW::GLEW ${GLFW3_LIBRARY} Tests Window_Game Events Graphics Primitives )
```

And that's will work as well - 

```CMake
target_link_libraries(DreamEngine OpenGL::GL GLEW::GLEW ${GLFW3_LIBRARY} Window_Game Tests Events Graphics Primitives )
```

This one won't, because it's linked later then the libraries which are used in Tests/Triangle_no_texture.cpp.
So order of the linking matters, first going parent file and after it it's dependencies.
Ex. - 
```CMake
target_link_libraries(DreamEngine OpenGL::GL GLEW::GLEW ${GLFW3_LIBRARY} Window_Game Tests Events Graphics Primitives )
```

It will produce such errors - 

```bash
[main] Building folder: Minecraft CPP DreamEngine
[build] Starting build
[proc] Executing command: /usr/bin/cmake --build "/mnt/sdb1/Linux/Minecraft CPP/build" --config Debug --target DreamEngine --
[build] [ 16%] Built target Primitives
[build] [ 33%] Built target Tests
[build] [ 50%] Built target Window_Game
[build] [ 66%] Built target Events
[build] [ 83%] Built target Graphics
[build] [ 91%] Linking CXX executable DreamEngine
[build] /usr/bin/ld: libTests.a(Triangle_no_texture.cpp.o): warning: relocation against `PassEvents' in read-only section `.text'
[build] /usr/bin/ld: libTests.a(Triangle_no_texture.cpp.o): en la función `triangleNoTexture()':
[build] /mnt/sdb1/Linux/Minecraft CPP/DreamEngine/Tests/Triangle_no_texture.cpp:48: referencia a `load_shader(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)' sin definir
[build] /usr/bin/ld: /mnt/sdb1/Linux/Minecraft CPP/DreamEngine/Tests/Triangle_no_texture.cpp:70: referencia a `Shader::use()' sin definir
[build] /usr/bin/ld: /mnt/sdb1/Linux/Minecraft CPP/DreamEngine/Tests/Triangle_no_texture.cpp:83: referencia a `char_callback(GLFWwindow*, unsigned int)' sin definir
[build] /usr/bin/ld: /mnt/sdb1/Linux/Minecraft CPP/DreamEngine/Tests/Triangle_no_texture.cpp:84: referencia a `PassEvents' sin definir
[build] /usr/bin/ld: /mnt/sdb1/Linux/Minecraft CPP/DreamEngine/Tests/Triangle_no_texture.cpp:86: referencia a `PassEvents' sin definir
[build] /usr/bin/ld: /mnt/sdb1/Linux/Minecraft CPP/DreamEngine/Tests/Triangle_no_texture.cpp:87: referencia a `PassEvents' sin definir
[build] /usr/bin/ld: /mnt/sdb1/Linux/Minecraft CPP/DreamEngine/Tests/Triangle_no_texture.cpp:90: referencia a `key_callback(GLFWwindow*, int, int, int, int)' sin definir
[build] /usr/bin/ld: /mnt/sdb1/Linux/Minecraft CPP/DreamEngine/Tests/Triangle_no_texture.cpp:91: referencia a `mouse_button_callback(GLFWwindow*, int, int, int)' sin definir
[build] /usr/bin/ld: /mnt/sdb1/Linux/Minecraft CPP/DreamEngine/Tests/Triangle_no_texture.cpp:92: referencia a `scroll_callback(GLFWwindow*, double, double)' sin definir
[build] /usr/bin/ld: /mnt/sdb1/Linux/Minecraft CPP/DreamEngine/Tests/Triangle_no_texture.cpp:94: referencia a `PassEvents' sin definir
[build] /usr/bin/ld: /mnt/sdb1/Linux/Minecraft CPP/DreamEngine/Tests/Triangle_no_texture.cpp:94: referencia a `PassEvents' sin definir
[build] /usr/bin/ld: /mnt/sdb1/Linux/Minecraft CPP/DreamEngine/Tests/Triangle_no_texture.cpp:94: referencia a `pointer_position(GLFWwindow*, double&, double&)' sin definir
[build] /usr/bin/ld: /mnt/sdb1/Linux/Minecraft CPP/DreamEngine/Tests/Triangle_no_texture.cpp:96: referencia a `PassEvents' sin definir
[build] /usr/bin/ld: /mnt/sdb1/Linux/Minecraft CPP/DreamEngine/Tests/Triangle_no_texture.cpp:99: referencia a `PassEvents' sin definir
[build] /usr/bin/ld: /mnt/sdb1/Linux/Minecraft CPP/DreamEngine/Tests/Triangle_no_texture.cpp:105: referencia a `PassEvents' sin definir
[build] /usr/bin/ld: /mnt/sdb1/Linux/Minecraft CPP/DreamEngine/Tests/Triangle_no_texture.cpp:111: referencia a `noTexture_triangle(Shader&, unsigned int&)' sin definir
[build] /usr/bin/ld: /mnt/sdb1/Linux/Minecraft CPP/DreamEngine/Tests/Triangle_no_texture.cpp:119: referencia a `Shader::~Shader()' sin definir
[build] /usr/bin/ld: /mnt/sdb1/Linux/Minecraft CPP/DreamEngine/Tests/Triangle_no_texture.cpp:119: referencia a `Shader::~Shader()' sin definir
[build] /usr/bin/ld: warning: creating DT_TEXTREL in a PIE
[build] collect2: error: ld devolvió el estado de salida 1
[build] make[3]: *** [CMakeFiles/DreamEngine.dir/build.make:106: DreamEngine] Error 1
[build] make[2]: *** [CMakeFiles/Makefile2:227: CMakeFiles/DreamEngine.dir/all] Error 2
[build] make[1]: *** [CMakeFiles/Makefile2:234: CMakeFiles/DreamEngine.dir/rule] Error 2
[build] make: *** [Makefile:189: DreamEngine] Error 2
[proc] The command: /usr/bin/cmake --build "/mnt/sdb1/Linux/Minecraft CPP/build" --config Debug --target DreamEngine -- exited with code: 2 and signal: null
[build] Build finished with exit code 2
```

So, basically compiler would think about it that the dependencies libraries an their members are not defined. Like if headers were not included, corrupted or path to them is incorrect.