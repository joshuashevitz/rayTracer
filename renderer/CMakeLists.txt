project(render)

add_subdirectory(tests)
add_subdirectory(Features)
add_subdirectory(objects)


# Create the renderer application
add_executable(${PROJECT_NAME}
	main.cpp
)

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

set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "Renderer")

