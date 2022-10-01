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
)
target_link_libraries(${PROJECT_NAME}
	PUBLIC test_functions
	PUBLIC algorithms
	PUBLIC tuples
)