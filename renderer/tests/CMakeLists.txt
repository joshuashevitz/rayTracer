project(test_suite)

add_library(${PROJECT_NAME}
	TestSuite.h
	TestSuite.cpp
)

target_include_directories(${PROJECT_NAME}
	PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)

target_include_directories(${PROJECT_NAME}
  PRIVATE "${CMAKE_CURRENT_LIST_DIR}/../"
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE Renderer::Core
  PRIVATE Renderer::Math
  PRIVATE Renderer::Objects
)

set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "Renderer/Tests")