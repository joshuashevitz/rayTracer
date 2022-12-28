project(render)

list(APPEND RENDER_SOURCE
	"src/main.cpp"
)

file(GLOB RENDER_INCLUDE "*.h")

add_executable(${PROJECT_NAME}
	${RENDER_SOURCE}
	${RENDER_INCLUDE}
)

target_include_directories(${PROJECT_NAME}
	PUBLIC "${CMAKE_CURRENT_LIST_DIR}/../"
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE Renderer::Core
  PRIVATE Renderer::Math
  PRIVATE Renderer::Objects
  PRIVATE Renderer::Tests
 )