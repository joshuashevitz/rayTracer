project(render)

# Create the renderer application
add_executable(${PROJECT_NAME}
	"src/main.cpp"
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE Renderer::Core
  PRIVATE Renderer::Math
  PRIVATE Renderer::Objects
)