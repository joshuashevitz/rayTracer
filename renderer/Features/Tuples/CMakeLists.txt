project(tuples)

add_library(${PROJECT_NAME}
	tuples.h
	tuples.cpp
)

target_include_directories(${PROJECT_NAME}
	PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)