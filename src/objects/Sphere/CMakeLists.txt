project(spheres)

add_library(${PROJECT_NAME}
	Sphere.h
	Sphere.cpp
)

target_include_directories(${PROJECT_NAME}
	PUBLIC ${CMAKE_CURRENT_LIST_DIR}
	PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Features/Tuples>
	PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/objects/Matrix>

)


target_link_libraries(${PROJECT_NAME}
	PUBLIC tuples
	PUBLIC matrix
)