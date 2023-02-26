cmake_minimum_required(VERSION 3.21)
project(Program5)

set(CMAKE_CXX_STANDARD 14)

add_executable(Program5 Main.cpp SceneComponent/Ray.h SceneComponent/Camera.h SceneComponent/Geometry/Sphere.h SceneComponent/Light.h SceneComponent/LightDirectional.h SceneComponent/SceneComponent.h Image/Pixel.h Image/Screen.h SceneComponent/Geometry/Geometry.h RayTracer.h Scene.h SceneComponent/Geometry/Material.h Vector3.h)

target_link_libraries(Program5 m)