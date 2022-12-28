project(Tests)

list(APPEND TEST_SOURCE
	"TestSuite.h"
	"TestSuite.cpp"
)

file(GLOB TEST_INCLUDE "*.h")

add_library(${PROJECT_NAME} STATIC
	${TEST_SOURCE}
	${TEST_INCLUDE}
)

add_library(Renderer::Tests ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
  PUBLIC "${CMAKE_CURRENT_LIST_DIR}/../"
)

set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "Renderer/Tests")