cmake_minimum_required(VERSION 3.21)
project(Program5)

set(CMAKE_CXX_STANDARD 14)

add_executable(Program5 Main.cpp Ray.cpp Ray.h Camera.cpp Camera.h Sphere.cpp Sphere.h Light.h LightDirectional.cpp LightDirectional.h Object.h)
