project(spheres)

add_library(${PROJECT_NAME}
	Sphere.h
	Sphere.cpp
)

target_include_directories(${PROJECT_NAME}
	PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)