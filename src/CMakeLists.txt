add_executable(
  app WIN32
  main.cpp
  app.h app.cpp
  window.h window.cpp
)

target_link_libraries(app PRIVATE SDL2::SDL2 imgui implot)
target_include_directories(app PUBLIC ${CMAKE_BINARY_DIR}/_deps/imgui-src)
target_include_directories(app PUBLIC ${CMAKE_SOURCE_DIR}/dependencies/implot)

add_subdirectory(lib)

if(WIN32)
  # Copy DLLs needed for runtime on Windows
  add_custom_command(TARGET app POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:SDL2::SDL2>
    $<TARGET_FILE_DIR:app>)
endif()