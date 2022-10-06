project(color_tuples)

add_library(${PROJECT_NAME}
	Color.h
	Color.cpp
)

target_include_directories(${PROJECT_NAME}
	PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(${PROJECT_NAME}

)
