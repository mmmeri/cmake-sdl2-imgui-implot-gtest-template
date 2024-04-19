include(FetchContent)

FetchContent_Declare(
  SDL2
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG 859844eae358447be8d66e6da59b6fb3df0ed778 # 2.30.0
)
add_subdirectory(sdl)

# Dear ImGui
FetchContent_Declare(imgui
  GIT_REPOSITORY https://github.com/ocornut/imgui
  GIT_TAG 8490a262c45a27dc5acbc0ef68f81ed4ba784cf1 # 1.90.2-docking
)
add_subdirectory(imgui)
add_subdirectory(implot)

# googletest
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG f8d7d77c06936315286eb55f8de22cd23c188571 # 1.14
)
add_subdirectory(googletest)