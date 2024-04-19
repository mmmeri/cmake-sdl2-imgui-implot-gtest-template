add_library(implot STATIC implot.h implot.cpp implot_internal.h implot_items.cpp)
target_include_directories(implot PUBLIC ${CMAKE_BINARY_DIR}/_deps/imgui-src)
target_include_directories(implot PUBLIC ${imgui_SOURCE_DIR})