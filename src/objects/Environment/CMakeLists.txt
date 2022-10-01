project(environment)

add_library(${PROJECT_NAME}
	Environment.h
	Environment.cpp
)

target_include_directories(${PROJECT_NAME}
	PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)

target_include_directories(${PROJECT_NAME}
	PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Features/Algorithms>
	PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Features/Tuples>
)
target_link_libraries(${PROJECT_NAME}
	PUBLIC algorithms
	PUBLIC tuples
)