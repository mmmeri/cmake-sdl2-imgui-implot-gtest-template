
#set(OpenGL_GL_PREFERENCE GLVND)
#find_package(OpenGL REQUIRED)
##find_package(SDL2 REQUIRED)
#
#set(IMGUI_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/dependencies/imgui)
#file(GLOB IMGUI_SOURCES ${IMGUI_INCLUDE_DIR}/*.cpp)
#file(GLOB IMGUI_HEADERS ${IMGUI_INCLUDE_DIR}/*.h)
#                 
#add_library(imgui STATIC 
#	${IMGUI_SOURCES} ${IMGUI_HEADERS}
#	${imgui_SOURCE_DIR}/backends/imgui_impl_sdl2.h
#	${imgui_SOURCE_DIR}/backends/imgui_impl_sdl2.cpp
#	${imgui_SOURCE_DIR}/backends/imgui_impl_sdlrenderer2.h
#	${imgui_SOURCE_DIR}/backends/imgui_impl_sdlrenderer2.cpp
#)
#
#add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_GLAD)
#target_include_directories(imgui PUBLIC ${imgui_SOURCE_DIR})
#target_link_libraries(imgui PUBLIC SDL2::SDL2)
#
##include_directories(
##    ${IMGUI_INCLUDE_DIR}
##    ${OPENGL_INCLUDE_DIR}
##    ${SDL2_INCLUDE_DIR})
#    
##target_link_libraries(imgui
##    ${OPENGL_LIBRARIES}
##   ${SDL2_LIBRARIES})
#    
#set_target_properties(imgui PROPERTIES LINKER_LANGUAGE CXX)
#set_target_properties(imgui PROPERTIES FOLDER dependencies)
#
#set(IMGUI_LIBRARIES imgui)

# vendor/imgui/CMakeLists.txt
message(STATUS "Fetching imgui ...")

set(CMAKE_CXX_STANDARD 17)

FetchContent_GetProperties(imgui)
if (NOT imgui_POPULATED)
  FetchContent_Populate(imgui)
endif ()

add_library(imgui
  ${imgui_SOURCE_DIR}/imgui.cpp
  ${imgui_SOURCE_DIR}/imgui.h
  ${imgui_SOURCE_DIR}/imconfig.h
  ${imgui_SOURCE_DIR}/imgui_demo.cpp
  ${imgui_SOURCE_DIR}/imgui_draw.cpp
  ${imgui_SOURCE_DIR}/imgui_internal.h
  ${imgui_SOURCE_DIR}/imgui_tables.cpp
  ${imgui_SOURCE_DIR}/imgui_widgets.cpp
  ${imgui_SOURCE_DIR}/imstb_rectpack.h
  ${imgui_SOURCE_DIR}/imstb_textedit.h
  ${imgui_SOURCE_DIR}/imstb_truetype.h
  ${imgui_SOURCE_DIR}/backends/imgui_impl_sdl2.h
  ${imgui_SOURCE_DIR}/backends/imgui_impl_sdl2.cpp
  ${imgui_SOURCE_DIR}/backends/imgui_impl_sdlrenderer2.h
  ${imgui_SOURCE_DIR}/backends/imgui_impl_sdlrenderer2.cpp)

target_include_directories(imgui PUBLIC ${imgui_SOURCE_DIR})
target_link_libraries(imgui PUBLIC SDL2::SDL2)

FetchContent_MakeAvailable(imgui)