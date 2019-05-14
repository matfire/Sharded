cmake_minimum_required(VERSION 3.14)
project(Sharded)

set(CMAKE_CXX_STANDARD 14)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

find_package(glfw3 3.2 REQUIRED)
find_package(OpenGL REQUIRED)


add_library(Sharded SHARED Engine.cpp Engine.h)
target_link_libraries(Sharded glfw ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY})
target_include_directories(Sharded PUBLIC ${OPENGL_INCLUDE_DIR})