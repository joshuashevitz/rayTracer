project(render)

# Source and Include files
list(APPEND RENDERER_SOURCE
  "src/Visualizer.cpp"
  "src/main.cpp"
)

file(GLOB RENDERER_INCLUDE "*.h")

# Create the renderer application
add_executable(${PROJECT_NAME}
  ${RENDERER_SOURCE}
  ${RENDERER_INCLUDE}
)

target_include_directories(${PROJECT_NAME}
  PUBLIC "${CMAKE_CURRENT_LIST_DIR}/../"
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE Renderer::Core
  PRIVATE Renderer::Math
  PRIVATE Renderer::Objects
  PRIVATE SDL3
)