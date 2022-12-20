cmake_minimum_required(VERSION 3.20)

project(RayTracer)

## Project wide configurations
# Setup the project to use the C++20 spec
set(CMAKE_CXX_STANDARD 20)

# Have cmake to generate project/compile information 
#  for external tools to use.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Allow the use of 'folders' in generate projects
set_property(GLOBAL PROPERTY USE_FOLDERS ON)


# Include the sub-projects
add_subdirectory("renderer")
add_subdirectory("app")