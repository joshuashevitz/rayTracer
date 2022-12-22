# Manage and configure all the external libraries that are used.

message("\nConfigurating externals")
message("=========================================================")

#=========================================================
# SDL
#=========================================================
message("SDL:")
set(SDL_STATIC OFF)

add_subdirectory("sdl")

set_target_properties(
  SDL3
  SDL3_test
  uninstall
  PROPERTIES FOLDER "Externals/SDL"
)
message("Done!\n")