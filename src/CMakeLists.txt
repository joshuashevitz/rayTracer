cmake_minimum_required(VERSION 3.20)
project(render)

add_executable(${PROJECT_NAME}
	main.cpp
)

add_subdirectory(tests)
add_subdirectory(Features)
add_subdirectory(objects)

target_link_libraries(${PROJECT_NAME}
	PUBLIC tuples
	PUBLIC algorithms
	PUBLIC test_suite
	PUBLIC environment
	PUBLIC projectiles
	PUBLIC color_tuples
	PUBLIC canvas
	PUBLIC matrix
	PUBLIC rays
	PUBLIC spheres
)