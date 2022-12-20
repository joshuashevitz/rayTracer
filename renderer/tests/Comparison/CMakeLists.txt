project(test_functions)

add_library(${PROJECT_NAME}
	comparisonTests.h
	comparisonTests.cpp
)

target_include_directories(${PROJECT_NAME}
	PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)