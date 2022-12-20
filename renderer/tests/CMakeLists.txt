project(test_suite)

add_library(${PROJECT_NAME}
	TestSuite.h
	TestSuite.cpp
)

target_include_directories(${PROJECT_NAME}
	PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)
add_subdirectory(Comparison)

target_include_directories(${PROJECT_NAME}
	PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Features/Algorithms>
	PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Features/Tuples>
	PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/objects/Colors>
	PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/objects/Matrix>
	PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/objects/Sphere>
	PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/objects/Ray>
)

target_link_libraries(${PROJECT_NAME}
	PUBLIC test_functions
	PUBLIC algorithms
	PUBLIC tuples
	PUBLIC color_tuples
	PUBLIC matrix
	PUBLIC spheres
	PUBLIC rays
)

set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "Renderer/Tests")