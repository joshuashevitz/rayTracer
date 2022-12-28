project(Objects)

list(APPEND OBJECTS_SOURCE
  "src/Canvas.cpp"
  "src/Environment.cpp"
  "src/Projectiles.cpp"
  "src/Sphere.cpp"
  "src/Ray.cpp"
)

file(GLOB OBJECTS_INCLUDE "*.h")

add_library(${PROJECT_NAME}
	${OBJECTS_SOURCE}
	${OBJECTS_INCLUDE}
)
add_library(Renderer::Objects ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
	PUBLIC Renderer::Core
)

target_include_directories(${PROJECT_NAME}
	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/../"
)

set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "Renderer")