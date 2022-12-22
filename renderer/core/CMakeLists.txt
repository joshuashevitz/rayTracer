project(Core)

# Source and Include files
list(APPEND CORE_SOURCE
 "src/Color.cpp"
)

file(GLOB CORE_INCLUDE "*.h")


# Create the library
add_library(${PROJECT_NAME} STATIC
  ${CORE_SOURCE}
  ${CORE_INCLUDE}
)
add_library(Renderer::Core ALIAS ${PROJECT_NAME})


target_include_directories(${PROJECT_NAME}
  PUBLIC "${CMAKE_CURRENT_LIST_DIR}/../"
)

set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "Renderer")