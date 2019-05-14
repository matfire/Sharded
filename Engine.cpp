//
// Created by matteo on 5/14/19.
//

#include "Engine.h"

Engine::Engine() {
    _width = 1024;
    _height = 768;
    _window = nullptr;
}

Engine::~Engine() {

}

bool Engine::start(std::string title) {
    // initializing GLFW
    if (!glfwInit()) {
        std::cout << "Error initializing GLFW" << std::endl;
        return false;
    }
    // creating window
    _window = glfwCreateWindow(_width, _height, title.c_str(), nullptr, nullptr);
    if (_window == nullptr) {
        std::cout << "Error creating window" << std::endl;
        return false;
    }

    // GLFW Setup
    glfwMakeContextCurrent(_window);
    int width, height;
    glfwGetFramebufferSize(_window, &width, &height);
    glfwSwapInterval(1);
    const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    int xPos = (mode->width - _width) / 2;
    int yPos = (mode->height - _height) / 2;
    glfwSetWindowPos(_window, xPos, yPos);

    // Viewport Setup
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -10, 10);
    glDepthRange(-10, 10);
    glMatrixMode(GL_MODELVIEW);
    // Alpha setup
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SOURCE0_ALPHA, GL_ONE_MINUS_SRC1_ALPHA);

    return true;
}

void Engine::update() {
    glfwPollEvents();
}

void Engine::render() {
    glClearColor(0, 1, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // add sprite render

    glfwSwapBuffers(_window);
}