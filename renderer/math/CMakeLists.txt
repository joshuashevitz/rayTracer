project(Math)

# Source and Include files
list(APPEND MATH_SOURCE
  "src/Matrix.cpp"
  "src/simpleMath.cpp"
  "src/tuples.cpp"
  "src/comparisonTests.cpp"
)

file(GLOB MATH_INCLUDE "*.h")

# Create the library
add_library(${PROJECT_NAME} STATIC
  ${MATH_SOURCE}
  ${MATH_INCLUDE}
)
add_library(Renderer::Math ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
  PUBLIC "${CMAKE_CURRENT_LIST_DIR}/../"
)

set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "Renderer")