cmake_minimum_required(VERSION 3.21)
project(Program5)

set(CMAKE_CXX_STANDARD 14)

add_executable(Program5 Main.cpp SceneComponent/Ray.cpp SceneComponent/Ray.h SceneComponent/Camera.cpp SceneComponent/Camera.h SceneComponent/Sphere.cpp SceneComponent/Sphere.h SceneComponent/Light.h SceneComponent/LightDirectional.cpp SceneComponent/LightDirectional.h SceneComponent/SceneComponent.h Pixel.h Screen.h)
