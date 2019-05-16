//
// Created by matteo on 5/14/19.
//

#ifndef SHARDED_ENGINE_H
#define SHARDED_ENGINE_H
#include <GLFW/glfw3.h>
#include <iostream>

#ifdef _WIN32
#pragma comment(lib, "opengl32.lib")
#endif

class Engine {
public:
    Engine();
    ~Engine();
    bool start(std::string title);
    void update();
    void render();
private:
    int _width;
    int _height;
    GLFWwindow *_window;
};


#endif //SHARDED_ENGINE_H
