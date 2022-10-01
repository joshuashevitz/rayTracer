project(algorithms)

add_library(${PROJECT_NAME}
	simpleMath.h
	simpleMath.cpp
)

target_include_directories(${PROJECT_NAME}
	PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)