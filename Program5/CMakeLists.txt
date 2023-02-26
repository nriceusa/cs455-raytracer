cmake_minimum_required(VERSION 3.21)
project(Program5)

set(CMAKE_CXX_STANDARD 14)

add_executable(Program5 Main.cpp SceneComponent/Ray.cpp SceneComponent/Ray.h SceneComponent/Camera.cpp SceneComponent/Camera.h SceneComponent/Geometry/Sphere.h SceneComponent/Light.h SceneComponent/LightDirectional.cpp SceneComponent/LightDirectional.h SceneComponent/SceneComponent.h Image/Pixel.h Image/Screen.h SceneComponent/Geometry/Geometry.h RayTracer.cpp RayTracer.h Scene.cpp Scene.h SceneComponent/Geometry/Material.cpp SceneComponent/Geometry/Material.h Vector3.h)

target_link_libraries(Program5 m)